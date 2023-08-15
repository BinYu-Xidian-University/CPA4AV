
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

extern int __VERIFIER_nondet_int();


int g;

void svp_simple_697_001_isr_1(void *arg) {
    g=1;
}

int svp_simple_697_001_main(void) {
  int x = __VERIFIER_nondet_int(); // rand
  int y = __VERIFIER_nondet_int(); //rand
  int r = __VERIFIER_nondet_int(); //rand

  g = r;

  x = g;
  y = g;
  __VERIFIER_assert(x == y);
  return 0;
}
