/* dinky.c
  El segundo mayor de los hermanos Kutiri. Es un guarro.
  Quiere un puñado de polvo del gremio de psiónicos.
  Los Hermanos Kutiri son questnpcs "peculiares": Sólo te darán el
  objeto que deseas (el látigo de Lady Morkobva) si les traes los
  objetos que te piden a todos y cada uno de ellos.
  [n] nemesis@simauria

  Creación: 08-Dic-2001 02:34:05 CET (Lo que yo te diga: 1 npc/h)
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
 say(W("Dinky recoge el puñado de polvo con mucho cuidado, lo huele, lo prueba y "
       "sus ojillos se iluminan. Exclama: '¡Polvo del Gremio de Psiónicos! ¡Eso "
       "sí que es un lugar especial! ¡Muchísimas gracias!' "
       "Te tiende la mano, pero tú declinas su oferta.\n"));
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
   return W("Le explicas a Dinky lo que te ha contado Kwailin y los hermanos Kutiri. "
            "se echan a reír. Binky te dice: 'Oh, así que Kwailin me vió en el lugar "
            "de los hechos... Sí, fui yo. Lady Morkobva me golpeó con su látigo "
            "y me llamó sucio kender. Así que decidí vengarme con esta pequeña broma. "
            "Para que la venganza fuera completa, intenté enemistarla con las "
            "dos únicas personas que le importan, esos gemelos Trassi. Pero veo que "
            "no lo conseguí, así que de nada me sirve el látigo. Además, mis hermanos "
            "y yo nos hemos peleado por él varias veces. Creo que lo mejor será que "
            "te lo dé... pero antes tendrás que traernos un objeto muy especial "
            "a cada uno...'\n");
  }
  else return W("Binky te dice: 'Ya te lo he explicado, yo robé el látigo "
                "de Lady Morkobva. Estoy dispuesto a devolvértelo si nos traes "
                "a cada uno un objeto especial, así que deja de molestar a "
                "mis hermanos con eso.'\n");
 }
 else return "Dinky te mira fijamente y dice: 'No sé de qué me estás hablando.'\n";
}

// create
create() {
  ::create();
 SetStandard("Dinky", "kender", 100, GENERO_MASCULINO);
  SetLong(W("Es el kender más sucio que has visto en tu vida. Bajo una capa "
            "de mugre bastante importante puedes distinguir unos ojillos "
            "maliciosos que observan todos tus movimientos. Su traje rosa "
            "está todo lleno de manchas bastante añejas ya...\n") );
  SetShort("El payaso Dinky");
  AddId(({"Dinky","dinky","el payaso Dinky","el payaso dinky",
          "payaso Dinky","payaso dinky",}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "¡Dinky se tira un pedo!\n",
   "Dinky comienza a hurgarse la nariz.\n",
   "Dinky se suena la nariz con la manga de su traje.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"daga","daga de nikaia","daga de Nikaia","daga de Lattini",
                "daga de lattini"}),
  "Dinky te dice: 'Yo no sé nada de eso.'\n",1);
  AddQuestion(({"látigo","robo","latigo","lentejuela","látigo de Lady Morkobva",
  "látigo de lady Morkobva","látigo de Lady morkobva","látigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),SF(answ_robo),1);
  AddQuestion(({"objeto","objeto especial"}),
  "Dinky te dice: 'Me gustaría tener suciedad de un lugar muy especial.'\n",1); // un puñado de polvo del gremio de psiónicos
  AddQuestion(({"suciedad","suciedad de un lugar muy especial"}),
  W("Dinky te dice: 'Verás, colecciono suciedad de todas las partes del mundo, así "
  "que siempre estoy buscando nuevas suciedades. Tendrás que traérmela de un "
  "lugar muy especial.'\n"),1);
// Info sobre los miembros de la compañía
  AddQuestion(({"André","Andre","andré","andre","forzudo",
                "forzudo de la compañía"}),
  "Dinky te dice: 'Le tengo cariño al bruto ése. Es el único que no insiste en "
  "que me lave todos los días. Y es lo que yo digo: Si un baño al año no hace "
  "daño, ¿por qué arriesgarse con más?'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Dinky te dice: 'No saben apreciar mis bromas. Como aquella vez que engrasé "
  "la cuerda floja. Fue divertidísimo, pero a Mossi no pareció gustarle. El "
  "señor Baskari incluso nos obligó a prometer que no volveríamos a hacerlo.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Dinky te dice: 'Desde el asunto de la cuerda floja no me puede ni ver. Yo "
  "no tengo la culpa de que fuera tan torpe y se cayera.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Dinky te dice: 'El muy abusón intentó pegarme. Menos mal que André y el "
  "señor Baskari le detuvieron.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Dinky te dice: 'Jo, cómo nos lo pasamos con él... ¡Pica siempre!'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Dinky sonríe y te dice: 'Se toma mejor las bromas que su marido, aunque "
  "al principio se enfada mucho.'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Dinky te dice: 'Le hizo daño a mi hermano Binky. Desde entonces la odia.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Dinky te dice: 'No sé por qué hacemos nosotros de payasos. Con Igart las "
  "carcajadas están aseguradas. Imagínate, una kainoak bailando...'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Dinky te dice: 'Se enfada mucho con nosotros porque nos reímos de ella. "
  "¿Qué culpa tenemos de que sea tan gracioso verla 'bailar'?'\n",1);
  AddQuestion(({"Morda","morda"}),
  W("Dinky te dice: 'Dice que es una elfa, pero yo creo que sólo lo es a medias. "
  "Pero no se lo digas, tiene muy mal genio. Una vez me tiró encima todo un "
  "cubo de agua con jabón. Tardé dos días en quitarme el olor a limpio. ¡Puag!'\n"),1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Dinky te dice: 'Desde que sale con Mossi es tabú. Si le hacemos algo, el "
  "bestia ése es capaz de cualquier cosa.'\n",1);
  AddQuestion(({"Baskari","baskari"}),
  "Dinky te dice: 'El señor Baskari me cae bien. Sólo tiene un defecto: me "
  "obliga a lavarme cada vez que tengo que actuar. Suerte del carro averiado.'\n",1);
  AddQuestion(({"Madame Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),
  "Dinky te dice: 'Cada vez que me mira a los ojos me dan escalofríos.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  W("Los hermanos Kutiri hacen una reverencia y Binky te dice: 'El mejor grupo de "
  "payasos de todo el reino de Simauria, para servirte.'\n"),1);
  AddQuestion(({"Binky","binky"}),
  "Dinky te dice: 'Mi hermano mayor, y el más listo de todos nosotros.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Dinky hace una reverencia y se le escapa un pedo. Dice: 'Ooops, perdón.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "Dinky te dice: 'Es taaaan listo. Ha inventado un montón de aparatos, pero "
  "Baskari los confisca y los pone en lo que llama 'Museo de Cosas Imposibles'. "
  "Puedes ir a verlo. La entrada es barata.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
 "Dinky te dice: 'Es el genio musical de la familia. Compone la letra y la "
 "música de las canciones que cantamos en nuestro espectáculo.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Dinky te dice: 'Clyde es nuestro hermano pequeño... Es un poco tonto, "
  "pero no puede evitarlo, nació así.'\n",1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Binky dice: 'Muy bien, ya tenemos cada uno lo nuestro'. "
 "Acto seguido, te entrega un látigo con empuñadura de marfil negro.\n");

 // Texto que te da las demás veces que lo resuelvas
 SetAgainText(
    "Dinky coge el polvo y dice: 'Gracias, pero de éste ya tengo...'\n Acto "
    "seguido, lo tira al suelo.\n");

 // SetQuest:
 // Quest: sangorquest; subquest: dinky;
 // Las tres últimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","dinky",({"polvo_psi"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/latigo_morkobva");
}
