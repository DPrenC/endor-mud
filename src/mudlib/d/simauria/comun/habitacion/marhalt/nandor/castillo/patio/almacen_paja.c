/****************************************************************************
Fichero: almacen_paja.c
Autor: Ratwor
Fecha: 29/12/2007
Descripci�n: Un almac�n de paja para las caballerizas.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("un almac�n de paja");
    SetIntLong("La parte del establo en que te encuentras est� repleta de montones de "
    "paja que llegan hasta el techo de viejas vigas rode�ndote por todas partes.\n");
    AddDetail("paja", "Hierba seca con la que se alimenta a los animales.\n");
    AddDetail("vigas", "A�osas vigas entre las que la paja antigua se mezcla con las "
    "telara�as.\n");
    SetIntNoise("Oyes el suave rumor del viento al colarse por las grietas de los aleros.\n");
    SetIntSmell("Percibes los t�picos olores de un establo: paja seca, cuero curtido, "
    "arreos engrasados, y el inconfundible olor seco de los caballos.\n");
    SetIntBright(30);
    AddExit("norte", "./caballerizas");
    SetLocate("el castillo de Nandor");
}
