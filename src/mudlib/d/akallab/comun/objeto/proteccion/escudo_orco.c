/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 02-03-00                |
 |               Ultima Modificacion.. 02-02-00                |
 *=============================================================*/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>


inherit ARMOUR;

create() {
  ::create();
  SetStandard(AT_ESCUDO,3,P_SIZE_MEDIUM,M_ACERO);
  SetIds(({"escudo"}));
  AddAdjective("orco");
  AddAdjective("acero");
  AddAdjective("pesado");
  SetShort("un escudo orco");
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(
"Es un escudo usado por los orcos y que requiere de una cierta destreza\n\
para su uso por ello protege más a un orco que a otra raza.\n");
}

int QueryAC()
{
  object wearer;
  wearer=QueryEquipped();
  if((!wearer) || (wearer->QueryRace()=="orco"))
    return ::QueryAC()+1;
  if(member(({"troll","demonio","elfo-oscuro"}),wearer->QueryRace())!=-1)
    return ::QueryAC();
  return ::QueryAC()-1;
}
