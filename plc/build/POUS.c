void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





static inline INT __RD_SEQ_RBEAR_TRAP_MOD__INT__INT__INT1(BOOL EN,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD35_ENO,);
  __res = MOD__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD35_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __RD_SEQ_RBEAR_TRAP_DIV__INT__INT__INT2(BOOL EN,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_DIV39_ENO,);
  __res = DIV__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_DIV39_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __RD_SEQ_RBEAR_TRAP_MOD__INT__INT__INT3(BOOL EN,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD16_ENO,);
  __res = MOD__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD16_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __RD_SEQ_RBEAR_TRAP_DIV__INT__INT__INT4(BOOL EN,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_DIV54_ENO,);
  __res = DIV__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_DIV54_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __RD_SEQ_RBEAR_TRAP_MOD__INT__INT__INT5(BOOL EN,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD21_ENO,);
  __res = MOD__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD21_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __RD_SEQ_RBEAR_TRAP_DIV__INT__INT__INT6(BOOL EN,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_DIV20_ENO,);
  __res = DIV__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_DIV20_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __RD_SEQ_RBEAR_TRAP_MOD__INT__INT__INT7(BOOL EN,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD19_ENO,);
  __res = MOD__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD19_ENO,,__TMP_ENO);
  return __res;
}

static inline ULINT __RD_SEQ_RBEAR_TRAP_MUL__ULINT__ULINT8(BOOL EN,
  UINT __PARAM_COUNT,
  ULINT IN1,
  ULINT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MUL1_ENO,);
  __res = MUL__ULINT__ULINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MUL1_ENO,,__TMP_ENO);
  return __res;
}

static inline ULINT __RD_SEQ_RBEAR_TRAP_ADD__ULINT__ULINT9(BOOL EN,
  UINT __PARAM_COUNT,
  ULINT IN1,
  ULINT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ADD5_ENO,);
  __res = ADD__ULINT__ULINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_ADD5_ENO,,__TMP_ENO);
  return __res;
}

static inline ULINT __RD_SEQ_RBEAR_TRAP_MOD__ULINT__ULINT__ULINT10(BOOL EN,
  ULINT IN1,
  ULINT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD7_ENO,);
  __res = MOD__ULINT__ULINT__ULINT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD7_ENO,,__TMP_ENO);
  return __res;
}

static inline ULINT __RD_SEQ_RBEAR_TRAP_MOD__ULINT__ULINT__ULINT11(BOOL EN,
  ULINT IN1,
  ULINT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD9_ENO,);
  __res = MOD__ULINT__ULINT__ULINT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD9_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __RD_SEQ_RBEAR_TRAP_EQ__BOOL__INT12(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ121_ENO,);
  __res = EQ__BOOL__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ121_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __RD_SEQ_RBEAR_TRAP_EQ__BOOL__INT13(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ117_ENO,);
  __res = EQ__BOOL__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ117_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __RD_SEQ_RBEAR_TRAP_EQ__BOOL__INT14(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ130_ENO,);
  __res = EQ__BOOL__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ130_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __RD_SEQ_RBEAR_TRAP_EQ__BOOL__INT15(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ134_ENO,);
  __res = EQ__BOOL__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ134_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __RD_SEQ_RBEAR_TRAP_ULINT_TO_INT16(BOOL EN,
  ULINT IN,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ULINT_TO_INT231_ENO,);
  __res = ULINT_TO_INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_ULINT_TO_INT231_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __RD_SEQ_RBEAR_TRAP_MUL__INT__INT17(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MUL17_ENO,);
  __res = MUL__INT__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MUL17_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __RD_SEQ_RBEAR_TRAP_ADD__INT__INT18(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ADD14_ENO,);
  __res = ADD__INT__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_ADD14_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __RD_SEQ_RBEAR_TRAP_SUB__INT__INT__INT19(BOOL EN,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_SUB43_ENO,);
  __res = SUB__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_SUB43_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __RD_SEQ_RBEAR_TRAP_MOD__INT__INT__INT20(BOOL EN,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD245_ENO,);
  __res = MOD__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD245_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __RD_SEQ_RBEAR_TRAP_DIV__INT__INT__INT21(BOOL EN,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_DIV249_ENO,);
  __res = DIV__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_DIV249_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __RD_SEQ_RBEAR_TRAP_SUB__INT__INT__INT22(BOOL EN,
  INT IN1,
  INT IN2,
  RD_SEQ_RBEAR_TRAP *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_SUB253_ENO,);
  __res = SUB__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_SUB253_ENO,,__TMP_ENO);
  return __res;
}

