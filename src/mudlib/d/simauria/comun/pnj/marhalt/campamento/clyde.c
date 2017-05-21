/* clyde.c
  El hermano peque�o de los Kutiri Bros.
  Aunque los dem�s le tratan a patadas, �l s� es un
  aut�ntico artista. Pero claro, su nombre le hace el
  blanco perfecto para el desprecio de los hermanos.
  Necesita un pincel.
  Los Hermanos Kutiri son questnpcs "peculiares": S�lo te dar�n el
  objeto que deseas (el l�tigo de Lady Morkobva) si les traes los
  objetos que te piden a todos y cada uno de ellos.
  [n] nemesis@simauria

  Creaci�n: 12-Dic-2001 15:54:51 CET
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
 say(W("Clyde coge el pincel y te dice: 'Con esto mi carrera en el mundo "
       "de la pintura ser� fulgurante. Me ir� ma�ana mismo.'\n"));
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
   return W("Le explicas a Clyde lo que te ha contado Kwailin y los hermanos Kutiri. "
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
 else return W("Clyde te mira fijamente y dice: '�Robar? �Yo? Si se trata de robos, "
               "preg�ntale a mi hermano Tinky.'\n");
}

// create
create() {
  ::create();
 SetStandard("Clyde", "kender", 100, GENERO_MASCULINO);
  SetLong(W("Es un kender vestido con un brillante traje naranja. En sus "
            "ojos maliciosos ves algo m�s, como si escondiesen algo.\n") );
  SetShort("El payaso Clyde");
  AddId(({"Clyde","clyde","el payaso Clyde","el payaso clyde",
          "payaso Clyde","payaso clyde",}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "Clyde suspira.\n",
   "Clyde murmura: 'Ojal� pudiera marcharme de aqu�...'\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"daga","daga de nikaia","daga de Nikaia","daga de Lattini",
                "daga de lattini"}),
  "Clyde te dice: 'Si se trata de robos, Tinky es tu hombre, a m� d�jame en paz.'\n",1);
  AddQuestion(({"l�tigo","robo","latigo","lentejuela","l�tigo de Lady Morkobva",
  "l�tigo de lady Morkobva","l�tigo de Lady morkobva","l�tigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),SF(answ_robo),1);
  AddQuestion(({"objeto","objeto especial"}),
  "Clyde te lleva aparte y te dice: 'Ver�s, me encantar�a largarme de aqu�, "
  "pero estos cuatro in�tiles se empe�an en que me dedique a hacer payasadas "
  "el resto de mi vida y a m� eso no me va. Yo soy un artista. Quiero ser "
  "pintor. Pero mis hermanos no lo tolerar�an. Si me traes algo para pintar, "
  "podr� largarme de aqu�.'\n",1);
// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a"}),
  "Clyde te dice: 'Es el �nico que me comprende y me trata como a un ser "
  "inteligente. Claro que intentar mantener una conversaci�n coherente "
  "con �l es... �c�mo decirlo? Digamos que pensar no es lo suyo.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Clyde te dice: 'Supongo que si los trat�ramos un poco mejor ellos tambi�n "
  "se portar�an mejor con nosotros...'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Clyde te dice: 'Es una buena chica. Es una l�stima que mis hermanos no "
  "la sepan apreciar.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  W("Clyde te dice: 'Hay que comprenderle. Los salvajes que tengo por hermanos "
    "casi matan a su hermana y todav�a pretenden que no le den ganas de acogotarnos "
    "cada vez que nos ve.'\n"),1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Clyde te dice: 'Algunas veces no puedo evitarlo y me divierto a su costa "
  "como los salvajes de mis hermanos. Pero es que es muy divertido. Siempre "
  "cae en nuestras bromas.'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Clyde te dice: 'Nikaia es la lanzadora de cuchillos y esposa de Lattini. "
  "Nunca la he visto re�r con tantas ganas como aquella vez que Pinky le "
  "hizo un arreglillo al bigote de su marido. Es una pena que no se r�a "
  "tan a menudo como debiera... Tiene una hermosa sonrisa.'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Clyde te dice: 'Fr�a como el hielo y muy dura. Mi hermano se col� en su "
  "carromato cuando se estaba cambiando de ropa, as� que ella le arre� un "
  "latigazo. Le estuvo bien empleado por mir�n.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Clyde te dice: 'No les hagas caso a mis hermanos. Digan lo que digan, son "
  "buenas bailarinas, aunque tengo que reconocer que Igart tiene un estilo "
  "de baile... particular.'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Clyde te dice: 'Lo hace lo mejor que puede, lo que pasa es que es chocante "
  "hasta que te acostumbras.'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Clyde te dice: 'Es buena bailando, aunque su caracter deja algo que desear...'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Clyde te dice: 'Desde que Mossi y ella est�n juntos, ha cambiado mucho. Eso "
  "s�, sigue sin fiarse un pelo de ninguno de nosotros.'\n",1);
  AddQuestion(({"Baskari","baskari"}),
  "Clyde te dice: 'Es un explotador. No sabes las ganas que tengo de marcharme "
  "y perderle de vista.'\n",1);
  AddQuestion(({"Madame Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),
  "Clyde te dice: 'No me f�o de esa bruja. Me da escalofr�os...'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Los hermanos Kutiri hacen una reverencia y Binky te dice: 'El mejor grupo de "
  "payasos de todo el reino de Simauria, para servirte.'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Clyde te dice: 'S�lo le interesa el dinero. Le da igual que Baskari nos "
  "explote, o que yo est� harto de esta absurda profesi�n.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Clyde te dice: 'Es la verg�enza de la familia. S�lo se lava cuando vamos a "
  "actuar, y porque Baskari le obliga.'\n",1);
  AddQuestion(({"pinky","Pinky"}),
 "Clyde te dice: 'Es un imb�cil. Se cree un genio porque ha inventado cosas "
 "como la silla con dos patas o el carro sin ruedas. Eso s�, Baskari ha "
 "encontrado un fil�n en esas chorradas. Qued�ndose un peque�o porcentaje, "
 "claro...'\n",1);
  AddQuestion(({"Tinky","tinky"}),
  W("Clyde te dice: 'Se cree m�sico, pero yo preferir�a definirlo como 'productor "
    "de ruidos chirriantes'. No le pidas que cante, por favor... Una vaca lo "
    "har�a con mejor voz...'\n"),1);
  AddQuestion(({"Clyde","clyde"}),
  "Clyde hace una reverencia y te dice: 'Clyde Kutiri a tu servicio.'\n",1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Binky dice: 'Muy bien, ya tenemos cada uno lo nuestro'. "
 "Acto seguido, te entrega un l�tigo con empu�adura de marfil negro.\n");

 // Texto que te da las dem�s veces que lo resuelvas
 SetAgainText("Clyde coge el pincel y lo esconde. Te dice: 'Gracias, con dos "
                "pinceles mi carrera ser� a�n m�s brillante.'\n");

 // SetQuest:
 // Quest: sangorquest; subquest: clyde;
 // Las tres �ltimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","clyde",({"pincel"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/latigo_morkobva");
}
