extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();












volatile int svp_simple_015_001_global_var1;
volatile int svp_simple_015_001_global_var2;

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
//  idlerun();
  svp_simple_015_001_global_var1 = 5;
  svp_simple_015_001_global_var2 = 5;
}
void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 10; i++) {
    //		print2("Running....");
  }
}
// bug points:
//1.svp_simple_015_001_global_var1<R#33>,<W#42>,<R#34>
// possible false positive points:
//1.svp_simple_015_001_global_var2<R#34>,<W#40>,<R#34>