/* Fichero: cinturon_orome.c
Autor: Aul�
Fecha: 03/08/2014
Descripci�n: cintur�n para Orom�.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_CINTURON, 3, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("el cintur�n de enrredaderas bendecidas");
SetLong(
"Este cintur�n ha sido confeccionado por Yavanna para su amigo y aliado Orom�.\n"
"Est� constitu�do por varios flexibles tallos vegetales entretejidos en complicados "
"nudos, de manera que no se sabe donde finaliza uno y empieza el otro. Los colores de sus "
"tallos son del m�s fresco y puro verde. Lasdiminutas hojas que los recubren son de "
"distintos tonos del verde, el plateado y el dorado. Una leve luminosidad parece "
"emanar de todo el conjunto. La bendici�n de Yavanna que pesa sobre �ste objeto le "
"permite a Orom� moverse en lo m�s tupido de un bosque a gran velocidad, pues las "
"plantas y dem�s vegetales reconocen el poder de Yavanna y lo aceptan como parte de s�, "
"apart�ndose ante �l y cerr�ndose a su paso.\n");
SetIds(({"cintur�n","ropa", "cinturon", "vestidura","cinturon_orome"}));
SetAds(({"de", "orome", "verde", "tallos", "hojas", "enredaderas"}));
  SetValue(3000000);
  SetMagic(1);
 SetNoDrop("Ser�a un sacrilegio tirar un objeto sagrado como este.\n");
 Set(P_NOSELL,"No hay en toda Arda riquezas suficientes que puedan intercambiarse por "
 "�ste cintur�n.\n");
}