        /*   Bardo para la posada de Nandor     */
        /*         (c) Nemesis 1997             */
	/* Nemesis mismo le metio mano para que */
	/* fuera mas coherente. Concretamente,  */
	/* le bajo los HP.                      */

// NOTA: No tocar esta versión, porque se va a ir en breve.
//       Si alguien quiere modificar algo la versión definitiva
//       está en el directorio pnj/campamento

#include <properties.h>
inherit NPC;
create() {
  ::create();
SetName("Boyc");
SetShort("Boyc, el bardo autodidacta.");
SetLong("Boyc es bajo y tiene el pelo rubio. Lleva una camisa y pantalones elasticos.\n");
SetRace("medio elfo");
AddId("bardo", "boyc");
SetLevel(10);
SetCon(3);
SetStr(4);
SetInt(5);
SetDex(7);
SetMaxHP(45);
SetHP(45);
Set(P_ALIGN,100);
Set(P_AC,0);
Set(P_NOGET,"Boyc se revuelve y te pega con su guitarra.\n");
SetGender(1);
InitChats(3,({"Boyc se aclara la garganta.\n",
 "Boyc toma un sorbo de agua.\n",
 "Boyc te guinya un ojo.\n",
 "Boyc te sonrie.\n",
 "Boyc toca una bella melodia.\n",
 "Boyc toca y canta una de tus canciones favoritas.\n",
 "Boyc te dedica una cancion.\n",
 "Boyc pregunta: Alguna peticion?\n",
 "Boyc dice: Gracias a todos por venir, me alegro de que esteis aqui.\n",
 "Boyc canta: Contrabando de sandias,\n"
 "            Y de naranjas podrias,...\n",
 "Boyc dice: Esta cancion es antigua... Espero que os guste.\n",
 "Boyc dice: Venga, todos juntos!!\n"}));

AddQuestion(({"gremio de bardos"}),
 "Boyc dice: Creo que te equivocas. Yo no pertenezco a ese gremio... yo soy\n"
 "autodidacta.\n");
AddQuestion(({"bardos"}),
 "Boyc dice: Los bardos tienen un gremio en el lugar de donde vengo. Son gente\n"
 "extranya y a mi me gusta mas cantar, asi que no me mezclo con ellos.\n");
}