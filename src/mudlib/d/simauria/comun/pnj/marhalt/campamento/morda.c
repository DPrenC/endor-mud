/* morda.c
  Bailarina elfa.
  Tiene información relativa al caso del látigo desaparecido.
  [n] nemesis@simauria

  Creación: 05-Dic-2001 01:15:17 CET (joer, 1 pnj/h, vaya media...)
  Modificado:
*/

#include <rooms.h>
#include <properties.h>
#include "./path.h"

inherit NPC;

private string answ_robo() {
 if(TP->Query("beni_acusa"))
  return W("Le cuentas a Morda lo que Beni te ha contado sobre el robo del látigo "
           "de Lady Morkobva. La sonrisa se borra de su cara y te dice: '¿Esa "
           "renacuaja de Beni te ha dicho eso? Pues ya le puedes decir que "
           "nosotras no somos tan rastreras. Además, si quisiéramos hacerle algo "
           "a ella o a su hermanito, lo haríamos cara a cara. Le puedes decir "
           "que si quiere hacer alguna acusación, que nos lo diga a la cara. "
           "Entonces ajustaremos cuentas.'\n");
  else return "Morda te dice: 'No sé de qué carajo me hablas.'\n";
}

private string answ_self() {
 if(TI->QueryGender() == GENERO_MASCULINO)
  return "Morda te dice insinuante: 'Ésa soy yo. ¿Qué deseas, cariño?'\n";
 else return "Morda te dice: 'Ésa soy yo. ¿Quieres algo?'\n";
}