void RD_SEQ_RBEAR_TRAP_init__(RD_SEQ_RBEAR_TRAP *data__, BOOL retain) {
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PANIC,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SET_TRAP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ACTIVATE_TRAP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN_MINUTOS,2,retain)
  __INIT_VAR(data__->IN_SEGUNDOS,30,retain)
  __INIT_VAR(data__->TIMER,0,retain)
  __INIT_VAR(data__->C_TIMER,0,retain)
  __INIT_VAR(data__->D_TIMER,0,retain)
  __INIT_VAR(data__->DISPLAY_M,0,retain)
  __INIT_VAR(data__->DISPLAY_S,0,retain)
  __INIT_VAR(data__->RANDOM,0,retain)
  __INIT_VAR(data__->RANDOM_ULINT,0,retain)
  __INIT_VAR(data__->SEED,0,retain)
  __INIT_VAR(data__->M10,10000,retain)
  __INIT_VAR(data__->A,32310901,retain)
  __INIT_VAR(data__->C,32310901,retain)
  __INIT_VAR(data__->M,4294967296,retain)
  __INIT_VAR(data__->CLOCK,__BOOL_LITERAL(FALSE),retain)
  TOF_init__(&data__->TOF0,retain);
  TON_init__(&data__->TON0,retain);
  CTU_ULINT_init__(&data__->CTU_ULINT0,retain);
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->D1,0,retain)
  __INIT_VAR(data__->D2,0,retain)
  __INIT_VAR(data__->D3,0,retain)
  __INIT_VAR(data__->D4,0,retain)
  CTU_init__(&data__->CTU0,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  CTU_init__(&data__->CTU1,retain);
  TOF_init__(&data__->TOF1,retain);
  CTU_init__(&data__->CTU2,retain);
  TOF_init__(&data__->TOF2,retain);
  CTU_init__(&data__->CTU3,retain);
  TOF_init__(&data__->TOF3,retain);
  CTU_init__(&data__->CTU4,retain);
  TOF_init__(&data__->TOF4,retain);
  __INIT_VAR(data__->B1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->G0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->G1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->G2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->G3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->G4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->O1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->O2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->O3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->O4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RELEASE_TRAP,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  R_TRIG_init__(&data__->R_TRIG0,retain);
  R_TRIG_init__(&data__->R_TRIG4,retain);
  __INIT_VAR(data__->_TMP_MOD35_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD35_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV39_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_DIV39_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD16_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD16_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV54_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_DIV54_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD21_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD21_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV20_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_DIV20_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD19_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD19_OUT,0,retain)
  R_TRIG_init__(&data__->R_TRIG5,retain);
  __INIT_VAR(data__->_TMP_MUL1_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL1_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD5_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ADD5_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD7_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD7_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD9_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD9_OUT,0,retain)
  R_TRIG_init__(&data__->R_TRIG6,retain);
  R_TRIG_init__(&data__->R_TRIG7,retain);
  R_TRIG_init__(&data__->R_TRIG8,retain);
  R_TRIG_init__(&data__->R_TRIG9,retain);
  __INIT_VAR(data__->_TMP_EQ121_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ121_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ117_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ117_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ130_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ130_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ134_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ134_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ULINT_TO_INT231_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ULINT_TO_INT231_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL17_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL17_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD14_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ADD14_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SUB43_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SUB43_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD245_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD245_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV249_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_DIV249_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SUB253_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SUB253_OUT,0,retain)
}

// Code part
void RD_SEQ_RBEAR_TRAP_body__(RD_SEQ_RBEAR_TRAP *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TON0.,IN,,!(__GET_VAR(data__->CLOCK,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,CLOCK,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->R_TRIG4.,CLK,,!(__GET_VAR(data__->CLOCK,)));
  R_TRIG_body__(&data__->R_TRIG4);
  __SET_VAR(data__->CTU_ULINT0.,CU,,__GET_VAR(data__->R_TRIG4.Q,));
  __SET_VAR(data__->CTU_ULINT0.,R,,__GET_VAR(data__->RESET,));
  __SET_VAR(data__->CTU_ULINT0.,PV,,9999);
  CTU_ULINT_body__(&data__->CTU_ULINT0);
  __SET_VAR(data__->,SEED,,__GET_VAR(data__->CTU_ULINT0.CV,));
  __SET_VAR(data__->,RESET,,__GET_VAR(data__->CTU_ULINT0.Q,));
  __SET_VAR(data__->,_TMP_MOD35_OUT,,__RD_SEQ_RBEAR_TRAP_MOD__INT__INT__INT1(
    (BOOL)__BOOL_LITERAL(TRUE),
    (INT)__GET_VAR(data__->RANDOM,),
    (INT)10,
    data__));
  if (__GET_VAR(data__->_TMP_MOD35_ENO,)) {
    __SET_VAR(data__->,D4,,__GET_VAR(data__->_TMP_MOD35_OUT,));
  };
  __SET_VAR(data__->,_TMP_DIV39_OUT,,__RD_SEQ_RBEAR_TRAP_DIV__INT__INT__INT2(
    (BOOL)__GET_VAR(data__->_TMP_MOD35_ENO,),
    (INT)__GET_VAR(data__->RANDOM,),
    (INT)10,
    data__));
  __SET_VAR(data__->,_TMP_MOD16_OUT,,__RD_SEQ_RBEAR_TRAP_MOD__INT__INT__INT3(
    (BOOL)__GET_VAR(data__->_TMP_DIV39_ENO,),
    (INT)__GET_VAR(data__->_TMP_DIV39_OUT,),
    (INT)10,
    data__));
  if (__GET_VAR(data__->_TMP_MOD16_ENO,)) {
    __SET_VAR(data__->,D3,,__GET_VAR(data__->_TMP_MOD16_OUT,));
  };
  __SET_VAR(data__->,_TMP_DIV54_OUT,,__RD_SEQ_RBEAR_TRAP_DIV__INT__INT__INT4(
    (BOOL)__BOOL_LITERAL(TRUE),
    (INT)__GET_VAR(data__->RANDOM,),
    (INT)100,
    data__));
  __SET_VAR(data__->,_TMP_MOD21_OUT,,__RD_SEQ_RBEAR_TRAP_MOD__INT__INT__INT5(
    (BOOL)__GET_VAR(data__->_TMP_DIV54_ENO,),
    (INT)__GET_VAR(data__->_TMP_DIV54_OUT,),
    (INT)10,
    data__));
  if (__GET_VAR(data__->_TMP_MOD21_ENO,)) {
    __SET_VAR(data__->,D2,,__GET_VAR(data__->_TMP_MOD21_OUT,));
  };
  __SET_VAR(data__->,_TMP_DIV20_OUT,,__RD_SEQ_RBEAR_TRAP_DIV__INT__INT__INT6(
    (BOOL)__GET_VAR(data__->_TMP_MOD21_ENO,),
    (INT)__GET_VAR(data__->RANDOM,),
    (INT)1000,
    data__));
  __SET_VAR(data__->,_TMP_MOD19_OUT,,__RD_SEQ_RBEAR_TRAP_MOD__INT__INT__INT7(
    (BOOL)__GET_VAR(data__->_TMP_DIV20_ENO,),
    (INT)__GET_VAR(data__->_TMP_DIV20_OUT,),
    (INT)10,
    data__));
  if (__GET_VAR(data__->_TMP_MOD19_ENO,)) {
    __SET_VAR(data__->,D1,,__GET_VAR(data__->_TMP_MOD19_OUT,));
  };
  __SET_VAR(data__->R_TRIG5.,CLK,,(__GET_VAR(data__->SET_TRAP,) && !(__GET_VAR(data__->CLOCK,))));
  R_TRIG_body__(&data__->R_TRIG5);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG5.Q,));
  __SET_VAR(data__->CTU0.,PV,,__GET_VAR(data__->TIMER,));
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->,ACTIVATE_TRAP,,(!(__GET_VAR(data__->RELEASE_TRAP,)) && __GET_VAR(data__->CTU0.Q,)));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->SET_TRAP,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->ER,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->,_TMP_MUL1_OUT,,__RD_SEQ_RBEAR_TRAP_MUL__ULINT__ULINT8(
    (BOOL)(__GET_VAR(data__->R_TRIG1.Q,) || __GET_VAR(data__->R_TRIG2.Q,)),
    (UINT)2,
    (ULINT)__GET_VAR(data__->SEED,),
    (ULINT)__GET_VAR(data__->A,),
    data__));
  __SET_VAR(data__->,_TMP_ADD5_OUT,,__RD_SEQ_RBEAR_TRAP_ADD__ULINT__ULINT9(
    (BOOL)__GET_VAR(data__->_TMP_MUL1_ENO,),
    (UINT)2,
    (ULINT)__GET_VAR(data__->_TMP_MUL1_OUT,),
    (ULINT)__GET_VAR(data__->C,),
    data__));
  __SET_VAR(data__->,_TMP_MOD7_OUT,,__RD_SEQ_RBEAR_TRAP_MOD__ULINT__ULINT__ULINT10(
    (BOOL)__GET_VAR(data__->_TMP_ADD5_ENO,),
    (ULINT)__GET_VAR(data__->_TMP_ADD5_OUT,),
    (ULINT)__GET_VAR(data__->M,),
    data__));
  __SET_VAR(data__->,_TMP_MOD9_OUT,,__RD_SEQ_RBEAR_TRAP_MOD__ULINT__ULINT__ULINT11(
    (BOOL)__GET_VAR(data__->_TMP_MOD7_ENO,),
    (ULINT)__GET_VAR(data__->_TMP_MOD7_OUT,),
    (ULINT)__GET_VAR(data__->M10,),
    data__));
  if (__GET_VAR(data__->_TMP_MOD9_ENO,)) {
    __SET_VAR(data__->,RANDOM_ULINT,,__GET_VAR(data__->_TMP_MOD9_OUT,));
  };
  __SET_VAR(data__->R_TRIG6.,CLK,,(__GET_VAR(data__->B1,) && !(__GET_VAR(data__->G0,))));
  R_TRIG_body__(&data__->R_TRIG6);
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG6.Q,));
  __SET_VAR(data__->CTU1.,R,,__GET_VAR(data__->ER,));
  __SET_VAR(data__->CTU1.,PV,,__GET_VAR(data__->D1,));
  CTU_body__(&data__->CTU1);
  __SET_VAR(data__->,M1,,__GET_VAR(data__->CTU1.Q,));
  __SET_VAR(data__->,R1,,((__GET_VAR(data__->E1,) && __GET_VAR(data__->B1,)) && !(__GET_VAR(data__->G0,))));
  __SET_VAR(data__->TOF1.,IN,,(__GET_VAR(data__->M1,) && !(__GET_VAR(data__->B1,))));
  __SET_VAR(data__->TOF1.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TOF_body__(&data__->TOF1);
  __SET_VAR(data__->,E1,,__GET_VAR(data__->TOF1.Q,));
  __SET_VAR(data__->R_TRIG7.,CLK,,(__GET_VAR(data__->B2,) && !(__GET_VAR(data__->G0,))));
  R_TRIG_body__(&data__->R_TRIG7);
  __SET_VAR(data__->CTU2.,CU,,__GET_VAR(data__->R_TRIG7.Q,));
  __SET_VAR(data__->CTU2.,R,,__GET_VAR(data__->ER,));
  __SET_VAR(data__->CTU2.,PV,,__GET_VAR(data__->D2,));
  CTU_body__(&data__->CTU2);
  __SET_VAR(data__->,M2,,__GET_VAR(data__->CTU2.Q,));
  __SET_VAR(data__->,R2,,((__GET_VAR(data__->E2,) && __GET_VAR(data__->B2,)) && !(__GET_VAR(data__->G0,))));
  __SET_VAR(data__->TOF2.,IN,,(__GET_VAR(data__->M2,) && !(__GET_VAR(data__->B2,))));
  __SET_VAR(data__->TOF2.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TOF_body__(&data__->TOF2);
  __SET_VAR(data__->,E2,,__GET_VAR(data__->TOF2.Q,));
  __SET_VAR(data__->R_TRIG8.,CLK,,(__GET_VAR(data__->B3,) && !(__GET_VAR(data__->G0,))));
  R_TRIG_body__(&data__->R_TRIG8);
  __SET_VAR(data__->CTU3.,CU,,__GET_VAR(data__->R_TRIG8.Q,));
  __SET_VAR(data__->CTU3.,R,,__GET_VAR(data__->ER,));
  __SET_VAR(data__->CTU3.,PV,,__GET_VAR(data__->D3,));
  CTU_body__(&data__->CTU3);
  __SET_VAR(data__->,M3,,__GET_VAR(data__->CTU3.Q,));
  __SET_VAR(data__->,R3,,((__GET_VAR(data__->E3,) && __GET_VAR(data__->B3,)) && !(__GET_VAR(data__->G0,))));
  __SET_VAR(data__->TOF3.,IN,,(__GET_VAR(data__->M3,) && !(__GET_VAR(data__->B3,))));
  __SET_VAR(data__->TOF3.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TOF_body__(&data__->TOF3);
  __SET_VAR(data__->,E3,,__GET_VAR(data__->TOF3.Q,));
  __SET_VAR(data__->R_TRIG9.,CLK,,(__GET_VAR(data__->B4,) && !(__GET_VAR(data__->G0,))));
  R_TRIG_body__(&data__->R_TRIG9);
  __SET_VAR(data__->CTU4.,CU,,__GET_VAR(data__->R_TRIG9.Q,));
  __SET_VAR(data__->CTU4.,R,,__GET_VAR(data__->ER,));
  __SET_VAR(data__->CTU4.,PV,,__GET_VAR(data__->D4,));
  CTU_body__(&data__->CTU4);
  __SET_VAR(data__->,M4,,__GET_VAR(data__->CTU4.Q,));
  __SET_VAR(data__->,R4,,((__GET_VAR(data__->E4,) && __GET_VAR(data__->B4,)) && !(__GET_VAR(data__->G0,))));
  __SET_VAR(data__->TOF4.,IN,,(__GET_VAR(data__->M4,) && !(__GET_VAR(data__->B4,))));
  __SET_VAR(data__->TOF4.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TOF_body__(&data__->TOF4);
  __SET_VAR(data__->,E4,,__GET_VAR(data__->TOF4.Q,));
  __SET_VAR(data__->,G0,,(((((((((((__GET_VAR(data__->B2,) && __GET_VAR(data__->B1,)) || (__GET_VAR(data__->B3,) && __GET_VAR(data__->B1,))) || (__GET_VAR(data__->B3,) && __GET_VAR(data__->B2,))) || ((__GET_VAR(data__->B3,) && __GET_VAR(data__->B2,)) && __GET_VAR(data__->B1,))) || (__GET_VAR(data__->B4,) && __GET_VAR(data__->B1,))) || (__GET_VAR(data__->B4,) && __GET_VAR(data__->B2,))) || (__GET_VAR(data__->B4,) && __GET_VAR(data__->B3,))) || ((__GET_VAR(data__->B4,) && __GET_VAR(data__->B3,)) && __GET_VAR(data__->B1,))) || ((__GET_VAR(data__->B4,) && __GET_VAR(data__->B3,)) && __GET_VAR(data__->B2,))) || (((__GET_VAR(data__->B4,) && __GET_VAR(data__->B3,)) && __GET_VAR(data__->B4,)) && __GET_VAR(data__->B3,))) || ((__GET_VAR(data__->B4,) && __GET_VAR(data__->B2,)) && __GET_VAR(data__->B1,))));
  __SET_VAR(data__->,O1,,((((!(__GET_VAR(data__->G2,)) && __GET_VAR(data__->M2,)) && __GET_VAR(data__->B1,)) || ((!(__GET_VAR(data__->G3,)) && __GET_VAR(data__->M3,)) && __GET_VAR(data__->B1,))) || ((!(__GET_VAR(data__->G4,)) && __GET_VAR(data__->M4,)) && __GET_VAR(data__->B1,))));
  __SET_VAR(data__->,O2,,((((!(__GET_VAR(data__->G1,)) && !(__GET_VAR(data__->M1,))) && __GET_VAR(data__->B2,)) || ((!(__GET_VAR(data__->G3,)) && __GET_VAR(data__->M3,)) && __GET_VAR(data__->B2,))) || ((!(__GET_VAR(data__->G4,)) && __GET_VAR(data__->M4,)) && __GET_VAR(data__->B2,))));
  __SET_VAR(data__->,O3,,((((!(__GET_VAR(data__->G1,)) && !(__GET_VAR(data__->M1,))) && __GET_VAR(data__->B3,)) || ((!(__GET_VAR(data__->G2,)) && !(__GET_VAR(data__->M2,))) && __GET_VAR(data__->B3,))) || ((!(__GET_VAR(data__->G4,)) && __GET_VAR(data__->M4,)) && __GET_VAR(data__->B3,))));
  __SET_VAR(data__->,O4,,((((!(__GET_VAR(data__->G1,)) && !(__GET_VAR(data__->M1,))) && __GET_VAR(data__->B4,)) || ((!(__GET_VAR(data__->G2,)) && !(__GET_VAR(data__->M2,))) && __GET_VAR(data__->B4,))) || ((!(__GET_VAR(data__->G3,)) && !(__GET_VAR(data__->M3,))) && __GET_VAR(data__->B4,))));
  __SET_VAR(data__->,_TMP_EQ121_OUT,,__RD_SEQ_RBEAR_TRAP_EQ__BOOL__INT12(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (INT)__GET_VAR(data__->D1,),
    (INT)0,
    data__));
  __SET_VAR(data__->,G1,,__GET_VAR(data__->_TMP_EQ121_OUT,));
  __SET_VAR(data__->,_TMP_EQ117_OUT,,__RD_SEQ_RBEAR_TRAP_EQ__BOOL__INT13(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (INT)__GET_VAR(data__->D2,),
    (INT)0,
    data__));
  __SET_VAR(data__->,G2,,__GET_VAR(data__->_TMP_EQ117_OUT,));
  __SET_VAR(data__->,_TMP_EQ130_OUT,,__RD_SEQ_RBEAR_TRAP_EQ__BOOL__INT14(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (INT)__GET_VAR(data__->D3,),
    (INT)0,
    data__));
  __SET_VAR(data__->,G3,,__GET_VAR(data__->_TMP_EQ130_OUT,));
  __SET_VAR(data__->,_TMP_EQ134_OUT,,__RD_SEQ_RBEAR_TRAP_EQ__BOOL__INT15(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (INT)__GET_VAR(data__->D4,),
    (INT)0,
    data__));
  __SET_VAR(data__->,G4,,__GET_VAR(data__->_TMP_EQ134_OUT,));
  __SET_VAR(data__->,ER,,((((((((__GET_VAR(data__->G0,) || __GET_VAR(data__->O1,)) || __GET_VAR(data__->O2,)) || __GET_VAR(data__->O3,)) || __GET_VAR(data__->O4,)) || __GET_VAR(data__->R1,)) || __GET_VAR(data__->R2,)) || __GET_VAR(data__->R3,)) || __GET_VAR(data__->R4,)));
  __SET_VAR(data__->,RELEASE_TRAP,,(__GET_VAR(data__->RELEASE_TRAP,) || (((((__GET_VAR(data__->M4,) && __GET_VAR(data__->M3,)) && __GET_VAR(data__->M2,)) && __GET_VAR(data__->M1,)) && !(__GET_VAR(data__->ACTIVATE_TRAP,))) && __GET_VAR(data__->SET_TRAP,))));
  __SET_VAR(data__->,_TMP_ULINT_TO_INT231_OUT,,__RD_SEQ_RBEAR_TRAP_ULINT_TO_INT16(
    (BOOL)__BOOL_LITERAL(TRUE),
    (ULINT)__GET_VAR(data__->RANDOM_ULINT,),
    data__));
  if (__GET_VAR(data__->_TMP_ULINT_TO_INT231_ENO,)) {
    __SET_VAR(data__->,RANDOM,,__GET_VAR(data__->_TMP_ULINT_TO_INT231_OUT,));
  };
  __SET_VAR(data__->,SET_TRAP,,(!(__GET_VAR(data__->PANIC,)) && (__GET_VAR(data__->SET_TRAP,) || __GET_VAR(data__->START,))));
  __SET_VAR(data__->,PANIC,,__GET_VAR(data__->PANIC,));
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_VAR(data__->SET_TRAP,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->,_TMP_MUL17_OUT,,__RD_SEQ_RBEAR_TRAP_MUL__INT__INT17(
    (BOOL)__GET_VAR(data__->R_TRIG3.Q,),
    (UINT)2,
    (INT)__GET_VAR(data__->IN_MINUTOS,),
    (INT)60,
    data__));
  __SET_VAR(data__->,_TMP_ADD14_OUT,,__RD_SEQ_RBEAR_TRAP_ADD__INT__INT18(
    (BOOL)__GET_VAR(data__->_TMP_MUL17_ENO,),
    (UINT)2,
    (INT)__GET_VAR(data__->_TMP_MUL17_OUT,),
    (INT)__GET_VAR(data__->IN_SEGUNDOS,),
    data__));
  if (__GET_VAR(data__->_TMP_ADD14_ENO,)) {
    __SET_VAR(data__->,TIMER,,__GET_VAR(data__->_TMP_ADD14_OUT,));
  };
  __SET_VAR(data__->R_TRIG0.,CLK,,__GET_VAR(data__->ER,));
  R_TRIG_body__(&data__->R_TRIG0);
  __SET_VAR(data__->,_TMP_SUB43_OUT,,__RD_SEQ_RBEAR_TRAP_SUB__INT__INT__INT19(
    (BOOL)__GET_VAR(data__->R_TRIG0.Q,),
    (INT)__GET_VAR(data__->TIMER,),
    (INT)10,
    data__));
  if (__GET_VAR(data__->_TMP_SUB43_ENO,)) {
    __SET_VAR(data__->,TIMER,,__GET_VAR(data__->_TMP_SUB43_OUT,));
  };
  __SET_VAR(data__->,C_TIMER,,__GET_VAR(data__->CTU0.CV,));
  __SET_VAR(data__->,_TMP_MOD245_OUT,,__RD_SEQ_RBEAR_TRAP_MOD__INT__INT__INT20(
    (BOOL)__BOOL_LITERAL(TRUE),
    (INT)__GET_VAR(data__->D_TIMER,),
    (INT)60,
    data__));
  if (__GET_VAR(data__->_TMP_MOD245_ENO,)) {
    __SET_VAR(data__->,DISPLAY_S,,__GET_VAR(data__->_TMP_MOD245_OUT,));
  };
  __SET_VAR(data__->,_TMP_DIV249_OUT,,__RD_SEQ_RBEAR_TRAP_DIV__INT__INT__INT21(
    (BOOL)__BOOL_LITERAL(TRUE),
    (INT)__GET_VAR(data__->D_TIMER,),
    (INT)60,
    data__));
  if (__GET_VAR(data__->_TMP_DIV249_ENO,)) {
    __SET_VAR(data__->,DISPLAY_M,,__GET_VAR(data__->_TMP_DIV249_OUT,));
  };
  __SET_VAR(data__->,_TMP_SUB253_OUT,,__RD_SEQ_RBEAR_TRAP_SUB__INT__INT__INT22(
    (BOOL)__BOOL_LITERAL(TRUE),
    (INT)__GET_VAR(data__->TIMER,),
    (INT)__GET_VAR(data__->C_TIMER,),
    data__));
  if (__GET_VAR(data__->_TMP_SUB253_ENO,)) {
    __SET_VAR(data__->,D_TIMER,,__GET_VAR(data__->_TMP_SUB253_OUT,));
  };

  goto __end;

__end:
  return;
} // RD_SEQ_RBEAR_TRAP_body__() 





void MY_CLOCK_COUNTER_init__(MY_CLOCK_COUNTER *data__, BOOL retain) {
  __INIT_VAR(data__->CLOCK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLOCK0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DISPLAY,0,retain)
  TON_init__(&data__->TON0,retain);
  TOF_init__(&data__->TOF0,retain);
  CTU_ULINT_init__(&data__->CTU_ULINT0,retain);
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
}

// Code part
void MY_CLOCK_COUNTER_body__(MY_CLOCK_COUNTER *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TON0.,IN,,!(__GET_VAR(data__->CLOCK,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->TOF0.,EN,,__GET_VAR(data__->TON0.ENO,));
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,CLOCK,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->R_TRIG1.,CLK,,!(__GET_VAR(data__->CLOCK,)));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->CTU_ULINT0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU_ULINT0.,R,,__GET_VAR(data__->RESET,));
  __SET_VAR(data__->CTU_ULINT0.,PV,,10);
  CTU_ULINT_body__(&data__->CTU_ULINT0);
  __SET_VAR(data__->,DISPLAY,,__GET_VAR(data__->CTU_ULINT0.CV,));
  __SET_VAR(data__->,RESET,,__GET_VAR(data__->CTU_ULINT0.Q,));

  goto __end;

__end:
  return;
} // MY_CLOCK_COUNTER_body__() 





static inline ULINT __DIGIT_EXTRACTOR_MOD__ULINT__ULINT__ULINT1(BOOL EN,
  ULINT IN1,
  ULINT IN2,
  DIGIT_EXTRACTOR *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD35_ENO,);
  __res = MOD__ULINT__ULINT__ULINT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD35_ENO,,__TMP_ENO);
  return __res;
}

