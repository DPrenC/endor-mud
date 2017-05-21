/*****************************************************************************************
 ARCHIVO:       tdhab12.c
 AUTOR:         Chantiel, Alura
 FECHA:         08-5-1997
 DESCRIPCIÓN:   Templo de Dehim.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;

int añadir_bicho();

public void create()
{
    ::create();

    SetIntShort("la habitación");
    SetIntLong("Aquí es donde los adeptos novicios solían reposar. Ves camas por todas "
          "partes, deterioradas por el tiempo. Entre la mugre, ves un baúl cerca de la "
          "pared.\n");
    SetIntBright(40);
    SetIndoors(1);
    AddDetail(({"baul", "baúl"}), "Es bastante grande. Parece que está tallado en "
          "oro.\n");
    SetIntNoise("Escuchas un largo y prolongado quejido. No viene de esta "
          "habitación.\n");

    AddExit("norte", ALULAGO("templo/tdpas14.c"));
    AddExit("este", ALULAGO("templo/tdpas13.c"));
    AddExit("oeste", ALULAGO("templo/tdhab13.c"));

    añadir_bicho();
}

int añadir_bicho()
{
    if ((1 + random(2)) == 1)
    {
    	   AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 2);
    	   return 1;
    }
    AddItem(ALUPNJ("vampiro"), REFRESH_DESTRUCT, 3);
    return 1;
}