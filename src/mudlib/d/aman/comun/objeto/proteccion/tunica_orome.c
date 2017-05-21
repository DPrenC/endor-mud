/* Fichero: tunica_orome.c
Autor: Aul�
Fecha: 03/08/2014
Descripci�n: t�nica de orome.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_TUNICA, 2, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("la t�nica de hojas de Telperion");
SetLong(
"Esta es la t�nica con que gusta ataviarse Orom�, el vala se�or de los bosques.\n"
"Es un ropaje largo, amplio aunque m�s agustado al cuerpo que una t�nica normal.\n"
"Posee mangas largas hasta el codo y unas aberturas hasta la ingle, tanto por detr�s "
"como por delante, permiten moverse y cabalgar con libertad. El tejido es suave, fino "
"aunque acogedor y d�ctil como el mantillo de un bosque, teniendo el mismo color.\n"
"Formando diversas figuras, hay cosidas innumerables miniaturas de las hojas de "
"Telperion, el legendario �rbol de Plata de Valinor, realizadas en dicho material y "
"cinceladas con gran esmero. As� mismo,la tela se ve finamente bordada en el dobladillo, "
"el final de las mangas y el cuello con motivos vegetales. Su color la hace ideal para "
"camuflarse en lugares boscosos.\n");
SetIds(({"t�nica","ropa", "tunica", "ropaje", "vestidura","tunica_orome"}));
SetAds(({"de", "tela", "tejido", "hojas", "orome"}));
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Ser�a un sacrilegio tirar un objeto sagrado como este.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "la t�nica de Orom�.\n");
}