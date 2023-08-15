
extern int __VERIFIER_nondet_int();

int myglobal;


void isr_fun(void) {
  int i = __VERIFIER_nondet_int();
  int tmp = myglobal+1;
  myglobal=tmp; 
  // myglobal=myglobal+1; 
}

void svp_simple_505_001_isr_1(void *arg) {

  // myglobal=myglobal+1; 
  int tmp = myglobal+1;
  myglobal=tmp; 

  isr_fun();

}

int svp_simple_505_001_main(void) {

  // myglobal=myglobal+1;
  int tmp = myglobal+1;
  myglobal=tmp; 


  return 0;
}
