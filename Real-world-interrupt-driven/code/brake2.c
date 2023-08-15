#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <assert.h>

//#include "brake_acc_nodiv_ctrl_h"

// Lihao
//int test;

#define MODEL brake_acc_nodiv_ctrl
#define NUMST 4

/*==================*
 * Required defines *
 *==================*/

#ifndef MODEL
# error Must specify a model name_  Define MODEL=name_
#else
/* create generic macros that work with any model */
# define EXPAND_CONCAT(name1,name2) name1 ## name2
# define CONCAT(name1,name2) EXPAND_CONCAT(name1,name2)
# define MODEL_INITIALIZE CONCAT(MODEL,_initialize)
# define MODEL_STEP       CONCAT(MODEL,_step)
# define MODEL_TERMINATE  CONCAT(MODEL,_terminate)
# define RT_MDL           CONCAT(MODEL,_M)
#endif

#if defined(TID01EQ) && TID01EQ == 1
#define FIRST_TID 1
#else 
#define FIRST_TID 0
#endif

/*====================*
 * External functions *
 *====================*/
/*
extern void MODEL_INITIALIZE(void);
extern void MODEL_TERMINATE(void);
extern void MODEL_STEP(int_T tid);  // multirate step function
*/

/*===================*
 * Visible functions *
 *===================*/

/* Function: rtOneStep ========================================================
 *
 * Abstract:
 *   Perform one step of the model.  This function is modeled such that
 *   it could be called from an interrupt service routine (ISR) with minor
 *   modifications.
 *
 *   Note that error checking is only necessary when this routine is
 *   attached to an interrupt.
 *
 *   Also, you may wish to unroll any or all of for and while loops to
 *   improve the real-time performance of this function.
 */
//static void rt_OneStep(void)
//{
//    int_T i;
//    /*******************************************
//     * Step the model for the base sample time *
//     *******************************************/
//    MODEL_STEP(0);
//    /*********************************************************
//     * Step the model for any other sample times (subrates) *
//     *********************************************************/
//    for (i = FIRST_TID+1; i < NUMST; i++) {
//        /******************************************
//         * Step the model for sample time "i" *
//         ******************************************/
//        MODEL_STEP(i);
//    }
//
//} /* end rtOneStep */

/* Function: rt_InitModel ====================================================
 * 
 * Abstract: 
 *   Initialized the model and the overrun flags
 *
 */
/*
void rt_InitModel(void)
{
    MODEL_INITIALIZE();
}
*/

/* Function: rt_TermModel ====================================================
 * 
 * Abstract:
 *   Terminates the model and prints the error status
 *
 */
/*
int_T rt_TermModel(void)
{
    MODEL_TERMINATE();
    return(0);
}
*/

/*
void havocInputs(ExtU_brake_acc_nodiv_ctrl_T *_inputs) {
    ExtU_brake_acc_nodiv_ctrl_T inputs; 
    *_inputs = inputs;
}
*/

/* Split in separate tasks
   Lihao
 */

//Lihao

void task_compute_isr();
void task_RR_Wheel_isr();
void task_FL_Wheel_isr();


//void irq_err(void) {ERROR: goto ERROR;}

int brake_acc_nodiv_ctrl_B_local_RT_h;
int brake_acc_nodiv_ctrl_B_local_RTH;
int brake_acc_nodiv_ctrl_B_local_RT4;
int brake_acc_nodiv_ctrl_B_local_RT1;
int brake_acc_nodiv_ctrl_B_local_RT2;
int brake_acc_nodiv_ctrl_B_local_RT3;
int brake_acc_nodiv_ctrl_B_local_RT14;

int brake_acc_nodiv_ctrl_B_local_ABS_FL_Wheel_Threshold_10kmh = 100;
int brake_acc_nodiv_ctrl_B_local_ABS_RL_Wheel_Threshold_10kmh = 100;
int brake_acc_nodiv_ctrl_B_local_ABS_RR_Wheel_Threshold_10kmh = 100;
int brake_acc_nodiv_ctrl_B_local_ABS_FR_Wheel_Threshold_10kmh = 100;

int brake_acc_nodiv_ctrl_P_RT_X0;
int brake_acc_nodiv_ctrl_P_RT4_X0;
int brake_acc_nodiv_ctrl_P_RT1_X0;
int brake_acc_nodiv_ctrl_P_RT2_X0;
int brake_acc_nodiv_ctrl_P_RT3_X0;

