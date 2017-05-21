/* Fichero: botas_melkor.c
Autor: Aul�
Fecha: 03/08/2014
Descripci�n: botas de Melkor.
*/

#include <properties.h>
#include <combat.h>
inherit ARMOUR;
create(){
::create();
SetStandard(AT_BOTAS, 5, P_SIZE_LARGE, M_ESPECIAL);
    SetShort("las botas f�rreas");
SetLong(

"Estas enormes botas est�n forjadas en el dur�simo hierro negro de Angband y las "
"punteras macizas y la ca�a alta repujada con placas f�rreas les proporcionan gran peso "
"y resistencia.\n");
SetIds(({"botas","ropa", "calzado", "botas_melkor"}));
SetAds(({"de", "melkor", "altas", "morgoth", "del", "hierro"}));
  SetValue(3000000);
  SetMagic(1);
 Set(P_NOSELL, "Nadie en su sano juicio querr�a comprar un objeto tan funesto como estas botas.\n");
}