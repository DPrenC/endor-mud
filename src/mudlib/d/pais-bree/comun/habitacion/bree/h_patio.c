/*
Fichero: h_patio.c
Autor: Aul�
Fecha: 02/12/2014
Descripci�n: patio de la herrer�a.
*/
#include "./path.h"
inherit BREE_ROOM;

create()
{
    ::create();
    	SetIntShort("el patio de la herrer�a");
    	SetIntLong(
"Tras el edificio de la herrer�a hay un patio cerrado por el oeste y el norte por un "
"muro de piedra bien constru�do, mientras que al sur se alza un establo. El suelo est� "
"toscamente empedrado y puede verse una plataforma peque�a junto a la pared y unas "
"barras de hierro verticales para sujetar al animal al que se quiere herrar.\n");
AddDetail("muro",
"Es un muro de m�s de un metro y medio de altura, formado por cantos rodados y argamasa "
"y con la parte superior redondeada. Impide que cualquier animal escape del patio.\n");
AddDetail("plataforma",
"Es una peque�a plataforma met�lica con un hueco de la forma del casco de un caballo que "
"permite herrar a los animales con mayor comodidad.\n");
AddDetail("barras",
"Son gruesas barras de hierro verticales encajadas por los extremos curvos en el muro "
"del establo, junto a la plataforma de herrar. Sirve para sujetar a los animales "
"impidiendo que se muevan.\n");
AddDetail(({"herrer�a", "herreria"}),
"Al este se alza la herrer�a, un edificio bajo y macizo cubierto de un tejado poco "
"inclinado.\n");
AddDetail("establo",
"Al sur se levanta un peque�o establo perteneciente a la herrer�a.\n");

    	AddExit("este", HABITACION+"bree/comercios/herreria");
    	AddExit("sur", "./h_establo");
    	    AddDoor("este", "un port�n de madera",
    "Es un gran port�n de madera por la que podr�a entrar un carro y por la que es f�cil "
    "introducir a las monturas para herrarlas.\n",
    ({"porton", "este", "puerta del este", "puerta", "e"}));
        AddDoor("sur", "la puerta del establo",
"Es una s�lida puerta de tablones que cierra el establo.\n",
    ({"establo", "sur", "puerta del sur", "puerta", "s"}));


    	}