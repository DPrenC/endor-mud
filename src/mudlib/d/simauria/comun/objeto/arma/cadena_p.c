/*
DESCRIPCION  : Cadena. Es la version pequeña de la cadena del Limbo
FICHERO      : cadena_p.c [Bomber]
*/

inherit WEAPON;
#include <combat.h>
#include <properties.h>

create() {
  ::create();
  SetStandard(WT_ESPADA,2,P_SIZE_SMALL,M_HIERRO);
  SetAds(({"una","larga"}));
  SetIds(({"arma","cadena"}));
  SetShort("una cadena");
  SetLong("Es una cadena corriente de metal que puede ser usada como arma.\n");
  SetWeight(QueryWeight()*2);//Doblo peso
  SetValue(QueryValue()*4);//Cuadruplico valor
  Set(P_GENDER, GENDER_FEMALE);
  SetResetQuality(85);
  SetNumberHands(1);
}
