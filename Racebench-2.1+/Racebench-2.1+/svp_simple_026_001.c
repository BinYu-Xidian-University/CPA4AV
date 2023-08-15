extern void idlerun();
extern int __VERIFIER_nondet_int();
extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();














void svp_simple_026_001_init();

volatile int svp_simple_026_001_gloable_var;
int svp_simple_026_001_main() {
//  svp_simple_026_001_init();

  disable_isr(1);
  if (svp_simple_026_001_gloable_var > 12) {
    svp_simple_026_001_gloable_var = 0;
    svp_simple_026_001_gloable_var = 3;
  }
//  enable_isr(1);

  return 0;
}
void svp_simple_026_001_init() {
  svp_simple_026_001_gloable_var = 3;
  init();
}

void svp_simple_001_001_isr_1() {
  int tmp = svp_simple_026_001_gloable_var+1;
  svp_simple_026_001_gloable_var = tmp;
}
void svp_simple_001_001_isr_2() {
  svp_simple_026_001_gloable_var = 13;
  enable_isr(1);
}
void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 100; i++) {
    //		print2("Running....");
  }
}
