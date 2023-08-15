# 1 "svp_simple_011_001.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "svp_simple_011_001.c"
# 77 "svp_simple_011_001.c"
# 1 "/usr/include/assert.h" 1 3 4
# 35 "/usr/include/assert.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 461 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 452 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 453 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/long-double.h" 1 3 4
# 454 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 462 "/usr/include/features.h" 2 3 4
# 485 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 486 "/usr/include/features.h" 2 3 4
# 36 "/usr/include/assert.h" 2 3 4
# 66 "/usr/include/assert.h" 3 4




# 69 "/usr/include/assert.h" 3 4
extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



# 78 "svp_simple_011_001.c" 2
# 1 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stdbool.h" 1 3 4
# 79 "svp_simple_011_001.c" 2
# 1 "/usr/include/errno.h" 1 3 4
# 28 "/usr/include/errno.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/errno.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/errno.h" 3 4
# 1 "/usr/include/linux/errno.h" 1 3 4
# 1 "/usr/include/x86_64-linux-gnu/asm/errno.h" 1 3 4
# 1 "/usr/include/asm-generic/errno.h" 1 3 4




# 1 "/usr/include/asm-generic/errno-base.h" 1 3 4
# 6 "/usr/include/asm-generic/errno.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/asm/errno.h" 2 3 4
# 1 "/usr/include/linux/errno.h" 2 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/errno.h" 2 3 4
# 29 "/usr/include/errno.h" 2 3 4








extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 52 "/usr/include/errno.h" 3 4

# 80 "svp_simple_011_001.c" 2
# 105 "svp_simple_011_001.c"

# 105 "svp_simple_011_001.c"
unsigned int ACPIBASE;



# 108 "svp_simple_011_001.c" 3 4
_Bool 
# 108 "svp_simple_011_001.c"
    tco_lock;
unsigned long timer_alive;
char tco_expect_close;




char tco_write_buf;


char tco1_rld;
# 151 "svp_simple_011_001.c"

# 151 "svp_simple_011_001.c" 3 4
_Bool 
# 151 "svp_simple_011_001.c"
    tco1_cnt_b0;

# 152 "svp_simple_011_001.c" 3 4
_Bool 
# 152 "svp_simple_011_001.c"
    tco1_cnt_b1;

# 153 "svp_simple_011_001.c" 3 4
_Bool 
# 153 "svp_simple_011_001.c"
    tco1_cnt_b2;

# 154 "svp_simple_011_001.c" 3 4
_Bool 
# 154 "svp_simple_011_001.c"
    tco1_cnt_b3;

# 155 "svp_simple_011_001.c" 3 4
_Bool 
# 155 "svp_simple_011_001.c"
    tco1_cnt_b4;

# 156 "svp_simple_011_001.c" 3 4
_Bool 
# 156 "svp_simple_011_001.c"
    tco1_cnt_b5;

# 157 "svp_simple_011_001.c" 3 4
_Bool 
# 157 "svp_simple_011_001.c"
    tco1_cnt_b6;

# 158 "svp_simple_011_001.c" 3 4
_Bool 
# 158 "svp_simple_011_001.c"
    tco1_cnt_b7;



int heartbeat = 30;







int nowayout = 0;






unsigned char seconds_to_ticks(int seconds)
{


 return (seconds * 10) / 6;
}
# 265 "svp_simple_011_001.c"
int tco_timer_set_heartbeat (int t)
{
 unsigned char val;
 unsigned char tmrval;

 tmrval = seconds_to_ticks(t);


 if (tmrval > 0x3f || tmrval < 0x04)
  return -
# 274 "svp_simple_011_001.c" 3 4
         22
# 274 "svp_simple_011_001.c"
               ;


 do { while (tco_lock) { } } while (
# 277 "svp_simple_011_001.c" 3 4
0
# 277 "svp_simple_011_001.c"
);
 val = 0;
 val &= 0xc0;
 val |= tmrval;


 val = 0;
 do { tco_lock = 
# 284 "svp_simple_011_001.c" 3 4
0
# 284 "svp_simple_011_001.c"
; } while (
# 284 "svp_simple_011_001.c" 3 4
0
# 284 "svp_simple_011_001.c"
);

 if ((val & 0x3f) != tmrval)
  return -
# 287 "svp_simple_011_001.c" 3 4
         22
# 287 "svp_simple_011_001.c"
               ;

 heartbeat = t;
 return 0;
}

