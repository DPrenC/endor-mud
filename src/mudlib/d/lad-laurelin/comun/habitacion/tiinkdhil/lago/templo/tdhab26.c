/*****************************************************************************************
 ARCHIVO:       tdhab26.c
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
    SetIntLong("El comedor era bastante extenso, pues aqu� se congregaban todos los "
          "monjes para sus menesteres. Por lo que sabes, en este templo sol�an alojar a "
          "enfermos, peregrinos y a alg�n ni�o abandonado.\n");
    SetIndoors(1);
    SetIntBright(30);

    AddExit("oeste", ALULAGO("templo/tdhab27.c"));
    AddExit("sur", ALULAGO("templo/tdhab21.c"));

    AddItem(ALUPNJ("adepto"), REFRESH_DESTRUCT, 1);
}
