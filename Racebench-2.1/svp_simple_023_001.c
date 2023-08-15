extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();









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
    svp_simple_023_001_global_var = svp_simple_023_001_global_var + 1;  
  }
}
void svp_simple_001_001_isr_1() {
  svp_simple_023_001_global_var = 0; 
}

void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 10; i++) {
    //		print2("Running....");
  }
}
//bug points:
// 1.svp_simple_023_001_global_var <R, #27>, <W, #41>, <R, #37>
// 2.svp_simple_023_001_global_var <R, #35>, <W, #39>, <W, #35> 