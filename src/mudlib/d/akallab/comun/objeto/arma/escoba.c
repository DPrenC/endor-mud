inherit WEAPON;
#include <combat.h>
#include <properties.h>
#include <materials.h>

create() {
  ::create();
  SetStandard(WT_MAZA, 0, P_SIZE_MEDIUM, M_MADERA);
  SetAds(({"un","ligera"}));
  SetIds(({"arma","escoba"}));
  SetShort("una escoba");
  SetLong(
  "Es una vulgar escoba con mango de madera y de cepillo de estopa.\n");
  SetDamType(DT_BLUDGEON);
  Set(P_GENDER,GENDER_FEMALE);
  SetResetQuality(50);
}

init()
{
::init();
add_action("barrer_cmd","barrer");
}

int barrer_cmd()
{
write("Barres un poco el suelo con la escoba. Es una sensacion ... diferente.\n");
say(capitalize(TP->QueryName())+" barre un poco el "
      "suelo con una escoba.\n",TP);
return 1;
}
