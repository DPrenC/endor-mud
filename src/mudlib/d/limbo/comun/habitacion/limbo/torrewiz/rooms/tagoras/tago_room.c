#include "path.h"
#include <magia.h>
#include <moving.h>
#include <properties.h>

inherit ROOM;

#define NUMBER(x) ({"dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve", "diez"})[x-2]

protected int nMXP;

public int cmd_mxp(string str);
public QueryMXP() { return nMXP; }
public SetMXP(int i) { return nMXP = i; }

public string QueryMXPIntLong() { return ::QueryIntLong(); }

public void EnableMXPPlayer()
{
	int i;
	string * indices;
	mapping mMXP = ([
		"MXP_TAG":MXP_TAG,
		"MXP_SEND_READ":"<send href=\"leer &text;\">",
		"MXP_SEND_LOOK":"<send href=\"mirar &text;\">",
		"MXP_NO_SEND":"</send>",
		"MXP_SEND":"<send href=\"",
		"MXP_END_SEND":"\">",
	]);
	indices = m_indices(mMXP);
	for (i = 0; i < sizeof(indices); i++)
		TP->SetColour(indices[i], m_entry(mMXP, indices[i])[0]);
}

public int cmd_mxp(string str)
{
	if (!str || (-1==member(({"on", "off"}), LOWER(trim(str)))))
		return notify_fail("mxp <on|off>", NOTIFY_ILL_ARG);
	if ("on"==LOWER(trim(str)))
	{
		write ("MXP habilitado para esta room.\n");
		SetMXP(1);
		EnableMXPPlayer();
	}
	if ("off"==LOWER(trim(str)))
	{
		write ("MXP deshabilitado para esta room.\n");
		SetMXP(0);
	}

	return 1;
}

public void create()
{
	::create();
	Set(P_TPORT,TPORT_NO);
	AddRoomCmd("mxp", "cmd_mxp");
}

public string MXPSend(string comando, string texto)
{
	if ("leer" == comando)
		return "%^MXP_TAG%^%^MXP_SEND_READ%^"+ texto +"%^MXP_NO_SEND%^";
	if ("mirar" == comando)
		return "%^MXP_TAG%^%^MXP_SEND_LOOK%^"+ texto +"%^MXP_NO_SEND%^";
	return "%^MXP_TAG%^%^MXP_SEND%^"+comando+"%^MXP_END_SEND%^"+texto+"%^MXP_NO_SEND%^";
}

public string QueryIntLong()
{
	string base_long = ::QueryIntLong();
	//string dummy;
	//string * indices;
	//int i, idx;

	if (!QueryMXP()) return base_long;
	else return QueryMXPIntLong();

/*
	indices = m_indices(QueryDetails());
	for (i=0; i < sizeof(indices); i++)
	{
	}
*/
}

// Func: MakeExitString() -> Devuelve la cadena con las salidas dependiendo
// de los parámetros de entrada.
//
public varargs string MakeExitString( int brief, string *dirs, int hidden )
{
    int s;
    string str;


    dirs = sort_array(dirs, (:member(({"norte", "nordeste", "este", "sudeste", "sur",
                                       "suroeste", "oeste", "noroeste", "arriba", "abajo",
                                       "entrar", "salir" }), (pointerp($2) ? $2[0] : $2)) >= 0:));

    if( brief )
    {
        dirs = map( dirs, SF(map_brief_exit ));
        return implode( dirs, "," );
    }

	if (QueryMXP())
    	dirs = map(dirs, (:(pointerp($1) ? "%^MXP_TAG%^%^MXP_SEND%^" + "abrir " + $1[0] + "%^MXP_END_SEND%^" + $1[0] + "%^MXP_NO_SEND%^" + " (cerrada por " + $1[1] + ")" : "%^MXP_TAG%^%^MXP_SEND%^" + $1 + "%^MXP_END_SEND%^" + $1 + "%^MXP_NO_SEND%^"):));
	else
    	dirs = map(dirs, (:(pointerp($1) ? $1[0] + " (cerrada por " + $1[1] + ")" : $1):));
    switch( s = sizeof( dirs))
    {
        case 0: return (!hidden ? "No existe ninguna salida obvia.\n" :
                                  "No hay salidas ocultas.\n");
        case 1:
            return (!hidden ? "Hay una salida obvia: " : "OCULTA: ") + dirs[0] + ".\n";
        case 2..10:
             str = (!hidden ? "Hay " + NUMBER(s) + " salidas obvias: " :
                              "OCULTAS [" + NUMBER(s) + "]: ");
             break;
        default:
             str = (!hidden ? "Hay muchas salidas obvias: " : "OCULTAS: ");
    }
    return str+ implode_list(dirs) + ".\n";
}
