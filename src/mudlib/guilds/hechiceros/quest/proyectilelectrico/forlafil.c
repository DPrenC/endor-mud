/*
DESCRIPCION : el hechicero forlafil
FICHERO     : /guilds/quest/proyectilelectrico/forlafil.c
MODIFICACION: 22-10-00 [Maler] Creacion
19/01/2005: [kastwey]: adecento el sangrado y cambio algunas funciones, weno, muchas :P

--------------------------------------------------------------------------------
*/

#include "path.h"
#include <guild.h>
#include <moving.h>

#define QPROY(x) "/guilds/hechiceros/quest/proyectilelectrico/"+x

inherit NPC;

string dialogo();
void comprueba_objeto(object ob, object player);
void devolver_objeto(object ob, object player);
string preguntar_mapa();

//QueryLong, devuelve un long si le has ayudado y otro si no lo has hecho

public mixed QueryLong()
{
    mapping Spells;
    Spells=TP->QuerySpells();
    //Compruebo gremio.
    if(TP->QueryGuild()!=GC_HECHICEROS) return ::QueryLong();
    //inicializo spells en el caso de q no hubiera (si no peta), y defino j.
    if (!Spells) Spells=([]);
		//compruebo si le has ayudado o no
    if(!Spells["proyectil electrico"] || Spells["proyectil electrico",1]<70)
		{
        return ::QueryLong() + " Cuando te ve, se acerca.\n";
		}
		else return ::QueryLong();
}

void notify_enter(mixed from, int method, mixed extra)
// cuando se le da algo al pnj, se ejecuta esta función
{
	  if (from->QueryIsPlayer() && method == M_GIVE) call_out("comprobar_objeto",1,PO,from);
	  return;
}



void create()
{
    ::create();
   SetStandard("Forlafil","elfo",40,GENDER_MALE);
    SetShort("Forlafil, el explorador");
    SetLong("Ves a Forlafil, el explorador. Lleva unas gastadas ropas de viaje, "+
        "y no lleva ningún distintivo, ni parece llevar armas.\n");
    SetIds(({"forlafil","Forlafil","explorador"}));
    AddQuestion(({"mapa","Mapa"}),SF(preguntar_mapa));
    InitChats(20, ({ SF(dialogo) }) );
}


void comprobar_objeto(object ob, object player)
{
    int i;
    mapping spells;
    object mapa;
    if (!environment()) return;
    // nunca se sabe...
    if (!player || !present(player,environment()))
    // el player se ha largao
    {
        tell_room(environment(),W("Forlafil mira hacia todos lados buscando a quien le ha dado " + ob->QueryShort() + ". Extrañado, pone cara de disgusto y suelta " + ob->QueryShort() + ".\n"));
        ob->move(environment());
        return;
    }
    if (player->QueryGuild() != GC_HECHICERO || member(ob->QueryIds(),"sello_proyectil_arandil") < 0)
    {
        tell_object(player,W("El explorador te dice: Oh " + capitalize(player->QueryName()) + ". Un regalo? Lo siento, pero no puedo aceptarlo.\n"));
        say(W("El explorador le dice a " + capitalize(player->QueryName()) + ": Oh. Un regalo? Lo siento, pero no puedo aceptarlo.\n"),player);
        devolver_objeto(ob,player);
        return;
    }
    spells = player->QuerySpells() || ([]);
    if (present("spell_proyectil_arandil",player) || spells["proyectil electrico"] && spells["proyectil electrico",1]>= 70)
    // eso es que ya se lo sabe, así que segur oque le has ayudado :)
    {
    	  tell_object(player,W("El explorador mira el sello y te dice: " + capitalize(player->QueryName()) + ", ya se que vienes de parte de Arandil, pero yo ya te di el mapa en su momento.\n"));
    	  // say(W("El explorador le dice algo a " + capitalize(player->QueryName()) + ".\n"),player);
    	  devolver_objeto(ob,player);
    	  return;
    }
    tell_object(player,W("Forlafil te dice: Saludos, enviado de Arandil. He encontrado el mapa. Forlafil saca una caja de un bolsillo escondido, la abre "
	      "y te da el mapa.\n\n"));
    mapa = clone_object(QPROY("mapa"));
    if (mapa->move(TP) != ME_OK)
    // el movimiento ha fallado
    {
        tell_object(player,W("Sin poder evitarlo, el mapa se te cae al suelo.\n"));
        say(W("Sin poder evitarlo, a " + capitalize(player->QueryName()) + " se le cae el mapa al suelo.\n"),player);
        mapa->move(environment());
    }
    return;
}

string dialogo()
{
	  string mensaje;
	  if (!environment()) return "";
	  switch(random(2))
	  {
	  	case 0: mensaje = "Forlafil te pregunta: Eres tú el enviado de Arandil?.\n"; break;
      case 1: mensaje = "Forlafil dice: Tener un objeto tan importante me está volviendo paranoico.\n"; break;
    }
    filter(all_inventory(environment()),(:
    	  $1->QueryIsPlayer() && $1->QueryGuild() == GC_HECHICERO &&
    	  !present("spell_proyectil_arandil",$1) &&
    	  ((!$1->QuerySpells() || ([]))["proyectil electrico"] || ($1->QuerySpells() || ([]))["proyectil electrico",1] < 70)
    	  ?tell_object($1,W($2)):0
    :),mensaje);
    return "";
}

string preguntar_mapa()
{
  	if (!TP) return "";
	  if (TP->QueryGuild() != GC_HECHICERO)
	  // no es hechicero
	  {
	  	  return W("Forlafil te mira y te dice: ¿Mapa? ¿Qué mapa?\n");
	  }
	  else if (!(TP->QuerySpells() || ([]))["proyectil electrico"] || (TP->QuerySpells() || ([]))["proyectil electrico",1] < 70)
	  {
	  	  return W("Forlafil dice: Si, encontré el mapa que Arandil me pidió que buscara, por supuesto esta bien guardado, y sólo se lo daré a su enviado, "
        "el portador de su sello, si realmente eres su enviado, búscale, y pídele el sello.\n");
    }
    else
    {
    	  return W("Forlafil te dice: Pero " + capitalize(TP->QueryName()) + " yo ya te di el mapa en su momento. ¿Qué más quieres que te diga?\n");
    }
    return "";
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
public int QueryForlafil() { return 1; }
