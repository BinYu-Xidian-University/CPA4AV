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

int g = 0;

void svp_simple_636_001_isr_1(void *arg)
{
  if (g == 1)
    g = 3;
}

int svp_simple_636_001_main()
{

  g = 1;

  g = 2;

  __VERIFIER_assert(g == 2);
  return 0;
}
