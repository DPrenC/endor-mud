/* Fichero: botas_melkor.c
Autor: Aulë
Fecha: 03/08/2014
Descripción: botas de Melkor.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_BOTAS, 5, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("las botas férreas");
SetLong(

"Estas enormes botas están forjadas en el durísimo hierro negro de Angband y las "
"punteras macizas y la caña alta repujada con placas férreas les proporcionan gran peso "
"y resistencia.\n");
SetIds(({"botas","ropa", "calzado", "botas_melkor"}));
SetAds(({"de", "melkor", "altas", "morgoth", "del", "hierro"}));
  SetValue(3000000);
  SetMagic(1);
 Set(P_NOSELL, "Nadie en su sano juicio querría comprar un objeto tan funesto como estas botas.\n");
}