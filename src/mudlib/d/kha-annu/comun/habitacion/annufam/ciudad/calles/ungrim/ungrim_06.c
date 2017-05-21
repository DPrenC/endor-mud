/****************************************************************************
Fichero: ungrim_06.c
Autor: Riberales
Creación: 27/09/2005
Descripción: Un tramo de la calle Ungrim.
****************************************************************************/

#include "./path.h"
inherit BASE_CIUDAD_ANNUFAM;



public void create()
{
    ::create();

    SetIntShort("la calle Ungrim");
    SetIntLong(W("Sigues caminando por la calle Ungrim. Vas dejando al este "
                 "la Avenida Real y te internas en la calle que parece que "
                 "acaba en unos veinte metros. Al norte se encuentran las "
                 "cuadras de la ciudad, donde descansan los caballos guiados "
                 "por los pocos que saben el camino, como por ejemplo, los "
                 "carteros o los tenderos que bajan a por provisiones. En la "
                 "pared sur observas una ventana.\n"));

    AddLuzAntorchas();
    AddSuelo();


    AddDetail(({"cuadra","cuadras"}),
              W("Son las cuadras de la ciudad, donde llegan los jinetes "
                "cuando suben de Kha-annu.\n"));


    AddDetail("ventana",W("Te acercas a la ventana y observas el interior de "
                          "la casa de Alibrilla.\n"));


    AddExit("norte",HAB_CIUDAD_ANNUFAM("cuadras"));
    AddExit("oeste",HAB_UNGRIM_ANNUFAM("ungrim_07"));
    AddExit("este",HAB_UNGRIM_ANNUFAM("ungrim_05"));
}
