/*****************************************************************************************
 ARCHIVO:       tdpas12.c
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

    SetIntShort("un pasillo entre los dormitorios");
    SetIntLong("Este pasillo conduce a las habitaciones donde pernoctaban los monjes. "
          "Es un largo corredor iluminado por una extra�a l�mpara que cuelga del "
          "techo.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail(({"lampara", "l�mpara", "bola"}), "Es una bola que contiene un l�quido "
          "luminoso.\n");

    AddExit("norte", ALULAGO("templo/tdhab21.c"));
    AddExit("sur", ALULAGO("templo/tdhab11.c"));
}
