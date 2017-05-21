/****************************************************************************
Fichero: camino32.c
Autor: Ratwor
Fecha: 27/12/2007
Descripción: El camino del norte de Marhalt.
****************************************************************************/

#include "./path.h"
#include <moving.h>
inherit CAMINOS "/norte_marhalt/camino_base";

public int entrar_senda(){
    if (!TP) return 0;
    if (query_once_interactive(TP)) {
        write("Te internas en la extraña senda.\n");
        TP->move(ROOMFS("senda20"),M_GO,"nordeste");
        return 1;
    }
    tell_room(TO, TP->QueryShort()+" mira con curiosidad la senda que comienza "
    "hacia el nordeste.\n");
    return 1;
}


create(){
    ::create();
    SetIntLong(QueryIntLong()+ "Entre la frondosidad del bosque de cored, Una extrecha "
    "senda se interna en las profundidades de la espesura hacia el nordeste.\n");
    AddDetail(({"senda", "extrecha senda", "nordeste", "al nordeste"}),
    "Entre la espesa vegetación hay un pequeño sendero fácilmente penetrable.\n");
    AddExit("oeste", "./camino33");
    AddExit("sudeste", "./camino31");
    AddExit("nordeste", SF(entrar_senda));

}