static inline ULINT __DIGIT_EXTRACTOR_DIV__ULINT__ULINT__ULINT2(BOOL EN,
  ULINT IN1,
  ULINT IN2,
  DIGIT_EXTRACTOR *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_DIV39_ENO,);
  __res = DIV__ULINT__ULINT__ULINT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_DIV39_ENO,,__TMP_ENO);
  return __res;
}

static inline ULINT __DIGIT_EXTRACTOR_MOD__ULINT__ULINT__ULINT3(BOOL EN,
  ULINT IN1,
  ULINT IN2,
  DIGIT_EXTRACTOR *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD1_ENO,);
  __res = MOD__ULINT__ULINT__ULINT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD1_ENO,,__TMP_ENO);
  return __res;
}

static inline ULINT __DIGIT_EXTRACTOR_DIV__ULINT__ULINT__ULINT4(BOOL EN,
  ULINT IN1,
  ULINT IN2,
  DIGIT_EXTRACTOR *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_DIV54_ENO,);
  __res = DIV__ULINT__ULINT__ULINT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_DIV54_ENO,,__TMP_ENO);
  return __res;
}

static inline ULINT __DIGIT_EXTRACTOR_MOD__ULINT__ULINT__ULINT5(BOOL EN,
  ULINT IN1,
  ULINT IN2,
  DIGIT_EXTRACTOR *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD6_ENO,);
  __res = MOD__ULINT__ULINT__ULINT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD6_ENO,,__TMP_ENO);
  return __res;
}

