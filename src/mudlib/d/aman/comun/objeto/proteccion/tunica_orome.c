/* Fichero: tunica_orome.c
Autor: Aulë
Fecha: 03/08/2014
Descripción: túnica de orome.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TUNICA, 2, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("la túnica de hojas de Telperion");
SetLong(
"Esta es la túnica con que gusta ataviarse Oromë, el vala señor de los bosques.\n"
"Es un ropaje largo, amplio aunque más agustado al cuerpo que una túnica normal.\n"
"Posee mangas largas hasta el codo y unas aberturas hasta la ingle, tanto por detrás "
"como por delante, permiten moverse y cabalgar con libertad. El tejido es suave, fino "
"aunque acogedor y dúctil como el mantillo de un bosque, teniendo el mismo color.\n"
"Formando diversas figuras, hay cosidas innumerables miniaturas de las hojas de "
"Telperion, el legendario Árbol de Plata de Valinor, realizadas en dicho material y "
"cinceladas con gran esmero. Así mismo,la tela se ve finamente bordada en el dobladillo, "
"el final de las mangas y el cuello con motivos vegetales. Su color la hace ideal para "
"camuflarse en lugares boscosos.\n");
SetIds(({"túnica","ropa", "tunica", "ropaje", "vestidura","tunica_orome"}));
SetAds(({"de", "tela", "tejido", "hojas", "orome"}));
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Sería un sacrilegio tirar un objeto sagrado como este.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "la túnica de Oromë.\n");
}