// sets kth bit of var to 1
unsigned char setbit(unsigned char var, int k) {
  var = var | (1 << k);
  return var;
}

// determines if the kth bit of var is 1
int checkbit(unsigned char var, int k) {
  return var & (1 << k);
}
