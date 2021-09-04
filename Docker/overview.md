# Overview

### Image vs. Container
An image is the application we want to run
* we get all images from registries

A container is an instance of that image running as a process
* you can have many containers running off the same image

What happens in `docker container run`
1. looks for that image locally in image cache
2. if it doesn't find anything then it looks in remote image repository (defaults to Docker Hub)
3. Downloads the latest version (`nginx:latest` by default)
4. Creates a new container based on that image and prepares to start
  * it doesn't just copy the image
  * it starts building on top of the image
5. Gives it a virtual IP on a private network inside docker engine
6. Opens up port 80 on host and forwards to port 80 in container
  * if we use `--publish 80:80`
  * if we don't use the `publish` command, no ports are opened
7. Starts container by using the CMD in the image Dockerfile

Containers aren't mini-VMs
* they are just processes
* limited to what resources they can access
* exit when process stops
