/* 
	Deepsleep tool for iOS and macOS 
	MIT Licensed, by Sem Voigtländer
	compile: clang deepsleep.c -o deepsleep -framework IOKit -framework CoreFoundation
*/


#include <stdio.h>
#include <mach/mach.h>
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/pwr_mgt/IOPMLib.h>


int main(int argc, char *argv[]) {

  mach_port_t master = kIOMasterPortDefault;
  kern_return_t err = KERN_SUCCESS;
  io_service_t ref = MACH_PORT_NULL;
  
  // Get a reference to the powermanagement rootdomain
  ref = IORegistryEntryFromPath(kIOMasterPortDefault, "IOPower:/IOPowerConnection/IOPMrootDomain");
  
  if(IO_OBJECT_NULL == ref) {
    printf("Failed to get a reference to I/O Powermanagement rootdomain.\n");
    return KERN_FAILURE;
  }
  
  // Mark the system as booted (mostlikely not even needed)
  err = IORegistryEntrySetCFProperty(ref, CFSTR("System Boot Complete"), kCFBooleanTrue);
  
  if(KERN_SUCCESS != err) {
    printf("Failed to mark system boot sequence as completed. (Not mandatory), continuing...\n");
  }
  
  // Get a powermanagement reference for the system
  ref = IOPMFindPowerManagement(master);
  if(IO_OBJECT_NULL == ref) {
    printf("Failed to get a powermanagement reference for the system.\n");
    return KERN_FAILURE;
  }
  
  // Send the hibernate mach message to IOPowerManagement
  printf("Sending hibernation message to powermanagement.\n");
  err = IOPMSleepSystem(ref);
  
  if(KERN_SUCCESS != err) {
    printf("Failed to send hibernation message to powermanagement.\n");
    return KERN_FAILURE;
  }
  
  return err;

}
