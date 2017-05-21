/*
--------------------------------------------------------------------------------
DESCRIPCION : Bodega de la goleta "Radiante" (ruta Berat-)
FICHERO     : /d/simauria/comun/obejto/barco/radiante/bodega.c
MODIFICACION: 22-01-00 [Chaos@Simauria] Creacion

--------------------------------------------------------------------------------
*/

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("la bodega de la goleta Radiante");
    SetIntLong("Te encuentras en la bodega de la goleta 'Radiante'. En un rinc�n, "
        "pegadas a la pared, ves un mont�n de cajas de diferentes tama�os. Al lado de "
        "las cajas ves un mont�n de sacos. En el otro extremo de la bodega ves varios "
        "barriles de madera sujetos por cuerdas a las paredes para que no se muevan. Ves "
        "la escalera que lleva a cubierta.\n");
    SetIndoors(1);
    SetIntBright(0); //No hay luz, se necesita una lampara o antorcha para ver algo

    //Ambientacion

    AddDetail(({"radiante", "Radiante", "goleta", "barco", "cubierta"}), QueryIntLong());
    AddDetail(({"saco", "sacos"}), "Los sacos son de tela y est�n llenos de grano.\n");
    AddDetail(({"cajas", "caja"}), "Son unas cajas de madera y llevan mecanc�a diversa "
        "para el comercio.\n");
    AddDetail(({"barril", "barriles"}), "Est�n clasificados seg�n que tipo de bebida "
        "lleven. hay varios grupos: agua, ron y comida.\n");

    AddExit("subir", BARCO("radiante/cubierta"));
}
