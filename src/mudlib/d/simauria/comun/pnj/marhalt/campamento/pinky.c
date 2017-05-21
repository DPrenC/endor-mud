/* pinky.c
  La 'rama t�cnica' de la familia Kutiri. Inventor de objetos in�tiles.
  Necesita un engranaje para su �ltimo invento.
  Los Hermanos Kutiri son questnpcs "peculiares": S�lo te dar�n el
  objeto que deseas (el l�tigo de Lady Morkobva) si les traes los
  objetos que te piden a todos y cada uno de ellos.
  [n] nemesis@simauria

  Creaci�n: 09-Dic-2001 02:31:28 CET (oye, s�lo 30 minutos... creo que es un r�cord...)
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
 say(W("Pinky coge el peque�o engranaje, lo mira al trasluz y grita: "
       "'�Por fin! �La pieza esencial para mi m�quina!' Ahora s� que conseguir� "
       "la fama mundial.'\n"));
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
   return W("Le explicas a Pinky lo que te ha contado Kwailin y los hermanos Kutiri. "
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
 else return "Pinky te mira fijamente y dice: 'No s� de qu� me est�s hablando.'\n";
}

// create
create() {
  ::create();
 SetStandard("Pinky", "kender", 100, GENERO_MASCULINO);
  SetLong(W("Es un kender vestido con una especie de mono de color rosa. "
            "Lleva unos lentes que le hacen parecer 'intelectual'. Su "
            "mirada te pone igual de nervioso que las de sus hermanos.\n") );
  SetShort("El payaso Pinky");
  AddId(({"Pinky","pinky","el payaso Pinky","el payaso pinky",
          "payaso Pinky","payaso pinky",}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "Pinky saca un l�piz y un papel y comienza a escribir f�rmulas.\n",
   "Pinky se quita los lentes y los limpia con aire intelectual.\n",
   "Pinky saca unos tornillos del bolsillo y los examina cuidadosamente.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"daga","daga de nikaia","daga de Nikaia","daga de Lattini",
                "daga de lattini"}),
  "Pinky te dice: 'Yo no s� nada de eso.'\n",1);
  AddQuestion(({"l�tigo","robo","latigo","lentejuela","l�tigo de Lady Morkobva",
  "l�tigo de lady Morkobva","l�tigo de Lady morkobva","l�tigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),SF(answ_robo),1);
  AddQuestion(({"objeto","objeto especial"}),
  "Pinky te dice: 'Necesito una pieza para mi �ltimo invento.'\n",1); // un engranaje
  AddQuestion(({"pieza","pieza para invento"}),
  "Pinky te dice: 'Es un nombre demasiado t�cnico que s�lo un aut�ntico "
  "cient�fico como yo podr�a memorizar, no digamos pronunciar. T� simplemente "
  "tr�eme la pieza que necesito y no te preocupes de m�s. Yo har� el resto.'\n",1);
// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a"}),
  "Pinky te dice: 'Es un cabeza de chorlito incapaz de comprender una sola "
  "palabra de lo que hago, pero es muy �til para realizar trabajos pesados.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Pinky te dice: '�Equilibristas? Cualquier mono lo hace mejor que ellos. "
  "Realmente no s� para qu� los queremos. Son un par de aburridos.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Pinky te dice: 'La demostraci�n de que no tiene futuro como equilibrista. "
  "Mi hermano Dinky puso un poquito de grasa en su cuerda y ella �qu� hizo? "
  "�Aguant� el tipo como una profesional? No se�or, cay� a plomo contra la "
  "red que la esperaba abajo. Una aut�ntica equilibrista ni siquiera habr�a "
  "usado red. Si haces algo, que sea con todas las consecuencias, es lo que "
  "siempre dec�a mi madre. Pero parece que a Beni no la educaron bien.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Pinky te dice: 'Intent� pegar a mi hermano. Supongo que se enfad� porque "
  "pusimos en evidencia la poca profesionalidad de Beni.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Pinky te dice: 'El pobre es la v�ctima perfecta para nuestras bromas. "
  "�Pica siempre!'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Pinky sonr�e y te dice: 'Es mucho m�s simp�tica que su marido. C�mo se "
  "ri� cuando le hice aquel arreglo al bigote de Lattini.'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Pinky te dice: 'No debi� hacerle eso a mi hermano. �l se vengar�, ya lo ver�s.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Pinky te dice: 'El objeto principal de nuestras burlas. Dicen que somos "
  "crueles y nos odian, pero yo s� que en el fondo les gusta. Una mala "
  "cr�tica es un est�mulo para todo artista.'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Pinky te dice: 'Se enfada mucho con nosotros porque nos re�mos de ella. "
  "�Qu� culpa tenemos de que sea tan gracioso verla \"bailar\"?'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Pinky te dice: 'Es la peor de las tres. No sabe aguantar una broma. Una vez "
  "sabote� uno de mis inventos, que explot�. No fue nada gracioso.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Pinky te dice: 'Dicen que est� enamorada de Mossi. Eso confirma lo que yo "
  "siempre he dicho: Kwailin tiene muy mal gusto.'\n",1);
  AddQuestion(({"Baskari","baskari"}),
  "Pinky te dice: 'Gracias a �l mis inventos son conocidos en todo el mundo, "
  "pero se lleva un porcentaje de las ganancias. Un 90%, para ser exactos... "
  "�Maldito estafador!'\n",1);
  AddQuestion(({"Madame Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),
  "Pinky te dice: 'Es retorcida y mal�vola, se le ve en los ojos.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Los hermanos Kutiri hacen una reverencia y Binky te dice: 'El mejor grupo de "
  "payasos de todo el reino de Simauria, para servirte.'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Pinky te dice: 'Mi hermano mayor, es el m�s listo. Despu�s de m�, claro.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "Pinky hace una reverencia y te dice: 'Pinky Kutiri, inventor, para servirte.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Pinky te dice: 'Bajo toda esa mugre, late el coraz�n de un artista de las "
  "bromas. Nunca sabes por d�nde va a salir.'\n",1);
   AddQuestion(({"Tinky","Tinky"}),
   "Pinky te dice: 'Supongo que yo soy la rama \"cient�fica\" de la familia y �l "
   "la rama art�stica. Es un m�sico de primera, y tiene cierto talento para "
   "crear instrumentos, no te creas. En eso se parece mucho a m�.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Pinky te dice: 'Clyde es todo lo contrario a m�. Yo soy educado, elegante, "
  "inteligente... y Clyde es... bueno, es Clyde. Es un desastre, pero sigue "
  "siendo nuestro hermano y le queremos.'\n",1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Binky dice: 'Muy bien, ya tenemos cada uno lo nuestro'. "
 "Acto seguido, te entrega un l�tigo con empu�adura de marfil negro.\n");

 // Texto que te da las dem�s veces que lo resuelvas
 SetAgainText("Pinky mira el engranaje con atenci�n y te dice: 'Oye, gracias "
                "por traerme uno de repuesto.'\n");

 // SetQuest:
 // Quest: sangorquest; subquest: pinky;
 // Las tres �ltimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","pinky",({"engranaje"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/latigo_morkobva");
}
