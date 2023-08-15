

extern int __VERIFIER_nondet_int();



int glob;


void svp_simple_520_001_isr_1(void *arg) {

  glob++; // RACE!

}

int svp_simple_520_001_main() {
  int i = __VERIFIER_nondet_int();

  glob++; // RACE!

  return 0;
}
