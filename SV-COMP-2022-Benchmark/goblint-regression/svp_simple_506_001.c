

extern void exit (int status);

int glob;


void f() {
  int tmp = glob+1;
  glob = glob+1;
  // glob++; 

  exit(0);
}

void svp_simple_506_001_isr_1(void *arg) {
  int tmp = glob+1;
  glob=glob+1;
  // glob++;

}

int svp_simple_506_001_main(void) {

  // while () {
  //   f();
  // }
  f();
  
  glob = 8;
  return 0;
}
