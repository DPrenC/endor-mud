/****************************************************************************
Fichero: cam_cortado15.c
Autor: Ratwor
Fecha: 19/08/2007
Descripción: El camino entre montañas que se dirije a la cueva de los trolls.
****************************************************************************/


#include "./path.h"
#include <properties.h>
inherit CAMINOS "/gremio/cam_cortado_base";
create(){
    ::create();
    SetLocate("desfiladero de Marhalt");
    SetIntShort("un acantilado");
    SetIntLong("  Has llegado a un pequeño entrante del desfiladero en la pared "
    "montañosa. Sólo te resta volver sobre tus pasos, pues frente a ti se alza un "
    "acantilado completamente liso, y a tu alrededor no ves mas que rocas y maleza.\n");
    AddDetail("acantilado", "Lo tienes frente a tí y se alza cientos de metros sobre "
    "tu cabeza.\n");
    AddExit("sureste", "./cam_cortado09");

}
