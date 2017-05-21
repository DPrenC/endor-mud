/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 23-11-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <door.h>
#include <nightday.h>
#include <scheduler.h>
#include <sounds.h>

inherit GROOM;

create()
{
 ::create();
 SetIntShort("una calle");
 SetIntLong(
"Un enorme arco que cruza la calle de un lado a otro te indica que estás en\n\
la entrada a la zona comercial de Crowy. Allí puedes encontrar alimentos, ropa\n\
libros o simplemente relajar tu espiritu en una iglesia. Por el contrario, si\n\
te dirijes hacia el Oeste volverás al centro de la ciudad.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes el murmullo de la gente.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail("arco",
"Es un arco de piedra bastante antiguo y que cruza la calle. En su parte\n\
frontal hay una gran inscripción tallada en la piedra en la que puedes leer\n\
'Zona Comercial de Crowy'.\n");
    AddExit("este",CROWY("zona_comercial1"));
    AddExit("oeste",CROWY("calle10"));
    AddExit("sur",CROWY("tienda_cuero"));
AddDoor("sur", "la puerta de la tienda",
    "Es la puerta de la tienda de cuero.\n",
    ({"puerta", "puerta de la tienda", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
 AddItem(PNJ("crowy/guardia_enano"),REFRESH_DESTRUCT);

 SetLocate("crowy");
}

void init()
{
 ::init();
}