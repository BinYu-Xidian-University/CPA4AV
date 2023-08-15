extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

int g2;

void svp_simple_619_001_isr_1(void *arg) {

  int tmp3 = g2 + 1;
  g2 = tmp3;
  // g2++;

  int tmp4 = g2 - 1;
  g2 = tmp4;
  // g2--;

}

int svp_simple_619_001_main(void) {

  __VERIFIER_assert(g2 == 0);

  return 0;
}