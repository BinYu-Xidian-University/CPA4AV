extern void idlerun();

extern void enable_isr(int);
extern int __VERIFIER_nondet_int();
extern void disable_isr(int);

extern int rand();

void init();












volatile int svp_simple_015_001_global_var1;
volatile int svp_simple_015_001_global_var2;
volatile int svp_simple_015_001_global_var3;

void svp_simple_015_001_main() {
  enable_isr(-1);

  int x = __VERIFER_nondet_int();
  int y = __VERIFER_nondet_int();
  int z;
  int p = __VERIFER_nondet_int();

  if ((svp_simple_015_001_global_var1 < y) &&
      (svp_simple_015_001_global_var1 > x))
    z = x + y;

  p == 1 ? svp_simple_015_001_global_var2 : svp_simple_015_001_global_var2;
}

void svp_simple_001_001_isr_1() {
  // idlerun();
  svp_simple_015_001_global_var1 = 5;
  svp_simple_015_001_global_var2 = 5;

}

void svp_simple_001_001_isr_2() {
  svp_simple_015_001_global_var3 = 6;
  svp_simple_015_001_global_var3 = 7;
}

void svp_simple_001_001_isr_3() {
  // idlerun();
  int reader1;
  reader1 = svp_simple_015_001_global_var3;
}

void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 100; i++) {
    //		print2("Running....");
  }
}
