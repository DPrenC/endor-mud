/***
Fichero: recipiente.c
Autor: kastwey@simauria
Descripción: Recipiente que está en las celdas del pueblo de Siempreunidos.
Esto es para salir de la cárcel... se amontonan
Se llega al techo, se coge la ganzúa y......
Creación: 06/12/2004
***/

#include "path.h"

inherit THING;

create()
{
    ::create();
    SetShort("un recipiente metálico");
    SetLong("Es un recipiente de unos 50 centímetros de alto. Supones que se utilizará para ser llenado de agua para los presos de las celdas.\n");
    SetWeight(1000);
    SetValue(600);
    AddId("recipiente");
    AddId("bidón");
    AddId("bidon");
    AddId("lata");
    AddId("recipiente_puesto_celdas");
}
