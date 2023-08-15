int myglobal;
int debug;

void svp_simple_538_001_isr_1(void *arg) {
  int tmp=myglobal+1;
  myglobal = tmp;
  // myglobal=myglobal+1; // NORACE

  debug = 3;  // add

}

int svp_simple_538_001_main(void) {

  debug = 0; // NORACE

  int tmp=myglobal+1;
  myglobal = tmp;
  // myglobal=myglobal+1; // NORACE

  int tmp1=debug+1;
  debug = tmp1;
  // debug++; // NORACE
  return 0;
}
