# 1 "svp_simple_017_001.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "svp_simple_017_001.c"
extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();
# 22 "svp_simple_017_001.c"
volatile int svp_simple_017_001_global_var;
volatile int svp_simple_017_001_local_array[10];

void svp_simple_017_001_main() {
  init();
  int i = 0;

  for (svp_simple_017_001_global_var = 0; svp_simple_017_001_global_var < 10;
       svp_simple_017_001_global_var++)
  {
    svp_simple_017_001_local_array[svp_simple_017_001_global_var] = i++;
  }
}

void svp_simple_001_001_isr_1() {


  svp_simple_017_001_global_var = 5;

  svp_simple_017_001_local_array[5] = 0;
}
void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 10; i++) {

  }
}
