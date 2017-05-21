/* mossi.c
  Equilibrista de la compa��a. Hermano de Beni.
  Tiene informaci�n relativa al caso del l�tigo desaparecido.
  [n] nemesis@simauria

  Creaci�n: 03-Dic-2001 02:10:55 CET
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
  SetLong("Un muchacho humano no demasiado alto. Es m�s bien delgado, aunque "
          "de complexi�n fuerte, sin duda debido a las peculiaridades de su "
          "profesi�n.\n");
  AddId(({"Mossi","mossi","equilibrista","equilibrista masculino"}));
  SetDex(120); // Es MUY �gil
  SetAlign(400);
  InitChats(5,({
   "Mossi dice: 'Como pille al culpable se va a enterar.'\n",
   "Mossi da una voltereta en el aire.\n",
   "Beni salta sobre los hombros de su hermano, que la recoge con facilidad.\n",
   "Mossi dice: 'Vamos a ensayar el nuevo ejercicio.'\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"l�tigo","robo","latigo","l�tigo de Lady Morkobva",
  "l�tigo de lady Morkobva","l�tigo de Lady morkobva","l�tigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),
  "Mossi te dice: 'Alguien de la compa��a rob� el l�tigo favorito de Lady "
  "Morkobva y nos culp� a nosotros. Como le eche el guante al culpable "
  "lo va a pasar muy mal. Mi pobre hermana se pas� la noche llorando el "
  "d�a que Lady Morkobva habl� con nosotros y nos acus�.'\n",1);
  AddQuestion(({"padre","tu padre","vuestro padre"}),
  "Mossi te dice: '�Quieres que mi hermana se eche a llorar? �A qu� viene "
  "esa pregunta?'\n",1);
  AddQuestion(({"madre","tu madre","vuestra madre"}),
  "Mossi te dice: 'Que me perdone Xaenetia, pero por m� esa zorra se puede "
  "pudrir en el Infierno. �C�mo pudo abandonar a sus propios hijos?'\n",1);
  AddQuestion(({"lentejuela"}),
  "Mossi te dice: 'Alguien la dej� en el carromato de Lady Morkobva para que "
  "nos acusaran a nosotros. Por suerte Lady Morkobva nos crey�, pero mi "
  "hermana se pas� toda la noche llorando. Para ella, Lady Morkobva es como "
  "la madre que nunca tuvo y le doli� mucho que sospechara de ella. Si agarro "
  "al culpable, me va a pagar cada l�grima de mi hermana con su sangre.'\n",1);
// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo","forzudo de la compa��a"}),
  "Mossi te dice: 'Andr� es el forzudo de la compa��a. Baskari le organiza "
  "combates de lucha libre algunas veces. Andr� dice que van a medias, pero "
  "Baskari no ha ido a medias con nadie en su vida. Es fuerte, pero no tiene "
  "muchas luces, el pobre.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Mossi te dice: 'Mi hermana y yo somos equilibristas. Llevamos casi tres a�os "
  "en la compa��a.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Mossi te dice: '�se soy yo, �quer�as algo de m�?'\n",1);
  AddQuestion(({"beni","Beni"}),
  "Mossi te dice: 'Es mi hermana. Si intentas hacerle da�o, te parto en dos.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  W("Mossi te dice: 'Lo tiene todo: jugador, borracho y mujeriego. Una vez intent� "
    "ponerle la mano encima a mi hermana, as� que le puse un ojo morado. Le "
    "cont� a su mujer que se hab�a dado con una puerta. El muy cobarde. Me da "
    "mucha pena Nikaia. Toda la compa��a sabe c�mo es Lattini, pero nadie le "
    "dice nada, porque lo quiere tanto que ser�a capaz de una barbaridad.'\n"),1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Mossi te dice: 'Es la esposa de Lattini y le quiere mucho. A pesar de que "
  "es muy celosa, Lattini hace lo que quiere. El amor es ciego, se dice, y "
  "ella est� muy enamorada. Ahora, como alguna vez le pille, Lattini va a "
  "quedar convertido en colador. Menuda es Nikaia con los cuchillos...'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Mossi te dice: 'Es la domadora de fieras de la compa��a. Fue muy amable con "
  "nosotros cuando entramos en la compa��a. Nos dej� vivir en su carromato "
  "mientras consegu�amos el dinero para el nuestro, y luego nos lo vendi� a "
  "un precio de risa. No hagas caso a los que te dicen que es fr�a como una "
  "serpiente. Si se portaran bien con ella, ella se portar�a mejor con ellos.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kallia y morda"}),
  "Mossi te dice: 'Igart, Kwailin y Morda son las bailarinas ex�ticas de la "
  "compa��a. La verdad es que constituyen un conjunto pintoresco: una kainoak, "
  "una elfa y una humana bailando juntas. Mi hermana no les cae bien porque "
  "seg�n Baskari es mejor bailarina que ellas. A m� personalmente no me parece "
  "que lo hagan tan mal, la verdad.'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Mossi te dice: 'Es sin duda la m�s ex�tica de las tres: una bailarina "
  "kainoak. Y no es torpe, no te creas. Es esbelta para ser kainoak y muy "
  "�gil a su manera.'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Mossi te dice: 'Ex�tica: una elfa con la piel negra. Algunos sospechan "
  "que es s�lo elfa a medias, ya me entiendes, pero ella asegura que no. "
  "A m� personalmente me parece que algo �lfico s� tiene. M�s que por "
  "ejemplo el se�or Baskari o su esposa, que son medio-elfos.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  W("Mossi suspira y te dice: 'Es la m�s guapa de las tres. Esos ojos rasgados de pupila "
    "verde son preciosos. Adem�s, creo que es la que mejor se mueve de las tres. "
    "No s� por qu� Baskari dijo que mi hermana era la mejor bailarina.'\n"),1);
  AddQuestion(({"Baskari","baskari","se�or Baskari","se�or baskari",
                "senyor Baskari","senyor baskari"}),
  "Mossi te dice: 'Fue una suerte que el se�or Baskari nos aceptara hace tres "
  "a�os. Nos proporcion� casa y comida. Sin �l sin duda nos hubi�ramos muerto "
  "de hambre. Eso no quita para que yo crea que es un brib�n que vender�a a "
  "su madre por un porcentaje. Pero fuera de los negocios, no es mal tipo.'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                  "Madamme nileki","madamme nileki"}),
  "Mossi te dice: 'Es la esposa del se�or Baskari. No es tan r�cana como "
  "su marido, pero tiene su punto. Dicen que ni es bruja ni es nada, pero "
  "yo s� que no lo dicen en voz alta porque si ella lo supiera les echar�a "
  "un mal de ojo que no se lo quitar�an en diez a�os. No lo hace siempre, "
  "pero algunas veces ayuda a los que realmente lo necesitan.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Mossi te dice: 'Se creen muy graciosos, pero una vez casi matan a mi "
  "hermana con sus bromitas. No s� cu�ndo se decidir� a echarlos el se�or "
  "Baskari. Cuando por su culpa demos todos con nuestros huesos en la "
  "prisi�n, supongo.'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Mossi te dice: 'Es el \"cerebro\" de los Kutiri. Siempre est� maquinando algo.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Mossi te dice: 'Uno de los hermanos Kutiri. Le tiene m�s miedo al agua que "
  "a ninguna otra cosa. Qu� guarro es, Madre de los Hielos.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "Mossi te dice: 'Uno de los hermanos Kutiri. Es \"inventor de trastos "
  "in�tiles\". Es lo que �l mismo dice.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
 "Mossi te dice: 'Uno de los hermanos Kutiri. Le ha robado algo a todos los "
 "miembros de la compa��a. Eso s�, hay que decir que suele devolver lo que "
 "roba... al cabo de cierto tiempo.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Mossi te dice: 'Uno de los hermanos Kutiri. Se pone furioso cada vez que "
  "le preguntan si es hermano de los otros. Yo creo que s�lo es medio hermano, "
  "ya me entiendes...'\n",1);
}
