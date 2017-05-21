/*****************************************************************************************
 ARCHIVO:       tdpas7.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("el pasillo");
    SetIntLong("Delante de ti debía haber una puerta ancha, pero ahora sólo hay "
          "cascotes. Oyes algo a tu alrededor. ¿Será algún fantasma?\n");
    SetIntNoise("Escuchas débiles lamentos de algún lugar que no puedes precisar.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail(({"pared", "paredes"}), "Sólo ves manchas y suciedad, aparte de "
          "ratas...\n");

    AddExit("oeste", ALULAGO("templo/tdhab3.c"));
    AddExit("sudeste", ALULAGO("templo/tdpas8.c"));
}
