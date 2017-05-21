/* dinky.c
  El segundo mayor de los hermanos Kutiri. Es un guarro.
  Quiere un pu�ado de polvo del gremio de psi�nicos.
  Los Hermanos Kutiri son questnpcs "peculiares": S�lo te dar�n el
  objeto que deseas (el l�tigo de Lady Morkobva) si les traes los
  objetos que te piden a todos y cada uno de ellos.
  [n] nemesis@simauria

  Creaci�n: 08-Dic-2001 02:34:05 CET (Lo que yo te diga: 1 npc/h)
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
 say(W("Dinky recoge el pu�ado de polvo con mucho cuidado, lo huele, lo prueba y "
       "sus ojillos se iluminan. Exclama: '�Polvo del Gremio de Psi�nicos! �Eso "
       "s� que es un lugar especial! �Much�simas gracias!' "
       "Te tiende la mano, pero t� declinas su oferta.\n"));
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
   return W("Le explicas a Dinky lo que te ha contado Kwailin y los hermanos Kutiri. "
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
 else return "Dinky te mira fijamente y dice: 'No s� de qu� me est�s hablando.'\n";
}

// create
create() {
  ::create();
 SetStandard("Dinky", "kender", 100, GENERO_MASCULINO);
  SetLong(W("Es el kender m�s sucio que has visto en tu vida. Bajo una capa "
            "de mugre bastante importante puedes distinguir unos ojillos "
            "maliciosos que observan todos tus movimientos. Su traje rosa "
            "est� todo lleno de manchas bastante a�ejas ya...\n") );
  SetShort("El payaso Dinky");
  AddId(({"Dinky","dinky","el payaso Dinky","el payaso dinky",
          "payaso Dinky","payaso dinky",}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "�Dinky se tira un pedo!\n",
   "Dinky comienza a hurgarse la nariz.\n",
   "Dinky se suena la nariz con la manga de su traje.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"daga","daga de nikaia","daga de Nikaia","daga de Lattini",
                "daga de lattini"}),
  "Dinky te dice: 'Yo no s� nada de eso.'\n",1);
  AddQuestion(({"l�tigo","robo","latigo","lentejuela","l�tigo de Lady Morkobva",
  "l�tigo de lady Morkobva","l�tigo de Lady morkobva","l�tigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),SF(answ_robo),1);
  AddQuestion(({"objeto","objeto especial"}),
  "Dinky te dice: 'Me gustar�a tener suciedad de un lugar muy especial.'\n",1); // un pu�ado de polvo del gremio de psi�nicos
  AddQuestion(({"suciedad","suciedad de un lugar muy especial"}),
  W("Dinky te dice: 'Ver�s, colecciono suciedad de todas las partes del mundo, as� "
  "que siempre estoy buscando nuevas suciedades. Tendr�s que tra�rmela de un "
  "lugar muy especial.'\n"),1);
// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a"}),
  "Dinky te dice: 'Le tengo cari�o al bruto �se. Es el �nico que no insiste en "
  "que me lave todos los d�as. Y es lo que yo digo: Si un ba�o al a�o no hace "
  "da�o, �por qu� arriesgarse con m�s?'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Dinky te dice: 'No saben apreciar mis bromas. Como aquella vez que engras� "
  "la cuerda floja. Fue divertid�simo, pero a Mossi no pareci� gustarle. El "
  "se�or Baskari incluso nos oblig� a prometer que no volver�amos a hacerlo.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Dinky te dice: 'Desde el asunto de la cuerda floja no me puede ni ver. Yo "
  "no tengo la culpa de que fuera tan torpe y se cayera.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Dinky te dice: 'El muy abus�n intent� pegarme. Menos mal que Andr� y el "
  "se�or Baskari le detuvieron.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Dinky te dice: 'Jo, c�mo nos lo pasamos con �l... �Pica siempre!'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Dinky sonr�e y te dice: 'Se toma mejor las bromas que su marido, aunque "
  "al principio se enfada mucho.'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Dinky te dice: 'Le hizo da�o a mi hermano Binky. Desde entonces la odia.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Dinky te dice: 'No s� por qu� hacemos nosotros de payasos. Con Igart las "
  "carcajadas est�n aseguradas. Imag�nate, una kainoak bailando...'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Dinky te dice: 'Se enfada mucho con nosotros porque nos re�mos de ella. "
  "�Qu� culpa tenemos de que sea tan gracioso verla 'bailar'?'\n",1);
  AddQuestion(({"Morda","morda"}),
  W("Dinky te dice: 'Dice que es una elfa, pero yo creo que s�lo lo es a medias. "
  "Pero no se lo digas, tiene muy mal genio. Una vez me tir� encima todo un "
  "cubo de agua con jab�n. Tard� dos d�as en quitarme el olor a limpio. �Puag!'\n"),1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Dinky te dice: 'Desde que sale con Mossi es tab�. Si le hacemos algo, el "
  "bestia �se es capaz de cualquier cosa.'\n",1);
  AddQuestion(({"Baskari","baskari"}),
  "Dinky te dice: 'El se�or Baskari me cae bien. S�lo tiene un defecto: me "
  "obliga a lavarme cada vez que tengo que actuar. Suerte del carro averiado.'\n",1);
  AddQuestion(({"Madame Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),
  "Dinky te dice: 'Cada vez que me mira a los ojos me dan escalofr�os.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  W("Los hermanos Kutiri hacen una reverencia y Binky te dice: 'El mejor grupo de "
  "payasos de todo el reino de Simauria, para servirte.'\n"),1);
  AddQuestion(({"Binky","binky"}),
  "Dinky te dice: 'Mi hermano mayor, y el m�s listo de todos nosotros.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Dinky hace una reverencia y se le escapa un pedo. Dice: 'Ooops, perd�n.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "Dinky te dice: 'Es taaaan listo. Ha inventado un mont�n de aparatos, pero "
  "Baskari los confisca y los pone en lo que llama 'Museo de Cosas Imposibles'. "
  "Puedes ir a verlo. La entrada es barata.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
 "Dinky te dice: 'Es el genio musical de la familia. Compone la letra y la "
 "m�sica de las canciones que cantamos en nuestro espect�culo.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Dinky te dice: 'Clyde es nuestro hermano peque�o... Es un poco tonto, "
  "pero no puede evitarlo, naci� as�.'\n",1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Binky dice: 'Muy bien, ya tenemos cada uno lo nuestro'. "
 "Acto seguido, te entrega un l�tigo con empu�adura de marfil negro.\n");

 // Texto que te da las dem�s veces que lo resuelvas
 SetAgainText(
    "Dinky coge el polvo y dice: 'Gracias, pero de �ste ya tengo...'\n Acto "
    "seguido, lo tira al suelo.\n");

 // SetQuest:
 // Quest: sangorquest; subquest: dinky;
 // Las tres �ltimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","dinky",({"polvo_psi"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/latigo_morkobva");
}
