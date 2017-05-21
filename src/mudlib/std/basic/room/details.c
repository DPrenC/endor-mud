/* /std/basic/room/details.c
   =========================
   [t] Theuzifan

   21-01-01 [t] Creación.
*/



private static mapping details, smells, noises, readmsgs;
private static string precontent;

/* obtener los detalles de /std/base/details */
public varargs string SetIntLong(string what) { return TO->SetLong(what); }
public varargs string SetIntShort(string what) {
	if (what) {
		if (what[<1] == '\n') {
			what = what[0..<2];
		}
		if (what[<1] == '.') {
			what = what[0..<2];
		}
		what = capitalize(what);
	}
	return TO->SetShort(what);
}
public varargs string SetExaIntLong(string what)  { return TO->SetExaLong(what); }
public varargs string SetIntNoise(string what) { return TO->SetNoise(what); }
public varargs string SetIntSmell(string what) { return TO->SetSmell(what); }

public string QueryIntLong() { return TO->QueryLong(); }
public string QueryIntShort() { return TO->QueryShort(); }
public string QueryExaIntLong() { return TO->QueryExaLong(); }
public string QueryIntNoise() {	return TO->QueryNoise(); }
public string QueryIntSmell() { return TO->QuerySmell(); }

public varargs string IntLong(string str) { return QueryIntLong(); }
public varargs string IntShort(string str) { return QueryIntShort(); }
public varargs string ExaIntLong(string str) { return QueryExaIntLong(); }
public varargs string IntNoise(string str) { return QueryIntNoise(); }
public varargs string IntSmell(string str) { return QueryIntSmell(); }

private static varargs void _add_expanded(mapping map, mixed desc, mixed det, string exa) {
	if (pointerp(desc)) {
		int i;
		for (i=0; i<sizeof(desc); i++) {
			map += ([desc[i]:det;exa]);
		}
	}
	else {
		map += ([desc:det;exa]);
	}
		
}

private static void _remove_expanded(mapping map, mixed desc) {
	if (member(map, desc)) {
		m_delete(map, desc);
	}
	else if (pointerp(desc)) {
		int i;
		
		for (i=0; i<sizeof(desc); i++) {
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
	if (!member(details, str)) {
		return 0;
	}
	return funcall(details[str], str);
}

public string GetSmell(string str) {
	if (!str) {
		return QueryIntSmell();
	}
	if (!member(smells, str)) {
		return 0;
	}
	return funcall(smells[str], str);
}

public string GetNoise(string str) {
	if (!str) {
		return QueryIntNoise();
	}
	if (!member(noises, str)) {
		return 0;
	}
	return funcall(noises[str], str);
}

public string GetReadMsg(string str) {
	if (!member(readmsgs, str)) {
		return 0;
	}
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
	
	for (i=0; i<sizeof(obj); i++) {
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
	for (i=0; i<sizeof(idx); i++) {
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

public varargs string GetIntDesc(int brief, mixed excl, object pl) {
	string desc;
	
	desc = "";
	if (!brief) {
		desc = QueryIntLong();
	}

	if (pl->QueryObvious()) {
		if (brief) {
			desc += "[";
		}
		desc += TO->Exits(brief, pl);
		if (brief) {
			desc += "]\n";
		}
	}
	
	return desc + Content(0, excl, pl);
}

void create() {
	details = ([]);
	smells = ([]);
	noises = ([]);
	readmsgs = ([]);
	precontent = "";
}