/****************************************************************************
Fichero: r_mangual.c
Autor: Riberales
Fecha: 12/03/2006
Descripción: Habitación de entrene en manguales.
[t]: 28/02/2009 Añado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"mangual","manguales"});

    SetIntShort("la habitación de manguales");

    SetIntLong("Estás en una de las habitaciones del Centro de Adiestramiento "
               "de Guerreros Enanos de Annufam, dedicada al aprendizaje y "
               "mejora de los manguales. Por doquier observas armas de "
               "este tipo, de diferentes tamaños y formas.\n");

    AddParedes();
    AddVentanaN();

    AddDetail(({"mangual","manguales","armas","arma"}),
                "Son gruesas empuñaduras de madera o hierro a las que hay "
                "unidas una o varias cadenas rematadas con una enorme bola "
                "metálica. Con un golpe de uno de estos trastos puedes "
                "sacarle la cabeza del sitio a cualquier enemigo.\n");

    AddExit("sur",HAB_PRIMERA_ANNUFAM("pasillo07"));
	AddDoor("sur");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
