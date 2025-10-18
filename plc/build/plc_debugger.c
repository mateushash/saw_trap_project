/*
 * DEBUGGER code
 * 
 * On "publish", when buffer is free, debugger stores arbitrary variables 
 * content into, and mark this buffer as filled
 * 
 * 
 * Buffer content is read asynchronously, (from non real time part), 
 * and then buffer marked free again.
 *  
 * 
 * */
#ifdef TARGET_DEBUG_AND_RETAIN_DISABLE

void __init_debug    (void){}
void __cleanup_debug (void){}
void __retrieve_debug(void){}
void __publish_debug (void){}

#else

#include "iec_types_all.h"
#include "POUS.h"
/*for memcpy*/
#include <string.h>
#include <stdio.h>

typedef unsigned int dbgvardsc_index_t;
typedef unsigned short trace_buf_offset_t;

#define BUFFER_EMPTY 0
#define BUFFER_FULL 1

#ifndef TARGET_ONLINE_DEBUG_DISABLE

#define TRACE_BUFFER_SIZE 4096
#define TRACE_LIST_SIZE 1024

/* Atomically accessed variable for buffer state */
static long trace_buffer_state = BUFFER_EMPTY;

typedef struct trace_item_s {
    dbgvardsc_index_t dbgvardsc_index;
} trace_item_t;

trace_item_t trace_list[TRACE_LIST_SIZE];
char trace_buffer[TRACE_BUFFER_SIZE];

/* Trace's cursor*/
static trace_item_t *trace_list_collect_cursor = trace_list;
static trace_item_t *trace_list_addvar_cursor = trace_list;
static const trace_item_t *trace_list_end = 
    &trace_list[TRACE_LIST_SIZE-1];
static char *trace_buffer_cursor = trace_buffer;
static const char *trace_buffer_end = trace_buffer + TRACE_BUFFER_SIZE;



#define FORCE_BUFFER_SIZE 1024
#define FORCE_LIST_SIZE 256

typedef struct force_item_s {
    dbgvardsc_index_t dbgvardsc_index;
    void *value_pointer_backup;
} force_item_t;

force_item_t force_list[FORCE_LIST_SIZE];
char force_buffer[FORCE_BUFFER_SIZE];

/* Force's cursor*/
static force_item_t *force_list_apply_cursor = force_list;
static force_item_t *force_list_addvar_cursor = force_list;
static const force_item_t *force_list_end = 
    &force_list[FORCE_LIST_SIZE-1];
static char *force_buffer_cursor = force_buffer;
static const char *force_buffer_end = force_buffer + FORCE_BUFFER_SIZE;


#endif

/***
 * Declare programs 
 **/
extern RD_SEQ_RBEAR_TRAP RES0__INSTANCE0;
extern MY_CLOCK_COUNTER RES0__INSTANCE1;
extern DIGIT_EXTRACTOR RES0__INSTANCE2;
extern PUZZLE RES0__INSTANCE3;
extern SUB_TIMER RES0__INSTANCE4;

/***
 * Declare global variables from resources and conf 
 **/
extern       RD_SEQ_RBEAR_TRAP   RES0__INSTANCE0;
extern       MY_CLOCK_COUNTER   RES0__INSTANCE1;
extern       DIGIT_EXTRACTOR   RES0__INSTANCE2;
extern       PUZZLE   RES0__INSTANCE3;
extern       SUB_TIMER   RES0__INSTANCE4;

typedef const struct {
    void *ptr;
    __IEC_types_enum type;
} dbgvardsc_t;

