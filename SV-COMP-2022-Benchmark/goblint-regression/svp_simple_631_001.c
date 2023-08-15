
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }



int g = 3; 

void svp_simple_631_001_isr_1(void *arg) {

  g = 1;

  g = 2;

  g = 3;

}

int svp_simple_631_001_main(void) {

  __VERIFIER_assert(g == 3);

  __VERIFIER_assert(g == 3);
  return 0;
}
