extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

extern int __VERIFIER_nondet_int();


int glob1 = 0;

void svp_simple_604_001_isr_1(void *arg) {
  int t = __VERIFIER_nondet_int();

  if(t == 42) {
      glob1 = 1;
  }
  t = glob1;


  glob1 = 0;
}

int svp_simple_604_001_main(void) {
  return 0;
}
