/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: escudotroll.c                                         * */
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
  SetStandard(AT_ESCUDO,4,P_SIZE_HUGE,M_ACERO);
  SetIds(({"escudo","escudo de hierro"}));
  SetShort("un escudo de hierro");
  SetLong(W("Es un escudo de hierro. Tiene un tamaño medio y forma "
  "rectangular.\n"));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
}


