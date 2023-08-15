int data;

void svp_simple_548_001_isr_1(void *arg)
{

  data++; // NORACE
}

int svp_simple_548_001_main()
{

  data++; // NORACE

  return 0;
}
