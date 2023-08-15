extern void idlerun();

extern void enable_isr(int);
extern int __VERIFIER_nondet_int();
extern void disable_isr(int);

extern int rand();

void init();







#define MAX_LENGTH 10
#define TRIGGER 9

volatile int svp_simple_003_001_global_var1;
volatile int svp_simple_003_001_global_var2;

volatile int svp_simple_003_001_global_flag = 0;
volatile int svp_simple_003_001_global_flag1 = 0;
void svp_simple_003_001_main() {
//  init();
  int reader1, reader2;
  int reader3, reader4;
  idlerun();

  disable_isr(1);
  disable_isr(2);

  for (int i = 0; i < MAX_LENGTH; i++) {
    if (i == TRIGGER) {
      reader3 = svp_simple_003_001_global_var2;
    }
  }
  for (int j = MAX_LENGTH; j > 0; j--) {
    if (j == TRIGGER) {
      reader4 = svp_simple_003_001_global_var2;
    }
  }

  enable_isr(1);
  for (int i = 0; i < MAX_LENGTH; i++) {
    if (i == TRIGGER) {
      reader1 = svp_simple_003_001_global_var1;
    }
  }
  for (int j = MAX_LENGTH; j > 0; j--) {
    if (j == TRIGGER) {
      reader2 = svp_simple_003_001_global_var1;
    }
  }
}

void svp_simple_001_001_isr_1() {
  enable_isr(2);
  // svp_simple_003_001_global_var2 = 999;

  if (svp_simple_003_001_global_flag == 1) {
    svp_simple_003_001_global_var1 = 999;
  }
  if (svp_simple_003_001_global_flag1 == 2) {
    svp_simple_003_001_global_var1 = 888;
  }
}

void svp_simple_001_001_isr_2() {
  // idlerun();
  svp_simple_003_001_global_flag = 1;
}

void svp_simple_001_001_isr_3() {
  // idlerun();
  if(svp_simple_003_001_global_var1 == 999){
    svp_simple_003_001_global_flag1 = 2;
  }
}



void init() { enable_isr(-1); }

void idlerun() {
//  int i = 0;
//  for (i = 0; i <= 10; i++) {
//    //		print2("Running....");
//  }
}
