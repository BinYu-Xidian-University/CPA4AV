extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();





volatile int svp_simple_022_001_global_var1;
volatile int svp_simple_022_001_global_var2;
volatile int svp_simple_022_001_global_var3;
volatile int svp_simple_022_001_global_array[20];
void svp_simple_022_001_func_1();
void svp_simple_022_001_func_2();
void svp_simple_022_001_func_3();
void svp_simple_022_001_func_4();
void svp_simple_022_001_init();

void svp_simple_022_001_main() {
  svp_simple_022_001_init();

  svp_simple_022_001_global_var1 = 0;  
  svp_simple_022_001_func_1();
  int i;
  for (i = 0; i < 20; i++) {
    svp_simple_022_001_global_array[i] = 0;
  }
  svp_simple_022_001_func_2();
  svp_simple_022_001_global_var3 = svp_simple_022_001_global_var1; 
}

void svp_simple_022_001_init() {
  svp_simple_022_001_global_var1 = rand();
  svp_simple_022_001_global_var2 = rand();
  svp_simple_022_001_global_var3 = rand();

  init();
}

void svp_simple_022_001_func_1() { svp_simple_022_001_func_3(); }

void svp_simple_022_001_func_2() { svp_simple_022_001_func_4(); }

void svp_simple_022_001_func_3() {
  if (svp_simple_022_001_global_var1 >= 12) { 
    svp_simple_022_001_global_var1 = 12;       
  } else {
    svp_simple_022_001_global_var1 = 0;  
  }
}

void svp_simple_022_001_func_4() {
  svp_simple_022_001_global_var3 = svp_simple_022_001_global_var1;  
}
void svp_simple_001_001_isr_1() {
  svp_simple_022_001_global_var1 = 0; 
}
void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 10; i++) {
    //		print2("Running....");
  }
}


//bug points:
// 1: svp_simple_022_001_global_var1 <W, #28>, <W,#62>, <R,#51>
// 2: svp_simple_022_001_global_var1 <R, #51>, <W,#62>, <R,#54>
// 3: svp_simple_022_001_global_var1 <W, #54>, <W,#62>, <R,#59>
// 4: svp_simple_022_001_global_var1 <R, #59>, <W,#62>, <R,#35>

//possible false positive points:
// 1: svp_simple_022_001_global_var1 <W, #32>, <W,#66>, <R,#39>
// 2: svp_simple_022_001_global_var1 <R, #55>, <W,#66>, <R,#56>
// 3: svp_simple_022_001_global_var1 <R, #55>, <W,#66>, <R,#63>
