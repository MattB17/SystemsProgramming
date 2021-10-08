# Storage Media
Linux has amazing capabilities for handling storage devices, whether physical storage such as hard disks, network storage, or virtual storage devices like RAID (redundant array of independent disks) and LVM (logical volume manager)

The first step in managing a storage device is attaching the device to the filesystem tree
* this process, called mounting, allows the device to participate with the operating system
* Unix-like operating systems, like Linux, maintain a single filesystem tree with devices attached at various points
* this contrast other operating systems such as MS-DOS and Windows that maintain separate trees for each device

A file named `/etc/fstab` lists the devices (typically hard disk partitions) that are to be mounted at boot time

A mount point is a directory somewhere on the filesystem tree
* it doesn't have to be an empty directory, though if you mount a device on a non-empty directory, you will not be able to see the directory's previous contents until you unmount the device

Operating systems store data that been read from, and is to be written to, storage devices in memory for as long as possible before actually having to interact with the slower device
* this buffering allows writing to storage devices to be done very quickly, because the writing to the physical device is being deferred to a future time
* in the meantime, the data destined for the device is piling up in memory
* from time to time, the operating system will write this data to the physical device

Unmounting a device entails writing all the remaining data to the device so that it can be safely removed
* if the device is removed without first being unmounted, the possibility exists that not all the data destined for the device has been transferred
* in some cases, this data may include vital directory updates, which will lead to filesystem corruption

The `fdisk` program allows us to interact directly with disk-like devices (such as hard disk drives and flash drives) at a very low level
* with this tool we can edit, delete, and create partitions on the device

`mkfs` can create filesystems in a variety of formats
* it is short for make filesystem

Each time the system boots, it routinely checks the integrity of the filesystems before mounting them
* this is done by the `fsck` program (short for filesystem check)
* the last number in each `/etc/fstab` entry specifies the order in which the devices are to be checked
  * devices with a zero as the last digit are not routinely checked
* `fsck` can also repair corrupt filesystems with varying degrees of success, depending on the amount of damage
* on Unix-like filesystems, recovered portions of files are placed in the `lost+found` directory, located in the root of each filesystem
* on most systems, filesystem corruption detected at boot time will cause the system to stop and direct you to run `fsck` before continuing

`dd` copies blocks pf data from one place to another
* the syntax is `dd if=<input_file> of=<output_file> [bs=<block_size> [count=<blocks>]]`
* copy everything one one drive to another `dd if=/dev/sdb of=/dev/sdc`