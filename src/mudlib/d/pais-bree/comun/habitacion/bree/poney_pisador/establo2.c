/*
Fichero: establo2.c
Autor: aulë
Fecha: 18/03/2013
Descripción:  sur del establo del Poney Pisador.
*/
#include "./path.h"
inherit HABITACION+"bree/poney_pisador/bestablo";
create()
{
    ::create();
    	SetIntShort("establos del Poney Pisador");
    	    	SetIntLong("Estos son los establos del Poney Pisador, un largo recinto ubicado "
    	"bajo el ala sur de la posada.\n"
    	"Grandes pesebres alternados con bebederos se alinean en la parte baja de ambos "
    	"muros, con divisiones de madera para separar a los animales estabulados entre sí.\n"
    	"Un ancho pasillo central discurre entre ambas hileras de pesebres, separado de la "
    	"zona que ocupan los animales por un canal de desagüe para los orines y "
    	"excrementos de las bestias.\n"
    	"El suelo de piedra está cubierto de paja en la zona de los pesebres y de piedra "
    	"rústica en el pasillo, al igual que la que forma los gruesos muros. Grandes "
    	"vigas de roble soportan el techo.\n"
    	"Al norte vislumbras la puerta de los establos y al sur estos finalizan en un "
    	"espacio umbrío lleno de heno hasta el techo.\n");

    AddDetail("paja",
    "Una leve capa de paja mullida y seca que cubre la zona que ocupan los animales, ocultando el suelo "
    "de piedra.\nEn la estancia del sur hay mucha más paja almacenada.\n");

        AddDetail("pajar",
    "Al sur de aquí vislumbras enormes montones de paja seca y balas de heno, parece "
    "tratarse del pajar de los establos.\n");

         AddExit("norte", "./establo1");
     AddExit("sur", "./pajar");
    }