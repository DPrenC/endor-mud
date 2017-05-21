/****************************************************************************
Fichero: train_base.c
Autor: Kastwey
Fecha: 04/02/2006 18:11public int allow_enter(int method, mixed
Descripción: La habitación base de los entrenamientos. Se controla aqí la
entrada de los jugadores que no son guardabosques
****************************************************************************/

#include <gremios.h>
#include <moving.h>

inherit ROOM;

public int allow_enter(int method, mixed extra)
{
    object prev = PO;
    if (!prev || !interactive(prev)) return ::allow_enter(method, extra);
    if (prev->QueryGuild()!=GC_GUARDABOSQUES && !query_wiz_level(prev))
    {
      tell_object(prev,"No se permite el acceso a los jugadores que no "
                       "son guardabosques.\n");
        return ME_NO_ENTER;
    }
    return ::allow_enter(method, extra);
}
create()
{
    ::create();
    SetIndoors(0);
}

