extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();









void svp_simple_028_001_init();

volatile int svp_simple_028_001_isr_1_flag;
volatile int svp_simple_028_001_gloable_var;


int svp_simple_028_001_main() {
  svp_simple_028_001_init();

  disable_isr(-1);
  enable_isr(1);
  if (svp_simple_028_001_gloable_var > 12) {  
    svp_simple_028_001_gloable_var = 0;     
  }
  return 0;
}

void svp_simple_028_001_init() {
  svp_simple_028_001_gloable_var = rand();
  svp_simple_028_001_isr_1_flag = rand();

  init();
}

void svp_simple_001_001_isr_1() {
  svp_simple_028_001_gloable_var++; 
  svp_simple_028_001_isr_1_flag = 0;
  enable_isr(2);
}
void svp_simple_001_001_isr_2() {
  if (svp_simple_028_001_isr_1_flag) {
    svp_simple_028_001_gloable_var++;  
  }
}

//bug points:
// 1.svp_simple_028_001_gloable_var <R, #30>, <W, #44>, <W, #31>

//possible false positive points:
// 1.svp_simple_028_001_gloable_var <R, #29>, <W, #49>, <W, #30>
// 2.svp_simple_028_001_gloable_var <R, #29>, <W, #53>, <W, #30>