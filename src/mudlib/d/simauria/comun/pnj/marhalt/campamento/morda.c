/* morda.c
  Bailarina elfa.
  Tiene informaci�n relativa al caso del l�tigo desaparecido.
  [n] nemesis@simauria

  Creaci�n: 05-Dic-2001 01:15:17 CET (joer, 1 pnj/h, vaya media...)
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit NPC;

private string answ_robo() {
 if(TP->Query("beni_acusa"))
  return W("Le cuentas a Morda lo que Beni te ha contado sobre el robo del l�tigo "
           "de Lady Morkobva. La sonrisa se borra de su cara y te dice: '�Esa "
           "renacuaja de Beni te ha dicho eso? Pues ya le puedes decir que "
           "nosotras no somos tan rastreras. Adem�s, si quisi�ramos hacerle algo "
           "a ella o a su hermanito, lo har�amos cara a cara. Le puedes decir "
           "que si quiere hacer alguna acusaci�n, que nos lo diga a la cara. "
           "Entonces ajustaremos cuentas.'\n");
  else return "Morda te dice: 'No s� de qu� carajo me hablas.'\n";
}

private string answ_self() {
 if(TI->QueryGender() == GENERO_MASCULINO)
  return "Morda te dice insinuante: '�sa soy yo. �Qu� deseas, cari�o?'\n";
 else return "Morda te dice: '�sa soy yo. �Quieres algo?'\n";
}

// create
create() {
  ::create();
 SetStandard("Morda", "elfo", 100, GENERO_FEMENINO);
  SetShort("Morda, una bailarina");
  SetLong("A pesar de que Morda tiene todos los rasgos de un elfo, te llama "
          "la atenci�n que su piel tiene un hermoso tono canela y sus cabellos "
          "son de color azabache. Eso s�, tiene los hermosos ojos azules de "
          "su raza. Sabes que hay casos de medio-elfos mulatos, pero Morda "
          "parece demasiado �lfica para serlo s�lo a medias.\n");
  // En la habitaci�n habr� un AddDetail tal que as�n:
  // AddDetail(({"bailarina ex�tica","bailarina exotica","bailarina"}),
  //           "�Cu�l de las tres?");
  AddId(({"Morda","morda","bailarina elfa","elfa negra","elfa mulata"}));
  SetAlign(400);
  InitChats(5,({
   "Morda les dice a sus compa�eras: 'Ensayemos los pasos del nuevo n�mero.'\n",
   "Morda inicia una sensual danza mientras sus compa�eras dan palmas.\n",
   "Morda mira a Kwailin, le dice algo a Igart al o�do y las dos sueltan una "
   "risita.\n",
   "Igart, Kwailin y Morda te miran y cuchichean algo entre ellas. Luego "
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
  "Morda te dice: 'Es el forzudo de la compa��a. Una mole de m�sculos. Creo "
  "que le hace til�n a Igart. Creo que har�an buena pareja... Es el "
  "ejemplar masculino m�s grande que hay por aqu�...'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Morda te dice: 'Unos pobres muertos de hambre a los que recogimos cuando "
  "estaban mendigando por las calles y a los que dimos un hogar. Y se han "
  "vuelto unos estirados que se creen superiores a todos. Claro que no me "
  "extra�a, si se juntan con esa maldita elfa-oscura...'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Morda te dice: 'Una ni�ata estirada que se cree que porque Baskari hizo "
  "una vez un comentario sobre lo bien que baila, puede pisotearnos a las "
  "dem�s. Esa est�pida ser�a incapaz de dar un paso si tuviera el p�blico "
  "que nosotras tenemos. Eso sin contar con que el salvaje de su hermano "
  "no se lo permitir�a.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Morda te dice: 'El hermano de esa engre�da de Beni. Con la excusa de que "
  "tiene que ser el padre que ella no tuvo, se cree con derecho a decirle "
  "a su hermana lo que tiene y no tiene que hacer. Y a quitar de enmedio "
  "a quienes se opongan. Si no fuera por �l, ella ser�a hasta simp�tica.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Morda te dice: 'Es un cerdo. Me sedujo prometi�ndome que dejar�a a su "
  "mujer y nos ir�amos juntos, que �l conoc�a a mucha gente en Ishtria, "
  "que estaba desperdiciando mi talento en ferias de mala muerte... Y luego "
  "si te he visto no me acuerdo... Me abandon� para ir detr�s de esa Lady "
  "Morkobva... Espero que esa elfa-oscura demuestre m�s sentido que yo y "
  "le deje la cara marcada de un latigazo.'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Morda te dice: 'La esposa de Lattini. Hubo un tiempo en que la odi�, "
  "pero ahora s�lo puedo sentir l�stima por ella. Adora a su marido y "
  "ser�a capaz de cualquier barbaridad si se enterase de c�mo es en "
  "realidad... Es la �nica raz�n por la que todas guardamos silencio.'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Morda te dice: ��sa? �Qu� puedo decir de ella? Se disfraza de mujer, y va "
  "provocando a los hombres con esos trajes de cuero que se pone... Pero por "
  "dentro es un trozo de hielo, no tiene coraz�n. Es absolutamente incapaz del "
  "m�s m�nimo sentimiento. S�lo espero que alg�n d�a alguien la haga sufrir "
  "de verdad.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas ex�ticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Morda te dice: 'Tus humildes servidoras: por un pu�ado de monedas bailaremos "
  "s�lo para ti.'\n",1);
  AddQuestion(({"Morda","morda"}),SF(answ_self),1);
  AddQuestion(({"Igart","igart"}),
  "Morda te dice: 'Mi compa�era, aqu� presente. Preg�ntale lo que quieras, "
  "que estoy segura que te contestar� con placer.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Morda te dice: 'Mi joven compa�era. Sus danzas son famosas en todo el mundo, "
  "aunque �ltimamente parece un poco ausente, no es la misma...'\n",1);
  AddQuestion(({"Baskari","baskari","se�or Baskari","se�or baskari",
                "senyor Baskari","senyor baskari"}),
  "Morda te dice: 'El hombre que nos explota. Pero en fin, yo no soy tan "
  "radical como Igart: yo creo que si s�lo le importase el dinero no estar�a "
  "en este negocio. De pueblo en pueblo y sin ning�n hogar fijo. Es una "
  "vida muy dura, cr�eme. Si estuviera en ella por el dinero ser�a tonto. "
  "Y otra cosa no s�, pero Baskari tonto no es, precisamente.'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                  "Madamme nileki","madamme nileki"}),
  "Morda te dice: 'La esposa del se�or Baskari. Experta en las artes arcanas. "
  "Si quiere, puede predecir el futuro y fabricar pociones para curar "
  "cualquier enfermedad.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Morda te dice: '�Los hermanos Kutiri? No me hables de ellos. Maldito el "
  "d�a en que decidimos recoger a estos peque�os bastardos. Ya nos han "
  "prohibido volver a cuatro ciudades desde que est�n con nosotros. Se "
  "emborrachan, gastan bromas pesadas a las autoridades, roban... "
  "Baskari sabe que habr� que echarlos, pero no se decide. Los beneficios "
  "son los beneficios, dice...'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Morda te dice: 'El mayor de los hermanos Kutiri. Y el peor.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Morda te dice: 'Uno de los hermanos Kutiri. No es demasiado amigo del agua...'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  W("Morda te dice: 'Uno de los hermanos Kutiri. Suele definirse a s� mismo como "
    "\"inventor de aparatos in�tiles\". No ha dicho otra verdad igual en su vida...'\n"),1);
  AddQuestion(({"Tinky","Tinky"}),
 "Morda te dice: 'Uno de los hermanos Kutiri. Alg�n d�a acabar� en prisi�n por "
 "robo. Y lo malo es que nos arrastrar� a los dem�s con �l.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Morda te dice: 'Para m� que su madre le quiso decir algo a su padre cuando "
  "le puso ese nombre... �a ti qu� te parece?'\n",1);
}
