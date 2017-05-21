/*
Archivo: reloj_darwen.c
Autor(es): [T] Tagoras
Fecha: 10/03/2009
[T] 23/03/2009: Añado sonidos.
*/

#include "path.h"
#include <colours.h>
#include <properties.h>
#include <sounds.h>

inherit THING;

private int nType;
private string sRoom;
private string sItemId;
private int nExpiry;
private int nClue;
private int nTarget;
private int nTargetDone;

public void Destroy()
{
	play_sound(TP, SND_SUCESOS("cristal_roto"), 0, 60);
	write("El reloj de arena comienza a vibrar, se resquebraja y se deshace en un montón de polvo que se lleva el aire.\n");
	say("Algo en "+CAP(TNAME)+" se deshace en una nube de polvo que es barrida por el aire.\n", TP);
	destruct(TO);
}

public int IsExpired () { return (nExpiry < time()); }
public int QueryExpiry () { return nExpiry; }
public int SetExpiry (int expiry)
{
	remove_call_out("Destroy");
	if (expiry < time())
		call_out("Destroy", 1);
	else
		call_out("Destroy", expiry-time());
	return nExpiry = expiry;
}

public string QueryItemId() { return sItemId; }
public string SetItemId(string str) { return sItemId = str; }

public string QueryRoom() { return sRoom; }
public string SetRoom(string str) { return sRoom = str; }

public int QueryTarget() { return nTarget; }
public int SetTarget(int i) { return nTarget = i; }

public int QueryTargetDone() { return nTargetDone; }
public int SetTargetDone(int i) { return nTargetDone = i; }

public int QueryType() { return nType; }
public int SetType(int type) { return nType = type; }

public int QueryClue() { return nClue; }
public int SetClue(int clue) { return nClue = clue; }

public string QueryLong()
{
	string baselong = ::QueryLong() || "";
	string rest;
	int rest_time = QueryExpiry() - time();

	if (extern_call()) return baselong;

	if (rest_time < 0)
	{
		remove_call_out("Destroy");
		rest = "El tiempo que tenías ha concluido. No has cumplido la misión que te encomendó Darwen.\n";
		call_out("Destroy", 1);
	}
	else
	{
		play_sound(TP, SND_SUCESOS("reloj_tictac_rapido"), 0, 60);
		rest = "\nTe quedan "+(rest_time/60)+" minutos";
		if (rest_time%60)
			rest += " y "+(rest_time%60)+" segundos";
		rest += " para completar tu misión.\n";
	}
	
	return (baselong[<1] == '\n' ? baselong[..<2] : baselong) + " " + rest;
}

public void create()
{
	::create();
	SetShort("un reloj de arena");
	SetLong("Es un reloj de arena que indica el tiempo que te queda para poder completar la misión que te ha asignado Darwen.");
	SetMaterial(M_CRISTAL);
	SetWeight(250);
	SetValue(50);
	SetIds(({"reloj", "reloj_darwen"}));
	SetAds(({"un", "de", "arena"}));
	SetGender(GENERO_MASCULINO);
	Set(P_NUMBER, NUMERO_SINGULAR);
	SetSize(P_SIZE_SMALL);
	SetNoDrop(1);
	SetNoGive(1);
	Set(P_NOSELL, "Si lo vendes no pordrás saber cuanto tiempo te queda para completar la misión que te encomendó Darwen.\n");
	if (QueryExpiry() && IsExpired())
		call_out("Destroy", 1);
}
