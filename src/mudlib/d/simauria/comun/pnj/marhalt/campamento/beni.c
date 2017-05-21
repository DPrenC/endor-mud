/* beni.c
  Equilibrista de la compa��a. Hermana de Mossi.
  Tiene informaci�n relativa al caso del l�tigo desaparecido.
  [n] nemesis@simauria

  Creaci�n: 03-Dic-2001 01:10:55 CET
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit NPC;

private string answ_lentejuela() {
 TP->Set("beni_acusa",1);
 return W("Beni te dice: 'Alguien la dej� en el carromato de Lady Morkobva para que "
          "nos acusaran a nosotros, pero Lady morkobva es demasiado lista para dejarse "
          "enga�ar. Seguro que fueron esas lagartas de Igart, Kallia y Morda, que "
          "me odian porque soy mejor bailarina que ellas. Ellas tambi�n usan lentejuelas "
          "en sus trajes...'\n");
}

create() {
  ::create();
 SetStandard("Beni", "humano", 100, GENERO_FEMENINO);
  SetShort("Beni, una equilibrista");
  SetLong("Una muchacha humana no demasiado alta. Es m�s bien delgada, aunque "
          "posee unos m�sculos fibrosos que sin duda son de gran ayuda en su "
          "profesi�n.\n");
  AddId(({"Beni","beni","equilibrista","equilibrista femenina"}));
  SetDex(130); // Es MUY �gil
  SetAlign(400);
  InitChats(5,({
   "Beni dice: �Qui�n nos querr�a culpar del robo?.\n",
   "Beni comienza unos ejercicios de estiramiento.\n",
   "Beni salta sobre los hombros de su hermano, que la recoge con facilidad.\n",
   "Beni dice: Vamos a ensayar otro ejercicio.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"l�tigo","robo","latigo","lentejuela","l�tigo de Lady Morkobva",
  "l�tigo de lady Morkobva","l�tigo de Lady morkobva","l�tigo de lady morkobva",
  "latigo de Lady Morkobva","latigo de lady Morkobva","latigo de Lady morkobva",
  "latigo de lady morkobva"}),
  "Beni te dice: 'Alguien de la compa��a le rob� su l�tigo favorito a Lady "
  "Morkobva y nos culp� a nosotros. Dej� una lentejuela como las de mi traje "
  "para que las culpas cayesen sobre m�. Menos mal que Lady Morkobva nos crey�. "
  "Nos ayud� mucho cuando entramos en la compa��a y sabe que nosotros no le "
  "har�amos algo as�.'\n",1);
  AddQuestion(({"padre","tu padre","vuestro padre"}),
  W("Beni te dice: 'No conocimos a nuestro padre, muri� al poco de nacer nosotros. "
    "Pero, �a qu� viene esa pregunta?'\n"),1);
  AddQuestion(({"madre","tu madre","vuestra madre"}),
  "Beni te dice con voz triste: 'Nos abandon� siendo peque�os. No queremos "
  "volver a verla nunca m�s.'\n",1);
  AddQuestion(({"lentejuela"}),SF(answ_lentejuela),1);

// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a","forzudo de la compa�ia"}),
  W("Beni te dice: 'Andr� es el forzudo de la compa��a. Su padre era un guerrero o "
    "algo as�. Nunca habla de su madre, pero yo s� que no era orco como su padre. "
    "Es mestizo, y tuvo una infancia dura, el pobre. Es muy fuerte, pero tiene "
    "buen coraz�n.\n"),1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Beni te dice: 'Mi hermano y yo somos equilibristas. Llevamos casi tres a�os "
  "en la compa��a.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Beni te dice: '�sa soy yo, �quer�as algo de m�?'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Beni te dice: 'Es mi hermano.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Beni te dice: 'Es ilusionista y de vez en cuando se saca un sobresueldo "
  "desplumando a pobres incautos en las salas de juego. Todos saben que hace "
  "trampas, pero nadie, jam�s, ha sido capaz de demostrarlo. Es muy bueno. "
  "Una vez intent� propasarse conmigo, pero mi hermano le par� los pies. "
  "Pobre Nikaia, lo que tiene que aguantar...'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Beni te dice: 'Es la esposa de Lattini. Ninguno de nosotros comprendi� "
  "por qu� una lanzadora de cuchillos como ella se iba a casar con semejante "
  "bandarra, pero lo cierto es que ella le quiere con locura. En fin, supongo "
  "que el amor es ciego.'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Beni te dice: 'Es la domadora de fieras de la compa��a. Pr�cticamente se "
  "puede decir que nos adopt� a mi hermano y a m�. Dicen que es fr�a y cruel, "
  "y que s�lo quiere a su pantera, pero yo s� que no es cierto. Lo que pasa "
  "es que los hombres s�lo ven en ella su f�sico, y las mujeres est�n celosas "
  "porque es atractiva. Pero yo s� que en el fondo es muy buena.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Beni te dice: 'Esas lagartas... Se creen que porque bailan delante de los "
  "hombres tienen la exclusiva de la belleza y el erotismo. Una vez que ellas "
  "pidieron cobrar m�s, Baskari les dijo que si no estaban contentas con su "
  "sueldo, pod�an irse porque yo era mejor bailarina que ellas y las podr�a "
  "sustituir perfectamente. Ellas me odian porque saben que es verdad.'\n",1);
  AddQuestion(({"Igart","igart"}),
  "Beni te dice: 'Es la peor de las tres. Yo no s� qu� le ve la gente a una "
  "t�a de casi tres metros moviendo los cuatro brazos como una loca. Creo "
  "que nunca lo entender�.'\n",1);
  AddQuestion(({"Morda","morda"}),
  "Beni te dice: 'Ella dice que es una alta elfa de Lad-Laurelin, pero "
  "yo estoy segura de que es s�lo medio-elfa. �D�nde se ha visto una elfa "
  "con la piel negra?'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Beni te dice: 'Baskari la contrat� por sus ojos rasgados, que le dan un "
  "toque ex�tico. Hay que reconocer que �ltimamente se porta mejor conmigo. "
  "Quiz� se ha dado cuenta de que las otras no son buenas compa��as.'\n",1);
  AddQuestion(({"Baskari","baskari","se�or Baskari","se�or baskari",
                "senyor Baskari","senyor baskari"}),
  "Beni te dice: 'Fue una suerte que el se�or Baskari nos aceptara hace tres "
  "a�os, pues est�bamos en la miseria. Le estamos muy agradecidos, porque nos "
  "proporcion� casa y comida. Sin �l nos hubi�ramos muerto de hambre.'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                  "Madamme nileki","madamme nileki"}),
  "Beni te dice: 'Es la esposa del se�or Baskari. Se port� muy bien con "
  "nosotros cuando llegamos. No te creas lo que dicen por ah� de que es "
  "una farsante. Si quiere, puede hacer prodigios incre�bles, y sabe "
  "leer el futuro, te lo digo yo.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  W("Beni te dice: 'Son los payasos de la compa��a. A algunos les caen simp�ticos, "
    "pero la verdad es que son unos impresentables, siempre bebiendo y gastando "
    "bromas pesadas. M�s de una vez nos han echado de alg�n pueblo por culpa "
    "de sus estupideces. Todav�a recuerdo cuando le echaron grasa a mi cuerda "
    "floja. Menos mal que todav�a no hab�a empezado a hacer el ejercicio sin red. "
    "�Casi me mato!'\n"),1);
  AddQuestion(({"Binky","binky"}),
  "Beni te dice: 'El mayor de los hermanos Kutiri. Y el peor.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Beni te dice: 'Uno de los hermanos Kutiri. No se ha lavado en su vida.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  W("Beni te dice: 'Uno de los hermanos Kutiri. Dice que es inventor, pero todav�a "
    "no ha hecho nada �til, que yo sepa.'\n"),1);
  AddQuestion(({"Tinky","Tinky"}),
 "Beni te dice: 'Uno de los hermanos Kutiri. El muy ladr�n me rob� el traje "
 "y tuve que salir a la pista con uno de Madamme Nileki. Qu� verg�enza.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Beni te dice: 'Uno de los hermanos Kutiri. Para m� que no es hijo del mismo "
  "padre que los otros...'\n",1);
}
