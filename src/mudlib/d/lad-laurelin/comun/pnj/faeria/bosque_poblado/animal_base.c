/***
Fichero: comadreja.c
Autor: kastwey@simauria
Descripción: animal base para el bosque de Siempreunidos.
Creación: 18/12/2004
***/

#include "path.h"
#include <moving.h>

inherit NPC;

void MePiro();

public varargs int DoDamage (int damage, int type, int gentle, mixed xtras)
{
    if (!xtras) xtras = ({({})});
    xtras += ({ ({0,0,0,SF(MePiro)}) });
    return ::DoDamage(damage, type, 1, &xtras);
}

void MePiro()
{
    string direccion, *direcciones;
    direcciones = m_indices(environment()->QueryPlainExits());
    if (!sizeof(direcciones))
    {
    	  tell_room(environment(),W(QueryName() + " huye asustad" + (QueryGender() == 2?"a":"o") + ".\n"));
    	  remove();
    	  return;
    }
    direccion = direcciones[random(sizeof(direcciones))];
    SetMsgOut("huye asustad" + (QueryGender() == 2?"a":"o") + " en dirección " + direccion);
    StopAllHunting();
    if (move(environment()->QueryPlainExits()[direccion],M_GO) != ME_OK)
    {
        tell_room(environment(),W(capitalize(QueryName()) + " huye asustad" + (QueryGender() == 2?"a":"o") + ".\n"));
        remove();
    }
}
