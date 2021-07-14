#define PAGE_PRESENT  0
#define PAGE_PROT     1
#define PAGE_RW       2
#define PAGE_USER     3
#define PAGE_DIRTY    4
#define PAGE_ACCESSED 5

// function-like macro
// define a function SET
// the bit at the position identified by the parameter `flag` is set in the variable `var`
#define SET(var, flag)   ((var) |= 1 << (flag))

int main() {
  int page_flag = 0;
  // the set macro is used as if it were a function
  // this line will become `((page_flag) |= 1 << ( 3));`
  SET(page_flag, PAGE_USER);
  printf("PAGE_USER: %d\n", page_flag);

  page_flag = 0;
  SET(page_flag, PAGE_DIRTY);
  printf("PAGE_DIRTY: %d\n", page_flag);

  return 0;
}
