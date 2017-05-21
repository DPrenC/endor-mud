/*   granjero.c
     Creado por : Nemesis
     Fecha 28-Sep-98
     [n] Castellanizado. (Oct'02)
     12/01/2005: [kastwey@simauria]: simplifico un montón de código y hago
     que el chats solo se lo diga al que no tenga resuelto el quest.
     También hag oque la descripción cambie si quien lo mira
     tiene el quest hecho.
*/


#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <moving.h>
inherit NPC;

string dialogo();
void devolver_objeto(object ob, object pl);
void comprobar_objeto(object ob, object pl);

create() {
    ::create();
    SetStandard("Corl","humano",15,GENERO_MASCULINO);
    AddId(({"hombre","granjero","gran_jero"}));
    SetShort("El granjero");
    InitChats(5, ({ SF(dialogo) }) );
    InitAChats(10,({ "¡El granjero te escupe a la cara!\n",
        "El granjero grita desesperadamente.\n",
        "El granjero te maldice.\n" }));
    AddQuestion(({"problema","quest", "su problema"}),
    "El granjero dice: '¡Ah! ¡Alguien dispuesto a ayudarme! Estoy un poco enfermo y "
    "no puedo trabajar en mi granja. En una receta de mi abuela se explica cómo "
    "curarme, el problema es que no tengo el ingrediente principal: leche. Si tú "
    "pudieras conseguirme un poco de leche...'\n",1);

    AddQuestion(({"leche"}),
    "El granjero te dice: 'Mis vacas tienen mucha. El problema es que alguien ha robado "
    "mi cubo. Ofrecémela cuando la consigas.'\n",1);

    AddQuestion(({"cubo"}),
    "El granjero te dice: 'Es el único cubo que mis vacas aceptan para que las ordeñe. "
    "No se dejan ordeñar si no lo hago con ESE cubo. Lo malo es que un ladrón me lo robó "
    "hace unos días. Dicen que le pillaron mientras intentaba robar una percha "
    "en el castillo. Así que supongo que le encerrarían. Es todo cuanto sé... "
    "¡Ayúdame, por favor!'\n",1);
    SetCitizenship("nandor");
}


public string QueryLong()
{
  if (QUESTMASTER->QueryQuestSolved("ayudar_granjero",TP))
  // tiene el quest hecho
  {
    return "Este humano debe ser el dueño de la granja. Desde que le ayudaste parece muy contento y en buena forma.\n";
  }
  else
  {
    return "Este debe ser el dueño de la granja. Parece triste y enfermo.\n";
  }
}

string dialogo()
{
  string mensaje;
  if (!environment()) return "";
  switch(random(5))
  {
  	case 0: mensaje = "El granjero suspira: '¿Donde estará mi cubo?'\n"; break;
  	case 1: mensaje = "El granjero te dice: 'Necesito un poco de leche.'\n"; break;
  	case 2: mensaje = "El granjero te mira con cara triste.\n"; break;
  	case 3: mensaje = "El granjero mira melancólico hacia el horizonte.\n"; break;
  	case 4: mensaje =       "El granjero te dice: 'dame la leche cuando la tengas.'\n"; break;
  }

  foreach(object ob:all_inventory(environment()))
  {
    if (query_once_interactive(ob) && !QUESTMASTER->QueryQuestSolved("ayudar_granjero", ob)) tell_object(ob,mensaje);
  }
    return "";
}

public int QueryGranjeroNandor() { return 1; }

void notify_enter(mixed from,int method,mixed extra)
{
	call_out("comprobar_objeto",1,PO,TP);
}

