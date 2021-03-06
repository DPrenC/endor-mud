/****************************************************************************
Fichero: cam_cortado00.c
Autor: Ratwor
Fecha: 19/08/2007
Descripci�n: El camino entre las monta�as que va a psionicos y cueva de los trolls.
****************************************************************************/

#include "./path.h"
#include <moving.h>
inherit CAMINOS "/gremio/cam_cortado_base";

public int ir_camino(){
    write("Te internas entre la maleza frondosa del sudeste, apareciendo en un "
    "ancho camino.\n");
    say(CAP(TNAME)+" se interna entre la maleza frondosa.\n");
	    TP->move( CAMINOS "/simauria-gorat/camino04", M_SILENT);
    return 1;
}

create() {
    ::create();
    SetIntLong(" Te encuentras en una angosta garganta, excavada tiempo atr�s en la roca "
    "por la acci�n de corrientes de agua ya desaparecidas, que corre entre   escarpadas "
    "paredes ensanch�ndose un poco mas al noroeste, para formar un abrupto desfiladero "
    "que penetra en el p�treo coraz�n de la cordillera, mientras que al sudeste "
    "finaliza en un entrante cubierto de maleza sobre el camino.\n");
    AddDetail("maleza", " Cubriendo la parte baja de las paredes y obstruyendo la "
    "salida hacia el sureste, de forma que esta resulta casi imperceptible a simple "
    "vista, crece una maleza reseca constituida en su mayor parte por zarzas y plantas "
    "rastreras con las que ser�a muy f�cil enrredarse.\n");
    AddExit("sureste", SF(ir_camino));
    AddExit("noroeste","./cam_cortado01");
    HideExit("sureste",1);
}
