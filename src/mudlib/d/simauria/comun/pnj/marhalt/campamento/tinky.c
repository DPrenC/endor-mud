/* tinky.c
  La 'rama musical' de la familia Kutiri. Cantautor y creador de instrumentos.
  Necesita una lira.
  Los Hermanos Kutiri son questnpcs "peculiares": S�lo te dar�n el
  objeto que deseas (el l�tigo de Lady Morkobva) si les traes los
  objetos que te piden a todos y cada uno de ellos.
  [n] nemesis@simauria

  Creaci�n: 10-Dic-2001 01:40:14 CET
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit "std/questnpc";

// Sobrecargamos reward_player para que s�lo obtengamos lo que queremos
// si les entregamos los objetos a los cinco hermanos
void reward_player(object pl,object ob) {
 string *wq;

 // para evitar problemas en los member() m�s abajo
 wq = pl->QueryAttr("sangorquest")||({});
// Como el HelpMessage lo escupe s�lo al pasar por reward_player, habr�
// que hacer de alguna manera que el jugata sepa que ha conseguido traer
// el objeto adecuado... Se deja fuera porque mola m�s que lo diga siempre.
 say(W("Tinky coge la guitarra y exclama: 'Es justo lo que necesitaba para "
       "ambientar mi �ltima composici�n. �Muchas gracias!'\n"));
// No se entrega el l�tigo hasta que no haya resuelto los 5 subquests
 if ( (-1==member(wq,"binky")) ||
      (-1==member(wq,"dinky")) ||
      (-1==member(wq,"pinky")) ||
      (-1==member(wq,"tinky")) ||
      (-1==member(wq,"clyde"))
    ) return;
 else ::reward_player(pl,ob);
}

// Funciones para responder a las preguntas...
private string answ_robo() {
 if(TI->Query("asked_kwailin")) {
  if(!TI->Query("discovered_binky")) {
   TI->Set("discovered_binky",1);
   return W("Le explicas a Tinky lo que te ha contado Kwailin y los hermanos Kutiri. "
            "se echan a re�r. Binky te dice: 'Oh, as� que Kwailin me vi� en el lugar "
            "de los hechos... S�, fui yo. Lady Morkobva me golpe� con su l�tigo "
            "y me llam� sucio kender. As� que decid� vengarme con esta peque�a broma. "
            "Para que la venganza fuera completa, intent� enemistarla con las "
            "dos �nicas personas que le importan, esos gemelos Trassi. Pero veo que "
            "no lo consegu�, as� que de nada me sirve el l�tigo. Adem�s, mis hermanos "
            "y yo nos hemos peleado por �l varias veces. Creo que lo mejor ser� que "
            "te lo d�... pero antes tendr�s que traernos un objeto muy especial "
            "a cada uno...'\n");
  }
  else return W("Binky te dice: 'Ya te lo he explicado, yo rob� el l�tigo "
                "de Lady Morkobva. Estoy dispuesto a devolv�rtelo si nos traes "
                "a cada uno un objeto especial, as� que deja de molestar a "
                "mis hermanos con eso.'\n");
 }
 else return "Tinky te mira fijamente y dice: '�Robar? �Yo? �Bromeas!'\n";
}

// create
create() {
  ::create();
 SetStandard("Tinky", "kender", 100, GENERO_MASCULINO);
  SetLong(W("Es un kender vestido con un brillante traje verde. Tiene una "
            "larga melena desali�ada y unos ojos de mirada traviesa. "
            "Algo te dice que te debes mantener alejado de esos �giles "
            "dedos de m�sico...\n") );
  SetShort("El payaso Tinky");
  AddId(({"Tinky","tinky","el payaso Tinky","el payaso tinky",
          "payaso Tinky","payaso tinky",}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "Tinky saca un extra�o instrumento y comienza a aporrearlo. De �l salen\n"
   "unos horripilantes sonidos que �l acompa�a con espasm�dicos movimientos\n"
   "de cabeza.\n",
   "Tinky comienza a canturrear: 'Te machacar� con mi guitarra...'\n", // Es un poco macarrilla...
   "Tinky comienza a cantar una grotesca canci�n sobre un elefante.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"daga","daga de nikaia","daga de Nikaia","daga de Lattini",
                "daga de lattini"}),
  "Tinky te dice: '�Por qu� todo el mundo sospecha de m� cuando algo desaparece?'\n",1);
  AddQuestion(({"l�tigo","robo","latigo","lentejuela","l�tigo de Lady Morkobva",
  "l�tigo de lady Morkobva","l�tigo de Lady morkobva","l�tigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),SF(answ_robo),1);
  AddQuestion(({"objeto","objeto especial"}),
  W("Tinky te dice: '�Sabes? Eso mismo me pregunto yo: �Qu� puede querer un m�sico "
    "de mi talento?'\n"),1); // �C�mo puedo ser tan maligno...?
// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a"}),
  "Tinky te dice: 'Se porta bien con nosotros, pero no tiene demasiado buen "
  "o�do para la m�sica.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Tinky te dice: 'No s� qu� clase de arte es saltar de un lado a otro como "
  "los monos. El �nico artista de esta compa��a soy yo.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Tinky te dice: 'Es una chica mona, pero no tiene futuro como artista.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Tinky te dice: 'Es un salvaje. Intent� matar a mi hermano Dinky.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Tinky te dice: 'Me encanta robarle una lente que utiliza en uno de sus "
  "n�meros. Se vuelve como loco busc�ndola. Es m�s divertido...'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Tinky te dice: 'Nikaia es la lanzadora de cuchillos y esposa de Lattini. "
  "En general, no le gusta que le hagamos bromas a Lattini, aunque aquella "
  "vez que le arreglamos el bigote a su marido se ri� con ganas.'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Tinky te dice: 'Me cae mal. Maltrat� a mi hermano Binky.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Tinky te dice: 'La verdad es que no tienen demasiado talento para el baile, "
  "pero son perfectas para una canci�n guarra.'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Tinky te dice: 'Hemos pensado seriamente en pedirle que se una a nostros. "
  "Es un espect�culo desternillante verla bailar...'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Tinky te dice: 'No le gusta mi m�sica, no s� por qu�. Para m� que ha pasado "
  "mucho tiempo al sol.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Tinky te dice: '�ltimamente no tomo prestada ninguna de sus cosas... Tendr� "
  "que solucionar eso...'\n",1);
  AddQuestion(({"Baskari","baskari"}),
  "Tinky te dice: 'El jefe se empe�a en que no toque demasiado mis canciones. "
  "Tengo cientos de composiciones que nadie ha escuchado. �Quieres o�r alguna?'\n",1);
  AddQuestion(({"Madame Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),
  "Tinky te dice: 'Creo que me odia por alguna extra�a raz�n.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Los hermanos Kutiri hacen una reverencia y Binky te dice: 'El mejor grupo de\n"
  "payasos de todo el reino de Simauria, para servirte.'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Tinky te dice: 'Mi hermano mayor. Es el que nos consigui� este trabajo.'\n",1);
  AddQuestion(({"Tinky","tinky"}),
  "Tinky hace una reverencia y te dice: 'Tinky Kutiri, cantautor, a tu servicio.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Tinky te dice: 'Bajo toda esa mugre, late el coraz�n de un artista de las\n"
  "bromas. Nunca sabes por d�nde va a salir.'\n",1);
  AddQuestion(({"pinky","Pinky"}),
 "Tinky te dice: 'Pinky es un genio. Deber�as verle en acci�n. Sus inventos\n"
 "har�n que el apellido Kutiri sea conocido en todo el mundo, ya lo ver�s.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  W("Tinky te dice: 'Es la oveja negra de la familia. Nuestro apellido "
    "se arrastra por el fango desde que naci�, pero es nuestro hermano y tenemos "
    "que quererle.'\n"),1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Binky dice: 'Muy bien, ya tenemos cada uno lo nuestro'. "
 "Acto seguido, te entrega un l�tigo con empu�adura de marfil negro.\n");

 // Texto que te da las dem�s veces que lo resuelvas
 SetAgainText("Tinky mira la guitarra con atenci�n y te dice: 'Oye, gracias, "
                "as� ya podr� hacer un d�o'.\n");

 // SetQuest:
 // Quest: sangorquest; subquest: tinky;
 // Las tres �ltimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","tinky",({"guitarra_boyc"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/latigo_morkobva");
}
