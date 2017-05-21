/*
DESCRIPCION  : Entrada al edificio de los siervos/suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/entrada_sum.c
MODIFICACION : 28-09-98 [Angor@Simauria] Creacion.
               23-03-99 [Angor@Simauria] wrapeado...
               10-10-99 [woo] Modificado...
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include "/secure/wizlevels.h"  //por el IS_WIZARD()
#include <moving.h>
inherit ROOM;

int ir_almacen(string donde);
int ir_norte(){ir_almacen(TEMPLO("comida"));return 1;}
int ir_oeste(){ir_almacen(TEMPLO("magia"));return 1;}
int ir_sur(){ir_almacen(TEMPLO("armas1"));return 1;}

#define AO      (TP->QueryGenderEndString())
#define NOMBRE  (capitalize(TP->QueryName()))

create() {
  ::create();
  SetIntShort("la entrada al edificio de los siervos");
  SetIntLong(
  W("Te encuentras en la entrada del edificio de los siervos de los dioses. "
    "Éstos han convertido la planta baja en un gran "
    "almacén es cuyas estanterias se pueden encontrar los más variados "
    "productos a fin de que los más inexpertos en este mundo puedan "
    "equiparse y familiarizarse con ellos. Un enorme guerrero kainoak "
    "controla quien puede y quien no puede pasar al almacén. Al este, la "
    "puerta principal permite salir al exterior, y unas escaleras "
    "conducen a la planta superior.\n"));

AddDetail(({"puerta"}),
W("Es una robusta puerta de roble. Permite salir al exterior del "
  "edificio.\n"));

AddDetail(({"escaleras"}),
W("Unas anchas escaleras de madera adosadas a la pared del edificio "
  "permiten subir a la planta superior donde viven los siervos de los "
  "dioses.\n"));

AddDetail(({"almacen","almacen de suministros","estanterias"}),
W("Se extiende ante ti ocupando toda la amplia planta baja de este "
  "edificio. En sus estanterias se puede encontrar casi de todo, pero "
  "un guardian se encarga de que solo puedan entrar a él los principiantes "
  "siguiendo ordenes de los dioses.\n"));

SetIntNoise("Se oye el murmullo de la gente en el almacen.\n");
SetIntSmell("Huele a los mas diversos productos.\n");
SetLocate("isla Limbo");
SetIndoors(1);
SetIntBright(50);


AddExit("arriba",TEMPLO("escalera"));
AddExit("norte",SF(ir_norte));
AddExit("oeste",SF(ir_oeste));
AddExit("este",TEMPLO("plaza03"));
AddExit("sur",SF(ir_sur));
AddItem(PNJ("guardia"));
ForbidAllMagic();
SetSafe(1);
}

int ir_almacen(string donde){
object ob;
  ob=TP;

  //pnj?
  if (!(ob->QueryIsPlayer())) return 1;
  //wizard?
  if (IS_WIZARD(ob)){
     write("Sayek te mira de arriba a abajo y te hace una reverencia: 'Que honor, un "
           "wizard por aqui. Puedes pasar al almacen, "+NOMBRE+"'.\n");
     say(NOMBRE+" trata de entrar al almacen. Sayek le hace una reverencia a este "
        "wizard y le deja pasar.\n",TP);
     TP->move(donde,M_GO);
     return 1;
     }

  //novato?
  write("Sayek te dice:'Eh tu, ¿dónde crees que vas?'.\n");
  if (ob->QueryLevel()<=4){
     write("Sayek te mira de arriba a abajo y dice: 'Parece que aún eres "+TP->QueryArtIndString()+" principiante. "
           "Bien, puedes pasar al almacen'.\n");
     say(NOMBRE+" trata de entrar al almacen. Sayek le observa y le deja pasar.\n",TP);
     TP->move(donde,M_GO);
     }
  else{
     write("Sayek te mira de arriba a abajo y dice: 'Tu ya no puedes pasar al almacen'. Ya "
           "tienes el suficiente nivel como para buscarte la vida sin ayuda de los dioses.\n");
     say(NOMBRE+" trata de entrar al almacen. Sayek le detiene y no le deja pasar.\n",TP);
     }
  return 1;
}

