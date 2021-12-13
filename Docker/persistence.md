# Persistence
Containers are usually immutable and ephemeral
* immutable infrastructure - only re-deploy containers, never change
  * this is the ideal scenario, but what about databases or unique data?
  * ideally your container shouldn't contain your unique data mixed in with the application binaries
  * docker gives us features to ensure these "separation of concerns"
  * ideally, the unique data stays and is saved somewhere as we cycle through different containers
  * this unique data is known as persistent data
  * 2 ways to handle persistent data
    * volumes - make special location outside of container UFS
      * preserves the data across container removals
    * bind mounts - link container path to host path
      * mounting a local directory into a container

### Volumes
`VOLUME` command in Dockerfile

named volumes are a friendly way to assign volumes to containers
* `docker container run -d --name mysql -e MYSQL_ALLOW_EMPTY_PASSWORD=True -v mysql-db:/var/lib/mysql mysql`
* the `-v` command allows us to specify a named volume
* in this case we create a volume named `mysql-db`

`docker volume create`
* required to do this before `docker run` to use custom drivers and labels

### Bind Mounting
Maps a host file or directory to a container file or directory
* basically just two locations pointing to the same file(s)
* skips UFS and host files overwrite any in container

Can't use bind mounts in a Dockerfile
* must be at a `container run`
* `... run -v /Users/mattb/stuff:/path/container`
* `docker container run -d --name nginx -p 80:80 -v $(pwd):/usr/share/nginx/html nginx`
  * creates container with bind mount from working directory to `/usr/share/nginx/html`
