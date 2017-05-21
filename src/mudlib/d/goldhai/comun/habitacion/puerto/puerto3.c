/*=============================================================*
 |            << GOLDHAI.Puerto [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 06-01-98               |
 |               Ultima Modificacion... 14-04-10               |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <door.h>
#include <sounds.h>
#include <scheduler.h>

inherit GROOM;

create()
{
    ::create();
    SetIntShort("el puerto oeste de Goldhai");
    SetIntLong("El puerto parece inmenso desde aqu�, con todos esos barcos yendo y "
    "viniendo y desapareciendo en el horizonte para dirigirse a alg�n rec�ndito lugar.\n"
    "Hacia el este se entra en la lonja del puerto, donde se puede comprar todo tipo "
    "de pescados.\n El puerto contin�a en direcci�n Norte y Sur.\n");
    SetIndoors(0);
    SetIntNoise("Puedes o�r todo el ruido que genera un puerto.\n");
    SetIntSmell("Huele a pescado.\n");

    AddDetail(({"mar","oceano","agua", "oc�ano"}),
    "El agua est� bastante sucia y no es el mejor sitio para ba�arse.\n");
    AddDetail(({"pescaderia","lonja", "pescader�a"}),
    "Es un extra�o edificio de madera donde los pescadores venden la pesca diaria.\n");
    AddDetail(({"puerto"}),
    "Es el principal puerto de la isla y soporta una gran afluencia de barcos.\n");
    AddDetail(({"barco","barcos"}),
    "Los hay de infinidad de tipos, pesqueros, cargueros, de pasajeros. Algunos de"
    " ellos est�n prepar�ndose para amarrar en el puerto mientras que otros ya lo han"
    " hecho o se disponen a salir.\n");

    AddExit("norte",PUERTO("puerto6"));
    AddExit("este",PUERTO("puerto4"));
    AddExit("sur",PUERTO("puerto2"));
    AddDoor("este", "la puerta de la lonja",
    "Es la puerta principal de la lonja del puerto.\n",
    ({"puerta de la lonja", "puerta del este", "puerta principal", "puerta"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));


    SetLocate("puerto de Goldhai");
}
