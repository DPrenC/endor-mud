/****************************************************************************
Fichero: r_marciales.c
Autor: Riberales
Fecha: 17/03/2006
Descripción: Habitación de entrene en artes marciales.
[t]: 28/02/2009 Añado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

//Como aquí no hay armas, pasamos a 0 la función de coger.
cmd_coger(string str)
{
    return 0;
}

create()
{
    ::create();
	tipo_arma=({"ninguna"});


    SetIntShort("la sala de artes marciales");
    SetIntLong("En esta habitación no ves armas colgadas en las paredes, así "
               "es que sólo puede tratarse de la sala de artes marciales. Con "
               "armas o sin armas, estos enanos están dispuestos a poner las "
               "cosas complicadas a quien se les ponga por delante.\n");


    AddVentanaS();

    AddDetail(({"pared","paredes"}),
                "Las paredes son todo un homenaje a la sobriedad. Lo único "
                "que presentan son unas antorchas y la enseña de Kha-annu. En "
                "la pared sur también puedes ver una ventana que da luz "
                "durante el día.\n");


    AddExit("norte", HAB_PRIMERA_ANNUFAM("pasillo10"));
	AddDoor("norte");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
