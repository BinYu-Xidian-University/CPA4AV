extern void idlerun();
extern int __VERIFIER_nondet_int();
extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();







#define MAX_LENGTH 10
#define TRIGGER 9
#define TRIGGER1 1

volatile int svp_simple_005_001_global_condition = 0;

volatile int svp_simple_005_001_global_var;

void svp_simple_005_001_main() {
  init();
  for (int i = 0; i < MAX_LENGTH; i++) {
    for (int j = 0; j < MAX_LENGTH; j++) {
      if ((i == TRIGGER) && (j == TRIGGER1))
        svp_simple_005_001_global_var = 0x01;
    }
  }

  if (svp_simple_005_001_global_condition == 1)
    svp_simple_005_001_global_var = 0x09;

  svp_simple_005_001_global_var = 0x05;
}

void svp_simple_001_001_isr_1() {
  // idlerun();
  int reader;
  svp_simple_005_001_global_condition = 1;
  reader = svp_simple_005_001_global_var;
}

void svp_simple_001_001_isr_2() {
  // idlerun();
  int reader;
  reader = svp_simple_005_001_global_var;
}

void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 10; i++) {
    //		print2("Running....");
  }
}
