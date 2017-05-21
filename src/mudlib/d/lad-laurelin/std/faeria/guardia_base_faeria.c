/***
fichero: guardia_base.c
autor: kastwey
Descripción: guardia base para el cuerpo del poblado de faeria
Creación: 02/12/2004
26/12/2004 Modifico algunas cosas para adaptar lo de los e
migos
Quiero que quede lo más realista posible, así que me comeré la cabeza hasta que
lo termine y funcione :)
***/
#include "path.h"
#define TURNOS_ESPERA 2
#include <moving.h>

inherit STD_FAERIA("pnj_base_faeria");

void informar();
void volver();
void StartInform();
string ObtenerDireccion(string ruta);
public mapping AddInformEnemy(object enemigo);
public mapping AddInformNonGrata(object nongrata);
public mapping SetInformEnemies(mapping enemies);
public mapping SetInformNonGratas(mapping nongratas);
public mapping QueryInformEnemies();
public mapping QueryInformNonGratas();
public int SetInformar(int valor);
public int QueryInformar();
public int ResetInform();
public void BorraInformadores();
public int SetInformando(int valor);
public int QueryInformando();
int QueryPedirRefuerzos();
public int soy_tu_amigo(object victima);
int SetPedirRefuerzos();
public int QueryIsGuardia();
int atacar(object ob);
int pPedirRefuerzos = 1;
static int paso;
int t_espera;
string *vuelta = ({});
int pInformando;
static int pInformar = 1;
int pVolviendo;
mapping pInformEnemies;
mapping pInformNonGratas;
object pRefuerzo;

create()
{
	  ::create();
 	SetAttackOwnRace(1000);
  	SetAggressive(2);
 	  SetFriendFunction(SF(soy_tu_amigo));
  	SetWhimpy(-1);
  	AddId("guardia");
  	AddId("guardia_faeria");
    AddWalkZones(HABITACION + "faeria/");
}

public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras)
{
    object enemigo;
    enemigo = (TP->QueryIsPet()?TP->QueryOwner():TP);
    if (TP->QueryGuildLevel() < 10)
    {
        write (W(TO->QueryName() + " te aparta a un lado y te dice:\n"
            "¡Pero bueno renacuajo! ¿Te crees que voy a perder el tiempo luchando con un micaco como tú?\n"
            "Mejor vete al parque de novatos con Sigreb.\n"));
        say(W(TO->QueryName() + " empuja a " + capitalize(TP->QueryName()) + " y le dice:\n"
            "¡Pero bueno renacuajo! ¿Te crees que voy a perder el tiempo luchando con un micaco como tú?\n"), TP);
        TP->RemoveEnemy(TO);
        TO->RemoveEnemy(TP);
        return 0;
    }
    if (!enemigo) return ::Defend(dam, dam_type, flags, &xtras);
    if (QueryInformNonGratas())
    {
        if (!QueryInformNonGratas()[enemigo->QueryRealName()]) AddInformNonGrata(enemigo);
    }
    else AddInformNonGrata(enemigo);
    return ::Defend(dam, dam_type, flags, &xtras);
}

int SetPedirRefuerzos(int refuerzos)
{
    return pPedirRefuerzos = refuerzos;
}

int QueryPedirRefuerzos() { return pPedirRefuerzos; }

int atacar(object ob)
{
    Kill(ob);
    return 1;
}

public int QueryIsGuardia() { return 1; }
public int QueryIsGuardiaFaeria() { return 1; }


void heart_beat()
{
	  ::heart_beat();
	  if (Fighting())
	  {
	  	  t_espera = 0;
	  	  return;
	  }
	  if (!Fighting() && !pInformando && pInformar && (pInformEnemies || pInformNonGratas))
	  // ta preparado para tirar a la oficina
	  // siempre que haya esperado los turnos establecidos.
	  {
	  	  if (t_espera == TURNOS_ESPERA)
	  	  {
     	      StartInform();
	  	      return;
 	      }
	  	  t_espera++;
	  	  return;
	  }
    if (pInformando) informar();
    else if (pVolviendo) volver();
}



void informar()
{
	  object env;
	  if (!env = environment()) return;
	  if (Fighting()) return;
	  if (!env->QueryOficina())
	  {
	  	  tell_room(env,W(capitalize(QueryName()) + " anota algo en el tablón.\n"));
	  	  if (QueryInformEnemies()) TABLON_ENEMIGOS->AddEnemies(QueryInformEnemies());
	  	  if (QueryInformNonGratas())  TABLON_ENEMIGOS->AddNonGratas(QueryInformNonGratas());
	  	  ResetInform();
	  	  if (sizeof(vuelta))
	  	  {
  	  	  	BorraInformadores();
  	  	  	paso = sizeof(vuelta)-1;
     	  }
	      pVolviendo = 1;
	  }
	  else
	  {
  	    vuelta+=({to_string(env)});
	      if (move(env->QueryOficina(),M_GO,ObtenerDireccion(env->QueryOficina())) != ME_OK) return;
    }
}

void volver()
{
	  if (Fighting()) return;
    if (!sizeof(vuelta))
    {
    	  ResetInform();
    	  return;
    }
    move(vuelta[paso],M_GO,ObtenerDireccion(vuelta[paso]));
	  paso--;
	  if (paso < 0)
	  {
	  	  pVolviendo = 0;
	  	  vuelta=({});
    }
}


