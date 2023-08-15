
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }



int g = 0;



void svp_simple_635_001_isr1(void *arg )
{

    g = 1000;
    __VERIFIER_assert(g != 0);
    if (g > 0) {
      g--;
    }
  

}

int svp_simple_635_001_main(int argc , char **argv )
{

  return 0;
}
