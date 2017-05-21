/****************************************************************************
Fichero: base_room
Autor: Tagoras
Fecha: 27/02/2009
Descripción: Base de las rooms de los maestros de la segunda planta del centro.
****************************************************************************/

#include "path.h"

inherit HAB_SEGUNDA_ANNUFAM("base_planta");

create()
{
	::create();

	SetIntShort("la habitación de un maestro guerrero");
	AddDetail("cama", "Es una cama de estructura de madera y con colchón de paja. No es muy grande pero sí lo suficientemente cómoda para los oficiales enanos.\n");
	AddDetail(({"pared", "paredes"}), "Se trata de unas paredes de piedra muy parecidas a las del resto del edificio. Las mismas antorchas, la misma ventana y la misma sobriedad a excepción de un colorido tapiz.\n");
	AddDetail(({"tapiz"}), "Es un tapiz de lana con el escudo de K-hanu. En él puedes ver una corona con cinco diamantes en la parte superior y un león flanqueado por dos hachas sobre un fondo de color verde en la parte inferior.\n");
	AddItem(PNJ_CENTRO_ANNUFAM("maestro_guerrero"), REFRESH_DESTRUCT, 1);
}

void AddArcon()
{
	SetIntLong("Los guerreros nunca se han caracterizado por su pasión por el lujo, pero vaya. Pensabas que en las habitaciones de los superiores de este centro habría algo que las distinguiese un poco más de las de los miembros del ejército regular. En esta ves lo de siempre: una cama, un tapiz colgado de la pared y listo. La única diferencia es que en lugar de armario hay un arcón que parece cerrado.\n");
	AddDetail(({"mobiliario", "muebles"}), "Sólo hay una cama y un arcón");
	AddItem(OTRO_ANNUFAM("arcon_maestro"), REFRESH_REMOVE);
}

void AddArmario()
{
	SetIntLong("Estás en la habitación de uno de los maestros guerreros del centro de adiestramiento para guerreros enanos de Annufam. Aquí las cosas no son tan sobrias como en el resto de instalaciones, pero tampoco es para ponerse a echar cohetes. En una de las paredes ves un tapiz con el escudo del dominio de Kha-annu, y junto a la cama, un poco más grande y cómoda que la de los reclutas, un armario que parece estar cerrado.\n");
	AddDetail(({"mobiliario", "muebles"}), "Sólo hay una cama y un armario");
	AddItem(OTRO_ANNUFAM("armario_maestro"), REFRESH_REMOVE);
}

void AddNWindow()
{
	AddDetail("ventana", "Desde esta altura puedes contemplar toda la Arena de Annufam y allá lejos el perfil de las montañas de Kha-annu y los bosques de Lad-Laurelin.\n");
}

void AddSWindow()
{
	AddDetail("ventana", "Desde esta altura puedes contemplar toda la extensión de la ciudad de Annufam, desde la entrada a la misma y el foso hasta las mismas puertas del Centro de Adiestramiento para Guerreros Enanos.\n");
}
