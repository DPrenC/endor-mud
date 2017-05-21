/*
DESCRIPCION  : Delante del mausoleo del Guardian del Templo de Dehim
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/ camino3.c
NOTAS:
CREACION :  ALura (Julio del 2000)
*/

#include "./path.h"
#include <properties.h>
#include <rooms.h>

inherit ROOM;

create() {
  ::create();
SetPreIntShort("delante de");
SetIntShort("un mausoleo.");
SetIntLong(
"  Este pequeño sendero tiene en los límites varios árboles viejos y grandes\n"
"cuyo color todavía perdura intenso y brillante.\n"
"Delante de ti, al oeste, ves un bello mausoleo al que no parece que hallan\n"
"tocado malvadas manos. Desde aquí se puede ver el panteón.\n");

AddDetail (({"niebla"}),"  No hay restos de niebla.\n");

AddDetail (({"panteón"}),
"  Es una obra de arte gigantesca que destaca del cementerio porque no tiene la\n"
"misma fina y delicada estructura que el resto de lugares. Figuras como gárgolas\n"
"y otros horrorosos seres pueblan sus paredes.\n");

SetIntSmell("  Huele a la hierba fresca del camino.\n ");
SetLocate("Cementerio2");
SetIndoors (0); /* 0 exterior; 1 interior */
SetIntBright(25);

AddExit("nordeste","camino15");
//AddDoor("idpuertaG","oeste","mausoleo2","puerta","Es la puerta de entrada a un mausoleo.\n",
//	([P_MATERIAL:M_BRONCE,P_PUERTA_VIDA:300,P_PUERTA_VIDA_MAX:300]));

}