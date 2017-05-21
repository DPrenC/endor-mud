/*---------------------------------------------------------------------------
  16-11-98 [cheto@simauria] embarcadero.c pa el quest del cocinero
  08-02-00 [woo, cheto] Modificao...
  03-03-03 [zomax] añado la linea licenciaobj=present("qlicencia",TP);
  		   que se la debió dejar alguien o borrar y por eso de que no
  		   asignaba licenciaobj a nada no destruía más abajo la licencia
  		   una vez pescado el atún. También cambio hermita por ermita
  		   en las descripción, no en el path.
----------------------------------------------------------------------------*/

#include "./path.h"
inherit SIM_ROOM;
hacer_pescar()
{
object ob1,ob2,ob3,canyaobj,licenciaobj;
if (ob3=present("atun",TP)) write ("Ya tienes un atun.\n");
else{
if (!canyaobj=present("canya de pescar",TP))
	write("No puedes pescar sin canya de pescar.\n");
	else {if (!ob2=(present("qcebo",TP)))
		write("No intentes pescar sin cebo.\n");
	else {if(!present("qlicencia",TP)) write("No tienes licencia para pescar.\n");
else {
			write("¡Pescas un bonito atún!\n");
			ob1=clone_object(GOBJETO("comida/atun"));
			ob1->move (TP);
			if (ob2) destruct(ob2);
                        write("Pierdes el equilibrio y se te caen la licencia y la caña al agua.\n");
			if (canyaobj) destruct(canyaobj);
			licenciaobj=present("qlicencia",TP);
			if (licenciaobj) destruct(licenciaobj);
		}}}}
return 1;
}

init(){
add_action("hacer_pescar","pescar");
::init();
}

create(){
    ::create();
   SetIntShort("un viejo embarcadero");
   SetIntLong(
        "Estás en un viejo embarcadero del puerto de Gorat, es un muelle abandonado donde "
        "puedes pescar si dispones de las herramientas adecuadas, ves el mar, un "
        "puerto y unos barcos abandonados.\n Al norte comienza una playa de rocas donde "
        "se asienta el famoso faro de Gorat.\n");
    SetIndoors(0);
    SetIntNoise("Puedes oír, hacia el sur, todo el ruido que genera un puerto.\n");
    SetIntSmell("Huele a pescado.\n");
    AddDetail(({"océano", "mar","oceano","agua"}),
    "Es como un gran lago pero con agua salada.\n");
    AddDetail(({"puerto","puerto","habitacion","lugar"}),
    "Es un puerto de pescadores.\n");
    AddDetail(({"barco","barcos"}),
    "Ves unos pequenyos barcos medio hundidos atracados en el muelle...\n");
    AddExit("sur", CNS("puerto"));
    AddExit("norte", "./playa1");
    SetLocate("puerto de Gorat");
    AddItem(GORPNJ("pescador"),REFRESH_DESTRUCT);
}
