
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

extern int __VERIFIER_nondet_int();



int g = 42;
int h = 42;


void svp_simple_700_001_isr_1(void *arg) {
  int x = __VERIFIER_nondet_int(); //rand
  if (x > -1000) { 
    g = x;
    h = x - 17;
   
    h = x;
   
  }
 
}

void svp_simple_700_001_isr_2(void *arg) {
  int x = __VERIFIER_nondet_int(); 
  int y = __VERIFIER_nondet_int(); 
 
  x = g;
  y = h;
  
  __VERIFIER_assert(y <= x);
 
}

// void svp_simple_700_001_isr_3(void *arg) {
//   int x = __VERIFIER_nondet_int(); 
//   int y = __VERIFIER_nondet_int(); 
 
//   x = g;
//   y = h;

//   __VERIFIER_assert(y == x);

// }

int svp_simple_700_001_main(void) {
  int x = __VERIFIER_nondet_int(); 
  int y = __VERIFIER_nondet_int(); 

 
  x = g;
  y = h;
 
  __VERIFIER_assert(y == x);

  __VERIFIER_assert(y == x);
  return 0;
}
