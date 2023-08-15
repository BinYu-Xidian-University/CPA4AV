# 1 "svp_simple_006_001.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "svp_simple_006_001.c"
extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();
# 22 "svp_simple_006_001.c"
volatile int svp_simple_006_001_global_var1;
volatile int svp_simple_006_001_global_var2;
volatile unsigned char flag = 0x55;
void svp_simple_006_001_main() {
  init();
  int reader1, reader2;

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      if (i == j) {
        if (i == 0)
          reader1 = svp_simple_006_001_global_var1;
        else if (i == 4)
          reader2 = svp_simple_006_001_global_var1;
        else if (i == 6)
          reader2 = svp_simple_006_001_global_var1;
      }
    }

  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++) {
      if (((i + j) == 6) && (i < j))
        svp_simple_006_001_global_var2 = 0x02;
    }
}

void svp_simple_001_001_isr_1() {
  int reader2;


  svp_simple_006_001_global_var1 = 0;
  reader2 = svp_simple_006_001_global_var2;
}
void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 10; i++) {

  }
}
