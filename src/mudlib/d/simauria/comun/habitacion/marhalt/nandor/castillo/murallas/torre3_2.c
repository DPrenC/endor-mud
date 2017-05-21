/****************************************************************************
Fichero: torre3_2.c
Autor: Ratwor
Fecha: 30/12/2007
Descripci�n: La peque�a torre sudeste del castillo.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("una peque�a torre");
    SetIntLong("Te encuentras en una estancia peque�a y cuadrada, vac�a a escepci�n de "
    "un largo tabl�n apoyado contra la pared a modo de banco. Una escalera de caracol "
    "conecta esta habitaci�n con los pisos superior e inferior, jalonada por soportes de "
    "antorchas algo desvencijados, y una hilera de estrechas aspilleras. Al noroeste un bajo arco de piedra conduce a la muralla.\n");
    AddDetail("tabl�n", "Un macizo tabl�n de madera colocado contra una pared a modo de "
    "banco.\n");
    AddDetail("escalera", "Una ruinosa escalera de caracol que une las distintas partes "
    "de la torre. Constru�da en piedra de mala calidad, sus escalones est�n hundidos en "
    "algunos puntos y medio derrumbados en otros, con algunas de las piedras que la "
    "constituyen medio sueltas.\n");
    AddDetail("soportes", "Viejos soportes de hierro oxidados y en ocasiones medio "
    "desprendidos del muro que los sustenta.\n");
    AddDetail("aspilleras", "Aberturas en forma rectangular, mas anchas en la parte "
    "interior que en la exterior para que resulte dificil colar cualquier proyectil en "
    "el edificio, situadas a buena altura sobre el suelo. Atisbando por ellas se pueden "
    "ver los prados situados al pie del acantilado a cuyo borde se alza la torre, y "
    "mas al sur el r�o Kandal que los delimita. Por las del muro oriental se atisba la "
    "pendiente de la colina y nandor, por las del norte la muralla oriental y el "
    "torre�n de C�nor y por las del occidental el sur de la muralla y la torre del "
    "homenaje.\n");
    SetIntBright(25);
    SetLocate("el castillo de Nandor");
    AddExit("noroeste", "./muralla20");
    AddExit("arriba", "./torre3_3");
    AddExit("abajo", "./torre3_1");
    AddItem(PNJCASTILLO("hombre_armas"), REFRESH_DESTRUCT);
}

