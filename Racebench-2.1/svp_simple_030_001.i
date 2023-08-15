# 1 "svp_simple_030_001.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "svp_simple_030_001.c"
extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();
# 19 "svp_simple_030_001.c"
void svp_simple_030_001_init();
void isr_addData();
volatile int svp_simple_030_001_isr_1_flag;
volatile int svp_simple_030_001_gloable_var;


int svp_simple_030_001_main() {
  svp_simple_030_001_init();

  disable_isr(-1);
  enable_isr(1);
  if (svp_simple_030_001_gloable_var > 12) {
    svp_simple_030_001_gloable_var = 0;
  }
  return 0;
}

void svp_simple_030_001_init() {
  svp_simple_030_001_gloable_var = __VERIFER_nondet_int();
  svp_simple_030_001_isr_1_flag = __VERIFER_nondet_int();

  init();
}

void isr_addData() {
  svp_simple_030_001_gloable_var++;
}

void svp_simple_001_001_isr_1() {
  isr_addData();
  svp_simple_030_001_isr_1_flag = 0;
  enable_isr(2);
}
void svp_simple_001_001_isr_2() {
  if (svp_simple_030_001_isr_1_flag) {
    svp_simple_030_001_gloable_var++;
  }
}
void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 10; i++) {

  }
}
