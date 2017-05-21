/* morkobva.c
  Domadora de fieras. Excitante elfa oscura.
  Quiere recuperar un látigo al que tiene mucho cariño.
  A cambio te dará un mechón de pelos de pantera para que se lo des a Nileki.
  [n] nemesis@simauria

  Creación: 04-Dic-2001 15:23:18 CET
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit "std/questnpc";

// Funciones para responder a las preguntas...
// En principio no es como Lattini... aunque podría serlo

private string answ_pelos() {
 if(!TI->Query("know_hair"))
  return W("Lady Morkobva se ríe y te dice: '¿Para qué quieres pelos de mi pantera? "
           "Si quieres puedo abrirte la puerta y dejar que los cojas tú. Pero "
           "será justo advertirte que del último que estuvo a solas con ella "
           "sólo conseguimos recuperar un dedo a medio masticar...'\n");
 else {
  TI->Set("told_story",1);
  return W("Ante la actitud de Lady Morkobva, le explicas lo que te ha dicho Nileki. "
           "Lady Morkobva se queda pensativa un momento y finalmente te dice: "
           "'Si de verdad Nileki lo necesita tanto, te daré un poco con gusto, pero "
           "primero necesito recuperar mi látigo. Mi gatita no estará tranquila si "
           "no ve que lo llevo conmigo.'\n");
 }
}

private string answ_latigo() {
 if(!TI->Query("told_story"))
  return W("Lady Morkobva te dice: 'Me han robado mi látigo favorito. Si agarro al "
           "culpable voy a servírselo como primer plato a mi gatita.'\n");
 else {
  TI->Set("asked_whip",1);
  return W("Lady Morkobva te dice: 'Alguien me ha robado mi látigo favorito. "
           "Lo utilizo desde que empecé mi carrera. Lo malo es que mi pantera se ha "
           "acostumbrado a él, y no me podré acercar a ella con nada afilado si no lo "
           "llevo conmigo. Es un animal tranquilo, pero las cosas metálicas la asustan.'\n");
 }
}

private string answ_robo() {
  if(!TI->Query("asked_whip"))
  return W("Lady Morkobva te dice: 'Sí, me han robado, pero no sé por qué tendría "
           "que responder a tus preguntas...'\n");
  else return W("Lady Morkobva te dice: 'En un principio sospeché de los gemelos Trassi, "
                "porque encontré una lentejuela igual que las del traje de Beni, "
                "pero en seguida me di cuenta de que ellos no podían haber sido. Pobre "
                "Beni. Se echó a llorar en mis brazos jurando que era inocente. Me sentí "
                "muy mal por haberla acusado.'\n");
}

private string answ_self() {
 if(TI->QueryGender() == GENERO_MASCULINO)
  return W("Lady Morkobva te mira con desprecio y dice: '¿Otro "+TI->QueryRace()+" deslumbrado por mi belleza "
           "que quiere llevarme lejos de aquí? ¿Ah, no? Mejor que sea así. No soporto a los "
           "que intentan impresionarme con sus supuestos \"encantos masculinos\"'.\n");
 else return "Lady Morkobva te dice: 'Ésa soy yo, ¿querías algo de mí?'\n";
}

private string answ_lattini() {
 if(TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'Es un auténtico cerdo, como todos los hombres. Lo único "
           "que sabe hacer bien es jugar, beber y perseguir a cualquier cosa que lleve "
           "faldas, aunque sea una mesa camilla. Lo malo es que algunas le encuentran "
           "irresistible. Pero que le pregunten a Morda qué sacó finalmente. Mi consejo, "
           "querida, es que te mantengas lejos de él si puedes evitarlo, y que no te "
           "creas una palabra de lo que te diga.'\n");
 else return W("Lady Morkobva te dice: 'Es un auténtico cerdo. Lo único que sabe hacer bien "
               "es jugar, beber y perseguir a cualquier cosa que lleve faldas, aunque sea "
               "una mesa camilla. Sin ánimo de ofender... todos sois iguales.'\n");
}


private string answ_beni() {
 if(TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'La quiero como a una hija. Es tan dulce... Por eso "
           "tengo que protegerla de gente como Lattini. No quiero que ella sufra por "
           "culpa de los hombres como yo sufrí...'\n");
 else return W("Lady Morkobva mira duramente y te dice con voz ronca: 'Si intentas "
               "hacerle algo, mi pantera comerá criadillas de "+TI->QueryRace()+" esta noche...'\n");
}

private string answ_nikaia() {
 if(TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'Nikaia es la esposa de Lattini. Sí, ese cerdo "
           "está casado. Para que veas que algunas le encuentran irresistible. "
           "Por desgracia, en el pecado llevó la penitencia, porque Lattini le es "
           "infiel siempre que puede, y eso que ella es muy celosa y si algún día "
           "lo pilla, le cortará lo que le cuelga... Pero ella cree que la culpa es "
           "nuestra, que nosotras le acosamos. Por eso yo no le caigo bien. Si ella "
           "supiera la verdad... en el fondo la compadezco.'\n");
 else return W("Lady Morkobva te dice: 'Nikaia es la esposa de Lattini. ¿No se da "
               "cuenta de que todos sois unos cerdos?'\n");
}

private string answ_morda() {
 if(TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'Pobre Morda. En el fondo me da pena. Lattini la "
           "sedujo, prometiéndole que se irían juntos, y que aprovecharía los "
           "contactos que dice que tiene en el mundo artístico para conseguirle "
           "un contrato en Ishtria... Pero cuando consiguió lo que quiso, simplemente "
           "la dejó tirada.'\n");
 else return W("Lady Morkobva te dice: 'Claro, todos queréis saber más sobre ella, "
               "os parece excitante sólo porque es negra ¿no? No pienso decirle nada a un "
               "degenerado como tú.'\n");
}


private string answ_kwailin() {
 if(TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'Lo cierto es que esta chica ha cambiado de un tiempo a "
           "esta parte. Durante un tiempo se comportaba como sus compañeras, incluso "
           "dicen que coqueteó con Lattini. Pero desde hace unos meses ha cambiado. Ya ni "
           "siquiera parece gustarle su trabajo. Hace unos días Mossi me contó que "
           "están enamorados y quieren casarse. La verdad es que me alegro por "
           "ella. Mossi es un buen muchacho y sabrá hacerla feliz.'\n");
 else return W("Lady Morkobva te dice fríamente: 'Lo siento, no tienes ninguna posibilidad. Está enamorada "
               "de Mossi.'\n");
}

private string answ_baskari() {
 if(TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'Es nuestro jefe. Como todos los demás de su género, "
           "no es muy de fiar, pero es honrado a su manera. Eso sí, vendería a su madre "
           "si con ello sacase dinero. Por suerte, Nileki sabe paliar esa vena "
           "de estafador que tienen todos los artistas ambulantes...'\n");
 else return W("Lady Morkobva te dice: 'Es nuestro jefe. No es que sea completamente "
               "honrado (es un hombre), pero sabe mantener su palabra, y de vez "
               "en cuando hasta tiene buen corazón...'\n");
}

private string answ_nileki() {
 if(!TI->Query("asked_about_potion"))
  return W("Lady Morkobva te dice: 'La esposa de Baskari. Experta en pociones y en sortilegios. "
           "Esto lo sabe muy bien Baskari, que se cuida mucho de no hacer nada que pueda molestarle.'\n");
 else return W("Lady Morkobva te dice: 'Si Nileki necesita mi ayuda, estaré encantada "
               "de ayudarla, pero primero necesito mi látigo.'\n");
}

private string answ_binky() {
 if(!TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'Para que veas lo de fiar que son los hombres, "
           "ese... ese maldito pequeñajo se coló en mi carromato mientras me estaba "
           "cambiando. Suerte que llevo un látigo siempre conmigo y se llevó lo suyo.'\n");
 else return W("Lady Morkobva te dice: 'El mayor de los hermanos Kutiri. Ha intentado "
               "colarse en mi carromato para verme desnuda muchas veces. La última le dejé mi látigo "
               "marcado en la frente. Espero que eso le enseñe.'\n");
}

// Finalmente, la descripción cambia dependiendo del sexo de quien la mire...
QueryLong() {
 if(TP->QueryGender() == GENERO_MASCULINO)
  return W("Es una bellísima elfa oscura de larga melena negra y piel blanquísima. "
          "Sus hermosos ojos grises parecen mirarte con desprecio, mientras "
          "sus labios carnosos esbozan una sonrisa desdeñosa. Bajo un traje "
          "ajustado de cuero negro se adivinan unas formas hechas para llevar "
          "a los hombres a la locura.\n");
 else return W("Es una bella elfa oscura de piel blanca y cabellos negros. "
               "Tras sus misteriosos ojos grises parece ocultarse una sombra "
               "de dolor y amargura, que se traducen en un carácter "
               "más bien áspero.\n");
}

// create
create() {
  ::create();
 SetStandard("Lady Morkobva", "elfo-oscuro", 100, GENERO_FEMENINO);
  SetShort("Lady Morkobva, la domadora de fieras");
  AddId(({"Lady Morkobva","lady Morkobva","lady morkobva","Morkobva","morkobva",
          "domadora","domadora de fieras"}));
  SetMaxHP(3000);
  SetHP(3000);
  SetAlign(400);
  InitChats(5,({
   "Lady Morkobva mete la mano entre los barrotes y acaricia a su pantera.\n",
   "Lady Morkobva dice: Si cojo al culpable se va a acordar de Lady Morkobva.\n",
   "Lady Morkobva dice: Seguro que ha sido el cerdo de Lattini.\n",
   "Lady Morkobva dice: Intentar culpar a esos pobrecillos. Hace falta ser...\n"
  }));
  // Questions... Laaarga lista...
  AddQuestion(({"látigo","latigo","tu látigo","tu latigo"}),SF(answ_latigo),1);
  AddQuestion(({"pelo de pantera","pelos de pantera"}),
              SF(answ_pelos),1);
  AddQuestion(({"robo","sospechosos"}),SF(answ_robo),1);
// Info sobre los miembros de la compañía
  AddQuestion(({"André","Andre","andré","andre","forzudo",
                "forzudo de la compañía"}),
  "Lady Morkobva te dice: 'No hay mucho que decir, tan musculoso como poco "
  "inteligente. Por lo menos no va por ahí babeando detrás de mí, como otros "
  "que yo me sé...'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Lady Morkobva te dice: 'Pobrecillos. Su madre les abandonó cuando eran muy "
  "pequeños y tuvieron que ganarse la vida como artistas ambulantes. Por suerte "
  "Baskari tiene corazón en algunas ocasiones y les recogió. Eso sí, les hizo "
  "comprarse su propio carro, así que mientras tanto vivieron en el mío. Creo "
  "que me consideran la madre que nunca tuvieron. Y para mí ellos son como mis "
  "hijos. Si alguien les intentara hacer daño...'\n",1);
  AddQuestion(({"Beni","beni"}), SF(answ_beni),1);
  AddQuestion(({"Mossi","mossi"}),
  "Lady Morkobva te dice: Un buen muchacho. Quiere con locura a su hermana y "
  "sé que ha tenido un encontronazo con Lattini. Me alegro. Ese Lattini se va "
  "a llevar una sorpresa desagradable un día, te lo digo yo...\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),SF(answ_lattini),1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
                SF(answ_nikaia),1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),SF(answ_self),1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Lady Morkobva te dice: Bailarinas exóticas... ¡ja! Esas tres desvergonzadas "
  "sólo están aquí para atraer a los hombres con esos trajes minúsculos con los "
  "que actúan. Por supuesto, objetivo número uno para el cerdo de Lattini... "
  "y creo que conseguido, aunque te parezca mentira.\n",1);
  AddQuestion(({"Igart","igart"}),
  "Lady Morkobva te dice: Una kainoak bailando... vivir para ver...\n",1);
  AddQuestion(({"Morda","morda"}),SF(answ_morda),1);
  AddQuestion(({"Kwailin","kwailin"}),SF(answ_kwailin),1);
  AddQuestion(({"Baskari","baskari"}),SF(answ_baskari),1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                "Madamme nileki","madamme nileki"}),SF(answ_nileki),1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Lady Morkobva te dice: 'Esos kenders son una auténtica pesadilla. De vez en "
  "cuando son simpáticos, pero la mayoría de las veces son insoportables. A ver "
  "si Baskari se decide a echarles de una vez...'\n",1);
  AddQuestion(({"Binky","binky"}),SF(answ_binky),1);
  AddQuestion(({"Dinky","dinky"}),
  "Lady Morkobva te dice: 'El más cerdo de los hermanos Kutiri.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  W("Lady Morkobva te dice: 'Supongo que es la \"rama técnica\" de la familia Kutiri.'\n"),1);
  AddQuestion(({"Tinky","Tinky"}),
 W("Lady Morkobva te dice: 'Una vez robó unos trozos de una botella rota... No sé "
   "para qué podría quererlos...'\n"),1);
  AddQuestion(({"Clyde","clyde"}),
  W("Lady Morkobva te dice: 'Nunca he comprendido por qué le pusieron ese estúpido "
    "nombre. Pero supongo que con los kenders la lógica está de más...'\n"),1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Lady Morkobva dice: '¡Mi látigo! Muchas gracias.' "
 "Acto seguido, se dirige a la jaula de su pantera y entra con el látigo en "
 "una mano y unas tijeras en la otra. Poco después sale y te entrega unos "
 "pelos del animal.\n");
 // Texto que te da las demás veces que lo resuelvas
 SetAgainText("Lady Morkobva te dice: 'Muchas gracias, aunque ya tengo uno igual.'\n");

 // SetQuest:
 // Quest: sangorquest; subquest: lady_m;
 // Las tres últimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","lady_m",({"lady_whip"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/pelos");
}
