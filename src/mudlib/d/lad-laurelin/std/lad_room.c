/*
   ##################################################################
   ## lad_room.c : Habitacion estandard para Lad Laurelin.         ##
   ## Creacion : 09/05/97. [g] Guybrush (davalgal@eui.upv.es)      ##
   ##                                   (guybrush@simauria.upv.es) ##
   ##                                                              ##
   ##                      [l] Lonerwolf                           ##
   ##                                                              ##
   ##                                                              ##
   ## Modificaciones: 19/05/97 [g] Modifica el inherit, la Short,  ##
   ##                la Long y la Locate.                          ##
   ##                 18/06/10 [l] Como pasa el tiempo, se iguala  ##
   ##                el uso de algunas funciones al resto del mud  ##
   ##################################################################
*/

#include "path.h"

inherit ROOM;

create()
{
   ::create();

   SetIntShort("algún lugar de Lad-Laurelin");
   SetIntLong("Estas en alguna parte del vasto dominio de Lad-Laurelin.\n");
   SetIndoors(0);
   SetLocate("Lad-Laurelin");
   SetIntNoise("No escuchas nada en especial.\n");
   SetIntSmell("No hueles nada en especial.\n");
   // [l] esto esta en simauria, pero aqui no, como simauria funciona bien  pues lo pongo 
   // aqui tambien
   SetClimateServer(SERVER);
}