static inline ULINT __DIGIT_EXTRACTOR_DIV__ULINT__ULINT__ULINT6(BOOL EN,
  ULINT IN1,
  ULINT IN2,
  DIGIT_EXTRACTOR *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_DIV5_ENO,);
  __res = DIV__ULINT__ULINT__ULINT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_DIV5_ENO,,__TMP_ENO);
  return __res;
}

static inline ULINT __DIGIT_EXTRACTOR_MOD__ULINT__ULINT__ULINT7(BOOL EN,
  ULINT IN1,
  ULINT IN2,
  DIGIT_EXTRACTOR *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD2_ENO,);
  __res = MOD__ULINT__ULINT__ULINT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD2_ENO,,__TMP_ENO);
  return __res;
}

void DIGIT_EXTRACTOR_init__(DIGIT_EXTRACTOR *data__, BOOL retain) {
  __INIT_VAR(data__->RANDOM,1234,retain)
  __INIT_VAR(data__->DIVISOR,10,retain)
  __INIT_VAR(data__->D1,0,1)
  __INIT_VAR(data__->D2,0,retain)
  __INIT_VAR(data__->D3,0,retain)
  __INIT_VAR(data__->D4,0,retain)
  __INIT_VAR(data__->M1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD35_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD35_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV39_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_DIV39_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD1_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD1_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV54_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_DIV54_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD6_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD6_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV5_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_DIV5_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD2_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD2_OUT,0,retain)
}

