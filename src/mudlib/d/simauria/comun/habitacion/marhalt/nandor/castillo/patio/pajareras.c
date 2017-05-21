/****************************************************************************
Fichero: pajareras.c
Autor: Ratwor
Fecha: 29/12/2007
Descripción: Las pajareras del castillo
****************************************************************************/

#include "./path.h"
#include <properties.h>
inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("las pajareras");
    SetIntLong("Te hallas en un cobertizo de paredes de adobe cerrado por una valla de "
    "alambre. El suelo está cubierto de paja mezclada con escrementos y diminutos "
    "huesecillos. Cerca del techo hay colocadas unas varas largas. En este cobertizo se "
    "guardan las aves de presa con las que el señor del castillo practica la cetrería.\n");
    AddDetail("valla", "Una delgada valla de alambre que cierra la parte oeste de las "
    "pajareras proporcionando luz al interior.\n");
    AddDetail("varas", "Largas varas de madera donde se posan las aves.\n");
    AddDetail(({"huesecillos", "huesos", "paja", "excrementos"}), "Una sucia capa de "
    "paja vieja, excrementos y frágiles huesos de pequeños animales cazados por los inquilinos del cobertizo.\n");
    SetIntSmell("Un desagradable olor a suciedad mezclado con el inconfundible de "
    "las aves invade tus fosas nasales.\n");
    SetIntBright(30);
    AddExit("oeste", "./patio19");
    AddDoor("oeste", "una puerta de madera",
    "Es la puerta para salir al patio de armas, también sirve por si alguna vez "
    "existiera el riesgo de que se escapase algún ave de su jaula.\n",
    ({"puerta", "puerta de madera", "puerta del patio", "puerta del oeste"}));
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("halcon"), REFRESH_DESTRUCT, d4());
    AddItem(PNJCASTILLO("azor"), REFRESH_DESTRUCT, d4());
}
