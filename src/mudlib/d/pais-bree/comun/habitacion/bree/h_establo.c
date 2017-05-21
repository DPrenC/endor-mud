/*
Fichero: h_establo.c
Autor: Aulë
Fecha: 02/12/2014
Descripción: establo de la herrería.
*/
#include "./path.h"
inherit BREE_ROOM;

create()
{
    ::create();
    	SetIntShort("un pequeño establo");
    	SetIntLong(
    	"Te encuentras en un pequeño establo cuyo techo desciende suavemente hacia el "
    	"oeste. En el muro de este lado hay un pequeño ventanuco que proporciona "
    	"ventilación, y bajo dicho muro desaparece el canal de desagüe que recorre la "
    	"estancia de lado a lado. El suelo es de piedra irregular con argamasa y a lo "
    	"largo de la pared del sur hay un pesebre con sólidos postes de madera para "
    	"sujetar a los animales.\n");
    	AddExit("norte", "./h_patio");
        AddDoor("norte", "la puerta del establo",
"Es una sólida puerta de tablones que cierra el establo.\n",
    ({"establo", "norte", "puerta del norte", "puerta", "n"}));


    	}