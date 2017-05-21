/***************************************************************************************
 ARCHIVO:	entrada.c
 AUTOR:		[k] Korsario
 FECHA:		27-02-1998
 COMENTARIOS:	Entrada al poblado Kender de Flenton
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

object portal;

fgritos()
{
	   if (d4()>2) write("Oyes el bullicio del poblado, voces y risas... parece un lugar bastante "
	       "animado.\n");
	   else write("Escuchas risas de ni�os y algunas voces tras la empalizada... parece un lugar "
	       "bastante agradable para pasar unos d�as.\n");
}

create()
{
    ::create();
    SetLocate("flenton");
    SetIntShort("la entrada al poblado Flenton");
    SetIntLong("Est�s en la entrada del poblado Flenton. Desde aqu� puedes ver como una alta "
        "empalizada de madera rodea el poblado, y un gran �rbol sobresale entre las casas. "
        "Hay un puesto de frutas a un lado del camino. Ves una gran puerta de madera abierta "
        "de par en par, como si nunca se cerrase.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el bullicio del poblado tras la empalizada.\n");
    SetIntSmell("Hueles el aroma de las flores que bordean el camino.\n");
    AddDetail(({"empalizada","valla"}),"Es una alta empalizada de madera que rodea "
   	    "todo el poblado.\n");
    AddDetail(({"madera"}),"La madera con la que ha sido construida la empalizada es bastante "
        "s�lida.\n");
    AddDetail(({"arbol","�rbol"}),"A lo lejos ves un gran �rbol que sobresale en el medio del "
        "poblado.\n");
    AddDetail(({"casas"}),"A lo largo de la calle hay varias casas peque�as a ambos lados.\n");
    AddDetail(({"puesto","puesto de frutas"}),"Es un puesto de frutas. Actualmente est� vac�o.\n");
    AddDetail(({"camino","sendero"}),"Es el sendero que te ha tra�do hasta aqu�, est� bordeado "
        "de flores y hiervajos.\n");
    AddReadMsg(({"cartel","cartelito"}),"Lees el cartel:\n Bienvenido al poblado "
      	 "de Flenton.\n");
    AddExit("norte",FLENHAB+"empalizada/empalizada_30");
    AddExit("sur",FLENHAB+"empalizada/empalizada_00");
    AddExit("oeste",FLENHAB+"calles/jefe_00");
    AddExit("este",LINKKHA);
    portal=clone_object("/obj/monolito");
    portal->SetRaza("kender");
    portal->move(TO);
}

init()
{
    ::init();
    call_out("fgritos",1);
}
