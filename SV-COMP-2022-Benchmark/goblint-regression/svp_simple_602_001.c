extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }


int A = 5;
int B = 5;


void *generate(void *arg) {
  int i;
  for (i=1; i<100; i++) {

    A = i;
    A = 5;

    sleep(1);
  }
}

void *process(void *arg) {
  while (1) {

    if (A > 0) {
      A++;
      B = A;
      B--;
      A--;
    }
    else
    sleep(2);
  }
}

void *dispose(void *arg) {
  int p;
  while (1) {
    if (B > 0) {
      p = B;
      __VERIFIER_assert(p == 5);
    }
    else
    sleep(5);
  }
}

int svp_simple_602_001_main () {
  int i;

  for (i=0; i<10; i++) {


    __VERIFIER_assert(A == B);

    // pthread_mutex_unlock(&mutex_B);
    // pthread_mutex_unlock(&mutex_A);
    sleep(3);
  }
  return 0;
}
