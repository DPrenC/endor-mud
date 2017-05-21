/* Archivo        descampado.c
   Autor:         Yalin y Lug
   Fecha:         07/05/2006
   Descripción:   Descampado en la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("abroom");

create ()
{
    ::create();
    SetIntShort("un descampado en la aldea de Sloch");
    SetIntLong("Estás dentro de un descampado en la aldea de Sloch. Algún día, en este lugar hubo "
    "una casa y un huerto similares a los que puedes ver en el resto de la aldea, pero fue "
    "derrivada por alguna extraña razón que se te escapa. A tu alrededor no ves más que "
    "escombros, hierbajos que crecen por todas partes y la suciedad que lo invade todo.\nHacia el "
    "oeste puedes volver a la calle.\n");
    SetIntNoise("Puedes oír el piar de algunos pajarillos y voces de personas a lo lejos.\n");
    SetIntSmell("Huele a tierra removida y a viejo.\n");
    AddDetail(({"escombros",}), "Por todo el solar se desperdigan piedras de "
        "lo que algún día fueron paredes, trozos de pizarras del techo y "
        "algunos pedazos de maderas medio podridas que formaban parte del "
        "interior de la casa.\n");
    AddDetail(({"suelo"}), "Es el solar en el que, algún día, hubo una casa. "
        "El suelo es irregular y los escombros se amontonan por todos lados.\n");
    AddDetail(({"hierbajos", "hierbas"}), "Son las malas hierbas que siempre "
    "crecen en los lugares abandonados por el hombre.\n");
    AddExit("oeste", SHERALD("calles/calle01"));
}
