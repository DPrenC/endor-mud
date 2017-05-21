/* Herrero de la tienda de Nandor.
   (c) Bansee@Simauria.
   Mayo'99 : Re-Revisado. Ya no se llama Ulises y es algo mas tocho.
   13-09-00: Maler, modificao pal quest de Tamara, ninios
   19-09-01: [n] Retocada totalmente la indentación (Maler, cada día
                 lo haces peor...) y a partir de ahora se guardará un
     log de quién resuelve el quest y cuándo
   13-06-03: [n] Le cambio el nombre al archivo, y lo cambio también en
                 la herrería. El archivo ulises.c desaparece de la estructura
     de directorios por el bien de la Humanidad...
 13/01/2005: [kastwey]: modifico el chats para que solo hable
 a los que tienen el quest sin resolver
 Igual con las preguntas
 Modifico el dar_cmd y uso el notify_enter, que queda mas mejor :)
16/01/2005: [kastwey]: añado las funciones para el quest del ghoul.
*/
#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
#include <moving.h>

#define COSTE 50000
#define COSTE_STR "diez monedas de mithril"
#define COSTE_DESCUENTO 10000
#define COSTE_DESCUENTO_STR "dos monedas de mithril"
inherit NPC;
inherit "/lib/money";

string dialogo();
string preguntar_problema();
string preguntar_tamara();
void devolver_objeto(object ob, object pl);
void comprobar_objeto(object ob, object pl);



create() {
    ::create();
    SetStandard("Altur","humano",([GC_LUCHADOR: 20]),GENERO_MASCULINO);
    AddId("herrero");
    AddId("altur");
    SetAds(({"fuerte", "gordo", "herrero", "el"}));
    SetShort("El herrero Altur");
    SetWeight(100000);
    Set(P_CANT_LURE,1);
    SetCitizenship("nandor");
    AddItem(ARMANANDOR("martillo_herrero"),REFRESH_REMOVE,SF(wieldme));
    AddDefence(DT_BLUDGEON,4); //Su fuerte musculatura le protege un poco mas. (Nem dixit).
    AddQuestion(({"problema","busqueda","que buscas","alteracion","preocupacion",
        "su problema", "qué buscas","alteración"}),SF(preguntar_problema));
    AddQuestion(({"Tamara","tamara"}),SF(preguntar_tamara));
    AddQuestion(({"plata","lingote"}),"Altur te sonríe y te dice: Si tu me traes un "
    "lingote de plata, podría hacerte un cuchillo. Los habitantes del pueblo "
    "chismorrean a cerca de un ladrón que apresaron en el castillo, y que acababa "
    "de asaltar una diligencia con un cargamento de plata. Quizás tengas suerte "
    "y encuentres algo allí.\n",1);


    InitChats(5, ({ SF(dialogo) }) );
}


string dialogo()
{
  string mensaje;
  if (!environment()) return "";
  switch(random(3))
  {
    case 0: mensaje = "Altur dice: '¿Por qué seré tan desgraciado?'\n"; break;
    case 1: mensaje = "Altur dice: 'Nadie quiere ayudarme a encontrarla.'\n"; break;
    case 2: mensaje = "Altur dice: 'No puedo abandonar mi trabajo para buscarla, muchos dependen de mí.'\n"; break;
  }
  foreach(object ob:all_inventory(environment()))
  {
    if (query_once_interactive(ob) && !QUESTMASTER->QueryQuestSolved("cored_quest_tamara", ob)) tell_object(ob,mensaje);
  }
  return "";
}

public string QueryLong()
// devuelve descripciones diferentes según si ha hecho o no el quest
{
  if (QUESTMASTER->QueryQuestSolved("cored_quest_tamara",TP))
  // lo tiene hecho
  {
    return W("Un amasijo de 100 kilos de musculos llamado Altur. "
      "Se mueve de un lado a otro de la herrería con gran energía. "
      "Desde que le ayudaste, su cara muestra cláramente la felicidad y la dicha de haber recuperado a su amor perdido.\n");
  }
  else
  {
    return W("Un amasijo de 100 kilos de musculos llamado Altur. "
      "Se mueve de un lado a otro de la herrería. Debe tener algún problema, ya que "
      "parece muy triste.\n");
  }
}

