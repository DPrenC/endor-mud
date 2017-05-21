/****************************************************************************
Fichero: r_hacha02.c
Autor: Riberales
Fecha: 21/02/2006
Descripci�n: Otra habitaci�n de hachas.
****************************************************************************/



#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

create()
{
    ::create();
    tipo_arma = ({"hacha","hachas"});

    SetIntShort("la sala de hachas");
    SetIntLong("Est�s en la prolongaci�n de la sala de lucha con hacha. En la "
               "pared del fondo puedes ver una pintura en la que hay unos "
               "enanos luchando. La imagen resalta la crueldad y el caos de "
               "la guerra, y a la vez, incentiva a los enanos a que se "
               "identifiquen con ella.\n");

    AddParedes();
    AddVentanaS();

    AddDetail(({"arma","armas","hacha","hachas"}),
                "Las hachas son las armas que m�s utilizan los enanos, e "
                "imaginas que ser� por eso que las que tienes ante ti "
                "resultan tan contundentes. Desde luego est�s seguro de que "
                "con esos dobles filos, o con los filos sencillos... o con "
                "cualquiera de esos pedazos de acero con empu�adura, un enano "
                "enfadado puede ser muy peligroso.\n");

    AddDetail(({"imagen","pintura","cuadro"}),
                "Ves lo que resulta un panorama desolador de guerra y "
                "destrucci�n. El color predominante de la pintura es el rojo, "
                "debido a la abundancia de sangre de los cad�veres. El pintor "
                "se ha inspirado en una de las hist�ricas batallas del pueblo "
                "enano contra los orcos y en ella puedes ver a Ungrim, el "
                "h�roe de Kha-annu, cort�ndole la cabeza a un enemigo.\n");

    AddExit("oeste",HAB_PRIMERA_ANNUFAM("r_hacha01"));
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
