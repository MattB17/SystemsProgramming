# Networking

### Examining and Monitoring a Network
The `ping` command sends a special network packet called an ICMP ECHO_REQUEST to a specified host
* most network devices receiving this packet will reply to it, allowing the network connection to be verified
* it is possible to configure most network devices (including Linux hosts) to ignore these packets
  * this is usually done for security reasons, to partially obscure a host from a potential attacker
  * it is also common for firewalls to be configured to block ICMP traffic
* once started, `ping` continues to send packet at a specified interval (default is 1 second) until it is interrupted
* after it is interrupted, `ping` prints performance statistics
* a properly performing network will exhibit 0% packet loss
* a successful ping will indicate that the elements of the network (its interface cards, cabling, routing, and gateways) are in generally good working order

The `traceroute` program displays a listing of all the hops network traffic takes to get from the local system to a specified host

The `netstat` program is used to examine various network settings and statistics

### Transporting Files over a Network
`ftp` uses the File Transfer Protocol (FTP)
* FTP is used widely on the Internet for file downloads
* most, if not all, web browsers support it, and you often see URIs starting with the protocol `ftp://`
* before there were web browsers, there was the `ftp` program
* `ftp` is used to communicate with FTP servers - machines that contain files that can be uploaded and downloaded over a network
* FTP, in its original form, is not secure because it sends account names and passwords in cleartext
  * this means that they are not encrypted and anyone sniffing the network can see them
  * because of this, almost all FTP done over the Internet is done by anonymous FTP servers
  * an anonymous server allows anyone to log in using the login name anonymous and a meaningless password

`lftp` works much like the traditional `ftp` program but has many additional convenience features, such as multiple-protocol support (including HTTP), automatic retry on failed downloads, background processes, tab completion of path names, etc.

`wget` is useful for downloading content from both web and FTP sites
* single files, multiple files, and even entire sites can be downloaded

### Secure Communication with Remote Hosts
Secure Shell (SSH) solves the 2 basic problems of secure communication with a remote host
* it authenticates that remote host is who it says it is - preventing man-in-the-middle attacks
* it encrypts all of the communications between the local and remote hosts

SSH consists of 2 parts
* an SSH servers runs on the remote host, listening for incoming connections on port 22
* while an SSH client is used on the local system to communicate with the remote server

Most Linux distributions ship an implementation of SSH called OpenSSH
* to enable a system to receive remote connections, it must have the OpenSSH-server package installed, configured, and running, and (if the system is either running or behind a firewall) it must allow incoming network connections on TCP port 22

`ssh` allows us to execute a single command on a remote system
* `ssh remote-sys 'ls *' > dirlist.txt` executes `ls *` on `remote-sys` and writes the contents to `dirlist.txt` on the host
* `ssh remote-sys 'ls * > dirlist.txt'` executes `ls *` on `remote-sys` and writes the contents to `dirlist.txt` on `remote-sys`

Part of what happends when you establish a connection with a remote host via SSH is that an encrypted tunnel is created between the local and remote systems
* normally, this tunnel is used to allow commands typed at the local system to be transmitted safely to the remote system and the results to be transmitted safely back
* the SSH protocol allows most types of network traffic to be sent through the encrypted tunnel, creating a sort of VPN (virtual private network) between the local and remote systems

The OpenSSH package also includes two programs that can make use of an SSH-encrypted tunnel to copy files across the network
* `scp` (secure copy) is used much like the `cp` program to copy files
* `sftp` is a secure replacement for the `ftp` program
  * it works much like the original `ftp` program
  * but instead of transmitting everything in cleartext, it uses an SSH-encrypted tunnel
  * `sftp` has an important advantage over conventional `ftp` in that it does not require an FTP server to be running on the remote host
    * it requires only the SSH server
    * this means that any remote machine that can connect with the SSH client can also be used as a FTP-like server
