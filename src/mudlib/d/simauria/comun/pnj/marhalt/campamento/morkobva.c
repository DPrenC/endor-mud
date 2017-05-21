/* morkobva.c
  Domadora de fieras. Excitante elfa oscura.
  Quiere recuperar un l�tigo al que tiene mucho cari�o.
  A cambio te dar� un mech�n de pelos de pantera para que se lo des a Nileki.
  [n] nemesis@simauria

  Creaci�n: 04-Dic-2001 15:23:18 CET
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit "std/questnpc";

// Funciones para responder a las preguntas...
// En principio no es como Lattini... aunque podr�a serlo

private string answ_pelos() {
 if(!TI->Query("know_hair"))
  return W("Lady Morkobva se r�e y te dice: '�Para qu� quieres pelos de mi pantera? "
           "Si quieres puedo abrirte la puerta y dejar que los cojas t�. Pero "
           "ser� justo advertirte que del �ltimo que estuvo a solas con ella "
           "s�lo conseguimos recuperar un dedo a medio masticar...'\n");
 else {
  TI->Set("told_story",1);
  return W("Ante la actitud de Lady Morkobva, le explicas lo que te ha dicho Nileki. "
           "Lady Morkobva se queda pensativa un momento y finalmente te dice: "
           "'Si de verdad Nileki lo necesita tanto, te dar� un poco con gusto, pero "
           "primero necesito recuperar mi l�tigo. Mi gatita no estar� tranquila si "
           "no ve que lo llevo conmigo.'\n");
 }
}

private string answ_latigo() {
 if(!TI->Query("told_story"))
  return W("Lady Morkobva te dice: 'Me han robado mi l�tigo favorito. Si agarro al "
           "culpable voy a serv�rselo como primer plato a mi gatita.'\n");
 else {
  TI->Set("asked_whip",1);
  return W("Lady Morkobva te dice: 'Alguien me ha robado mi l�tigo favorito. "
           "Lo utilizo desde que empec� mi carrera. Lo malo es que mi pantera se ha "
           "acostumbrado a �l, y no me podr� acercar a ella con nada afilado si no lo "
           "llevo conmigo. Es un animal tranquilo, pero las cosas met�licas la asustan.'\n");
 }
}

private string answ_robo() {
  if(!TI->Query("asked_whip"))
  return W("Lady Morkobva te dice: 'S�, me han robado, pero no s� por qu� tendr�a "
           "que responder a tus preguntas...'\n");
  else return W("Lady Morkobva te dice: 'En un principio sospech� de los gemelos Trassi, "
                "porque encontr� una lentejuela igual que las del traje de Beni, "
                "pero en seguida me di cuenta de que ellos no pod�an haber sido. Pobre "
                "Beni. Se ech� a llorar en mis brazos jurando que era inocente. Me sent� "
                "muy mal por haberla acusado.'\n");
}

private string answ_self() {
 if(TI->QueryGender() == GENERO_MASCULINO)
  return W("Lady Morkobva te mira con desprecio y dice: '�Otro "+TI->QueryRace()+" deslumbrado por mi belleza "
           "que quiere llevarme lejos de aqu�? �Ah, no? Mejor que sea as�. No soporto a los "
           "que intentan impresionarme con sus supuestos \"encantos masculinos\"'.\n");
 else return "Lady Morkobva te dice: '�sa soy yo, �quer�as algo de m�?'\n";
}

private string answ_lattini() {
 if(TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'Es un aut�ntico cerdo, como todos los hombres. Lo �nico "
           "que sabe hacer bien es jugar, beber y perseguir a cualquier cosa que lleve "
           "faldas, aunque sea una mesa camilla. Lo malo es que algunas le encuentran "
           "irresistible. Pero que le pregunten a Morda qu� sac� finalmente. Mi consejo, "
           "querida, es que te mantengas lejos de �l si puedes evitarlo, y que no te "
           "creas una palabra de lo que te diga.'\n");
 else return W("Lady Morkobva te dice: 'Es un aut�ntico cerdo. Lo �nico que sabe hacer bien "
               "es jugar, beber y perseguir a cualquier cosa que lleve faldas, aunque sea "
               "una mesa camilla. Sin �nimo de ofender... todos sois iguales.'\n");
}


private string answ_beni() {
 if(TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'La quiero como a una hija. Es tan dulce... Por eso "
           "tengo que protegerla de gente como Lattini. No quiero que ella sufra por "
           "culpa de los hombres como yo sufr�...'\n");
 else return W("Lady Morkobva mira duramente y te dice con voz ronca: 'Si intentas "
               "hacerle algo, mi pantera comer� criadillas de "+TI->QueryRace()+" esta noche...'\n");
}

private string answ_nikaia() {
 if(TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'Nikaia es la esposa de Lattini. S�, ese cerdo "
           "est� casado. Para que veas que algunas le encuentran irresistible. "
           "Por desgracia, en el pecado llev� la penitencia, porque Lattini le es "
           "infiel siempre que puede, y eso que ella es muy celosa y si alg�n d�a "
           "lo pilla, le cortar� lo que le cuelga... Pero ella cree que la culpa es "
           "nuestra, que nosotras le acosamos. Por eso yo no le caigo bien. Si ella "
           "supiera la verdad... en el fondo la compadezco.'\n");
 else return W("Lady Morkobva te dice: 'Nikaia es la esposa de Lattini. �No se da "
               "cuenta de que todos sois unos cerdos?'\n");
}

private string answ_morda() {
 if(TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'Pobre Morda. En el fondo me da pena. Lattini la "
           "sedujo, prometi�ndole que se ir�an juntos, y que aprovechar�a los "
           "contactos que dice que tiene en el mundo art�stico para conseguirle "
           "un contrato en Ishtria... Pero cuando consigui� lo que quiso, simplemente "
           "la dej� tirada.'\n");
 else return W("Lady Morkobva te dice: 'Claro, todos quer�is saber m�s sobre ella, "
               "os parece excitante s�lo porque es negra �no? No pienso decirle nada a un "
               "degenerado como t�.'\n");
}


private string answ_kwailin() {
 if(TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'Lo cierto es que esta chica ha cambiado de un tiempo a "
           "esta parte. Durante un tiempo se comportaba como sus compa�eras, incluso "
           "dicen que coquete� con Lattini. Pero desde hace unos meses ha cambiado. Ya ni "
           "siquiera parece gustarle su trabajo. Hace unos d�as Mossi me cont� que "
           "est�n enamorados y quieren casarse. La verdad es que me alegro por "
           "ella. Mossi es un buen muchacho y sabr� hacerla feliz.'\n");
 else return W("Lady Morkobva te dice fr�amente: 'Lo siento, no tienes ninguna posibilidad. Est� enamorada "
               "de Mossi.'\n");
}

private string answ_baskari() {
 if(TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'Es nuestro jefe. Como todos los dem�s de su g�nero, "
           "no es muy de fiar, pero es honrado a su manera. Eso s�, vender�a a su madre "
           "si con ello sacase dinero. Por suerte, Nileki sabe paliar esa vena "
           "de estafador que tienen todos los artistas ambulantes...'\n");
 else return W("Lady Morkobva te dice: 'Es nuestro jefe. No es que sea completamente "
               "honrado (es un hombre), pero sabe mantener su palabra, y de vez "
               "en cuando hasta tiene buen coraz�n...'\n");
}

private string answ_nileki() {
 if(!TI->Query("asked_about_potion"))
  return W("Lady Morkobva te dice: 'La esposa de Baskari. Experta en pociones y en sortilegios. "
           "Esto lo sabe muy bien Baskari, que se cuida mucho de no hacer nada que pueda molestarle.'\n");
 else return W("Lady Morkobva te dice: 'Si Nileki necesita mi ayuda, estar� encantada "
               "de ayudarla, pero primero necesito mi l�tigo.'\n");
}

private string answ_binky() {
 if(!TI->QueryGender() == GENERO_FEMENINO)
  return W("Lady Morkobva te dice: 'Para que veas lo de fiar que son los hombres, "
           "ese... ese maldito peque�ajo se col� en mi carromato mientras me estaba "
           "cambiando. Suerte que llevo un l�tigo siempre conmigo y se llev� lo suyo.'\n");
 else return W("Lady Morkobva te dice: 'El mayor de los hermanos Kutiri. Ha intentado "
               "colarse en mi carromato para verme desnuda muchas veces. La �ltima le dej� mi l�tigo "
               "marcado en la frente. Espero que eso le ense�e.'\n");
}

// Finalmente, la descripci�n cambia dependiendo del sexo de quien la mire...
QueryLong() {
 if(TP->QueryGender() == GENERO_MASCULINO)
  return W("Es una bell�sima elfa oscura de larga melena negra y piel blanqu�sima. "
          "Sus hermosos ojos grises parecen mirarte con desprecio, mientras "
          "sus labios carnosos esbozan una sonrisa desde�osa. Bajo un traje "
          "ajustado de cuero negro se adivinan unas formas hechas para llevar "
          "a los hombres a la locura.\n");
 else return W("Es una bella elfa oscura de piel blanca y cabellos negros. "
               "Tras sus misteriosos ojos grises parece ocultarse una sombra "
               "de dolor y amargura, que se traducen en un car�cter "
               "m�s bien �spero.\n");
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
  AddQuestion(({"l�tigo","latigo","tu l�tigo","tu latigo"}),SF(answ_latigo),1);
  AddQuestion(({"pelo de pantera","pelos de pantera"}),
              SF(answ_pelos),1);
  AddQuestion(({"robo","sospechosos"}),SF(answ_robo),1);
// Info sobre los miembros de la compa��a
  AddQuestion(({"Andr�","Andre","andr�","andre","forzudo",
                "forzudo de la compa��a"}),
  "Lady Morkobva te dice: 'No hay mucho que decir, tan musculoso como poco "
  "inteligente. Por lo menos no va por ah� babeando detr�s de m�, como otros "
  "que yo me s�...'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Lady Morkobva te dice: 'Pobrecillos. Su madre les abandon� cuando eran muy "
  "peque�os y tuvieron que ganarse la vida como artistas ambulantes. Por suerte "
  "Baskari tiene coraz�n en algunas ocasiones y les recogi�. Eso s�, les hizo "
  "comprarse su propio carro, as� que mientras tanto vivieron en el m�o. Creo "
  "que me consideran la madre que nunca tuvieron. Y para m� ellos son como mis "
  "hijos. Si alguien les intentara hacer da�o...'\n",1);
  AddQuestion(({"Beni","beni"}), SF(answ_beni),1);
  AddQuestion(({"Mossi","mossi"}),
  "Lady Morkobva te dice: Un buen muchacho. Quiere con locura a su hermana y "
  "s� que ha tenido un encontronazo con Lattini. Me alegro. Ese Lattini se va "
  "a llevar una sorpresa desagradable un d�a, te lo digo yo...\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),SF(answ_lattini),1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
                SF(answ_nikaia),1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),SF(answ_self),1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Lady Morkobva te dice: Bailarinas ex�ticas... �ja! Esas tres desvergonzadas "
  "s�lo est�n aqu� para atraer a los hombres con esos trajes min�sculos con los "
  "que act�an. Por supuesto, objetivo n�mero uno para el cerdo de Lattini... "
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
  "Lady Morkobva te dice: 'Esos kenders son una aut�ntica pesadilla. De vez en "
  "cuando son simp�ticos, pero la mayor�a de las veces son insoportables. A ver "
  "si Baskari se decide a echarles de una vez...'\n",1);
  AddQuestion(({"Binky","binky"}),SF(answ_binky),1);
  AddQuestion(({"Dinky","dinky"}),
  "Lady Morkobva te dice: 'El m�s cerdo de los hermanos Kutiri.'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  W("Lady Morkobva te dice: 'Supongo que es la \"rama t�cnica\" de la familia Kutiri.'\n"),1);
  AddQuestion(({"Tinky","Tinky"}),
 W("Lady Morkobva te dice: 'Una vez rob� unos trozos de una botella rota... No s� "
   "para qu� podr�a quererlos...'\n"),1);
  AddQuestion(({"Clyde","clyde"}),
  W("Lady Morkobva te dice: 'Nunca he comprendido por qu� le pusieron ese est�pido "
    "nombre. Pero supongo que con los kenders la l�gica est� de m�s...'\n"),1);

 // Funciones propias del QuestNPC...
 // Texto que te da la primera vez que lo resuelves
 SetHelpText(
 "Lady Morkobva dice: '�Mi l�tigo! Muchas gracias.' "
 "Acto seguido, se dirige a la jaula de su pantera y entra con el l�tigo en "
 "una mano y unas tijeras en la otra. Poco despu�s sale y te entrega unos "
 "pelos del animal.\n");
 // Texto que te da las dem�s veces que lo resuelvas
 SetAgainText("Lady Morkobva te dice: 'Muchas gracias, aunque ya tengo uno igual.'\n");

 // SetQuest:
 // Quest: sangorquest; subquest: lady_m;
 // Las tres �ltimas se ponen a 0 y luego se les da valor...
 SetQuest("sangorquest","lady_m",({"lady_whip"}),0,0,0);
 // OJO: SetReward() NECESITA el path completo, no vale uno relativo
 SetReward("/d/simauria/comun/objeto/otro/sangorquest/pelos");
}
