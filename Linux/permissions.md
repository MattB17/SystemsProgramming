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
