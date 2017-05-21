#include "path.h"
inherit "/obj/mochila";

create() {
	::create();
	SetAds(({"de gran calidad"}));
	SetIntShort("una mochila de gran calidad");
	SetIntLong("Dentro de una mochila de gran calidad.\n");
	SetLong("Es una mochila de cuero curtido de gran calidad, "
		"aunque de confección sobria. Tiene múltiples recovecos para "
		"guardar objetos y aprovechar al máximo su espacio.\n");
	SetShort("una mochila de gran calidad");
    SetWeight(1500); /* La mochila pesa 1500 gr */
    SetMaxIntWeight(15000); /* Podemos llevar hasta 15 kg */
}
