extern void idlerun();
extern int __VERIFIER_nondet_int();
extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();









volatile int svp_simple_016_001_global_var1;
volatile int svp_simple_016_001_global_var2;




void svp_simple_016_001_main() {
  init();
  int reader1;
  svp_simple_016_001_global_var1 = 0x01;
  int tmp1 = svp_simple_016_001_global_var1;
  int tmp2 = svp_simple_016_001_global_var1+tmp1;
  reader1 = svp_simple_016_001_global_var1+tmp2;

}

void svp_simple_001_001_isr_1() {
  // idlerun();
  svp_simple_016_001_global_var1 = 0x09;
}

void svp_simple_001_001_isr_2() {
  // idlerun();
  svp_simple_016_001_global_var2 = 0x09;
  svp_simple_016_001_global_var2 = 3;
}

void svp_simple_001_001_isr_3() {
  // idlerun();
  int reader1;
  reader1 = svp_simple_016_001_global_var2;
}




void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 100; i++) {
    //		print2("Running....");
  }
}
