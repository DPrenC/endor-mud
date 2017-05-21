/* Archivo:         casagranja06.c
   Autor:           Yalin y Lug
   Descripci�n:     dormitorio en la planta alta de la casa de los administradores en la granja de la aldea de Sloch
   Fecha:           25/05/2006
*/

#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("el dormitorio");
    SetIntLong("Est�s en un dormitorio en la planta alta de la casa de los "
        "administradores de la granja de la aldea de Sloch.\nAqu� puedes ver "
        "una habitaci�n con una gran cama con dosel en el centro, unas "
        "perchas clavadas en la pared para colgar ropas y, en uno de los "
        "extremos, un ba�l. Del techo cuelga una gran l�mpara.\nPuedes "
        "volver al comedor yendo hacia el oeste.\n");
    SetIntSmell("Aqu� huele ligeramente a alcanfor.\n");
    SetIntNoise("Puedes escuchar el sonido amortiguado del resto de la casa "
        "y de la calle.\n");
    AddDetail(({"suelo"}), "Se trata de un suelo de maderas pulidas. En la "
        "zona m�s cercana a la cama puedes ver unas alfombras.\n");
    AddDetail(({"pared", "paredes"}), "Son paredes de mamposter�a, como en "
    "el resto de la casa, pero en este cuarto han sido recubiertas con una "
    "chapa de madera de roble que le da un aspecto m�s c�lido.\n");
    AddDetail(({"techo"}), "El techo es un artesonado de tablas estrechas "
        "encajadas entre s� que separan la estancia del contacto directo con "
        "el tejado.\n");
    AddDetail(({"lampara", "l�mpara"}), "Es una l�mpara con cinco brazos que cuelga del techo, "
        "tiene una especie de bombas de fino cristal tallado donde, al "
        "anochecer, se encienden unas buj�as de sebo de cabra para iluminar "
        "la estancia.\n");
    AddDetail(({"alfombra", "alfombras"}), "est�n hechas de gruesa y suave "
        "lana, y rodean la cama por todos sus lados.\n");
    AddExit("oeste", SHERALD("casas/casagranja04"));
}
