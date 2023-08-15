
extern int __VERIFIER_nondet_int();



int glob;


void svp_simple_521_001_isr_1(void *arg) {

  glob++; // NORACE

}

int svp_simple_521_001_main() {
  int i = __VERIFIER_nondet_int();


  printf("Do the work? ");

  printf("Now we do the work..n");
  i++;
  if (i-1)
    glob++; // NORACE
  printf("Work is completed...");
  i--;


  return 0;
}
