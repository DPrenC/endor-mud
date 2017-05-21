/* archivo: /d/simauria/comun/habitacion/sherek/aldea/calles/caminorio00.c
   Autor:           Yalin y Lug
   Descripción:     camino que conecta la aldea con el río, el lavadero y los viñedos
   Fecha:           29/05/2006
*/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetIntShort("el camino hacia el río");
    SetIntLong("Estás en un estrecho camino que desciende desde la aldea de "
        "Sloch hacia el río Kandal, tiene mucha pendiente, lo que hace que "
        "sea complicado subir o bajar con mucha carga por él.\nLos arbustos "
        "del bajo monte impiden ir en cualquier otra dirección que no sea la que "
        "propone este sendero.\n");
    SetIntSmell("Huele a campo.\n");
    SetIntNoise("Puedes escuchar el canto de los grillos a tu alrededor.\n");
    AddDetail(({"suelo"}), "Está formado por tierra endurecida de tanto ser "
        "pisada por los viandantes que caminan por aquí. En algunos lugares "
        "está salpicado por grandes lajas planas.\n");
    AddDetail(({"arbusto", "arbustos"}), "son brezos y retamas que conforman "
        "un espeso monte bajo.\n");
    AddDetail(({"laja", "lajas", "piedra", "piedras"}), "son algunas grandes "
        "piedras de color blancuzco que salpican el sendero en el que estás.\n");
    AddExit("nordeste", SHERALD("calles/callejuela01"));
    AddExit("sur", SHERALD("calles/caminorio01"));
}