string preguntar_problema()
{
  if (QUESTMASTER->QueryQuestSolved("cored_quest_tamara",TP))
  // lo tiene hecho
  {
  	tell_object(TP,W("Altur sonríe y te dice: 'Oh " + capitalize(TP->QueryName()) + "! ya no tengo ningún problema. Gracias a tu intervención he podido reunirme con mi amor, Tamara, por lo que te estaré eternamente agradecido!'.\n"));
    say(W("Altur le dice algo a " + capitalize(TP->QueryName()) + ".\n"),TP);
  }
  else
  // no tiene hecho el quest
  {
  	tell_object(TP,   W("Altur te dice: 'Mi historia es muy triste. Hace ya unos años estaba prometido "
      "con la preciosa Tamara, la luz de mi vida. Pero el resto del pueblo estaba celoso "
	    "de nuestro amor, y muchos la deseaban, intentando provocarme males, e incluso la muerte. "
	    "Por mi bien, Tamara huyó de Nandor, y no se ha vuelto a saber de ella. Ayúdame a recuperarla, "
	    "aventurero, no puedo recompensarte, pero me harías el hombre más feliz sobre la faz de Simauria.'\n"));
 	  say(W("Altur le dice algo a " + capitalize(TP->QueryName()) + ".\n"),TP);
	}
  return "";
}

