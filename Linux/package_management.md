# Package Management
Package management is a method of installing and maintaining software on the system

Virtually all software for a Linux system is found on the Internet
* most of it is provided by the distribution vendor in the form of package files
* the rest is available in source code form which can be installed manually

The basic unit of software in a packaging system is the package file
* a package file is a compressed collection of files that comprise the software package
* a package may consist of numerous programs and data files that support the programs
* the package file also contains metadata about the package - such as a text description of the package and its contents
* many packages contain pre- and post-installation scripts that perform configuration tasks before and after the package installation

Package files are created by a package maintainer
* the package maintainer gets the software in source code form from the upstream provider (the author of the program), compiles it, and creates the package metadata and any necessary installation scripts

Packages are made available to the users of a distribution in central repositories, which may contain many thousands of packages, each specially built and maintained for the distribution
* a distribution may maintain several different repositories for different stages of the software development life cycle

Programs seldom stand alone
* instead, they rely on the presence of other software components to get their work done
* common activities such as input/output are handled by routines shared by many programs
* these routines are stored in what are called shared libraries, which provide essential services to more than one program
* if a package requires a shared resource such as a shared library, it is said to have a dependency
* modern package management systems all provide some method of dependency resolution to ensure that when a package is installed, all of its dependencies are installed too

Package management systems usually consist of 2 types of tools
* low-level tools that handle tasks such as installing and removing package files
* high-level tools that perform metadata searching and dependency resolution
