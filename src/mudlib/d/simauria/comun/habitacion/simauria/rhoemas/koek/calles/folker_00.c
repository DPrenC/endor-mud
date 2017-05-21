/***************************************************************************************
 ARCHIVO:	folker_00.c
 AUTOR:		[z] Zomax
 FECHA:		08-11-2001
 COMENTARIOS:	Calle Folker de Koek
 ***************************************************************************************/

#include "./path.h"

inherit RHOESTD("roome");

create () {
    ::create();

    SetLocate("Koek");
    SetIntShort("la calle Folker");
    carcel=(RHOEHAB("koek/calles/folker_01"));

    AddExit("norte",RHOEHAB("koek/granja/granero"));
    AddExit("sur",RHOEHAB("koek/granja/pajar"));
    AddExit("este",RHOEHAB("koek/calles/folker_01"));
    AddExit("oeste",RHOEHAB("koek/granja/molino"));

    map[neu,des]="Te encuentras en la calle Folker, una de las principales vías del "+
 	    "pueblo. Al norte está el granero y al sur una pequeña casa. Al oeste "+
 	    "puedes ver el molino del pueblo y al este la calle sigue su camino. ";
}