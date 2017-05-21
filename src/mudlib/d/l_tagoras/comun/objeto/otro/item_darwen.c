/*
Archivo: item_darwen.c
Autor(es): [T] Tagoras
Fecha: 12/03/2009
Descripcion: Item base para los retos de Darwen.
*/

#include "path.h"
#include <colours.h>
#include <properties.h>
#include <moving.h>
#include <sounds.h>

#define ITEM_N		((Query(P_NUMBER) == NUMERO_PLURAL)?"n":"")

inherit THING;

protected string sPlayer;
protected int nExpiry;

public void Destroy()
{
	write(CAP(QueryShort())+" brilla"+ITEM_N+" intensamente y desaparece"+ITEM_N+" en un fogonazo.\n");
	say("Algo en "+CAP(TNAME)+" emite un poderoso fogonazo y desaparece como por arte de magia.\n", TP);
	play_sound(environment(), SND_MAGIA("reducir"), 0, 60);
	destruct(TO);
}

public int IsExpired () { return (nExpiry < time()); }
public int QueryExpiry () { return nExpiry; }
public int SetExpiry (int expiry)
{
	remove_call_out("Destroy");
	nExpiry = expiry;
	if (nExpiry > time())
		call_out("Destroy", nExpiry-time());
	else
		call_out("remove", 1);
	return nExpiry;
}

public string QueryPlayer() { return sPlayer; }
public string SetPlayer(string str) { return (sPlayer = LOWER(str)); }

public string QueryArtDetString()
{
	switch (Query(P_NUMBER))
	{
		case NUMERO_SINGULAR:
			return ((QueryGender()==GENERO_FEMENINO)?"la":"el"); break;
		case NUMERO_PLURAL:
			return ((QueryGender()==GENERO_FEMENINO)?"las":"los"); break;
	}
	return "indeterminado";
}

public string QueryShort()
{
	string base_short = ::QueryShort() || "";
	string tip;

	if (extern_call()) return base_short;

	if (TP && (TP->QueryRealName() == QueryPlayer()))
		tip = " "+TC_BOLD+"[RETO]"+TC_NORMAL;
	else
		tip = "";

	return base_short + tip;
}

public void create()
{
	::create();
	SetShort("el objeto de Darwen");
	SetLong("Es un objeto indefinible.\n");
	SetWeight(50);
	SetValue(50);
	SetIds(({"objeto", "objeto_darwen"}));
	SetAds(({"el", "de", "Darwen"}));
	Set(P_NUMBER, NUMERO_SINGULAR);
	SetGender(GENERO_MASCULINO);
	SetSize(P_SIZE_SMALL);
	//SetNoDrop(1);
	//SetNoGive(1);
	//SetNoSell(1);
	Set(P_NOSELL, "A Darwen no le gustaría eso.\n");
	if (nExpiry && IsExpired())
		call_out("Destroy", 1);
	AddClassId("objeto_darwen");
}

varargs int move(mixed dest, int method, mixed data)
{
	//if (find_object("tagoras")) dtell("tagoras",sprintf("Mover a %O con el método %d y datos %O\n", dest, method, data));
	switch (method)
	{
		case M_GET:
			if (QueryPlayer() && (QueryPlayer()!=TP->QueryRealName()))
			{
				return ME_NO_GET;
			}
			break;
/*
		case M_GIVE:
			if (PO && dest->QueryDarwen())
			{
				PO->command_me("reto acabar");
				return ME_DESTRUCTED_SELF;
			}
			//return ME_NO_GIVE;
			break;
*/
	}
    return ::move(dest, method, data);
}