string ObtenerDireccion(string ruta)
{
	  if (!ruta) return 0;
	  if (member(m_values(environment()->QueryExits(),0),ruta) < 0) return 0;
	  return m_indices(environment()->QueryExits())[member(m_values(environment()->QueryExits(),0),ruta)];
}

public int SetInformar(int valor) { return pInformar = valor; }

public int QueryInformar() { return pInformar; }


public mapping AddInformEnemy(object enemigo)
{
		if (enemigo && !pInformEnemies) pInformEnemies = ([]);
		pInformEnemies[enemigo->QueryRealName()]++;
		return pInformEnemies;
}

public mapping QueryInformEnemies() { return pInformEnemies; }

public mapping RemoveInformEnemy(object enemigo)
{
	  if (!pInformEnemies[enemigo->QueryRealName()]) return pInformEnemies;
	  pInformEnemies = m_delete(pInformEnemies,enemigo->QueryRealName());
	  return pInformEnemies;
}


public mapping AddInformNonGrata(object nongrata)
{
		if (nongrata && !pInformNonGratas) pInformNonGratas = ([]);
		pInformNonGratas[nongrata->QueryRealName()]++;
		return pInformNonGratas;
}

public mapping QueryInformNonGratas() { return pInformNonGratas; }

public mapping RemoveInformNonGrata(object nongrata)
{
	  if (!pInformNonGratas[nongrata->QueryRealName()]) return pInformNonGratas;
	  pInformNonGratas = m_delete(pInformNonGratas,nongrata->QueryRealName());
	  return pInformNonGratas;
}

public mapping SetInformEnemies(mapping enemigos) { return pInformEnemies = enemigos; }

public mapping SetInformNonGratas(mapping nongratas) { return pInformNonGratas = nongratas; }

public int ResetInform()
{
		pInformEnemies = 0;
	  pInformNonGratas = 0;
	  pInformar = 1;
	  pInformando = 0;
	  t_espera = 0;
	  return 1;
}

void StartInform()
{
		if (pInformar)
	  {
  	  	if (Fighting()) return;
  	  	pInformando = 1;
	      if (environment())
        {
		        filter(all_inventory(environment()),
                (: call_other($1, "QueryIsGuardia") && $1 != TO?$1->SetInactivo(1):0 :));
        }
    }
}

public varargs void Die(mixed silent)
{
	  if (QueryInformando())
	  {
	  	  // está de camino para informar.
        if (!sizeof(vuelta)) return ::Die(silent);
        filter(all_inventory(to_object(vuelta[0])),
            (: call_other($1, "QueryIsGuardia")?$1->SetInactivo(0):0 :));
    	  /*
    	  filter(all_inventory(to_object(vuelta[0])),
            (: call_other($1, "QueryIsGuardia")?$1->StartInform():0 :));
        */
        ResetInform();
        pInformar = 0;

    }
    return ::Die(silent);
}






public int SetInformando(int valor) { return pInformando = valor; }

public int QueryInformando() { return pInformando; }


public int soy_tu_amigo(object victima)
{
	if (!victima || !CanSeeObject(victima)) return 1;
	if (!victima->QueryIsPlayer()) return 1;
    if (TABLON_ENEMIGOS->QueryEnemies()[victima->QueryRealName()])
    {
        tell_object(victima, W(capitalize(TO->QueryName()) + " te dice: Eh "
            + capitalize(victima->QueryName()) + "! ¿Realmente crees que después "
            "de asesinar a uno de nuestros habitantes puedes pasar por aquí "
            "y quedar impune?\n") );
        say(W(capitalize(QueryName()) + " le grita a "
            + capitalize(victima->QueryName()) + ": Eh tu! ¿¿Realmente crees que "
            "después de asesinar a uno de nuestros habitantes vas a quedar "
            "impune?\n"), victima);
        return 0;
    }
    else if (member(RAZASENEMIGAS, victima->QueryRace()) > -1)
    {
        tell_object(victima, W(capitalize(TO->QueryName()) + " te grita: Eh maldito " + victima->QueryRace() + "!\n"
            "¿Te crees realmente que una criatura como tú va a ser bienvenida en nuestros territorios?\n"));
        say(W(capitalize(QueryName()) + " le grita a " + capitalize(victima->QueryName()) + ": Eh! " + victima->QueryRace() + "!\n"
            "¿Te crees realmente que una criatura como tú va a ser bienvenida en nuestros territorios?\n"), victima);
        return 0;
    }
    else if (TABLON_ENEMIGOS->QueryNonGratas()[victima->QueryRealName()])
    {
        tell_object(victima, W(capitalize(QueryName()) + " te dice: Sabes que aquí ya no eres bienvenido.\n"
            "Márchate!\n"));
        say(W(capitalize(QueryName()) + " le dice a " + capitalize(victima->QueryName()) + ": Eh! Sabes que ya no eres bienvenid" + AO + " en nuestros territorios!\n"
            "Márchate!\n"), victima);
            return 1;
    }
    return 1;
}

public void BorraInformadores()
{
	  if (sizeof(vuelta))
 	  {
      	filter(all_inventory(to_object(vuelta[0])),
            (: call_other($1, "QueryIsGuardia")?$1->ResetInform():0 :));
    }
}

public int SetInactivo(int valor)
{
    if (valor)
    {
        SetInformar(0);
        t_espera = 0;
        return 1;
    }
    SetInformar(1);
    return 0;
}
