/*****************************************************************************************
 ARCHIVO:       tdhab28.c
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

    SetIntShort("el comedor");
    SetIntLong("Aqu� termina el comedor.\nVes una larga mesa que comienza en una "
          "esquina de la habitaci�n y termina en la otra.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail("mesa", "Est� en muy malas condiciones. Los a�os y las termitas no "
           "perdonan.\n");

    AddExit("este", ALULAGO("templo/tdhab27.c"));

    AddItem(ALUPNJ("mongord.c"), REFRESH_DESTRUCT, 1);
}
