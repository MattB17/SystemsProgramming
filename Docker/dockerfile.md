# Dockerfile
A dockerfile is a recipe for creating an image

`docker-build -f <some dockerfile>`
* `-f` is used to specify a dockerfile

Each stanza is another layer in our image

Every dockerfile has a FROM command, specifying a minimal base
* ie. `FROM debian:jessie`

package managers like apt and yum are one of the reasons to build containers
* FROM Debian, Ubuntu, Fedora, or CentOS

`ENV` is for environment variables
* it is a way to set environment variables
* one reason environment variables were chosen as a preferred way to inject key/value pairs is the work everywhere, on every OS and config

`RUN` used to execute shell commands inside the container as it is building it

The best way to do logging inside a container is not to log to a log file
* docker handles all the logging for us
* we just have to ensure all the logs are sent to stdout and stderr

`EXPOSE` command
* by default no TCP or UDP ports are open inside a container unless we list it here
* this does not mean they will automatically be open on our host - that is what the `-p` command is for in `docker run`

`CMD` is a required parameter
* the final command that will be run every time you launch a new container from the image or every time you restart a stopped container

`docker image build -t customnginx .`
* gives it a tag of `customnginx`
* builds in this directory `.`
  * ie. using the dockerfile in the current directory

Docker caches steps in image build, so that the next time you build the image, if the step has not changed it is not rerun
* this gives very short build times
* when a line changes, every line after that has to be rebuilt as well
* typically want things that change the least at top and things that change the most at bottom

Usually start with an official image in the docker file
* then possibly make tweaks as the project gets more complex

`WORKDIR <some_directory>` is basically just a `cd` into the working directory

`COPY` used to copy from your local machine into your container images

Some of the required commands could be included in an image you include with the `FROM` command

Usually when you run a clean command you want to run it on the same line as the actual install so that it removes everything all at the same time
* and you only get one image layer

### Example
```
# downloads the image
FROM node:6-alpine

# exposes port 3000
`EXPOSE 3000`

# install tini
RUN apk add --update tini

# creates a directory for app files
RUN mkdir -p /usr/src/app

# changes working directory to /usr/src/app and copies package.json
# from local to the working directory on the container
WORKDIR /usr/src/app
COPY package.json package.json

# installs dependencies and cleans after
# done in 1 line to avoid 2 separate images and remove unnecessary parts
RUN npm install && npm cache clean --force

# copies all files from current directory on local to working directory
# on container
COPY . .

# Starts the container with command '/sbin/tini -- node ./bin/www'
CMD ["tini", "--", "node", "./bin/www"]
```
