/****************************************************************************
Fichero: avenida_02.c
Autor: Riberales
Creación: 6/10/2005
Descripción: Un trozo enchufao a posteriori, para poder meter la garita y
la torre sin que comiera espacio físico.
****************************************************************************/

#include "./path.h"

inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
    ::create();
    SetIntShort("la avenida real de Annufam");
    SetIntLong(W("Sigues caminando a lo largo de la avenida real. Todo sigue "
                 "siendo igual de espartano. Al norte observas como la "
                 "avenida es cruzada perpendicularmente por otra calle, "
                 "mientras que al sur se encuentra el principio de la misma, "
                 "junto al portón de entrada.\n"));

    AddDetail(({"pared este","este"}),
              W("Es la pared lateral de la vivienda del tendero Loinus. En "
                "ella, observas una ventana por donde le entra la claridad a "
                "la casa.\n"));

    AddDetail(({"ventana","ventana de pared"}),
              W("Es una ventana bastante vulgar. Dentro " + /*mirar_ventana()*/
                "...\n"));

    AddDetail("pared","¿Qué pared quieres mirar exactamente?\n");



    AddSuelo();
    AddLuzAntorchas();

    AddExit("sur",HAB_AVENIDA_ANNUFAM("avenida_01"));
    AddExit("norte",HAB_AVENIDA_ANNUFAM("avenida_03"));

}
