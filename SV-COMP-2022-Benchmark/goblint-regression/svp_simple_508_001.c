
int myglobal;


void svp_simple_508_001_isr_1(void *arg) {
  myglobal=myglobal+1; // NORACE

}

int svp_simple_508_001_main(void) {

  myglobal=myglobal+1; // NORACE

  return 0;
}
