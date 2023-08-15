
extern int __VERIFIER_nondet_int();


int glob;

void svp_simple_513_001_isr_1(void *arg) {

  glob++; // NORACE

}

int svp_simple_513_001_main() {
  int i = __VERIFIER_nondet_int();

  if (i)
  printf("Now we do the work..n");
  if (i)
    glob++; // NORACE
  printf("Work is completed...");

  return 0;
}
