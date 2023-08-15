int data;

void svp_simple_547_001_isr_1(void *arg)
{
  int tmp = data + 1;
  data = tmp;
  // data++; // RACE!
}

int svp_simple_547_001_main()
{
  int tmp = data + 1;
  data = tmp;
  // data++; // RACE!

  return 0;
}