static const dbgvardsc_t dbgvardsc[] = {
{&(RES0__INSTANCE0.START), BOOL_ENUM},
{&(RES0__INSTANCE0.PANIC), BOOL_ENUM},
{&(RES0__INSTANCE0.ER), BOOL_ENUM},
{&(RES0__INSTANCE0.SET_TRAP), BOOL_ENUM},
{&(RES0__INSTANCE0.ACTIVATE_TRAP), BOOL_ENUM},
{&(RES0__INSTANCE0.IN_MINUTOS), INT_ENUM},
{&(RES0__INSTANCE0.IN_SEGUNDOS), INT_ENUM},
{&(RES0__INSTANCE0.TIMER), INT_ENUM},
{&(RES0__INSTANCE0.C_TIMER), INT_ENUM},
{&(RES0__INSTANCE0.D_TIMER), INT_ENUM},
{&(RES0__INSTANCE0.DISPLAY_M), INT_ENUM},
{&(RES0__INSTANCE0.DISPLAY_S), INT_ENUM},
{&(RES0__INSTANCE0.RANDOM), INT_ENUM},
{&(RES0__INSTANCE0.RANDOM_ULINT), ULINT_ENUM},
{&(RES0__INSTANCE0.SEED), ULINT_ENUM},
{&(RES0__INSTANCE0.M10), ULINT_ENUM},
{&(RES0__INSTANCE0.A), ULINT_ENUM},
{&(RES0__INSTANCE0.C), ULINT_ENUM},
{&(RES0__INSTANCE0.M), ULINT_ENUM},
{&(RES0__INSTANCE0.CLOCK), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF0.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF0.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TOF0.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF0.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TOF0.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TOF0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TOF0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TON0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TON0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TON0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.CTU_ULINT0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU_ULINT0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU_ULINT0.CU), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU_ULINT0.R), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU_ULINT0.PV), ULINT_ENUM},
{&(RES0__INSTANCE0.CTU_ULINT0.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU_ULINT0.CV), ULINT_ENUM},
{&(RES0__INSTANCE0.CTU_ULINT0.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU_ULINT0.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU_ULINT0.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU_ULINT0.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU_ULINT0.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE0.RESET), BOOL_ENUM},
{&(RES0__INSTANCE0.D1), INT_ENUM},
{&(RES0__INSTANCE0.D2), INT_ENUM},
{&(RES0__INSTANCE0.D3), INT_ENUM},
{&(RES0__INSTANCE0.D4), INT_ENUM},
{&(RES0__INSTANCE0.CTU0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.CU), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.R), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.PV), INT_ENUM},
{&(RES0__INSTANCE0.CTU0.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.CV), INT_ENUM},
{&(RES0__INSTANCE0.CTU0.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU0.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.CU), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.R), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.PV), INT_ENUM},
{&(RES0__INSTANCE0.CTU1.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.CV), INT_ENUM},
{&(RES0__INSTANCE0.CTU1.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU1.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF1.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF1.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF1.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TOF1.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF1.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TOF1.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TOF1.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF1.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TOF1.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.CTU2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.CU), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.R), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.PV), INT_ENUM},
{&(RES0__INSTANCE0.CTU2.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.CV), INT_ENUM},
{&(RES0__INSTANCE0.CTU2.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU2.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF2.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF2.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TOF2.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF2.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TOF2.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TOF2.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF2.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TOF2.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.CTU3.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.CU), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.R), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.PV), INT_ENUM},
{&(RES0__INSTANCE0.CTU3.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.CV), INT_ENUM},
{&(RES0__INSTANCE0.CTU3.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU3.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF3.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF3.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF3.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TOF3.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF3.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TOF3.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TOF3.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF3.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TOF3.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.CTU4.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.CU), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.R), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.PV), INT_ENUM},
{&(RES0__INSTANCE0.CTU4.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.CV), INT_ENUM},
{&(RES0__INSTANCE0.CTU4.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.CTU4.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF4.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF4.IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF4.PT), TIME_ENUM},
{&(RES0__INSTANCE0.TOF4.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF4.ET), TIME_ENUM},
{&(RES0__INSTANCE0.TOF4.STATE), SINT_ENUM},
{&(RES0__INSTANCE0.TOF4.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE0.TOF4.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.TOF4.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE0.B1), BOOL_ENUM},
{&(RES0__INSTANCE0.B2), BOOL_ENUM},
{&(RES0__INSTANCE0.B3), BOOL_ENUM},
{&(RES0__INSTANCE0.B4), BOOL_ENUM},
{&(RES0__INSTANCE0.M1), BOOL_ENUM},
{&(RES0__INSTANCE0.M2), BOOL_ENUM},
{&(RES0__INSTANCE0.M3), BOOL_ENUM},
{&(RES0__INSTANCE0.M4), BOOL_ENUM},
{&(RES0__INSTANCE0.E1), BOOL_ENUM},
{&(RES0__INSTANCE0.E2), BOOL_ENUM},
{&(RES0__INSTANCE0.E3), BOOL_ENUM},
{&(RES0__INSTANCE0.E4), BOOL_ENUM},
{&(RES0__INSTANCE0.R1), BOOL_ENUM},
{&(RES0__INSTANCE0.R2), BOOL_ENUM},
{&(RES0__INSTANCE0.R3), BOOL_ENUM},
{&(RES0__INSTANCE0.R4), BOOL_ENUM},
{&(RES0__INSTANCE0.G0), BOOL_ENUM},
{&(RES0__INSTANCE0.G1), BOOL_ENUM},
{&(RES0__INSTANCE0.G2), BOOL_ENUM},
{&(RES0__INSTANCE0.G3), BOOL_ENUM},
{&(RES0__INSTANCE0.G4), BOOL_ENUM},
{&(RES0__INSTANCE0.O1), BOOL_ENUM},
{&(RES0__INSTANCE0.O2), BOOL_ENUM},
{&(RES0__INSTANCE0.O3), BOOL_ENUM},
{&(RES0__INSTANCE0.O4), BOOL_ENUM},
{&(RES0__INSTANCE0.RELEASE_TRAP), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG2.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG3.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG0.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG0.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG0.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG0.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG4.M), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOD35_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOD35_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_DIV39_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_DIV39_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOD16_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOD16_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_DIV54_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_DIV54_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOD21_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOD21_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_DIV20_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_DIV20_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOD19_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOD19_OUT), INT_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG5.M), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MUL1_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MUL1_OUT), ULINT_ENUM},
{&(RES0__INSTANCE0._TMP_ADD5_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_ADD5_OUT), ULINT_ENUM},
{&(RES0__INSTANCE0._TMP_MOD7_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOD7_OUT), ULINT_ENUM},
{&(RES0__INSTANCE0._TMP_MOD9_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOD9_OUT), ULINT_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG6.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG7.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG8.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG8.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG8.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG8.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG8.M), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG9.EN), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG9.ENO), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG9.CLK), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG9.Q), BOOL_ENUM},
{&(RES0__INSTANCE0.R_TRIG9.M), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_EQ121_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_EQ121_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_EQ117_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_EQ117_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_EQ130_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_EQ130_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_EQ134_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_EQ134_OUT), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_ULINT_TO_INT231_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_ULINT_TO_INT231_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MUL17_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MUL17_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_ADD14_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_ADD14_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_SUB43_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_SUB43_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_MOD245_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_MOD245_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_DIV249_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_DIV249_OUT), INT_ENUM},
{&(RES0__INSTANCE0._TMP_SUB253_ENO), BOOL_ENUM},
{&(RES0__INSTANCE0._TMP_SUB253_OUT), INT_ENUM},
{&(RES0__INSTANCE1.CLOCK), BOOL_ENUM},
{&(RES0__INSTANCE1.CLOCK0), BOOL_ENUM},
{&(RES0__INSTANCE1.DISPLAY), ULINT_ENUM},
{&(RES0__INSTANCE1.TON0.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.TON0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.TON0.IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TON0.PT), TIME_ENUM},
{&(RES0__INSTANCE1.TON0.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.TON0.ET), TIME_ENUM},
{&(RES0__INSTANCE1.TON0.STATE), SINT_ENUM},
{&(RES0__INSTANCE1.TON0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TON0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.TON0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.TOF0.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.TOF0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.TOF0.IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TOF0.PT), TIME_ENUM},
{&(RES0__INSTANCE1.TOF0.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.TOF0.ET), TIME_ENUM},
{&(RES0__INSTANCE1.TOF0.STATE), SINT_ENUM},
{&(RES0__INSTANCE1.TOF0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE1.TOF0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.TOF0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE1.CTU_ULINT0.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU_ULINT0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU_ULINT0.CU), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU_ULINT0.R), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU_ULINT0.PV), ULINT_ENUM},
{&(RES0__INSTANCE1.CTU_ULINT0.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU_ULINT0.CV), ULINT_ENUM},
{&(RES0__INSTANCE1.CTU_ULINT0.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU_ULINT0.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU_ULINT0.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU_ULINT0.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.CTU_ULINT0.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE1.RESET), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE1.R_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE2.RANDOM), ULINT_ENUM},
{&(RES0__INSTANCE2.DIVISOR), ULINT_ENUM},
{&(RES0__INSTANCE2.D1), ULINT_ENUM},
{&(RES0__INSTANCE2.D2), ULINT_ENUM},
{&(RES0__INSTANCE2.D3), ULINT_ENUM},
{&(RES0__INSTANCE2.D4), ULINT_ENUM},
{&(RES0__INSTANCE2.M1), BOOL_ENUM},
{&(RES0__INSTANCE2._TMP_MOD35_ENO), BOOL_ENUM},
{&(RES0__INSTANCE2._TMP_MOD35_OUT), ULINT_ENUM},
{&(RES0__INSTANCE2._TMP_DIV39_ENO), BOOL_ENUM},
{&(RES0__INSTANCE2._TMP_DIV39_OUT), ULINT_ENUM},
{&(RES0__INSTANCE2._TMP_MOD1_ENO), BOOL_ENUM},
{&(RES0__INSTANCE2._TMP_MOD1_OUT), ULINT_ENUM},
{&(RES0__INSTANCE2._TMP_DIV54_ENO), BOOL_ENUM},
{&(RES0__INSTANCE2._TMP_DIV54_OUT), ULINT_ENUM},
{&(RES0__INSTANCE2._TMP_MOD6_ENO), BOOL_ENUM},
{&(RES0__INSTANCE2._TMP_MOD6_OUT), ULINT_ENUM},
{&(RES0__INSTANCE2._TMP_DIV5_ENO), BOOL_ENUM},
{&(RES0__INSTANCE2._TMP_DIV5_OUT), ULINT_ENUM},
{&(RES0__INSTANCE2._TMP_MOD2_ENO), BOOL_ENUM},
{&(RES0__INSTANCE2._TMP_MOD2_OUT), ULINT_ENUM},
{&(RES0__INSTANCE3.D1), INT_ENUM},
{&(RES0__INSTANCE3.D2), INT_ENUM},
{&(RES0__INSTANCE3.D3), INT_ENUM},
{&(RES0__INSTANCE3.D4), INT_ENUM},
{&(RES0__INSTANCE3.B1), BOOL_ENUM},
{&(RES0__INSTANCE3.B2), BOOL_ENUM},
{&(RES0__INSTANCE3.B3), BOOL_ENUM},
{&(RES0__INSTANCE3.B4), BOOL_ENUM},
{&(RES0__INSTANCE3.M1), BOOL_ENUM},
{&(RES0__INSTANCE3.M2), BOOL_ENUM},
{&(RES0__INSTANCE3.M3), BOOL_ENUM},
{&(RES0__INSTANCE3.M4), BOOL_ENUM},
{&(RES0__INSTANCE3.E1), BOOL_ENUM},
{&(RES0__INSTANCE3.E2), BOOL_ENUM},
{&(RES0__INSTANCE3.E3), BOOL_ENUM},
{&(RES0__INSTANCE3.E4), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU1.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU1.CU), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU1.R), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU1.PV), INT_ENUM},
{&(RES0__INSTANCE3.CTU1.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU1.CV), INT_ENUM},
{&(RES0__INSTANCE3.CTU1.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU1.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU1.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU1.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU1.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE3.R1), BOOL_ENUM},
{&(RES0__INSTANCE3.R2), BOOL_ENUM},
{&(RES0__INSTANCE3.R3), BOOL_ENUM},
{&(RES0__INSTANCE3.R4), BOOL_ENUM},
{&(RES0__INSTANCE3.G1), BOOL_ENUM},
{&(RES0__INSTANCE3.G2), BOOL_ENUM},
{&(RES0__INSTANCE3.G3), BOOL_ENUM},
{&(RES0__INSTANCE3.G4), BOOL_ENUM},
{&(RES0__INSTANCE3.G0), BOOL_ENUM},
{&(RES0__INSTANCE3.O1), BOOL_ENUM},
{&(RES0__INSTANCE3.O2), BOOL_ENUM},
{&(RES0__INSTANCE3.O3), BOOL_ENUM},
{&(RES0__INSTANCE3.O4), BOOL_ENUM},
{&(RES0__INSTANCE3.ER), BOOL_ENUM},
{&(RES0__INSTANCE3.SAFE), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU2.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU2.CU), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU2.R), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU2.PV), INT_ENUM},
{&(RES0__INSTANCE3.CTU2.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU2.CV), INT_ENUM},
{&(RES0__INSTANCE3.CTU2.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU2.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU2.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU2.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU2.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU3.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU3.CU), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU3.R), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU3.PV), INT_ENUM},
{&(RES0__INSTANCE3.CTU3.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU3.CV), INT_ENUM},
{&(RES0__INSTANCE3.CTU3.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU3.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU3.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU3.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU3.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU4.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU4.CU), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU4.R), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU4.PV), INT_ENUM},
{&(RES0__INSTANCE3.CTU4.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU4.CV), INT_ENUM},
{&(RES0__INSTANCE3.CTU4.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU4.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU4.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU4.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.CTU4.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG2.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG2.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG2.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG2.M), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG3.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG3.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG3.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG3.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG3.M), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG4.EN), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG4.ENO), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG4.CLK), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG4.Q), BOOL_ENUM},
{&(RES0__INSTANCE3.R_TRIG4.M), BOOL_ENUM},
{&(RES0__INSTANCE3._TMP_EQ121_ENO), BOOL_ENUM},
{&(RES0__INSTANCE3._TMP_EQ121_OUT), BOOL_ENUM},
{&(RES0__INSTANCE3._TMP_EQ117_ENO), BOOL_ENUM},
{&(RES0__INSTANCE3._TMP_EQ117_OUT), BOOL_ENUM},
{&(RES0__INSTANCE3._TMP_EQ130_ENO), BOOL_ENUM},
{&(RES0__INSTANCE3._TMP_EQ130_OUT), BOOL_ENUM},
{&(RES0__INSTANCE3._TMP_EQ134_ENO), BOOL_ENUM},
{&(RES0__INSTANCE3._TMP_EQ134_OUT), BOOL_ENUM},
{&(RES0__INSTANCE4.ER), BOOL_ENUM},
{&(RES0__INSTANCE4.START), BOOL_ENUM},
{&(RES0__INSTANCE4.PANIC), BOOL_ENUM},
{&(RES0__INSTANCE4.IN_MINUTOS), INT_ENUM},
{&(RES0__INSTANCE4.IN_SEGUNDOS), INT_ENUM},
{&(RES0__INSTANCE4.R_SEGUNDOS), BOOL_ENUM},
{&(RES0__INSTANCE4.DISPLAY_M), INT_ENUM},
{&(RES0__INSTANCE4.DISPLAY_S), INT_ENUM},
{&(RES0__INSTANCE4.CLOCK), BOOL_ENUM},
{&(RES0__INSTANCE4.I_TIMER), INT_ENUM},
{&(RES0__INSTANCE4.TIMER), INT_ENUM},
{&(RES0__INSTANCE4.C_TIMER), INT_ENUM},
{&(RES0__INSTANCE4.D_TIMER), INT_ENUM},
{&(RES0__INSTANCE4.TOF0.EN), BOOL_ENUM},
{&(RES0__INSTANCE4.TOF0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE4.TOF0.IN), BOOL_ENUM},
{&(RES0__INSTANCE4.TOF0.PT), TIME_ENUM},
{&(RES0__INSTANCE4.TOF0.Q), BOOL_ENUM},
{&(RES0__INSTANCE4.TOF0.ET), TIME_ENUM},
{&(RES0__INSTANCE4.TOF0.STATE), SINT_ENUM},
{&(RES0__INSTANCE4.TOF0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE4.TOF0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE4.TOF0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE4.TON0.EN), BOOL_ENUM},
{&(RES0__INSTANCE4.TON0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE4.TON0.IN), BOOL_ENUM},
{&(RES0__INSTANCE4.TON0.PT), TIME_ENUM},
{&(RES0__INSTANCE4.TON0.Q), BOOL_ENUM},
{&(RES0__INSTANCE4.TON0.ET), TIME_ENUM},
{&(RES0__INSTANCE4.TON0.STATE), SINT_ENUM},
{&(RES0__INSTANCE4.TON0.PREV_IN), BOOL_ENUM},
{&(RES0__INSTANCE4.TON0.CURRENT_TIME), TIME_ENUM},
{&(RES0__INSTANCE4.TON0.START_TIME), TIME_ENUM},
{&(RES0__INSTANCE4.SET_TRAP), BOOL_ENUM},
{&(RES0__INSTANCE4.ACTIVATE_TRAP), BOOL_ENUM},
{&(RES0__INSTANCE4.CTU0.EN), BOOL_ENUM},
{&(RES0__INSTANCE4.CTU0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE4.CTU0.CU), BOOL_ENUM},
{&(RES0__INSTANCE4.CTU0.R), BOOL_ENUM},
{&(RES0__INSTANCE4.CTU0.PV), INT_ENUM},
{&(RES0__INSTANCE4.CTU0.Q), BOOL_ENUM},
{&(RES0__INSTANCE4.CTU0.CV), INT_ENUM},
{&(RES0__INSTANCE4.CTU0.CU_T.EN), BOOL_ENUM},
{&(RES0__INSTANCE4.CTU0.CU_T.ENO), BOOL_ENUM},
{&(RES0__INSTANCE4.CTU0.CU_T.CLK), BOOL_ENUM},
{&(RES0__INSTANCE4.CTU0.CU_T.Q), BOOL_ENUM},
{&(RES0__INSTANCE4.CTU0.CU_T.M), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG0.EN), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG0.ENO), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG0.CLK), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG0.Q), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG0.M), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG1.EN), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG1.ENO), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG1.CLK), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG1.Q), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG1.M), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG2.EN), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG2.ENO), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG2.CLK), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG2.Q), BOOL_ENUM},
{&(RES0__INSTANCE4.R_TRIG2.M), BOOL_ENUM},
{&(RES0__INSTANCE4._TMP_MOD70_ENO), BOOL_ENUM},
{&(RES0__INSTANCE4._TMP_MOD70_OUT), INT_ENUM},
{&(RES0__INSTANCE4._TMP_DIV1_ENO), BOOL_ENUM},
{&(RES0__INSTANCE4._TMP_DIV1_OUT), INT_ENUM},
{&(RES0__INSTANCE4._TMP_MUL86_ENO), BOOL_ENUM},
{&(RES0__INSTANCE4._TMP_MUL86_OUT), INT_ENUM},
{&(RES0__INSTANCE4._TMP_ADD89_ENO), BOOL_ENUM},
{&(RES0__INSTANCE4._TMP_ADD89_OUT), INT_ENUM},
{&(RES0__INSTANCE4._TMP_SUB99_ENO), BOOL_ENUM},
{&(RES0__INSTANCE4._TMP_SUB99_OUT), INT_ENUM},
{&(RES0__INSTANCE4._TMP_SUB43_ENO), BOOL_ENUM},
{&(RES0__INSTANCE4._TMP_SUB43_OUT), INT_ENUM}
};

