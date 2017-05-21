/*****************************************************************************************
 ARCHIVO:       tdhab12.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCI�N:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;

int a�adir_bicho();

public void create()
{
    ::create();

    SetIntShort("la habitaci�n");
    SetIntLong("Aqu� es donde los adeptos novicios sol�an reposar. Ves camas por todas "
          "partes, deterioradas por el tiempo. Entre la mugre, ves un ba�l cerca de la "
          "pared.\n");
    SetIntBright(40);
    SetIndoors(1);
    AddDetail(({"baul", "ba�l"}), "Es bastante grande. Parece que est� tallado en "
          "oro.\n");
    SetIntNoise("Escuchas un largo y prolongado quejido. No viene de esta "
          "habitaci�n.\n");

    AddExit("norte", ALULAGO("templo/tdpas14.c"));
    AddExit("este", ALULAGO("templo/tdpas13.c"));
    AddExit("oeste", ALULAGO("templo/tdhab13.c"));

    a�adir_bicho();
}

int a�adir_bicho()
{
    if ((1 + random(2)) == 1)
    {
    	   AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 2);
    	   return 1;
    }
    AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 3);
    return 1;
}