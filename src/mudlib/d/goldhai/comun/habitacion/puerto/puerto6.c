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
    SetIntLong("Te encuentras en la parte norte del puerto, un lugar más tranquilo en "
    "relación con el resto del puerto, el cual está limitado por grandes rocas "
    "que lo separan del mar, y en las cuales el agua golpea con fuerza.\n Hacia el "
    "este y hacia el sur se puede llegar a otras partes del puerto.\n");
    SetIndoors(0); 
    SetIntNoise("Puedes oír todo el ruido que genera un puerto.\n");
    SetIntSmell("Huele a pescado.\n");

    AddDetail(({"mar","océano","oceano","agua"}),
    "El agua está bastante sucia y no es el mejor sitio para bañarse.\n");
    AddDetail(({"puerto"}),
    "Es el principal puerto de la isla y soporta una gran afluencia de barcos.\n");
    AddDetail(({"barco","barcos"}),
    "Los hay de infinidad de tipos, pesqueros, cargueros, de pasajeros. Algunos de "
    "ellos están preparándose para amarrar en el puerto mientras que otros ya lo han"
   " hecho o se disponen a salir.\n");

    AddExit("este",PUERTO("puerto5"));
    AddExit("sur",PUERTO("puerto3"));

    SetLocate("puerto de Goldhai");
}
