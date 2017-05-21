/****************************************************************************
Fichero: terraza.c
Autor: Ratwor
Fecha: 24/04/2008
Descripción: una pequeña terraza.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <magia.h>
inherit ROOM;
create(){
    ::create();
    SetIndoors(0);
    SetIntShort("una pequeña terraza");
    SetIntLong("Estás en una agradable terraza en los aposentos de Ratwor, un colorido "
    "mosaico de pequeñas piedrecitas adornan todo el suelo.\n Las vistas desde aquí "
    "son envidiables, pues se puede ver buena parte del océano hacia el este, mientras "
    "que al sur se contempla el maravilloso templo de los dioses de Limbo.\n");
    SetIntNoise("Se escuchan los trinos de los gorriones y los graznidos de los grajos.\n");
    SetIntSmell("Huele a hierva fresca, mar y flores.\n");
    AddDetail("suelo",
    "Ves un precioso mosaico realizado de los más brillantes azulejos.\n");
    AddDetail("mosaico",
    "Es un mosaico multicolor realizado en brillantes y pulidos azulejos. Representa a "
    "tres Sirenas jugando entre las olas. Una de ellas, la que ocupa la parte principal "
    "de la escena, se recuesta perezosamente sobre las aguas mientras sus pechos se "
    "yerguen firmes hacia el firmamento y su piel broncínea brilla de gotas de sal.\n"
    " En segundo plano se puede apreciar como las dos Sirenas restantes retozan "
    "juguetonamente entre la espuma de las olas.\n");

    Set(P_TPORT,TPORT_NO);
    ForbidAllMagic("La magia que se puede hacer aquí es algo más gratificante que lo "
    "que pretentes hacer.\n");
    AddExit("norte", "./workroom");
    AddDoor("norte", "una vidriera",
    "Son dos grandes batientes rellenados de vidrio emplomado. Los vidrios en diferentes "
    "tonalidades de gris, amarillo y rojo, representan desde la parte superior izquierda "
    "hasta la parte inferior derecha, todas las posiciones posibles en las que dos "
    "personas del sexo que sean pueden copular: dos personas una encima de otra pero "
    "invertidas, Una mujer entre dos hombres, dos hombres...\n Son infinidad de posturas, "
    "representadas con gran detalle para tratarse de vidrio transparente de colores.\n",
    ({"vidriera", "puerta del sur", "vidriera emplomada"}),
    ([P_DOOR_TRANSPARENCY:1, P_MATERIAL: M_CRISTAL,
        P_DOOR_KNOCK_SOUND: SND_SUCESOS("llamar_puerta_cristal")]));
}

