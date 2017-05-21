/****************************************************************************
Fichero: silo2.c
Autor: Ratwor
Fecha: 01/01/2008
Descripción: Un silo de cereales o similares.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntBright(23);
    SetIntShort("un silo");
    SetIntLong("Te encuentras en uno de los almacenes de grano del castillo. Es una "
    "habitación pequeña y cuadrada, sin ningún tipo de mobiliario. En el centro de la "
    "estancia hay un pozo de unos tres metros de diametro en el que se almacena el  "
    "grano que los campesinos de Nandor están obligados a dar a su señor, y que  mas "
    "tarde se vende o se intercambia por otras mercancías.\n");
    AddDetail("pozo", "Un profundo pozo a medio llenar de grano.\n");
    AddDetail(({"pared", "paredes"}), "La piedra de las paredes está cuidadosamente "
    "pulida, ofreciendo un aspecto menos tosco que la cara exterior del muro de la torre.\n");
    AddDetail(({"suelo", "emlosado", "losas"}), "El suelo de la torre está hecho de "
    "losas cuadradas bien pulidas y perfectamente encajadas, denotando la importancia "
    "del edificio en el que habita la nobleza.\n");
    AddExit("sur", "./pasillo4");
    AddDoor("sur", "una puerta de madera",
    "Es una puerta vieja de madera para salir del silo.\n",
    ({"puerta", "puerta de madera", "puerta del silo", "puerta vieja", "puerta del sur"}));
    SetLocate("el castillo de Nandor");
}

