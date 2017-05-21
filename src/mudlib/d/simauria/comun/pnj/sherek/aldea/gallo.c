/* Archivo:         gallo.c
* Descripción:      gallo para la granja de Sloch.
* Autor:            Yalin y Lug.
* Fecha:            18/05/2006
*/

#include "path.h"
#include <properties.h>
#include <guild.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("un gallo","gallo",([ GC_LUCHADOR: 10]),GENERO_MASCULINO);
    SetShort("un gallo");
    SetLong("Es un gran gallo de corral de color negro. Por su actitud se nota que es el "
            "jefe del gallinero y que no tiene nadie que le haga sombra. Su cresta es grande "
            "y rojiza.\n");
    AddId("gallo");
    SetHP(QueryMaxHP());
    SetHands(({({"una pata",3,5}),
        ({"otra pata",3,5}),
        ({"el pico",3,7})}));
    SetWeight(4000);
    SetNoGet("El gallo amenaza con darte un terrible picotazo.\n");
    InitChats(5,({"El gallo canta: ¡Ki kiri kiiiiii!.\n",
                "El gallo se pavonea ante todo el corral.\n",
                "El gallo da un salto y se sube a una vara.\n",
                "El gallo come unos granos de cereal.\n"}));
}
