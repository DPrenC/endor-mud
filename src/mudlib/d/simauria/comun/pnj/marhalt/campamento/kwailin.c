/* kwailin.c
  Bailarina humana.
  Tiene informaci�n relativa al caso del l�tigo desaparecido.
  [n] nemesis@simauria

  Creaci�n: 05-Dic-2001 01:58:10 CET (joer, 1 pnj/h, vaya media...)
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit NPC;

private string answ_robo() {
// Kwailin te dar� la pista decisiva para que encuentres el l�tigo...
 if(TP->Query("beni_acusa")) {
  TP->Set("asked_kwailin",1);
  return W("Le cuentas a Kwailin lo que Beni te ha contado sobre el robo del l�tigo "
           "de Lady Morkobva. La sonrisa se borra de su cara y te dice: '�De "
           "verdad piensa eso de nosotras? No me extra�a. Nos hemos portado muy "
           "mal con ella. Te dir� algo que hasta ahora no le he contado a nadie. "
           "Yo vi a uno de los hermanos Kutiri rondando por el carromato de Lady "
           "Morkobva la noche en que el l�tigo desapareci�. No s� cual era, pero "
           "Estoy segura de que no les importar� confesar si les dices que alguien "
           "les vi�. Les encanta alardear de sus \"haza�as\".'\n");
  }
  else return "Kwailin te dice: 'No s� de qu� me hablas.'\n";
}

private string answ_self() {
 if(TI->QueryGender() == GENERO_MASCULINO)
  return "Kwailin te dice insinuante: '�sa soy yo. �Qu� deseas, guapet�n?'\n";
 else return "Kwailin te dice: '�sa soy yo. �Quieres algo?'\n";
}

private string answ_morda() {
 if(TI->QueryGender() == GENERO_MASCULINO)
  return W("Kwailin te dice: 'Mi compa�era, aqu� presente. Si quieres saber cosas, "
           "de ella, preg�ntale. Adelante, no seas t�mido.'\n");
 else return W("Kwailin te dice: 'Mi compa�era, aqu� presente. Si quieres saber cosas, "
               "de ella, preg�ntale.'\n");
}

private string answ_kutiri() {
 if(!TP->Query("asked_kwailin"))
  return W("Kwailin te dice: 'Panda de enanos malolientes. No saben comportarse. Han "
           "estado a punto de matarnos a todos en m�s de una ocasi�n por culpa de "
           "sus bromas. La �ltima vez casi consiguen que Beni se caiga de su cuerda. "
           "�Se pod�a haber matado!'\n");
 else return W("Kwailin te dice: 'Como ya te dije, vi a uno de ellos rondando por "
               "el carromato de Lady Morkobva la noche que ella dice que su "
               "l�tigo desapareci�. Apostar�a lo que quieras a que fue uno de ellos.'\n");
}

// create
create() {
  ::create();
 SetStandard("Kwailin", "humano", 100, GENERO_FEMENINO);
  SetShort("Kwailin, una bailarina");
  SetLong("Una hermosa muchacha humana. Tiene una hermosa melena negra y unos "
          "bellos ojos verdes rasgados, que dan a su rostro un aire misterioso. "
          "Se nota que es algo m�s joven que las otras.\n");
  // En la habitaci�n habr� un AddDetail tal que as�n:
  // AddDetail(({"bailarina ex�tica","bailarina exotica","bailarina"}),
  //           "�Cu�l de las tres?");
  AddId(({"Kwailin","kwailin","bailarina humana"}));
  SetAlign(400);
  InitChats(5,({
   "Kwailin mira al horizonte y suspira.\n",
   "Kwailin comienza unos pasos de baile, pero al ver que la miras se para.\n",
   "Kwailin y Morda ensayan unos pasos de baile.\n",
   "Kwailin, Igart y Morda te miran y cuchichean algo entre ellas. Luego "
   "comienzan a re�r.\n"
  }));
  // Questions... Laaarga lista... (no �sta, en general)
  AddQuestion(({"l�tigo","robo","latigo","lentejuela","l�tigo de Lady Morkobva",
  "l�tigo de lady Morkobva","l�tigo de Lady morkobva","l�tigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),SF(answ_robo),1);
// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a","forzudo de la compa�ia"}),
  "Kwailin te dice: 'Ese gigant�n es demasiado bueno. No deber�a dejar que "
  "Baskari le hiciera pelear. Alg�n d�a va a encontrar la horma de su zapato "
  "y le van a hacer da�o. Y lo sentir� mucho, sobre todo por Igart, que se "
  "ha enamorado de �l.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Kwailin te mira pensativa un momento y finalmente te dice: 'Mis compa�eras "
  "y yo nos hemos portado muy mal con ellos. Nunca les hemos aceptado, y les "
  "hemos hecho la vida imposible. Espero que no sea demasiado tarde para que "
  "me perdonen.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Kwailin te dice: 'Es a la que peor hemos tratado, y no se lo merec�a "
  "Yo tambi�n soy hu�rfana, y comprendo por todo lo que ha pasado. Creo "
  "que me hubiera marchado si cuando llegu� me hubieran tratado como "
  "nosotras hemos tratado a esa pobrecilla...'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Kwailin te dice: 'El hermano de Beni. Al principio yo pensaba como mis "
  "compa�eras: que era un estirado, pero hablando con �l he descubierto "
  "que realmente es una buena persona, s�lo que la vida le ha hecho no "
  "fiarse de los dem�s. Si �l me lo pidiera, estar�a dispuesta incluso "
  "a casarme con �l...'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Kwailin te dice: 'Menudo cerdo. Despu�s de dejar tirada a la pobre Morda, "
  "intent� lo mismo conmigo. Pero le dej� las cosas muy claras: a m� los "
  "hombres como �l no me interesan. Conmigo no valen sus 'encantos'. "
  "Adem�s, yo a quien quiero es a Mossi.'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Kwailin te dice: 'Pobre mujer... Lo que tiene que aguantar desde que se "
  "cas� con Lattini...'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Kwailin te dice: '�Sabes? Al principio yo pensaba como Igart: que s�lo era "
  "una reprimida que odiaba a los hombres porque s�. Sin embargo, despu�s de "
  "hablar con Mossi y con ella creo que tuvo una mala experiencia en su "
  "juventud. Como lo de Morda con Lattini, pero m�s fuerte... Y creo que eso "
  "la ha vuelto como es. Estoy segura de que alg�n d�a encontrar� al hombre "
  "perfecto, y por fin podr� ser feliz, al menos yo lo creo as�...'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Kwailin te dice: 'Aqu� estamos. �Quieres que bailemos para ti?'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),SF(answ_self),1);
  AddQuestion(({"Morda","morda"}),SF(answ_morda),1);
  AddQuestion(({"Igart","igart"}),
  "Kwailin te dice: 'Supongo que no es mala chica, aunque no tiene pelos "
  "en la lengua. �ltimamente anda mucho con Andr�... Yo creo que tienen "
  "algo...'\n",1);
  AddQuestion(({"Baskari","baskari","se�or Baskari","se�or baskari",
                "senyor Baskari","senyor baskari"}),
  "Kwailin te dice: 'Es una l�stima que le tenga tanto apego a su dinero. "
  "Si no fuera por eso, podr�a incluso ser buena persona. Por desgracia, "
  "eso no es as�, y se queda en un simple granuja de buen coraz�n... a veces.'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                  "Madamme nileki","madamme nileki"}),
  "Kwailin te dice: 'Es la esposa del se�or Baskari. Mucha gente cree que es "
  "una simple farsante, que sus supuestos 'hechizos' son como los trucos de "
  "magia de Lattini. Pobres incautos... Desconocen su aut�ntico poder.'\n",1);
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
  "Kwailin te dice: 'Uno de los hermanos Kutiri. Su mayor �xito fue inventar "
  "un carromato sin ruedas... Y utiliz� el nuestro para construir su primer "
  "prototipo. Es la vez que m�s cerca del asesinato he visto a Morda.'\n",1);
  AddQuestion(({"Tinky","Tinky"}),
  "Kwailin te dice: 'Uno de los hermanos Kutiri. Si te acercas a �l... vigila "
  "tu bolsa. En realidad, vigila cualquier objeto que lleves. Bueno, lo "
  "mejor es que no te le acerques mucho...'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Kwailin te dice: 'Uno de los hermanos Kutiri. La verdad es que su madre "
  "tuvo guasa cuando le puso el nombre...'\n",1);
}
