# Images
What's in an image
* app binaries and dependencies
* metadata about the image data and how to run the image

An image is not a complete operating system
* there is no kernel nor kernel modules (eg. drivers)
* the host provides the kernel

The image can be as small as one file (your app binary like a golang static binary)

Or the image could be really big
* like a Ubuntu distribution with apt, and Apache, and PHP, etc.
