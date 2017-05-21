/*
   Archivo: bree_room.c :
   Descripción: room base para el país de Bree.
     Creacion : 15/11/2012.
   Autor: Aulë
   */


#include "./path.h"

inherit ROOM;

create()
{
  ::create();
 SetIntShort("las tierras de Bree");
  SetIntLong("Estás en algún lugar de las tierras de Bree.\n");
  SetLocate("tierras de Bree");
  SetIntNoise("El silencio es absoluto.\n");
  SetIntSmell("El aire es totalmente inodoro.\n");

  /* SetClimateServer(SERVER); */
  SetIndoors(0);
}
