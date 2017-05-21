/*
  florete.c
  (c) Nemesis@Simauria

  El arma de esgrima por excelencia: el florete.
*/

#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_ESGRIMA, 5, P_SIZE_GENERIC, M_ACERO);
   SetShort("un lujoso florete");
   SetLong("Es un florete de hoja larga y punta afilada. La hoja brilla con un reflejo\n"
           "azulado y la guarda está guarnecida de piedras preciosas.\n");
   AddId(({"florete","lujoso florete"}));
   SetNumberHands(1);
   Set(P_GENDER,GENERO_MASCULINO);
   SetValue(QueryValue()*3);
   SetResetQuality(95);
   SetQuality(95);
}
