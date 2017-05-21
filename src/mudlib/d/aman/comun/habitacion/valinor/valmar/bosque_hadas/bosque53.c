/*****************************************************************************************
 ARCHIVO:       bosque53.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCI�N:   Bosque de las Hadas.
 COMENTARIOS:   Details...
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntShort("el corredor norte");
    SetIntLong("Has llegado a lo que parece ser un corredor. Miles de peque�as piedras "
        "de colores cubren el suelo y entre �stas, por muy absurdo que pueda parecer, "
        "crecen florecillas de color dorado. De las paredes cuelgan ardientes "
        "antorchas, y a su alrededor revolotean extra�as luces de todo tipo "
        "semejantes a luci�rnagas.\n");
    AddDetail(({"piedras", "piedras de colores"}), "Rojas, amarillas, violetas, "
        "verdes... Es toda una explosi�n de colorido.\n");
    //AddDetail("piedra", W(".\n"));
    AddDetail(({"flores", "florecillas"}), "Son como soles en miniatura, su forma se "
        "asemeja a la de las cal�ndulas y tienen miles de peque�os p�talos de color "
        "del oro puro.\n");
    AddDetail(({"antorchas", "antorcha"}), "Dispersan luz y calor por doquier creando "
        "misteriosas sombras clandestinas.\n");
    AddDetail(({"luces", "extra�as luces", "luci�rnagas", "luciernagas"}), "Te acercas "
        "un poco m�s y te das cuenta de que no son luces ni luci�rnagas sino diminutos "
        "seres alados, cuya piel desnuda brilla ante las antorchas.\n");
    SetIndoors(1);
    SetIntBright(30);

    AddExit("norte", HAB_BOSQUE_HADAS("bosque58.c"));
    AddExit("sur", HAB_BOSQUE_HADAS("bosque48.c"));
}
