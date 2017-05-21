/* mossi.c
  Equilibrista de la compañía. Hermano de Beni.
  Tiene información relativa al caso del látigo desaparecido.
  [n] nemesis@simauria

  Creación: 03-Dic-2001 02:10:55 CET
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit NPC;

create() {
  ::create();
 SetStandard("Mossi", "humano", 100, GENERO_MASCULINO);
  SetShort("Mossi, un equilibrista");
  SetLong("Un muchacho humano no demasiado alto. Es más bien delgado, aunque "
          "de complexión fuerte, sin duda debido a las peculiaridades de su "
          "profesión.\n");
  AddId(({"Mossi","mossi","equilibrista","equilibrista masculino"}));
  SetDex(120); // Es MUY ágil
  SetAlign(400);
  InitChats(5,({
   "Mossi dice: 'Como pille al culpable se va a enterar.'\n",
   "Mossi da una voltereta en el aire.\n",
   "Beni salta sobre los hombros de su hermano, que la recoge con facilidad.\n",
   "Mossi dice: 'Vamos a ensayar el nuevo ejercicio.'\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"látigo","robo","latigo","látigo de Lady Morkobva",
  "látigo de lady Morkobva","látigo de Lady morkobva","látigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),
  "Mossi te dice: 'Alguien de la compañía robó el látigo favorito de Lady "
  "Morkobva y nos culpó a nosotros. Como le eche el guante al culpable "
  "lo va a pasar muy mal. Mi pobre hermana se pasó la noche llorando el "
  "día que Lady Morkobva habló con nosotros y nos acusó.'\n",1);
  AddQuestion(({"padre","tu padre","vuestro padre"}),
  "Mossi te dice: '¿Quieres que mi hermana se eche a llorar? ¿A qué viene "
  "esa pregunta?'\n",1);
  AddQuestion(({"madre","tu madre","vuestra madre"}),
  "Mossi te dice: 'Que me perdone Xaenetia, pero por mí esa zorra se puede "
  "pudrir en el Infierno. ¿Cómo pudo abandonar a sus propios hijos?'\n",1);
  AddQuestion(({"lentejuela"}),
  "Mossi te dice: 'Alguien la dejó en el carromato de Lady Morkobva para que "
  "nos acusaran a nosotros. Por suerte Lady Morkobva nos creyó, pero mi "
  "hermana se pasó toda la noche llorando. Para ella, Lady Morkobva es como "
  "la madre que nunca tuvo y le dolió mucho que sospechara de ella. Si agarro "
  "al culpable, me va a pagar cada lágrima de mi hermana con su sangre.'\n",1);
// Info sobre los miembros de la compañía
  AddQuestion(({"André","Andre","andré","andre","forzudo","forzudo de la compañía"}),
  "Mossi te dice: 'André es el forzudo de la compañía. Baskari le organiza "
  "combates de lucha libre algunas veces. André dice que van a medias, pero "
  "Baskari no ha ido a medias con nadie en su vida. Es fuerte, pero no tiene "
  "muchas luces, el pobre.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Mossi te dice: 'Mi hermana y yo somos equilibristas. Llevamos casi tres años "
  "en la compañía.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Mossi te dice: 'Ése soy yo, ¿querías algo de mí?'\n",1);
  AddQuestion(({"beni","Beni"}),
  "Mossi te dice: 'Es mi hermana. Si intentas hacerle daño, te parto en dos.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  W("Mossi te dice: 'Lo tiene todo: jugador, borracho y mujeriego. Una vez intentó "
    "ponerle la mano encima a mi hermana, así que le puse un ojo morado. Le "
    "contó a su mujer que se había dado con una puerta. El muy cobarde. Me da "
    "mucha pena Nikaia. Toda la compañía sabe cómo es Lattini, pero nadie le "
    "dice nada, porque lo quiere tanto que sería capaz de una barbaridad.'\n"),1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Mossi te dice: 'Es la esposa de Lattini y le quiere mucho. A pesar de que "
  "es muy celosa, Lattini hace lo que quiere. El amor es ciego, se dice, y "
  "ella está muy enamorada. Ahora, como alguna vez le pille, Lattini va a "
  "quedar convertido en colador. Menuda es Nikaia con los cuchillos...'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Mossi te dice: 'Es la domadora de fieras de la compañía. Fue muy amable con "
  "nosotros cuando entramos en la compañía. Nos dejó vivir en su carromato "
  "mientras conseguíamos el dinero para el nuestro, y luego nos lo vendió a "
  "un precio de risa. No hagas caso a los que te dicen que es fría como una "
  "serpiente. Si se portaran bien con ella, ella se portaría mejor con ellos.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kallia y morda"}),
  "Mossi te dice: 'Igart, Kwailin y Morda son las bailarinas exóticas de la "
  "compañía. La verdad es que constituyen un conjunto pintoresco: una kainoak, "
  "una elfa y una humana bailando juntas. Mi hermana no les cae bien porque "
  "según Baskari es mejor bailarina que ellas. A mí personalmente no me parece "
  "que lo hagan tan mal, la verdad.'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Mossi te dice: 'Es sin duda la más exótica de las tres: una bailarina "
  "kainoak. Y no es torpe, no te creas. Es esbelta para ser kainoak y muy "
  "ágil a su manera.'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Mossi te dice: 'Exótica: una elfa con la piel negra. Algunos sospechan "
  "que es sólo elfa a medias, ya me entiendes, pero ella asegura que no. "
  "A mí personalmente me parece que algo élfico sí tiene. Más que por "
  "ejemplo el señor Baskari o su esposa, que son medio-elfos.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  W("Mossi suspira y te dice: 'Es la más guapa de las tres. Esos ojos rasgados de pupila "
    "verde son preciosos. Además, creo que es la que mejor se mueve de las tres. "
    "No sé por qué Baskari dijo que mi hermana era la mejor bailarina.'\n"),1);
  AddQuestion(({"Baskari","baskari","señor Baskari","señor baskari",
                "senyor Baskari","senyor baskari"}),
  "Mossi te dice: 'Fue una suerte que el señor Baskari nos aceptara hace tres "
  "años. Nos proporcionó casa y comida. Sin él sin duda nos hubiéramos muerto "
  "de hambre. Eso no quita para que yo crea que es un bribón que vendería a "
  "su madre por un porcentaje. Pero fuera de los negocios, no es mal tipo.'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                  "Madamme nileki","madamme nileki"}),
  "Mossi te dice: 'Es la esposa del señor Baskari. No es tan rácana como "
  "su marido, pero tiene su punto. Dicen que ni es bruja ni es nada, pero "
  "yo sé que no lo dicen en voz alta porque si ella lo supiera les echaría "
  "un mal de ojo que no se lo quitarían en diez años. No lo hace siempre, "
  "pero algunas veces ayuda a los que realmente lo necesitan.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Mossi te dice: 'Se creen muy graciosos, pero una vez casi matan a mi "
  "hermana con sus bromitas. No sé cuándo se decidirá a echarlos el señor "
  "Baskari. Cuando por su culpa demos todos con nuestros huesos en la "
  "prisión, supongo.'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Mossi te dice: 'Es el \"cerebro\" de los Kutiri. Siempre está maquinando algo.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Mossi te dice: 'Uno de los hermanos Kutiri. Le tiene más miedo al agua que "
  "a ninguna otra cosa. Qué guarro es, Madre de los Hielos.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "Mossi te dice: 'Uno de los hermanos Kutiri. Es \"inventor de trastos "
  "inútiles\". Es lo que él mismo dice.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
 "Mossi te dice: 'Uno de los hermanos Kutiri. Le ha robado algo a todos los "
 "miembros de la compañía. Eso sí, hay que decir que suele devolver lo que "
 "roba... al cabo de cierto tiempo.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Mossi te dice: 'Uno de los hermanos Kutiri. Se pone furioso cada vez que "
  "le preguntan si es hermano de los otros. Yo creo que sólo es medio hermano, "
  "ya me entiendes...'\n",1);
}