// Code part
void DIGIT_EXTRACTOR_body__(DIGIT_EXTRACTOR *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_MOD35_OUT,,__DIGIT_EXTRACTOR_MOD__ULINT__ULINT__ULINT1(
    (BOOL)__BOOL_LITERAL(TRUE),
    (ULINT)__GET_VAR(data__->RANDOM,),
    (ULINT)10,
    data__));
  if (__GET_VAR(data__->_TMP_MOD35_ENO,)) {
    __SET_VAR(data__->,D4,,__GET_VAR(data__->_TMP_MOD35_OUT,));
  };
  __SET_VAR(data__->,_TMP_DIV39_OUT,,__DIGIT_EXTRACTOR_DIV__ULINT__ULINT__ULINT2(
    (BOOL)__GET_VAR(data__->_TMP_MOD35_ENO,),
    (ULINT)__GET_VAR(data__->RANDOM,),
    (ULINT)10,
    data__));
  __SET_VAR(data__->,_TMP_MOD1_OUT,,__DIGIT_EXTRACTOR_MOD__ULINT__ULINT__ULINT3(
    (BOOL)__GET_VAR(data__->_TMP_DIV39_ENO,),
    (ULINT)__GET_VAR(data__->_TMP_DIV39_OUT,),
    (ULINT)10,
    data__));
  if (__GET_VAR(data__->_TMP_MOD1_ENO,)) {
    __SET_VAR(data__->,D3,,__GET_VAR(data__->_TMP_MOD1_OUT,));
  };
  __SET_VAR(data__->,_TMP_DIV54_OUT,,__DIGIT_EXTRACTOR_DIV__ULINT__ULINT__ULINT4(
    (BOOL)__BOOL_LITERAL(TRUE),
    (ULINT)__GET_VAR(data__->RANDOM,),
    (ULINT)100,
    data__));
  __SET_VAR(data__->,_TMP_MOD6_OUT,,__DIGIT_EXTRACTOR_MOD__ULINT__ULINT__ULINT5(
    (BOOL)__GET_VAR(data__->_TMP_DIV54_ENO,),
    (ULINT)__GET_VAR(data__->_TMP_DIV54_OUT,),
    (ULINT)10,
    data__));
  if (__GET_VAR(data__->_TMP_MOD6_ENO,)) {
    __SET_VAR(data__->,D2,,__GET_VAR(data__->_TMP_MOD6_OUT,));
  };
  __SET_VAR(data__->,_TMP_DIV5_OUT,,__DIGIT_EXTRACTOR_DIV__ULINT__ULINT__ULINT6(
    (BOOL)__GET_VAR(data__->_TMP_MOD6_ENO,),
    (ULINT)__GET_VAR(data__->RANDOM,),
    (ULINT)1000,
    data__));
  __SET_VAR(data__->,_TMP_MOD2_OUT,,__DIGIT_EXTRACTOR_MOD__ULINT__ULINT__ULINT7(
    (BOOL)__GET_VAR(data__->_TMP_DIV5_ENO,),
    (ULINT)__GET_VAR(data__->_TMP_DIV5_OUT,),
    (ULINT)10,
    data__));
  if (__GET_VAR(data__->_TMP_MOD2_ENO,)) {
    __SET_VAR(data__->,D1,,__GET_VAR(data__->_TMP_MOD2_OUT,));
  };

  goto __end;

__end:
  return;
} // DIGIT_EXTRACTOR_body__() 





static inline BOOL __PUZZLE_EQ__BOOL__INT1(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  PUZZLE *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ121_ENO,);
  __res = EQ__BOOL__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ121_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __PUZZLE_EQ__BOOL__INT2(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  PUZZLE *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ117_ENO,);
  __res = EQ__BOOL__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ117_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __PUZZLE_EQ__BOOL__INT3(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  PUZZLE *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ130_ENO,);
  __res = EQ__BOOL__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ130_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __PUZZLE_EQ__BOOL__INT4(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  PUZZLE *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ134_ENO,);
  __res = EQ__BOOL__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ134_ENO,,__TMP_ENO);
  return __res;
}

