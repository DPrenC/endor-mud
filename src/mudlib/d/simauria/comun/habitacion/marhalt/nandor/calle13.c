/****************************************************************************
Fichero: calle13.c
Autor: Ratwor
Fecha: 01/11/2006
Descripción:  la calle Narwhald.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("la calle Narwhald");
    SetIntLong("La calle Narwhald continúa de este a oeste, acompañada por más plantas a "
        "ambos lados de la calle y los lisos guijarros del suelo.\n  El edificio del "
        "sur es la parte trasera del cuartel general del gremio de guerreros, mientras que"
        " al norte ves una pequeña casa de color arcilla.\n");
    SetIntSmell("Notas distintos olores de las plantas que rodean la calle.\n");
    SetIndoors(0);
    AddDetail(({"guijarros","suelo"}), "Unos redondeados y brillantes guijarros cubren el"
        " suelo de la calle.\n");
    AddDetail(({"plantas","maceteros", "flores"}),
        "Distintas plantas y maceteros acompañan a la calle en toda su extensión.\n"
        "En esta zona de la calle te encuentras con begoñas, helechos y campanillas.\n");
    AddDetail(({"helechos", "campanillas", "begoñas"}), "Una curiosa convinación de colores"
        " con el conjunto de plantas  de la calle.\n");
    AddDetail(({"edificio","sur","edificio del sur"}), "Es el destartano gremio de "
        "guerreros.\n");
    AddDetail(({"casa","norte","casa del norte"}), "Una casa cerrada como "
    "otra cualquiera.\n");
    AddExit("oeste","./calle14");
    AddExit("este","./calle12");
    AddItem(PNJ("marhalt/pueblerinos_nandor"),REFRESH_DESTRUCT,2);
}
