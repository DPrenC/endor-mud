/* Fichero: tunica_mandos.c
Autor: Aul�
Fecha: 03/08/2014
Descripci�n: t�nica de Mandos.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TUNICA, 1, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("una larga t�nica gris");
SetLong(
"Es una larga t�nica de un sencillo tejido gris, tenue y que da sensaci�n de volatilidad "
"y movimiento. Esta liviana t�nica cubre a su portador hasta los pies, y posee amplias mangas "
"que llegan hasta medio antebrazo. No tiene adorno ni signo alguno, aunque su sobriedad no "
"puede ocultar un tenue halo de poder.\n");
SetIds(({"t�nica","ropa", "tunica", "tunica de mandos", "vestidura"}));
Set(P_GENDER,GENDER_FEMALE);
Set(P_NUMBER,NUMBER_SINGULAR);
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Ser�a un sacrilegio tirar un objeto sagrado como este.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "la t�nica del juez de los Valar.\n");
}