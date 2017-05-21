/*****************************************************************************************
 ARCHIVO:       tdpas14.c
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

    SetIntShort("el corredor");
    SetIntLong("Este pasillo lleva a las habitaciones de los monjes al sur, al norte y "
          "noroeste a la cocina. El resto de direcciones llevan a otros corredores.\n");
    SetIntNoise("Escuchas a lo lejos un prolongado quejido.\n");
    SetIndoors(1);
    SetIntBright(40);

    AddExit("norte", ALULAGO("templo/tdhab22.c"));
    AddExit("sur", ALULAGO("templo/tdhab12.c"));
    AddExit("sudeste", ALULAGO("templo/tdpas13.c"));
    AddExit("nordeste", ALULAGO("templo/tdpas15.c"));

    AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 1);
}
