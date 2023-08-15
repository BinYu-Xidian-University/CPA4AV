extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } }

int g;


void svp_simple_641_001_isr1(void* ptr) {
    
    g = 1;
   
    printf("g is %i", g);
    g = 0;
  
}

void svp_simple_641_001_isr2(void* ptr) {

    __VERIFIER_assert(g == 0);
    g = 0;

}

int svp_simple_641_001_main(int argc, char const *argv[])
{

    sleep(1);


    return 0;
}
