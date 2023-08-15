extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

extern int __VERIFIER_nondet_int();

int g = 42;

void svp_simple_622_001_isr_1(void *arg)
{

  g = 15;

  g = 42;
}

int svp_simple_622_001_main(void)
{
  __VERIFIER_assert(g == 42);
  return 0;
}
