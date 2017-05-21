/****************************************************************************
Fichero: camino04.c
Autor: Ratwor
Fecha: 12/11/2006
Descripci�n: El nuevo camino Gorat-Ishtria
****************************************************************************/

#include "./path.h"
#include <moving.h>
inherit CAMINOS "/simauria-gorat/camino_base";

public int ir_desfiladero(){
    write("Te internas entre la maleza frondosa del noroeste, apareciendo en un "
    "encajonado desfiladero.\n");
    say(CAP(TNAME)+" se interna entre la maleza frondosa.\n");
    TP->move( CAMINOS "/gremio/cam_cortado00", M_SILENT);
    return 1;
}

create()
{
    ::create();
    SetIntLong(QueryIntLong()+" En la monta�a que observas al norte durante todo el "
        "camino, aprecias cierta abundancia de maleza alta y frondosa.\n");
    AddDetail(({"salida","entrante"})," Al noroeste ves que puedes meterte, atravesando "
    "la abundancia de maleza,          entre las monta�as.\n");
    AddDetail(({"vegetacion", "vegetaci�n", "maleza"}),
    " Cubriendo la parte baja de las paredes de la monta�a,"
    "y obstruyendo una salida hacia el noroeste, de forma que esta resulta casi "
    "imperceptible a simple vista, crece una maleza reseca constituida en su mayor "
    "parte por zarzas y plantas rastreras con las que ser�a muy f�cil enrredarse.\n");
    AddExit("oeste", "./camino05");
    AddExit("este", "./camino03");
    AddExit("noroeste", SF(ir_desfiladero));
    HideExit("noroeste",1);
}
