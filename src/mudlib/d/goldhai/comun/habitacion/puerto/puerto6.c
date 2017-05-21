/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 06-01-98                |
 |               Ultima Modificacion.. 20-02-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GROOM;

create()
{
    ::create();
    SetIntShort("el puerto oeste de Goldhai");
    SetIntLong("Te encuentras en la parte norte del puerto, un lugar m�s tranquilo en "
    "relaci�n con el resto del puerto, el cual est� limitado por grandes rocas "
    "que lo separan del mar, y en las cuales el agua golpea con fuerza.\n Hacia el "
    "este y hacia el sur se puede llegar a otras partes del puerto.\n");
    SetIndoors(0); 
    SetIntNoise("Puedes o�r todo el ruido que genera un puerto.\n");
    SetIntSmell("Huele a pescado.\n");

    AddDetail(({"mar","oc�ano","oceano","agua"}),
    "El agua est� bastante sucia y no es el mejor sitio para ba�arse.\n");
    AddDetail(({"puerto"}),
    "Es el principal puerto de la isla y soporta una gran afluencia de barcos.\n");
    AddDetail(({"barco","barcos"}),
    "Los hay de infinidad de tipos, pesqueros, cargueros, de pasajeros. Algunos de "
    "ellos est�n prepar�ndose para amarrar en el puerto mientras que otros ya lo han"
   " hecho o se disponen a salir.\n");

    AddExit("este",PUERTO("puerto5"));
    AddExit("sur",PUERTO("puerto3"));

    SetLocate("puerto de Goldhai");
}
