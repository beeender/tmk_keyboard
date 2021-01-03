#ifndef _H_MYNEWT_CFG_
#define _H_MYNEWT_CFG_

#include "syscfg/syscfg.h"

#ifndef MATRIX_ROWS
#define MATRIX_ROWS (MYNEWT_VAL(TMK_MATRIX_ROWS))
#endif

#ifndef MATRIX_COLS
#define MATRIX_COLS (MYNEWT_VAL(TMK_MATRIX_COLS))
#endif

#endif
