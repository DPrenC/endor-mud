/*****************************************************************************************
 ARCHIVO:       tdhab27.c
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

    SetIntShort("el comedor");
    SetIntLong("Esto puede que fuera el comedor de los monjes. La costumbre era "
          "reunirse aquí para compartir los retazos de su cotidiana vida. No queda mucho "
          "de los muebles, pues algunos están bastante destrozados.\n");
    SetIndoors(1);
    SetIntBright(30);

    AddExit("oeste", ALULAGO("templo/tdhab28.c"));
    AddExit("este", ALULAGO("templo/tdhab26.c"));
    AddExit("sur", ALULAGO("templo/tdpas15.c"));
}
