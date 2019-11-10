macos:
  clang src/deepsleep.c -o deepsleep_macos -framework IOKit -framework CoreFoundation

ios:
  clang -arch arm64 -isysroot $(xcode-select -p)/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS.sdk src/deepsleep.c -o deepsleep_arm64 -framework IOKit -framework CoreFoundation

install:
  make macos
  sudo cp deepsleep_macos /usr/local/bin/deepsleep
