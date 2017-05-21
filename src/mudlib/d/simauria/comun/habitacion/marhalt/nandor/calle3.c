/****************************************************************************
Fichero: calle3.c
Autor: Ratwor
Fecha: 12/08/2007
Descripción: Calle principal de Nandor.
****************************************************************************/


#include "./path.h"

inherit SIM_ROOM;
create() {
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("la calle principal de Nandor");
    SetIntLong("Estás en la calle principal de la villa de Nandor. El suelo aquí "
        "está cubierto del polvo que se desprende de la tierra.\n  Al este se encuentra"
        " la plaza, con su fuente de agua cristalina.\n  Al norte puedes ver una "
        "casona sobria pero limpia: es el cuartel general del Gremio de Guerreros.\n "
        " Al sur ves otra casa cuyos dueños parecen no pasar mucho tiempo en ella,"
        " a juzgar por su apariencia descuidada.\n  Al este y oeste sigue la calle.\n");

    AddDetail(({"casa", "Edificacion", "edificación"}),
        "¿La del norte o la del sur?.\n");
    AddDetail(({"casa del norte","casa norte","casa no lujosa"
        "casa humilde", "casa limpia","casa no demasiado lujosa aunque limpia",
	    "casa humilde y limpia", "casa no lujosa y limpia", "gremio"}),
        "Es el cuartel general del gremio de guerreros, una simple edificación de "
        "dos plantas y paredes encaladas.\n");
    AddDetail(({"casa del sur","casa sur","casa descuidada"}),
        "Es una pequeña casa algo descuidada, pero firme todavía.\n");
    SetIndoors(0);
    AddExit("norte",GUILDS+"guerreros/sedes/nandor/sede_nandor");
    AddExit("sur","./casas/casa3s");
    AddExit("este","./calle41n");
    AddExit("oeste","./calle2");
    AddDoor("sur");
}
