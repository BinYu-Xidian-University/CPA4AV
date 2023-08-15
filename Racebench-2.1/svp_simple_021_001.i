# 1 "svp_simple_021_001.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "svp_simple_021_001.c"
extern void idlerun();
extern void enable_isr(int);
extern void disable_isr(int);
extern int rand();
void init();
void svp_simple_021_001_init();
void svp_simple_021_001_RecvTcBlock();


volatile int svp_simple_021_001_tc_block_rcvd_bytes_ch1;
volatile int svp_simple_021_001_tc_block_rcvd_bytes_ch2;
volatile int svp_simple_021_001_tc_block_rcvd_bytes;
volatile int svp_simple_021_001_tc_chan1_buff[10];
volatile int svp_simple_021_001_tc_chan2_buff[10];
volatile int *svp_simple_021_001_tc_buff_p;

struct svp_simple_021_001_tc_block_data {
  int type;
  int id;
  int valid_len;
};
# 32 "svp_simple_021_001.c"
void svp_simple_021_001_main() {
  struct svp_simple_021_001_tc_block_data tc_block;

  svp_simple_021_001_init();

  svp_simple_021_001_RecvTcBlock();
  int ichan;
  for (ichan = 0; ichan < 2; ichan++) {
    if (ichan == 0) {
      svp_simple_021_001_tc_buff_p = svp_simple_021_001_tc_chan1_buff;
      svp_simple_021_001_tc_block_rcvd_bytes =
          svp_simple_021_001_tc_block_rcvd_bytes_ch1;
    } else {
      svp_simple_021_001_tc_buff_p = svp_simple_021_001_tc_chan2_buff;
      svp_simple_021_001_tc_block_rcvd_bytes =
          svp_simple_021_001_tc_block_rcvd_bytes_ch2;
    }

    tc_block.type = *(svp_simple_021_001_tc_buff_p + 2);
    tc_block.id = *(svp_simple_021_001_tc_buff_p + 4);
    tc_block.valid_len = *(svp_simple_021_001_tc_buff_p + 5);
  }
}

void svp_simple_021_001_init() {
  svp_simple_021_001_tc_block_rcvd_bytes_ch1 = __VERIFER_nondet_int();
  svp_simple_021_001_tc_block_rcvd_bytes_ch2 = __VERIFER_nondet_int();

  init();
}

void svp_simple_021_001_RecvTcBlock() {
  int svp_simple_021_001_flag_chan1;
  svp_simple_021_001_flag_chan1 = 0;

  if (svp_simple_021_001_tc_block_rcvd_bytes_ch1 >= 16) {
    svp_simple_021_001_tc_block_rcvd_bytes_ch1 = 0;
    int i;
    for (i = 0; i < 10; i++) {
      svp_simple_021_001_tc_chan1_buff[i] = 0;
    }
    svp_simple_021_001_flag_chan1 = 0xFF;
  }
}

void svp_simple_001_001_isr_1() {
  svp_simple_021_001_tc_block_rcvd_bytes_ch1 =
      (*((volatile unsigned int *)0x10000000) >> 3) & 0x1FFF;
}


void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 10; i++) {

  }
}
