# 1 "svp_simple_003_001.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "svp_simple_003_001.c"
extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();
# 20 "svp_simple_003_001.c"
volatile int svp_simple_003_001_global_var1;
volatile int svp_simple_003_001_global_var2;

volatile int svp_simple_003_001_global_flag = 1;
volatile int svp_simple_003_001_global_flag1 = 0;
void svp_simple_003_001_main() {
  init();
  int reader1, reader2;
  int reader3, reader4;
  idlerun();

  disable_isr(1);
  disable_isr(2);

  for (int i = 0; i < 100; i++) {
    if (i == 99) {
      reader3 = svp_simple_003_001_global_var2;
    }
  }
  for (int j = 100; j > 0; j--) {
    if (j == 99) {
      reader4 = svp_simple_003_001_global_var2;
    }
  }

  enable_isr(1);
  for (int i = 0; i < 100; i++) {
    if (i == 99) {
      reader1 = svp_simple_003_001_global_var1;
    }
  }
  for (int j = 100; j > 0; j--) {
    if (j == 99) {
      reader2 = svp_simple_003_001_global_var1;
    }
  }
}

void svp_simple_001_001_isr_1() {
  enable_isr(2);
  svp_simple_003_001_global_var2 = 999;

  if (svp_simple_003_001_global_flag == 1) {
    svp_simple_003_001_global_var1 = 999;
  } else if (svp_simple_003_001_global_flag1 == 2) {
    svp_simple_003_001_global_var1 = 888;
  }
}

void svp_simple_001_001_isr_2() {
  idlerun();
  svp_simple_003_001_global_flag = 1;
}
void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 10; i++) {

  }
}
