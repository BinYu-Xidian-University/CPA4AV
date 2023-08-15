extern int __VERIFIER_nondet_int();
extern void abort(void);
void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}


int data;


void svp_simple_560_001_isr_1(void *arg) {
 
int tmp=data+1;
	data = tmp;
  // data++; // RACE!

}

int svp_simple_560_001_main() {
 
  int i = __VERIFIER_nondet_int();
  assume_abort_if_not(0 <= i && i < 10);
  int tmp=data+1;
	data = tmp;
  // data++; // RACE!
 
  return 0;
}

