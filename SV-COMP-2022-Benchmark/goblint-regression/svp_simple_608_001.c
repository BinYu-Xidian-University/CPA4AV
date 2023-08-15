extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond)
{
  if (!(cond))
  {
  ERROR:
  {
    reach_error();
    abort();
  }
  }
}

int glob1 = 0;

void svp_simple_608_001_isr_1(void *arg)
{

  glob1 = 5;

  __VERIFIER_assert(glob1 == 5);
  glob1 = 0;
}

int svp_simple_608_001_main(void)
{

  __VERIFIER_assert(glob1 == 0);

  return 0;
}
