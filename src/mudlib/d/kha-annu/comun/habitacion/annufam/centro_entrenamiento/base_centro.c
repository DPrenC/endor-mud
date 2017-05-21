/****************************************************************************
Fichero: base_centro
Autor: Tagoras
Fecha: 27/02/2009
Descripción: Base de una room del centro de entrenamiento
****************************************************************************/

#include "path.h"

inherit BASE_ANNUFAM;

create()
{
	::create();

	AddDetail("antorcha", "Es una antorcha que durante las horas de falta de luz sirve para alumbrar el centro. No tiene ninguna característica en especial.\n");
	AddDetail(({"farol","faroles"}), "Son faroles metálicos en cuyo interior arde una pequeña mecha.\n");
	AddDetail("suelo", "Está formado por piedras de color verde y marrón a imitación de la enseña oficial del dominio de Kha-annu.\n");
	AddDetail("techo", "Es un techo abovedado del que cuelgan algunos faroles.\n");

	SetIndoors(1);
	SetIntBright(45);
}
