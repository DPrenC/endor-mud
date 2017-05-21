/*
DESCRIPCION : un muerto de cementerio
FICHERO     : /d/akallab/comun/pnj/monstruo/muerto.c
MODIFICACION: 27-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include <properties.h>
#include <living.h>
#include <attributes.h>
#include <combat.h>

#include "path.h"
#include AK_MACRO

inherit NPC;

mapping contador;

create() {
  ::create();
 SetName("zombie");
  SetShort("un muerto viviente");
  SetLong(
   "Es un muerto que se ha levantado de la tumba por obra de algun maléfico "
   "sortilegio. Su cuerpo esta medio podrido y puedes ver muchos de sus huesos. "
   "Es muy agresivo, sin duda dolido por no poder tener aun el descanso eterno.\n");

  SetLevel(10+random(10));
  SetIds(({"muerto","zombi","nomuerto"}));
  SetRace("nomuerto");
  SetGender(GENDER_MALE);
  SetSize(P_SIZE_MEDIUM);
  SetGoChance(0);
  SetAC(5);
  Set(P_HANDS,({ ({"su descarnada garra derecha",0,10}),
                 ({"su descarnada garra izquierda",0,10})
                 }) );
  SetAggressive (1);
  SetAlign(-900);
  InitChats (10, ({
    "El muerto viviente se dirige hacia ti.\n",
    "Ves como un trozo de carne putrefacta se desprende del cuerpo del muerto.\n"
    "El muerto viviente tambalea un momento pero se recupera.\n",
    "El muerto viviente emite sordos gruñidos: Mmmmmmmm.....Mmmmmmm......Mmmmmm....\n",
     }));


}
