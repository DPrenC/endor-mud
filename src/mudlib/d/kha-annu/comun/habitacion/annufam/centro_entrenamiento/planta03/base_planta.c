/****************************************************************************
Fichero: base_planta
Autor: [T] Tagoras
Fecha: 06/03/2009
Descripción: Base de las rooms de la planta 3 (segundo piso)
Copiado de la base_planta de la planta 2
[T] 23/03/2009: Añado sonidos.
****************************************************************************/

#include "path.h"
#include <sounds.h>

inherit HAB_CENTRO_ANNUFAM("base_centro");

string olor();
string QueryIntNoise();

create()
{
	::create();
	SetIndoors(1);
	SetIntBright(45);
	SetIntNoise("Se oyen algunos ruidos.\n");
	SetIntSmell(olor());
}

string olor()
{
	if (random(100) < 50)
		return "Estos enanos se ve que huelen fuerte siempre, puaj.\n";
	return "Aspiras el aire y te arrepientes de haberlo hecho tan profundamente.\n";
}

string QueryIntNoise()
{
	if (0 == random(2))
	{
		play_sound(TP, SND_SUCESOS("ronquido1"));
		return "Escuchas los ronquidos de algún enano mientras duerme.\n";
	}
	play_sound(TP, SND_SUCESOS("pasos1"));
	return "Se oyen unos pasos pero no eres capaz de detectar de donde proceden.\n";
}