// create
create() {
  ::create();
 SetStandard("Morda", "elfo", 100, GENERO_FEMENINO);
  SetShort("Morda, una bailarina");
  SetLong("A pesar de que Morda tiene todos los rasgos de un elfo, te llama "
          "la atención que su piel tiene un hermoso tono canela y sus cabellos "
          "son de color azabache. Eso sí, tiene los hermosos ojos azules de "
          "su raza. Sabes que hay casos de medio-elfos mulatos, pero Morda "
          "parece demasiado élfica para serlo sólo a medias.\n");
  // En la habitación habrá un AddDetail tal que asín:
  // AddDetail(({"bailarina exótica","bailarina exotica","bailarina"}),
  //           "¿Cuál de las tres?");
  AddId(({"Morda","morda","bailarina elfa","elfa negra","elfa mulata"}));
  SetAlign(400);
  InitChats(5,({
   "Morda les dice a sus compañeras: 'Ensayemos los pasos del nuevo número.'\n",
   "Morda inicia una sensual danza mientras sus compañeras dan palmas.\n",
   "Morda mira a Kwailin, le dice algo a Igart al oído y las dos sueltan una "
   "risita.\n",
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
  "Morda te dice: 'Es el forzudo de la compañía. Una mole de músculos. Creo "
  "que le hace tilín a Igart. Creo que harían buena pareja... Es el "
  "ejemplar masculino más grande que hay por aquí...'\n",1);
  AddQuestion(({"Beni y Mossi","gemelos Trassi","beni y mossi","gemelos trassi",
                "los gemelos Trassi","los gemelos trassi","equilibristas",
                "los equilibristas"}),
  "Morda te dice: 'Unos pobres muertos de hambre a los que recogimos cuando "
  "estaban mendigando por las calles y a los que dimos un hogar. Y se han "
  "vuelto unos estirados que se creen superiores a todos. Claro que no me "
  "extraña, si se juntan con esa maldita elfa-oscura...'\n",1);
  AddQuestion(({"Beni","beni"}),
  "Morda te dice: 'Una niñata estirada que se cree que porque Baskari hizo "
  "una vez un comentario sobre lo bien que baila, puede pisotearnos a las "
  "demás. Esa estúpida sería incapaz de dar un paso si tuviera el público "
  "que nosotras tenemos. Eso sin contar con que el salvaje de su hermano "
  "no se lo permitiría.'\n",1);
  AddQuestion(({"Mossi","mossi"}),
  "Morda te dice: 'El hermano de esa engreída de Beni. Con la excusa de que "
  "tiene que ser el padre que ella no tuvo, se cree con derecho a decirle "
  "a su hermana lo que tiene y no tiene que hacer. Y a quitar de enmedio "
  "a quienes se opongan. Si no fuera por él, ella sería hasta simpática.'\n",1);
  AddQuestion(({"Lattini","lattini","latini","Latini","el gran lattini",
                "el gran Lattini","el Gran Lattini","ilusionista",
                "el ilusionista"}),
  "Morda te dice: 'Es un cerdo. Me sedujo prometiéndome que dejaría a su "
  "mujer y nos iríamos juntos, que él conocía a mucha gente en Ishtria, "
  "que estaba desperdiciando mi talento en ferias de mala muerte... Y luego "
  "si te he visto no me acuerdo... Me abandonó para ir detrás de esa Lady "
  "Morkobva... Espero que esa elfa-oscura demuestre más sentido que yo y "
  "le deje la cara marcada de un latigazo.'\n",1);
  AddQuestion(({"Nikaia","nikaia","lanzadora de cuchillos","lanzadora"}),
  "Morda te dice: 'La esposa de Lattini. Hubo un tiempo en que la odié, "
  "pero ahora sólo puedo sentir lástima por ella. Adora a su marido y "
  "sería capaz de cualquier barbaridad si se enterase de cómo es en "
  "realidad... Es la única razón por la que todas guardamos silencio.'\n",1);
  AddQuestion(({"Lady Morkobva","lady morkobva","lady Morkobva","Lady morkobva",
                "domadora","la domadora","domadora de fieras",
                "la domadora de fieras"}),
  "Morda te dice: ¿Ésa? ¿Qué puedo decir de ella? Se disfraza de mujer, y va "
  "provocando a los hombres con esos trajes de cuero que se pone... Pero por "
  "dentro es un trozo de hielo, no tiene corazón. Es absolutamente incapaz del "
  "más mínimo sentimiento. Sólo espero que algún día alguien la haga sufrir "
  "de verdad.'\n",1);
  AddQuestion(({"Igart, Kwailin y Morda","bailarinas","bailarinas exóticas",
                "bailarinas exoticas","igart, kwailin y morda"}),
  "Morda te dice: 'Tus humildes servidoras: por un puñado de monedas bailaremos "
  "sólo para ti.'\n",1);
  AddQuestion(({"Morda","morda"}),SF(answ_self),1);
  AddQuestion(({"Igart","igart"}),
  "Morda te dice: 'Mi compañera, aquí presente. Pregúntale lo que quieras, "
  "que estoy segura que te contestará con placer.'\n",1);
  AddQuestion(({"Kwailin","kwailin"}),
  "Morda te dice: 'Mi joven compañera. Sus danzas son famosas en todo el mundo, "
  "aunque últimamente parece un poco ausente, no es la misma...'\n",1);
  AddQuestion(({"Baskari","baskari","señor Baskari","señor baskari",
                "senyor Baskari","senyor baskari"}),
  "Morda te dice: 'El hombre que nos explota. Pero en fin, yo no soy tan "
  "radical como Igart: yo creo que si sólo le importase el dinero no estaría "
  "en este negocio. De pueblo en pueblo y sin ningún hogar fijo. Es una "
  "vida muy dura, créeme. Si estuviera en ella por el dinero sería tonto. "
  "Y otra cosa no sé, pero Baskari tonto no es, precisamente.'\n",1);
  AddQuestion(({"Madamme Nileki","Nileki","nileki","madamme Nileki",
                  "Madamme nileki","madamme nileki"}),
  "Morda te dice: 'La esposa del señor Baskari. Experta en las artes arcanas. "
  "Si quiere, puede predecir el futuro y fabricar pociones para curar "
  "cualquier enfermedad.'\n",1);
  AddQuestion(({"los hermanos Kutiri","los Hermanos Kutiri","hermanos Kutiri",
                "Hermanos Kutiri","Kutiri bros","hermanos kutiri","kutiri",
                "los hermanos kutiri"}),
  "Morda te dice: '¿Los hermanos Kutiri? No me hables de ellos. Maldito el "
  "día en que decidimos recoger a estos pequeños bastardos. Ya nos han "
  "prohibido volver a cuatro ciudades desde que están con nosotros. Se "
  "emborrachan, gastan bromas pesadas a las autoridades, roban... "
  "Baskari sabe que habrá que echarlos, pero no se decide. Los beneficios "
  "son los beneficios, dice...'\n",1);
  AddQuestion(({"Binky","binky"}),
  "Morda te dice: 'El mayor de los hermanos Kutiri. Y el peor.'\n",1);
  AddQuestion(({"Dinky","dinky"}),
  "Morda te dice: 'Uno de los hermanos Kutiri. No es demasiado amigo del agua...'\n",1);
  AddQuestion(({"Pinky","pinky"}),
  W("Morda te dice: 'Uno de los hermanos Kutiri. Suele definirse a sí mismo como "
    "\"inventor de aparatos inútiles\". No ha dicho otra verdad igual en su vida...'\n"),1);
  AddQuestion(({"Tinky","Tinky"}),
 "Morda te dice: 'Uno de los hermanos Kutiri. Algún día acabará en prisión por "
 "robo. Y lo malo es que nos arrastrará a los demás con él.'\n",1);
  AddQuestion(({"Clyde","clyde"}),
  "Morda te dice: 'Para mí que su madre le quiso decir algo a su padre cuando "
  "le puso ese nombre... ¿a ti qué te parece?'\n",1);
}
