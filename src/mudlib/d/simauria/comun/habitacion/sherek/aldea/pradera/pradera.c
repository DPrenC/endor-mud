/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera00.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripción: Base para la pradera al sur de la aldea.
****************************************************************************/

#include "path.h"
#include <sounds.h>
inherit SHERALD("abroom");

public void poner_pnj()
{
    switch (d8())
    {
        case 1..3:
            int hora = QueryServer()->QueryState();
            if ((hora >= ND_PRENOON) && (hora <= ND_FALL)) AddItem(PNJ("sherek/aldea/ninyo"),REFRESH_DESTRUCT,1);
        break;
        case 4:
            AddItem(PNJ("sherek/aldea/guardian"),REFRESH_DESTRUCT,1);
        break;
        default: break;
    }
}

public string ruidos()
{
    switch (QueryServer()->QueryState())
    {
        case ND_PRENIGHT:
        case ND_NIGHT:
        case ND_PREDAWN:
        case ND_DAWN:
            return "El profundo silencio de una aldea dormida, interrumpido "
                "tan sólo por el murmullo del río cercano y los pasos "
                "marciales de algunos guardianes.\n";
        break;
        default:
            return "Suenan cantos de pájaros y risas de niños, con el "
                "murmullo impreciso de los animales de la granja cercana.\n";
        break;
    }
    return "";
}

create()
{
    ::create();
    SetIntShort("una pradera al sur de la aldea");
    SetIntLong("Una extensión de terreno llano, tapizado de hierba, baja en "
        "suave pendiente desde la aldea hasta el río, al sur.\nAquí suelen "
        "celebrarse los bailes y festejos en la fiesta de la cosecha, y es "
        "un lugar muy a propósito para que jueguen los niños, los abuelos "
        "pesquen o paséen al aire, y las mujeres se sienten a coser cuando "
        "hace buen tiempo.\n");
    SetIntSmell("Huele a hierba fresca.\n");
    SetIntNoise(SF(ruidos),1);
    AddDetail(("hierba"), "Es fresca, verde y suave. Dan ganas de echarse a "
        "dormir en ella.\n");
}

void init()
{
    ::init();
    object ob;
    ob = present("to_delete",TO);
    int hora = QueryServer()->QueryState();
    if ((ob) && ((hora >= ND_PRENIGHT) || (hora <= ND_SUNRISE))) ob->remove();
}
