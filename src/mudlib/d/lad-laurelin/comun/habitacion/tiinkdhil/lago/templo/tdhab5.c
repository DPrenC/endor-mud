/*****************************************************************************************
 ARCHIVO:       tdhab5.c
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

    SetIntShort("el salón");
    SetIntLong("Te encuentras en la esquina suroeste de la sala. Está bastante oscuro, "
          "pero consigues ver el soporte de una antorcha en la parte superior de la "
          "pared.\n");
    SetIndoors(1);
    SetIntBright(28);
    AddDetail("antorcha", "Puede que aún se pueda utilizar.\n");
    AddDetail("techo", "Es una inmensa bóveda decorada con expresivos dibujos del "
          "dios. Dehim es el sanador celestial, la esperanza de los enfermos.\n");

    AddExit("este", ALULAGO("templo/tdhab4.c"));
    AddExit("norte", ALULAGO("templo/tdhab9.c"));
    AddExit("nordeste", ALULAGO("templo/tdhab8.c"));

    AddItem("/obj/torch.c", REFRESH_REMOVE, 1);
    AddItem(ALUPNJ("adepto"), REFRESH_DESTRUCT, 2);
}
