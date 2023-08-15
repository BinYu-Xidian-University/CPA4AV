
int x = 1;

void svp_simple_601_001_isr_1(void *arg)
{

  if (x == 1)
  { // NORACE
  }

  x = -1; // NORACE
}

int svp_simple_601_001_main(void)
{
  assert(x == 1);

  x = 0; // NORACE
  assert(x == 0);
  x = 1; // NORACE

  return 0;
}
