#include <size.h>
#include <bags.h>

inherit "/obj/bag";

create() {
	::create();
	SetIds(({"mochila"}));
	SetIntShort("una mochila");
	SetIntLong("Dentro de una mochila.\n");
	SetLong("Es una mochila de cuero curtido de buena manufactura, "
		"de corte sencillo y sobrio, pero que realizará "
		"estupendamente su labor. Lleva el emblema del gremio de "
		"los guardabosques.\n");
	SetShort("una mochila");
    SetWeight(1000); /* La mochila pesa 1000 gr */
    SetMaxIntWeight(10000); /* Podemos llevar hasta 10 kg */
    SetBagType(B_BACK);
    SetSize(P_SIZE_MEDIUM);
}
