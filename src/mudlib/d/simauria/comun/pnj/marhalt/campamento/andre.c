/* andre.c
  El forzudo de la compañía de titiriteros.
  Necesita una vieja espada que tiene Lady Morkobva.
  A cambio te dará una cosa que Sangor quiere mucho.
  [n] nemesis@simauria

  Creación: 02-Dic-2001 20:17:29 CET
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit "std/questnpc";

create() {
  ::create();
 SetStandard("André", "gigante", 100, GENERO_MASCULINO);
  SetShort("André, el forzudo de la compañía");
  SetLong("Es una auténtica mole de músculos. Mide casi 3 metros de alto y "
          "casi lo mismo de ancho. En su rostro distingues ciertos rasgos "
          "orcos, aunque nunca habías visto un orco tan grande.\n");
  AddId(({"André","Andre","andré","andre","forzudo"}));
  SetSize(P_SIZE_MEDIUM); // Ojo: es normal, porque es grande, pero no tanto...
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "André dice: 'Ojalá alguien me ayudara.'\n",
   "André dice: '¿Por qué jugaría con ese tahúr de Lattini?'\n",
   "André dice: 'No sé para qué me jugué nada. Incluso borracho me ganó...'\n",
   "André dice: '¿Cómo pude ser tan imbécil?'\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"espada","tu espada"}),
  W("André te dice: 'Es una espada que había estado en mi familia durante más de "
    "500 años. Mi padre me contó que uno de mis antepasados mató a un gran rey "
    "de Simauria con ella, claro que yo nunca me lo creí. Pero lo cierto es que "
    "es lo único que mi querido padre me dejó al morir, y aunque no sepa usarla, "
    "es un honor que me diera algo que tenía en tanta estima. Y ahora yo lo he "
    "perdido en una partida de cartas... Si mi padre me viera se moriría de "
    "vergüenza... Claro que ya está muerto...'\n"),1);
  AddQuestion(({"padre","tu padre"}),
  W("André te dice: 'Fue un gran guerrero de Akallab. Cuando se firmó la tregua "
    "con Simauria recorrió el mundo como mercenario. Nunca fue vencido en "
    "ninguna batalla.'\n"),1);
// Ésta llevará "premio"...
  AddQuestion(({"madre","tu madre"}),
  W("André te dice: '¿Qué tienes que decir de mi madre? ¡Fue una santa, son "
    "rumores infundados!'\n"),1);
  AddQuestion(({"cartas","partida"}),
  W("André te dice: 'Vi a Lattini tan borracho que pensé que podría ganarle unas "
    "monedas. No conté con que es el mayor tramposo de este lado del mundo. Me "
    "ganó casi todo lo que tenía. Jugamos a las 8 y media. En la última mano, "
    "por fin me sale un 8. El muy tramposo se jugó todo lo que tenía y yo piqué "
    "como un tonto. Me jugué mis últimas monedas y mi espada. Yo paso y él coge "
    "dos cartas. Me planto y le enseño triunfal mi ocho. Él sonríe, me mira con "
    "los ojos enrojecidos por el alcohol y me enseña sus cartas: 5, 2 y tres "
    "figuras. 8 y medio en total. Acto seguido recogió sus ganancias, me deseó "
    "buenas noches, y se alejó tambaleándose hacia su carreta, mientras yo me "
    "quedaba allí con cara de tonto.'\n"),1);
  AddQuestion(({"ocho y media","8 y media"}),
  W("André suspira y te dice: 'Ay, las ocho y media es un juego... Y un juego "
    "vil, que no hay que jugarlo a ciegas, pues juegas cien veces, mil, y de "
    "las mil ves febril que o te pasas o no llegas. Y el no llegar da dolor "
    "pues implica que mal tasas y eres del otro deudor. Mas, ay de ti si te "
    "pasas... si te pasas es peor...'\n"),1); // Lo siento, tenía que hacerlo ;)
// Info sobre los miembros de la compañía
  AddQuestion(({"André","Andre","andré","andre","forzudo",
                "forzudo de la compañía"}),
  "André te dice: 'Ése soy yo, ¿querías algo de mí?'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  W("André te dice: 'Son gemelos. Chico y chica. Su madre les abandonó siendo muy "
    "pequeños y se ganaron la vida como artistas ambulantes. Se unieron a la "
    "compañía hará unos tres años como equilibristas.'\n"),1);
  AddQuestion(({"Beni","beni"}),
  "André te dice: 'Es uno de los gemelos Trassi: la chica.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "André te dice: 'Es uno de los gemelos Trassi: el chico.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  W("André te dice: 'No me hables de ese maldito tahúr. Jugué con él pensando que "
    "estaba demasiado borracho para ver las cartas y pensé que podría desplumarle. "
    "No me preguntes cómo lo hizo, el caso es que me desplumó él a mí. Y lo peor "
    "es que me ganó mi posesión más preciada: una espada que heredé de mi padre. "
    "El muy tramposo...'\n"),1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  W("André te dice: 'Es la esposa de Lattini. Es una lanzadora de cuchillos "
    "experta y quiere a su marido con locura. Es una de las razones por las que "
    "no le reviento la cabeza a Lattini. No quiero que ella practique conmigo...'\n"),1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  W("André te dice: 'Es la domadora de fieras de la compañía. Atractiva, pero fría "
    "como el hielo. Más de uno se ha llevado un buen latigazo por intentar poner "
    "la mano donde no debía...'\n"),1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "André te dice: 'Son bailarinas exóticas. Bailan bastante bien, supongo.'\n",1);
  AddQuestion(({"Igart","igart"}),
  W("André te dice: 'Es mona para ser una kainoak. Y no es nada patosa, a pesar de "
    "lo que pueda parecer: tener cuatro brazos es una ventaja para una bailarina.'\n"),1);
  AddQuestion(({"Morda","morda"}),
  W("André te dice: 'Sin duda una elfa negra es muy exótico. Claro que todas "
    "tienen algo exótico, o no serían 'bailarinas exóticas' ¿no crees?'\n"),1);
  AddQuestion(({"Kwailin","kwailin"}),
  W("André te dice: 'La bailarina humana de la compañía. Sus ojos le dan un "
    "aire misterioso y exótico.'\n"),1);
  AddQuestion(({"Baskari","baskari"}),
  W("André te dice: 'Es nuestro jefe. Me proporciona combates de lucha libre "
    "y vamos a medias con los beneficios. No es por presumir, pero todavía no "
    "me ha ganado nadie.'\n"),1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki","bruja","pitonisa"}),
  W("André te dice: 'Es la esposa de Baskari. Se dice que es una bruja poderosa, y "
    "que aunque las pociones que vende en la feria son sólo engañabobos, puede "
    "hacer toda clase de sortilegios y pócimas para el bien... o para el mal.'\n"),1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  W("André te dice: 'Binky, Dinky, Pinky, Tinky y Clyde. Los payasos de nuestra "
    "compañía. También hacen juegos malabares. La verdad es que son simpáticos, "
    "pero algunas veces me sacan de quicio con sus bromas pesadas.'\n"),1);
  AddQuestion(({"Binky","binky"}),
  "André te dice: 'El mayor de los hermanos Kutiri. Colecciona piedras.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "André te dice: 'Uno de los hermanos Kutiri. Un poco guarro, pero buena persona.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "André te dice: 'Uno de los hermanos Kutiri. Es inventor... o eso dice él.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
  "André te dice: 'Uno de los hermanos Kutiri. Le gusta coleccionar cosas brillantes.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  W("André te dice: 'Uno de los hermanos Kutiri. Supongo que sus padres le pusieron "
    "ese nombre por gastarle una broma.'\n"),1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "André te dice: '¡Muchas gracias! ¡Te estaré eternamente agradecido!'\n");
 // Texto que te da las demás veces que lo resuelvas
 SetAgainText(
 "André te mira extrañado y te dice: 'Gracias, pero ya recuperé mi espada."
 "Me la trajiste tú, ¿no te acuerdas? No obstante, guardaré ésta, por si alguien "
 "intenta robar la mía.\n");

 // SetQuest:
 // Quest: sangorquest; subquest: andre;
 SetQuest("sangorquest","andre",({"andre_sword"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 //SetReward("/d/simauria/comun/objeto/quest/sangor_obj");
 SetReward("/players/nemesis/polloquest/cert");
}
