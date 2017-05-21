/****************************************************************************
Fichero: base_centro
Autor: Tagoras
Fecha: 27/02/2009
Descripci�n: Base de una room del centro de entrenamiento
****************************************************************************/

#include "path.h"

inherit BASE_ANNUFAM;

create()
{
	::create();

	AddDetail("antorcha", "Es una antorcha que durante las horas de falta de luz sirve para alumbrar el centro. No tiene ninguna caracter�stica en especial.\n");
	AddDetail(({"farol","faroles"}), "Son faroles met�licos en cuyo interior arde una peque�a mecha.\n");
	AddDetail("suelo", "Est� formado por piedras de color verde y marr�n a imitaci�n de la ense�a oficial del dominio de Kha-annu.\n");
	AddDetail("techo", "Es un techo abovedado del que cuelgan algunos faroles.\n");

	SetIndoors(1);
	SetIntBright(45);
}