int brake_acc_nodiv_ctrl_P_Gain1_Gain;

int brake_acc_nodiv_ctrl_P_Distribution_Gain0;
int brake_acc_nodiv_ctrl_P_Distribution_Gain1;
int brake_acc_nodiv_ctrl_P_Distribution_Gain2;
int brake_acc_nodiv_ctrl_P_Distribution_Gain3;


int brake_acc_nodiv_ctrl_P_average_rpm_Gain;
int brake_acc_nodiv_ctrl_P_wgrads_Gain;
int brake_acc_nodiv_ctrl_P_vkmh_Gain;

#define brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_vms_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_wheSpdms_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_times_10_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_slip_abs_on_times_10_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_Threshold_10kmh_Threshold 100
#define brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_ReleaseBrake_Value 8
#define brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_positive_UpperSat 100
#define brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_positive_LowerSat 5

#define brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_vms_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_wheSpdms_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_times_10_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_slip_abs_on_times_10_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_Threshold_10kmh_Threshold 100
#define brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_ReleaseBrake_Value 8
#define brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_positive_UpperSat 100
#define brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_positive_LowerSat 5

#define brake_acc_nodiv_ctrl_P_ABS_RL_Wheel_vms_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_RL_Wheel_wheSpdms_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_RL_Wheel_times_10_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_RL_Wheel_slip_abs_on_times_10_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_RL_Wheel_Threshold_10kmh_Threshold 100
#define brake_acc_nodiv_ctrl_P_ABS_RL_Wheel_ReleaseBrake_Value 8
#define brake_acc_nodiv_ctrl_P_ABS_RL_Wheel_positive_UpperSat 100
#define brake_acc_nodiv_ctrl_P_ABS_RL_Wheel_positive_LowerSat 5

#define brake_acc_nodiv_ctrl_P_ABS_FR_Wheel_vms_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_FR_Wheel_wheSpdms_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_FR_Wheel_times_10_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_FR_Wheel_slip_abs_on_times_10_Gain 10
#define brake_acc_nodiv_ctrl_P_ABS_FR_Wheel_Threshold_10kmh_Threshold 100
#define brake_acc_nodiv_ctrl_P_ABS_FR_Wheel_ReleaseBrake_Value 8
#define brake_acc_nodiv_ctrl_P_ABS_FR_Wheel_positive_UpperSat 100
#define brake_acc_nodiv_ctrl_P_ABS_FR_Wheel_positive_LowerSat 5

#define brake_acc_nodiv_ctrl_P_Pedal_map_UpperSat 50
#define brake_acc_nodiv_ctrl_P_Pedal_map_LowerSat 20

#define brake_acc_nodiv_ctrl_U_In_BrakePedal 15
#define brake_acc_nodiv_ctrl_U_In_FLRotation 10
#define brake_acc_nodiv_ctrl_U_In_RRRotation 10
#define brake_acc_nodiv_ctrl_U_In_RLRotation 10
#define brake_acc_nodiv_ctrl_U_In_FRRotation 10

int vkmh;
int test;

int RT9;
int RT10;
int RT11;
int RT12;
int RT14;

int RT_Buffer0;
int RT0_Buffer0;
int RT1_Buffer0;
int RT2_Buffer0;
int RT3_Buffer0;
int RT4_Buffer0;

int Distribution_idx;
int Distribution_idx_0;
int Distribution_idx_1;


#define LIMIT 20
int cnt1, cnt2, cnt3;


