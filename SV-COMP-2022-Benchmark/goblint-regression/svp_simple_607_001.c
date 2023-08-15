extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

extern int __VERIFIER_nondet_int();


int glob1 = 0;

void svp_simple_607_001_isr_1(void *arg) {
  int t = __VERIFIER_nondet_int();

  if(t == 42) {
      glob1 = 1;
  }
  t = glob1;


  __VERIFIER_assert(t == 1);

  glob1 = 0;

  // pthread_mutex_unlock(&mutex1);
  // return NULL;
}

int svp_simple_607_001_main(void) {
  // pthread_t id;
  // pthread_create(&id, NULL, t_fun, NULL);
  // pthread_mutex_lock(&mutex1);
  // pthread_mutex_unlock(&mutex1);
  // pthread_join (id, NULL);
  return 0;
}
