extern void abort(void);
void reach_error() { assert(0); }

int  num;


void svp_simple_326_001_isr_1(void * arg)
{

  while (num > 0) {
    int tmp = num-1;
    num=tmp;
  } 
}


void svp_simple_326_001_isr_2(void * arg)
{

  while (num == 0) {
    int tmp = num-1;
    num=tmp;
  } 

}


int svp_simple_326_001_main()
{

  num = 1;

  if (num!=1)
  {
    ERROR: {reach_error();abort();}
  }

  return 0;
  
}
