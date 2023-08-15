extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }


int g = 0;


void svp_simple_633_001_isr_1(void *arg) {
  g = 1;
}

int svp_simple_633_001_main() {
 
  if (g) 
    __VERIFIER_assert(g);
  else
    __VERIFIER_assert(!g);
  
  g = 1;
  
  return 0;
}
