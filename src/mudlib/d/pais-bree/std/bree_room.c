/*
   Archivo: bree_room.c :
   Descripci�n: room base para el pa�s de Bree.
     Creacion : 15/11/2012.
   Autor: Aul�
   */


#include "./path.h"

inherit ROOM;

create()
{
  ::create();
 SetIntShort("las tierras de Bree");
  SetIntLong("Est�s en alg�n lugar de las tierras de Bree.\n");
  SetLocate("tierras de Bree");
  SetIntNoise("El silencio es absoluto.\n");
  SetIntSmell("El aire es totalmente inodoro.\n");

  /* SetClimateServer(SERVER); */
  SetIndoors(0);
}
