/* andre.c
  El forzudo de la compa��a de titiriteros.
  Necesita una vieja espada que tiene Lady Morkobva.
  A cambio te dar� una cosa que Sangor quiere mucho.
  [n] nemesis@simauria

  Creaci�n: 02-Dic-2001 20:17:29 CET
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit "std/questnpc";

create() {
  ::create();
 SetStandard("Andr�", "gigante", 100, GENERO_MASCULINO);
  SetShort("Andr�, el forzudo de la compa��a");
  SetLong("Es una aut�ntica mole de m�sculos. Mide casi 3 metros de alto y "
          "casi lo mismo de ancho. En su rostro distingues ciertos rasgos "
          "orcos, aunque nunca hab�as visto un orco tan grande.\n");
  AddId(({"Andr�","Andre","andr�","andre","forzudo"}));
  SetSize(P_SIZE_MEDIUM); // Ojo: es normal, porque es grande, pero no tanto...
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "Andr� dice: 'Ojal� alguien me ayudara.'\n",
   "Andr� dice: '�Por qu� jugar�a con ese tah�r de Lattini?'\n",
   "Andr� dice: 'No s� para qu� me jugu� nada. Incluso borracho me gan�...'\n",
   "Andr� dice: '�C�mo pude ser tan imb�cil?'\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"espada","tu espada"}),
  W("Andr� te dice: 'Es una espada que hab�a estado en mi familia durante m�s de "
    "500 a�os. Mi padre me cont� que uno de mis antepasados mat� a un gran rey "
    "de Simauria con ella, claro que yo nunca me lo cre�. Pero lo cierto es que "
    "es lo �nico que mi querido padre me dej� al morir, y aunque no sepa usarla, "
    "es un honor que me diera algo que ten�a en tanta estima. Y ahora yo lo he "
    "perdido en una partida de cartas... Si mi padre me viera se morir�a de "
    "verg�enza... Claro que ya est� muerto...'\n"),1);
  AddQuestion(({"padre","tu padre"}),
  W("Andr� te dice: 'Fue un gran guerrero de Akallab. Cuando se firm� la tregua "
    "con Simauria recorri� el mundo como mercenario. Nunca fue vencido en "
    "ninguna batalla.'\n"),1);
// �sta llevar� "premio"...
  AddQuestion(({"madre","tu madre"}),
  W("Andr� te dice: '�Qu� tienes que decir de mi madre? �Fue una santa, son "
    "rumores infundados!'\n"),1);
  AddQuestion(({"cartas","partida"}),
  W("Andr� te dice: 'Vi a Lattini tan borracho que pens� que podr�a ganarle unas "
    "monedas. No cont� con que es el mayor tramposo de este lado del mundo. Me "
    "gan� casi todo lo que ten�a. Jugamos a las 8 y media. En la �ltima mano, "
    "por fin me sale un 8. El muy tramposo se jug� todo lo que ten�a y yo piqu� "
    "como un tonto. Me jugu� mis �ltimas monedas y mi espada. Yo paso y �l coge "
    "dos cartas. Me planto y le ense�o triunfal mi ocho. �l sonr�e, me mira con "
    "los ojos enrojecidos por el alcohol y me ense�a sus cartas: 5, 2 y tres "
    "figuras. 8 y medio en total. Acto seguido recogi� sus ganancias, me dese� "
    "buenas noches, y se alej� tambale�ndose hacia su carreta, mientras yo me "
    "quedaba all� con cara de tonto.'\n"),1);
  AddQuestion(({"ocho y media","8 y media"}),
  W("Andr� suspira y te dice: 'Ay, las ocho y media es un juego... Y un juego "
    "vil, que no hay que jugarlo a ciegas, pues juegas cien veces, mil, y de "
    "las mil ves febril que o te pasas o no llegas. Y el no llegar da dolor "
    "pues implica que mal tasas y eres del otro deudor. Mas, ay de ti si te "
    "pasas... si te pasas es peor...'\n"),1); // Lo siento, ten�a que hacerlo ;)
// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a"}),
  "Andr� te dice: '�se soy yo, �quer�as algo de m�?'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  W("Andr� te dice: 'Son gemelos. Chico y chica. Su madre les abandon� siendo muy "
    "peque�os y se ganaron la vida como artistas ambulantes. Se unieron a la "
    "compa��a har� unos tres a�os como equilibristas.'\n"),1);
  AddQuestion(({"Beni","beni"}),
  "Andr� te dice: 'Es uno de los gemelos Trassi: la chica.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Andr� te dice: 'Es uno de los gemelos Trassi: el chico.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  W("Andr� te dice: 'No me hables de ese maldito tah�r. Jugu� con �l pensando que "
    "estaba demasiado borracho para ver las cartas y pens� que podr�a desplumarle. "
    "No me preguntes c�mo lo hizo, el caso es que me desplum� �l a m�. Y lo peor "
    "es que me gan� mi posesi�n m�s preciada: una espada que hered� de mi padre. "
    "El muy tramposo...'\n"),1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  W("Andr� te dice: 'Es la esposa de Lattini. Es una lanzadora de cuchillos "
    "experta y quiere a su marido con locura. Es una de las razones por las que "
    "no le reviento la cabeza a Lattini. No quiero que ella practique conmigo...'\n"),1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  W("Andr� te dice: 'Es la domadora de fieras de la compa��a. Atractiva, pero fr�a "
    "como el hielo. M�s de uno se ha llevado un buen latigazo por intentar poner "
    "la mano donde no deb�a...'\n"),1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Andr� te dice: 'Son bailarinas ex�ticas. Bailan bastante bien, supongo.'\n",1);
  AddQuestion(({"Igart","igart"}),
  W("Andr� te dice: 'Es mona para ser una kainoak. Y no es nada patosa, a pesar de "
    "lo que pueda parecer: tener cuatro brazos es una ventaja para una bailarina.'\n"),1);
  AddQuestion(({"Morda","morda"}),
  W("Andr� te dice: 'Sin duda una elfa negra es muy ex�tico. Claro que todas "
    "tienen algo ex�tico, o no ser�an 'bailarinas ex�ticas' �no crees?'\n"),1);
  AddQuestion(({"Kwailin","kwailin"}),
  W("Andr� te dice: 'La bailarina humana de la compa��a. Sus ojos le dan un "
    "aire misterioso y ex�tico.'\n"),1);
  AddQuestion(({"Baskari","baskari"}),
  W("Andr� te dice: 'Es nuestro jefe. Me proporciona combates de lucha libre "
    "y vamos a medias con los beneficios. No es por presumir, pero todav�a no "
    "me ha ganado nadie.'\n"),1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki","bruja","pitonisa"}),
  W("Andr� te dice: 'Es la esposa de Baskari. Se dice que es una bruja poderosa, y "
    "que aunque las pociones que vende en la feria son s�lo enga�abobos, puede "
    "hacer toda clase de sortilegios y p�cimas para el bien... o para el mal.'\n"),1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  W("Andr� te dice: 'Binky, Dinky, Pinky, Tinky y Clyde. Los payasos de nuestra "
    "compa��a. Tambi�n hacen juegos malabares. La verdad es que son simp�ticos, "
    "pero algunas veces me sacan de quicio con sus bromas pesadas.'\n"),1);
  AddQuestion(({"Binky","binky"}),
  "Andr� te dice: 'El mayor de los hermanos Kutiri. Colecciona piedras.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Andr� te dice: 'Uno de los hermanos Kutiri. Un poco guarro, pero buena persona.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "Andr� te dice: 'Uno de los hermanos Kutiri. Es inventor... o eso dice �l.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
  "Andr� te dice: 'Uno de los hermanos Kutiri. Le gusta coleccionar cosas brillantes.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  W("Andr� te dice: 'Uno de los hermanos Kutiri. Supongo que sus padres le pusieron "
    "ese nombre por gastarle una broma.'\n"),1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Andr� te dice: '�Muchas gracias! �Te estar� eternamente agradecido!'\n");
 // Texto que te da las dem�s veces que lo resuelvas
 SetAgainText(
 "Andr� te mira extra�ado y te dice: 'Gracias, pero ya recuper� mi espada."
 "Me la trajiste t�, �no te acuerdas? No obstante, guardar� �sta, por si alguien "
 "intenta robar la m�a.\n");

 // SetQuest:
 // Quest: sangorquest; subquest: andre;
 SetQuest("sangorquest","andre",({"andre_sword"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 //SetReward("/d/simauria/comun/objeto/quest/sangor_obj");
 SetReward("/players/nemesis/polloquest/cert");
}
