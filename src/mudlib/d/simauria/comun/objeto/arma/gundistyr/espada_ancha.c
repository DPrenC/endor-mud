/* espada_ancha.c
Autor: [a] Articman
Descripción: Es un arma chupi-guay solo para trolls, para las demás
             razas es normalita
Modificado: 26-Ene-2002 [n] Creación
*/

inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include "path.h"

public varargs void NotifyEquip(object liv, object weapon, int flags)
{
  if (weapon != TO) return;
  if(liv->QueryRace()=="troll") {
    write("En cuanto empuñas la cimitarra te sientes muy cómodo con ella\n");
    weapon->SetWC(11);
  }
  ::NotifyEquip(liv, weapon, flags);
}


create() {
  ::create();
  if (!clonep()) return;

 SetStandard(WT_ESPADA,7,P_SIZE_LARGE,M_ACERO);
 SetShort("una espada ancha");
 SetLong(W("Es una larga y ancha espada. Tiene una empuñadura de tonos "
 "azules no muy trabajada y la hoja es bastante larga con lo que el arma "
 "tiene un tamaño considerable.\n"));
 SetIds(({"espada ancha","espada"}));
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_GENDER,GENERO_FEMENINO);
}
