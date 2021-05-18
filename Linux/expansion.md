# Exapnsion
`$((expression))` evaluates `expression`
* `echo $((2 + 2))` evaluates to 4
* `echo $(((5**2) * 3))` evaluate to 75 -> (5*5)*3
* `echo Five divided by two equals $((5/2)) with $((5%2)) left over` - integer division and modulo arithmetic

We can also make use of brace expansion
* `echo Front-{A,B,C}-Back` prints `Front-A-Back Front-B-Back Front-C-Back`
* `echo Number_{1..5}` prints `Number_1 Number_2 Number_3 Number_4 Number_5`
* `echo {Z..A}` prints the alphabet in reverse order
* `echo a{A{1,2},B{3,4}}b` prints `aA1b aA2b aB3b aB4b`
* `mkdir {2009..2011}-0{1..9} {2009..2011}-{10..12}` makes a directory for every month from 2009-01 to 2011-12

We can also expand parameters / variables
* `echo $USER` prints your username

Expansion also works for an entire command
* `command1 $(command2)` executes `command2` and passes the result as arguments to `command1`
* `ls -l $(which cp)` retrieves the listing of the `cp` program
* `file $(ls /usr/bin/* | grep zip)` passes all the files in `/usr/bin` containing zip to the `file` command
