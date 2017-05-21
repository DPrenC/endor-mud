/*
DESCRIPCION  : La Plaza de Krigor
FICHERO      : plaza.c
MODIFICACION : [Chaos] Creacion
*/

#include "./path.h"
#include <door.h>
#include <nightday.h>
#include <scheduler.h>
#include <sounds.h>

inherit SIM_ROOM;

create()
{
	::create();

	SetIntShort("la plaza de Krigor");
	SetIntLong("Estás en la plaza del pueblo de Krigor. En medio de la plaza hay un "
	"pequeño pozo y al lado una estatua.\n En la parte norte de la plaza hay un "
	"edificio que se diferencia de los demás porque es de piedra y un poco mas grande,"
	" es posible que sea el ayuntamiento.\n Al sur ves una casa que tiene un letrero "
	"encima de la puerta.\n Al este hay un edificio de madera mas grande y tiene un "
	"cartel colgando al lado de la puerta.\n De esta plaza salen diferentes callejuelas"
	" que se internan en el pueblo.  El sendero cruza desde el sudeste hacia el nordeste.\n");

	SetLocate("Krigor");
	SetIndoors(0);
	SetIntNoise("Oyes el murmullo de la gente en la plaza .\n");
	SetIntSmell("Huele un poko a vaca.\n");
    AddDetail("cartel", "El cartel de la posada.\n");
	AddReadMsg("cartel","Pone: 'Posada los tres puñales'\n");
	AddDetail("letrero","Es el letrero de la tienda de Kluer.\n");
	AddDetail("pozo","Es un pozo construido de piedra en forma redondeada, pero "
	"no tiene polea para coger agua.\n");
	AddDetail("estatua","Es la estatua de un guerrero humano legendario derrotando a "
	"un enorme demonio. En la base se puede leer una placa.\n");
	AddDetail("placa", "Una placa de cobre.\n");
	AddReadMsg("placa","En memoria del gran héroe local: 'Maegrin'\n");

	AddExit("nordeste",KRIGOR("sendero08"));
	AddExit("sur",KRIGOR("tienda"));
	AddExit("norte",KRIGOR("ayuntamiento"));
	AddExit("este",KRIGOR("posada/posada"));
	AddExit("suroeste",KRIGOR("calle04"));
	AddExit("sudeste",KRIGOR("sendero06"));
	AddExit("oeste",KRIGOR("calle05"));
    AddDoor("este", "la puerta de la posada",
    "Es una puerta mediana de madera que pertenece a la posada de Krigor.\n",
    ({"puerta", "puerta de la posada", "puerta del este", "puerta mediana"}));
    AddDoor("sur", "la puerta de la tienda",
    "La puerta para entrar a la tienda de Krigor.\n",
    ({"puerta", "puerta de la tienda", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddDoor("norte", "la puerta del ayuntamiento",
    "Una gran puerta de madera que pertenece al ayuntamiento.\n",
    ({"puerta", "puerta del ayuntamiento", "puerta del norte", "gran puerta",
        "puerta grande"}),
    ([P_DOOR_CLOSE_TIME : ({ND_PREFALL, ND_FALL, ND_PRENIGHT, ND_NIGHT, ND_PREDAWN, ND_DAWN, ND_SUNRISE})]));

}


