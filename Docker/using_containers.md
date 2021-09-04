# Using Containers
Docker CLI is a great substitute for adding SSH to containers

`docker container run -it --name proxy nginx bash`
* run an nginx server named proxy in interactive mode
* the `bash` when run with `-it` will give you a terminal inside the running container

We can only run something in a container if it is in its image or we have added it after
* `docker container run -it alpine bash` does not work because bash is not installed on alpine
