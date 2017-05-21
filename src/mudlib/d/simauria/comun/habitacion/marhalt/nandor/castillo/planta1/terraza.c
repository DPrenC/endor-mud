/****************************************************************************
Fichero: bodega3.c
Autor: Ratwor
Fecha: 24/04/2008
Descripción: una pequeña terraza.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <magia.h>
inherit SIM_ROOM;
public string f_mosaico();
create(){
    ::create();
    SetIndoors(0);
    SetIntShort("una pequeña terraza");
    SetIntLong("Estás en el exterior del castillo, sobre una plataforma oculta de "
    "miradas indiscretas por los grandes contrafuertes del castillo y por un espeso "
    "entramado de parras de uva blanca, lo cual no impide que el lugar sea ventilado "
    "y agradable.\n Puesto que a este lado del castillo tan solo dan campos de cultivo, "
    "el río Kandal allí bajo el precipicio de la colina y más allá, las montañas "
    "de Betwa, la intimidad es absoluta. El suelo está decorado con un colorido mosaico.\n");
    SetIntNoise("Se escuchan los trinos de los gorriones y los graznidos de los grajos.\n");
    SetIntSmell("Huele a hierva fresca y flores.\n");
    AddDetail(({"rio", "río", "kandal", "Kandal", "rrío kandal", "rio kandal"}),
    "Es el río que atraviesa la región de Marhalt de este a oeste, en este "
    "tramo transcurre entre las montañas del norte de Betwa y la parte sur de la "
    "colina donde se asienta el castillo.\n");
    AddDetail("suelo",
    "Ves un precioso mosaico realizado de los más brillantes azulejos.\n");
    AddDetail("mosaico",SF(f_mosaico));

    Set(P_TPORT,TPORT_NO);
    ForbidAllMagic("La magia que se puede hacer aquí es algo más gratificante que lo "
    "que pretentes hacer.\n");
    AddExit("norte", "./sala_ero");
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

public string f_mosaico(){
    TP->SetExplored();
    return "Es un mosaico multicolor realizado en brillantes y pulidos azulejos. Representa a "
    "tres Sirenas jugando entre las olas. Una de ellas, la que ocupa la parte principal "
    "de la escena, se recuesta perezosamente sobre las aguas mientras sus pechos se "
    "yerguen firmes hacia el firmamento y su piel broncínea brilla de gotas de sal.\n"
    " En segundo plano se puede apreciar como las dos Sirenas restantes retozan "
    "juguetonamente entre la espuma de las olas.\n";
}
