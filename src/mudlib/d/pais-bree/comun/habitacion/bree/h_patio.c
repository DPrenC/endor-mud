/*
Fichero: h_patio.c
Autor: Aulë
Fecha: 02/12/2014
Descripción: patio de la herrería.
*/
#include "./path.h"
inherit BREE_ROOM;

create()
{
    ::create();
    	SetIntShort("el patio de la herrería");
    	SetIntLong(
"Tras el edificio de la herrería hay un patio cerrado por el oeste y el norte por un "
"muro de piedra bien construído, mientras que al sur se alza un establo. El suelo está "
"toscamente empedrado y puede verse una plataforma pequeña junto a la pared y unas "
"barras de hierro verticales para sujetar al animal al que se quiere herrar.\n");
AddDetail("muro",
"Es un muro de más de un metro y medio de altura, formado por cantos rodados y argamasa "
"y con la parte superior redondeada. Impide que cualquier animal escape del patio.\n");
AddDetail("plataforma",
"Es una pequeña plataforma metálica con un hueco de la forma del casco de un caballo que "
"permite herrar a los animales con mayor comodidad.\n");
AddDetail("barras",
"Son gruesas barras de hierro verticales encajadas por los extremos curvos en el muro "
"del establo, junto a la plataforma de herrar. Sirve para sujetar a los animales "
"impidiendo que se muevan.\n");
AddDetail(({"herrería", "herreria"}),
"Al este se alza la herrería, un edificio bajo y macizo cubierto de un tejado poco "
"inclinado.\n");
AddDetail("establo",
"Al sur se levanta un pequeño establo perteneciente a la herrería.\n");

    	AddExit("este", HABITACION+"bree/comercios/herreria");
    	AddExit("sur", "./h_establo");
    	    AddDoor("este", "un portón de madera",
    "Es un gran portón de madera por la que podría entrar un carro y por la que es fácil "
    "introducir a las monturas para herrarlas.\n",
    ({"porton", "este", "puerta del este", "puerta", "e"}));
        AddDoor("sur", "la puerta del establo",
"Es una sólida puerta de tablones que cierra el establo.\n",
    ({"establo", "sur", "puerta del sur", "puerta", "s"}));


    	}