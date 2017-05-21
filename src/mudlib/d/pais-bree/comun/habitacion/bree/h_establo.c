/*
Fichero: h_establo.c
Autor: Aul�
Fecha: 02/12/2014
Descripci�n: establo de la herrer�a.
*/
#include "./path.h"
inherit BREE_ROOM;

create()
{
    ::create();
    	SetIntShort("un peque�o establo");
    	SetIntLong(
    	"Te encuentras en un peque�o establo cuyo techo desciende suavemente hacia el "
    	"oeste. En el muro de este lado hay un peque�o ventanuco que proporciona "
    	"ventilaci�n, y bajo dicho muro desaparece el canal de desag�e que recorre la "
    	"estancia de lado a lado. El suelo es de piedra irregular con argamasa y a lo "
    	"largo de la pared del sur hay un pesebre con s�lidos postes de madera para "
    	"sujetar a los animales.\n");
    	AddExit("norte", "./h_patio");
        AddDoor("norte", "la puerta del establo",
"Es una s�lida puerta de tablones que cierra el establo.\n",
    ({"establo", "norte", "puerta del norte", "puerta", "n"}));


    	}