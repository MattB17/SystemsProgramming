#define S_IRUSR 0000400 // R for owner
#define S_IRGRP 0000040 // R for group
#define S_IROTH 0000004 // R for other

// generate a read-only permissions for a file
mode_t mode = S_IRUSR | S_IRGRP | S_IROTH;
//          = 0400 | 040 | 004
//          = 0444

// given a mode variable, do the group or other users have read permissions?
mode & (S_IRGRP | S_IROTH) // -> mode & (040 | 004) -> mode & 044
