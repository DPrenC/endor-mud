/* Pocion curativa (regalo de Quest)
   Agosto 2001
   [Alura] Creaci�n
   [Nemesis] Cambiado de /std/food a /std/drink.
             Pal caso es lo mismo, pero ahora deja un bonito frasco :)

*/

inherit DRINK;
#include "path.h"
#include <health.h>
#include <properties.h>

int cura;

int curacion_total(){
 int vida;
 return (TP->QueryMaxHP()) - (TP->QueryHP());	
}


create()
{
  ::create();
  cura=curacion_total();
  SetShort("un frasco azul");
  SetLong(W("Es un frasco peque�o de cristal en cuyo interior se mueve un l�quido azulado "
        "apreciado por su gran capacidad curativa.\n"));
  SetSmell("Huele estupendamente.\n");
  SetIds(({"frasco", "frasco azul"}));
  SetWeight(200);
  Set_Drink_Name("poci�n curativa");
  Set_Vessel_Volume(30);
  Set_Vessel_Name("frasco azul");
  Set_Vessel_Gender(GENERO_MASCULINO);
  SetFoodAlc(0);
  SetFoodHeal(cura);
}
 