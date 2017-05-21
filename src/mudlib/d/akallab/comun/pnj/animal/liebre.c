/*
DESCRIPCION  : una liebre
FICHERO      : /d/akallab/comun/pnj/animal/liebre.c
MODIFICACION : 29-10-98 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/

inherit NPC;

#include <properties.h>  //por el PSIZE
#include <living.h>      //por el GENDER

create() {
  ::create();
 SetStandard("liebre","liebre",3,GENDER_FEMALE);
  SetShort("una liebre parda");
  SetLong(
    "Una liebre parda ha detenido sus precisos saltos al cruzarse contigo. Puedes ver "
    "como mueve sus largas orejas atenta a cualquier imprevisto.\n");
  SetWeight(1500);
  SetIds(({"liebre"}));
  SetAds(({"parda","asustada"}));
  SetGoChance(75);
  SetDex(5);
  SetStr(2);
  SetCon(2);
  SetInt(1);
  SetAlign(0);
  SetHands(({({"un mordisco",0,10})}));
  InitChats(10,({
     "La liebre se esconde detras de unos matojos y te observa.\n",
     "La liebre comienza a dar saltos de un lado a otro asustada.\n",
     "La liebre estira sus orejas ante el sonido de tu respiracion.\n"     }));
  InitAChats(10,({
     "La liebre intenta escapar, aunque tu le pisas las orejas evitando su huida.\n",
     "La liebre emite gemidos de dolor.\n"     }));
}

public varargs void Die(mixed silent) {
  write(
    "La liebre empieza a sangrar por todos los orificios de su cuerpo, los "
    "naturales y los que le acabas de hacer.\n");
  say(
    "La liebre empieza a sangrar por todos los orificios de su cuerpo, los "
    "naturales y los que "+TP->QueryName()+" le ha hecho.\n",TP);
 ::Die(silent);
}
