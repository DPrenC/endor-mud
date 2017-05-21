/*****************************************************************************************
 ARCHIVO:       tdpas12.c
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

    SetIntShort("un pasillo entre los dormitorios");
    SetIntLong("Este pasillo conduce a las habitaciones donde pernoctaban los monjes. "
          "Es un largo corredor iluminado por una extraña lámpara que cuelga del "
          "techo.\n");
    SetIndoors(1);
    SetIntBright(40);
    AddDetail(({"lampara", "lámpara", "bola"}), "Es una bola que contiene un líquido "
          "luminoso.\n");

    AddExit("norte", ALULAGO("templo/tdhab21.c"));
    AddExit("sur", ALULAGO("templo/tdhab11.c"));
}
