# Linux File System Properties
Unix-like systems such as Linux always have a single file system tree, regardless of how many drives or storage devices are attached to the computer

Storage devices are attached (mounted) at various points on the tree

Each formatted partition or device using a Linux filesystem, such as ext3, will have the `/lost+found` directory
* It is used in the case of a partial recovery from a filesystem corruption event
* Unless something really bad has happened to your system, this directory will remain empty

### Fragmentation
3 types of fragmentation
1. **File fragmentation:** happens when logically sequential blocks of a file are not allocated to sequential blocks on disk
  * leads to poor sequential read performance, since many disk seeks are needed to read all the blocks in the file
2. **External fragmentation:** happens when the free space is broken up into (possibly many) small extents
  * can lead to file fragmentation because it is hard or impossible to allocate large extents to files
3. **Internal fragmentation:** happens when the unit of allocation is larger than needed for the thing being stored in it
  * Eg. Allocating full block to hold 32 bits of inode map

Fragmentation rules with extents:
1. Extend an extent if possible - keeps file fragmentation low
2. Allocate a single extent if possible
3. Prefer not to break up large extents

Adjacent free extents should be coalesced into a single extent
* happens naturally with bitmaps
* requires more effort if you have a linked list of free extents

### Links
By default, every file has a single hard link that gives the file its name
* when we create a hard link, we create an additional directory entry for the file

Hard links have 2 limitations:
* a hard link cannot reference a file outside its own filesystem
  * this means a link cannot reference a file that is not on the same disk partition as the link itself
* a hard link cannot reference a directory

A hard link is indistinguishable from the file itself
* unlike a directory list containing a symbolic link, a directory list containing a hard link shows no special indication of the link
* when a hard link is deleted, the link is removed, but the contents of the file itself continue to exist (its space is not deallocated) until all links to the file are deleted

When thinking about hard links, think of files as 2 parts: the data part with the file's contents, and the name part holding the file's name
* when we create hard links we are creating additional name parts that all point to the same data part
* the system associates a chain of disk block to an inode which is then associated with the name part
* each hard link refers to a specific inode containing the file's contents

Symbolic links work by creating a special type of file that contains a text pointer to the referenced file or directory
* a file pointed to by a symbolic link and the symbolic link itself are largely indistinguishable from one another
* if you write something to the symbolic link, the referenced file is also written to
* when you delete a symbolic link, only the link is deleted, not the file itself
* if the file is deleted before the symbolic link, the link will continue to exist but will point to nothing - it is said to be broken

Symbolic links were created to overcome the 2 disadvantages of hard links
* hard links can't span physical devices
* hard links can't reference directories, only files
