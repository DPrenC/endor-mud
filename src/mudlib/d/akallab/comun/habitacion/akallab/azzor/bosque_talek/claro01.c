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
    SetIntShort("la cabaña en el claro en el bosque");
    SetIntLong("Estás junto a la cabaña que hay en el claro del bosque. La "
        "cabaña es una pequeña construcción de madera con una humeante "
        "chimenea de piedra adosada. La puerta de la cabaña queda justo al "
        "norte de aquí. El camino del Este cruza el claro del bosque al sur "
        "de aquí.\n");
    AddDetail(({"puerta"}),"Está justo delante de ti, al norte. Permite "
        "entrar en la cabaña.\n");
    AddDetail(({"chimenea"}),"La chimenea está construida con bloques de "
        "piedra para poder resistir el calor del fuego. Está adosada a la "
        "cara oeste de la cabaña de la curandera.\n");
    AddDetail(({"claro"}),"Es una extensión de pradera sin árboles en el "
        "medio del bosque. No deja de resultarte sorprendente que siendo "
        "este bosque más bien espeso haya aquí un claro.\n");
    AddDetail(({"cabanya","cabanya de madera","cabaña","cabaña de madera"}),
        "Es una pequeña construcción que hay al noroeste del claro del "
        "bosque. Supones que en ella debe vivir una conocida curandera de la "
        "que has oido hablar. Dicen que es capaz de preparar poderosas "
        "pociones y ungüentos con ingredientes que se encuentran en este "
        "bosque.\n");
    AddExit("sur",BOSQUE_TALEK("camino05"));
    AddExit("este",BOSQUE_TALEK("camino07"));
    AddExit("sudeste",BOSQUE_TALEK("claro00"));
    AddExit("norte",BOSQUE_TALEK("cabanya"));
    AddItem(OTRO("palo"),REFRESH_DESTRUCT,1);
}
