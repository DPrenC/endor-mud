/* Archivo: /d/simauria/comun/pnj/abadia/serpiente.c
* DESCRIPCION  : serpiente para el camino de Nandor a la abadía de Sherek.
* Autor: Lug y Yalin.
*/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("una culebra","culebra",([ GC_TORPE: 5]),GENERO_FEMENINO);
    SetShort("una culebra");
    SetLong("Es una culebra de color marrón oscuro con un dibujo verdoso en "
        "forma de escalera. Sería un buen cinturón.\n");
    AddId(({"culebra","serpiente","reptil"}));
    SetSize(1);
    SetWeight(1000);
    SetMaxHP(57);
    SetHP(QueryMaxHP());
    SetInt(1);
    SetCon(5);
    SetStr(6);
    SetDex(6);
    SetHands(({ ({"colmillos",3,2}) }));
    SetAlign(-50);
    SetNoGet("La culebra te ve la intención y se resbala entre las hierbas");
    SetGoChance(90);
    AddWalkZones("/d/simauria/comun/habitacion/caminos/nandor-sherek");
}

