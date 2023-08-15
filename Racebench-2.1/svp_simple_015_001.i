# 1 "svp_simple_015_001.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "svp_simple_015_001.c"
extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();
# 22 "svp_simple_015_001.c"
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

  svp_simple_015_001_global_var1 = 5;
  svp_simple_015_001_global_var2 = 5;
}
void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 10; i++) {

  }
}
