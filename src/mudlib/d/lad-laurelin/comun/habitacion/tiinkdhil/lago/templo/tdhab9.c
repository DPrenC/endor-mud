/*****************************************************************************************
 ARCHIVO:       tdhab9.c
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

    SetIntShort("la parte este del salón");
    SetIntLong("Te topas con la pared, que está cubierta de cortinas deshilachadas. "
          "Este ambiente te produce escalofríos...\n");
    SetIndoors(1);
    SetIntBright(25);
    AddDetail("techo", "Es una inmensa bóveda decorada con expresivos dibujos del "
          "dios. Dehim es el sanador celestial, la esperanza de los enfermos.\n");

    AddExit("este", ALULAGO("templo/tdhab8.c"));
    AddExit("norte", ALULAGO("templo/tdhab17.c"));
    AddExit("sur", ALULAGO("templo/tdhab5.c"));
    AddExit("nordeste", ALULAGO("templo/tdhab16.c"));
    AddExit("sudeste", ALULAGO("templo/tdhab4.c"));
}
