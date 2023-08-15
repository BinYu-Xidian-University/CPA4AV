

int myglobal;

void svp_simple_507_001_isr_1(void *arg)
{
  int tmp = myglobal + 1;
  myglobal = tmp;
  // myglobal=myglobal+1; // RACE!
}

int svp_simple_507_001_main(void)
{
  int tmp = myglobal + 1;
  myglobal = tmp;
  // myglobal=myglobal+1; // RACE!
}