extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();







#define MAX_LENGTH 100
#define TRIGGER 99

volatile int svp_simple_003_001_global_var1;
volatile int svp_simple_003_001_global_var2;

volatile int svp_simple_003_001_global_flag = 1;
volatile int svp_simple_003_001_global_flag1 = 0;
void svp_simple_003_001_main() {
  init();
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
  svp_simple_003_001_global_var2 = 999;

  if (svp_simple_003_001_global_flag == 1) {
    svp_simple_003_001_global_var1 = 999;
  } else if (svp_simple_003_001_global_flag1 == 2) {
    svp_simple_003_001_global_var1 = 888;
  }
}

void svp_simple_001_001_isr_2() {
  idlerun();
  svp_simple_003_001_global_flag = 1;
}
void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 10; i++) {
    //		print2("Running....");
  }
}
// bug points:
//1.svp_simple_003_001_global_var1<R#48>,<W#63>,<R#53>
// possible false positive points:
//1.svp_simple_003_001_global_var2<R#38>,<W#62>,<R#43>
//2.svp_simple_003_001_global_var1<R#50>,<W#67>,<R#55>