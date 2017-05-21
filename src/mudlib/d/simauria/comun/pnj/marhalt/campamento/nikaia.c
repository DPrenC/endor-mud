/* nikaia.c
  La esposa del Gran Lattini.
  Te dará la espada de André a cambio de otra parecida.
  [n] nemesis@simauria

  Creación: 04-Dic-2001 02:47:05 CET
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
   "Nikaia dice: 'Qué felicidad haber recuperado mi daga. Qué injusta fui.'\n",
   "Nikaia suspira: '¿Por qué me tienes que hacer sufrir así?'\n",
   "Nikaia lanza unos cuchillos contra una diana con forma de silueta humana.\n",
   "Nikaia juguetea con unos cuchillos.\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"espada"}),
  "Nikaia te dice: '¿Espada? ¿Qué espada? Mi colección de espadas es muy "
  "numerosa. Tengo muchas espadas procedentes de todo el mundo, forjadas por "
  "los artesanos más famosos de la historia. Las armas blancas son mi gran "
  "pasión desde pequeña. Como no puedo ir a la guerra, me dediqué a estudiarlas "
  "y a coleccionarlas.'\n",1);
  AddQuestion(({"espada de André","espada de André"}),
  "Nikaia te dice: 'Ah, te refieres a esa espada. Mi marido se la ganó "
  "legalmente. Es una espada muy valiosa, ese tonto no sabía apreciarla "
  "en lo que vale. Fue forjada hace siglos por el artesano orco más famoso: "
  "Ontarmur. Siento mucho no poder dártela, pero no creo que nunca tenga la "
  "oportunidad de conseguir otra igual. Claro, que si me consiguieras otra "
  "espada parecida, no me importaría devolvérsela a André...'\n");
  AddQuestion(({"Ontarmur","ontarmur","artesano orco","artesano"}),
  W("Nikaia te dice: 'Ontarmur es famoso principalmente porque sólo usaba el "
  "adamantio para forjar sus espadas, lo que las hacía prácticamente eternas. "
  "Son muy raras, y cuando alguien consigue una no se deshace fácilmente de "
  "ella. Si quieres que te dé la espada de André, tendrías que traerme otra "
  "espada Ontarmur a cambio.'\n"),1);
  AddQuestion(({"ocho y media","cartas","partida","8 y media",
                "partida con André","partida con andré","partida con Andre",
                "partida con andre"}),
  "Nikaia te dice: 'Mi marido le ganó a André su espada legalmente. Es cierto "
  "que no me gusta que juegue, y mucho menos que beba, pero cuando vi que lo "
  "hizo por complacerme le perdoné enseguida. Sólo vive para hacerme feliz.'\n",1);
// Info sobre los miembros de la compañía
  AddQuestion(({"André","Andre","andré","andre","forzudo",
                "forzudo de la compañía"}),
  "Nikaia te dice: 'Es el forzudo de la compañía. Es bastante buena persona, "
  "aunque lo suyo no es pensar. Baskari se aprovecha de su fuerza organizando "
  "combates de lucha libre en los que los pobres incautos no tienen ninguna "
  "posibilidad.'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Nikaia te dice: 'Los gemelos Trassi son equilibristas, y bastante buenos. "
  "Desde que se unieron a la compañía nuestros ingresos han aumentado bastante. "
  "Mi marido no les cae bien por alguna razón, pero creo que a mí me tienen "
  "bastante aprecio. Es una pena que se relacionen con Lady Morkobva.'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Nikaia te dice: 'Es muy amable conmigo, y viene algunas veces a charlar "
  "y a hacerme compañía cuando mi marido sale por ahí con Baskari a hacer "
  "algún negocio.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Nikaia te dice: 'No es tan simpático como su hermana, pero es buen chico. "
  "Supongo que haber tenido que cuidar de su hermana desde que su madre les "
  "abandonó le hace más desconfiado de lo normal.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Nikaia te dice: 'Mi adorado marido. Es un hombre encantador al que quiero "
  "con locura. No sé qué haría si alguna vez me abandonase. Todas están "
  "celosas porque se casó conmigo, especialmente esa lagarta de Lady Morkobva, "
  "que no le deja ni a sol ni a sombra.'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Nikaia te dice: 'Ésa soy yo: ¿querías algo de mí?'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Nikaia te dice: 'Esa maldita devoradora de hombres va siempre por ahí, "
  "exhibiéndose y provocando a los hombres. Sé que va detrás de mi marido, pero "
  "como algún día la pille va a saber lo que es bueno...'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Nikaia te dice: 'Son las bailarinas exóticas de la compañía. Baskari las "
  "contrató para que atrajeran a los hombres con sus bailes. Son unas descaradas "
  "que van detrás de mi Lattini. Pero no tienen nada que hacer. Él sólo me "
  "quiere a mí.'\n",1);
  AddQuestion(({"Igart","igart"}),
  W("Nikaia te dice:' ¿Una kainoak bailarina? Pues sí, Igart baila. Y tengo que "
    "reconocer que no lo hace mal. Pero mi Lattini no tiene ojos más que para mí.'\n"),1);
  AddQuestion(({"Morda","morda"}),
  W("Nikaia te dice: 'Es la peor de las tres. Es una desvergonzada, parece mentira "
    "que sea una elfa. Los elfos no se comportan así. Claro que, nadie dijo que "
    "fuera elfa... Es ella la única que lo asegura.'\n"),1);
  AddQuestion(({"Kwailin","kwailin"}),
  W("Nikaia te dice: 'Hay que reconocer que últimamente se ha vuelto más recatada. "
    "Creo que se ha dado cuenta de que con la actitud de sus compañeras no va a "
    "llegar a ninguna parte. Bueno, sí, pero no en esta compañía. Además, creo "
    "que ella y Mossi se han enamorado.' Nikaia suspira y añade: '¿No es bonito el amor?'\n"),1);
  AddQuestion(({"Baskari","baskari"}),
  "Nikaia te dice: 'Nuestro jefe. Un auténtico bribón, pero de vez en cuando "
  "tiene buen corazón, como cuando recogió a Beni y a Mossi. Claro que él dice "
  "que sólo vió en ellos una manera de aumentar los beneficios...'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),
  "Nikaia te dice: 'Es una mujer misteriosa. Creo que es la única amiga que "
  "tengo en el grupo. Supongo que al estar casadas nos comprendemos mejor. "
  "Puede ver el futuro y tiene poder sobre las mentes de los otros. Por suerte "
  "sólo utiliza sus habilidades para ayudar a los que realmente lo necesitan.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Nikaia te dice: 'Malditos kenders. Son una auténtica pesadilla. Creo que "
  "Baskari sólo los mantiene porque dan buenos dividendos. Como payasos no "
  "tienen rival, pero algunas veces sus bromas son muy pesadas. No saben "
  "cuándo termina el espectáculo y empieza la vida.'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Nikaia te dice: 'El mayor de los hermanos Kutiri. Una vez reventó la "
  "actuación de mi marido.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Nikaia te dice: 'Uno de los hermanos Kutiri. Una vez, casi vamos a la cárcel "
  "por culpa de sus tonterías.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  W("Nikaia te dice: 'Uno de los hermanos Kutiri. Le cortó el bigote a mi marido. "
  "La verdad es que estaba graciosísimo, pero en aquella ocasión perdió los "
  "estribos. Temí que hiciera una barbaridad, sobre todo cuando cogió una de "
  "mis espadas... Menos mal que Baskari pudo tranquilizarle.'\n"),1);
  AddQuestion(({"Tinky","Tinky"}),
 "Nikaia te dice: 'Uno de los hermanos Kutiri. Siempre está robando cosas. "
 "Seguro que fue él el que robó mi daga.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  W("Nikaia te dice: 'Uno de los hermanos Kutiri. El maldito cerdo... Por su culpa "
    "una vez me quedé desnuda delante del público. Tuvo suerte de no estar a la "
    "vista. Le habría clavado todos mis cuchillos en su cuerpo contrahecho...\n"),1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Nikaia examina cuidadosamente la espada. Al cabo de un rato, sus ojos "
 "se abren y exclama: '¡Un alfanje Ontarmur! ¡Sólo hay tres en el mundo! "
 "¡Muchísimas gracias! Creo que te puedo dar la espada de André a cambio. "
 "Al fin y al cabo, mi marido se la puede volver a ganar cuando quiera.' "
 "Nikaia sonríe maliciosamente y te entrega la espada con un guiño.\n");
 // Texto que te da las demás veces que lo resuelvas
 SetAgainText(
 "Nikaia examina cuidadosamente la espada y te dice: "
 "'Una vulgar imitación, pero muy buena. Creo que la guardaré.'\n");

 // SetQuest:
 // Quest: sangorquest; subquest: nikaia;
 // Las tres últimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","nikaia",({"nikaia_sword"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/andre_sword");
}
