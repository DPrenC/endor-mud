/*=============================================================*
 |            << Simaruia:fortaleza [m] Maler >>               |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 23-03-99                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit PUB;

create()
{
    ::create();
    SetIntShort("el mes�n de la banda");
    SetIntLong(
        "Te encuentras en el mes�n de la banda, un lugar bastante sucio, pero en el que "
        "se sirve muy buena comida.\n  Las paredes son totalmente lisas.\n  Haciendo "
        "memoria crees recordar una historia de un viejo soldado de Nandor, que dec�a "
        "que nunca en su vida hab�a comido nada parecido al estofado que preparan en "
        "este mes�n.\n");
    SetIntBright(30);
    SetIntNoise("Apenas oyes nada, la gente degusta sus platos sin hacer ruido.\n");
    SetIntSmell("Huele a carne recien guisada.\n");
    AddDetail(({"meson","restaurante","garito","habitacion"}),
        "Se trata de un sitio muy sucio, pero tranquilo. Las paredes est�n pintadas de"
        " un color verdoso y sin decoraciones de ning�n tipo.\n  Hay un par de decenas"
        " de mesas cuadradas con 4 sillas a su alrededor que ocupan toda la estancia,"
        " la cual est� ligeramente alumbrada por unas velas situadas en el centro de"
        " las mesas.\n");
    AddDetail(({"paredes","pared"}),
        "Destacan por su inquietante color verde.\n");

    AddFood("estofado con patatas","un plato de",8,14,0);
    AddFood("estofado de conejo","un plato de",7,13,0);
    AddFood("ternera estofada","un plato de",8,12,0);
    AddFood("Pur� de verduras","un cuenco de",9,13,0);
    AddFood("Carne a la parrilla","un plato de",9,14,0);
    AddFood("huevo","un",1,4,0);
    SetKeeper(PNJFF("mesonera_cored"));
    AddExit("este",ROOMFF("patio15"));
    AddDoor("este", "la puerta del mes�n",
    "Es la puerta para entrar al mes�n.\n",
    ({"puerta", "puerta del oeste", "puerta del meson", "puerta del mes�n"}));
    SetLocate("Cored");
}
