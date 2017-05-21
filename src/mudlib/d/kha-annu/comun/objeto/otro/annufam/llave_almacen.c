/****************************************************************************
Fichero: llave_almacen.c
Autor: Tagoras
Creaci�n: 28/02/2009
Descripci�n: llave del almacen del centro
****************************************************************************/

#include "./path.h"

inherit THING;

public void create()
{
    ::create();
    SetShort("la llave del armario");
    SetLong("Es una peque�a llave met�lica que sirve para abrir el armario del almac�n.\n");
    AddId(({"llave", "llave metalica", "llave met�lica", "llave_almacen_annufam", "llave del armario"}));
    SetValue(0);
    SetWeight(50);
}