void PUZZLE_init__(PUZZLE *data__, BOOL retain) {
  __INIT_VAR(data__->D1,1,retain)
  __INIT_VAR(data__->D2,2,retain)
  __INIT_VAR(data__->D3,3,retain)
  __INIT_VAR(data__->D4,0,retain)
  __INIT_VAR(data__->B1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->M4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->E4,__BOOL_LITERAL(FALSE),retain)
  CTU_init__(&data__->CTU1,retain);
  __INIT_VAR(data__->R1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->R4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->G1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->G2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->G3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->G4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->G0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->O1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->O2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->O3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->O4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SAFE,__BOOL_LITERAL(FALSE),retain)
  CTU_init__(&data__->CTU2,retain);
  CTU_init__(&data__->CTU3,retain);
  CTU_init__(&data__->CTU4,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  R_TRIG_init__(&data__->R_TRIG3,retain);
  R_TRIG_init__(&data__->R_TRIG4,retain);
  __INIT_VAR(data__->_TMP_EQ121_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ121_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ117_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ117_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ130_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ130_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ134_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ134_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PUZZLE_body__(PUZZLE *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,(__GET_VAR(data__->B1,) && !(__GET_VAR(data__->G0,))));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU1.,R,,__GET_VAR(data__->ER,));
  __SET_VAR(data__->CTU1.,PV,,__GET_VAR(data__->D1,));
  CTU_body__(&data__->CTU1);
  __SET_VAR(data__->,M1,,__GET_VAR(data__->CTU1.Q,));
  __SET_VAR(data__->,R1,,((__GET_VAR(data__->E1,) && __GET_VAR(data__->B1,)) && !(__GET_VAR(data__->G0,))));
  __SET_VAR(data__->,G0,,(((((((((((__GET_VAR(data__->B2,) && __GET_VAR(data__->B1,)) || (__GET_VAR(data__->B3,) && __GET_VAR(data__->B1,))) || (__GET_VAR(data__->B3,) && __GET_VAR(data__->B2,))) || ((__GET_VAR(data__->B3,) && __GET_VAR(data__->B2,)) && __GET_VAR(data__->B1,))) || (__GET_VAR(data__->B4,) && __GET_VAR(data__->B1,))) || (__GET_VAR(data__->B4,) && __GET_VAR(data__->B2,))) || (__GET_VAR(data__->B4,) && __GET_VAR(data__->B3,))) || (((__GET_VAR(data__->B4,) && __GET_VAR(data__->B3,)) && __GET_VAR(data__->B4,)) && __GET_VAR(data__->B3,))) || ((__GET_VAR(data__->B4,) && __GET_VAR(data__->B2,)) && __GET_VAR(data__->B1,))) || ((__GET_VAR(data__->B4,) && __GET_VAR(data__->B3,)) && __GET_VAR(data__->B1,))) || ((__GET_VAR(data__->B4,) && __GET_VAR(data__->B3,)) && __GET_VAR(data__->B2,))));
  __SET_VAR(data__->,O1,,((((!(__GET_VAR(data__->G2,)) && __GET_VAR(data__->M2,)) && __GET_VAR(data__->B1,)) || ((!(__GET_VAR(data__->G3,)) && __GET_VAR(data__->M3,)) && __GET_VAR(data__->B1,))) || ((!(__GET_VAR(data__->G4,)) && __GET_VAR(data__->M4,)) && __GET_VAR(data__->B1,))));
  __SET_VAR(data__->R_TRIG2.,CLK,,(__GET_VAR(data__->B2,) && !(__GET_VAR(data__->G0,))));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTU2.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTU2.,R,,__GET_VAR(data__->ER,));
  __SET_VAR(data__->CTU2.,PV,,__GET_VAR(data__->D2,));
  CTU_body__(&data__->CTU2);
  __SET_VAR(data__->,M2,,__GET_VAR(data__->CTU2.Q,));
  __SET_VAR(data__->,R2,,((__GET_VAR(data__->E2,) && __GET_VAR(data__->B2,)) && !(__GET_VAR(data__->G0,))));
  __SET_VAR(data__->,E2,,(__GET_VAR(data__->M2,) && !(__GET_VAR(data__->B2,))));
  __SET_VAR(data__->R_TRIG3.,CLK,,(__GET_VAR(data__->B3,) && !(__GET_VAR(data__->G0,))));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->CTU3.,CU,,__GET_VAR(data__->R_TRIG3.Q,));
  __SET_VAR(data__->CTU3.,R,,__GET_VAR(data__->ER,));
  __SET_VAR(data__->CTU3.,PV,,__GET_VAR(data__->D3,));
  CTU_body__(&data__->CTU3);
  __SET_VAR(data__->,M3,,__GET_VAR(data__->CTU3.Q,));
  __SET_VAR(data__->,R3,,((__GET_VAR(data__->E3,) && __GET_VAR(data__->B3,)) && !(__GET_VAR(data__->G0,))));
  __SET_VAR(data__->,E3,,(__GET_VAR(data__->M3,) && !(__GET_VAR(data__->B3,))));
  __SET_VAR(data__->R_TRIG4.,CLK,,(__GET_VAR(data__->B4,) && !(__GET_VAR(data__->G0,))));
  R_TRIG_body__(&data__->R_TRIG4);
  __SET_VAR(data__->CTU4.,CU,,__GET_VAR(data__->R_TRIG4.Q,));
  __SET_VAR(data__->CTU4.,R,,__GET_VAR(data__->ER,));
  __SET_VAR(data__->CTU4.,PV,,__GET_VAR(data__->D4,));
  CTU_body__(&data__->CTU4);
  __SET_VAR(data__->,M4,,__GET_VAR(data__->CTU4.Q,));
  __SET_VAR(data__->,R4,,((__GET_VAR(data__->E4,) && __GET_VAR(data__->B4,)) && !(__GET_VAR(data__->G0,))));
  __SET_VAR(data__->,E4,,(__GET_VAR(data__->M4,) && !(__GET_VAR(data__->B4,))));
  __SET_VAR(data__->,O2,,((((!(__GET_VAR(data__->G1,)) && !(__GET_VAR(data__->M1,))) && __GET_VAR(data__->B2,)) || ((!(__GET_VAR(data__->G3,)) && __GET_VAR(data__->M3,)) && __GET_VAR(data__->B2,))) || ((!(__GET_VAR(data__->G4,)) && __GET_VAR(data__->M4,)) && __GET_VAR(data__->B2,))));
  __SET_VAR(data__->,O3,,((((!(__GET_VAR(data__->G1,)) && !(__GET_VAR(data__->M1,))) && __GET_VAR(data__->B3,)) || ((!(__GET_VAR(data__->G2,)) && !(__GET_VAR(data__->M2,))) && __GET_VAR(data__->B3,))) || ((!(__GET_VAR(data__->G4,)) && __GET_VAR(data__->M4,)) && __GET_VAR(data__->B3,))));
  __SET_VAR(data__->,O4,,((((!(__GET_VAR(data__->G1,)) && !(__GET_VAR(data__->M1,))) && __GET_VAR(data__->B4,)) || ((!(__GET_VAR(data__->G2,)) && !(__GET_VAR(data__->M2,))) && __GET_VAR(data__->B4,))) || ((!(__GET_VAR(data__->G3,)) && !(__GET_VAR(data__->M3,))) && __GET_VAR(data__->B4,))));
  __SET_VAR(data__->,E1,,(__GET_VAR(data__->M1,) && !(__GET_VAR(data__->B1,))));
  __SET_VAR(data__->,_TMP_EQ121_OUT,,__PUZZLE_EQ__BOOL__INT1(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (INT)__GET_VAR(data__->D1,),
    (INT)0,
    data__));
  __SET_VAR(data__->,G1,,__GET_VAR(data__->_TMP_EQ121_OUT,));
  __SET_VAR(data__->,_TMP_EQ117_OUT,,__PUZZLE_EQ__BOOL__INT2(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (INT)__GET_VAR(data__->D2,),
    (INT)0,
    data__));
  __SET_VAR(data__->,G2,,__GET_VAR(data__->_TMP_EQ117_OUT,));
  __SET_VAR(data__->,_TMP_EQ130_OUT,,__PUZZLE_EQ__BOOL__INT3(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (INT)__GET_VAR(data__->D3,),
    (INT)0,
    data__));
  __SET_VAR(data__->,G3,,__GET_VAR(data__->_TMP_EQ130_OUT,));
  __SET_VAR(data__->,_TMP_EQ134_OUT,,__PUZZLE_EQ__BOOL__INT4(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (INT)__GET_VAR(data__->D4,),
    (INT)0,
    data__));
  __SET_VAR(data__->,G4,,__GET_VAR(data__->_TMP_EQ134_OUT,));
  __SET_VAR(data__->,ER,,((((((((__GET_VAR(data__->G0,) || __GET_VAR(data__->O1,)) || __GET_VAR(data__->O2,)) || __GET_VAR(data__->O3,)) || __GET_VAR(data__->O4,)) || __GET_VAR(data__->R1,)) || __GET_VAR(data__->R2,)) || __GET_VAR(data__->R3,)) || __GET_VAR(data__->R4,)));
  __SET_VAR(data__->,SAFE,,(((__GET_VAR(data__->M4,) && __GET_VAR(data__->M3,)) && __GET_VAR(data__->M2,)) && __GET_VAR(data__->M1,)));

  goto __end;

