/*
Pizarra para el castigo
*/

#include "path.h"
#include <colours.h>
#include <properties.h>

inherit THING;

#define BB_CAPACITY	10

protected string * aBBWritten;

public string * QueryBBWritten() { return aBBWritten; }
public string * SetBBWritten(string * written) { return aBBWritten = written; }
public string AddBBWritten(string written)
{
	if (!aBBWritten)
		aBBWritten = ({});
	if (sizeof(aBBWritten) > BB_CAPACITY)
		return "";
	else
	{
		aBBWritten += ({written});
		return written;
	}
}
public string ReadBBWritten()
{
	if (!aBBWritten)
		 aBBWritten = ({});
	return implode(aBBWritten, "\n") + "\n";
}
public string ClearBBWritten()
{
	aBBWritten = ({});
}

public string QueryExaLong()
{
	string msg;

	msg = "La pizarra consiste en una trozo pulido de roca de pizarra, por ello el nombre de pizarra. La pizarra es una roca homogénea formada por la compactación de arcillas. Esta que tenemos aquí es de un color "+TC_BLUE+"azulado+"TC_NORMAL+" oscuro y está formada por una sola laja.\n";
	if (!aBBWritten || (0==sizeof(aBBWritten)))
		msg += "Está totalmente limpia.\n";
	else
	{
		if (sizeof(aBBWritten) < BB_CAPACITY)
			msg += "Alguien ha escrito algo en ella, tal vez debas leer el contenido de la pizarra.\n";
		else
			msg += "Alguien la ha llenado de mensajes y ya no se puede escribir nada más hasta que se borre. Puedes leer el contenido de la pizarra.\n";
	}

	return msg;
}

public void create()
{
	::create();
	SetShort("una pizarra");
	SetLong("Es una pizarra donde los jugadores castigados han de escribir una frase repetidas veces como fórmula de castigo.\n");
	SetAds(({"de", "la"}));
	AddId("pizarra");
	AddSubReadMsg("contenido", SF(ReadBBWritten));
	SetNoGet("¡Serás animal! ¿Cómo pretendes llevarte la pizarra?.");
	SetSize(P_SIZE_HUGE);
	SetGender(GENERO_FEMENINO);
}
