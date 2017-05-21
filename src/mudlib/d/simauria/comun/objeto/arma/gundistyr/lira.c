/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: lira.c                                                * */
/* *      AUTOR: [a] Artic                                               * */
/* *      MODIFICADO: 25/02/02 [a] Creación                              * */
/* *                                                                     * */
/* *********************************************************************** */

inherit WEAPON;
#include <combat.h>
#include <properties.h>

create() {
if (::create()) return 1;
SetStandard(WT_MAZA,2,P_SIZE_GENERIC,M_MADERA);
SetShort("una lira");
SetLong("Es una lira de color dorado. Parece ser de poca calidad.\n");
SetIds(({"lira","lira dorada"}));
SetWeight(400);
Set(P_GENDER,GENERO_FEMENINO);
Set(P_NUMBER,NUMERO_SINGULAR);
SetNumberHands(1);
}