string preguntar_tamara()
{
	if (QUESTMASTER->QueryQuestSolved("cored_quest_tamara",TP))
	// lo tiene hecho
	{
		tell_object (TP,W("Altur te dice: 'Tamara es la luz de mi vida, y gracias a ti he podido volver a estar con ella. De verdad, gracias de nuevo " + capitalize(TP->QueryName()) + ".\n"));
		say(W("Altur le dice algo a " + capitalize(TP->QueryName()) + ".\n"),TP);
	}
	else
	// no lo tiene hecho
	{
		tell_object(TP,"Altur te dice: 'Tamara es la luz de mi vida, espero que la encuentres con vida, es pelirroja, alta, y en todos los aspectos perfecta. He oido que se refugia con un bandido llamado Cored, si la encuentras, por favor, convencela para que vuelva conmigo, ahora nadie en el pueblo se atreve a intimidarme.'");
  	say(W("Altur le dice algo a " + capitalize(TP->QueryName()) + ".\n"),TP);
  }
  return "";
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
		say(W("Altur mira hacia todos lados para hablar con " + capitalize(pl->QueryName()) + ". Al ver que no está, suelta " + ob->QueryShort() + " en el suelo mientras murmura algo ininteligible.\n"));
		ob->move(environment());
		return;
	}
	if (member(ob->QueryIds(),"quest_carta_tamara") >= 0)
	// es la carta
	{
        // si no es el propietario de la carta...
 		 if (ob->QueryOwner() != pl->QueryRealName())
		 {
		     write(W("Altur desdobla la carta y tras leerla te mira con cara de "
		             "incomprensión mientras pregunta: ¿Para qué me das un "
		             "papel en blanco?\n"));
		     say(W("Altur le dice algo a " + capitalize(TP->QueryName()) +
		           ".\n"),TP);
		     devolver_objeto(ob,TP);
		     return;
		 }
        if (QUESTMASTER->QueryQuestSolved("cored_quest_tamara",pl))
 		// lo tiene hecho
		 {
			tell_object(pl,"Altur mira la carta y te dice: Una copia de la carta que ya me habías dado... ¿De dónde la has sacado?\n");
			say(W("Altur mira la carta que le ha dado " + capitalize(pl->QueryName()) + " y le dice algo.\n"),pl);
			tell_room(environment(),"A continuación, dobla la carta y se la guarda.\n");
			ob->remove();
			if (ob) destruct(ob);
		}
		else
		// no tiene el quest hecho, así que se le da por resuelto
		{
			tell_object(pl,"Altur coge la carta, y con una velocidad increíble la abre y comienza "
        "a leer. Al poco, levanta la vista de la carta y te sonríe al tiempo que te dice: 'Muchas gracias, has conseguido reunirme con la persona "
        "que más quiero de este mundo, no sé como puedo agradecértelo.'\n");
      say("Altur habla con " + capitalize(pl->QueryName()) + ".\n",pl);
      QUESTMASTER->InformSolution("Altur ha recuperado su felicidad "
        "gracias a "+ capitalize(pl->QueryName())+". Enhorabuena!!\n");
      QUESTMASTER->SetPlayerQuest("cored_quest_tamara", pl);
      write_file(LOGS "TAMARAQUEST", ctime(time())+" "+TP->QueryRealName()+" ["+
        pl->QueryLevel()+"]   Ha resuelto el quest de Tamara\n");
    }
  }
  else if (member(ob->QueryIds(),"lingote_quest_ghoul") >= 0 )
  // es el lingote para el cuchillo del quest del ghoul
  {
  	mixed dinpagado;
  	int dinero, ncoste;
  	object cuchillo;
    dinero = QuerySomeonesValue(TP);
    if (QUESTMASTER->QueryQuestSolved("cored_quest_tamara",TP))
  	// lo tiene hecho así que se le aplica un descuento
  	{
  		write("Altur mira maravillado el lingote que le acabas de dar y te dice: "
  		"Bien " + capitalize(TP->QueryName()) + ". por el tamaño del lingote yo diría que de aquí se podría sacar un maravilloso cuchillo de plata. "
  		"En pago al favor que te debo por haberme ayudado a recuperar a mi querida Tamara, te haré un precio especial por construirte el cuchillo. "
  		"Solo te costará " + COSTE_DESCUENTO_STR + ".\n");
  		ncoste = COSTE_DESCUENTO;
    }
    else
  	{
		  write("Altur mira maravillado el lingote que le acabas de dar y te dice: "
  		"Bien " + capitalize(TP->QueryName()) + ". por el tamaño del lingote yo diría que de aquí se podría sacar un maravilloso cuchillo de plata. "
  		"El coste de construirlo será de " + COSTE_STR + ".\n");
  		ncoste = COSTE;
  	}
    say("Altur le dice algo a " + capitalize(TP->QueryName()) + ".\n",TP);
    if (dinero < ncoste)
  	// no tiene suficiente pasta
  	{
  		write("Cuando vas a pagarle, te das cuenta de que no llevas suficiente dinero encima.\n");
  		devolver_objeto(ob,TP);
  		return ;
  	}
  	dinpagado = PayValue2(TP,ncoste);
  	if (intp(dinpagado)) write(W("Le pagas a Altur " + dinpagado + ".\n"));
    else write("Le pagas a Altur " +dinpagado[0]+(dinpagado[1] ? " y recibes "+dinpagado[1] : "")+".\n");
    say("Al instante, Altur comienza a trabajar. "
    "Con ayuda de las herramientas de su herrería, en poco rato, tiene entre sus manos un fabuloso cuchillo, que ves como en su pulida superficie refleja la luz del fuego de la fragua.\n");
    cuchillo = clone_object(QUEST + "ghoul/cuchillo_ghoul");
    if (cuchillo->move(TP) != ME_OK)
    // no se ha podido mover al inventario del jugador
    {
	    write("Altur te da el cuchillo. Sin poder evitarlo, se te cae al suelo.\n");
	    say("Altur le da el cuchillo a " + capitalize(TP->QueryName()) + ", pero sin poder "
	        "evitarlo, se le cae al suelo.\n",TP);
	    cuchillo->move(environment());
    }
    else
    {
    	write("Altur te da el cuchillo.\n");
    	say("Altur le da el cuchillo a " + capitalize(TP->QueryName()) + ".\n",TP);
    }
    ob->remove();
    if (ob) destruct(ob);
  }
  else
  // no es la carta
  {
   	tell_object(pl,"Altur observa " + ob->QueryShort() + " y te dice: ¿Un regalo? Te lo "
       	"agradezco " + capitalize(pl->QueryName()) + " pero no puedo aceptarlo.\n");
   	say("Altur le dice algo a " + capitalize(pl->QueryName()) + ".\n",pl);
   	devolver_objeto(ob,pl);
  }
  return;
}


public int QueryHerreroTamaraQuest() { return 1; }
