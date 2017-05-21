/*****************************************************************************************
 ARCHIVO:       tdpas7.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCI�N:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("el pasillo");
    SetIntLong("Delante de ti deb�a haber una puerta ancha, pero ahora s�lo hay "
          "cascotes. Oyes algo a tu alrededor. �Ser� alg�n fantasma?\n");
    SetIntNoise("Escuchas d�biles lamentos de alg�n lugar que no puedes precisar.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail(({"pared", "paredes"}), "S�lo ves manchas y suciedad, aparte de "
          "ratas...\n");

    AddExit("oeste", ALULAGO("templo/tdhab3.c"));
    AddExit("sudeste", ALULAGO("templo/tdpas8.c"));
}