static const dbgvardsc_index_t retain_list[] = {
/* RES0__INSTANCE0.CTU_ULINT0.CU_T.M */ 51,
/* RES0__INSTANCE0.CTU0.CU_T.M */ 68,
/* RES0__INSTANCE0.R_TRIG1.M */ 73,
/* RES0__INSTANCE0.CTU1.CU_T.M */ 85,
/* RES0__INSTANCE0.CTU2.CU_T.M */ 107,
/* RES0__INSTANCE0.CTU3.CU_T.M */ 129,
/* RES0__INSTANCE0.CTU4.CU_T.M */ 151,
/* RES0__INSTANCE0.R_TRIG2.M */ 192,
/* RES0__INSTANCE0.R_TRIG3.M */ 197,
/* RES0__INSTANCE0.R_TRIG0.M */ 202,
/* RES0__INSTANCE0.R_TRIG4.M */ 207,
/* RES0__INSTANCE0.R_TRIG5.M */ 226,
/* RES0__INSTANCE0.R_TRIG6.M */ 239,
/* RES0__INSTANCE0.R_TRIG7.M */ 244,
/* RES0__INSTANCE0.R_TRIG8.M */ 249,
/* RES0__INSTANCE0.R_TRIG9.M */ 254,
/* RES0__INSTANCE1.CTU_ULINT0.CU_T.M */ 311,
/* RES0__INSTANCE1.R_TRIG1.M */ 317,
/* RES0__INSTANCE2.D1 */ 320,
/* RES0__INSTANCE3.CTU1.CU_T.M */ 366,
/* RES0__INSTANCE3.CTU2.CU_T.M */ 393,
/* RES0__INSTANCE3.CTU3.CU_T.M */ 405,
/* RES0__INSTANCE3.CTU4.CU_T.M */ 417,
/* RES0__INSTANCE3.R_TRIG1.M */ 422,
/* RES0__INSTANCE3.R_TRIG2.M */ 427,
/* RES0__INSTANCE3.R_TRIG3.M */ 432,
/* RES0__INSTANCE3.R_TRIG4.M */ 437,
/* RES0__INSTANCE4.CTU0.CU_T.M */ 492,
/* RES0__INSTANCE4.R_TRIG0.M */ 497,
/* RES0__INSTANCE4.R_TRIG1.M */ 502,
/* RES0__INSTANCE4.R_TRIG2.M */ 507
};
static unsigned int retain_list_collect_cursor = 0;
static const unsigned int retain_list_size = sizeof(retain_list)/sizeof(dbgvardsc_index_t);

