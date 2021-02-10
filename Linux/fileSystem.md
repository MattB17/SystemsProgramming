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
