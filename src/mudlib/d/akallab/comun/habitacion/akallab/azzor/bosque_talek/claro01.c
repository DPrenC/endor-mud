/*
DESCRIPCION  : Claro en el bosque
FICHERO      : claro01.c
MODIFICACION : 10-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetPreIntShort("junto a");
    SetIntShort("la caba�a en el claro en el bosque");
    SetIntLong("Est�s junto a la caba�a que hay en el claro del bosque. La "
        "caba�a es una peque�a construcci�n de madera con una humeante "
        "chimenea de piedra adosada. La puerta de la caba�a queda justo al "
        "norte de aqu�. El camino del Este cruza el claro del bosque al sur "
        "de aqu�.\n");
    AddDetail(({"puerta"}),"Est� justo delante de ti, al norte. Permite "
        "entrar en la caba�a.\n");
    AddDetail(({"chimenea"}),"La chimenea est� construida con bloques de "
        "piedra para poder resistir el calor del fuego. Est� adosada a la "
        "cara oeste de la caba�a de la curandera.\n");
    AddDetail(({"claro"}),"Es una extensi�n de pradera sin �rboles en el "
        "medio del bosque. No deja de resultarte sorprendente que siendo "
        "este bosque m�s bien espeso haya aqu� un claro.\n");
    AddDetail(({"cabanya","cabanya de madera","caba�a","caba�a de madera"}),
        "Es una peque�a construcci�n que hay al noroeste del claro del "
        "bosque. Supones que en ella debe vivir una conocida curandera de la "
        "que has oido hablar. Dicen que es capaz de preparar poderosas "
        "pociones y ung�entos con ingredientes que se encuentran en este "
        "bosque.\n");
    AddExit("sur",BOSQUE_TALEK("camino05"));
    AddExit("este",BOSQUE_TALEK("camino07"));
    AddExit("sudeste",BOSQUE_TALEK("claro00"));
    AddExit("norte",BOSQUE_TALEK("cabanya"));
    AddItem(OTRO("palo"),REFRESH_DESTRUCT,1);
}
