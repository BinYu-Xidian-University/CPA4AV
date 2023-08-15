

int myglobal;


void munge() {

  myglobal=myglobal+1; // NORACE

}

void svp_simple_510_001_isr_1(void *arg) {
  munge();

}


int svp_simple_510_001_main(void) {

  munge();

  return 0;
}
