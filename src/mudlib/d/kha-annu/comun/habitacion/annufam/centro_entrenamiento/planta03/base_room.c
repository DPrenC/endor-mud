/****************************************************************************
Fichero: base_room
Autor: Tagoras
Fecha: 27/02/2009
Descripci�n: Base de las rooms de los maestros de la segunda planta del centro.
****************************************************************************/

#include "path.h"

inherit HAB_SEGUNDA_ANNUFAM("base_planta");

create()
{
	::create();

	SetIntShort("la habitaci�n de un maestro guerrero");
	AddDetail("cama", "Es una cama de estructura de madera y con colch�n de paja. No es muy grande pero s� lo suficientemente c�moda para los oficiales enanos.\n");
	AddDetail(({"pared", "paredes"}), "Se trata de unas paredes de piedra muy parecidas a las del resto del edificio. Las mismas antorchas, la misma ventana y la misma sobriedad a excepci�n de un colorido tapiz.\n");
	AddDetail(({"tapiz"}), "Es un tapiz de lana con el escudo de K-hanu. En �l puedes ver una corona con cinco diamantes en la parte superior y un le�n flanqueado por dos hachas sobre un fondo de color verde en la parte inferior.\n");
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT, 1);
}

void AddArcon()
{
	SetIntLong("Los guerreros nunca se han caracterizado por su pasi�n por el lujo, pero vaya. Pensabas que en las habitaciones de los superiores de este centro habr�a algo que las distinguiese un poco m�s de las de los miembros del ej�rcito regular. En esta ves lo de siempre: una cama, un tapiz colgado de la pared y listo. La �nica diferencia es que en lugar de armario hay un arc�n que parece cerrado.\n");
	AddDetail(({"mobiliario", "muebles"}), "S�lo hay una cama y un arc�n");
	AddItem(OTRO_ANNUFAM("arcon_maestro"), REFRESH_REMOVE);
}

void AddArmario()
{
	SetIntLong("Est�s en la habitaci�n de uno de los maestros guerreros del centro de adiestramiento para guerreros enanos de Annufam. Aqu� las cosas no son tan sobrias como en el resto de instalaciones, pero tampoco es para ponerse a echar cohetes. En una de las paredes ves un tapiz con el escudo del dominio de Kha-annu, y junto a la cama, un poco m�s grande y c�moda que la de los reclutas, un armario que parece estar cerrado.\n");
	AddDetail(({"mobiliario", "muebles"}), "S�lo hay una cama y un armario");
	AddItem(OTRO_ANNUFAM("armario_maestro"), REFRESH_REMOVE);
}

void AddNWindow()
{
	AddDetail("ventana", "Desde esta altura puedes contemplar toda la Arena de Annufam y all� lejos el perfil de las monta�as de Kha-annu y los bosques de Lad-Laurelin.\n");
}

void AddSWindow()
{
	AddDetail("ventana", "Desde esta altura puedes contemplar toda la extensi�n de la ciudad de Annufam, desde la entrada a la misma y el foso hasta las mismas puertas del Centro de Adiestramiento para Guerreros Enanos.\n");
}
