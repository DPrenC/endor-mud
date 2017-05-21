/*****************************************************************************************
 ARCHIVO:       robledal36.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("el norte de la isla");
    SetIntLong("Estás en un denso bosque de recios árboles centinela resguardados tras "
        "agujas color verde grisaceo, robles y acebos tan viejos como el propio bosque. "
        "Multitud de líquenes tapizan los gruesos troncos que puedes ver a tu alrededor "
        "como túnicas arbóreas.\n");
    AddDetail(({"árboles", "arboles", "recios árboles", "centinela"}), "Están inclinados "
        "hacia el suelo.\n");
    AddDetail("acebos", "Son arbustos sagrados para los druidas, y son utilizados en "
        "el solsticio de invierno para atraer suerte y prosperidad.\n");
    AddDetail("robles", "La corteza de sus troncos está repleta de nudos.\n");
    AddDetail(({"troncos", "túnicas", "tunicas"}), "Algunos están esparcidos al lado del "
        "sendero. La mayoría están podridos y huecos debido a la humedad y a la "
        "constante falta de luz.\n");
    AddDetail(({"líquenes", "liquenes"}), "Cubren y colorean toda la superficie de los "
        "troncos.\n");
    AddDetail("suelo", "Está cubieto de pequeñas hojas secas.\n");

    SetIntSmell("El ambiente está húmedo y huele a madera picada.\n");
    SetIntNoise("Escuchas el crujir de los árboles y gruñidos procedentes de algún lugar "
        "cercano.\n");

    AddExit("oeste", HAB_BOSQUE_ISLA("robledal35.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal32.c"));
}
