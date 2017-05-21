/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: armadtroll.c                                          * */
/* *      AUTOR: [a] Articman                                            * */
/* *      MODIFICADO: 26/01/02 [a] Creación                              * */
/* *                                                                     * */
/* *********************************************************************** */

#include "../path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create() {
  ::create();
  SetStandard(AT_CORAZA,8,P_SIZE_HUGE,M_HIERRO);
  SetIds(({"coraza","coraza de hierro"}));
  SetShort("una coraza de hierro");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(W("Es una coraza hecha de hierro, aunque por el estado en el "
  "que se encuentra se diría que ha pasado bastantes batallas.\n"));
 }
