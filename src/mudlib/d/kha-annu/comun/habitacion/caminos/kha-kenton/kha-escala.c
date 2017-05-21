#include "./path.h"
#include <moving.h>

#define CIMA "/d/Kha-annu/comun/habitacion/Kha-annu/afueras/montanya/"
inherit KHA_ROOM;

int no_climb();
int ok_climb();

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetIntLong("Sigues caminando tranquilamente cuando adviertes que en la pared de la montaña "
        "hay unas rocas que sobresalen ligeramente.\n");
    AddDetail("rocas","Algunas sobresalen de la pared. Tal vez podrías intentar escalar la "
        "montaña.\n");
    AddDetail(({"pared","montaña","montanya"}),"Parece que la cima de la montaña es accesible "
        "desde este punto.\n");
    SetIntBright(MAX_SUNBRIGHT);
    SetIndoors(0);
    AddExit("noroeste",CAMINO+"kha-kenton5");
    AddExit("este",CAMINO+"kha-kenton7");
    SetLocate("Camino de Kha-Annu");
}

init()
{
    ::init();
    add_action("subir","escalar");
}

int subir(string str)
{
    if ( str == "montaña" || str == "cima" || str == "" )
    {
        switch(TP->UseSkill("trepar") )
        {
            case -100..0:
                no_climb();
            break;
            default:
                ok_climb();
            break;
        }
    }
    return 1;
}

int no_climb()
{
    write("No te sientes capaz de subir la Montanya.\n");
    return 1;
}

int ok_climb()
{
    write("Empiezas a buscar puntos de apollo y alcanzas un rellano.\n");
    TP->move(CIMA+"monta01",M_GO);
    return 1;
}
