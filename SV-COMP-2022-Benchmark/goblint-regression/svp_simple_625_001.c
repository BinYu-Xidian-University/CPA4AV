
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }



int g = 2; 

void svp_simple_625_001_isr_1(void *arg) {

  g = 1;

  g = 2;

}

int svp_simple_625_001_main(void) {

  __VERIFIER_assert(g == 2);
  return 0;
}
