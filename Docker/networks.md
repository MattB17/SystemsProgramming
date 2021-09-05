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

### Default Security
* create you apps so frontend/backend sit on same Docker network
* their inter-communication never leaves the host
* all externally exposed ports are closed by default
* you must manually expose via -p
  * this is better default security
* this gets even better with Swarm and Overlay networks
