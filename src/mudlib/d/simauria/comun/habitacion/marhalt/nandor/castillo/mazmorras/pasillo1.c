/****************************************************************************
Fichero: pasillo1.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: En las mazmorras del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("mazmorras/mazmorras_base");

create(){
    ::create();
    SetIntLong("Te hallas en una estancia excavada en los mismos cimientos de la torre "
    "de la Dama. Ninguna abertura proporciona aire fresco ni luz, y por lo dem�s el "
    "lugar est� completamente vac�o. Las paredes de piedra a medias excavadas en la "
    "roca, a medias hechas de bloques mal colocados sostienen alg�n soporte para "
    "antorchas y est�n cuajadas de huecos y sobresalientes. Una angosta escalera de "
    "caracol asciende a la planta superior, y hacia el noroeste se extiende un "
    "oscuro pasillo.\n");
    AddDetail("escalera", "Una ruinosa escalera de caracol que une las distintas partes "
    "de la torre. Constru�da en piedra de mala calidad, sus escalones est�n hundidos en "
    "algunos puntos y medio derrumbados en otros, con algunas de las piedras que la "
    "constituyen medio sueltas.\n");

    AddExit("arriba", CASTILLO("murallas/torre3_1"));
    AddExit("noroeste", "./pasillo2");
}

