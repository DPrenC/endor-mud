/* Carchivo:        caminorio05.c
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
    SetIntLong("Estás en una especie de pequeña plataforma donde termina el camino que baja desde "
    "la aldea de Sloch hacia el río Kandal.\nAl suroeste de aquí puedes ver una pequeña "
    "construcción que alberga el lavadero, hacia el norte asciende un camino hacia la aldea y al "
    "este está laentrada a los viñedos.\n");
    SetIntSmell("Huele a campo.\n");
    SetIntNoise("Puedes escuchar el sonido del agua en el río.\n");
    AddDetail(({"suelo"}), "Está formado por tierra endurecida de tanto ser "
        "pisada por los viandantes que caminan por aquí. En algunos lugares "
        "está salpicado por grandes lajas planas.\n");
    AddDetail(({"laja", "lajas", "piedra", "piedras"}), "son algunas grandes "
        "piedras de color blancuzco que salpican el sendero en el que estás.\n");
    AddDetail(({"rio", "río", "Kandal", "cauce"}), "Es el cauce del Río "
        "Kandal que pasa encajado entre grandes rocas. Tiene bastante fuerza, "
        "por lo que no sería buena cosa caerse aquí al agua.\n");
    AddDetail(({"suroeste", "lavadero", "construcción", "edificación"}), "es "
        "un pequeño cobertizo en cuyo interior está el lavadero que usan los "
        "habitantes de la aldea.\n");
    AddDetail(({"este", "viñedos", "viñedo"}), "Es una pequeña extensión de "
        "tierras dedicadas al cultivo de la vid. Las zepas están en hileras "
        "y casi a ras del suelo apoyadas en varales para que sea más fácil "
        "recoger el fruto en tiempos de vendimia.\n");
    AddExit("norte", SHERALD("calles/caminorio04"));
    AddExit("suroeste", SHERALD("calles/lavadero"));
    AddExit("este", SHERALD("campo/vinyedo00"));
}
