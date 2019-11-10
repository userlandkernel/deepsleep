# DeepSleep
A cli utillity for hibernating Apple devices

## Why
- Initially found a cool factory tool for it, thought it would help reserve battery to aid in preserving tetherboot longer.
- It's very minimal code but an easy asset for beginners learning about IOKit
- It's multiplatform (both iOS, watchOS, tvOS and macOS) and a commandline tool that didn't exist yet.
- It was fun to reverse engineer a facory tool

## How to use it
- Turn on airplane mode so the device will not wake up by incoming calls or text messages
- Turn off notifications in settings temporarily
- Open a terminal or via ssh run deepsleep
- Make sure to LEAVE YOUR DEVICE AT REST, because any button press or hardware interrupt (like USB) will wake it up again
- Waking up is as easy as pressing any way of hardware input (buttons, USB, keyboard etc)

## How to build it
- Make sure you have the IOKit headers and libkern in your iOS SDK.
```bash 
# To copy the required headers if you don't have them
sudo cp -r /Applications/Xcode.app/Contents/Developer/Platforms/MacOS.platform/Developer/SDKs/macOS.sdk/System/Library/Frameworks/IOKit.framework/Headers /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/System/Library/Frameworks/IOKit.framework/Headers && sudo cp -r /Applications/Xcode.app/Contents/Developer/Platforms/MacOS.platform/Developer/SDKs/macOS.sdk/usr/include/libkern /Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk/usr/include/libkern
```  
- Run `make` in the directory of this repo.
- If you're on macOS you can use the tool now. Even non-root users can execute it :)
- If you're on iOS you'll have to codesign it: ```bash ldid -S deepsleep``` will do.
- If you're on iOS you must elevate to root privileges for the command to work.

## Contributions
- You can contribute by writing settings panes, control center bundles or activator triggers to make entering deepsleep easier.
