/*****************************************************************************************
 ARCHIVO:       tdhab22.c
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

    SetIntShort("la despensa de la cocina");
    SetIntLong("Aquí guardaban los cocineros toda la comida de la semana. No hay nada "
          "comestible, pues lo que hay está podrido o pasado.\n");
    SetIndoors(1);
    SetIntBright(30);

    AddExit("este", ALULAGO("templo/tdpas15.c"));
    AddExit("sur", ALULAGO("templo/tdpas14.c"));

    AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 1);
}
