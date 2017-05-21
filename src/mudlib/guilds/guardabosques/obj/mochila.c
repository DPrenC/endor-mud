#include "path.h"
inherit "/obj/mochila";

create() {
	::create();
	SetLong("Es una mochila de cuero curtido de buena manufactura, "
		"de corte sencillo y sobrio, pero que realizará "
		"estupendamente su labor. Lleva el emblema del gremio de "
		"los guardabosques.\n");
    SetWeight(1250); /* La mochila pesa 1250 gr */
    SetMaxIntWeight(12500); /* Podemos llevar hasta 12,5 kg */
}