void task_compute_isr(void ) {
        // cnt1++;
        brake_acc_nodiv_ctrl_B_local_RT_h = brake_acc_nodiv_ctrl_P_RT_X0;
        
        brake_acc_nodiv_ctrl_B_local_RT4 = brake_acc_nodiv_ctrl_P_RT4_X0;

        brake_acc_nodiv_ctrl_B_local_RT1 = brake_acc_nodiv_ctrl_P_RT1_X0;

        brake_acc_nodiv_ctrl_B_local_RT2 = brake_acc_nodiv_ctrl_P_RT2_X0;

        brake_acc_nodiv_ctrl_B_local_RT3 = brake_acc_nodiv_ctrl_P_RT3_X0;


        test = 0;

        Distribution_idx = brake_acc_nodiv_ctrl_P_Distribution_Gain1 +
            brake_acc_nodiv_ctrl_B_local_RT14;
        Distribution_idx_0 = brake_acc_nodiv_ctrl_P_Distribution_Gain2 +
            brake_acc_nodiv_ctrl_B_local_RT14;
        Distribution_idx_1 = brake_acc_nodiv_ctrl_P_Distribution_Gain3 +
            brake_acc_nodiv_ctrl_B_local_RT14;

        // vkmh = RT9+RT10;
        // vkmh = vkmh + RT11;
        // vkmh = vkmh + RT12;
        // vkmh = vkmh + brake_acc_nodiv_ctrl_P_average_rpm_Gain;
        // vkmh = vkmh + brake_acc_nodiv_ctrl_P_wgrads_Gain;
        // vkmh = vkmh + brake_acc_nodiv_ctrl_P_vkmh_Gain;


        test++;


        // if (test != 0) {

        // }
        // if (test != 1) {
        // }

      
        RT_Buffer0 = brake_acc_nodiv_ctrl_P_Distribution_Gain0 + brake_acc_nodiv_ctrl_B_local_RT14;

        RT4_Buffer0 = vkmh;

        RT1_Buffer0 = Distribution_idx;

        RT2_Buffer0 = Distribution_idx_0;

        RT3_Buffer0 = Distribution_idx_1;
    //}

}

void task_RR_Wheel_isr(void ) {  

        cnt2 ++;
        test = 0;

        if (test != 0) {

        }

        brake_acc_nodiv_ctrl_B_local_RT_h = brake_acc_nodiv_ctrl_P_RT_X0;

        brake_acc_nodiv_ctrl_B_local_RT4 = brake_acc_nodiv_ctrl_P_RT4_X0;

        brake_acc_nodiv_ctrl_B_local_RT1 = brake_acc_nodiv_ctrl_P_RT1_X0;

        brake_acc_nodiv_ctrl_B_local_RT2 = brake_acc_nodiv_ctrl_P_RT2_X0;

        brake_acc_nodiv_ctrl_B_local_RT3 = brake_acc_nodiv_ctrl_P_RT3_X0;

        int rtb_to_int;

        brake_acc_nodiv_ctrl_B_local_RT_h = RT_Buffer0;

        brake_acc_nodiv_ctrl_B_local_RT4 = RT4_Buffer0;

        rtb_to_int = brake_acc_nodiv_ctrl_U_In_RRRotation;

        bool rtb_RelationalOperator;
        int rtb_vms;
        int u;
        rtb_vms = brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_vms_Gain + brake_acc_nodiv_ctrl_B_local_RT4;

        u = rtb_vms + brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_wheSpdms_Gain;
        u = u + rtb_to_int;

        int positive_UpperSat_local = brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_positive_UpperSat;

        if (u >= positive_UpperSat_local) {
            u = brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_positive_UpperSat;
        } else {
            int positive_LowerSat_local = brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_positive_LowerSat;
            if (u <= positive_LowerSat_local) {
                u = brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_positive_LowerSat;
            }
        }

        // int tmp0 = brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_times_10_Gain;

        // int tmp1 = brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_slip_abs_on_times_10_Gain + rtb_vms;
        // if (tmp0 > tmp1) {
        //     rtb_RelationalOperator = true;
        // } else {
        //     rtb_RelationalOperator = false;
        // }

        // int Threshold_10kmh_Threshold_local = brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_Threshold_10kmh_Threshold;
        // if (brake_acc_nodiv_ctrl_B_local_RT4 >= Threshold_10kmh_Threshold_local) {

        //     if (rtb_RelationalOperator) {
        //         brake_acc_nodiv_ctrl_B_local_ABS_RR_Wheel_Threshold_10kmh = brake_acc_nodiv_ctrl_P_ABS_RR_Wheel_ReleaseBrake_Value;
        //     } else {
        //         brake_acc_nodiv_ctrl_B_local_ABS_RR_Wheel_Threshold_10kmh = brake_acc_nodiv_ctrl_B_local_RT_h;
        //     }

        // } else {

        //     brake_acc_nodiv_ctrl_B_local_ABS_RR_Wheel_Threshold_10kmh = brake_acc_nodiv_ctrl_B_local_RT_h;

        // }

        brake_acc_nodiv_ctrl_B_local_RT1 = RT1_Buffer0;

        RT9 = rtb_to_int;

    }

