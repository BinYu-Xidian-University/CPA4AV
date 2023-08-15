
int myglobal;

int f(int x) {
  return 5;
}
void svp_simple_542_001_isr_1(void *arg) {
    myglobal=f(myglobal);
    if(myglobal == 5){
          int tmp = 1;
    }
}

int svp_simple_542_001_main(void) {
//  int tmp=myglobal+1;
//  myglobal = tmp;

  myglobal = f(myglobal);
  myglobal = f(myglobal);
  return 0;
}