extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();











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
    //		print2("Running....");
  }
}

//bug points:
// 1.svp_simple_030_001_gloable_var <R, #30>, <W, #44>, <W, #31>

//possible false positive points:
// 1.svp_simple_030_001_gloable_var <R, #29>, <W, #52>, <W, #30>
// 2.svp_simple_030_001_gloable_var <R, #29>, <W, #56>, <W, #30>