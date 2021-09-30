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

Images are designed using the Union File System concept
* every image starts with a blank layer known as scratch
* every change that happens after that in the file system on the image is another layer
* images are made up of file system changes and metadata
* each layer is uniquely identified and only stored once on a host

We're never storing the same image data more than once on the file system
* if multiple images share some layers, only one copy of each layer is stored

Copy on Write (CoW)
* if we run a container off an image then docker creates a new read/write layer for that container on top of that image
* if you run 2 containers off the same image then the size of the containers is only the difference between what has been done on the container since it started and the base image
* the base image is read only
* if you are running a container and change a file that is in the image then the file is only copied to the container after the change - CoW
  * otherwise, if you are not changing the file but just reading it, you read the version stored on the image, no need to copy to container
