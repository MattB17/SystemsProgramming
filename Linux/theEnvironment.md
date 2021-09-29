# The Environment
The shell maintains a body of information during our shell session called the environment
* data stored in the environment is used by programs to determine facts about our configuration

The shell stores 2 basic types of data in the environment
* shell variables
  * bits of data placed there by bash
* environment variables

In addition to variables, the shell also stores some programmatic data - aliases and shell functions

When we log on to the system, the bash program starts and reads a series of configuration scripts called startup files - which define the default environment shared by all users
* this is followed by more startup files in our home directory that define our personal environment

There are 2 kinds of shell sessions
* a login shell session
  * one in which we are prompted for our username and password
* a non-login shell session
  * typically occurs when we launch a terminal session in the GUI
  * they inherit the environment from their parent process, usually a login shell

When we enter a command on the command line, bash does not search the whole computer for the command
* it searches a list of directories that are contained in the PATH variable
* `PATH=$PATH:$HOME/bin`
  * `PATH` is modified is modified to add the director `$HOME/bin` to the end of the list
  * now when bash searches for commands it will also search in `$HOME/bin`
* `export PATH`
  * tells the shell to make the contents of `PATH` available to child processes of this shell
