/* beni.c
  Equilibrista de la compañía. Hermana de Mossi.
  Tiene información relativa al caso del látigo desaparecido.
  [n] nemesis@simauria

  Creación: 03-Dic-2001 01:10:55 CET
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit NPC;

private string answ_lentejuela() {
 TP->Set("beni_acusa",1);
 return W("Beni te dice: 'Alguien la dejó en el carromato de Lady Morkobva para que "
          "nos acusaran a nosotros, pero Lady morkobva es demasiado lista para dejarse "
          "engañar. Seguro que fueron esas lagartas de Igart, Kallia y Morda, que "
          "me odian porque soy mejor bailarina que ellas. Ellas también usan lentejuelas "
          "en sus trajes...'\n");
}

create() {
  ::create();
 SetStandard("Beni", "humano", 100, GENERO_FEMENINO);
  SetShort("Beni, una equilibrista");
  SetLong("Una muchacha humana no demasiado alta. Es más bien delgada, aunque "
          "posee unos músculos fibrosos que sin duda son de gran ayuda en su "
          "profesión.\n");
  AddId(({"Beni","beni","equilibrista","equilibrista femenina"}));
  SetDex(130); // Es MUY ágil
  SetAlign(400);
  InitChats(5,({
   "Beni dice: ¿Quién nos querría culpar del robo?.\n",
   "Beni comienza unos ejercicios de estiramiento.\n",
   "Beni salta sobre los hombros de su hermano, que la recoge con facilidad.\n",
   "Beni dice: Vamos a ensayar otro ejercicio.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"látigo","robo","latigo","lentejuela","látigo de Lady Morkobva",
  "látigo de lady Morkobva","látigo de Lady morkobva","látigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),
  "Beni te dice: 'Alguien de la compañía le robó su látigo favorito a Lady "
  "Morkobva y nos culpó a nosotros. Dejó una lentejuela como las de mi traje "
  "para que las culpas cayesen sobre mí. Menos mal que Lady Morkobva nos creyó. "
  "Nos ayudó mucho cuando entramos en la compañía y sabe que nosotros no le "
  "haríamos algo así.'\n",1);
  AddQuestion(({"padre","tu padre","vuestro padre"}),
  W("Beni te dice: 'No conocimos a nuestro padre, murió al poco de nacer nosotros. "
    "Pero, ¿a qué viene esa pregunta?'\n"),1);
  AddQuestion(({"madre","tu madre","vuestra madre"}),
  "Beni te dice con voz triste: 'Nos abandonó siendo pequeños. No queremos "
  "volver a verla nunca más.'\n",1);
  AddQuestion(({"lentejuela"}),SF(answ_lentejuela),1);

// Info sobre los miembros de la compañía
  AddQuestion(({"André","Andre","andré","andre","forzudo",
                "forzudo de la compañía","forzudo de la compañia"}),
  W("Beni te dice: 'André es el forzudo de la compañía. Su padre era un guerrero o "
    "algo así. Nunca habla de su madre, pero yo sé que no era orco como su padre. "
    "Es mestizo, y tuvo una infancia dura, el pobre. Es muy fuerte, pero tiene "
    "buen corazón.\n"),1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Beni te dice: 'Mi hermano y yo somos equilibristas. Llevamos casi tres años "
  "en la compañía.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Beni te dice: 'Ésa soy yo, ¿querías algo de mí?'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Beni te dice: 'Es mi hermano.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Beni te dice: 'Es ilusionista y de vez en cuando se saca un sobresueldo "
  "desplumando a pobres incautos en las salas de juego. Todos saben que hace "
  "trampas, pero nadie, jamás, ha sido capaz de demostrarlo. Es muy bueno. "
  "Una vez intentó propasarse conmigo, pero mi hermano le paró los pies. "
  "Pobre Nikaia, lo que tiene que aguantar...'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Beni te dice: 'Es la esposa de Lattini. Ninguno de nosotros comprendió "
  "por qué una lanzadora de cuchillos como ella se iba a casar con semejante "
  "bandarra, pero lo cierto es que ella le quiere con locura. En fin, supongo "
  "que el amor es ciego.'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Beni te dice: 'Es la domadora de fieras de la compañía. Prácticamente se "
  "puede decir que nos adoptó a mi hermano y a mí. Dicen que es fría y cruel, "
  "y que sólo quiere a su pantera, pero yo sé que no es cierto. Lo que pasa "
  "es que los hombres sólo ven en ella su físico, y las mujeres están celosas "
  "porque es atractiva. Pero yo sé que en el fondo es muy buena.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Beni te dice: 'Esas lagartas... Se creen que porque bailan delante de los "
  "hombres tienen la exclusiva de la belleza y el erotismo. Una vez que ellas "
  "pidieron cobrar más, Baskari les dijo que si no estaban contentas con su "
  "sueldo, podían irse porque yo era mejor bailarina que ellas y las podría "
  "sustituir perfectamente. Ellas me odian porque saben que es verdad.'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Beni te dice: 'Es la peor de las tres. Yo no sé qué le ve la gente a una "
  "tía de casi tres metros moviendo los cuatro brazos como una loca. Creo "
  "que nunca lo entenderé.'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Beni te dice: 'Ella dice que es una alta elfa de Lad-Laurelin, pero "
  "yo estoy segura de que es sólo medio-elfa. ¿Dónde se ha visto una elfa "
  "con la piel negra?'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Beni te dice: 'Baskari la contrató por sus ojos rasgados, que le dan un "
  "toque exótico. Hay que reconocer que últimamente se porta mejor conmigo. "
  "Quizá se ha dado cuenta de que las otras no son buenas compañías.'\n",1);
  AddQuestion(({"Baskari","baskari","señor Baskari","señor baskari",
                "senyor Baskari","senyor baskari"}),
  "Beni te dice: 'Fue una suerte que el señor Baskari nos aceptara hace tres "
  "años, pues estábamos en la miseria. Le estamos muy agradecidos, porque nos "
  "proporcionó casa y comida. Sin él nos hubiéramos muerto de hambre.'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                  "Madamme nileki","madamme nileki"}),
  "Beni te dice: 'Es la esposa del señor Baskari. Se portó muy bien con "
  "nosotros cuando llegamos. No te creas lo que dicen por ahí de que es "
  "una farsante. Si quiere, puede hacer prodigios increíbles, y sabe "
  "leer el futuro, te lo digo yo.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  W("Beni te dice: 'Son los payasos de la compañía. A algunos les caen simpáticos, "
    "pero la verdad es que son unos impresentables, siempre bebiendo y gastando "
    "bromas pesadas. Más de una vez nos han echado de algún pueblo por culpa "
    "de sus estupideces. Todavía recuerdo cuando le echaron grasa a mi cuerda "
    "floja. Menos mal que todavía no había empezado a hacer el ejercicio sin red. "
    "¡Casi me mato!'\n"),1);
  AddQuestion(({"Binky","binky"}),
  "Beni te dice: 'El mayor de los hermanos Kutiri. Y el peor.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Beni te dice: 'Uno de los hermanos Kutiri. No se ha lavado en su vida.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  W("Beni te dice: 'Uno de los hermanos Kutiri. Dice que es inventor, pero todavía "
    "no ha hecho nada útil, que yo sepa.'\n"),1);
  AddQuestion(({"Tinky","Tinky"}),
 "Beni te dice: 'Uno de los hermanos Kutiri. El muy ladrón me robó el traje "
 "y tuve que salir a la pista con uno de Madamme Nileki. Qué vergüenza.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Beni te dice: 'Uno de los hermanos Kutiri. Para mí que no es hijo del mismo "
  "padre que los otros...'\n",1);
}
