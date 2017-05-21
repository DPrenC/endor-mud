/***
Fichero: hab_siempreunidos.c
Autor: kastwey@simauria
Creaci�n: 12/12/2004
Descripci�n: Habitaci�n base de Siempreunidos.
***/

#include "path.h"

inherit STD_FAERIA("hab_faeria");

public string QueryOficina();
public string SetOficina(string ruta);
static string pOficina;

create()
{
    ::create();
    SetLocate("Pueblo de Siempreunidos");
}

public string SetOficina(string ruta) { return pOficina = ruta; }

public string QueryOficina() { return pOficina; }
