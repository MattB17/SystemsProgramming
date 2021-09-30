# Commands

### Base Commands
* `docker`
  * lists docker commands
* `docker version`
  * check your versions and that docker is working
* `docker info`
  * shows most configuration values for the engine
* `docker pull`
  * pulls an image
  * ie. `docker pull alpine` to pull the alpine image

### Container Commands
* `docker container run`
  * stats a new container from an image
  * `docker run` is the old way of using the command
  * always starts a new container
  * use the `-it` option to run interactively
    * `docker container run -it`
* `docker container start`
  * to start an existing stopped container
  * to start interactively do `docker container start -ai`
* `docker container ls`
  * list running containers
  * `docker ps` is the old way of using the command
  * `docker container ls -a` lists all containers
* `docker container stop`
  * stops the container process but doesn't remove it
  * `docker stop` is the old way of using the command
* `docker container logs`
  * shows logs for a specific container
  * use `--help` to see all the log options
  * `docker logs` is the old way of using the command
* `docker container top`
  * display the running processes of a container
* `docker container rm`
  * remove (delete) one or more containers
  * `docker rm` is the old way of using the command
* `docker container inspect`
  * details of one container config
  * show metadata about the container (startup, config, volumes, networking, etc)
  * shown in a JSON format
* `docker container stats`
  * performance stats for all containers
  * show live performance data for all containers
* `docker container exec -it`
  * run additional command in existing container
  * runs an additional process on an existing running container

### Image Commands
* `docker image ls`
  * list all pulled images
* `docker image history`
  * shows layers of changes made in image
* `docker image inspect`
  * returns JSON metadata about the image

### Network Commands
* `docker network ls`
  * list all the networks that have been created
* `docker network inspect`
  * lists details of a specific network
  * ie `docker network inspect bridge`
* `docker network create`
  * spawns a new virtual network for you to attach containers to
* `docker network connect`
  * dynamically creates a NIC in a container on an existing virtual network
* `docker network disconnect`
  * dynamically removes a NIC from a container on a specific virtual network

### Options
* `--detach`
  * run in the background
  * can also do `-d`
* `--name`
  * to name your container
* `-t`
  * `--pseudo-tty`
  * simulates a real terminal, like what SSH does
* `-i`
  * `--interactive`
  * keeps session open to receive terminal input
* `-p`
  * `--publish`
  * publishing ports is always in `HOST:CONTAINER` format
* `--format`
  * a common option for formatting the output of commands using "Go templates"
