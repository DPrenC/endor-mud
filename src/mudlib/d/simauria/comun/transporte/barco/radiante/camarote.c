/*
--------------------------------------------------------------------------------
DESCRIPCION : Camarotes de la goleta "Radiante" (ruta Berat-Gorat)
FICHERO     : /d/simauria/comun/transportes/barco/radiante/camarotes.c
MODIFICACION: 08-02-00 [Chaos@Simauria] Creacion

--------------------------------------------------------------------------------
*/

#include "./path.h"

inherit ROOM;

public void create()
{
    ::create();

    SetIntShort("los camarotes de la goleta 'Radiante'");
    SetIntLong("Est�s en el pasillo donde est�n los camarotes, delante de las escaleras "
        "que conducen a la cubierta. En frente ves una puerta que lleva al camarote del "
        "capit�n. Hacia la derecha se encuentran los camarotes de la tripulaci�n. \n");
    SetIndoors(1);
    SetIntBright(0); //No hay luz, se necesita una lampara o antorcha para ver algo

    //Ambientaci�n

    AddDetail(({"radiante", "Radiante", "goleta", "barco", "cubierta"}), QueryIntLong());
    AddDetail("camarotes", "Sus puertas est�n cerradas.\n");
    AddDetail("escaleras", "Son de madera y tiene ciertas partes podridas.\n");
    AddDetail("puerta", "Est� cerrada.\n");
    AddDetail("puertas", "Est�n cerradas.\n");

    AddExit("escaleras", BARCO("radiante/cubierta"));

  //AddExit("izquierda", BARCO("radiante/pasajeros"));
  //AddExit("derecha", BARCO("radiante/tripulacion"));
}
