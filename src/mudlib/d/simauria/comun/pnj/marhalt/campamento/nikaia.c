/* nikaia.c
  La esposa del Gran Lattini.
  Te dar� la espada de Andr� a cambio de otra parecida.
  [n] nemesis@simauria

  Creaci�n: 04-Dic-2001 02:47:05 CET
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit "std/questnpc";

create() {
  ::create();
 SetStandard("Nikaia", "humano", 100, GENERO_FEMENINO);
  SetShort("Nikaia, la lanzadora de cuchillos");
  SetLong("Es una mujer humana alta y esbelta. Tiene una larga melena negra "
          "y ojos del mismo color. Es ciertamente muy hermosa, aunque parece "
          "que ha llorado recientemente.\n");
  AddId(({"Nikaia","nikaia","esposa de Lattini","esposa de lattini",
          "lanzadora de cuchillos"}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "Nikaia dice: 'Qu� felicidad haber recuperado mi daga. Qu� injusta fui.'\n",
   "Nikaia suspira: '�Por qu� me tienes que hacer sufrir as�?'\n",
   "Nikaia lanza unos cuchillos contra una diana con forma de silueta humana.\n",
   "Nikaia juguetea con unos cuchillos.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"espada"}),
  "Nikaia te dice: '�Espada? �Qu� espada? Mi colecci�n de espadas es muy "
  "numerosa. Tengo muchas espadas procedentes de todo el mundo, forjadas por "
  "los artesanos m�s famosos de la historia. Las armas blancas son mi gran "
  "pasi�n desde peque�a. Como no puedo ir a la guerra, me dediqu� a estudiarlas "
  "y a coleccionarlas.'\n",1);
  AddQuestion(({"espada de Andr�","espada de Andr�"}),
  "Nikaia te dice: 'Ah, te refieres a esa espada. Mi marido se la gan� "
  "legalmente. Es una espada muy valiosa, ese tonto no sab�a apreciarla "
  "en lo que vale. Fue forjada hace siglos por el artesano orco m�s famoso: "
  "Ontarmur. Siento mucho no poder d�rtela, pero no creo que nunca tenga la "
  "oportunidad de conseguir otra igual. Claro, que si me consiguieras otra "
  "espada parecida, no me importar�a devolv�rsela a Andr�...'\n");
  AddQuestion(({"Ontarmur","ontarmur","artesano orco","artesano"}),
  W("Nikaia te dice: 'Ontarmur es famoso principalmente porque s�lo usaba el "
  "adamantio para forjar sus espadas, lo que las hac�a pr�cticamente eternas. "
  "Son muy raras, y cuando alguien consigue una no se deshace f�cilmente de "
  "ella. Si quieres que te d� la espada de Andr�, tendr�as que traerme otra "
  "espada Ontarmur a cambio.'\n"),1);
  AddQuestion(({"ocho y media","cartas","partida","8 y media",
                "partida con Andr�","partida con andr�","partida con Andre",
                "partida con andre"}),
  "Nikaia te dice: 'Mi marido le gan� a Andr� su espada legalmente. Es cierto "
  "que no me gusta que juegue, y mucho menos que beba, pero cuando vi que lo "
  "hizo por complacerme le perdon� enseguida. S�lo vive para hacerme feliz.'\n",1);
// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a"}),
  "Nikaia te dice: 'Es el forzudo de la compa��a. Es bastante buena persona, "
  "aunque lo suyo no es pensar. Baskari se aprovecha de su fuerza organizando "
  "combates de lucha libre en los que los pobres incautos no tienen ninguna "
  "posibilidad.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Nikaia te dice: 'Los gemelos Trassi son equilibristas, y bastante buenos. "
  "Desde que se unieron a la compa��a nuestros ingresos han aumentado bastante. "
  "Mi marido no les cae bien por alguna raz�n, pero creo que a m� me tienen "
  "bastante aprecio. Es una pena que se relacionen con Lady Morkobva.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Nikaia te dice: 'Es muy amable conmigo, y viene algunas veces a charlar "
  "y a hacerme compa��a cuando mi marido sale por ah� con Baskari a hacer "
  "alg�n negocio.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Nikaia te dice: 'No es tan simp�tico como su hermana, pero es buen chico. "
  "Supongo que haber tenido que cuidar de su hermana desde que su madre les "
  "abandon� le hace m�s desconfiado de lo normal.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Nikaia te dice: 'Mi adorado marido. Es un hombre encantador al que quiero "
  "con locura. No s� qu� har�a si alguna vez me abandonase. Todas est�n "
  "celosas porque se cas� conmigo, especialmente esa lagarta de Lady Morkobva, "
  "que no le deja ni a sol ni a sombra.'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Nikaia te dice: '�sa soy yo: �quer�as algo de m�?'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Nikaia te dice: 'Esa maldita devoradora de hombres va siempre por ah�, "
  "exhibi�ndose y provocando a los hombres. S� que va detr�s de mi marido, pero "
  "como alg�n d�a la pille va a saber lo que es bueno...'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Nikaia te dice: 'Son las bailarinas ex�ticas de la compa��a. Baskari las "
  "contrat� para que atrajeran a los hombres con sus bailes. Son unas descaradas "
  "que van detr�s de mi Lattini. Pero no tienen nada que hacer. �l s�lo me "
  "quiere a m�.'\n",1);
  AddQuestion(({"Igart","igart"}),
  W("Nikaia te dice:' �Una kainoak bailarina? Pues s�, Igart baila. Y tengo que "
    "reconocer que no lo hace mal. Pero mi Lattini no tiene ojos m�s que para m�.'\n"),1);
  AddQuestion(({"Morda","morda"}),
  W("Nikaia te dice: 'Es la peor de las tres. Es una desvergonzada, parece mentira "
    "que sea una elfa. Los elfos no se comportan as�. Claro que, nadie dijo que "
    "fuera elfa... Es ella la �nica que lo asegura.'\n"),1);
  AddQuestion(({"Kwailin","kwailin"}),
  W("Nikaia te dice: 'Hay que reconocer que �ltimamente se ha vuelto m�s recatada. "
    "Creo que se ha dado cuenta de que con la actitud de sus compa�eras no va a "
    "llegar a ninguna parte. Bueno, s�, pero no en esta compa��a. Adem�s, creo "
    "que ella y Mossi se han enamorado.' Nikaia suspira y a�ade: '�No es bonito el amor?'\n"),1);
  AddQuestion(({"Baskari","baskari"}),
  "Nikaia te dice: 'Nuestro jefe. Un aut�ntico brib�n, pero de vez en cuando "
  "tiene buen coraz�n, como cuando recogi� a Beni y a Mossi. Claro que �l dice "
  "que s�lo vi� en ellos una manera de aumentar los beneficios...'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),
  "Nikaia te dice: 'Es una mujer misteriosa. Creo que es la �nica amiga que "
  "tengo en el grupo. Supongo que al estar casadas nos comprendemos mejor. "
  "Puede ver el futuro y tiene poder sobre las mentes de los otros. Por suerte "
  "s�lo utiliza sus habilidades para ayudar a los que realmente lo necesitan.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Nikaia te dice: 'Malditos kenders. Son una aut�ntica pesadilla. Creo que "
  "Baskari s�lo los mantiene porque dan buenos dividendos. Como payasos no "
  "tienen rival, pero algunas veces sus bromas son muy pesadas. No saben "
  "cu�ndo termina el espect�culo y empieza la vida.'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Nikaia te dice: 'El mayor de los hermanos Kutiri. Una vez revent� la "
  "actuaci�n de mi marido.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Nikaia te dice: 'Uno de los hermanos Kutiri. Una vez, casi vamos a la c�rcel "
  "por culpa de sus tonter�as.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  W("Nikaia te dice: 'Uno de los hermanos Kutiri. Le cort� el bigote a mi marido. "
  "La verdad es que estaba gracios�simo, pero en aquella ocasi�n perdi� los "
  "estribos. Tem� que hiciera una barbaridad, sobre todo cuando cogi� una de "
  "mis espadas... Menos mal que Baskari pudo tranquilizarle.'\n"),1);
  AddQuestion(({"Tinky","Tinky"}),
 "Nikaia te dice: 'Uno de los hermanos Kutiri. Siempre est� robando cosas. "
 "Seguro que fue �l el que rob� mi daga.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  W("Nikaia te dice: 'Uno de los hermanos Kutiri. El maldito cerdo... Por su culpa "
    "una vez me qued� desnuda delante del p�blico. Tuvo suerte de no estar a la "
    "vista. Le habr�a clavado todos mis cuchillos en su cuerpo contrahecho...\n"),1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Nikaia examina cuidadosamente la espada. Al cabo de un rato, sus ojos "
 "se abren y exclama: '�Un alfanje Ontarmur! �S�lo hay tres en el mundo! "
 "�Much�simas gracias! Creo que te puedo dar la espada de Andr� a cambio. "
 "Al fin y al cabo, mi marido se la puede volver a ganar cuando quiera.' "
 "Nikaia sonr�e maliciosamente y te entrega la espada con un gui�o.\n");
 // Texto que te da las dem�s veces que lo resuelvas
 SetAgainText(
 "Nikaia examina cuidadosamente la espada y te dice: "
 "'Una vulgar imitaci�n, pero muy buena. Creo que la guardar�.'\n");

 // SetQuest:
 // Quest: sangorquest; subquest: nikaia;
 // Las tres �ltimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","nikaia",({"nikaia_sword"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/andre_sword");
}
