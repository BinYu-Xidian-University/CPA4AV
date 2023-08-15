extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

int glob1 = 0;

void svp_simple_610_001_isr_1(void *arg) {
  // pthread_mutex_lock(&mutex1);
  // pthread_mutex_lock(&mutex2);
  glob1 = 5;

  // pthread_mutex_unlock(&mutex2);
  // pthread_mutex_lock(&mutex2);

  glob1 = 0;

  // pthread_mutex_unlock(&mutex2);
  // pthread_mutex_unlock(&mutex1);
  // return NULL;
}

int svp_simple_610_001_main(void) {
  // pthread_t id;
  // pthread_create(&id, NULL, t_fun, NULL);
  // pthread_mutex_lock(&mutex2);
  __VERIFIER_assert(glob1 == 0);
  // pthread_mutex_unlock(&mutex2);
  // pthread_join (id, NULL);
  return 0;
}
