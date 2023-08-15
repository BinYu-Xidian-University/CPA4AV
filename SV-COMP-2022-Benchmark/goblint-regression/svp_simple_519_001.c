
int myglobal;


void svp_simple_519_001_isr_1(void *arg) {
  myglobal=myglobal+1; // NORACE
}

int add1 (int x) {
  return x+1;
}

int svp_simple_519_001_main(void) {

  printf("myglobal equals %dn",myglobal); // NORACE

  add1(myglobal); // NORACE

  return 0;
}
