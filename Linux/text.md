# Text

### Regular Expressions
Regular expressions are symbolic notations used to identify patterns in text
* regular expressions can contain
  * literals: actual characters to match
  * metacharacters: used to specify more complex matches
    * the metacharacters are: `^`, `$`, `.`, `[`, `]`, `{`, `}`, `-`, `?`, `*`, `+`, `(`, `)`, `|`, `\`

Regular expression metacharacters
* `.` (any character)
  * used to match any character
  * `grep -h '.zip' dirlist*.txt`
    * matches any line that contains any character followed by `zip`
    * that is it must have contain `<x>zip` where `<x>` is an arbitrary character
* `^` and `$` (anchors)
  * `^` matches only if the regular expression is found at the beginning of the line
  * `$` matches only if the regular expression is found at the end of the line
  * `grep -h '^zip' dirlist*.txt` matches lines that begin with `zip`
  * `grep -h 'zip$' dirlist*.txt` matches lines that end with `zip`
  * `grep -h '^zip$' dirlist*.txt` matches lines that start and end with `zip` (ie the line is just `zip`)
* bracket expressions and character classes
  * with bracket expressions we can specify a set of characters to be matched
  * `grep -h '[bg]zip' dirlist*.txt` matches lines containing `bzip` or `gzip`
  * the `^` inside brackets indicates negation
    * `grep -h '[^bg]zip' dirlist*.txt` matches lines that contain `<x>zip` where `<x>` is any character other than `b` or `g`
  * `-` is used to indicate a character range
    * `grep -h '^[A-Z]' dirlist*.txt` matches all lines that start with an uppercase character
    * `grep -h '^[A-Za-z0-9]' dirlist*.txt` matches all lines that begin with a letter or number
* alternation
  * the facility that allows a match to occur from among a set of expressions
  * it allows matches from a set of strings or other regular expressions
  * `echo "AAA" | grep -E 'AAA|BBB'` matches either string AAA or string BBB
  * `grep -Eh '^(bz|gz|zip)' dirlist*.txt` matches filenames that start with either `bz`, `gz`, or `zip`
* quantifiers
  * `?` - match an element zero times or one time
    * `echo "(555) 123-4567" | grep -E '^\(?[0-9][0-9][0-9]\)? [0-9][0-9][0-9]-[0-9][0-9][0-9][0-9]$'` matches phone numbers of the form `(nnn) nnn-nnnn` or `nnn nnn-nnnn`
  * `*` - match and element zero or more times
    * `echo "This works." | grep -E [[:upper:]][[:upper:][:lower:]]*\.` matches sentences that start with an upper case letter `[[:upper:]]`, have any number of additional upper or lower case characters `[[:upper:][:lower:]]*`, and ends with a period `\.`
  * `+` - match an element one or more times
    * pretty much the same as `*` but needs at least 1 match
    * `echo "This that" | grep -E '^([[:alpha:]]+ ?)+$'` matches lines consisting of one or more alphabet characters `[[:alpha:]]+` separated by single spaces ` ?`
  * `{}` - match an element a specific number of times
    * `echo "(555) 123-4567" | grep -E '^\(?[0-9]{3}\)? [0-9]{3}-[0-9]{4}$'` matches same phone numbers as before

The `find` command supports a test based on a regular expression
* `grep` will print a line when the line contains a string that matches an expression
* `find` requires that the pathname exactly match the regular expression
* `find . -regex '.*[^-_./0-9a-zA-Z].*'` find every pathname that contains any character that is not a member of the set `[-_./0-9a-zA-Z]`

The `locate` program supports both basic (the `--regexp` option) and extended (the `--regex` option) regular expressions

### Text Processing
`cat -ns foo.txt` numbers the lines of `foo.txt` (`n` option) and compresses multiple consecutive blank lines to a single blank line (`s` option)

`sort file1.txt file2.txt file3.txt > final_sorted_list.txt` merges the files `file1.txt`, `file2.txt`, and `file3.txt` into a single sorted file

`ls -l /usr/bin | sort -nr -k 5 | head` sort the contents of `ls -l /usr/bin` numerically in reverse order according to the 5th field (file size) and display the top 10
* so this equates to looking at the 10 largest files/directories

`sort -k 3.7nbr -k 3.1nbr -k 3.4nbr distros.txt`
* sort starting from the 7th position in the 3rd field (`-k 3.7`), then the 1st position in the 3rd field, then the 4th position in the 3rd field
* the `nbr` option is to sort numerically (`n`), ignoring leading blank spaces (`b`), and in reverse order (`r`)

For `uniq` to work, the input must first be sorted
* `sort foo.txt | uniq`

`cut` is best used to extract text from files that are produced by other programs, rather than text directly typed by humans
* `cut -f 3 distros.txt` - extracts the third field from `distros.txt` where the default delimiter is tab
  * say this produces dates in the form `dd/mm/yyyy`
  * then the command `cut -f 3 distros.txt | cut -c 7-10` extracts the year
* `cut -d ':' -f 1 /etc/passwd | head` extracts the first field from `/etc/passwd`, assuming the file is delimited by `':'`
