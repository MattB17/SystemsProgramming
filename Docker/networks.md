# Docker Networks

### Network Defaults
* each container is connected to a private virtual network "bridge"
* each virtual network routes through NAT firewall on host IP
* all containers on a virtual network can talk to each other without -p
* best practice is to create a new virtual network for each app:
  * network "my_web_app" for mysql and php/apache containers
  * network "my_api" for mongo and nodejs containers
* "Batteries Included, But Removable"
  * defaults work well in many cases, but easy to swap out parts to customize it
* can make new virtual networks
* can attach containers to more than one virtual network (or none)
* can skip virtual networks and use host IP (`--net=host`)
* use different Docker network drivers to gain new abilities

For each port on the host, it can only be listening to one container

`--network bridge`
* default Docker virtual network, which is NAT'ed behind the host IP

`--network host`
* it gains performance by skipping virtual networks but sacrifices security of the container model

`--network none`
* removes eth0 and only leaves you with localhost interface in the container

network driver are built-in or 3rd party extensions that give you virtual network features

### Creating a network
`docker network create my_app_net`
* creates new network called `my_app_net`
* no driver specified so it defaults to `bridge`

`docker container run -d --name new_nginx --network my_app_net nginx`
* runs an `nginx` container on `my_app_net`

`docker network connect my_app_net webhost`
* connects the existing container `webhost` to the network `my_app_net`

`docker network disconnect my_app_net webhost`
* disconnects container `webhost` from network `my_app_net`

To start up a container on a given network
* `docker container run -d --name my_nging --network my_app_net nginx`

### Default Security
* create you apps so frontend/backend sit on same Docker network
* their inter-communication never leaves the host
* all externally exposed ports are closed by default
* you must manually expose via -p
  * this is better default security
* this gets even better with Swarm and Overlay networks

### DNS
Static IPs and using IPs for talking to containers in an anti-pattern
* do your best to avoid it
* IP addresses of containers are always changing
  * they may fail and be brought up in a different location

Docker daemon has a built-in DNS server that containers use by default

New networks that you create get automatic DNS resolution
* containers find each other on that virtual network using their container names
* docker defaults the hostname to the container's name, but you can also set aliases

Suppose `my_nginx` and `new_nginx` servers are on the same network
* can send a ping from one to the other with `docker container exec -it my_nginx ping new_nginx`

The bridge network does not have a DNS server built into it by default
* instead use `--link`
* but it is easier to just create a new network and use the default DNS on that network

This gets way easier with docker compose
