/****************************************************************************
Fichero: herreria_01.c
Autor: Riberales
		[T] Tagoras
Creaci�n: 29/09/2005
Descripci�n: La entrada de la herrer�a..
[T] 11/03/2009: A�ado puertas.
****************************************************************************/

#include "./path.h"
#include <door.h>
#include <properties.h>
#include <materials.h>
#include <scheduler.h>

//inherit ROOM;
inherit SCHEDULER_ROOM;

string cmd_escuchar();
int cmd_coger();



public void create()
{
    ::create();

    SetIntShort("la gran herrer�a de Annufam");
    SetLocate("Annufam");
    SetIntLong("Te encuentras en la parte suroeste de la gran herrer�a de "
               "la ciudad. Al sur sales a la calle Ungrim. Hay diferentes "
               "zonas donde puedes realizar diversas acciones. Al norte, "
               "observas un mostrador, al igual que al nordeste. Al este, "
               "por el contrario, descansa lo que parece un yunque.\n");

    AddDetail("suelo",
            "Hay peque�os trozos de hierro y acero, debidos a la forja de "
            "la herrer�a. No estar�a mal que barriesen de vez en cuando.\n");

    AddDetail(({"pared","paredes"}),
              "Est�n llenas de armas y armaduras de todo tipo, ya reparadas "
              "o esperando a serlo.\n");


    AddDetail(({"armas de pared","armas de paredes","arma de pared",
                "arma de paredes"}),
              "Se trata de espadas y hachas de hierro en su gran mayor�a, "
              "aunque tambi�n observas alguna daga y lanza por reparar.\n");


    AddDetail(({"armaduras de paredes","armaduras de pared","armadura de pared"
               ,"armadura de paredes"}),
              "Corazas y cascos abollados, y alg�n escudo doblado son, "
              "junto a las armas, los adornos de la herrer�a.\n");

    SetIndoors(1);
    SetIntLight(75);
    SetIntNoise(SF(cmd_escuchar));
    SetIntSmell("La respiraci�n es casi insoportable por el gran calor que "
                "desprende el horno del este.\n");
	SetCloseTime(S_CLOSED_AT_NIGHT);
	SetAssociatedRooms(({HAB_HERRERIA_ANNUFAM("herreria_02"), HAB_HERRERIA_ANNUFAM("herreria_03"), HAB_HERRERIA_ANNUFAM("herreria_04")}));
	SetLastDest(HAB_UNGRIM_ANNUFAM("ungrim_08"));
	SetNotifyExits("sur");
    AddExit("sur",HAB_UNGRIM_ANNUFAM("ungrim_08"));
    AddExit("norte",HAB_HERRERIA_ANNUFAM("herreria_02"));
    AddExit("nordeste",HAB_HERRERIA_ANNUFAM("herreria_03"));
    AddExit("este",HAB_HERRERIA_ANNUFAM("herreria_04"));
    AddDoor("sur", "la puerta de la calle", "Se trata de una gran puerta de madera maciza.\n",
        ({"puerta", "puerta maciza", "puerta de madera"}), GENDER_FEMALE,
        ([P_MATERIAL : M_MADERA, P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));

    AddRoomCmd("coger","cmd_coger");
}

int cmd_coger(string str)
{
    if (member(({"arma de pared","armas de pared","armas de paredes",
                 "arma de paredes","armadura de pared","armaduras de pared",
                "armaduras de paredes","armadura de paredes"}),str) >= 0)
    {
        return notify_fail(W("No cojas eso, pertenece a la herrer�a, y te "
                             "puedes meter en problemas.\n"),
               NOTIFY_NOT_VALID);
    }
}



string cmd_escuchar()
{
    object herrero;
    if ((herrero = present("maestro_herrero",to_object(HAB_HERRERIA_ANNUFAM
        ("herreria_04")))) && living(herrero))
    {
        return "Escuchas el golpeteo de algo met�lico en direcci�n este.\n";
    }

	return "Extra�amente no escuchas nada.\n";
}
