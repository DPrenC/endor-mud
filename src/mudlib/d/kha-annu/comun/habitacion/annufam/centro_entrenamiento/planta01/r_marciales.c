/****************************************************************************
Fichero: r_marciales.c
Autor: Riberales
Fecha: 17/03/2006
Descripci�n: Habitaci�n de entrene en artes marciales.
[t]: 28/02/2009 A�ado puertas
****************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_ANNUFAM("r_base");

//Como aqu� no hay armas, pasamos a 0 la funci�n de coger.
cmd_coger(string str)
{
    return 0;
}

create()
{
    ::create();
	tipo_arma=({"ninguna"});


    SetIntShort("la sala de artes marciales");
    SetIntLong("En esta habitaci�n no ves armas colgadas en las paredes, as� "
               "es que s�lo puede tratarse de la sala de artes marciales. Con "
               "armas o sin armas, estos enanos est�n dispuestos a poner las "
               "cosas complicadas a quien se les ponga por delante.\n");


    AddVentanaS();

    AddDetail(({"pared","paredes"}),
                "Las paredes son todo un homenaje a la sobriedad. Lo �nico "
                "que presentan son unas antorchas y la ense�a de Kha-annu. En "
                "la pared sur tambi�n puedes ver una ventana que da luz "
                "durante el d�a.\n");


    AddExit("norte", HAB_PRIMERA_ANNUFAM("pasillo10"));
	AddDoor("norte");
	AddItem(PNJ_CENTRO_ANNUFAM("recluta"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("soldado"), REFRESH_DESTRUCT);
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT);
	AddWeapon();
}
