/***
Fichero: hab_faeria.c
Autor: kastwey
Descripción: Habitación estándard de Faeria.
Creación: 02/12/2004
20/12/2004
Añado el notify_leave para quitar el InformObj si el player lo tenía puesto, al salir de la zona.
***/


#include "../path.h"

inherit ROOM;

int haz_mirar(string str) {
    object room;
    if (!str || str!="tiempo") return 0;
    else
    {
        room = TO;
        if(room->QueryIndoors())
        {
            write("No puedes ver el tiempo que hace desde aqui.\n");
            return 42;
        }
        write(CHRONOS->QueryWeatherMsg());
        return 42;
    }
}


init()
{
    ::init();
    add_action("haz_mirar", "mirar");
    add_action("haz_mirar", "m");
    add_action("haz_mirar", "exa");
    add_action("haz_mirar", "examinar");
    if (!interactive(TP)) return;
    if (member(TP->QueryInformObjs(),(TABLON_ENEMIGOS)) <= -1)
    {
    	  TP->AddInformObj(TABLON_ENEMIGOS);
    }
}


create()
{
    ::create();
    SetLocate("Faeria");
    SetIntNoise("No oyes nada en especial.\n");
    SetIntSmell("No hueles nada en especial.\n");
    SetIndoors(0); // [Nyh] Esto pone el Server a NIGHTDAY
}

public void notify_leave(mixed from,int method,mixed extra)
{
	  if (!interactive(PO)) return ::notify_leave(from, method, extra);
	  if (strstr(object_name(environment(PO)),(HABITACION + "faeria"),0) <0)
	  // está fuera de la zona
	  {
        PO->RemoveInformObj(TABLON_ENEMIGOS);
	  }
    return ::notify_leave(from, method, extra);
}

