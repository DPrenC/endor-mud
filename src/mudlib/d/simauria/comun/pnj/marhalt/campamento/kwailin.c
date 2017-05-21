/* kwailin.c
  Bailarina humana.
  Tiene información relativa al caso del látigo desaparecido.
  [n] nemesis@simauria

  Creación: 05-Dic-2001 01:58:10 CET (joer, 1 pnj/h, vaya media...)
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit NPC;

private string answ_robo() {
// Kwailin te dará la pista decisiva para que encuentres el látigo...
 if(TP->Query("beni_acusa")) {
  TP->Set("asked_kwailin",1);
  return W("Le cuentas a Kwailin lo que Beni te ha contado sobre el robo del látigo "
           "de Lady Morkobva. La sonrisa se borra de su cara y te dice: '¿De "
           "verdad piensa eso de nosotras? No me extraña. Nos hemos portado muy "
           "mal con ella. Te diré algo que hasta ahora no le he contado a nadie. "
           "Yo vi a uno de los hermanos Kutiri rondando por el carromato de Lady "
           "Morkobva la noche en que el látigo desapareció. No sé cual era, pero "
           "Estoy segura de que no les importará confesar si les dices que alguien "
           "les vió. Les encanta alardear de sus \"hazañas\".'\n");
  }
  else return "Kwailin te dice: 'No sé de qué me hablas.'\n";
}

private string answ_self() {
 if(TI->QueryGender() == GENERO_MASCULINO)
  return "Kwailin te dice insinuante: 'Ésa soy yo. ¿Qué deseas, guapetón?'\n";
 else return "Kwailin te dice: 'Ésa soy yo. ¿Quieres algo?'\n";
}

private string answ_morda() {
 if(TI->QueryGender() == GENERO_MASCULINO)
  return W("Kwailin te dice: 'Mi compañera, aquí presente. Si quieres saber cosas, "
           "de ella, pregúntale. Adelante, no seas tímido.'\n");
 else return W("Kwailin te dice: 'Mi compañera, aquí presente. Si quieres saber cosas, "
               "de ella, pregúntale.'\n");
}

private string answ_kutiri() {
 if(!TP->Query("asked_kwailin"))
  return W("Kwailin te dice: 'Panda de enanos malolientes. No saben comportarse. Han "
           "estado a punto de matarnos a todos en más de una ocasión por culpa de "
           "sus bromas. La última vez casi consiguen que Beni se caiga de su cuerda. "
           "¡Se podía haber matado!'\n");
 else return W("Kwailin te dice: 'Como ya te dije, vi a uno de ellos rondando por "
               "el carromato de Lady Morkobva la noche que ella dice que su "
               "látigo desapareció. Apostaría lo que quieras a que fue uno de ellos.'\n");
}

// create
create() {
  ::create();
 SetStandard("Kwailin", "humano", 100, GENERO_FEMENINO);
  SetShort("Kwailin, una bailarina");
  SetLong("Una hermosa muchacha humana. Tiene una hermosa melena negra y unos "
          "bellos ojos verdes rasgados, que dan a su rostro un aire misterioso. "
          "Se nota que es algo más joven que las otras.\n");
  // En la habitación habrá un AddDetail tal que asín:
  // AddDetail(({"bailarina exótica","bailarina exotica","bailarina"}),
  //           "¿Cuál de las tres?");
  AddId(({"Kwailin","kwailin","bailarina humana"}));
  SetAlign(400);
  InitChats(5,({
   "Kwailin mira al horizonte y suspira.\n",
   "Kwailin comienza unos pasos de baile, pero al ver que la miras se para.\n",
   "Kwailin y Morda ensayan unos pasos de baile.\n",
   "Kwailin, Igart y Morda te miran y cuchichean algo entre ellas. Luego "
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
  "Kwailin te dice: 'Ese gigantón es demasiado bueno. No debería dejar que "
  "Baskari le hiciera pelear. Algún día va a encontrar la horma de su zapato "
  "y le van a hacer daño. Y lo sentiré mucho, sobre todo por Igart, que se "
  "ha enamorado de él.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Kwailin te mira pensativa un momento y finalmente te dice: 'Mis compañeras "
  "y yo nos hemos portado muy mal con ellos. Nunca les hemos aceptado, y les "
  "hemos hecho la vida imposible. Espero que no sea demasiado tarde para que "
  "me perdonen.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Kwailin te dice: 'Es a la que peor hemos tratado, y no se lo merecía "
  "Yo también soy huérfana, y comprendo por todo lo que ha pasado. Creo "
  "que me hubiera marchado si cuando llegué me hubieran tratado como "
  "nosotras hemos tratado a esa pobrecilla...'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Kwailin te dice: 'El hermano de Beni. Al principio yo pensaba como mis "
  "compañeras: que era un estirado, pero hablando con él he descubierto "
  "que realmente es una buena persona, sólo que la vida le ha hecho no "
  "fiarse de los demás. Si él me lo pidiera, estaría dispuesta incluso "
  "a casarme con él...'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Kwailin te dice: 'Menudo cerdo. Después de dejar tirada a la pobre Morda, "
  "intentó lo mismo conmigo. Pero le dejé las cosas muy claras: a mí los "
  "hombres como él no me interesan. Conmigo no valen sus 'encantos'. "
  "Además, yo a quien quiero es a Mossi.'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Kwailin te dice: 'Pobre mujer... Lo que tiene que aguantar desde que se "
  "casó con Lattini...'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Kwailin te dice: '¿Sabes? Al principio yo pensaba como Igart: que sólo era "
  "una reprimida que odiaba a los hombres porque sí. Sin embargo, después de "
  "hablar con Mossi y con ella creo que tuvo una mala experiencia en su "
  "juventud. Como lo de Morda con Lattini, pero más fuerte... Y creo que eso "
  "la ha vuelto como es. Estoy segura de que algún día encontrará al hombre "
  "perfecto, y por fin podrá ser feliz, al menos yo lo creo así...'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Kwailin te dice: 'Aquí estamos. ¿Quieres que bailemos para ti?'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),SF(answ_self),1);
  AddQuestion(({"Morda","morda"}),SF(answ_morda),1);
  AddQuestion(({"Igart","igart"}),
  "Kwailin te dice: 'Supongo que no es mala chica, aunque no tiene pelos "
  "en la lengua. Últimamente anda mucho con André... Yo creo que tienen "
  "algo...'\n",1);
  AddQuestion(({"Baskari","baskari","señor Baskari","señor baskari",
                "senyor Baskari","senyor baskari"}),
  "Kwailin te dice: 'Es una lástima que le tenga tanto apego a su dinero. "
  "Si no fuera por eso, podría incluso ser buena persona. Por desgracia, "
  "eso no es así, y se queda en un simple granuja de buen corazón... a veces.'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                  "Madamme nileki","madamme nileki"}),
  "Kwailin te dice: 'Es la esposa del señor Baskari. Mucha gente cree que es "
  "una simple farsante, que sus supuestos 'hechizos' son como los trucos de "
  "magia de Lattini. Pobres incautos... Desconocen su auténtico poder.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
                SF(answ_kutiri),1);
  AddQuestion(({"Binky","binky"}),
  "Kwailin te dice: 'El mayor de los hermanos Kutiri. Es el peor de todos.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Kwailin te dice: 'Uno de los hermanos Kutiri. La higiene no es precisamente "
  "su mejor cualidad...'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  "Kwailin te dice: 'Uno de los hermanos Kutiri. Su mayor éxito fue inventar "
  "un carromato sin ruedas... Y utilizó el nuestro para construir su primer "
  "prototipo. Es la vez que más cerca del asesinato he visto a Morda.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
  "Kwailin te dice: 'Uno de los hermanos Kutiri. Si te acercas a él... vigila "
  "tu bolsa. En realidad, vigila cualquier objeto que lleves. Bueno, lo "
  "mejor es que no te le acerques mucho...'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Kwailin te dice: 'Uno de los hermanos Kutiri. La verdad es que su madre "
  "tuvo guasa cuando le puso el nombre...'\n",1);
}
