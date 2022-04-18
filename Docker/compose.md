# Docker Compose
Why?
* configure relationships between containers
* save our docker container run settings in easy-to-read file
* create one-liner development environment setups

Docker Compose is comprised of 2 separate but related parts
* YAML-formatted file that describes our solution options for
  * containers
  * networks
  * volumes
* A CLI tool docker-compose used for local dev/test automation with those YAML files

`docker-compose.yml`
* compose YAML format has its own versions: 1, 2, 2.1, 3, 3.1
* YAML file can be used with docker-compose command for local docker automation
  * or with docker directly in production with Swarm (as of v1.13)
* `docker-compose --help`
* `docker-compose.yml` is default filename, but any can be used with `docker-compose -f`
