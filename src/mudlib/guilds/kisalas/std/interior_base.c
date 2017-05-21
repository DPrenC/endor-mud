/****************************************************************************
Fichero: base_interior.c
Autor: Kastwey
Fecha: 13/02/2006
Descripci�n: El archivo base para las habitaciones interiores del gremio de Kisalas.
****************************************************************************/


#include "path.h"

inherit ROOM;

private int pDetalleRelieves, pDetalleGrabados;
// para que no se puedan a�adir dos veces los mismos detalles (por si acaso...)

public void create()
{
    ::create();

    // sonidos, olores, luz y entorno
    SetIntNoise("No escuchas nada, aparte del silencio.\n");
    SetIntSmell("Percibes el inconfundible olor de la magia.\n");
    SetLocate("el gremio de las Kisalas");
    SetIndoors (1);
    SetIntBright(45);

    // detalles comunes:
    AddDetail (({"espirales","luz","espiral"}),
               "Ves unas espirales fosforescentes, que dan luminosidad al lugar.\n"
               "Las espirales son uno de los sistemas mas antiguos empleados por los "
               "" "elfos para iluminar las habitaciones. Est�n hechas con alg�n "
               "derivado del f�sforo, aunque hay quien asegura que lo que en verdad "
               "las ilumina es la presencia de alg�n tipo de magia.\n");

    AddDetail (({"sello","simbolo","s�mbolo","sellos","simbolos","s�mbolos"}),
               "Ves el s�mbolo de las Kisalas, consiste en una S y una K "
               "entrelazadas situadas en el centro de una espiral.\n");

}

// funciones para a�adir detalles

public int AddDetalleRelieves()
// a�ade los detalles de los relieves
{
    if (pDetalleRelieves) return 0;

    AddDetail(({"relieve","bajorrelieve","relieves","bajorrelieves"}),
                "Son relieves que representan diferentes momentos hist�ricos "
                "de las Kisalas.\n");
    return pDetalleRelieves = 1;
}


public int AddDetalleGrabados()
// a�ade los detalles de los grabados
{
    if (pDetalleGrabados) return 0;

    AddDetail(({"grabado","grabados"}),
                "Son unos grabados que ilustran la vida de las Kisalas.\n");
    return pDetalleGrabados = 1;
}

