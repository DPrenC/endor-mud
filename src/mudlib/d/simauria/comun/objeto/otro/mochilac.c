// mochilac.c
// [n] Nemesis@Simauria
// Creaci�n: 14-Jul-2003
// A diferencia de "otros", yo s� pongo las cabeceras.
// una mochila de gran calidad, copiada de la que tiene
// Uzi en Lad-Laurelin (pero copiada de cp...)

#include "path.h"
inherit "/obj/mochila";

create() {
	::create();
	SetAds(({"de gran calidad"}));
	SetIntShort("una mochila de gran calidad");
	SetIntLong("Dentro de una mochila de gran calidad.\n");
	SetLong("Es una mochila de cuero curtido de gran calidad, "
		"aunque de confecci�n sobria. Tiene m�ltiples recovecos para "
		"guardar objetos y aprovechar al m�ximo su espacio.\n");
	SetShort("una mochila de gran calidad");
    SetWeight(1500); /* La mochila pesa 1500 gr */
    SetMaxIntWeight(15000); /* Podemos llevar hasta 15 kg */
}
