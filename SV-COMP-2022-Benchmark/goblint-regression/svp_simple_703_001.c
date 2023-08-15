extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

extern int __VERIFIER_nondet_int();



void svp_simple_703_001_isr_1(void *arg) {
  int x = __VERIFIER_nondet_int(); 
  __VERIFIER_assert(!(x == 3));

}

int svp_simple_703_001_main(void) {
  int x = 3;


  return 0;
}
