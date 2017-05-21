/*=============================================================*
 |             << GOLDHAI.playa [w] Woo@simauria >>            |
 *=============================================================*
 |                Creacion............. 29-10-98               |
 |                Ultima Modificacion.. 29-10-98               |
 |                                                             |
 *=============================================================*/

#include "../sys/goldhai.h"
#include <sounds.h>

inherit GROOM;

create() {
 ::create();

 SetSoundEnvironment(SND_AMBIENTES("olas"), 10);
 SetIntShort("un cantilado");

 switch(random(3))
 {
  case 0:
 SetIntLong("\
Caminas por el borde de un increible acantilado de varias decenas de metros\n\
de altura. Las piedras caen rapidamente golpeando en la pared. No tienes\n\
otra salida que continuar por este acantilado.\n");
  break;

  case 1:
 SetIntLong("\
Te encuentras en el borde del acantilado de noroeste de Goldhai. Desde aquí\n\
puedes divisar el faro claramente. El bosque y el precipicio te invitan a no\n\
quedarte mucho tiempo en este lugar.\n");
   break;

  case 2:
 SetIntLong("\
Estás en otra zona del acantilado del noroeste de Goldhai. Te asomas muy\n\
cuidadosamente al precipicio y observas la gran distancia que hay hasta\n\
llegar a las rocas de abajo. Será mejor que te vayas de este sitio si no\n\
quieres tener un desagradable percance.\n");
  break;


  default:
 SetIntLong("\
Te encuentras en el borde del acantilado de noroeste de Goldhai. Desde aquí\n\
puedes divisar el faro claramente. El bosque y el precipicio te invitan a no\n\
quedarte mucho tiempo en este lugar.\n");
 }

 SetIndoors(0);
 SetIntSmell("\
Se mezcla un raro olor entre el mar y el bosque.\n");

 AddDetail(({"acantilado","precipicio"}),
"La altura de este acantilado es inmensa. Abajo puedes divisar como las olas\n\
rompen contra las rocas.\n");
 AddDetail(({"mar","oceano","agua"}),
"Desde este punto de la isla el mar adquiere una belleza especial. Ves como\n\
llegan las olas de forma lenta y rompen bruscamente contra el acantilado.\n");
 AddDetail(({"roca","rocas"}),
"La parte baja del acantilado está llena de enormes rocas que harían de forma\n\
casi milagrosa que alguien se pudiera salvar si cayera por aquí.\n");
 AddDetail(({"bosque","arboles"}),
"Ves unos enormes arboles que forman parte del bosque norte de Goldhai.\n");
 AddDetail(({"olas"}),
"Las olas golpean fuertemente contra las rocas del acantilado.\n");

  SetIndoors(0); // A descubierto
}
