/*
 * File: MBD_SpeedControl.h
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

#ifndef MBD_SpeedControl_h_
#define MBD_SpeedControl_h_
#ifndef MBD_SpeedControl_COMMON_INCLUDES_
#define MBD_SpeedControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "math.h"
#endif                                 /* MBD_SpeedControl_COMMON_INCLUDES_ */

#include "MBD_SpeedControl_types.h"
#include <math.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Signal1;                      /* '<S2>/fromWS_Signal 1' */
} B_MBD_SpeedControl_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } fromWS_Signal1_PWORK;              /* '<S2>/fromWS_Signal 1' */

  struct {
    int_T PrevIndex;
  } fromWS_Signal1_IWORK;              /* '<S2>/fromWS_Signal 1' */

  uint8_T is_active_c3_MBD_SpeedControl;/* '<Root>/Chart' */
  uint8_T is_c3_MBD_SpeedControl;      /* '<Root>/Chart' */
} DW_MBD_SpeedControl_T;

/* Real-time Model Data Structure */
struct tag_RTM_MBD_SpeedControl_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_MBD_SpeedControl_T MBD_SpeedControl_B;

/* Block states (default storage) */
extern DW_MBD_SpeedControl_T MBD_SpeedControl_DW;

/* Model entry point functions */
extern void MBD_SpeedControl_initialize(void);
extern void MBD_SpeedControl_step(void);
extern void MBD_SpeedControl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_MBD_SpeedControl_T *const MBD_SpeedControl_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MBD_SpeedControl'
 * '<S1>'   : 'MBD_SpeedControl/Chart'
 * '<S2>'   : 'MBD_SpeedControl/Speed'
 */
#endif                                 /* MBD_SpeedControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
