#include <stdio.h>

#define WARN(cond) \
  // even though the do while is only executed once it ensures that `WARN`
  // is executed as a statement.
  // another reason would be to allow the macro to include multiple statements
  do { \
      // #cond is the stringification operator - it preserves the argument as
      // a string, so the literal condition will be printed
      if (cond) fprintf(stderr, "Warning (%s:%d): %s\n", __FILE__, __LINE__, #cond); \
  } while (0) // 0 is false, so it only executes once

#define PAGE_PRESENT  0
#define PAGE_PROT     1
#define PAGE_RW       2
#define PAGE_USER     3
#define PAGE_DIRTY    4
#define PAGE_ACCESSED 5

#define SET(var, flag)   ((var) |= 1 << flag))
#define ISSET(var, flag) ((var) & (1 << (flag)))

int main() {
  int page_flag = 0;
  SET(page_flag, PAGE_USER);
  printf("PAGE_USER: %d\n", page_flag);

  // warning message tells us that PAGE_USER is set
  WARN(ISSET(page_flag, PAGE_USER));

  return 0;
}
