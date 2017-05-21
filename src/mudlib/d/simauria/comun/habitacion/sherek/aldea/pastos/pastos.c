/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pastos/pastos.c
Autor: Lug y Yalin
Fecha: 14/01/2007
Descripción: Base para los pastos de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("abroom");

public void pongo()
{
    switch (d3())
    {
        case 1:
            AddItem(PNJ("sherek/aldea/torob"),REFRESH_DESTRUCT,2);
        break;
        case 2:
            AddItem(PNJ("sherek/aldea/guardian"),REFRESH_DESTRUCT,1);
        break;
        default: break;
    }
}

create()
{
    ::create();
    SetIntShort("los pastos de la aldea de Sloch");
    SetIntLong("Estás sobre los pastos de la granja de la aldea de Sloch. "
        "Son utilizados para apacentar al numeroso ganado que se cría aquí.\n");
    SetIntNoise("Escuchas el canto de algún pájaro y los animales mientras "
        "pacen.\n");
    SetIntSmell("Huele a hierba y a humedad.\n");
    AddDetail(({"suelo"}), "La hierba nace por todos lados.\nEl terreno cae "
        "aquí en ligera pendiente hasta llegar al río.\n");
    AddDetail(({"hierba", "hierbas"}), "Nacen por todo el suelo y, en muchos "
        "lugares se ven ya pacidas por los rumiantes.\n");
}
