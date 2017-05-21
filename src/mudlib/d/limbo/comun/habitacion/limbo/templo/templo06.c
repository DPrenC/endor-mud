/*
DESCRIPCION  : Templo de Asthar junto al mural.
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/asthar_mural3.c
MODIFICACION : 08-02-98 [Angor@Simauria] Creacion
               30-09-98 [Angor@Simauria] Rehecha en gran medida
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;


create() {
  ::create();
  SetPreIntShort("junto a");
  SetIntShort("el mural del Templo de Ashtar");
  SetIntLong(
"Te hallas en la esquina suroeste del templo de Asthar. El muro oeste del templo "
"se haya recorrido por una banda continua de murales pintados que representan "
"momentos de la historia de Simauria. Los que hay frente a ti muestran varios "
"hechos de la 'Tercera Edad', que comprende desde la aparicion de la poderosa "
"raza de los demonios hasta su derrota final gracias a la Gran Alianza y la "
"aparicion de la raza de los draconianos. En el mural se muestran escenas epicas "
"de las batallas y hechos acontecidos en esta oscura epoca.\n");

AddDetail(({"mural","murales","demonios","draconianos","escenas","heroes"}),
 "Los murales pintados en la pared muestran escenas de Tercera Edad. En ellas "
 "puedes ver la aparicion de la raza de los demonios a todo lo ancho del mundo y "
 "como su lucha forzo el desarrollo de las otras razas. Tecnicas tales como la "
 "metalurgia o la magia pasaron asi a la mayoria de edad. Observas escenas de "
 "grandes batallas, destruccion y caos en las que cada raza forjo una larga serie "
 "de heroes casi mitologicos. Todas las razas aunaron sus esfuerzos en una "
 "iniciativa, jamas repetida, como fue la Gran Alianza, que les permitio doblegar "
 "a los poderosos demonios y con la oportuna aparicion por el oeste de los "
 "draconianos vencer finalmente. Encontraras mas informacion en las distintas "
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
AddExit("este",TEMPLO("altar"));
AddExit("norte",TEMPLO("templo03"));
}

