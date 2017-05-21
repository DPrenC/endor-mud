/*****************************************************************************
 AUTOR:		[h] Nyh
 DETALLES:	Cavernas del Caos
            Habitación base de las cavernas del caos que todas las demás
            heredarán haciendo un:
            inherit CAOSHAB "_caos_base_room";
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

public create()
{
  ::create();

  SetLocate("Cavernas del Caos");
  SetIndoors(1);
  SetIntBright(0);
  SetIntSmell("No hueles nada especial.\n");
  SetIntNoise("No escuchas nada importante.\n");
    if(d10()==1)
        AddItem(CAOSPNJ"ogro", REFRESH_DESTRUCT,d2());
}