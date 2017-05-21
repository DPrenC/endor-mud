/*
DESCRIPCION  : Templo de Asthar junto al mural.
FICHERO      : /d/limbo/comun/habitacion/limbo/templo03.c
MODIFICACION : 08-02-98 [Angor@Simauria] Creacion
               30-09-98 [Angor@Simauria] Rehecha en gran medida
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el oeste del templo de Asthar");
  SetIntLong(
"Te hallas junto al muro oeste del templo de Asthar. Este muro se haya recorrido "
"por una banda continua de murales pintados que representan momentos de la "
"historia de Simauria. Los que hay frente a ti muestran varios hechos de la "
"'Segunda Edad', que comprende el inicio del desarrollo de las distintas "
"civilizaciones en Simauria. En el mural se muestran escenas de las historias "
"epicas recogidas en los textos que se conservan de esta epoca.\n");

/*
AddDetail(({"segunda edad","Segunda Edad","edad","civilizaciones","desarrollo"}),
  "La Segunda Edad el periodo de tiempo mas lejano del que se conservan documentos. "
  "Estos documentos son escasos y poco precisos y en general consisten en cantares "
  "y poemas que relatan aventuras epicas de heroes locales en un mundo inexplorado. "
  "De todas ellas se puede deducir que las civilizaciones eran jovenes, poco "
  "desarrolladas y sin apenas interaccion entre ellas. Puedes encontrar mas "
  "informacion sobre la historia en las bibliotecas que hay a lo ancho de este "
  "mundo, especialmente en la 'Gran Biblioteca de Simauria'.\n");

 +"y se documentan algunos descubrimientos basicos tales como la metalurgia por los "
  "enanos y la magia por los elfos.\n");
*/

AddDetail(({"mural","murales","escenas","heroes","gestas","historias epicas","historias"}),
 "Los murales pintados en la pared muestran escenas de la Segunda Edad. En ellas "
 "se representa a los heroes mitologicos de varias de las razas asi como algunas "
 "de sus gestas. La Segunda Edad es el periodo de tiempo mas lejano del que se "
 "conservan documentos, y los pocos que quedan recogen cantares y poemas que "
 "relatan las aventuras epicas de los heroes que se muestran en el mural. Por lo "
 "que ves deduces que las civilizaciones eran jovenes, poco desarrolladas y sin "
 "apenas interaccion entre ellas. Encontraras mas informacion en las distintas "
 "bibliotecas de este mundo, especialmente en la 'Gran Biblioteca de Simauria'.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
 "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
 "Gracias a ellos, es en este lugar donde las almas de los seres se "
 "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
SetLocate("isla Limbo");
SetIndoors(1);
SetIntBright(50);
AddExit("norte",TEMPLO("templo00"));
AddExit("este",TEMPLO("templo04"));
AddExit("sur",TEMPLO("templo06"));
}
