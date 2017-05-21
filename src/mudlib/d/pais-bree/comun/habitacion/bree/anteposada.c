/*
Fichero: anteposada.c
Autor: aul�
Fecha: 12/03/2013
Descripci�n: lugar ante la arcada de la posada del Poney Pisador,
donde se unen los caminos que bajan hacia las puertas de la villa al oeste y al sur. 
*/
#include "./path.h"
inherit HABITACION+"bree/base_aldea";
create()
{
    ::create();
    	SetIntShort("ante la posada");
    	SetIntLong(
    	"Est�s en una peque�a plazoleta donde el camino del Este que sube desde la puerta "
    	"occidental se nivela y gira hacia el sur, costeando la ladera de la colina y "
    	"terminando en la otra puerta por la que se puede traspasar la empalizada.\n"
    	"Ante ti se alza un edificio s�lido de tres pisos, levantado en piedra.\n"
    	"Es la afamada posada del Poney Pisador, centro de la aldea de Bree y lugar de "
    	"referencia para las gentes de las cuatro aldeas del pa�s hom�nimo.\n");
    	AddDetail(({"posada", "poney pisador"}),
    	"Es el edificio m�s grande de la aldea. Dispone de dos alas entre las que se "
    	"localiza una arcada cubierta que da acceso a un patio interior, as� como a los "
    	"establos y dem�s dependencias principales. El piso m�s bajo de los tres que "
    	"constituyen la posada est� socavado a medias en la falda rocosa de la colina.\n"
    	"Voces y risas surgen de las ventanas del piso inferior, donde se distinguen "
    	"algunas figuras borrosas a trav�s de las ventanas iluminadas y las espesas "
    	"cortinas.\n");
    	AddDetail(({"sur", "camino sur"}),
    	"Desde aqu� el camino gira hacia el sur serpenteando entre las casas dispersas y "
    	"los pocos comercios de Bree terminando ante la puerta de la empalizada.\n");
    	AddDetail(({"oeste", "camino oeste"}),
    	"Desde aqu� el camino gira al oeste descendiendo por la falda de la colina "
    	"entre las casas dispersas de Bree hasta la puerta occidental de la empalizada.\n");
    	SetIntNoise("escuchas el ruido de voces, canciones y charlas procedentes de la "
    	"posada que se levanta justo al este.\n");
    	AddExit("suroeste", "./vias12"); 
    AddExit("oeste", "./viao12");
     AddExit("este", HABITACION+"bree/poney_pisador/arcada");
    }