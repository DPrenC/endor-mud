/*
Archivo: perfume_botella.c
Autor: [T] Tagoras
Fecha: 10/03/2009
[T] 20/02/2009: Coorijo algunos strings. Añado SetContentValue y QueryContentValue para poner el precio del cc de perfume.
*/

#include <properties.h>

#define FLASK_WEIGHT			100		// El frasco pesa 100 gr (vacío)
#define FLASK_VALUE				150		// El frasco vacío vale 150 cobres
#define FLASK_MAX_CONTENT		50		// Capacidad del frasco en cc
#define PERFUME_VALUE_PER_CC	50		// Cada cc de perfume vale 50 cobres
#define PERFUME_USED			2		// Cada vaporización gasta 2cc de perfume
#define PERFUME_DENSITY			1.2		// Cada cc de perfume pesa 1.2 gr
#define PERFUME_PERSISTENCE		1800	// Lo persistencia del perfume una vez puesto (en seg)

inherit THING;

private int pContent, pMaxContent, pBaseWeight, pContentValue;
private float pContentWeight;
private string pPerfume;

public int SetContent(int i)
{
	if (environment()) environment()->AddIntWeight(-((pContent - i) * pContentWeight));
	return pContent = i;
}
public int QueryContent() { return pContent; }

public int SetMaxContent(int i) { return pMaxContent = i; }
public int QueryMaxContent() { return pMaxContent; }

public int SetBaseWeight(int i) { return pBaseWeight = i; }
public int QueryBaseWeight() { return pBaseWeight; }

public float SetContentWeight(float f) { return pContentWeight = f; }
public float QueryContentWeight() { return pContentWeight; }

public int QueryWeight() { return pBaseWeight + (int)(pContentWeight * pContent); }

public int SetContentValue(int i) { return pContentValue = i; }
public int QueryContentValue() { return pContentValue; }

public int SetValue(int i) { return ::SetValue(i); }
public int QueryValue() { return ::QueryValue() + (pContentValue * pContent); }

public string SetPerfume(string str) { return pPerfume = str; }
public string QueryPerfume() { return pPerfume; }

public void NoSmell(int silent)
{
	if (!silent)
		write ("Las últimas trazas de perfume de "+LOWER(QueryPerfume())+" desaparecen.\n");
	TP->SetSmell("");
}

public int cmd_aplicar(string str)
{
	string verb;
	string bot_ao = Query(P_GENDER) == GENDER_FEMALE ? "a" : "o";
	string bot_ella = Query(P_GENDER) == GENDER_FEMALE ? "la" : "el";
	string bot_ununa = Query(P_GENDER) == GENDER_FEMALE ? "una" : "un";

	verb = query_verb();
	if (!str || ("" == str))
		return notify_fail("¿"+CAP(verb)+" qué?", NOTIFY_ILL_ARG);
	if (-1 == member(QueryIds(), LOWER(str)))
		return notify_fail("No encuentras "+LOWER(str)+".\n", NOTIFY_NOT_OBJ);
	if (!QueryContent())
		return notify_fail(CAP(bot_ella) + " " + str + " está completamente vací"+bot_ao+".\n", NOTIFY_NOT_VALID);
	write("Aprietas el difusor y te aplicas un poco de perfume. Ahora olerás a "+QueryPerfume()+".\n");
	say(CAP(TNAME)+" coje "+bot_ununa+" "+LOWER(str)+" y se vaporiza un poco de su contenido por encima.\n", TP);
	SetContent(QueryContent()-PERFUME_USED);		// 2 cc
	if (QueryContent() < 0) SetContent(0);		// Por si acaso
	remove_call_out ( "NoSmell" );
	TP->SetSmell ( "Huele a "+QueryPerfume()+".\n");
	call_out ( "NoSmell", PERFUME_PERSISTENCE, 0 );

	return 1;
}

public string QueryLong()
{
	int porc = 100 * QueryContent() / QueryMaxContent();
	string bot_ao = Query(P_GENDER) == GENDER_FEMALE ? "a" : "o";
	string long, baselong = ::QueryLong() || "";
	string label;

	if (extern_call()) return baselong;
	label = " La etiqueta pone: "+CAP(QueryPerfume())+".";
	switch(porc)
	{
		case 0: long = "Está totalmente vací" + bot_ao; break;
		case 1..10: long = "Sólo le quedan algunas gotas de perfume"; break;
		case 11..20: long = "Está casi vací" + bot_ao; break;
		case 21..30: long = "Le queda poco perfume"; break;
		case 31..45: long = "Le queda algo menos de la mitad del perfume."; break;
		case 46..55: long = "Dirías que está más o menos medio llen" + bot_ao; break;
		case 56..70: long = "Aún le queda más de la mitad del perfume"; break;
		case 71..90: long = "Está casi llen" + bot_ao; break;
		case 91..95: long = "Está llen" + bot_ao; break;
		case 96..100: long = "El perfume llega justo hasta el borde"; break;
	}
	return (baselong[<1] == '\n' ? baselong[..<2] : baselong) + label + " " + long + ".\n";
}

create()
{
	::create();
	SetShort("un frasco de perfume");
	SetLong("Es un frasquito de cristal utilizado para llevar perfume. En su parte superior tiene un difusor para poder vaporizar su contenido.\n");
	SetIds(({"frasco", "frasquito"}));
	SetAds(({"un", "de", "perfume", "cristal"}));
	SetMaterial(M_CRISTAL);
	Set(P_GENDER, GENDER_MALE);
	SetValue(FLASK_VALUE);
	SetContent(FLASK_MAX_CONTENT);
	SetMaxContent(FLASK_MAX_CONTENT);
	SetBaseWeight(FLASK_WEIGHT);
	SetContentWeight(PERFUME_DENSITY);
	SetContentValue(PERFUME_VALUE_PER_CC);
	SetPerfume("flores frescas");
	NoSmell(1);
}

init()
{
	::init();
	add_action("cmd_aplicar", "aplicar");
	add_action("cmd_aplicar", "usar");
}

varargs int move(string dest, int method, mixed data)
{
	NoSmell(1);
	return ::move(dest, method, data);
}

int remove()
{
	NoSmell(1);
	return ::remove();
}