void task_FL_Wheel_isr(void) {  

    cnt3++;
    test = 0;
    if (test != 0) {
        // assert(0);
    }

    brake_acc_nodiv_ctrl_B_local_RT_h = brake_acc_nodiv_ctrl_P_RT_X0;

    brake_acc_nodiv_ctrl_B_local_RT4 = brake_acc_nodiv_ctrl_P_RT4_X0;

    // brake_acc_nodiv_ctrl_B_local_RT1 = brake_acc_nodiv_ctrl_P_RT1_X0;

    // brake_acc_nodiv_ctrl_B_local_RT2 = brake_acc_nodiv_ctrl_P_RT2_X0;

    // brake_acc_nodiv_ctrl_B_local_RT3 = brake_acc_nodiv_ctrl_P_RT3_X0;

    int rtb_to_int1;

    rtb_to_int1 = brake_acc_nodiv_ctrl_U_In_FLRotation;

    brake_acc_nodiv_ctrl_B_local_RT_h = RT_Buffer0;

    brake_acc_nodiv_ctrl_B_local_RT4 = RT4_Buffer0;

    bool rtb_RelationalOperator;
    int rtb_vms;
    // int u;

    rtb_vms = brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_vms_Gain + brake_acc_nodiv_ctrl_B_local_RT4;

    // u = rtb_vms + brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_wheSpdms_Gain;
    // u = u + rtb_to_int1;

    // int positive_UpperSat_local = brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_positive_UpperSat;

    // if (u >= positive_UpperSat_local) {
    //     u = brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_positive_UpperSat;
    // } else {

    //     int positive_LowerSat_local = brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_positive_LowerSat;
    //     if (u <= positive_LowerSat_local) {
    //         u = brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_positive_LowerSat;
    //     }
    // }

    // int tmp0 = brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_times_10_Gain;
    // int tmp1 = brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_slip_abs_on_times_10_Gain + rtb_vms;
    // if (tmp0 > tmp1) {
    //     rtb_RelationalOperator = true;
    // } else {
    //     rtb_RelationalOperator = false;
    // }

    // int Threshold_10kmh_Threshold_local = brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_Threshold_10kmh_Threshold;
    // if (brake_acc_nodiv_ctrl_B_local_RT4 >= Threshold_10kmh_Threshold_local) {

    //     if (rtb_RelationalOperator) {
    //         brake_acc_nodiv_ctrl_B_local_ABS_FL_Wheel_Threshold_10kmh = brake_acc_nodiv_ctrl_P_ABS_FL_Wheel_ReleaseBrake_Value;
    //     } else {
    //         brake_acc_nodiv_ctrl_B_local_ABS_FL_Wheel_Threshold_10kmh = brake_acc_nodiv_ctrl_B_local_RT3;
    //     }

    // } else {

    //     brake_acc_nodiv_ctrl_B_local_ABS_FL_Wheel_Threshold_10kmh = brake_acc_nodiv_ctrl_B_local_RT3;

    // }

    int In_BrakePedal;
    // if (rtb_RelationalOperator) {
        In_BrakePedal = brake_acc_nodiv_ctrl_U_In_BrakePedal;
    // } else {
    //     In_BrakePedal = brake_acc_nodiv_ctrl_U_In_BrakePedal + 50;
    // }
    int Pedal_map_UpperSat = brake_acc_nodiv_ctrl_P_Pedal_map_UpperSat;
    int Pedal_map_LowerSat = brake_acc_nodiv_ctrl_P_Pedal_map_LowerSat;
    int tmp;
    if (In_BrakePedal >= Pedal_map_UpperSat) {
        tmp = brake_acc_nodiv_ctrl_P_Pedal_map_UpperSat;
    } 
    if (In_BrakePedal <= Pedal_map_LowerSat) {
        tmp = brake_acc_nodiv_ctrl_P_Pedal_map_LowerSat;
    } else {
        tmp = brake_acc_nodiv_ctrl_U_In_BrakePedal;
    }

    RT14 = brake_acc_nodiv_ctrl_P_Gain1_Gain + tmp;

    RT12 = rtb_to_int1;

}


int svp_simple_005_001_main(void)
{

    test = 0;

 
    return 0;

}


