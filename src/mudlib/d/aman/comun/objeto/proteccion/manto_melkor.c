/* Fichero: manto_melkor.c
Autor: aul�
Fecha: 02/09/2014
Descripci�n: manto de Morghot
*/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_MANTO, 1, P_SIZE_LARGE, M_ESPECIAL);
SetShort("el manto de oscuridad sempiterna");
SetLong(
"Este amplio manto, m�s que una prenda de tejido parece una gran sombra, un fragmento de "
"las tinieblas que reinan m�s all� de los Muros de la Noche. Sus m�ltiples pliegues "
"permiten extenderla haciendo m�s imponente y oscuro a quien la porta u ocult�ndolo de "
"la vista bajo su negrura.\n");
SetIds(({"manto", "capa", "manto_melkor", "ropa"}));
SetAds(({"de","oscuridad", "oscura", "negra"}));
Set(P_GENDER,GENDER_MALE);
Set(P_NUMBER,NUMBER_SINGULAR);
  SetValue(3000000);
  SetMagic(1);
 Set(P_NOSELL,"Cualquiera huir�a ante la sola posibilidad de que le vendieran este oscuro manto.\n");
}