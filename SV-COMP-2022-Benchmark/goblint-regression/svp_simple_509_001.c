

int myglobal;


void munge() {
  int tmp = myglobal+1;
  myglobal=tmp; 
  // myglobal=myglobal+1; // RACE!

}
void isr_munge() {
  int tmp = myglobal+1;
  myglobal=tmp; 
  // myglobal=myglobal+1; // RACE!

}

void svp_simple_509_001_isr_1(void *arg) {
  isr_munge();
  // return NULL;
}


int svp_simple_509_001_main(void) {

  munge();
  return 0;
}
