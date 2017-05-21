/****************************************************************************
Fichero: camino.c
Autor: Ratwor
Fecha: 19/11/2006
Descripción: El camino base hacia Berat.
****************************************************************************/


#include "./path.h"
inherit SIM_ROOM;

create()
{
    ::create();
    SetIntShort("el camino Ishtria-Berat");
    switch (d4())
    {
        case 1:
            SetIntLong(
            "Estás en el camino que va desde Ishtria a Berat, es una senda que transcurre"
            " en medio de un frondoso bosque, te aconsejaría que andaras con cuidado por "
            "lo que pueda pasar.\n");
            break;
        case 2:
            SetIntLong(
            "Estás en el camino que une Ishtria con Berat, es una senda poco transitada a"
            " pie, pues hay una diligencia que pasa regularmente por este camino, por ello"
            " puedes observar que esta bastante mal señalizado.\n");
            break;
        case 3:
            SetIntLong(
            "Estás en el camino que enlaza la ciudad de Berat con la capital Ishtria, "
            "es un camino poco seguro, por lo que te aconsejo que cojas cuando puedas "
            "la diligencia.\n");
            break;
        case 4:
            SetIntLong(
	        "En estos momentos estas en el camino que va de Berat a la capital de los "
	        "humanos Ishtria, la Gran Ciudad, el camino transcurre por un frondoso bosque"
	        " donde debe haber infinidad de animales que no puedes ver, pero que sientes "
	        "que están ahí.\n");
	        break;
    }

    if (d4()==1)
        AddItem(PNJ("camino/aveboske"),REFRESH_REMOVE, d2());
    SetIndoors(0);
    SetLocate("Camino Ishtria-Berat");
    AddDetail(({"bosque","camino"}), "El camino atraviesa el bosque de norte a sur.\n");
}

