/* igart.c
  Bailarina kainoak.
  Tiene información relativa al caso del látigo desaparecido.
  [n] nemesis@simauria

  Creación: 05-Dic-2001 00:01:47 CET
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit NPC;

private string answ_robo() {
 if(TP->Query("beni_acusa"))
  return W("Le cuentas a Igart lo que Beni te ha contado sobre el robo del látigo "
           "de Lady Morkobva. La sonrisa se borra de su cara y te dice: '¿Esa "
           "renacuaja de Beni te ha dicho eso? Pues ya le puedes decir que "
           "nosotras no somos tan rastreras. Además, si quisiéramos hacerle algo "
           "a ella o a su hermanito, lo haríamos cara a cara. Le puedes decir "
           "que si quiere hacer alguna acusación, que nos lo diga a la cara. "
           "Entonces ajustaremos cuentas.'\n");
  else return "Igart te dice: 'No sé de qué carajo me hablas.'\n";
}

private string answ_self() {
 if(TI->QueryGender() == GENERO_MASCULINO)
  return "Igart te dice: 'Ésa soy yo. ¿Quieres algo, cariño?'\n";
 else return "Igart te dice: 'Ésa soy yo. ¿Quieres algo?'\n";
}

create() {
  ::create();
 SetStandard("Igart", "kainoak", 100, GENERO_FEMENINO);
  SetShort("Igart, una bailarina");
  SetLong("Una joven kainoak más esbelta de lo que es natural en estos seres. "
          "Sin duda esto la ayuda en su profesión, y hace que se mueva más "
          "insinuantemente. Al ver que la miras, te sonríe con descaro.\n");
  // En la habitación habrá un AddDetail tal que asín:
  // AddDetail(({"bailarina exótica","bailarina exotica","bailarina"}),
  //           "¿Cuál de las tres?");
  AddId(({"Igart","igart","bailarina kainoak"}));
  SetAlign(400);
  InitChats(5,({
   "Igart dice: 'Ya ha vuelto Lattini a poner un clavel en mi ventana. ¡No se "
   "da por vencido nunca!'\n Las otras dos ríen con ganas.\n",
   "Igart comienza unos pasos de baile, pero al ver que la miras se para.\n",
   "Igart le dice algo al oído a Morda mirando a Kwailin. De pronto ambas "
   "estallan en sonoras carcajadas.\n",
   "Igart, Kwailin y Morda te miran y cuchichean algo entre ellas. Luego "
   "comienzan a reír.\n"
  }));
  // Questions... Laaarga lista... (no ésta, en general)
  AddQuestion(({"látigo","robo","latigo","lentejuela","látigo de Lady Morkobva",
  "látigo de lady Morkobva","látigo de Lady morkobva","látigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),SF(answ_robo),1);
// Info sobre los miembros de la compañía
  AddQuestion(({"André","Andre","andré","andre","forzudo",
                "forzudo de la compañía","forzudo de la compañia"}),
  "Igart te dice: 'André es nuestro 'hombre fuerte'. Pero no creas que por ser "
  "grande es tonto. No, eso lo creen los demás, pero yo sé que es muy listo. "
  "Además, tiene un gran corazón y siempre está dispuesto a usar su fuerza "
  "para ayudar a los más débiles.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Igart te dice: 'Yo no sé qué le ve la gente a las contorsiones y ejercicios "
  "que hacen esos dos. Se lo digo siempre a Baskari: saldrían más baratos unos "
  "cuantos monos. Claro que él prefiere ahorrar en nuestros sueldos. ¡Mira mi "
  "vestido! Lo he remendado no sé cuántas veces, pero él no quiere comprarnos "
  "nuevos vestidos, dice que sería mucho gasto. Será hurón...'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Igart te dice: 'No me hables de esa niñata. Es la excusa que Baskari usa "
  "para no aumentar nuestro sueldo. Que baila mejor... ya me gustaría ver a "
  "esa remilgada bailando delante de todos esos salvajes, aguantando lo que "
  "nosotras tenemos que aguantar... Y todo ¿para qué? Para que Baskari se "
  "quede con el dinero que ganamos y luego nos dé una miseria.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Igart te dice: 'El hermano de esa remilgada de Beni. Me gustaría ver la "
  "cara que pone si Baskari le dice que su hermanita tiene que salir "
  "prácticamente desnuda a contonearse delante de los hombres. Creo que "
  "Baskari se llevaría una buena sorpresa.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Igart te dice: 'Es el ilusionista de la caravana. Domina toda clase de "
  "juegos de manos, tú ya me entiendes. Su esposa me da un poco de pena, "
  "porque creo que se ha acostado con todas las mujeres que se le han "
  "puesto a tiro. Bueno, excepto quizá con Lady Morkobva. Pero es normal, "
  "no creo que esa frígida sepa apreciar a un hombre como él.'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Igart te dice: '¿La esposa de Lattini? Pobrecita. Tiene que agacharse "
  "para pasar por las puertas, ya me entiendes... ¡Ja, ja, ja!'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Igart te dice: '¿Ésa? Va de mujer dura por la vida, con su traje de cuero "
  "y sus látigos, y sus cadenas... Ahora, te digo que en el fondo es una "
  "frustrada que no sabría qué hacer si un hombre se le insinuase. Bueno, sí "
  "que lo sabe: arrearle un zurriagazo... Pero es lo que yo digo, es más "
  "divertido ser apasionada de otra forma...'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Igart te dice: 'Las tienes delante: las mejores bailarinas del norte, del "
  "este y del sur, a tu servicio por un puñado de monedas.'\n",1);
  AddQuestion(({"Igart","igart"}),SF(answ_self),1);
  AddQuestion(({"Morda","morda"}),
  "Igart te dice: 'Mi compañera, aquí presente. Pregúntale lo que quieras, "
  "que estoy segura que te contestará con placer.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  W("Igart te dice: 'Mi compañera más joven. Entre nosotros... Últimamente está muy "
    "rara, y no para de hacerle ojitos a ese imbécil de Mossi. Mira que si "
    "se enamora de semejante idiota...'\n"),1);
  AddQuestion(({"Baskari","baskari","señor Baskari","señor baskari",
                "senyor Baskari","senyor baskari"}),
  "Igart te dice: 'Es un explotador, que se enriquece a costa nuestra. "
  "Le gusta aparentar que tiene corazón recogiendo a muertos de hambre "
  "como los gemelos Trassi, pero en el fondo sólo tiene un interés: "
  "el dinero y los beneficios. Pero ya llegará la revolución...'\n",1); // Un poco rojilla sí es...
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                  "Madamme nileki","madamme nileki"}),
  "Igart te dice: 'La esposa de Baskari. Es la única que sabe ponerle en "
  "su sitio cuando se enfada o nos grita sin razón. Las cosas nos irían "
  "mejor con ella al mando.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Igart te dice: '¡No me hables! ¡Menudos gamberros! Por aquello de que son "
  "pequeños, a André le caen bastante bien, pero lo cierto es que al final "
  "vamos a tener que echarlos. Desde que están con nosotros sólo nos han "
  "causado problemas. Parecen tener una fijación especial con Baskari y su "
  "esposa. Sólo sentí aquella vez que casi matan a Beni. Qué rabia que "
  "fallaran, oyes...'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Igart te dice: 'El mayor de los hermanos Kutiri. Y el peor.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Igart te dice: 'Uno de los hermanos Kutiri. Es más guarro que la mierda.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "Igart te dice: 'Uno de los hermanos Kutiri. Suele definirse como inventor "
  "de aparatos inútiles.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
 "Igart te dice: 'Uno de los hermanos Kutiri. Un auténtico ladrón. Y más "
 "malo que la tiña.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Igart te dice: 'Uno de los hermanos Kutiri. Hay algo en él que no parece "
  "de la misma familia... y no me refiero sólo al nombre...'\n",1);
}
