/****************************************************************************
Fichero: llave_almacen.c
Autor: Tagoras
Creación: 28/02/2009
Descripción: llave del almacen del centro
****************************************************************************/

#include "./path.h"

inherit THING;

public void create()
{
    ::create();
    SetShort("la llave del armario");
    SetLong("Es una pequeña llave metálica que sirve para abrir el armario del almacén.\n");
    AddId(({"llave", "llave metalica", "llave metálica", "llave_almacen_annufam", "llave del armario"}));
    SetValue(0);
    SetWeight(50);
}
