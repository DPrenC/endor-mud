/*
DESCRIPCION  : Templo de Asthar junto al mural.
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/templo00.c
MODIFICACION : 08-02-98 [Angor@Simauria] Creacion
               30-09-98 [Angor@Simauria] Rehecha en gran medida
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el noroeste del templo de Asthar");
  SetIntLong(
"Te hallas en la esquina noroeste del templo de Asthar. El muro oeste del templo "
"se halla recorrido por una banda continua de murales pintados que representan "
"momentos de la historia de Simauria. Los que hay frente a ti muestran varios "
"hechos de la 'Primera Edad', que comprende desde la Creacion del universo por "
"Dawa el hacedor y sus discipulos los dioses, hasta la aparicion de los primeros "
"documentos escritos. Al este de aqui se halla la entrada del templo.\n");

/*
AddDetail(({"primera edad","Primera Edad","edad"}),
  "La Primera Edad es el periodo de tiempo mas lejano en la historia de Simauria. "
  "De esta epoca apenas se conoce la historia, y el unico conocimiento disponible "
  "es a traves de mitos y leyendas de transmision oral, que fueron recopilados con "
  "posterioridad en poemas y canciones. La aparicion de los primeros documentos "
  "escritos, de origen elfico, marca el final de esta epoca. Puedes encontrar mas "
  "informacion sobre la historia en las bibliotecas que hay a lo ancho de este "
  "mundo, especialmente en la 'Gran Biblioteca de Simauria'.\n");
*/

AddDetail(({"mural","murales","Dawa","dawa","Creacion","creacion","dioses","universo","murales pintados"}),
 "Los murales pintados en la pared representan escenas de la Primera Edad. En "
 "ellas se representa a Dawa, el primer ser, y el principio del universo: Como "
 "Dawa existio y con el/ella el universo, como creo a los dioses y les ensenyo, y "
 "como concibio e hizo la vida en un universo que, hasta entonces, solo contenia "
 "materia inerte. Tambien se muestra como algunos dioses decidieron finalizar esta "
 "obra que Dawa solo habia esbozado bajando a los mundos y a veces tomando incluso "
 "forma material. En el caso de Simauria estos dioses habitaron en la isla Limbo. "
 "Puedes encontrar mas informacion en las distintas bibliotecas de este mundo.\n");

AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
 "La isla Limbo es el lugar magico de Simauria donde habitan los dioses. "
 "Gracias a ellos, es en este lugar donde las almas de los seres se "
 "encarnan y dan sus primeros pasos para vivir en este mundo.\n");

 SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
 SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
 SetLocate("isla Limbo");
 SetIndoors(1);
 SetIntBright(50);
 AddExit("sur",TEMPLO("templo03"));
 AddExit("este",TEMPLO("templo01"));
}
