/* Fichero: manto_orome.c
Autor: aul�
Fecha: 02/09/2014
Descripci�n: manto de Orom�, el vala Cazador
*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_MANTO, 2, P_SIZE_LARGE, M_ESPECIAL);
SetShort("el manto de los grandes bosques estivales");
SetLong(
"Este amplio manto est� fabricado con una ampulosa tela verde como el dosel de los "
"grandes bosques v�rgenes y sus pliegues caen y se expanden envolviendo a su portador.\n"
"Est� cubierta en su totalidad, a tramos regulares, por peque�as incrustaciones de "
"plata en forma de hojas de haya bellamente cinceladas. El manto  proporciona a quien lo "
"lleve un aspecto de majestad y poder y ha sido vestido por Orom� desde edades atr�s.\n");
SetIds(({"manto", "capa", "ropa","manto_orome"}));
SetAds(({"de","tela", "tejido", "orome" }));
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Ser�a un sacrilegio tirar un objeto sagrado como este.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "el manto de Orom�.\n");
  SetValue(3000000);
}