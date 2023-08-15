int global = 0;

void svp_simple_644_001_isr_1(void *arg) {

  access(global);

}

int svp_simple_644_001_main(void) {

  assert_racefree(global);  

  return 0;
}