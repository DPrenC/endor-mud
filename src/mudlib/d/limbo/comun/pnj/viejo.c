/*
DESCRIPCION  : Pulak, el viejo pescador en la fonda el 'Viejo Pescador'
FICHERO      : /d/limbo/comun/pnj/viejo.c
MODIFICACION : 15-09-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit NPC;

create() {
  ::create();
  SetStandard("Pulak","medio-elfo",10,GENDER_MALE);
  SetShort("Pulak, el viejo pescador");
  SetLong("Pulak es un viejo medio-elfo. Tras toda una vida dedicada a la pesca, ahora pasa\n"
          "las horas fumando en una larga pipa aquí en la fonda de su amigo Rodor. Su cara\n"
          "surcada de arrugas y sus manos ajadas son silenciosos testigos de una vida dura\n"
          "pero intensa en el mar. Sus ojos, de un azul intenso, parecen acostumbrados a\n"
          "mirar al horizonte.\n");

  SetIds(({"pescador", "Pulak", "pulak", "medio-elfo", "viejo"}));

  SetAlign(50);
  SetMaxHP(45);
  SetHP(45);

  Set(P_NOGET,"Pulak se revuelve y te pega con la pipa en la cabeza.\n");

InitChats(4,({
//--------------------------------------------------------------------------------
 "Pulak expulsa lentamente el oloroso humo de la pipa.\n",
 "Pulak te dice:' Te he contado ya como pesque un gigantesco tarpon en la Punta\n"
 "Sur de la isla. Fueron horas de lucha con aquel condenado pez. Recuerdo que...'\n",
 "Pulak fuma tranquilamente sentado en un rincon de la fonda.\n",
 "Pulak le dice a Rodor: '¡Parece que tienes más clientes!'\n",
 "Pulak comienza a caturrear una vieja canción de sobre un marinero y una sirena.\n",
 "Pulak rellena su pipa con más tabaco.\n"}));
}