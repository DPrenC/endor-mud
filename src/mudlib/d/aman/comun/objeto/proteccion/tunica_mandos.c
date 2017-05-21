/* Fichero: tunica_mandos.c
Autor: Aulë
Fecha: 03/08/2014
Descripción: túnica de Mandos.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TUNICA, 1, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("una larga túnica gris");
SetLong(
"Es una larga túnica de un sencillo tejido gris, tenue y que da sensación de volatilidad "
"y movimiento. Esta liviana túnica cubre a su portador hasta los pies, y posee amplias mangas "
"que llegan hasta medio antebrazo. No tiene adorno ni signo alguno, aunque su sobriedad no "
"puede ocultar un tenue halo de poder.\n");
SetIds(({"túnica","ropa", "tunica", "tunica de mandos", "vestidura"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_SINGULAR);
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Sería un sacrilegio tirar un objeto sagrado como este.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "la túnica del juez de los Valar.\n");
}