/* Fichero: cinturon_orome.c
Autor: Aulë
Fecha: 03/08/2014
Descripción: cinturón para Oromë.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_CINTURON, 3, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("el cinturón de enrredaderas bendecidas");
SetLong(
"Este cinturón ha sido confeccionado por Yavanna para su amigo y aliado Oromë.\n"
"Está constituído por varios flexibles tallos vegetales entretejidos en complicados "
"nudos, de manera que no se sabe donde finaliza uno y empieza el otro. Los colores de sus "
"tallos son del más fresco y puro verde. Lasdiminutas hojas que los recubren son de "
"distintos tonos del verde, el plateado y el dorado. Una leve luminosidad parece "
"emanar de todo el conjunto. La bendición de Yavanna que pesa sobre éste objeto le "
"permite a Oromë moverse en lo más tupido de un bosque a gran velocidad, pues las "
"plantas y demás vegetales reconocen el poder de Yavanna y lo aceptan como parte de sí, "
"apartándose ante él y cerrándose a su paso.\n");
SetIds(({"cinturón","ropa", "cinturon", "vestidura","cinturon_orome"}));
SetAds(({"de", "orome", "verde", "tallos", "hojas", "enredaderas"}));
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Sería un sacrilegio tirar un objeto sagrado como este.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "éste cinturón.\n");
}