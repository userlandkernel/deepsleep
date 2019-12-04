macos:
	clang src/deepsleep.c -o deepsleep_macos -framework IOKit -framework CoreFoundation

ios:
	xcrun -sdk iphoneos clang -arch arm64 src/deepsleep.c -o deepsleep_arm64 -framework IOKit -framework CoreFoundation

install:
	make macos
	sudo cp deepsleep_macos /usr/local/bin/deepsleep
