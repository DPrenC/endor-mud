/***
Fichero: recipiente.c
Autor: kastwey@simauria
Descripci�n: Recipiente que est� en las celdas del pueblo de Siempreunidos.
Esto es para salir de la c�rcel... se amontonan
Se llega al techo, se coge la ganz�a y......
Creaci�n: 06/12/2004
***/

#include "path.h"

inherit THING;

create()
{
    ::create();
    SetShort("un recipiente met�lico");
    SetLong("Es un recipiente de unos 50 cent�metros de alto. Supones que se utilizar� para ser llenado de agua para los presos de las celdas.\n");
    SetWeight(1000);
    SetValue(600);
    AddId("recipiente");
    AddId("bid�n");
    AddId("bidon");
    AddId("lata");
    AddId("recipiente_puesto_celdas");
}
