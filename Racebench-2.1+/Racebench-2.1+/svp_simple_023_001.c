extern void idlerun();
extern int __VERIFIER_nondet_int();
extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();








volatile int svp_simple_023_001_global_final;
volatile int svp_simple_023_001_global_var;
void svp_simple_023_001_func_1(int x);
void svp_simple_023_001_init();



void svp_simple_023_001_main() {
  svp_simple_023_001_init();
  svp_simple_023_001_func_1(svp_simple_023_001_global_var);
}
void svp_simple_023_001_init() {
  svp_simple_023_001_global_var = __VERIFER_nondet_int();

  init();
}

void svp_simple_023_001_func_1(int var) {
  if (var > 0 && var < 12) {
    int tmp = svp_simple_023_001_global_var+1;
    svp_simple_023_001_global_var = tmp;  
  }
}
void svp_simple_001_001_isr_2() {
  svp_simple_023_001_global_var = 0;
  svp_simple_023_001_global_final = 3;
}

void svp_simple_001_001_isr_1() {
  int tmp = svp_simple_023_001_global_final+1;
  svp_simple_023_001_global_final = 5;
}

void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 100; i++) {
    //		print2("Running....");
  }
}
