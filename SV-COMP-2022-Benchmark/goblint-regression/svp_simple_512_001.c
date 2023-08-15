
extern int __VERIFIER_nondet_int();


int glob;


void svp_simple_512_001_isr_1(void *arg) {
  int tmp = glob+1;
  glob = tmp;
  // glob++; // RACE!

}

int svp_simple_512_001_main() {
  int i = __VERIFIER_nondet_int();
  if (i)
  printf("Now we do the work..n");
  if (i)
  {
      int tmp = glob+1;
      glob = tmp;
      // glob++; // RACE!
  }
    
  printf("Work is completed...");

  return 0;
}
