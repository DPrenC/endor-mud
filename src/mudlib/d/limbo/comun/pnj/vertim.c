/*
DESCRIPCION  : Vertim, madre de Ibem la duenya de la tienda
FICHERO      : /d/limbo/comun/pnj/vertim.c
MODIFICACION : 15-09-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit NPC;

create() {
  ::create();
  SetStandard("Vertim","humano",10,GENDER_FEMALE);
  SetShort("Vertim, la madre de la tendera");
  SetLong("Vertim es la humana dueña de esta tienda. Es ya una anciana, por lo que es en\n"
          "realidad su hija Ibem quien atiende a los clientes. Suele descansar en la\n"
          "mecedora que hay en el porche de la tienda contemplando el mar y sintiendo su\n"
          "brisa en el rostro. Nunca falta un libro en su regazo para leer un rato.\n");

  SetGoChance(0);
  SetIds(({"dueña","duenya", "Vertim", "vertim", "vieja"}));
  SetAlign(50);
  Set(P_NOGET,"Vertim se revuelve y te pega con el grueso libro que estaba leyendo.\n");

InitChats(15,({
//--------------------------------------------------------------------------------
 "Vertim comienza a leer el libro que tiene en las manos.\n",
 "Ibem entra al almacen y sale al momento con cosas que colocar en las "
 "estanterias de la tienda.\n",
 "Vertim le dice a Ibem: '¡Ibem, sal un momento que tienes un cliente aqui!'\n"//
 "Ibem contesta: '¡Ya voy mamá! ¡Este almacen está hecho un desastre!'\n",
 "Vertim deja de leer un momento y contempla el mar.\n",
 "Ibem coloca unas pieles en una de las estanterias.\n",
 "Vertim se mece lentamente en la mecedora.\n",
 "Vertim le dice a Ibem: 'Hija, ¿te he contado lo que le paso al viejo Pulak?'\n"//
 "Ibem le contesta: 'Si mamá, ya me lo has contado'.\n",
 "Vertim te mira de arriba a abajo.\n",
 "Ibem te dice: '¿Tienes algo que vender? ¿o tal vez quieres comprar algo?'\n"}));
}