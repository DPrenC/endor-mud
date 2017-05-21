/**
 * SIMAURIA 'sys/money.h'
 */

#ifndef __MONEY_H__
#define __MONEY_H__

#include <config.h>

/* file names */
#define MONEY             OBJECTPATH "money"

#define MONEY_LIB         "/lib/money"
#define MONEY_CONFIG      FINANCELOGPATH "money_config"

#define MONEY_ERRORLOG    FINANCELOGPATH "MONEYERROR"
#define MONEY_WATCHLOG    FINANCELOGPATH "WATCHLOG"

#define BANKLOG           FINANCELOGPATH "BANCO"
#define CASHFLOW_SAVEFILE FINANCELOGPATH "cashflow"
#define MONEY_OVERFLOW    FINANCELOGPATH "MONEY_OVERFLOW"


/* Bank related defines */
#define A_ACCOUNT_ID 0
#define A_CHARACTER  1
#define A_AMOUNT     2
#define A_CREATED    3
#define A_DEPOSIT    4
#define A_WITHDRAW   5
#define A_BANK       6
#define A_COUNT      7      // how many data are hold in the accounts-array


/* Información relativa a un banco */
#define BANK_ID      0 // el identificador
#define BANK_NAME    1 // el nombre del banco
#define BANK_PATH    2 // la ruta dle banco
#define BANK_CLOSE   3 // las horas a las que cierra

/* id of money */
#define MONEY_NAME "algo de dinero"
/*  example:  money=present(MONEY_NAME,this_player());  */

#define MONEY_VALUE 0
#define MONEY_SHORT    1
#define MONEY_LONG     2

/* Some errorcodes */

#define MONEY_NEGATIVE     0  /* Occurs if you want to pay a negative value */
#define MONEY_NO_MONEY     1  /* Occurs if the player has no money object */
#define MONEY_NOT_ENOUGH   2  /* Occurs if the total value of the player's
                               * money is too low */
#define MONEY_CANT_PAY     3  /* Occurs if the player hasn't the value in the
                               * asked currencies */
#define MONEY_WRONG_RESULT 4  /* An internal error occured. Inform the Office
                               * of Finance! */

/* Account order */
#define F_ORDER_AMOUNT     0
#define F_ORDER_NAME       1
#define F_ORDER_DATE       2


#endif