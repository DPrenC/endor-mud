/*
DESCRIPCION  : Plaza del templo
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/plaza04.c
MODIFICACION :
16-09-98 [Angor@Simauria] Creacion.
23-09-99 [Angor@Simauria] wrapeado...
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <sounds.h>

inherit ROOM;


create() {
  ::create();
  SetIntShort("la plaza del templo de Asthar");
  SetIntLong(
  W("Estas en la parte este de la plaza del templo de Asthar. Desde este "
    "magnifico mirador que es la plaza puedes comtemplar la mayor parte "
    "de la costa este de la isla Limbo, desde los acantilados del sur hasta "
    "la torre de wizards al nordeste. Al oeste de la plaza se halla el "
    "edificio donde viven los siervos de los dioses y al sur el impresionante "
    "templo de Asthar. Al oeste de aqui, en el centro de la plaza esta "
    "situado un gran monolito de basalto negro.\n"));

 AddDetail(({"templo","templo de Asthar"}),
 W("El templo de Asthar es el edificio que se encuentra al sur de esta plaza. "
   "Es un gran edificio de base rectangular hecho de marmol de color claro "
   "sobre el sobre el que sobresale una inmensa boveda de forma hemisferica. "
   "En el templo, Asthar realiza la operacion que permite a un ser cambiar "
   "su forma fisica, manteniendo intacto su espiritu.\n"));

 AddDetail(({"torre","torre de los wizards"}),
 W("Es una gran torre construida sobre unos penyascos en el mar al este de "
   "la isla Limbo. Alli es donde viven y trabajan los wizards, los ayudantes "
   "de los dioses que ayudan a construir y mantener este mundo. Para acceder "
   "a la torre se ha construido un puente que parte de la costa este de la "
   "isla.\n"));

 AddDetail(({"plaza"}),
 W("La plaza es una gran extension cuadrada de adoquines blancos en cuyo "
   "centro se halla un gran monolito de basalto negro.\n"));

 AddDetail(({"monolito"}),
 "Es un gran bloque de basalto. Acercate mas si quieres verlo mejor.\n");

 AddDetail(({"isla","isla Limbo","Limbo","limbo"}),
 W("La isla Limbo es el lugar magico de Simauria donde habitan los dioses."
   "Gracias a ellos, es en este lugar donde las almas de los seres se "
   "encarnan y dan sus primeros pasos para vivir en este mundo.\n"));

 SetIntNoise("Oyes el ruido del las olas chocando contra los acantilados.\n");
 SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
 SetLocate("isla Limbo");
 SetIndoors(0);
 SetSoundEnvironment(SND_AMBIENTES("olas"), 10);

 AddExit("norte",TEMPLO("plaza02"));
 AddExit("oeste",TEMPLO("obelisco"));
 AddExit("sur",TEMPLO("plaza07"));
}