__end:
  return;
} // PUZZLE_body__() 





static inline INT __SUB_TIMER_MOD__INT__INT__INT1(BOOL EN,
  INT IN1,
  INT IN2,
  SUB_TIMER *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD70_ENO,);
  __res = MOD__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD70_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __SUB_TIMER_DIV__INT__INT__INT2(BOOL EN,
  INT IN1,
  INT IN2,
  SUB_TIMER *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_DIV1_ENO,);
  __res = DIV__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_DIV1_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __SUB_TIMER_MUL__INT__INT3(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  SUB_TIMER *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MUL86_ENO,);
  __res = MUL__INT__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MUL86_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __SUB_TIMER_ADD__INT__INT4(BOOL EN,
  UINT __PARAM_COUNT,
  INT IN1,
  INT IN2,
  SUB_TIMER *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ADD89_ENO,);
  __res = ADD__INT__INT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_ADD89_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __SUB_TIMER_SUB__INT__INT__INT5(BOOL EN,
  INT IN1,
  INT IN2,
  SUB_TIMER *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_SUB99_ENO,);
  __res = SUB__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_SUB99_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __SUB_TIMER_SUB__INT__INT__INT6(BOOL EN,
  INT IN1,
  INT IN2,
  SUB_TIMER *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_SUB43_ENO,);
  __res = SUB__INT__INT__INT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_SUB43_ENO,,__TMP_ENO);
  return __res;
}

void SUB_TIMER_init__(SUB_TIMER *data__, BOOL retain) {
  __INIT_VAR(data__->ER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->START,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PANIC,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IN_MINUTOS,3,retain)
  __INIT_VAR(data__->IN_SEGUNDOS,10,retain)
  __INIT_VAR(data__->R_SEGUNDOS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->DISPLAY_M,0,retain)
  __INIT_VAR(data__->DISPLAY_S,0,retain)
  __INIT_VAR(data__->CLOCK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->I_TIMER,0,retain)
  __INIT_VAR(data__->TIMER,0,retain)
  __INIT_VAR(data__->C_TIMER,0,retain)
  __INIT_VAR(data__->D_TIMER,0,retain)
  TOF_init__(&data__->TOF0,retain);
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->SET_TRAP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ACTIVATE_TRAP,__BOOL_LITERAL(FALSE),retain)
  CTU_init__(&data__->CTU0,retain);
  R_TRIG_init__(&data__->R_TRIG0,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  __INIT_VAR(data__->_TMP_MOD70_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD70_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV1_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_DIV1_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL86_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL86_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD89_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ADD89_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SUB99_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SUB99_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SUB43_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SUB43_OUT,0,retain)
}

// Code part
void SUB_TIMER_body__(SUB_TIMER *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TON0.,IN,,!(__GET_VAR(data__->CLOCK,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->TOF0.,EN,,__GET_VAR(data__->TON0.ENO,));
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,CLOCK,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->R_TRIG2.,CLK,,(__GET_VAR(data__->SET_TRAP,) && !(__GET_VAR(data__->CLOCK,))));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTU0.,PV,,__GET_VAR(data__->TIMER,));
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->,ACTIVATE_TRAP,,__GET_VAR(data__->CTU0.Q,));
  __SET_VAR(data__->,SET_TRAP,,(!(__GET_VAR(data__->PANIC,)) && (__GET_VAR(data__->SET_TRAP,) || __GET_VAR(data__->START,))));
  __SET_VAR(data__->,_TMP_MOD70_OUT,,__SUB_TIMER_MOD__INT__INT__INT1(
    (BOOL)__BOOL_LITERAL(TRUE),
    (INT)__GET_VAR(data__->D_TIMER,),
    (INT)60,
    data__));
  if (__GET_VAR(data__->_TMP_MOD70_ENO,)) {
    __SET_VAR(data__->,DISPLAY_S,,__GET_VAR(data__->_TMP_MOD70_OUT,));
  };
  __SET_VAR(data__->,_TMP_DIV1_OUT,,__SUB_TIMER_DIV__INT__INT__INT2(
    (BOOL)__BOOL_LITERAL(TRUE),
    (INT)__GET_VAR(data__->D_TIMER,),
    (INT)60,
    data__));
  if (__GET_VAR(data__->_TMP_DIV1_ENO,)) {
    __SET_VAR(data__->,DISPLAY_M,,__GET_VAR(data__->_TMP_DIV1_OUT,));
  };
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->SET_TRAP,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->,_TMP_MUL86_OUT,,__SUB_TIMER_MUL__INT__INT3(
    (BOOL)__GET_VAR(data__->R_TRIG1.Q,),
    (UINT)2,
    (INT)__GET_VAR(data__->IN_MINUTOS,),
    (INT)60,
    data__));
  __SET_VAR(data__->,_TMP_ADD89_OUT,,__SUB_TIMER_ADD__INT__INT4(
    (BOOL)__GET_VAR(data__->_TMP_MUL86_ENO,),
    (UINT)2,
    (INT)__GET_VAR(data__->_TMP_MUL86_OUT,),
    (INT)__GET_VAR(data__->IN_SEGUNDOS,),
    data__));
  if (__GET_VAR(data__->_TMP_ADD89_ENO,)) {
    __SET_VAR(data__->,TIMER,,__GET_VAR(data__->_TMP_ADD89_OUT,));
  };
  __SET_VAR(data__->,C_TIMER,,__GET_VAR(data__->CTU0.CV,));
  __SET_VAR(data__->,_TMP_SUB99_OUT,,__SUB_TIMER_SUB__INT__INT__INT5(
    (BOOL)__BOOL_LITERAL(TRUE),
    (INT)__GET_VAR(data__->TIMER,),
    (INT)__GET_VAR(data__->C_TIMER,),
    data__));
  if (__GET_VAR(data__->_TMP_SUB99_ENO,)) {
    __SET_VAR(data__->,D_TIMER,,__GET_VAR(data__->_TMP_SUB99_OUT,));
  };
  __SET_VAR(data__->R_TRIG0.,CLK,,__GET_VAR(data__->ER,));
  R_TRIG_body__(&data__->R_TRIG0);
  __SET_VAR(data__->,_TMP_SUB43_OUT,,__SUB_TIMER_SUB__INT__INT__INT6(
    (BOOL)__GET_VAR(data__->R_TRIG0.Q,),
    (INT)__GET_VAR(data__->TIMER,),
    (INT)10,
    data__));
  if (__GET_VAR(data__->_TMP_SUB43_ENO,)) {
    __SET_VAR(data__->,TIMER,,__GET_VAR(data__->_TMP_SUB43_OUT,));
  };
  __SET_VAR(data__->,PANIC,,__GET_VAR(data__->PANIC,));

  goto __end;

