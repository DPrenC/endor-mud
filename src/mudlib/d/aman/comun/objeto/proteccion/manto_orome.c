/* Fichero: manto_orome.c
Autor: aulë
Fecha: 02/09/2014
Descripción: manto de Oromë, el vala Cazador
*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_MANTO, 2, P_SIZE_LARGE, M_ESPECIAL);
SetShort("el manto de los grandes bosques estivales");
SetLong(
"Este amplio manto está fabricado con una ampulosa tela verde como el dosel de los "
"grandes bosques vírgenes y sus pliegues caen y se expanden envolviendo a su portador.\n"
"Está cubierta en su totalidad, a tramos regulares, por pequeñas incrustaciones de "
"plata en forma de hojas de haya bellamente cinceladas. El manto  proporciona a quien lo "
"lleve un aspecto de majestad y poder y ha sido vestido por Oromë desde edades atrás.\n");
SetIds(({"manto", "capa", "ropa","manto_orome"}));
SetAds(({"de","tela", "tejido", "orome" }));
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Sería un sacrilegio tirar un objeto sagrado como este.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "el manto de Oromë.\n");
  SetValue(3000000);
}