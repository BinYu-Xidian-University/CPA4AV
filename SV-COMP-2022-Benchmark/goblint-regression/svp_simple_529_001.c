

int x;

void svp_simple_529_001_isr_1(void *arg) {
  int tmp = x+1;
  x = tmp;
  // x++; // RACE!

}

int svp_simple_529_001_main() {
  return 0;
}
