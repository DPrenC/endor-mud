#include "./path.h"
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetIntLong("Te encuentras en un sendero que une la ciudad de Kha-annu con el bosque de "
        "Kenton.\n");
    SetIndoors(0);
    AddExit("noroeste",CAMINO+"kha-kenton4");
    AddExit("sudeste",CAMINO+"kha-kenton6");
   SetLocate("Camino de Kha-Annu");
}

init()
{
    ::init();
    add_action("funcion_escalar","escalar");
}

int funcion_escalar(string str)
{
    if ( (str = "montaña") || (str == "la montaña"))
    {
        write("No puedes escalar la montaña sin un equipo adecuado\n");
        return 1;
    }
    else
    {
        write("Escalar el que?\n");
        return 1;
    }
}
