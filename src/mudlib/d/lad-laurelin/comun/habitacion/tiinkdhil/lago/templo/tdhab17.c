/*****************************************************************************************
 ARCHIVO:       tdhab17.c
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
    SetIntLong("Contin�as en el sal�n. Est�s en una esquina de la sala. Al sudeste "
          "puedes distinguir el contorno de un c�rculo grabado en el suelo.\n");
    SetIndoors(1);
    SetIntBright(25);
    AddDetail("techo", "Es una inmensa b�veda decorada con expresivos dibujos del "
          "dios. Dehim es el sanador celestial, la esperanza de los enfermos.\n");

    AddExit("este", ALULAGO("templo/tdhab16.c"));
    AddExit("sur", ALULAGO("templo/tdhab9.c"));
    AddExit("sudeste", ALULAGO("templo/tdhab8.c"));

    AddItem(ALUPNJ("monjef"), REFRESH_DESTRUCT, 1);
}
