
extern void abort(void);

void reach_error() { assert(0); }

int data1, data2;

void svp_simple_325_001_isr_1(void * arg)
{  
  int tmp = data1+1;
  data1=tmp;
  int tmp1 = data2+1;
  data2=tmp1;
 
}


void svp_simple_325_001_isr_2(void * arg)
{  
   int tmp = data1+5;
  data1=tmp;
  int tmp1 = data2-6;
  data2=tmp1;
}


int svp_simple_325_001_main()
{

  data1 = 10;
  data2 = 10;



  if (data1!=16 && data2!=5)
  {
    ERROR: {reach_error();abort();}  
  }

  return 0;
}

