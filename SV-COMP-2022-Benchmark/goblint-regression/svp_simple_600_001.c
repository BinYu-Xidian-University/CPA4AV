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


void isr__VERIFIER_assert(int cond)
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

int glob1 = 5;

void svp_simple_600_001_isr_1(void *arg)
{
  int t;
  t = glob1;
  isr__VERIFIER_assert(t == 5);
  glob1 = -10;
  isr_VERIFIER_assert(glob1 == -10);
  glob1 = t;
}

int svp_simple_600_001_main(void)
{

  __VERIFIER_assert(glob1 == 5);
  int tmp = glob1 + 1;
  glob1 = tmp;
  // glob1++;
  __VERIFIER_assert(glob1 == 6);
  int tmp1 = glob1 - 1;
  glob1 = tmp1;
  // glob1--;

  return 0;
}
