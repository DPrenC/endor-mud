/****************************************************************************
Fichero: torre3_1.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: La pequeña torre sudeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("una pequeña torre");
    SetIntLong("La parte baja de la torre de la Dama forma una pequeña estancia "
    "cuadrada, vacía de cualquier objeto a escepción de los soportes para antorchas que "
    "bordean a trechos la angosta escalera de caracol que lleva al siguiente piso y "
    "desciende hacia otro nivel mas oscuro. En la pared sur hay varias aspilleras que "
    "permiten disparar o atisbar hacia el exterior. Al noroeste se abre un angosto "
    "pasadizo que conduce bajo la muralla hasta el patio de armas.\n");
    AddDetail("escalera", "Una ruinosa escalera de caracol que une las distintas partes "
    "de la torre. Construída en piedra de mala calidad, sus escalones están hundidos en "
    "algunos puntos y medio derrumbados en otros, con algunas de las piedras que la "
    "constituyen medio sueltas.\n");
    AddDetail("soportes", "Viejos soportes de hierro oxidados y en ocasiones medio "
    "desprendidos del muro que los sustenta.\n");
    AddDetail("aspilleras", "Aberturas en forma rectangular, mas anchas en la parte "
    "interior que en la exterior para que resulte dificil colar cualquier proyectil en "
    "el edificio, situadas a buena altura sobre el suelo. Atisbando por ellas se pueden "
    "ver los prados situados al pie del acantilado a cuyo borde se alza la torre, y "
    "mas al sur el río Kandal que los delimita.\n");
    AddDetail(({"rio", "río", "kandal", "Kandal"}),
    "Es el río que viene del este del dominio, atravesando la región de Sherek, "
    "el bosque de Marhalt y bordeando esta colina en su parte sur, para ir a desembocar "
    "en las aguas del oeste de Simauria.\n");

    SetIntBright(25);
    SetLocate("el castillo de Nandor");
    AddExit("noroeste", "./pasadizo3");
    AddExit("arriba", "./torre3_2");
    AddExit("abajo", CASTILLO("mazmorras/pasillo1"));
}

