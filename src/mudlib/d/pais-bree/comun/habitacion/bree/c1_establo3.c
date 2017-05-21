/*
Fichero: c1_establo3.c
Autor: aul�
Fecha: 12/10/2014
Descripci�n: establo de la granja
*/
#include "./path.h"
inherit BREE_ROOM;

create()
{
    ::create();
    	SetIntShort("el establo");
    	SetIntLong(
    	"Este largo establo recorre toda la parte norte de la casa y est� dividido en "
    	"distintas zonas para los diferentes animales.\n"
    	"Contra la pared del fondo hay unos peque�os cub�culos de madera llenos de paja "
    	"prensada y sobre ellos se alinean varias varas y tablas horizontales.\n"
    	"Un largo comedero con cereal est� apoyado junto a la puerta del sur que da "
    	"acceso al patio de la granja. Es en esta zona donde las aves del establo pasan el "
    	"tiempo picoteando y buscando insectos entre la paja pisoteada y cubierta de "
    	"escrementos. El techo de vigas y tablones de madera, "
    	"sucia y oscurecida por el tiempo, se apoya sobre gruesos muros de piedras "
    	"irregulares que tambi�n forman el piso del establo. Un estrecho canalillo de "
    	"piedra y argamasa canaliza los orines de los animales hacia el exterior a "
    	"trav�s de una rejilla de la pared del sur.\n");
    	AddDetail(({"cubiculos", "cub�culos"}),
    	"Son peque�os cajones techados rellenos de paja para que las gallinas pongan "
    	"sus huevos.\n");
    	 SetIntNoise("Oyes  movimientos, mugidos, cacareos y dem�s sonidos propios de los animales.\n");-
 SetIntSmell("Huele a esti�rcol de distintos tipos, paja seca, orines y animales");
 SetIndoors(1);
AddExit("norte", "./c1_establo2");
AddExit("oeste", "./c1_patio");
    	AddDoor("oeste", "un port�n de madera",
    	"Es un ancho port�n de madera oscurecida por el tiempo, claveteada "
    	"con grandes clavos de bronce y con una viga inferior que sustenta el conjunto y "
    	"sobre la que hay que pasar para entrar. Tiene doble batiente para permitir el "
    	"paso del ganado o de un carro cargado.\n",
    	({"porton", "port�n", "o", "oeste", "port�n de madera", "porton de madera"}));
    }