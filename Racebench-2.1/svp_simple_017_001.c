extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();









#define MAX_LENGTH 10
#define TRIGGER 5

volatile int svp_simple_017_001_global_var;
volatile int svp_simple_017_001_local_array[MAX_LENGTH];

void svp_simple_017_001_main() {
  init();
  int i = 0;

  for (svp_simple_017_001_global_var = 0; svp_simple_017_001_global_var < MAX_LENGTH;
       svp_simple_017_001_global_var++)
  {
    svp_simple_017_001_local_array[svp_simple_017_001_global_var] = i++;
  }
}

void svp_simple_001_001_isr_1() {
//  idlerun();

  svp_simple_017_001_global_var = TRIGGER;

  svp_simple_017_001_local_array[TRIGGER] = 0;
}
void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 10; i++) {
    //		print2("Running....");
  }
}
// bug points:
//1.svp_simple_017_001_global_var<R#29>,<W#39>,<R#29>  RWR
//2.svp_simple_017_001_global_var<R#29>,<W#39>,<R#32>  RWR
//3.svp_simple_017_001_global_var<R#32>,<W#39>,<W#30>  RWW
//4.svp_simple_017_001_global_var<W#30>,<W#39>,<R#29>  WWR
// possible false positive points:
//1.svp_simple_017_001_local_array<R#32>,<W#41>,<R#32> RWR