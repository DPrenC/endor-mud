/**
 * /std/room/details.c
 */

#include <door.h>
#include <messages.h>
#define MIRA_CLIMA ({"tiempo", "clima"})

private static mapping details, smells, noises, readmsgs;
private static string precontent;

//----------------------------------------------------------------------------

public int QueryIndoors(); // std/room/algo
public varargs int DoExplore(mixed arg); // /std/room/description
public mapping QueryDetails()   { return copy(details); }
public mapping QuerySmells()    { return copy(smells); }
public mapping QueryNoises()    { return copy(noises); }
public mapping QueryReadMsgs()  { return copy(readmsgs); }

//----------------------------------------------------------------------------

private static varargs void _add_expanded(mapping map, mixed desc, mixed det, string exa) {
	if (pointerp(desc)) {
		int i;
		for (i=sizeof(desc); i--; ) {
			map += ([desc[i]: det; exa]);
		}
	}
	else {
		map += ([desc: det; exa]);
	}

}

private static void _remove_expanded(mapping map, mixed desc) {
	if (member(map, desc)) {
		m_delete(map, desc);
	}
	else if (pointerp(desc)) {
		int i;

		for (i=sizeof(desc); i--; ) {
			if (member(map, desc[i])) {
				m_delete(map, desc[i]);
			}
		}
	}
}

public varargs void AddDetail(mixed det, mixed desc, string exa) {
	_add_expanded(details, det, desc, exa);
}

public void AddSmell(mixed det, mixed desc) {
	_add_expanded(smells, det, desc);
}

public void AddNoise(mixed det, mixed desc) {
	_add_expanded(noises, det, desc);
}

public void AddReadMsg(mixed det, mixed desc) {
	_add_expanded(readmsgs, det, desc);
}

public void RemoveDetail(mixed det) {
	_remove_expanded(details, det);
}

public void RemoveSmell(mixed det) {
	_remove_expanded(smells, det);
}

public void RemoveNoise(mixed det) {
	_remove_expanded(noises, det);
}

public void RemoveReadMsg(mixed det) {
	_remove_expanded(readmsgs, det);
}

public mixed GetDetail(string str) {
	if (!member(details, str))
	// comprobamos si va a mirar el tiempo, o si hay puertas, para mostrar el detalle
	{
	    mixed msg;
	    string res, salida, pshort, cserver;
	    object hab;
	    mixed puerta;
     if (member(MIRA_CLIMA, str) >= 0)
     {
         if (QueryIndoors()) return "Estás en un lugar cerrado.\n";
         if (!(cserver = TO->QueryClimateServer()))
         {
             return "No puedes ver el tiempo que hace desde esta habitación. Contacta con un wizard.\n";
         }
         return cserver->QueryWeatherMsg();
     }
     
     puerta = TO->FindDoor(str, 1);
     if (!puerta) return 0;
	    if (puerta == -1) return "¿Qué " + str + " quieres mirar exactamente?\n";
	    if (puerta->QueryDoorState() == DOOR_OPENED || !puerta->QueryDoorTransparency())
	    {
            return puerta->QueryLong();
	    }

	    pshort = puerta->QueryShort();
	    salida = TO->FindExitDoor(puerta);
	    if (!salida) return puerta->QueryLong();
	    hab = load_object(TO->QueryExitsDest()[salida]);
	    msg = puerta->QueryDoorTransparencyMsg() || ({0, 0});
	    tell_room(hab, ({MSG_SEE,
	                   (msg[1] ? funcall(msg[1], hab) :
    	                   "Ves a " + CAP(TNAME) + " mirar desde el otro lado de " +
	                       pshort + ".\n")}));
     return puerta->QueryLong() +
	           (!msg[0] ?
	            (TP->CanSee(hab) ? "A través de ella puedes observar " + hab->QueryIntShort(1) + ".\n" :
	             "Intentas mirar hacia el otro lado, pero no consigues ver nada.\n") :
	            funcall(msg[0], hab));
    }
	DoExplore(str);
 return funcall(details[str], str);
}

public string GetSmell(string str) {
	if (!str) {
		return TO->QuerySmell();
	}
	return funcall(smells[str], str);
}

public string GetNoise(string str) {
	if (!str) {
		return TO->QueryNoise();
	}
	return funcall(noises[str], str);
}

public string GetReadMsg(string str) {
	return funcall(readmsgs[str], str);
}

public int id(string str) {
	return str && (GetDetail(str) || GetSmell(str) || GetNoise(str) || GetReadMsg(str)) && 1;
}

public string QueryPreContent() {
	return precontent;
}

public string SetPreContent(string to) {
	return precontent = to;
}

public varargs string Content(string what, mixed excl, object pl) {
	object *obj;
	string str;
	mapping desc;
	mixed *idx;
	int i;

	if (!pointerp(excl)) {
		if (objectp(excl)) {
			excl = ({ excl });
		}
		else if (closurep(excl)) {
			excl = filter(obj, excl) || ({});
		}
		else {
			excl = ({});
		}
	}

	excl += ({ pl });
	desc = ([]);
	obj = all_inventory();

	for (i=sizeof(obj); i--; ) {
		str = obj[i]->QueryShort();
		if ((member(excl, obj[i]) != -1) || !str || str == "") {
			continue;
		}
		if (member(desc, str)) {
			desc[str]++;
		}
		else {
			desc += ([str:1]);
		}
	}

	str = precontent || "";
	idx = m_indices(desc);
	for (i=sizeof(idx); i--; ) {
		str += capitalize(idx[i]);
		if (desc[idx[i]] > 1) {
			str += "[" + desc[idx[i]] + "]";
		}
		if (str != "") {
			str += ".\n";
		}
	}
	return str;
}

void create() {
	details = ([]);
	smells = ([]);
	noises = ([]);
	readmsgs = ([]);
	precontent = "";
}