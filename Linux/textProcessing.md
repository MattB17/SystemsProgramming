# Text Processing

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