typedef void(*__for_each_variable_do_fp)(dbgvardsc_t*);
void __for_each_variable_do(__for_each_variable_do_fp fp)
{
    unsigned int i;
    for(i = 0; i < sizeof(dbgvardsc)/sizeof(dbgvardsc_t); i++){
        dbgvardsc_t *dsc = &dbgvardsc[i];
        if(dsc->type != UNKNOWN_ENUM) 
            (*fp)(dsc);
    }
}

#define __Unpack_desc_type dbgvardsc_t


#define __Unpack_case_t(TYPENAME)                                           \
        case TYPENAME##_ENUM :                                              \
            if(flags) *flags = ((__IEC_##TYPENAME##_t *)varp)->flags;       \
            if(value_p) *value_p = &((__IEC_##TYPENAME##_t *)varp)->value;  \
		    if(size) *size = sizeof(TYPENAME);                              \
            break;

#define __Unpack_case_p(TYPENAME)                                           \
        case TYPENAME##_O_ENUM :                                            \
        case TYPENAME##_P_ENUM :                                            \
            if(flags) *flags = ((__IEC_##TYPENAME##_p *)varp)->flags;       \
            if(value_p) *value_p = ((__IEC_##TYPENAME##_p *)varp)->value;   \
		    if(size) *size = sizeof(TYPENAME);                              \
            break;

#define __Is_a_string(dsc) (dsc->type == STRING_ENUM)   ||\
                           (dsc->type == STRING_P_ENUM) ||\
                           (dsc->type == STRING_O_ENUM)

static int UnpackVar(__Unpack_desc_type *dsc, void **value_p, char *flags, size_t *size)
{
    void *varp = dsc->ptr;
    /* find data to copy*/
    switch(dsc->type){
        __ANY(__Unpack_case_t)
        __ANY(__Unpack_case_p)
    default:
        return 0; /* should never happen */
    }
    return 1;
}



void Remind(unsigned int offset, unsigned int count, void * p);

extern int CheckRetainBuffer(void);
extern void InitRetain(void);

void __init_debug(void)
{
    /* init local static vars */
#ifndef TARGET_ONLINE_DEBUG_DISABLE
    trace_buffer_cursor = trace_buffer;
    trace_list_addvar_cursor = trace_list;
    trace_list_collect_cursor = trace_list;
    trace_buffer_state = BUFFER_EMPTY;

    force_buffer_cursor = force_buffer;
    force_list_addvar_cursor = force_list;
    force_list_apply_cursor = force_list;
#endif

    InitRetain();
    /* Iterate over all variables to fill debug buffer */
    if(CheckRetainBuffer()){
        unsigned int retain_offset = 0;
        retain_list_collect_cursor = 0;

        /* iterate over retain list */
        while(retain_list_collect_cursor < retain_list_size){
            void *value_p = NULL;
            size_t size;
            char* next_cursor;

            dbgvardsc_t *dsc = &dbgvardsc[
                retain_list[retain_list_collect_cursor]];

            UnpackVar(dsc, &value_p, NULL, &size);

            /* if buffer not full */
            Remind(retain_offset, size, value_p);
            /* increment cursor according size*/
            retain_offset += size;

            retain_list_collect_cursor++;
        }
    }else{
        char mstr[] = "RETAIN memory invalid - defaults used";
        LogMessage(LOG_WARNING, mstr, sizeof(mstr));
    }
}

extern void InitiateDebugTransfer(void);
extern void CleanupRetain(void);

extern unsigned long __tick;

void __cleanup_debug(void)
{
#ifndef TARGET_ONLINE_DEBUG_DISABLE
    trace_buffer_cursor = trace_buffer;
    InitiateDebugTransfer();
#endif    

    CleanupRetain();
}

void __retrieve_debug(void)
{
}

void Retain(unsigned int offset, unsigned int count, void * p);

/* Return size of all retain variables */
unsigned int GetRetainSize(void)
{
    unsigned int retain_size = 0;
    retain_list_collect_cursor = 0;

    /* iterate over retain list */
    while(retain_list_collect_cursor < retain_list_size){
        void *value_p = NULL;
        size_t size;
        char* next_cursor;

        dbgvardsc_t *dsc = &dbgvardsc[
            retain_list[retain_list_collect_cursor]];

        UnpackVar(dsc, &value_p, NULL, &size);

        retain_size += size;
        retain_list_collect_cursor++;
    }

    return retain_size;
}


extern void PLC_GetTime(IEC_TIME*);
extern int TryEnterDebugSection(void);
extern long AtomicCompareExchange(long*, long, long);
extern long long AtomicCompareExchange64(long long* , long long , long long);
extern void LeaveDebugSection(void);
extern void ValidateRetainBuffer(void);
extern void InValidateRetainBuffer(void);

#define __ReForceOutput_case_p(TYPENAME)                                                            \
        case TYPENAME##_P_ENUM :                                                                    \
        case TYPENAME##_O_ENUM :                                                                    \
            {                                                                                       \
                char *next_cursor = force_buffer_cursor + sizeof(TYPENAME);                         \
                if(next_cursor <= force_buffer_end ){                                               \
                    /* outputs real value must be systematically forced */                          \
                    if(vartype == TYPENAME##_O_ENUM)                                                \
                        /* overwrite value pointed by backup */                                     \
                        *((TYPENAME *)force_list_apply_cursor->value_pointer_backup) =  \
                            *((TYPENAME *)force_buffer_cursor);                                     \
                    /* inc force_buffer cursor */                                                   \
                    force_buffer_cursor = next_cursor;                                              \
                }else{                                                                              \
                    stop = 1;                                                                       \
                }                                                                                   \
            }                                                                                       \
            break;
void __publish_debug(void)
{
    InValidateRetainBuffer();
    
#ifndef TARGET_ONLINE_DEBUG_DISABLE 
    /* Check there is no running debugger re-configuration */
    if(TryEnterDebugSection()){
        /* Lock buffer */
        long latest_state = AtomicCompareExchange(
            &trace_buffer_state,
            BUFFER_EMPTY,
            BUFFER_FULL);
            
        /* If buffer was free */
        if(latest_state == BUFFER_EMPTY)
        {
            int stop = 0;
            /* Reset force list cursor */
            force_list_apply_cursor = force_list;

            /* iterate over force list */
            while(!stop && force_list_apply_cursor < force_list_addvar_cursor){
                dbgvardsc_t *dsc = &dbgvardsc[
                    force_list_apply_cursor->dbgvardsc_index];
                void *varp = dsc->ptr;
                __IEC_types_enum vartype = dsc->type;
                switch(vartype){
                    __ANY(__ReForceOutput_case_p)
                default:
                    break;
                }
                force_list_apply_cursor++;
            }

            /* Reset buffer cursor */
            trace_buffer_cursor = trace_buffer;
            /* Reset trace list cursor */
            trace_list_collect_cursor = trace_list;

            /* iterate over trace list */
            while(trace_list_collect_cursor < trace_list_addvar_cursor){
                void *value_p = NULL;
                size_t size;
                char* next_cursor;

                dbgvardsc_t *dsc = &dbgvardsc[
                    trace_list_collect_cursor->dbgvardsc_index];

                UnpackVar(dsc, &value_p, NULL, &size);

                /* copy visible variable to buffer */;
                if(__Is_a_string(dsc)){
                    /* optimization for strings */
                    /* assume NULL terminated strings */
                    size = ((STRING*)value_p)->len + 1;
                }

                /* compute next cursor positon.*/
                next_cursor = trace_buffer_cursor + size;
                /* check for buffer overflow */
                if(next_cursor < trace_buffer_end)
                    /* copy data to the buffer */
                    memcpy(trace_buffer_cursor, value_p, size);
                else
                    /* stop looping in case of overflow */
                    break;
                /* increment cursor according size*/
                trace_buffer_cursor = next_cursor;
                trace_list_collect_cursor++;
            }
            
            /* Leave debug section,
             * Trigger asynchronous transmission 
             * (returns immediately) */
            InitiateDebugTransfer(); /* size */
        }
        LeaveDebugSection();
    }
#endif
    unsigned int retain_offset = 0;
    /* when not debugging, do only retain */
    retain_list_collect_cursor = 0;

    /* iterate over retain list */
    while(retain_list_collect_cursor < retain_list_size){
        void *value_p = NULL;
        size_t size;
        char* next_cursor;

        dbgvardsc_t *dsc = &dbgvardsc[
            retain_list[retain_list_collect_cursor]];

        UnpackVar(dsc, &value_p, NULL, &size);

        /* if buffer not full */
        Retain(retain_offset, size, value_p);
        /* increment cursor according size*/
        retain_offset += size;

        retain_list_collect_cursor++;
    }
    ValidateRetainBuffer();
}

#ifndef TARGET_ONLINE_DEBUG_DISABLE

#define TRACE_LIST_OVERFLOW    1
#define FORCE_LIST_OVERFLOW    2
#define FORCE_BUFFER_OVERFLOW  3

#define __ForceVariable_case_t(TYPENAME)                                                \
        case TYPENAME##_ENUM :                                                          \
            /* add to force_list*/                                                      \
            force_list_addvar_cursor->dbgvardsc_index = idx;                            \
            ((__IEC_##TYPENAME##_t *)varp)->flags |= __IEC_FORCE_FLAG;                  \
            ((__IEC_##TYPENAME##_t *)varp)->value = *((TYPENAME *)force);               \
            break;
#define __ForceVariable_case_p(TYPENAME)                                                \
        case TYPENAME##_P_ENUM :                                                        \
        case TYPENAME##_O_ENUM :                                                        \
            {                                                                           \
                char *next_cursor = force_buffer_cursor + sizeof(TYPENAME);             \
                if(next_cursor <= force_buffer_end ){                                   \
                    /* add to force_list*/                                              \
                    force_list_addvar_cursor->dbgvardsc_index = idx;                    \
                    /* save pointer to backup */                                        \
                    force_list_addvar_cursor->value_pointer_backup =                    \
                        ((__IEC_##TYPENAME##_p *)varp)->value;                          \
                    /* store forced value in force_buffer */                            \
                    *((TYPENAME *)force_buffer_cursor) = *((TYPENAME *)force);          \
                    /* replace pointer with pointer to force_buffer */                  \
                    ((__IEC_##TYPENAME##_p *)varp)->value =                             \
                        (TYPENAME *)force_buffer_cursor;                                \
                    (((__IEC_##TYPENAME##_p *)varp)->fvalue) = *((TYPENAME *)force);    \
                    /* mark variable as forced */                                       \
                    ((__IEC_##TYPENAME##_p *)varp)->flags |= __IEC_FORCE_FLAG;          \
                    /* inc force_buffer cursor */                                       \
                    force_buffer_cursor = next_cursor;                                  \
                    /* outputs real value must be systematically forced */              \
                    if(vartype == TYPENAME##_O_ENUM)                                    \
                        *(((__IEC_##TYPENAME##_p *)varp)->value) = *((TYPENAME *)force);\
                } else {                                                                \
                    error_code = FORCE_BUFFER_OVERFLOW;                                 \
                    goto error_cleanup;                                                 \
                }                                                                       \
            }                                                                           \
            break;


void ResetDebugVariables(void);

int RegisterDebugVariable(dbgvardsc_index_t idx, void* force)
{
    int error_code = 0;
    if(idx < sizeof(dbgvardsc)/sizeof(dbgvardsc_t)){
        /* add to trace_list, inc trace_list_addvar_cursor*/
        if(trace_list_addvar_cursor <= trace_list_end){
            trace_list_addvar_cursor->dbgvardsc_index = idx;
            trace_list_addvar_cursor++;
        } else {
            error_code = TRACE_LIST_OVERFLOW;
            goto error_cleanup;
        }
        if(force){
            if(force_list_addvar_cursor <= force_list_end){
                dbgvardsc_t *dsc = &dbgvardsc[idx];
                void *varp = dsc->ptr;
                __IEC_types_enum vartype = dsc->type;

                switch(vartype){
                    __ANY(__ForceVariable_case_t)
                    __ANY(__ForceVariable_case_p)
                default:
                    break;
                }
                /* inc force_list cursor */
                force_list_addvar_cursor++;
            } else {
                error_code = FORCE_LIST_OVERFLOW;
                goto error_cleanup;
            }
        }
    }
    return 0;

error_cleanup:
    ResetDebugVariables();
    trace_buffer_state = BUFFER_EMPTY;
    return error_code;
    
}

#define ResetForcedVariable_case_t(TYPENAME)                                            \
        case TYPENAME##_ENUM :                                                          \
            ((__IEC_##TYPENAME##_t *)varp)->flags &= ~__IEC_FORCE_FLAG;                 \
            /* for local variable we don't restore original value */                    \
            /* that can be added if needed, but it was like that since ever */          \
            break;

#define ResetForcedVariable_case_p(TYPENAME)                                            \
        case TYPENAME##_P_ENUM :                                                        \
        case TYPENAME##_O_ENUM :                                                        \
            ((__IEC_##TYPENAME##_p *)varp)->flags &= ~__IEC_FORCE_FLAG;                 \
            /* restore backup to pointer */                                             \
            ((__IEC_##TYPENAME##_p *)varp)->value =                                     \
                force_list_apply_cursor->value_pointer_backup;                          \
            break;

void ResetDebugVariables(void)
{
    /* Reset trace list */
    trace_list_addvar_cursor = trace_list;

    force_list_apply_cursor = force_list;
    /* Restore forced variables */
    while(force_list_apply_cursor < force_list_addvar_cursor){
        dbgvardsc_t *dsc = &dbgvardsc[
            force_list_apply_cursor->dbgvardsc_index];
        void *varp = dsc->ptr;
        switch(dsc->type){
            __ANY(ResetForcedVariable_case_t)
            __ANY(ResetForcedVariable_case_p)
        default:
            break;
        }
        /* inc force_list cursor */
        force_list_apply_cursor++;
    } /* else TODO: warn user about failure to force */ 

    /* Reset force list */
    force_list_addvar_cursor = force_list;
    /* Reset force buffer */
    force_buffer_cursor = force_buffer;
}

void FreeDebugData(void)
{
    /* atomically mark buffer as free */
    AtomicCompareExchange(
        &trace_buffer_state,
        BUFFER_FULL,
        BUFFER_EMPTY);
}
int WaitDebugData(unsigned long *tick);
/* Wait until debug data ready and return pointer to it */
int GetDebugData(unsigned long *tick, unsigned long *size, void **buffer){
    int wait_error = WaitDebugData(tick);
    if(!wait_error){
        *size = trace_buffer_cursor - trace_buffer;
        *buffer = trace_buffer;
    }
    return wait_error;
}
#endif
#endif

