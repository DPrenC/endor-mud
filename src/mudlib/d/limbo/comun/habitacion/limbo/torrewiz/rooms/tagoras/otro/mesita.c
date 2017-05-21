#include "path.h"

inherit THING;

public void create()
{
	::create();
	SetShort("una mesita");
	SetLong("Es una mesita de madera con un pequeño cajón.\n");
	AddId("mesita");
}
