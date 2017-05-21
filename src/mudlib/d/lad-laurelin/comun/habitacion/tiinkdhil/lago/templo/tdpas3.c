/*****************************************************************************************
 ARCHIVO:       tdpas3.c
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
    SetPreIntShort("por");
    SetIntLong("Te cuesta esquivar los cascotes. F�jate, �si se ve el cielo!...\n "
          "El corredor contin�a al surdeste y oeste.\n");
    SetIndoors(1);
    SetIntBright(40);

    AddExit("sudeste", ALULAGO("templo/tdpas1.c"));
    AddExit("oeste", ALULAGO("templo/tdpas4.c"));
}
