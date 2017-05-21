/* binky.c
  El mayor de los hermanos Kutiri. Malignamente listo.
  Quiere una piedra roja como las que crean los conjuratas.
  Los Hermanos Kutiri son questnpcs "peculiares": Sólo te darán el
  objeto que deseas (el látigo de Lady Morkobva) si les traes los
  objetos que te piden a todos y cada uno de ellos.
  [n] nemesis@simauria

  Creación: 08-Dic-2001 01:14:41 CET (A este paso no acabaré nunca...)
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit "std/questnpc";

// Sobrecargamos reward_player para que sólo obtengamos lo que queremos
// si les entregamos los objetos a los cinco hermanos
void reward_player(object pl,object ob) {
 string *wq;

 // para evitar problemas en los member() más abajo
 wq = pl->QueryAttr("sangorquest")||({});
// Como el HelpMessage lo escupe sólo al pasar por reward_player, habrá
// que hacer de alguna manera que el jugata sepa que ha conseguido traer
// el objeto adecuado... Se deja fuera porque mola más que lo diga siempre.
 say(W("Binky coge la piedra y te dice: 'Muy bien, esto es exactamente lo que "
       "yo quería. Muchas gracias.\n"));
// No se entrega el látigo hasta que no haya resuelto los 5 subquests
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
            "se echan a reír. Binky te dice: 'Oh, así que Kwailin me vió en el lugar "
            "de los hechos... Sí, fui yo. Lady Morkobva me golpeó con su látigo "
            "y me llamó sucio kender. Así que decidí vengarme con esta pequeña broma. "
            "Para que la venganza fuera completa, intenté enemistarla con las "
            "dos únicas personas que le importan, esos gemelos Trassi. Pero veo que "
            "no lo conseguí, así que de nada me sirve ya el látigo. Además, mis hermanos "
            "y yo nos hemos peleado por él varias veces. Creo que lo mejor será que "
            "te lo dé... pero antes tendrás que traernos un objeto muy especial "
            "a cada uno...'\n");
  }
  else return W("Binky te dice: 'Ya te lo he explicado, yo robé el látigo "
                "de Lady Morkobva. Estoy dispuesto a devolvértelo si nos traes "
                "a cada uno un objeto especial...'\n");
 }
 else return W("Binky te mira fijamente y dice: 'Te lo digo otra vez: no me gusta "
               "que nos acusen sin pruebas. Podemos ser pequeños, pero tenemos "
               "derechos, ¿sabes?'\n");
}

// create
create() {
  ::create();
 SetStandard("Binky", "kender", 100, GENERO_MASCULINO);
  SetLong( W("Es un kender de melena larga y ojillos maliciosos. Lleva el "
             "pelo recogido en una coleta y viste ropa de color rojo chillón. "
             "Tiene una cicatriz en la frente que él intenta disimular dejando "
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
  AddQuestion(({"látigo","robo","latigo","lentejuela","látigo de Lady Morkobva",
  "látigo de lady Morkobva","látigo de Lady morkobva","látigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),SF(answ_robo),1);
  AddQuestion(({"objeto","objeto especial"}),
  "Binky te dice: 'Yo quiero un trozo de magia sólida.'\n",1); // una piedra roja
  AddQuestion(({"magia sólida","magia solida","trozo de magia sólida",
                "trozo de magia solida"}),
  "Binky te dice: Pues eso... yo creo que está clarísimo.\n",1);
  AddQuestion(({"cicatriz"}),
  W("La mirada de Binky se endurece y con una voz llena de odio dice: 'Esa maldita "
    "elfa oscura... Alguien debería darle una lección...'\n"),1);
// Info sobre los miembros de la compañía
  AddQuestion(({"André","Andre","andré","andre","forzudo",
                "forzudo de la compañía"}),
  "Binky te dice: 'Es el único que nos comprende. Se ríe de nuestras bromas "
  "y algunas veces nos sirve de cómplice. Es una pena que tantos combates de "
  "lucha libre le hayan dejado medio sonado.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Binky te dice: 'Son un par de aburridos. Mossi se enfadó mucho una vez porque "
  "según él casi matamos a su hermana. ¡Si estaba trabajando con red!'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Binky te dice: 'Es una niña malcriada que no sabe aguantar una broma. "
  "No me extraña que su madre la abandonara. Puede dar gracias que no le "
  "hiciera nada peor.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Binky te dice: 'En lugar de equilibrista le pegaría más hacer de matón. "
  "Nos ha amenazado varias veces de muerte. No sabe aguantar una broma.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Binky te dice: 'Lattini es como nuestro campo de pruebas. Si queremos hacer "
  "una broma nueva, primero lo probamos con él. Si lo descubre a tiempo, es "
  "que no caería ni el más tonto de los trolls...'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Binky sonríe y te dice: 'Solemos hacerle bromas también. Nos encanta ver "
  "la cara que pone cuando se enfada. Es taan divertida...'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Binky frunce el ceño y te dice: 'Le debo a ella esta cicatriz. Algún día me las pagará.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Binky te dice: 'No te fíes de ellas, son más malas que la tiña. Eso sí, nos "
  "lo pasamos muy bien riéndonos de la patosa de Igart. Si es que ya lo decía "
  "mi padre: Si no sabes torear, pa qué te metes...'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Binky te dice: 'No veas cómo se pone cada vez que nos acercamos a ver los "
  "ensayos. Hay que reconocer que pone voluntad, pero lo que no puede ser no "
  "puede ser, y además es imposible. Una kainoak bailando sólo hace el "
  "ridículo. Y nosotros queremos que se dé cuenta. La última vez salió detrás "
  "de nosotros y acabó cayendo cuan larga es en un charco de barro. Fue muy "
  "gracioso.'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Binky te dice: 'Si quieres que se enfade de verdad, pregúntale si su padre "
  "era del norte o del sur de Simauria. No veas cómo se pone cuando alguien "
  "pone en duda que es elfa de pura cepa.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Binky te dice: 'Nos lo hemos pasado en grande haciéndole rabiar, porque "
  "al final siempre se echaba a llorar. Estaba ridícula con todo el maquillaje "
  "corrido por las lágrimas. Sin embargo, últimamente se ha liado con Mossi "
  "y no nos podemos ni acercar, porque el muy bruto no tiene sentido del "
  "humor y seguro que nos intentaría pegar.'\n",1);
  AddQuestion(({"Baskari","baskari"}),
  "Binky te dice: 'Nos contrató hace siete años y es el mejor negocio que ha "
  "hecho en toda su vida. Gracias a nosotros tiene más contratos de los que "
  "puede atender en todo un año.'\n",1);
  AddQuestion(({"Madame Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),
  "Binky te dice: 'Es una bruja. No me fío de ella, y tú tampoco deberías.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  W("Los hermanos Kutiri hacen una reverencia y Binky te dice: 'El mejor grupo de "
    "payasos de todo el reino de Simauria, para servirte.'\n"),1);
  AddQuestion(({"Binky","binky"}),
  "Binky hace una reverencia y dice: '¿En qué puedo ayudarte?'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  W("Binky te dice: 'Mi guarrete hermano, aquí presente. Es buena persona, cuando "
    "te acostumbras al olor...'\n"),1);
  AddQuestion(({"Pinky","pinky"}),
  "Binky te dice: 'El genio de la familia. Inventor de cientos de aparatos, a "
  "cuál más sorprendente. Visita el 'Museo de las Cosas Imposibles' si "
  "quieres admirar una pequeña muestra de su talento.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
 "Binky te dice: 'Un auténtico genio musical. Tiene los dedos rápidos, así que "
 "vigila tu bolsa cuando estés con él...'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Binky te dice: 'Clyde es nuestro hermano pequeño... Tendrás que perdonar "
  "que no hable mucho, pero es que es un poco retrasado...'\n",1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Binky dice: 'Muy bien, ya tenemos cada uno lo nuestro'. "
 "Acto seguido, te entrega un látigo con empuñadura de marfil negro.\n");
 // Texto que te da las demás veces que lo resuelvas
 SetAgainText("Binky coge la piedra y dice: Gracias, aunque ya tengo una...\n");

 // SetQuest:
 // Quest: sangorquest; subquest: binky;
 // Las tres últimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","binky",({"piedra roja"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/latigo_morkobva");
}
