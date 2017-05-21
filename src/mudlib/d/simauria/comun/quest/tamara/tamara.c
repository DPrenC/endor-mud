/*
DESCRIPCION : tamara, posible futura quest (ya se me ocurrira algo)
FICHERO     : tamara.c
MODIFICACION: 16-7-00 [Maler] Creacion; 13-09-00 [Maler] a por la kuest
14/01/2005: [kastwey@simauria]: retoco y le pongo que use el notify_enter
También le pongo que solo hable a quien no tenga hecho el quest.
Sangro el código.
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
#include <moving.h>


inherit NPC;

string preguntar_problema();
string preguntar_velo();
void devolver_objeto(object ob, object pl);
void comprobar_objeto(object ob, object pl);
string dialogo();
private int NoLucho(object agresor);

create()
{
  ::create();
 SetStandard("tamara","humano",15,GENERO_FEMENINO);
  AddAdjective("bella");
  AddId("tendera");
  AddId("tendera tamara");
  SetShort("Tamara");
  SetAlign(0);
  Set(P_CANT_LURE,1);
  AddQuestion(({"Tamara","Tamara","problema","busqueda","que buscas","alteracion","preocupacion"}),SF(preguntar_problema),1);
  AddQuestion(({"velo"}),SF(preguntar_velo),1);
  SetChkFightFunction(SF(NoLucho));
  SetChkMagicFunction(SF(NoLucho));
  InitChats(12,SF(dialogo));
}

private int NoLucho(object agresor)
{
  tell_room(environment(),W(CAP(NNAME(agresor))+" se abalanza sobre Tamara con intenciones hostiles "
  "pero de repente se detiene y se calma.\n"),(({agresor})));
  return notify_fail("Te abalanzas sobre Tamara con intenciones hostiles. De repente, Tamara te mira asustada. "
                     "Ves el miedo en sus perfectos ojos azules, y, sin saber porqué, detienes tu ataque y pides disculpas.\n");
}


void notify_enter(mixed from,int method,mixed extra)
{
	if (method == M_GIVE) call_out("comprobar_objeto",1,PO,from);
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

void comprobar_objeto(object ob, object pl)
{
	if (!pl) return;
	if (!present(pl,environment()))
	// el player se ha ido
	{
		say(W("Tamara mira hacia todos lados para hablar con " + capitalize(pl->QueryName()) + ". Al ver que no está, suelta " + ob->QueryShort() + " en el suelo mientras murmura algo ininteligible.\n"));
		ob->move(environment());
		return;
	}
	if (member(ob->QueryIds(),"quest_velo_tamara") >= 0)
	// es el velo
	{
		if (QUESTMASTER->QueryQuestSolved("cored_quest_tamara",pl))
		// lo tiene hecho
		{
			tell_object(pl, "Tamara mira el velo que le has dado y te dice: "
			"'Gracias " + capitalize(pl->QueryName()) + " pero con el velo "
			"que me diste ya tengo suficiente. De todos modos, muchas "
			"gracias, así tendré uno por si se me pierde el otro.\n");
			say( "Tamara mira el velo que le ha dado "
			+ capitalize(pl->QueryName()) + " y le dice algo que no consigues "
			"entender.\n",pl);
			tell_room(environment(),"A continuación, se guarda el velo.\n");
			ob->remove();
			if (ob) destruct(ob);
		}
		else
		// no tiene el quest hecho, así que se le da por resuelto
		{
      object carta, lagrima;
      tell_object(pl,W("Tamara te mira con sus profundos ojos azules, y, "
	      "al sonreirte, sus nacarados dientes brillan bajo la tenue luz de la lámpara. " +
  	    (pl->QueryGender() == 2?"Emocionada":"Azorado") + ", oyes como te dice con voz temblorosa: Muchas gracias, " + capitalize(pl->QueryName()) +
  	    ", ahora nadie podrá reconocerme, y podré volver a caminar libre por el mundo.\n"));
	    say(W("Tamara le dice algo a " + capitalize(pl->QueryName()) + " que ves como se emociona visiblemente.\n"),pl);
	    tell_object(pl,W("Ahora que vuelvo a ser libre, ¿puedes hacerme un ultimo favor?.\nLleva "
        "esta carta a Altur, en Nandor, el lo entenderá. Muchas gracias por todo, estoy en "
   		  "deuda contigo.\n Al mirarla ves que Tamara está llorando de pura felicidad. Una de sus "
        "lágrimas resbala por su mejilla, y la recoges como un recuerdo de su belleza.\n"));
      lagrima=clone_object("/d/kenton/comun/quest/bruja/lagrima");
		  if (lagrima->move(pl) != ME_OK)
		  {
		    tell_object(pl,"Sin poder evitarlo, la lágrima se te cae al suelo.\n");
		    say(W("Sin poder evitarlo, a " + capitalize(pl->QueryName()) + " la lágrima se le cae al suelo.\n"),pl);
		    lagrima->move(environment());
		  }
    	  carta=clone_object(QUEST+"/tamara/carta");
         carta->SetOwner(TP->QueryRealName());
         if (carta->move(pl) != ME_OK)
		  {
		    tell_object(pl,"Sin poder evitarlo, la carta se te cae al suelo.\n");
		    say(W("Sin poder evitarlo, a " + capitalize(pl->QueryName()) + " la carta se le cae al suelo.\n"),pl);
		    carta->move(environment());
		  }
		}
  }
  else
  // no es el velo
  {
   	tell_object(pl,W("Tamara observa " + ob->QueryShort() + " y te dice: ¿Un regalo? Te lo agradezco " + capitalize(pl->QueryName()) + " pero no puedo aceptarlo.\n"));
   	say(W("Tamara le dice algo a " + capitalize(pl->QueryName()) + ".\n"),pl);
   	devolver_objeto(ob,pl);
  }
  return;
}

public int QueryTamaraQuest() { return 1; }

string preguntar_problema()
{
  if (QUESTMASTER->QueryQuestSolved("cored_quest_tamara",TP))
  // lo tiene hecho
  {
    return W("Tamara te sonríe y te dice: Oh " + capitalize(TP->QueryName()) + ". Ya no tengo ningún problema, desde que tu me ayudaste a reencontrarme con mi querido Altur.\n");
  }
  else
  // no lo tiene hecho, así que se le contesta
  {
    return W("Tamara te dice: me gustaría volver con Altur, yo le quiero, pero la gente no lo permitiría. Quizá "
      "tener un velo me ayudaría. He oído que hay una hilendera en el bosque de Cored, alrededor de esta fortaleza.\n");
  }
}


string preguntar_velo()
{
  if (QUESTMASTER->QueryQuestSolved("cored_quest_tamara",TP))
  {
    return "Tamara te dice: '¿El velo? Bueno, gracias a tí pude conseguir el velo que necesitaba. Gracias de nuevo'.\n";
  }
  else
  {
    return W("Tamara te dice: He oido que en lo profundo del bosque de Cored vivía una famosa hilandera, si encuentras su hogar, quizá "
      "allí encuentres el velo que necesito.\n");
  }
}

public string QueryLong()
{
	return W("Estás ante una de las visiones más maravillosas que has visto en tu "
    "larga vida de " + (TP->QueryGuild() == "ninguno"?"vagabundo sin gremio":TP->QueryGuild()) + ". Es Tamara, una humana de belleza legendaria, conocida "
    "en todo el mundo. Su largo pelo rojo cae en cascada sobre unos hombros increíblemente "
    "bien formados y proporcionados. Cuando su mirada se posa sobre la tuya, adviertes la "
    "increíble belleza y profundidad de sus azules ojos, que consiguen derretir el centro de "
    "tu alma. La belleza de esta mujer es legendaria, originaria de Nandor, desapareció, cansada "
    "de sus muchos pretendientes, y nunca más se supo de ella, parece que has descubierto su misterio.\n");
}


string dialogo()
{
	string mensaje;
	if (!environment()) return "";
	switch(random(3))
	{
		case 0: mensaje = "Tamara dice: Que desgraciada soy, si al menos tuviera algo con lo que taparme\n"; break;
		case 1: mensaje = "Tamara dice: Ojalá tuviese un velo.\n"; break;
		case 2: mensaje = "Tamara dice: Como echo de menos a mi querido Altur.\n"; break;
	}
    foreach(object ob: all_inventory(environment()))
    {
        if (query_once_interactive(ob) && !QUESTMASTER->QueryQuestSolved("cored_quest_tamara", ob)) tell_object(ob,mensaje);
    }
    return "";
}
