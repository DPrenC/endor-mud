/*=============================================================*
 |         << GOLDHAI.Acantilado [w] Woo@simauria >>           |
 *=============================================================*
 |            Creacion.................. 20-03-00              |
 |            Ultima Modificacion....... 20-03-00              |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <magia.h>
#include <sounds.h>


inherit GROOM;

create()
{
::create();
SetIndoors(0);
SetIntShort("una pequeña playa");
SetIntLong(
"Te encuentras a los pies de un impresionate acantilado. El oleaje ha "
"formado una pequeña playa de arena fina entre las rocas donde yacen "
"innumerables conchas. Varado en la orilla se halla un enorme barco que "
"parece haber naufragado... Un arriesgado camino escarpado sube por el "
"acantilado hasta lo más alto. Es peligroso pero parece ser la única forma "
"de salir de aquí.\n");

 AddDetail(({"acantilado","precipicio"}),
"Es un enorme acantilado que baja de forma casi perpendicular hasta la playa.\n");

 AddDetail(({"mar","oceano","agua"}),
"Desde este punto de la isla el mar adquiere una belleza especial. Ves como\n\
llegan las olas violentamente y rompen furiosas contra el acantilado.\n");

 AddDetail(({"playa","arena"}), "Es una pequeña playa de arena fina.\n");
 
 AddDetail(({"concha","conchas"}), "Las conchas cubren gran parte de la arena.\n");

 AddDetail(({"barco","barco pirata"}),
"Se trata de un enorme barco abandonado.\n");

 SetExplorable(1);
 SetTPort(TPORT_NO);
 ForbidAllMagic();
 AddExit("arriba",ACANTILADO("acantilado2"));
 AddExit("oeste",ACANTILADO("barco"));

 SetSoundEnvironment(SND_AMBIENTES("olas"));
 SetLocate("acantilado del suroeste de Goldhai");
}

int subir(string str)
{
 if (!TP->QueryIsPlayer()) return 0;
 if (TP->QueryWeightContent()>25000)
  return write("Llevas demasiado peso para subir, deberias dejar algo.\n"),1;
 return 0;
}

init() {
 ::init();
 add_action("subir","ar");
 add_action("subir","arriba");
}
