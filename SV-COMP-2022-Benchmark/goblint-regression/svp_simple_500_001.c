

int glob;

void svp_simple_500_001_isr_1(void *arg) {
  int tmp = glob + 1;
  glob = tmp; 
  // glob++;

}

int svp_simple_500_001_main(void) {
  int tmp = glob + 1;
  glob = tmp; 
  // glob++;
  return 0;
}
