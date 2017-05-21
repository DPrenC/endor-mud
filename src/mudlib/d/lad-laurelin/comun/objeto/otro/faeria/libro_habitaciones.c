/***
Fichero: libro_habitaciones.c
Autor: kastwey@simauria
Descripción: El libro de registro de las habitaciones de la posada.
Creación: 04/12/2004
***/

#include "path.h"
#include <properties.h>

#define SAVE_HERE DOMAINLOGPATH "lad-laurelin/libro_habitaciones_faeria"

#define H_ALQUILADA 1
#define H_LIBRE 0

inherit THING;
public mapping AddHuesped(string nombre);
public mapping RemoveHuesped(string nombre);
public int compruebaHabitaciones();
public mapping QueryHuespedes();
public int AsignaHabitacion();
mapping pHuespedes = ([]);
int pHab1, pHab2, pHab3;

create()
{
    ::create();
    restore_object(SAVE_HERE);
    SetShort("El libro de registro de las habitaciones");
    SetLong("Es el libro donde Engelbergt lleva la cuenta de a qué huéspedes les ha alquilado las habitaciones.\n");
    AddId("libro");
    AddId("libro de registros");
    SetValue(0);
  Set(P_NOGIVE, 1);
  Set(P_NOGET, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
  Set(P_NOTAKE, 1);
}

public mapping AddHuesped(string nombre)
{
    if (compruebaHabitaciones() == 0) return 0;
    pHuespedes+=([nombre:AsignaHabitacion()]);
    save_object(SAVE_HERE);
    return pHuespedes;
}

public int compruebaHabitaciones()
{
    if (pHab1 != H_ALQUILADA)
        return 1;
    if (pHab2 != H_ALQUILADA)
        return 2;
    if (pHab3 != H_ALQUILADA)
        return 3;
    return 0;
}

public mapping RemoveHuesped(string nombre)
{
    if (!pHuespedes[nombre]) return pHuespedes;
    if (pHuespedes[nombre] == 1) pHab1 = H_LIBRE;
    else if (pHuespedes[nombre] == 2) pHab2 = H_LIBRE;
    else if (pHuespedes[nombre] == 3) pHab3 = H_LIBRE;
    pHuespedes = m_delete(pHuespedes, nombre);
    save_object(SAVE_HERE);
    return pHuespedes;
}

public mapping QueryHuespedes() { return pHuespedes; }


public int AsignaHabitacion()
{
    if (pHab1 != H_ALQUILADA)
    {
        pHab1 = H_ALQUILADA;
        return 1;
    }
    if (pHab2 != H_ALQUILADA)
    {
        pHab2 = H_ALQUILADA;
        return 2;
    }
    if (pHab3 != H_ALQUILADA)
    {
        pHab3 = H_ALQUILADA;
        return 3;
    }
    return 0;
}

