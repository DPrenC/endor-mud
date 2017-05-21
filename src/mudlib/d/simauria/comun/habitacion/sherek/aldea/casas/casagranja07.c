/* Archivo:         casagranja07.c
   Autor:           Yalin y Lug
   Descripción:     trastero en la planta alta de la casa de los administradores en la granja de la aldea de Sloch
   Fecha:           25/05/2006
*/

#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("el desván");
    SetIntLong("Estás en un pequeño trastero en la planta alta de la casa de "
        "los administradores de la granja de la aldea de Sloch.\nAquí todo "
        "es desorden y polvo. A tu alrededor solamente puedes ver entre las "
        "telas de araña, cachivaches inservibles.\n");
    SetIntSmell("Huele a viejo y a humedad.\n");
    SetIntNoise("Puedes escuchar el sonido amortiguado del resto de la casa "
        "y de la calle.\n");
    SetIntBright(30);
    AddDetail(({"suelo"}), "Se trata de un suelo de maderas sin trabajar.\n");
    AddDetail(({"pared", "paredes"}), "Son paredes de mampostería desnuda "
        "sin pintar ni forrar.\n");
    AddDetail(({"techo"}), "Ves, sobre ti, directamente las lajas de pizarra "
        "que forman el tejado de la casa.\n");
    AddDetail(({"cachivaches"}), "Son todas esas cosas que ya no nos sirven "
        "pero que nos empeñamos estúpidamente en no tirar.\n");
    AddExit("abajo", SHERALD("casas/casagranja04"));
}
