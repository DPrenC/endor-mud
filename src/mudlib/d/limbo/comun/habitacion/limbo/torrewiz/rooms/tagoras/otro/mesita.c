#include "path.h"

inherit THING;

public void create()
{
	::create();
	SetShort("una mesita");
	SetLong("Es una mesita de madera con un peque�o caj�n.\n");
	AddId("mesita");
}
