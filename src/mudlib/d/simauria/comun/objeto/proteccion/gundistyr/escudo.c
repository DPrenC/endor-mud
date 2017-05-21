/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: escudo.c                                            * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 28/01/02 [a] Creación                              * */
/* *                                                                     * */
/* *********************************************************************** */

#include <properties.h>
#include <combat.h>
#include <materials.h>
#include "path.h"

inherit ARMOUR;

create() {
  ::create();
  SetStandard(AT_ESCUDO,2,P_SIZE_SMALL,M_ACERO);
  SetIds(({"escudo","escudo de madera"}));
  SetShort("un escudo de madera");
  SetLong(W("Es un pequeño escudo de madera de forma redonda. No parece "
  "proteger mucho.\n"));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
}


