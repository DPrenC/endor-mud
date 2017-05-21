/*
Fichero: pasillo3.c
Autor: aulë
Fecha: 31/03/2013
Descripción:  pasillos de la posada.
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bpasillo";
#include <moving.h>

public int ir_arriba(){
    write("Subes las escaleras de madera hasta la planta superior.\n"
     "Algunos escalones crujen y chirrían.\n");
    say(CAP(TNAME)+"  sube las escaleras hacia la planta superior mientras los "
    "escalones crujen y chirrían.\n");
    tell_room(HABITACION+"bree/poney_pisador/pasillo4", CAP(TNAME)+ " llega subiendo "
    "las escaleras desde el piso inferior.\n");
            TP->move( HABITACION+"bree/poney_pisador/pasillo4", M_GO);
    return 1;
}

create()
{
    ::create();
    	SetIntShort("un pasillo, junto a una escalera");
    	SetIntLong("El largo pasillo que se extiende hacia el oeste finaliza aquí junto a una escalera que sube a la planta superior.\n"
    	"Un farol cuelga juhto a la escalera, y al norte ves una puerta redonda que da entrada a uno de los cuartos para hobbits.\n"
    	"Suelos y paredes están levantados en piedra toscamente tallada.\n");
    	    	   AddDetail("suelo",
   "El suelo está hecho de losas de piedra muy antigua y pulida por el paso de "
   "innumerables pies.\n");
   AddDetail(({"muros", "paredes"}),
   "Los gruesos muros están levantados con pesados bloques de piedra de forma "
   "irregular y superficie toscamente alisada.\n");
   AddDetail("escalera",
   "Una gran escalera hecha en su totalidad de madera que asciende a la planta "
   "superior. Peldaños y barandilla están bien pulidos y barnizados.\n");

    	    SetIndoors(1);
    SetIntBright(20);
     AddExit("oeste", "./pasillo2");
     AddExit("norte", "./cuartohobbit2");
     AddExit("arriba", SF(ir_arriba));
     AddDoor("norte", "una puerta redonda",
     "Es una pequeña puerta redonda del estilo que gusta a los hobbits.\n"
     "Está hecha de madera que, aunque aparenta antigua, está bien pulida y barnizada.\n"
     "En el centro tiene una manilla de bronce de pomo redondeado para abrir y cerrar la puerta.\n",
     ({"norte", "n", "puerta norte", "puerta hobbit", "redonda", "puerta redonda"}));
    }