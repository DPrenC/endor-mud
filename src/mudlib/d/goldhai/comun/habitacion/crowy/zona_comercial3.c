/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 21-10-97                |
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
 SetIntShort("la zona comercial");
 SetIntLong(
"Un puesto de frutas te impide proseguir más hacie el Este, aunque quizás, lo\n\
que más te haya parado sean los canticos que escuchas provenientes del\n\
interior del centro religioso de la parte Sur. Se trata de un lugar de reunión\n\
de los guerreros antes de partir y allí cada uno se encomienda a su Dios\n\
particular. Luego, siempre puedes ir al Norte y comprarte algo de vestimenta.\n");
 SetIndoors(0); // 1: A cubierto  0: A descubierto
 SetIntNoise("Oyes unos canticos que vienen del Sur.\n");
 SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddDetail(({"puesto","puesto frutas","puesto de frutas"}),
"Un llamativo puesto de venta donde puedes comprar unas deliciosas frutas.\n");
 AddDetail(({"centro religioso","templo","iglesia"}),
"Es un viejo templo donde las gentes de cualquier religión se reunen.\n");
 AddDetail(({"comercio","comercios"}),
"Hay muchos y de todo tipo.\n");
 AddDetail("canticos","¿Estás intentando mirar unos canticos?\n");
 AddExit("este",CROWY("fruteria"));
 AddExit("oeste",CROWY("zona_comercial2"));
 AddExit("sur",CROWY("iglesia"));
 AddExit("norte",CROWY("tienda_ropa"));
AddDoor("norte", "la puerta de la sastrería",
    "Es la puerta de la antigua sastrería.\n",
    ({"puerta", "puerta de la tienda", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));

 AddItem(PNJ("crowy/crowiano"),REFRESH_DESTRUCT,random(2));
 AddItem(PNJ("crowy/guardia_humano"),REFRESH_DESTRUCT);

 SetLocate("Crowy");
}
