/***
Fichero: bosque_01.c
Autor: kastwey@simauria
Descripción: Bosque de siempreunidos.
Creación: 17/12/2004
***/

#include "path.h"
#include <moving.h>

inherit HAB_BOSQUE_PUESTO("bosque_base");

int ir_shadezzar();

create()
{
    ::create();
    SetIntLong(W("Te encuentras en la parte sur del pequeño bosque del pueblo de Siempreunidos.\n"
    "Hacia el sur puedes ver la puerta que comunica con la casa de Shadezzar, mientras que al norte te adentras en el bosque.\n"));
    AddDetail(({"puerta","sur","puerta del sur"}),"Es una puerta metálica normal y corriente.\n");
    SetOficina(HAB_PUESTO("casas/casa_shadezzar"));
    AddExit("norte",HAB_BOSQUE_PUESTO("bosque_03"));
    AddExit("noroeste","bosque_02");
    AddExit("nordeste","bosque_04");
    AddExit("sur",SF(ir_shadezzar));
}

int ir_shadezzar()
{
  	write(W("Empujas la puerta que cede produciendo un ligero chirrido metálico.\n"
  	"Pasas, y vuelves a cerrar.\n"));
  	say(W(capitalize(TP->QueryName()) + " empuja la puerta, que cede con un quejido metálico. Entra, y cierra tras de sí.\n"),TP);
  	if (TP->move(HAB_PUESTO("casas/casa_shadezzar"),M_GO,"sur") != ME_OK) return notify_fail(W("Por alguna razón no puedes salir hacia el sur.\n"
  	"Contacta con un wizard.\n"));
return 1;
}

