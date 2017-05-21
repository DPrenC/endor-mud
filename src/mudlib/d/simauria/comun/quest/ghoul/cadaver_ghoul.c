/**
Fichero: cadaver_ghoul.c
Autor: kastwey@simauria
Creaci�n: 20/07/2004
Comentarios. Borro todas las funciones del corpse y lo heredo :)
A�ado las nuevas acciones y modifico el DoDecay
para modificar las descripciones si se corta la cabeza.
15/01/2005: [kastwey@simauria]: reviso mi c�digo... a saber las cosas que habr�a puesto
Definitivamente, retoco mucho c�digo
**/

#include "path.h"
#include <moving.h>
#include <combat.h>

#define ARMASCORTANTES ({CS_ESGRIMA,CS_HACHA,CS_ESPADA,CS_CUCHILLO})

inherit "/std/corpse";

static string pKiller;
static int sin_cabeza;
public int SetKiller(string str);
public string QueryKiller();
int filtrar_armas_cortantes(object arma);


init()
{
	add_action("cmd_cortar","cortar");
  ::init();
}

create()
{
	::create();
	sin_cabeza = 0;
}

public void DoDecay (int justschedule) {
  ::DoDecay(justschedule);
  if (sin_cabeza == 1)
  {
	  SetShort(QueryShort() + " con la cabeza cercenada");
		SetLong(QueryLong() + "Al fijarte mejor, te das cuenta de que alguien le ha cortado la cabeza.\n");
  }
}

int cmd_cortar(string str)
// funci�n para cortarle la cabeza al ghoul
{
  object cuchillo, *armas, arma;
  string genero_arma;
  if (!str)
  {
    write ("�Cortar qu� a quien?\n");
    return 1;
  }
  str = lower_case(str);
  if (str == "cabeza a ghoul" || str == "cabeza al ghoul" || str == "la cabeza al ghoul" || str == "la cabeza del ghoul" || str == "cabeza de ghoul")
  {
	  if (present("qghoul_cuchillo",TP))
	  // tiene el cuchillo
	  {
	  	cuchillo = present("qghoul_cuchillo",TP);
	  	if (cuchillo->QueryEquipped())
      {
  	    if (sin_cabeza)
        {
          write ("Este cad�ver ya no tiene cabeza.\n");
          return 1;
        }
	      write (W("Con ayuda del cuchillo cortas la cabeza del ghoul, que cae rodando al suelo.\n"
        "Al instante, el cuchillo comienza a brillar con una luz intensa, y desaparece ante tus ojos.\n"));
        say(W(capitalize(TP->QueryName()) + " le corta la cabeza al ghoul, que cae rodando al suelo.\n"),TP);
        object cabeza;
        cabeza = clone_object(QUEST + "ghoul/cabeza");
        if (cabeza->move(TP) != ME_OK)
        // no se ha podido mover al inventario del player
        {
        	write("Te agachas a coger la cabeza pero te es imposible.\n");
        	say(W(capitalize(TP->QueryName()) + " se agacha a por la cabeza pero le es imposible cogerla.\n"),TP);
        	cabeza->move(environment());
        }
        else
        {
        	write ("Te agachas y coges la cabeza.\n");
        	say (W(capitalize(TP->QueryName()) + " se agacha y coge la cabeza.\n"),TP);
        }
        cabeza->SetOwner(TP->QueryRealName());
        cabeza->SetGhoulKiller(TO->QueryKiller());
        cuchillo->remove();
        if (cuchillo) destruct(cuchillo);
        sin_cabeza = 1;
        SetShort(QueryShort() + " con la cabeza cercenada");
	      SetLong(QueryLong() + "Al fijarte detenidamente, te das cuenta de que alguien le ha cortado la cabeza.\n");
        return 1;
      }
      else
      {
	      write ("Debes empu�ar el cuchillo para poder cortarle la cabeza al ghoul.\n");
        return 1;
      }
    }
    // como no tiene el cuchillo, pos vemos si tiene otras armas cortantes
    // y si las tiene me las cargo un poquito
    // es que este ghoul es mu tiquismiquis y hay que rebanarle la cabeza con un cuchillo pijo
    if (!sizeof(TP->QueryWeapons()))
    // no tiene ning�n arma empu�ada
    {
    	write("No tienes ning�n arma empu�ada para cortarle la cabeza al ghoul.\n");
    	return 1;
    }
    if (!sizeof(armas = filter(TP->QueryWeapons(),SF(filtrar_armas_cortantes))))
    {
      write("No tienes ning�n arma cortante empu�ada con la que cortarle la cabeza al ghoul.\n");
      return 1;
    }
    arma = armas[random(sizeof(armas))];
  	genero_arma = (arma->QueryThingArticle() == "la" ? "a" : "o");
    write (W("Intentas cortarle la cabeza al ghoul con ayuda de " + arma->QueryShort() + ".\n"
    "Tras varios intentos, te das cuenta de que con este arma te va a ser imposible cortarla. Quiz�s necesites alg�n arma especial...\n"
    "Al mirar " + arma->QueryShort() + ", te das cuenta de que lo �nico que has conseguido ha sido da�arl" + genero_arma + ".\n"));
    say (W(TP->QueryName() + " intenta cortarle la cabeza al ghoul con ayuda de " + arma->QueryShort() + ".\n"
    "Tras varios intentos, se da cuenta de que con esta arma le va a ser imposible cortarla.\n"
    "Al mirar " + arma->QueryShort() + ", observas que lo �nico que ha conseguido ha sido da�arl" + genero_arma + ".\n"),TP);
    if (arma->QueryQuality() <10) arma->SetQuality(0);
    else arma->SetQuality(arma->QueryQuality() - 10);
    return 1;
  }
}

public int SetKiller(string killer)
{
	pKiller = killer;
	return 1;
}

public string QueryKiller()
{
	return pKiller;
}

int filtrar_armas_cortantes(object arma)
{
	return member(ARMASCORTANTES,arma->QueryWeaponType()) >= 0;
}
