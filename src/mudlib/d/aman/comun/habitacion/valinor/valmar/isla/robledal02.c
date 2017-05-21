/*****************************************************************************************
 ARCHIVO:       robledal02.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Sendero a través del robledal.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("un sendero a través de los árboles");
    SetIntLong("Te encuentras en un sendero que cruza un denso bosque de recios árboles "
        "centinela resguardados tras robles y acebos tan viejos como el propio bosque. "
        "Multitud de líquenes tapizan los gruesos troncos que puedes ver a tu alrededor "
        "como túnicas arbóreas.\n");
    AddDetail(({"árboles", "arboles", "recios árboles", "centinela"}), "Están inclinados "
        "hacia el suelo.\n");
    AddDetail("acebos", "Se trata de unos arbustos de color verde oscuro, están "
        "adornados con pequeñas bolitas de color rojo.\n");
    AddDetail("robles", "La corteza de sus troncos está repleta de nudos.\n");
    AddDetail(({"troncos", "túnicas", "tunicas"}), "Algunos están esparcidos al lado del "
        "sendero. La mayoría están podridos y huecos debido a la humedad y a la "
        "constante falta de luz.\n");
    AddDetail(({"líquenes", "liquenes"}), "Cubren y colorean toda la superficie de los "
        "troncos.\n");
    AddDetail("suelo", "Pequeñas hojas secas disimulan lo que parece ser un sendero.\n");

    SetIntSmell("El ambiente está húmedo y huele a madera picada.\n");
    SetIntNoise("Escuchas el crujir de los árboles y gruñidos procedentes de algún lugar "
        "cercano.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal06.c"));
    AddExit("oeste", HAB_BOSQUE_ISLA("robledal01.c"));
}