static int tco_timer_get_timeleft (int *time_left)
{
 unsigned char val;

 do { while (tco_lock) { } } while (
# 297 "svp_simple_011_001.c" 3 4
0
# 297 "svp_simple_011_001.c"
);


 val = 0;
 val &= 0x3f;

 do { tco_lock = 
# 303 "svp_simple_011_001.c" 3 4
0
# 303 "svp_simple_011_001.c"
; } while (
# 303 "svp_simple_011_001.c" 3 4
0
# 303 "svp_simple_011_001.c"
);

 *time_left = (int)((val * 6) / 10);

 return 0;
}
# 712 "svp_simple_011_001.c"
int cnt1, cnt2, cnt3, cnt4, cnt5;
void closer1();
void closer2();
void writer1();
void writer2();

void closer1(void ) {






        tco_write_buf = 'V';
        do { if (1) { if (!nowayout) { tco_expect_close = 0; if (tco_write_buf == 'V') { tco_expect_close = 42; } } } do { do { tco1_rld = 0x01; } while (
# 726 "svp_simple_011_001.c" 3 4
       0
# 726 "svp_simple_011_001.c"
       ); } while (
# 726 "svp_simple_011_001.c" 3 4
       0
# 726 "svp_simple_011_001.c"
       ); } while (
# 726 "svp_simple_011_001.c" 3 4
       0
# 726 "svp_simple_011_001.c"
       );
        tco_expect_close = 42;

        cnt1++;


}
void closer2_isr(void) {

        tco_write_buf = 'V';
        do { if (1) { if (!nowayout) { tco_expect_close = 0; if (tco_write_buf == 'V') { tco_expect_close = 42; } } } do { do { tco1_rld = 0x01; } while (
# 736 "svp_simple_011_001.c" 3 4
       0
# 736 "svp_simple_011_001.c"
       ); } while (
# 736 "svp_simple_011_001.c" 3 4
       0
# 736 "svp_simple_011_001.c"
       ); } while (
# 736 "svp_simple_011_001.c" 3 4
       0
# 736 "svp_simple_011_001.c"
       );
        tco_expect_close = 42;
        do { if (tco_expect_close != 42) { } else { } do { timer_alive = 0; } while (
# 738 "svp_simple_011_001.c" 3 4
       0
# 738 "svp_simple_011_001.c"
       ); tco_expect_close = 0; } while (
# 738 "svp_simple_011_001.c" 3 4
       0
# 738 "svp_simple_011_001.c"
       );
        cnt2++;


}

void writer1_isr(void ) {



        do { if (0) { if (!nowayout) { tco_expect_close = 0; if (tco_write_buf == 'V') { tco_expect_close = 42; } } } do { do { tco1_rld = 0x01; } while (
# 748 "svp_simple_011_001.c" 3 4
       0
# 748 "svp_simple_011_001.c"
       ); } while (
# 748 "svp_simple_011_001.c" 3 4
       0
# 748 "svp_simple_011_001.c"
       ); } while (
# 748 "svp_simple_011_001.c" 3 4
       0
# 748 "svp_simple_011_001.c"
       );
        cnt3++;


}

void writer2_isr(void ) {

        do { if (0) { if (!nowayout) { tco_expect_close = 0; if (tco_write_buf == 'V') { tco_expect_close = 42; } } } do { do { tco1_rld = 0x01; } while (
# 756 "svp_simple_011_001.c" 3 4
       0
# 756 "svp_simple_011_001.c"
       ); } while (
# 756 "svp_simple_011_001.c" 3 4
       0
# 756 "svp_simple_011_001.c"
       ); } while (
# 756 "svp_simple_011_001.c" 3 4
       0
# 756 "svp_simple_011_001.c"
       );
        cnt4++;


}
# 907 "svp_simple_011_001.c"
int svp_simple_011_001_main(int argc, char *argv[]) {

  tco_expect_close = 0;




    closer1();
# 942 "svp_simple_011_001.c"
}
