/* Archivo        descampado.c
   Autor:         Yalin y Lug
   Fecha:         07/05/2006
   Descripci�n:   Descampado en la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("abroom");

create ()
{
    ::create();
    SetIntShort("un descampado en la aldea de Sloch");
    SetIntLong("Est�s dentro de un descampado en la aldea de Sloch. Alg�n d�a, en este lugar hubo "
    "una casa y un huerto similares a los que puedes ver en el resto de la aldea, pero fue "
    "derrivada por alguna extra�a raz�n que se te escapa. A tu alrededor no ves m�s que "
    "escombros, hierbajos que crecen por todas partes y la suciedad que lo invade todo.\nHacia el "
    "oeste puedes volver a la calle.\n");
    SetIntNoise("Puedes o�r el piar de algunos pajarillos y voces de personas a lo lejos.\n");
    SetIntSmell("Huele a tierra removida y a viejo.\n");
    AddDetail(({"escombros",}), "Por todo el solar se desperdigan piedras de "
        "lo que alg�n d�a fueron paredes, trozos de pizarras del techo y "
        "algunos pedazos de maderas medio podridas que formaban parte del "
        "interior de la casa.\n");
    AddDetail(({"suelo"}), "Es el solar en el que, alg�n d�a, hubo una casa. "
        "El suelo es irregular y los escombros se amontonan por todos lados.\n");
    AddDetail(({"hierbajos", "hierbas"}), "Son las malas hierbas que siempre "
    "crecen en los lugares abandonados por el hombre.\n");
    AddExit("oeste", SHERALD("calles/calle01"));
}
