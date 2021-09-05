#Examples
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
* `docker container inspect --format '{{ .NetworkSettings.IPAddress }}' webhost`
  * to see IP address where `webhost` is running

mongo
* `docker run --name mongo --detach mongo`

httpd (apache)
* `docker container run --detach --name webserver --publish 8080:80 httpd`

mysql
* `docker container run --detach --publish 3306:3306 --name db -e MYSQL_RANDOM_ROOT_PASSWORD=yes mysql`

ubuntu
* `docker container run -it --name ubuntu ubuntu`
  * starts a container named `ubuntu`
* the default CMD is bash so we don't have to specify it

alpine
* Alpine Linux is a small security-focused distribution
* alpine does not have bash installed by default but it does have `sh`
* `docker container run -it alpine sh`
