static int data1;
static int data2;

void svp_simple_545_001_isr_1(void *arg)
{
  int tmp = data1 + 1;
  data1 = tmp;
  // data1++;            // NORACE
  printf("%d", data2); // NORACE
}

int svp_simple_545_001_main(void)
{

  printf("%d", data1); // NORACE
  int tmp = data2 + 1;
  data2 = tmp;
  // data2++;            // NORACE

  return 0;
}
