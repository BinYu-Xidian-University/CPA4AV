

int myglobal;

void svp_simple_598_001_isr_1(void *arg) {
  myglobal=42; // RACE!

}

int svp_simple_598_001_main(void) {

  return 0;
}
