#include "path.h"
inherit "/obj/mochila";

create() {
	::create();
	SetAds(({"de gran calidad"}));
	SetIntLong("Dentro de una mochila de gran calidad.\n");
	SetLong("Es una mochila de cuero curtido de gran calidad, "
		"aunque de confecci�n sobria. Tiene m�ltiples recovecos para "
		"guardar objetos y aprovechar al m�ximo su espacio. Lleva el "
		"emblema del gremio de los Guardabosques.\n");
	SetShort("una mochila de gran calidad");
    SetWeight(1500); /* La mochila pesa 1500 gr */
    SetMaxIntWeight(15000); /* Podemos llevar hasta 15 kg */

}
