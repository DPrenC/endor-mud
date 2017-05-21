/*
DESCRIPCION : una urraca para el quest del amuleto perdido
FICHERO     : /d/akallab/comun/quest/amuleto/urraca.c
MODIFICACION: 27-10-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

inherit NPC;
#include <living.h>
#include <combat.h>
#include "path.h"
#include AK_MACRO

int desaparece();

create() {
  ::create();
 SetName("urraca");
  SetShort("una urraca negra con algo en el pico");
  SetLong(
  "Es una esquiva urraca negra que lleva algo cogido en el pico. No puedes "
    "ver bien lo que es, pero parece un colgante o un amuleto. La urraca no "
	"para de moverse de un sitio a otro.\n");
  SetRace("urraca");
  SetGender(GENDER_FEMALE);
  SetWeight(1500);
  SetGoChance(40);
  SetIds(({"urraca","urraca negra","pajaro"}));
  SetAds(({"negra"}));
  SetLevel(1);
  SetHands(({({"una pata",0,1}),
             ({"pico",0,6})}));

}

private void MePiro()
{
  write("La urraca escapa volando hacia las montanyas que hay al norte del "
          "bosque con el amuleto.\n");
  say("Cuando "+TP->QueryName()+" ataca a la urraca, ésta escapa "
        "volando.\n",TP);
  TO->remove();
}

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras)
{
  if (!xtras) xtras = ({});
  xtras += ({ ({0,0,0,SF(MePiro)}) });
  return ::DoDamage(damage, type, 1, &xtras);
}
