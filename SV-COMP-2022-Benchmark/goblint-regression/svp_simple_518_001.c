
int myglobal;
// pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
// pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
// pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;

void svp_simple_518_001_isr_1(void *arg) {
  int tmp = myglobal+1;
  myglobal = tmp;
  // myglobal=myglobal+1; // RACE!

}

int add1 (int x) {
  return x+1;
}

int svp_simple_518_001_main(void) {
  printf("myglobal equals %dn",myglobal); // RACE!

  add1(myglobal); // RACE!

  return 0;
}
