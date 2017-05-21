/*

    Nombre      : posadaEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Posada del poblado de Enalel

*/

#include "./path.h"
inherit PUB;

create() {
    ::create();

    SetIntBright(40);
    SetLocate("Poblado de Enalel");
    SetIntShort("la posada la manzana feliz");
    SetIntLong("Estás en la posada de la manzana feliz. Esta es la posada "
    "donde los pobladores de Enalel se reunen a descansar y charlar. Las mesas "
    "y taburetes ocupan gran parte de la sala y en un extremo está la barra "
    "donde puedes pedir alguna de las especialidades de la zona. Una pequeña "
    "escalera sube al piso superior, donde se encuentran las habitaciones.\n");
    SetIntNoise("La gente charla, bebe y come animadamente, por lo que no "
    "puedes apreciar otros sonidos.\n");
    SetIntSmell("La buena comida y la agradable bebida llenan la sala de ricos aromas.\n");
    AddDetail(({"mesas","mesas","taburete","taburetes","silla","sillas"}),"Todos "
    "los muebles son de madera de manzano. Parecen cómodos y fuertes y siempre hay "
    "un sitio libre para todos.\n");
    AddDetail(({"mostrador", "barra","tronco","tronco de manzano"}),"La barra de la posada "
    "es un enorme tronco de manzano que ha sido cortado para hacer las veces de "
    "barra de bar.\n");
    AddExit("este",ENALHAB"poblado/calles/calle06");
    AddExit("arriba",ENALHAB"poblado/posada/pasillo_habitaciones");
    AddItem(ENALPNJ"ancianos/rombrat",REFRESH_DESTRUCT);
    AddItem(ENALPNJ"ancianos/pelgas",REFRESH_DESTRUCT);
    SetKeeper(ENALPNJ"tenderos/tabernera_enalel");
    AddDoor("este", "la puerta principal",
    "Esta es la puerta principal de la posada que da salida a la calle del comercio.\n",
    ({"puerta", "puerta principal", "puerta del este"}));
    AddDrink("cerveza","una",2,5,6,0,"Te tomas una refrescante cerveza.");
    AddDrink("sidra","un vaso de",4,7,4,0,"Saboreas con deleite el vaso de sidra.");
    AddDrink("zumo de manzana","un vaso de",3,0,7,0,"Al beber del vaso de zumo, un sabroso sabor inunda tu boca.");
    AddDrink("licor de manzana","un vaso de",5,15,15,0,"Sientes como el delicioso licor de manzana quema un poco tu garganta.");
    AddDrink("vino","un vaso de",4,10,10,0,"Te tomas un vaso de buen vino élfico.");
    AddFood("conejo","una porción de",8,10,0,"Saboreas un delicioso guiso de conejo a la manzana.");
    AddFood("tarta de manzana","una porción de",12,6,0,"Se nota que la especialidad de la casa es esta tarta de manzana. Nuevos y deliciosos sabores inundan tus sentidos.");
    AddFood("cerdo","un trozo de",12,11,0,"Saboreas un delicioso trozo de cerdo a la sidra.");
}
