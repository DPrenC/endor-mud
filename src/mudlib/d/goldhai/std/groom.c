/*=============================================================*
 |            << GOLDHAI.Goldhai [w] Woo@simauria >>           |
 *=============================================================*
 |               Creacion............... 27-11-97              |
 |               Ultima Modificacion.... 11-05-99              |
 |                                                             |
 | NOTA: Goldhai tendrá una room.c especial que será esta, que |
 |       englobará el ROOM normal más las funciones que están  |
 |       definidas aquí.                                       |
 |                                                             |
 | 18-10-97 [w] Incorporado el control del tiempo...           |
 | 07-02-99 [w] Cambiada la habitación estandar.               |
 | 11-05-99 [w] Añadida la funcion SetLongWrap.                |
 |                                                             |
 *=============================================================*/

#include "../sys/goldhai.h"
#include <nightday.h>
inherit ROOM; // Habitacion standard.

#define DIR "/d/goldhai/std/"
//#define TIEMPO "/d/goldhai/std/control" // lo quito por ahora, el chronos no va.
#define TIEMPO NIGHTDAY


create() {
  ::create();
  SetServer(TIEMPO);
  AddRoomCmd(({"mirar","m"}),"_mirar");
}

string SetLongWrap(string texto) {
 return SetIntLong(texto+"\n");
}

_mirar(str)
{
 if(!str) return 0;
 if(str=="cielo" || str=="atmosfera" || str=="tiempo")
  if (!environment(TP)->QueryIndoors())
  {
   say(CAP(TNREAL)+" contempla el tiempo que hace.\n");
   write(TIEMPO->QueryWeatherMsg());
   return 1;
  }
  else
  {
   say(CAP(TNREAL)+" mira el techo.\n");
   write("Estás en un sitio cerrado que no te permite ver que tiempo hace.\n");
   return 1;
  }

 if (str=="pavimento" || str=="suelo")
  if (!environment(TP)->QueryIndoors())
  {
   say(CAP(TNREAL)+" mira el suelo.\n");
   write(TIEMPO->QueryGroundDesc());
   return 1;
  }
  else
  {
   say(CAP(TNREAL)+" mira el suelo.\n");
   write("Ves el suelo.\n");
   return 1;
  }
 return 0;
}
