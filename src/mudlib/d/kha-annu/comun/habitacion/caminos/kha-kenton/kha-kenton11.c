/*
Autores: [T] Tagoras
[T] 15/04/2009 AÃ±ado salida desde el camino de kha-Annu a Kento para llegara a Annufam y pongo un cartel con las direcciones.
*/

#include "./camino.h"

create()
{
    ::create();
    SetIntShort("el camino  de Kha-Annu.");
    SetDesc();
	SetIntLong(QueryIntLong()+"Hay un cartel, tal vez debas leerlo.\n");
    SetIndoors(0);
    AddExit("noroeste",CAMINO+"kha-kenton10");
	AddExit("este", HAB_CAMINO_ANNUFAM("camino_01"));
    AddExit("sur",CAMINO+"kha-kenton12");
    SetLocate("Camino de Kha-Annu");
	AddReadMsg("cartel",
"Oficina de Obras Públicas de Kha-annu\n"
"-------------------------------------\n"
"Direcciones:\n\n"
"Kha-annu: noroeste\n"
"Annufam:  este\n"
"Kenton:   sur\n\n" );
}
