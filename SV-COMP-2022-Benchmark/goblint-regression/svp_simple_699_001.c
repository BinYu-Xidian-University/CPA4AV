
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

extern int __VERIFIER_nondet_int();


int g = 42; 

void svp_simple_699_001_isr_1(void *arg) {

  g = 42;
}

int svp_simple_699_001_main(void) {
  int r = __VERIFIER_nondet_int(); 
  int t;
  if (r) {
    g = 17;

  }

  t = g;
  __VERIFIER_assert(t == 17);

  return 0;
}
