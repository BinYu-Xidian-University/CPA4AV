

extern int __VERIFIER_nondet_int();


int myglobal;


void svp_simple_522_001_isr_1(void *arg) {
  if (myglobal) // NORACE
    printf("How do you do?n");
}

int svp_simple_522_001_main(void) {

  int k = __VERIFIER_nondet_int();
  myglobal = k;

  if (myglobal)  // NORACE
    printf("Hello!n");
  return 0;
}
