#include "path.h"

inherit THING;

public void create()
{
	::create();
	SetShort("una silla");
	SetLong("Es una silla de madera.\n");
	AddId("silla");
}
