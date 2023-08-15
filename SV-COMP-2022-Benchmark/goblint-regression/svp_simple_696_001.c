
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }



int g = 1;


void svp_simple_696_001_isr_1(void *arg) {

  g = 2;
  __VERIFIER_assert(g == 2);
}

int svp_simple_696_001_main(void) {
  int x, y;
  x = g;
  y = g;
  __VERIFIER_assert(x == y);

  int tmp = g-x;
  int tmp1 = tmp -g;
  g = tmp1;

  return 0;
}
