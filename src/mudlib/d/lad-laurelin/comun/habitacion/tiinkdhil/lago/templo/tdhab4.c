/*****************************************************************************************
 ARCHIVO:       tdhab4.c
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

    SetIntShort("el sal�n");
    SetIntLong("Est�s en la parte sur del sal�n del templo. El altar est� hacia el "
          "norte.\n");
    SetIndoors(1);
    SetIntBright(35);
    AddDetail("suelo", "Antes estaba enmoquetado. Observas restos de pisadas "
          "recientes...\n");
    AddDetail("altar", "Est� demasiado lejos para examinarlo.\n");
    AddDetail("techo", "Es una inmensa b�veda decorada con expresivos dibujos del "
          "dios. Dehim es el sanador celestial, la esperanza de los enfermos.\n");

    AddExit("este", ALULAGO("templo/tdhab3.c"));
    AddExit("oeste", ALULAGO("templo/tdhab5.c"));
    AddExit("norte", ALULAGO("templo/tdhab8.c"));
    AddExit("noroeste", ALULAGO("templo/tdhab9.c"));
    AddExit("nordeste", ALULAGO("templo/tdhab7.c"));

    AddItem(ALUPNJ("adepto"), REFRESH_DESTRUCT, 1);
}
