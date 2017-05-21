/****************************************************************************
Fichero: almacen_paja.c
Autor: Ratwor
Fecha: 29/12/2007
Descripción: Un almacén de paja para las caballerizas.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("un almacén de paja");
    SetIntLong("La parte del establo en que te encuentras está repleta de montones de "
    "paja que llegan hasta el techo de viejas vigas rodeándote por todas partes.\n");
    AddDetail("paja", "Hierba seca con la que se alimenta a los animales.\n");
    AddDetail("vigas", "Añosas vigas entre las que la paja antigua se mezcla con las "
    "telarañas.\n");
    SetIntNoise("Oyes el suave rumor del viento al colarse por las grietas de los aleros.\n");
    SetIntSmell("Percibes los típicos olores de un establo: paja seca, cuero curtido, "
    "arreos engrasados, y el inconfundible olor seco de los caballos.\n");
    SetIntBright(30);
    AddExit("norte", "./caballerizas");
    SetLocate("el castillo de Nandor");
}
