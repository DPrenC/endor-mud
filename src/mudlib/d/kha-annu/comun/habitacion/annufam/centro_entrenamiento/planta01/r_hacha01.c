/****************************************************************************
Fichero: r_hacha01.c
Autor: Riberales
Fecha: 21/02/2006
Descripción: Habitación de hachas
****************************************************************************/



#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
	tipo_arma = ({"hacha","hachas"});

    SetIntShort("la sala de hachas");
    SetIntLong("Has llegado a la que parece la sala de lucha más importante "
               "del centro de entrenamiento de guerreros enanos de Annufam, "
               "la sala de lucha con hacha. Esta es el arma por excelencia de "
               "los enanos y se tenía que notar incluso en la decoración. En "
               "esta, además de la típica enseña del dominio de Kha-annu, "
               "también hay una pintura en la prolongación de la sala hacia "
               "el oeste.\n");

    AddParedes();
    AddVentanaS();

    AddDetail(({"pintura","imagen","cuadro"}),
                "En la pared del fondo de la sala hay una pintura que ocupa "
                "todo lo ancho y que representa una escena de lucha. Quizá "
                "acercándote puedas verla mejor.\n");

    AddDetail(({"arma","armas","hacha","hachas"}),
                "Las hachas son las armas que más utilizan los enanos, e "
                "imaginas que será por eso que las que tienes ante ti "
                "resultan tan contundentes. Desde luego estás seguro de que "
                "con esos dobles filos, o con los filos sencillos... o con "
                "cualquiera de esos pedazos de acero con empuñadura, un enano "
                "enfadado puede ser muy peligroso.\n");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("pasillo01"));
	AddDoor("norte");
    AddExit("este",HAB_PRIMERA_ANNUFAM("r_hacha02"));
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
