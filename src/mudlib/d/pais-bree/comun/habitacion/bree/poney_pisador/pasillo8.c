/*
Fichero: pasillo8.c
Autor: aulë
Fecha: 31/03/2013
Descripción:  pasillos de la posada. 
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bpasillo";
create()
{
    ::create();
    	SetIntShort("un pasillo");
    	    	   SetIntLong(QueryIntLong()+"En este lugar el pasillo cruza sobre la "
    	    	   "arcada de la posada y grandes ventanas cubiertas por cortinas se "
    	    	   "localizan a ambos lados.\n");
    	    	  AddDetail(({"ventanas", "ventanales"}),
    	    	  "Grandes ventanales que miran al este y al oeste.\n");
    	    	  AddDetail(({"ventana este", "ventanal este", "ventanal del este"}),
    	    	  "Ves el patio de la posada con el gran montón de leña y más allá, la "
    	    	  "ladera de la colina que asciende en forma cada vez más abrupta, con los "
    	    	  "perfiles redondeados de los agujeros hobbits que la jalonan.\n");
    	    	AddDetail(({"ventana oeste", "ventanal oeste", "ventanal del oeste"}),
    	    	"Observas la ladera en pendiente de la colina de Bree y los tejados que se "
    	    	"van sucediendo hasta el semicírculo que traza la empalizada y el foso,en la "
    	    	"parte baja, junto a la puerta occidental de la aldea.\n");
    	    	AddDetail("cortinas",
    	    	"Espesas cortinas que cuelgan frente a las ventanas.\n");
    	    SetIndoors(1);
    SetIntBright(20);
     AddExit("norte", "./pasillo7");
     AddExit("sur", "./pasillo9"); 
    }