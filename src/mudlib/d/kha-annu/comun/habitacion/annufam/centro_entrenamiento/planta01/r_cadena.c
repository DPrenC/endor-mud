/****************************************************************************
Fichero: r_cadena.c
Autor: Riberales
Fecha: 05/03/2006
Descripción: Sala de cadenas.
[t]: 28/02/2009 Añado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"cadena","cadenas"});

    SetIntShort("la sala de entrenamiento de cadenas");
    SetIntLong("Acabas de entrar a una de las salas de entrenamiento de lucha "
               "con cadenas del Centro de Adiestramiento de Guerreros Enanos. "
               "En líneas generales todo es más o menos como lo has venido "
               "viendo hasta ahora: nada de ornamentación, armas colgando de "
               "las paredes, antorchas y faroles para iluminar durante las "
               "horas de oscuridad y la ya típica enseña del dominio de "
               "Kha-annu presidiendo la sala. Desde luego hay que admitir que "
               "si lo que se pretende aquí es concentración para el combate, "
               "no hay muchas cosas que puedan distraer.\n");

    AddParedes();
    AddVentanaN();

    AddDetail(({"arma","armas","cadena","cadenas"}),
                "Estas cadenas serían la ilusión de cualquier carcelero. Las "
                "hay de todos los tamaños: con eslabones gordos, con eslabon"
                "es finos, con asideros para agarrarlas, sin asideros, de "
                "acero, de hierro... vamos, el material perfecto para una "
                "gran joyería, pero de guerra y destrucción.\n");

    AddExit("sur",HAB_PRIMERA_ANNUFAM("pasillo03"));
	AddDoor("sur");

	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