__end:
  return;
} // SUB_TIMER_body__() 





static inline ULINT __LINEAR_CONGRUENTIAL_GENERATOR_MUL__ULINT__ULINT1(BOOL EN,
  UINT __PARAM_COUNT,
  ULINT IN1,
  ULINT IN2,
  LINEAR_CONGRUENTIAL_GENERATOR *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MUL1_ENO,);
  __res = MUL__ULINT__ULINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MUL1_ENO,,__TMP_ENO);
  return __res;
}

static inline ULINT __LINEAR_CONGRUENTIAL_GENERATOR_ADD__ULINT__ULINT2(BOOL EN,
  UINT __PARAM_COUNT,
  ULINT IN1,
  ULINT IN2,
  LINEAR_CONGRUENTIAL_GENERATOR *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ADD5_ENO,);
  __res = ADD__ULINT__ULINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_ADD5_ENO,,__TMP_ENO);
  return __res;
}

static inline ULINT __LINEAR_CONGRUENTIAL_GENERATOR_MOD__ULINT__ULINT__ULINT3(BOOL EN,
  ULINT IN1,
  ULINT IN2,
  LINEAR_CONGRUENTIAL_GENERATOR *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD7_ENO,);
  __res = MOD__ULINT__ULINT__ULINT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD7_ENO,,__TMP_ENO);
  return __res;
}

static inline ULINT __LINEAR_CONGRUENTIAL_GENERATOR_MOD__ULINT__ULINT__ULINT4(BOOL EN,
  ULINT IN1,
  ULINT IN2,
  LINEAR_CONGRUENTIAL_GENERATOR *data__)
{
  ULINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOD9_ENO,);
  __res = MOD__ULINT__ULINT__ULINT(EN,
    &__TMP_ENO,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_MOD9_ENO,,__TMP_ENO);
  return __res;
}

static inline INT __LINEAR_CONGRUENTIAL_GENERATOR_ULINT_TO_INT5(BOOL EN,
  ULINT IN,
  LINEAR_CONGRUENTIAL_GENERATOR *data__)
{
  INT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_ULINT_TO_INT231_ENO,);
  __res = ULINT_TO_INT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_ULINT_TO_INT231_ENO,,__TMP_ENO);
  return __res;
}

void LINEAR_CONGRUENTIAL_GENERATOR_init__(LINEAR_CONGRUENTIAL_GENERATOR *data__, BOOL retain) {
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
  TOF_init__(&data__->TOF0,retain);
  TON_init__(&data__->TON0,retain);
  CTU_ULINT_init__(&data__->CTU_ULINT0,retain);
  __INIT_VAR(data__->SET_TRAP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ER,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEED,0,retain)
  __INIT_VAR(data__->A,0,retain)
  __INIT_VAR(data__->C,0,retain)
  __INIT_VAR(data__->M,0,retain)
  __INIT_VAR(data__->M10,0,retain)
  __INIT_VAR(data__->RANDOM_ULINT,0,retain)
  __INIT_VAR(data__->RANDOM,0,retain)
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CLOCK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL1_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MUL1_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD5_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ADD5_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD7_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD7_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOD9_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOD9_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ULINT_TO_INT231_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_ULINT_TO_INT231_OUT,0,retain)
  R_TRIG_init__(&data__->R_TRIG3,retain);
}

// Code part
void LINEAR_CONGRUENTIAL_GENERATOR_body__(LINEAR_CONGRUENTIAL_GENERATOR *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->SET_TRAP,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->ER,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->,_TMP_MUL1_OUT,,__LINEAR_CONGRUENTIAL_GENERATOR_MUL__ULINT__ULINT1(
    (BOOL)(__GET_VAR(data__->R_TRIG1.Q,) || __GET_VAR(data__->R_TRIG2.Q,)),
    (UINT)2,
    (ULINT)__GET_VAR(data__->SEED,),
    (ULINT)__GET_VAR(data__->A,),
    data__));
  __SET_VAR(data__->,_TMP_ADD5_OUT,,__LINEAR_CONGRUENTIAL_GENERATOR_ADD__ULINT__ULINT2(
    (BOOL)__GET_VAR(data__->_TMP_MUL1_ENO,),
    (UINT)2,
    (ULINT)__GET_VAR(data__->_TMP_MUL1_OUT,),
    (ULINT)__GET_VAR(data__->C,),
    data__));
  __SET_VAR(data__->,_TMP_MOD7_OUT,,__LINEAR_CONGRUENTIAL_GENERATOR_MOD__ULINT__ULINT__ULINT3(
    (BOOL)__GET_VAR(data__->_TMP_ADD5_ENO,),
    (ULINT)__GET_VAR(data__->_TMP_ADD5_OUT,),
    (ULINT)__GET_VAR(data__->M,),
    data__));
  __SET_VAR(data__->,_TMP_MOD9_OUT,,__LINEAR_CONGRUENTIAL_GENERATOR_MOD__ULINT__ULINT__ULINT4(
    (BOOL)__GET_VAR(data__->_TMP_MOD7_ENO,),
    (ULINT)__GET_VAR(data__->_TMP_MOD7_OUT,),
    (ULINT)__GET_VAR(data__->M10,),
    data__));
  if (__GET_VAR(data__->_TMP_MOD9_ENO,)) {
    __SET_VAR(data__->,RANDOM_ULINT,,__GET_VAR(data__->_TMP_MOD9_OUT,));
  };
  __SET_VAR(data__->,_TMP_ULINT_TO_INT231_OUT,,__LINEAR_CONGRUENTIAL_GENERATOR_ULINT_TO_INT5(
    (BOOL)__BOOL_LITERAL(TRUE),
    (ULINT)__GET_VAR(data__->RANDOM_ULINT,),
    data__));
  __SET_VAR(data__->,RANDOM,,__GET_VAR(data__->_TMP_ULINT_TO_INT231_OUT,));
  __SET_VAR(data__->TON0.,IN,,!(__GET_VAR(data__->CLOCK,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 500, 0, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,CLOCK,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->R_TRIG3.,CLK,,!(__GET_VAR(data__->CLOCK,)));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->CTU_ULINT0.,CU,,__GET_VAR(data__->R_TRIG3.Q,));
  __SET_VAR(data__->CTU_ULINT0.,R,,__GET_VAR(data__->RESET,));
  __SET_VAR(data__->CTU_ULINT0.,PV,,9999);
  CTU_ULINT_body__(&data__->CTU_ULINT0);
  __SET_VAR(data__->,RESET,,__GET_VAR(data__->CTU_ULINT0.Q,));
  __SET_VAR(data__->,SEED,,__GET_VAR(data__->CTU_ULINT0.CV,));

  goto __end;

__end:
  return;
} // LINEAR_CONGRUENTIAL_GENERATOR_body__() 





