/*=============================================================*
 |            << GOLDHAI.Puerto [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 29-10-98               |
 |               Ultima Modificacion... 14-05-10               |
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
    SetIntLong("Estás en la zona norte del puerto de Goldhai.\n Aquí todo está más "
    "calmado y no hay tanta gente alborotada yendo de un lado a otro.\n  Este sería "
    "un buen sitio para descansar si no fuera por el tremendo olor a pescado que "
    "se respira en el ambiente.\n Hacia el  nordeste se puede llegar a un enorme "
    "faro que guía a los barcos perdidos durante la noche, a la vez que impiden que "
    "éstos choquen contra la costa.\n En el sur se encuentra la lonja del puerto, un "
    "buen sitio para comprar pescado.\n Puedes ir a otra parte del puerto en direccion "
    "Oeste.\n");
    SetIndoors(0); 
    SetIntNoise("Puedes oír todo el ruido que genera un puerto.\n");
    SetIntSmell("Huele a pescado.\n");

    AddDetail(({"mar","oceano","agua"}),
    "El agua está bastante sucia y no es el mejor sitio para bañarse.\n");
     AddDetail(({"pescaderia","lonja"}),
    "Es un extraño edificio de madera donde los pescadores venden la pesca diaria.\n");
    AddDetail(({"puerto"}),
    "Es el principal puerto de la isla y soporta una gran afluencia de barcos.\n");
    AddDetail(({"barco","barcos"}),
    "Los hay de infinidad de tipos, pesqueros, cargueros, de pasajeros. Algunos de "
    "ellos están preparándose para amarrar en el puerto, mientras que otros ya lo han "
    "hecho o se disponen a salir.\n");

    AddExit("nordeste",BOSCURO("frente_faro2"));
    AddExit("oeste",PUERTO("puerto6"));
    AddExit("sur",PUERTO("puerto4"));
    AddDoor("sur", "la puerta de la lonja",
    "Es una puerta para entrar a la lonja del puerto.\n",
    ({"puerta de la lonja", "puerta del sur", "puerta"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));


    SetLocate("puerto de Goldhai");
}
