int g1,g2;

void svp_simple_668_001_isr_1(void *arg) {

  access(g1);

  access(g2);

}

int svp_simple_668_001_main(void) {

  assert_racefree(g1);

  assert_racefree(g1);
  assert_racefree(g2);


  assert_racefree(g1);


  return 0;
}