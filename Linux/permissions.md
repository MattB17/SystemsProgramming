# Permissions
Operating systems in the Unix tradition differ from those in the MS-DOS tradition in that they are not only multitasking systems but also multiuser systems

In the UNIX security model, a user may own files and directories
* when a user owns a file or directory, the user has control over its access
* users can belong to a group consisting of one or more users who are given access to files and directories by their owners
* an owner can grant access to a group or everybody (the world in Unix terms)

When user accounts are created, users are assigned a number called a User ID (or uid)
* the user is assigned a promary group ID (or gid) and may belong to additional groups

### Access Rights
Access rights to files and directories are defined in terms of read access, write access, and execution access

Suppose we have a file `foo.txt` and we issue the command `ls -l foo.txt`
* the permissions could be printed as `-rw-rw-r--`
  * the first position is the file type
    * `-` indicates a regular file
    * `d` indicates a directory
    * `l` indicates a symbolic link
    * `c` indicates a character special file
    * `b` indicates a block special file
  * the next 3 permissions indicate user access
    * `rw-` indicates the user has read and write access but not execute access
  * the next 3 indicate group access
    * `rw-` indicates the group has read and write access but not execute access
  * the last 3 indicate world access
    * `r--` indicates that everyone can read the file but write and execute access do not apply to users outside the group

Only the file's owner or a superuser can change the mode of a file or directory
* can be set with octal or symbolic notation
  * octal notation
    * 0 -> 000 -> ---
    * 1 -> 001 -> --x
    * 2 -> 010 -> -w-
    * 3 -> 011 -> -wx
    * 4 -> 100 -> r--
    * 5 -> 101 -> r-x
    * 6 -> 110 -> rw-
    * 7 -> 111 -> rwx
  * so `chmod 600 foo.txt` means give `rw-` to user and `---` to group and all others

The `umask` command controls the default permissions given to a file when it is created
* it uses octal notation to express a mask of bits to be removed from a file's mode attributes

### Changing Identities
At various times, we may find it necessary to take on the identity of another user
* often we want to gain superuser privileges to carry out some administrative task
* it is also possible to become another regular user to perform such tasks as testing an account

There are 3 ways to take on an alternate identity
* log out and log back in as the alternate user
* use the `su` command
  * the `su` command allows you to assume the identity of another user and either start a new shell session with that user's ID or issue a single command as that user
* use the `sudo` command
  * the `sudo` command allows an administrator to set up a configuration file called `/etc/sudoers` and define specific commands that particular users are permitted to execute under an assumed identity

The `chown` command is used to change the owner and group owner of a file or directory
* superuser privileges are required to use this command
* one user copying a file to user tony and making him owner
  * `sudo cp myfile.txt ~tony`
  * `sudo chown tony: ~tony/myfile.txt`
