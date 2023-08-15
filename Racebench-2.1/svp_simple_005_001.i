# 1 "svp_simple_005_001.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "svp_simple_005_001.c"
extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();
# 21 "svp_simple_005_001.c"
volatile int svp_simple_005_001_global_condition = 0;

volatile int svp_simple_005_001_global_var;

void svp_simple_005_001_main() {
  init();
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if ((i == 9) && (j == 1))
        svp_simple_005_001_global_var = 0x01;
    }
  }

  if (svp_simple_005_001_global_condition ==
      1)
    svp_simple_005_001_global_var = 0x09;

  svp_simple_005_001_global_var = 0x05;
}

void svp_simple_001_001_isr_1() {
  idlerun();
  int reader;
  reader = svp_simple_005_001_global_var;
}

void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 10; i++) {

  }
}
