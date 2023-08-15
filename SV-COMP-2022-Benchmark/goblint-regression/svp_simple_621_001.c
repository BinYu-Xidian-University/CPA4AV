extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

int g = 0; 

void svp_simple_621_001_isr_1(void *arg) {
  g = 42;
}

int svp_simple_621_001_main(void) {
  g = 2;
  __VERIFIER_assert(g == 2);
  return 0;
}
