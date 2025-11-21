/*
 * File: MBD_SpeedControl.c
 *
 * Code generated for Simulink model 'MBD_SpeedControl'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Nov 15 12:34:41 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MBD_SpeedControl.h"
#include "rtwtypes.h"
#include "MBD_SpeedControl_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define MBD_SpeedControl_IN_Alerte     ((uint8_T)1U)
#define MBD_SpeedControl_IN_Freinage   ((uint8_T)2U)
#define MBD_SpeedControl_IN_Normal     ((uint8_T)3U)

/* Block signals (default storage) */
B_MBD_SpeedControl_T MBD_SpeedControl_B;

/* Block states (default storage) */
DW_MBD_SpeedControl_T MBD_SpeedControl_DW;

/* Real-time model */
static RT_MODEL_MBD_SpeedControl_T MBD_SpeedControl_M_;
RT_MODEL_MBD_SpeedControl_T *const MBD_SpeedControl_M = &MBD_SpeedControl_M_;

/* Model step function */
void MBD_SpeedControl_step(void)
{
  /* FromWorkspace: '<S2>/fromWS_Signal 1' */
  {
    real_T t = MBD_SpeedControl_M->Timing.t[0];
    real_T *pTimeValues = (real_T *)
      MBD_SpeedControl_DW.fromWS_Signal1_PWORK.TimePtr;
    real_T *pDataValues = (real_T *)
      MBD_SpeedControl_DW.fromWS_Signal1_PWORK.DataPtr;
    if (t < pTimeValues[0]) {
      MBD_SpeedControl_B.Signal1 = 0.0;
    } else if (t == pTimeValues[1]) {
      MBD_SpeedControl_B.Signal1 = pDataValues[1];
    } else if (t > pTimeValues[1]) {
      MBD_SpeedControl_B.Signal1 = 0.0;
    } else {
      int_T currTimeIndex = MBD_SpeedControl_DW.fromWS_Signal1_IWORK.PrevIndex;
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }

      MBD_SpeedControl_B.Signal1 = pDataValues[currTimeIndex];
      MBD_SpeedControl_DW.fromWS_Signal1_IWORK.PrevIndex = currTimeIndex;
    }
  }

  /* Chart: '<Root>/Chart' incorporates:
   *  Constant: '<Root>/Speed_Max'
   */
  if (MBD_SpeedControl_DW.is_active_c3_MBD_SpeedControl == 0U) {
    MBD_SpeedControl_DW.is_active_c3_MBD_SpeedControl = 1U;
    MBD_SpeedControl_DW.is_c3_MBD_SpeedControl = MBD_SpeedControl_IN_Normal;
  } else {
    switch (MBD_SpeedControl_DW.is_c3_MBD_SpeedControl) {
     case MBD_SpeedControl_IN_Alerte:
      if (MBD_SpeedControl_B.Signal1 > 120.0) {
        MBD_SpeedControl_DW.is_c3_MBD_SpeedControl =
          MBD_SpeedControl_IN_Freinage;
      } else if (MBD_SpeedControl_B.Signal1 <= 100.0) {
        MBD_SpeedControl_DW.is_c3_MBD_SpeedControl = MBD_SpeedControl_IN_Normal;
      }
      break;

     case MBD_SpeedControl_IN_Freinage:
      if (MBD_SpeedControl_B.Signal1 <= 100.0) {
        MBD_SpeedControl_DW.is_c3_MBD_SpeedControl = MBD_SpeedControl_IN_Normal;
      }
      break;

     default:
      /* case IN_Normal: */
      if (MBD_SpeedControl_B.Signal1 > 100.0) {
        MBD_SpeedControl_DW.is_c3_MBD_SpeedControl = MBD_SpeedControl_IN_Alerte;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  MBD_SpeedControl_M->Timing.t[0] =
    ((time_T)(++MBD_SpeedControl_M->Timing.clockTick0)) *
    MBD_SpeedControl_M->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.4s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.4, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    MBD_SpeedControl_M->Timing.clockTick1++;
  }
}

/* Model initialize function */
void MBD_SpeedControl_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&MBD_SpeedControl_M->solverInfo,
                          &MBD_SpeedControl_M->Timing.simTimeStep);
    rtsiSetTPtr(&MBD_SpeedControl_M->solverInfo, &rtmGetTPtr(MBD_SpeedControl_M));
    rtsiSetStepSizePtr(&MBD_SpeedControl_M->solverInfo,
                       &MBD_SpeedControl_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&MBD_SpeedControl_M->solverInfo, (&rtmGetErrorStatus
      (MBD_SpeedControl_M)));
    rtsiSetRTModelPtr(&MBD_SpeedControl_M->solverInfo, MBD_SpeedControl_M);
  }

  rtsiSetSimTimeStep(&MBD_SpeedControl_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&MBD_SpeedControl_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&MBD_SpeedControl_M->solverInfo, false);
  rtsiSetSolverName(&MBD_SpeedControl_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(MBD_SpeedControl_M, &MBD_SpeedControl_M->Timing.tArray[0]);
  MBD_SpeedControl_M->Timing.stepSize0 = 0.4;

  /* Start for FromWorkspace: '<S2>/fromWS_Signal 1' */
  {
    static real_T pTimeValues0[] = { 0.0, 10.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0 } ;

    MBD_SpeedControl_DW.fromWS_Signal1_PWORK.TimePtr = (void *) pTimeValues0;
    MBD_SpeedControl_DW.fromWS_Signal1_PWORK.DataPtr = (void *) pDataValues0;
    MBD_SpeedControl_DW.fromWS_Signal1_IWORK.PrevIndex = 0;
  }
}

/* Model terminate function */
void MBD_SpeedControl_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
