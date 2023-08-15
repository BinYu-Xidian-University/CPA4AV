int g1,g2;

void svp_simple_537_001_isr_1(void *arg) {
  int tmp1 = g1+1;
  g1 = tmp1;
  // g1++; // NORACE

  int tmp2 = g2+1;
  g2 = tmp2;
  // g2++; // NORACE

}

int svp_simple_537_001_main(void) {

  g1=g2+1; // NORACE

  return 0;
}

