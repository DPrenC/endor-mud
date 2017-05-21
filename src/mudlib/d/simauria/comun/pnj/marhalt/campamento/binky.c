/* binky.c
  El mayor de los hermanos Kutiri. Malignamente listo.
  Quiere una piedra roja como las que crean los conjuratas.
  Los Hermanos Kutiri son questnpcs "peculiares": S�lo te dar�n el
  objeto que deseas (el l�tigo de Lady Morkobva) si les traes los
  objetos que te piden a todos y cada uno de ellos.
  [n] nemesis@simauria

  Creaci�n: 08-Dic-2001 01:14:41 CET (A este paso no acabar� nunca...)
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
 say(W("Binky coge la piedra y te dice: 'Muy bien, esto es exactamente lo que "
       "yo quer�a. Muchas gracias.\n"));
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
   return W("Le explicas a Binky lo que te ha contado Kwailin y los hermanos Kutiri. "
            "se echan a re�r. Binky te dice: 'Oh, as� que Kwailin me vi� en el lugar "
            "de los hechos... S�, fui yo. Lady Morkobva me golpe� con su l�tigo "
            "y me llam� sucio kender. As� que decid� vengarme con esta peque�a broma. "
            "Para que la venganza fuera completa, intent� enemistarla con las "
            "dos �nicas personas que le importan, esos gemelos Trassi. Pero veo que "
            "no lo consegu�, as� que de nada me sirve ya el l�tigo. Adem�s, mis hermanos "
            "y yo nos hemos peleado por �l varias veces. Creo que lo mejor ser� que "
            "te lo d�... pero antes tendr�s que traernos un objeto muy especial "
            "a cada uno...'\n");
  }
  else return W("Binky te dice: 'Ya te lo he explicado, yo rob� el l�tigo "
                "de Lady Morkobva. Estoy dispuesto a devolv�rtelo si nos traes "
                "a cada uno un objeto especial...'\n");
 }
 else return W("Binky te mira fijamente y dice: 'Te lo digo otra vez: no me gusta "
               "que nos acusen sin pruebas. Podemos ser peque�os, pero tenemos "
               "derechos, �sabes?'\n");
}

// create
create() {
  ::create();
 SetStandard("Binky", "kender", 100, GENERO_MASCULINO);
  SetLong( W("Es un kender de melena larga y ojillos maliciosos. Lleva el "
             "pelo recogido en una coleta y viste ropa de color rojo chill�n. "
             "Tiene una cicatriz en la frente que �l intenta disimular dejando "
             "que el flequillo crezca sobre ella.\n") );
  SetShort("El payaso Binky");
  AddId(({"Binky","binky","el payaso Binky","el payaso binky",
          "payaso Binky","payaso binky",}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "Binky juguetea con algo que lleva en la mano.\n",
   "Binky te mira fijamente. Instintivamente, te llevas las manos a la bolsa.\n",
   "Binky le dice algo a su hermano Dinky.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"daga","daga de nikaia","daga de Nikaia","daga de Lattini",
                "daga de lattini"}),
  "Binky te dice: 'Si Lattini ha perdido la daga de su mujer, que la busque. "
  "Nosotros ya estamos hartos de que nos culpen de cosas que no hemos hecho.'\n",1);
  AddQuestion(({"l�tigo","robo","latigo","lentejuela","l�tigo de Lady Morkobva",
  "l�tigo de lady Morkobva","l�tigo de Lady morkobva","l�tigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),SF(answ_robo),1);
  AddQuestion(({"objeto","objeto especial"}),
  "Binky te dice: 'Yo quiero un trozo de magia s�lida.'\n",1); // una piedra roja
  AddQuestion(({"magia s�lida","magia solida","trozo de magia s�lida",
                "trozo de magia solida"}),
  "Binky te dice: Pues eso... yo creo que est� clar�simo.\n",1);
  AddQuestion(({"cicatriz"}),
  W("La mirada de Binky se endurece y con una voz llena de odio dice: 'Esa maldita "
    "elfa oscura... Alguien deber�a darle una lecci�n...'\n"),1);
// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a"}),
  "Binky te dice: 'Es el �nico que nos comprende. Se r�e de nuestras bromas "
  "y algunas veces nos sirve de c�mplice. Es una pena que tantos combates de "
  "lucha libre le hayan dejado medio sonado.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Binky te dice: 'Son un par de aburridos. Mossi se enfad� mucho una vez porque "
  "seg�n �l casi matamos a su hermana. �Si estaba trabajando con red!'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Binky te dice: 'Es una ni�a malcriada que no sabe aguantar una broma. "
  "No me extra�a que su madre la abandonara. Puede dar gracias que no le "
  "hiciera nada peor.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Binky te dice: 'En lugar de equilibrista le pegar�a m�s hacer de mat�n. "
  "Nos ha amenazado varias veces de muerte. No sabe aguantar una broma.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Binky te dice: 'Lattini es como nuestro campo de pruebas. Si queremos hacer "
  "una broma nueva, primero lo probamos con �l. Si lo descubre a tiempo, es "
  "que no caer�a ni el m�s tonto de los trolls...'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Binky sonr�e y te dice: 'Solemos hacerle bromas tambi�n. Nos encanta ver "
  "la cara que pone cuando se enfada. Es taan divertida...'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Binky frunce el ce�o y te dice: 'Le debo a ella esta cicatriz. Alg�n d�a me las pagar�.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Binky te dice: 'No te f�es de ellas, son m�s malas que la ti�a. Eso s�, nos "
  "lo pasamos muy bien ri�ndonos de la patosa de Igart. Si es que ya lo dec�a "
  "mi padre: Si no sabes torear, pa qu� te metes...'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Binky te dice: 'No veas c�mo se pone cada vez que nos acercamos a ver los "
  "ensayos. Hay que reconocer que pone voluntad, pero lo que no puede ser no "
  "puede ser, y adem�s es imposible. Una kainoak bailando s�lo hace el "
  "rid�culo. Y nosotros queremos que se d� cuenta. La �ltima vez sali� detr�s "
  "de nosotros y acab� cayendo cuan larga es en un charco de barro. Fue muy "
  "gracioso.'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Binky te dice: 'Si quieres que se enfade de verdad, preg�ntale si su padre "
  "era del norte o del sur de Simauria. No veas c�mo se pone cuando alguien "
  "pone en duda que es elfa de pura cepa.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Binky te dice: 'Nos lo hemos pasado en grande haci�ndole rabiar, porque "
  "al final siempre se echaba a llorar. Estaba rid�cula con todo el maquillaje "
  "corrido por las l�grimas. Sin embargo, �ltimamente se ha liado con Mossi "
  "y no nos podemos ni acercar, porque el muy bruto no tiene sentido del "
  "humor y seguro que nos intentar�a pegar.'\n",1);
  AddQuestion(({"Baskari","baskari"}),
  "Binky te dice: 'Nos contrat� hace siete a�os y es el mejor negocio que ha "
  "hecho en toda su vida. Gracias a nosotros tiene m�s contratos de los que "
  "puede atender en todo un a�o.'\n",1);
  AddQuestion(({"Madame Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),
  "Binky te dice: 'Es una bruja. No me f�o de ella, y t� tampoco deber�as.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  W("Los hermanos Kutiri hacen una reverencia y Binky te dice: 'El mejor grupo de "
    "payasos de todo el reino de Simauria, para servirte.'\n"),1);
  AddQuestion(({"Binky","binky"}),
  "Binky hace una reverencia y dice: '�En qu� puedo ayudarte?'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  W("Binky te dice: 'Mi guarrete hermano, aqu� presente. Es buena persona, cuando "
    "te acostumbras al olor...'\n"),1);
  AddQuestion(({"Pinky","pinky"}),
  "Binky te dice: 'El genio de la familia. Inventor de cientos de aparatos, a "
  "cu�l m�s sorprendente. Visita el 'Museo de las Cosas Imposibles' si "
  "quieres admirar una peque�a muestra de su talento.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
 "Binky te dice: 'Un aut�ntico genio musical. Tiene los dedos r�pidos, as� que "
 "vigila tu bolsa cuando est�s con �l...'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Binky te dice: 'Clyde es nuestro hermano peque�o... Tendr�s que perdonar "
  "que no hable mucho, pero es que es un poco retrasado...'\n",1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Binky dice: 'Muy bien, ya tenemos cada uno lo nuestro'. "
 "Acto seguido, te entrega un l�tigo con empu�adura de marfil negro.\n");
 // Texto que te da las dem�s veces que lo resuelvas
 SetAgainText("Binky coge la piedra y dice: Gracias, aunque ya tengo una...\n");

 // SetQuest:
 // Quest: sangorquest; subquest: binky;
 // Las tres �ltimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","binky",({"piedra roja"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/latigo_morkobva");
}
