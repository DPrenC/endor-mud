/*
DESCRIPCION : el hechicero Ereldil
FICHERO     : /d//comun/pnj///ereldil.c
MODIFICACION: 21-10-00 [Maler] Creacion
21/01/2005: [kastwey] reescribo muchas cosillas.

--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <guild.h>
#include <moving.h>

inherit NPC;

void devolver_objeto(object ob, object pl);
void comprobar_objeto(object ob, object pl);
string preguntar_gema();
string preguntar_problema();
string dialogo();

//QueryLong, devuelve un long si le has ayudado y otro si no lo has hecho

public mixed QueryLong()
{
    mapping Spells;
    Spells=TP->QuerySpells() || ([]);
    //Compruebo gremio.
    if(TP->QueryGuild() != GC_HECHICEROS && TP->QueryGuild() != GC_CONJURADORES)
    // dos gremios que aceptan este conjuro.
    {
    	  return "Ves a Ereldil, el famoso hechicero. Su mirada "+
        "penetrante refleja su sabidur�a superior, su manto y su cayado son sus s�mbolos, s�mbolos de un hechicero "+
        "de alto nivel que no le tiene miedo a nada.\n";
    }
    //compruebo si le has ayudado o no
    if(!Spells["bola de fuego"] || Spells["bola de fuego",1]<70)
    // o no tiene el conjuro o lo tiene a nivel < 70
    {
        return "Ves a Ereldil, el famoso hechicero. Seg�n cuentan, Ereldil se cans� de los riesgos "+
        "que conllevaba ser un hechicero poderoso y conocido, y se retir� a un sitio donde su magia "+
        "fuera aceptada, y donde nadie le requiriese, concentr�ndose en el estudio de nuevos hechizos. "+
        "Est� registrando las estanter�as de su laboratorio, al parecer no encuentra algo.\n";
    }
    else
    // ya le has ayudado
    {
        return "Ves a Ereldil, que te reconoce y te sonr�e al verte entrar.\n";
    }
}


void notify_enter(mixed from,int method,mixed extra)
{
 	  if (from->QueryIsPlayer() && method == M_GIVE) call_out("comprobar_objeto",1,PO,from);
 	  return ::notify_enter(from, method, extra);
}


create()
{
    ::create();
   SetStandard("ereldil","elfo",40,GENDER_MALE);
    SetShort("Ereldil, el famoso hechicero");
    AddId("hechicero");
    AddQuestion(({"busqueda","problema","alteracion","preocupacion"}),SF(preguntar_problema),1);
    AddQuestion(({"gema","Gema"}),SF(preguntar_gema),1);
    InitChats(10, ({ SF(dialogo) }) );
}

void comprobar_objeto(object ob, object pl)
{
	  int i;
    mapping spells;
    if (!environment()) return;
    if (!pl || !present(pl,environment()))
    // el player se ha largao
    {
        tell_room(environment(),W("Arandil mira hacia todos lados buscando a quien le ha dado " + ob->QueryShort() + ". Extra�ado, pone cara de disgusto y suelta " + ob->QueryShort() + ".\n"));
        ob->move(environment());
        return;
    }
    // comprobamos que sea este el objeto que busca
    if (member(ob->QueryIds(),"spell_bola_ereldil") < 0)
    // no es
    {
    	  tell_object(pl,W("Ereldil te dice: Oh " + capitalize(pl->QueryName()) + ". un regalo? Lo siento, pero no puedo aceptarlo. Muchas gracias de todos modos.\n"));
    	  say(W("Ereldil le dice algo a " + capitalize(pl->QueryName()) + ".\n"),pl);
    	  devolver_objeto(ob,pl);
    	  return;
    }
    if (pl->QueryGuild() != GC_HECHICERO && pl->QueryGuild() != GC_CONJURADOR)
    // comprobamos si no pertenece a ninguno del os dos gremios para los que es
    // v�lido este hechizo.
    {
    	  tell_object(pl,W("Ereldil te mira y te dice: Oh " + capitalize(pl->QueryName()) + " un regalo? Lo siento, pero no puedo aceptarlo. Gracias de todos modos.\n"));
    	  say(W("Ereldil le dice algo a " + capitalize(pl->QueryName()) + ".\n"),pl);
    	  devolver_objeto(ob,pl);
    	  return;
    }
    // pertenecen a uno de estos dos gremios.
    // ahora se comprueba si saben el conjuro, lo que quiere decir que ya le hab�an ayudado.
    spells = pl->QuerySpells() || ([]);
    if (!spells["bola de fuego"] || spells["bola de fuego",1] < 70)
    // o no lo saben o lo saben a un nivel inferior a 70
    {
    	  tell_object(pl, "Ereldil dice: Gracias camarada, ahora puedo seguir con mi investigaci�n.\n\n"
        "A cambio de tus esfuerzos, y de la ayuda que me has prestado, voy a ense�arte un hechizo que te ser� de "
        "gran utilidad en tu camino.\n\nEreldil pasa largo tiempo explic�ndote los entresijos del hechizo "
        "'bola de fuego', hasta que llegas a dominarlo en su base.\n");
        say("Ereldil le dice algo a " + capitalize(pl->QueryName()) + " mientras su rostro se ilumina con una radiante sonrrisa.\n",pl);
        ob->remove();
        if (ob) destruct(ob);
       	TP->AddPlayerSpell("bola de fuego", random(5)+1, 70, P_INT);
        return;
    }
    // ya se sabe el conjuro, as� que eso es que ya le ayud�:
    {
    	  tell_object(pl, "Ereldil dice: gracias, amigo, pero.... ya me habias dado la gema.\n"
    	  "Ereldil se guarda la gema.\n");
    	  say("Ereldil le dice algo a " + capitalize(pl->QueryName()) + ".\n",pl);
    	  ob->remove();
    	  if (ob) destruct(ob);
    	  return;
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

string dialogo()
{
  	string mensaje;

  	if (!environment()) return 0;
  	switch(random(2))
  	{
        case 0: mensaje = "Ereldil dice: Vaya, jurar�a que estaba por aqu�.\n"; break;;
        case 1: mensaje = "Ereldil rebusca por las estanter�as.\n"; break;;
    }

    foreach(object ob: all_inventory(environment())) {
      if (   ob->QueryIsPlayer()
          && (   ob->QueryGuild() == GC_HECHICERO
              || ob->QueryGuild() == GC_CONJURADOR
             )
          && (  !ob->QuerySpells()["bola de fuego"]
              || ob->QuerySpells()["bola de fuego",1] < 70
             )
         )
      {
        tell_object(ob, mensaje);
      }
    }
    return 0; // [Nyh] Para evitar el warning de no return
}

string preguntar_problema()
// funci�n que se ejecuta al preguntarle a ereldil sobre problema.
{
	  mapping spells;
	  if (!TP || !TP->QueryIsPlayer()) return "";
	  if (TP->QueryGuild() != GC_HECHICERO && TP->QueryGuild() != GC_CONJURADOR)
	  {
	  	  return W("Ereldil te dice: Bueno " + capitalize(TP->QueryName()) + ", s� que tengo un problema, pero necesito que me ayude o un hechicero o un conjurador. �Conoces alguno?\n");
	  }
	  spells = TP->QuerySpells() || ([]);
	  if (!spells["bola de fuego"] || spells["bola de fuego",1] < 70)
	  // se le responde a la pregunta, pues, o no tiene el conjuro,
	  // o lo tiene con un nivel inferior a 70.
	  {
		    return W("Ereldil dice: casi he completado la investigaci�n de un nuevo hechizo, pero "
            "necesito una gema..... vaya, estaba seguro de que ten�a una por aqu�.... de cualquier "
            "forma, me har�as un gran favor si me la consiguieras. Quiz� te cueste encontrarla, pero "
            "yo encontr� la m�a en Betwa, cerca de Gorat, en una cueva de trolls... todav�a recuerdo "
            "mi �ltimo combate con shad, cuidate de �l, es extremadamente peligroso, igual voy a hacerle "
            "una visita un d�a de estos, cuando acabe mi investigaci�n.\n"
            "Ereldil sonr�e afablemente.\n");
    }
    // ya le ha ayudado anteriormente, pues tiene el conjuro bien aprendido.
    return W("Ereldil te mira y con una sonrrisa te dice: �Problema? no, ya no tengo ning�n problema. Desde que me trajiste la gema, mi nuevo hechizo va viento en popa!\n");
}

string preguntar_gema()
// funci�n que se ejecuta al preguntarle a ereldil sobre problema.
{
	  mapping spells;
	  if (!TP || !TP->QueryIsPlayer()) return "";
	  if (TP->QueryGuild() != GC_HECHICERO && TP->QueryGuild() != GC_CONJURADOR)
	  {
	  	  return W("Ereldil te dice: Bueno " + capitalize(TP->QueryName()) + ", estoy buscando una gema para completar la investigaci�n de uno de mis hechizos, pero no se donde la he dejado. De todos modos, necesitar�a la ayuda de un hechicero o de un conjurador. �Conoces alguno?\n");
	  }
	  spells = TP->QuerySpells() || ([]);
	  if (!spells["bola de fuego"] || spells["bola de fuego",1] < 70)
	  // se le responde a la pregunta, pues, o no tiene el conjuro,
	  // o lo tiene con un nivel inferior a 70.
	  {
		    return W("Ereldil dice: Los est�pidos trolls la hab�an tirado a la basura. Supongo que por all� habr� m�s aunque "
            "yo no pude encontrarlas. Tambi�n he oido que Malmabeth, una comerciante de Berat, ten�a un par de ellas.\n"
            "Me sirven los zafiros y el �mbar.\n");
    }
    // ya le ha ayudado anteriormente, pues tiene el conjuro bien aprendido.
    return W("Ereldil te mira y con una sonrrisa te dice: �La gema? Claro! la que me trajiste es perfecta! ya me queda cada vez menos para completar mi hechizo!");
}




