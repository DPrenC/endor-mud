/****************************************************************************
Fichero: Thualin_06.c
Autor: Riberales
Creación: 02/10/2005
Descripción: Un tramo de la calle Thualin.
****************************************************************************/

#include "./path.h"
inherit HAB_THUALIN_ANNUFAM("thualin_base");



public void create()
{
    ::create();

    SetIntShort("la calle Thualin");
    SetIntLong(W("Caminas por la calle Thualin, nunca dejando la pared del "
                 "Centro. Esta parte es un poco más tranquila, aunque al "
                 "oeste escuchas algunos ruidos metálicos. Al este, sin "
                 "embargo, sigues la calle hasta la plaza Belthain. Unas "
                 "antorchas impiden que esto quede a oscuras por la noche.\n"));


    AddSuelo();
    AddAntorchas();


    AddExit("oeste",HAB_THUALIN_ANNUFAM("thualin_07"));
    AddExit("este",HAB_THUALIN_ANNUFAM("thualin_05"));
	AddExit("sur",HAB_CIUDAD_ANNUFAM("alistamiento"));
}
