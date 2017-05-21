/*****************************************************************************************
 ARCHIVO:       hab_bosque.c
 AUTOR:         Ztico
 FECHA:         12-03-2005
 DESCRIPCI�N:   Habitaci�n estandard general para el bosque m�gico de Faeria.
 COMENTARIOS:   12-03-2005 De momento es simple, pero lo hago por si luego tengo que
                           poner m�s cosas.
*****************************************************************************************/

#include "./path.h"

inherit STD_VALINOR("hab_valinor");
inherit "/std/room/room_bosque";
create()
{
    if(::create()) return 1;

    SetLocate("Valmar");
    SetHaylenya(1);
    SetMaxLenya(d10(2));
    SetCantidadLenya(QueryMaxLenya());
    SetHayarboles(1);
    SetMaxArboles(d3());
    SetCantidadArboles(QueryMaxArboles());
    SetTipoArboles("roble");
}
