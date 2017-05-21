    /*   Bardo para la posada de Nandor     */
    /*         (c) Nemesis 1997             */
    /* Nemesis mismo le metio mano para que */
    /* fuera mas coherente. Concretamente,  */
    /* le bajo los HP.                      */

// Modificado:
// 06-Ene-02 [n] Retocado para que sea un questnpc y pueda poner su granito
//               de arena en el quest de Sangor. Tiene una guitarra que te
//               dar� si le traes un poco de whisky de veinte a�os...
//               Obviamente, es vilmente castellanizado de paso...

#include <properties.h>

inherit "std/questnpc";

create() {
  ::create();
SetName("Boyc");
 SetShort("Boyc, el bardo autodidacta.");
 SetLong(
 W("Boyc es bajo y tiene el pelo rubio. Lleva una camisa y pantalones el�sticos "
 "de brillantes colores. Rasguea una vieja guitarra con la que acompa�a las "
 "melod�as con las que ameniza las veladas de la posada.\n"));
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
  "Boyc toma un sorbo de vino.\n",
  "Boyc te gui�a un ojo.\n",
  "Boyc te sonr�e.\n",
  "Boyc toca una bella melod�a.\n",
  "Boyc comienza a cantar una de tus canciones favoritas.\n",
  "Boyc te dedica una canci�n.\n",
  "Boyc pregunta: '�Alguna petici�n?'\n",
  "Boyc dice: 'Gracias a todos por venir, me alegro de que est�is aqu�'.\n",
  "Boyc suspira: 'Lo que dar�a por un trago de buen whisky...'\n",
  "Boyc dice: 'Esta canci�n es antigua... Espero que os guste.'\n",
 "Boyc grita: '��Venga, todos juntos!!'\n"}));

// AddQuestions
AddQuestion(({"gremio de bardos"}),
 "Boyc dice: 'Creo que te equivocas. Yo no pertenezco a ese gremio... yo soy "
 "autodidacta'.\n");
AddQuestion(({"bardos"}),
 "Boyc dice: 'Los bardos tienen un gremio en el lugar de donde vengo. Son gente "
 "extra�a y a m� me gusta m�s cantar, as� que no me mezclo con ellos'.\n");
AddQuestion(({"guitarra"}),
W("Boyc sonr�e y te dice: '�Te gusta mi guitarra? Lo siento, pero no te la puedo dar. "
 "Me ha acompa�ado tantos a�os que ya no sabr�a qu� hacer sin ella.'\n"));
AddQuestion(({"whisky"}),
W("Boyc te dice: '�Tienes? No me malinterpretes, no soy ning�n borracho, pero "
 "hace mucho tiempo que no bebo whisky de verdad, como el que destilaba mi abuelo, "
 "whisky que dejaba reposar veinte a�os antes de beberlo. Aqu�l s� era buen licor, "
 "y no el aguachirle que sirven por aqu�...'"));

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Boyc dice: '�Hey, esto s� que parece whisky de verdad! A ver, d�jame probar...' "
 "Se bebe la botella de un s�lo trago y de repente se cae al suelo cuan largo es. "
 "Aprovechas ese momento para coger la guitarra. El posadero mira a Boyc y le "
 "grita: '�T�! �Toca algo movido!' Boyc se espabila r�pidamente, saca otra guitara "
 "de alg�n bolsillo y comienza a tocar una canci�n.\n");

 // Texto que te da las dem�s veces que lo resuelvas
 SetAgainText("Boyc coge la botella, te mira y dice: 'Gracias, pero creo que "
                "�sta me la guardar� para despu�s del show'.\n");

 // SetQuest:
 // Quest: sangorquest; subquest: boyc;
 // Las tres �ltimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","boyc",({"whisky_Boyc"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/whisky");

}
