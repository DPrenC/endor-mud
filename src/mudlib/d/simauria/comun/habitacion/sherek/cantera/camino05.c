/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/cantera/camino05.c
Autor: Lug y Yalin
Fecha: 27/08/2006
Descripci�n: camino a la cantera.
****************************************************************************/

#include "path.h"
inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("los dominios de Sherek");
    SetIntShort("el camino a la cantera");
    SetIntLong("Est�s en un camino ancho que une el camino de la abad�a con "
         "la cantera de donde los monjes consiguen las piedras para sus "
        "construcciones.\nEl terreno est� aplanado, debido a los muchos "
        "bloques de piedra que se han bajado arrastrando hasta el camino "
        "principal para ser cargados y transportados a su destino.\nHacia el "
        "norte, el camino asciende por la monta�a en direcci�n a la cantera, "
        "mientras que al sur baja hasta el camino principal.\n");
    SetIndoors(0);
    SetIntSmell("Sientes el efecto seco y acre del polvo de granito.\n");
    SetIntNoise("Se oye el eco lejano de las mazas de los picapedreros.\n");
    AddDetail(({"suelo","terreno","piso"}), "El terreno es plano y pelado, "
        "a causa de arrastrar por �l pesados bloques de piedra.\n");
    AddExit("sur", SHERCAN("camino04"));
    AddExit("norte", SHERCAN("camino06"));
}
