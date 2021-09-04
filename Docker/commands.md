# Commands

### Base Commands
* `docker`
  * lists docker commands
* `docker version`
  * check your versions and that docker is working
* `docker info`
  * shows most configuration values for the engine
* `docker container run`
  * stats a new container from an image
  * `docker run` is the old way of using the command
  * always starts a new container
* `docker container start`
  * to start an existing stopped container
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

### Options
* `--detach`
  * run in the background
* `--name`
  * to name your container

### Examples
nginx
* `docker container run --publish 80:80 nginx`
  * downloaded image `nginx` from Docker Hub
  * started a new container from that image
  * opened port 80 on the host IP
  * routes that traffic to the container IP, port 80
* `docker container run --publish 80:80 --detach nginx`
  * same as above but run it in the background
* `docker container run --publish 80:80 --detach --name webhost nginx`
  * name the container `webhost`
* `docker container logs webhost`
  * see logs of `webhost`
  * very useful if running in detach mode
* `docker container top webhost`
  * see the running processes of `webhost`

mongo
* `docker run --name mongo --detach mongo`

httpd (apache)
* `docker container run --detach --name webserver --publish 8080:80 httpd`

mysql
* `docker container run --detach --publish 3306:3306 --name db -e MYSQL_RANDOM_ROOT_PASSWORD=yes mysql`
