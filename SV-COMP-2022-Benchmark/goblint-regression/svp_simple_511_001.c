
int myglobal;



void svp_simple_511_001_isr_1(void *arg) {
  lock();
  myglobal++; // NORACE
  unlock();

}


int svp_simple_511_001_main(void) {
  // pthread_t id;
  // pthread_create(&id, NULL, t_fun, NULL);
  lock();
  myglobal++; // NORACE
  unlock();
  // pthread_join (id, NULL);
  return 0;
}
