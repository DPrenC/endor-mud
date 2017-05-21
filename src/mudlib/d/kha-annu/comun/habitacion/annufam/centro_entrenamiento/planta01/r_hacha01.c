/****************************************************************************
Fichero: r_hacha01.c
Autor: Riberales
Fecha: 21/02/2006
Descripci�n: Habitaci�n de hachas
****************************************************************************/



#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
	tipo_arma = ({"hacha","hachas"});

    SetIntShort("la sala de hachas");
    SetIntLong("Has llegado a la que parece la sala de lucha m�s importante "
               "del centro de entrenamiento de guerreros enanos de Annufam, "
               "la sala de lucha con hacha. Esta es el arma por excelencia de "
               "los enanos y se ten�a que notar incluso en la decoraci�n. En "
               "esta, adem�s de la t�pica ense�a del dominio de Kha-annu, "
               "tambi�n hay una pintura en la prolongaci�n de la sala hacia "
               "el oeste.\n");

    AddParedes();
    AddVentanaS();

    AddDetail(({"pintura","imagen","cuadro"}),
                "En la pared del fondo de la sala hay una pintura que ocupa "
                "todo lo ancho y que representa una escena de lucha. Quiz� "
                "acerc�ndote puedas verla mejor.\n");

    AddDetail(({"arma","armas","hacha","hachas"}),
                "Las hachas son las armas que m�s utilizan los enanos, e "
                "imaginas que ser� por eso que las que tienes ante ti "
                "resultan tan contundentes. Desde luego est�s seguro de que "
                "con esos dobles filos, o con los filos sencillos... o con "
                "cualquiera de esos pedazos de acero con empu�adura, un enano "
                "enfadado puede ser muy peligroso.\n");

    AddExit("norte",HAB_PRIMERA_ANNUFAM("pasillo01"));
	AddDoor("norte");
    AddExit("este",HAB_PRIMERA_ANNUFAM("r_hacha02"));
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
