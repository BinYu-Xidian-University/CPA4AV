extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);
extern int __VERIFIER_nondet_int();
extern int rand();

void init();









void svp_simple_028_001_init();

volatile int svp_simple_028_001_isr_1_flag;
volatile int svp_simple_028_001_gloable_var;
volatile int svp_simple_028_001_gloable_final;

int svp_simple_028_001_main() {
  svp_simple_028_001_init();

//  disable_isr(-1);
//  enable_isr(2);
  if (svp_simple_028_001_gloable_var > 12) {
    svp_simple_028_001_gloable_var = 0;
  }
  return 0;
}

void svp_simple_028_001_init() {
  svp_simple_028_001_gloable_var = __VERIFER_nondet_int();
  svp_simple_028_001_isr_1_flag = __VERIFER_nondet_int();

  init();
}

void svp_simple_028_001_isr_1() {
  int tmp = svp_simple_028_001_gloable_final+1;
  svp_simple_028_001_gloable_final = tmp;
}
void svp_simple_028_001_isr_2() {
  if (svp_simple_028_001_isr_1_flag) {
    int tmp = svp_simple_028_001_gloable_var+1;
    svp_simple_028_001_gloable_var = svp_simple_028_001_gloable_var;
  }
}
void svp_simple_028_001_isr_3() {
  int tmp = svp_simple_028_001_gloable_var+1;
  svp_simple_028_001_gloable_var = svp_simple_028_001_gloable_var;
  svp_simple_028_001_gloable_final = 3;
}
