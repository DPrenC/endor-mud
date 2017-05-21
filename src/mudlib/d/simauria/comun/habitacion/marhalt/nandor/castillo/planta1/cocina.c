/****************************************************************************
Fichero: cocina.c
Autor: Ratwor
Fecha: 01/01/2008
Descripción: La cocina del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("el castillo de Nandor");
    SetIntShort("las cocinas");
    SetIntLong(
    "Estas en la cocina del castillo. Como puedes ver, es una gran habitacion llena "
    "de pucheros que reposan sobre ardientes fogones. "
    "Por la puerta del oeste se accede a una estancia oscura, y por la del este "
    "a la zona de servidumbre.\n");
    AddDetail(({"ollas", "cacerolas", "pucheros"}),
    "Son unas enormes cacerolas de acero usadas para preparar los banquetes "
    "oficiales y otras comidas.\n");
    AddDetail(({"fuegos", "fogones"}),
    "Hay multitud de fogones, algunos encendidos y otros apagados.\n");
    SetIntBright(30);

    AddExit("oeste","./zona_servidumbre3" );
    AddExit("este","./zona_servidumbre2" );
    SetIntNoise("Oyes un ruído de ollas haciendo chup-chup.\n" );
    SetIntSmell("Huele a algo sabroso guisándose.\n" );
    AddItem(PNJ("marhalt/cocinero"),REFRESH_DESTRUCT);

}
