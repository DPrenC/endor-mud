/* tinky.c
  La 'rama musical' de la familia Kutiri. Cantautor y creador de instrumentos.
  Necesita una lira.
  Los Hermanos Kutiri son questnpcs "peculiares": Sólo te darán el
  objeto que deseas (el látigo de Lady Morkobva) si les traes los
  objetos que te piden a todos y cada uno de ellos.
  [n] nemesis@simauria

  Creación: 10-Dic-2001 01:40:14 CET
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
 say(W("Tinky coge la guitarra y exclama: 'Es justo lo que necesitaba para "
       "ambientar mi última composición. ¡Muchas gracias!'\n"));
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
   return W("Le explicas a Tinky lo que te ha contado Kwailin y los hermanos Kutiri. "
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
 else return "Tinky te mira fijamente y dice: '¿Robar? ¿Yo? ¡Bromeas!'\n";
}

// create
create() {
  ::create();
 SetStandard("Tinky", "kender", 100, GENERO_MASCULINO);
  SetLong(W("Es un kender vestido con un brillante traje verde. Tiene una "
            "larga melena desaliñada y unos ojos de mirada traviesa. "
            "Algo te dice que te debes mantener alejado de esos ágiles "
            "dedos de músico...\n") );
  SetShort("El payaso Tinky");
  AddId(({"Tinky","tinky","el payaso Tinky","el payaso tinky",
          "payaso Tinky","payaso tinky",}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "Tinky saca un extraño instrumento y comienza a aporrearlo. De él salen\n"
   "unos horripilantes sonidos que él acompaña con espasmódicos movimientos\n"
   "de cabeza.\n",
   "Tinky comienza a canturrear: 'Te machacaré con mi guitarra...'\n", // Es un poco macarrilla...
   "Tinky comienza a cantar una grotesca canción sobre un elefante.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"daga","daga de nikaia","daga de Nikaia","daga de Lattini",
                "daga de lattini"}),
  "Tinky te dice: '¿Por qué todo el mundo sospecha de mí cuando algo desaparece?'\n",1);
  AddQuestion(({"látigo","robo","latigo","lentejuela","látigo de Lady Morkobva",
  "látigo de lady Morkobva","látigo de Lady morkobva","látigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),SF(answ_robo),1);
  AddQuestion(({"objeto","objeto especial"}),
  W("Tinky te dice: '¿Sabes? Eso mismo me pregunto yo: ¿Qué puede querer un músico "
    "de mi talento?'\n"),1); // ¿Cómo puedo ser tan maligno...?
// Info sobre los miembros de la compañía
  AddQuestion(({"André","Andre","andré","andre","forzudo",
                "forzudo de la compañía"}),
  "Tinky te dice: 'Se porta bien con nosotros, pero no tiene demasiado buen "
  "oído para la música.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Tinky te dice: 'No sé qué clase de arte es saltar de un lado a otro como "
  "los monos. El único artista de esta compañía soy yo.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Tinky te dice: 'Es una chica mona, pero no tiene futuro como artista.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Tinky te dice: 'Es un salvaje. Intentó matar a mi hermano Dinky.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Tinky te dice: 'Me encanta robarle una lente que utiliza en uno de sus "
  "números. Se vuelve como loco buscándola. Es más divertido...'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Tinky te dice: 'Nikaia es la lanzadora de cuchillos y esposa de Lattini. "
  "En general, no le gusta que le hagamos bromas a Lattini, aunque aquella "
  "vez que le arreglamos el bigote a su marido se rió con ganas.'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Tinky te dice: 'Me cae mal. Maltrató a mi hermano Binky.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Tinky te dice: 'La verdad es que no tienen demasiado talento para el baile, "
  "pero son perfectas para una canción guarra.'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Tinky te dice: 'Hemos pensado seriamente en pedirle que se una a nostros. "
  "Es un espectáculo desternillante verla bailar...'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Tinky te dice: 'No le gusta mi música, no sé por qué. Para mí que ha pasado "
  "mucho tiempo al sol.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Tinky te dice: 'Últimamente no tomo prestada ninguna de sus cosas... Tendré "
  "que solucionar eso...'\n",1);
  AddQuestion(({"Baskari","baskari"}),
  "Tinky te dice: 'El jefe se empeña en que no toque demasiado mis canciones. "
  "Tengo cientos de composiciones que nadie ha escuchado. ¿Quieres oír alguna?'\n",1);
  AddQuestion(({"Madame Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),
  "Tinky te dice: 'Creo que me odia por alguna extraña razón.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Los hermanos Kutiri hacen una reverencia y Binky te dice: 'El mejor grupo de\n"
  "payasos de todo el reino de Simauria, para servirte.'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Tinky te dice: 'Mi hermano mayor. Es el que nos consiguió este trabajo.'\n",1);
  AddQuestion(({"Tinky","tinky"}),
  "Tinky hace una reverencia y te dice: 'Tinky Kutiri, cantautor, a tu servicio.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Tinky te dice: 'Bajo toda esa mugre, late el corazón de un artista de las\n"
  "bromas. Nunca sabes por dónde va a salir.'\n",1);
  AddQuestion(({"pinky","Pinky"}),
 "Tinky te dice: 'Pinky es un genio. Deberías verle en acción. Sus inventos\n"
 "harán que el apellido Kutiri sea conocido en todo el mundo, ya lo verás.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  W("Tinky te dice: 'Es la oveja negra de la familia. Nuestro apellido "
    "se arrastra por el fango desde que nació, pero es nuestro hermano y tenemos "
    "que quererle.'\n"),1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Binky dice: 'Muy bien, ya tenemos cada uno lo nuestro'. "
 "Acto seguido, te entrega un látigo con empuñadura de marfil negro.\n");

 // Texto que te da las demás veces que lo resuelvas
 SetAgainText("Tinky mira la guitarra con atención y te dice: 'Oye, gracias, "
                "así ya podré hacer un dúo'.\n");

 // SetQuest:
 // Quest: sangorquest; subquest: tinky;
 // Las tres últimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","tinky",({"guitarra_boyc"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/latigo_morkobva");
}
