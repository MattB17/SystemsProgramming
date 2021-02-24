# Redirection And Piping

### Redirection
I/O redirection lets user specify where standard output goes
* use `>` to redicted standard output to another file instead of the screen
* `ls -l /usr/bin > ls-output.txt` sends the output of `ls -l /usr/bin` to the file `ls-output.txt`
* errors are not sent to standard output but instead standard error
  * so if the command has an error it will still be printed to the screen, not sent to the file
* `>` overwrites a file
* `>>` appends to a file

Standard error can be redirected using `2>`
* `ls -l /bin/usr 2> ls-error.txt` redirects any errors from the `ls -l /bin/usr` command to `ls-error.txt`
* `ls -l /bin/usr > ls-error.txt 2>&1` performs 2 redirections
  * standard output is redirected to `ls-error.txt` with `> ls-error.txt`
  * standard error is redirected to standard output with `2>&1`

We can also affect standard input
* `cat movie.mpeg.0* > movie.mpeg` concatenates all files of the form `movie.mpeg.0XXX` into the file `movie.mpeg`
* `cat` redirects standard input to standard output
* `cat < ls-output.txt` redirects contents of `ls-output.txt` to standard output

### Piping
Using the pipe operator `|`, the standard output of one command can be piped into the standard input of another
* `ls /bin /usr/bin | sort | uniq | wc -l`
  * gets the contents of `/bin` and `/usr/bin`
  * then sorts these files by name
  * selects the unique files from the sorted result
  * then counts the number of unique files
* `ls /bin /usr/bin | sort | uniq | grep zip`
  * lists all unique files in `/bin` and `/usr/bin` that have a name containing `zip`
* `ls /usr/bin | tail -n 5`
  * lists the last 5 files in `/usr/bin`
* `ls /usr/bin | tee ls.txt | grep zip`
  * lists all files of `/usr/bin` in `ls.txt`
  * then outputs a list of those files that contain `zip`
