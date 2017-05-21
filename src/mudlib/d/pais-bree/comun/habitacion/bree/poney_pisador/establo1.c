/*
Fichero: establo1.c
Autor: aulë
Fecha: 15/03/2013
Descripción:  norte del establo del Poney Pisador.
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
    	"Al norte se accede al patio de la posada, al sur continúa el establo y al oeste "
    	"observas una zona de almacenaje.\n");
AddDetail("paja",
    "Una leve capa de paja mullida y seca que cubre la zona que ocupan los animales, ocultando el suelo "
    "de piedra.\nEn la estancia del sur hay mucha más paja almacenada.\n");

        AddDetail("pajar",
    "Mucho más al sur de aquí vislumbras enormes montones de paja seca y balas de heno, parece "
    "tratarse del pajar de los establos.\n");

     AddExit("norte", "./arcada");
     AddExit("sur", "./establo2");
     AddExit("oeste", "./almacen");
     AddDoor("norte", "la puerta del establo",
     "Es una gran puerta de doble batiente que da acceso al patio interior de la posada.\n"
     "Está formada por anchos tablones sin pulir, unidos en posición vertical mediante "
     "tres grandes travesaños de madera de roble colocados en su parte interior y sujetos "
     "con enormes clavos de hierro.\n"
     "Su superficie está sucia de polvo y el vapor producido por la respiración de los "
     "animales y algunas telarañas anidan en los recovecos de la madera.\n",
    ({"puerta", "n", "norte", "porton", "portón", "puerta de los establos"}));
  }