/****************************************************************************
Fichero: r_hacha02.c
Autor: Riberales
Fecha: 21/02/2006
Descripción: Otra habitación de hachas.
****************************************************************************/



#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"hacha","hachas"});

    SetIntShort("la sala de hachas");
    SetIntLong("Estás en la prolongación de la sala de lucha con hacha. En la "
               "pared del fondo puedes ver una pintura en la que hay unos "
               "enanos luchando. La imagen resalta la crueldad y el caos de "
               "la guerra, y a la vez, incentiva a los enanos a que se "
               "identifiquen con ella.\n");

    AddParedes();
    AddVentanaS();

    AddDetail(({"arma","armas","hacha","hachas"}),
                "Las hachas son las armas que más utilizan los enanos, e "
                "imaginas que será por eso que las que tienes ante ti "
                "resultan tan contundentes. Desde luego estás seguro de que "
                "con esos dobles filos, o con los filos sencillos... o con "
                "cualquiera de esos pedazos de acero con empuñadura, un enano "
                "enfadado puede ser muy peligroso.\n");

    AddDetail(({"imagen","pintura","cuadro"}),
                "Ves lo que resulta un panorama desolador de guerra y "
                "destrucción. El color predominante de la pintura es el rojo, "
                "debido a la abundancia de sangre de los cadáveres. El pintor "
                "se ha inspirado en una de las históricas batallas del pueblo "
                "enano contra los orcos y en ella puedes ver a Ungrim, el "
                "héroe de Kha-annu, cortándole la cabeza a un enemigo.\n");

    AddExit("oeste",HAB_PRIMERA_ANNUFAM("r_hacha01"));
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