void comprobar_objeto(object ob, object pl)
{
	if (!pl) return;
	if (!present(pl,environment()))
	// el player se ha quitao de enmedio
	{
		tell_room(environment(),W("El granjero observa " + ob->QueryShort() + " y luego busca con la mirada a " + capitalize(pl->QueryName()) + ". Al no encontrarlo, suelta " + ob->QueryShort() + " en el suelo.\n"));
		ob->move(environment());
		return;
	}
	if (member(ob->QueryIds(),"qbo_leche") >= 0)
	// es el cubo de la leche...
	{
		if (ob->QueryOwner() != pl->QueryRealName())
		// no es el propietario...
		// Teóricamente esto no debe pasar, pero me curo en salud.
		{
		  tell_object(pl,W("El granjero mira el cubo que le has "
		                   "dado y niega tristemente con la cabeza "
		                   "mientras te dice en tono recriminatorio: Esto no "
		                   "es lo que necesito.\nLa próxima vez, ordeña la "
		                   "vaca con tus propias "
		                   "manos... A saber de dónde has sacado el "
		                   "cubo...\n"));
          tell_room(environment(),"El granjero mira a " + capitalize(TNAME)
                    + " y le dice algo.\nVes como " + capitalize(TNAME)
                    + "enrojece visiblemente.\n", ({pl}));
    devolver_objeto(ob,pl);
          return;
        }
        if (QUESTMASTER->QueryQuestSolved("ayudar_granjero",pl))
		// ya lo había hecho antes.
		{
      tell_object(pl,W("El granjero observa el cubo que le acabas de dar y te dice: Gracias por la leche " + capitalize(pl->QueryName()) + ", pero por ahora no necesito más. Quédatela tú si quieres.\n"));
      devolver_objeto(ob,pl);
    }
    else
    // no lo ha hecho, así que se le da por resuelto
    {
    QUESTMASTER->SetPlayerQuest("ayudar_granjero",pl);
    write_file(LOGS "GRANJEROQUEST",capitalize(pl->QueryRealName())+
      " resolvio el quest el "+ctime(time())+"\n");
      tell_object(pl,"El granjero te mira lleno de felicidad y coge el cubo. Se dirige a la cocina "
        "y pronto sientes olor a leche caliente.\nAl poco rato vuelve corriendo y te dice: "
        "Muchas gracias!!! Ahora podre dedicarme a trabajar en mi granja!\n");
        QUESTMASTER->InformSolution("Un granjero ha recuperado la salud, gracias a "+
            capitalize(pl->QueryName())+"!!\n");
        ob->remove();
        if (ob) destruct(ob);
    }
  }
  else if (member(ob->QueryIds(),"qbo") >= 0)
  // el cubo está vacío, sin leche.
  {
  	tell_object(pl,W("El granjero te dice: Oh " + capitalize(pl->QueryName()) + "! gracias por el cubo, pero desgraciadamente no tengo fuerzas para ordeñar a las vacas. Por favor, hazlo tú y traeme el cubo con la leche.\n"));
  	say(W("El granjero le dice algo a " + capitalize(pl->QueryName()) + ".\n"),pl);
  	devolver_objeto(ob,pl);
  }
  else if (member(ob->QueryIds(),"cubo") >= 0 && !living(ob))
  // tiene una id cubo... lo del living es para evitar
  // que le den un familiar con nombre cubo... nada, que soy mu rebuscao ;)
  {
  	if (QUESTMASTER->QueryQuestSolved("ayudar_granjero",pl))
  	{
  		tell_object(pl,W("El granjero mira el cubo que le has dado y te dice: Gracias por el regalo, " + capitalize(pl->QueryName()) + " pero no puedo aceptarlo.\n"));
  	}
  	else
  	{
  		tell_object(pl,W("El granjero observa el cubo que le has dado y te dice... Hmmm. Gracias por el cubo " + capitalize(pl->QueryName())+ " pero este no es exactamente el que necesito.\n"));
  	}
  	say(W("El granjero le dice algo a " + capitalize(pl->QueryName()) + ".\n"),pl);
  	devolver_objeto(ob,pl);
  }
  else
  // no es un cubo
  {
  	tell_object(pl,W("El granjero observa " + ob->QueryShort() + " y te dice: Gracias por el regalo " + capitalize(pl->QueryName()) + " pero no puedo aceptarlo.\n"));
  	say(W("El granjero le dice algo a " + capitalize(pl->QueryName()) + ".\n"),pl);
  	devolver_objeto(ob,pl);
  }
}

void devolver_objeto(object ob, object pl)
{
	tell_object(pl,W(QueryName() + " te devuelve " + ob->QueryShort() + ".\n"));
  say(W(QueryName() + " le devuelve " + ob->QueryShort() + " a " + capitalize(pl->QueryName()) + ".\n"),pl);
  if (ob->move(pl) != ME_OK)
  {
    tell_object(pl,W("Sin poder evitarlo, " + ob->QueryShort() + " se te cae al suelo.\n"));
    say(W("Sin poder evitarlo, a " + capitalize(pl->QueryName()) + " se le cae " + ob->QueryShort() + " al suelo.\n"),pl);
    ob->move(environment());
  }
}
