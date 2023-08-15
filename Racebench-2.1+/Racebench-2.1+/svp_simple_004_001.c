extern void idlerun();
extern int __VERIFIER_nondet_int();
extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();

#define MAX_LENGTH 10
#define TRIGGER 9

volatile int svp_simple_004_001_condition1 = 1;
volatile int svp_simple_004_001_condition2 = 1;
volatile int svp_simple_004_001_condition3 = 1;
volatile int svp_simple_004_001_condition4 = 1;
volatile int svp_simple_004_001_condition5 = 1;
volatile int svp_simple_004_001_condition6 = 1;

volatile int svp_simple_004_001_global_var1 = 0x11;
volatile int svp_simple_004_001_global_var2 = 0x22;
volatile int svp_simple_004_001_global_var3 = 0x33;

void svp_simple_004_001_main() {
  init();
  int reader1, reader2;
  int reader3, reader4;
  int reader5, reader6;
  disable_isr(2);

  if (svp_simple_004_001_condition1 == 2) {
    reader1 = svp_simple_004_001_global_var1;
    reader5 = svp_simple_004_001_global_var3;
  }

  if (svp_simple_004_001_condition2 == 1) {
    reader2 = svp_simple_004_001_global_var1;
    reader6 = svp_simple_004_001_global_var3;
  }

  if (svp_simple_004_001_condition4 == 1){
    reader3 = svp_simple_004_001_global_var2;
  }

  if (svp_simple_004_001_condition5 == 1) {
    reader4 = svp_simple_004_001_global_var2;
  }
}

void svp_simple_001_001_isr_1() {
//  svp_simple_004_001_condition6 = 0;
  svp_simple_004_001_condition1 = 2;
  if (svp_simple_004_001_condition3 == 1)
    svp_simple_004_001_global_var1 = 0xaa;
  else
    svp_simple_004_001_global_var3 = 0xcc;

  enable_isr(2);
}

void svp_simple_001_001_isr_2() {
  if (svp_simple_004_001_condition6 == 1)
    svp_simple_004_001_global_var1 = 0x22;
}
void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 100; i++) {
    //		print2("Running....");
  }
}
