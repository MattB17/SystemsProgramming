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
