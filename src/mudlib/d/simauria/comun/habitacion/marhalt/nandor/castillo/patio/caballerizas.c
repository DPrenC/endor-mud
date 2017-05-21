/****************************************************************************
Fichero: caballerizas.c
Autor: Ratwor
Fecha: 29/12/2007
Descripción: Las caballerizas del castillo
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("las caballerizas");
    SetIntBright(30);
    SetIntLong("Te encuentras en los establos del castillo, una estancia alargada "
    "adosada a la muralla oriental con largos pesebres y varios compartimentos alineados "
    "donde se guardan tanto las monturas de los Dhes-Bláin como las bestias de carga.\n"
    "Colgados de la pared ves una hilera de arreos para las monturas.  Un ancho "
    "pasillo recorre el establo hacia los pajares situados mas al sur. Al oeste queda "
    "la salida al patio de armas.\n");
    AddDetail("arreos", "Una serie de riendas, sillas de montar, fustas, alforjas, "
    "bocados, cinchas y cabezadas de diferentes tipos y tamaños.\n");
    SetIntNoise("Oyes el suave rumor del viento al colarse por las grietas de los aleros.\n");
    SetIntSmell("Percibes los típicos olores de un establo: paja seca, cuero curtido, "
    "arreos engrasados, y el inconfundible olor seco de los caballos.\n");
    AddExit("oeste", "./patio13");
    AddExit("sur", "./almacen_paja");
    AddDoor("oeste", "una puerta de madera",
    "Es una ancha puerta de madera para salir al patio de armas.\n",
    ({"puerta", "puerta de madera", "puerta ancha", "ancha puerta", "puerta del oeste",
    "puerta del patio"}));
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("cuadrupedos"), REFRESH_DESTRUCT, d3(2));
    AddItem(PNJCASTILLO("cuidador_caballos"), REFRESH_DESTRUCT);
}
