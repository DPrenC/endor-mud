/****************************************************************************
Fichero: avenida_01.c
Autor: Kastwey
		Tagoras [t]
Creaci�n: 24/07/2005
Descripci�n: Inicio de la avenida real de Annufam
[t] 19/02/2009: Comentadas las secciones que hacen referencia al servidor del clima. Por ello el port�n no funciona autom�ticamente.
[t] 25/02/2009: Cambiado SERVER_ANNUFAM por NIGHTDAY para saber el estado del dia.
[t] 15/03/2009: El port�n funciona.
[t] 20/03/2009: A�adido sonido de abrir y cerrar al port�n.
[t] 02/05/2010: Hab�a un momento del d�a que la rueda no permit�a bajar el port�n, ahora parece que funciona.
****************************************************************************/

#include "./path.h"
#include <nightday.h>
#include <moving.h>
#include <sounds.h>

#define P_ABRIR       1
#define P_CERRAR      0
#define POR_GUARDIA   1
#define GARITA        HAB_CIUDAD_ANNUFAM("garita")
#define ENTRADA       HAB_CIUDAD_ANNUFAM("entrada.c")
#define DIR_FOSO      (HAB_FOSO_ANNUFAM("foso_01.c"))

inherit SCHEDULER_ROOM;
inherit BASE_CIUDAD_ANNUFAM;

int pPortonAbierto; // el port�n
int pDesdeGarita=-1;		// Se abre o cierra desde la garita
int pCuandoGarita=-1;		// Cuando se abre o cierra desde la garita
int salir_ciudad();
int entrar_garita();
int entrar_torre();

public object QueryGuardian()
// devuelve el objeto guardia
{
    object *inv = filter(all_inventory(),(:living($1) && $1->id("guardian_porton"):));
    if (sizeof(inv)) return inv[0];
    return 0;
}

public varargs int SetPortonAbierto(int i, int silent)
// abre o cierra el port�n.
// si se le pasa 1 en SILENT, lo har� en silencio
{
    object hab_player;
    // si hay alg�n call_out al actualizar estado del port�n
    // lo quitamos
    if (find_call_out("ActualizaEstadoPorton"))
    {
        remove_call_out("ActualizaEstadoPorton");
    }
	// Quitamos cualquier acci�n manual del jugador
	pDesdeGarita=-1;


	//if (find_object("tagoras")) dtell("tagoras", "DayState:"+QueryDayState()+" Cerrado:"+member(HORAS_PORTON_CERRADO, QueryDayState())+" Accion:"+i+" DesdeGarita:"+pDesdeGarita+" CuandoGarita:"+pCuandoGarita+" PortonAbierto:"+pPortonAbierto+"\n");
    if (i == pPortonAbierto) return i;
    if (pPortonAbierto && !i && !silent)
    // est� abierto y se va a cerrar
    {
        string msg = "Escuchas un estr�pito de cadenas. Miras el port�n, y "
                     "ves como comienza a elevarse lentamente.\n"
                     "Tras unos instantes, el port�n termina de "
                     "cerrarse.\n";
        tell_room(TO,msg);
        tell_room(ENTRADA,msg);
		play_sound(TO,SND_SUCESOS("cerrar_porton"));
		//play_sound(ENTRADA,SND_SUCESOS("cerrar_porton"));
    }
    if (!pPortonAbierto && i && !silent)
    // Se va a abrir
    {
        string msg = "Escuchas un estr�pito de cadenas. Miras el port�n, "
                     "y observas como desciende r�pidamente.\n"
                     "Al poco, el port�n termina de bajar y cesa el "
                     "ruido.\n";
        tell_room(TO,msg);
        tell_room(ENTRADA,msg);
		play_sound(TO,SND_SUCESOS("abrir_porton"));
		//play_sound(ENTRADA,SND_SUCESOS("abrir_porton"));
    }
    if (object_name((hab_player = environment(TP))) != GARITA)
    // la rueda no se mueve desde la garita
    {
        tell_room(GARITA,"Un soldado llega.\n"
                         "Con gran destreza, hace girar r�pidamente la "
                         "gran rueda, hasta que el port�n queda "
                         "totalmente " + (i ? "bajado" : "alzado") + ". "
                         "A continuaci�n, sale de la garita sin tan "
                         "siquiera haberte visto.\n");
    }
    // si el que lo ha movido es un player y est� en la garita, y adem�s,
    // hay aqu� un guardia...
    if (query_once_interactive(TP)
        && object_name(hab_player) == GARITA
        && QueryGuardian())
    {
        tell_room(TO,"El guardi�n mira boquiabierto el port�n.\n"
                     "R�pidamente se dirige hacia la garita.\n");
        // Nos traemos al player y a todos los que est�n en la garita
        // por los pelos
        object *inv;
        inv = filter(all_inventory(hab_player),(:query_once_interactive($1) && $1 != TP:));
        tell_object(TP,"El guardi�n del port�n llega desde la entrada "
                       "de la ciudad.\n"
                       "Te mira, y luego mira la barra que a�n "
                       "sujetas.\n"
                       "El enano te agarra de los pelos con increible "
                       "fuerza mientras te grita:\n"
                       "'�Pero qu� demonios te crees que haces aqu�?\n"
                       "�Piensas que el port�n es cosa de risa?!!\n"
                       "�La pr�xima vez utilizar� mi hacha contigo, "
                       "maldit" + AO + " gamberr" + AO + "!!!'\n"
                       "De un tir�n, te arrastra hasta la entrada de "
                       "la ciudad.\n");
        tell_room(hab_player,"Llega el guardia del port�n, y clava en " +
                             CAP(TNAME) + " una mirada capaz de atravesar "
                             "una roca mientras le amonesta a gritos por "
                             "haber movido el port�n.\n"
                             "Sin darle tiempo a reaccionar," + LALO + " "
                             "coge por los pelos y " + LALO + " arrastra "
                             "hacia la salida.\n"),({TP});
        tell_room(TO,CAP(TNAME) + " llega arrastrad " + AO + " por el guardia.\n");
        pPortonAbierto = i;
        TP->move(TO,M_SILENT);

        tell_room(hab_player,"El guardia vuelve a asomarse y grita:\n"
                             "'�Eh " + (sizeof(inv)>1?"vosotros":"t�") +
                             "!!! �Largo de aqu� ahora mismo!\n");
        filter(inv,(:tell_object($1,"Sin atreverte a rechistar, sales de la garita.\n");
                     $1->move(TO,M_GO,"oeste");:));
        tell_room(TO,"El guardi�n mira el port�n y suelta una maldici�n:\n"
                     "�Por todos los demonios! ahora tengo que dejar el "
                     "maldito port�n como estaba!\n"
                     "Tras decir esto, entra en la garita, " +
                     (i?"sube" : "baja") + " el port�n y "
                     "vuelve a salir.\n");
        return pPortonAbierto = !i;
    }
	// El player lo mueve desde la garita
	if (query_once_interactive(TP) && (object_name(hab_player) == GARITA))
	{
		// A estas horas deber�a estar cerrado pero el jugador lo abre
		if ((-1 != member(HORAS_PORTON_CERRADO, QueryDayState())) && i)
		{
			pDesdeGarita = i;
			pCuandoGarita = QueryDayState();
		}
		// A estas horas deber�a estar abierto pero el jugador lo cierra
		if ((-1 == member(HORAS_PORTON_CERRADO, QueryDayState())) && !i)
		{
			pDesdeGarita = i;
			pCuandoGarita = QueryDayState();
		}
		//if (find_object("tagoras")) dtell("tagoras", "DayState:"+QueryDayState()+" Cerrado:"+member(HORAS_PORTON_CERRADO, QueryDayState())+" Accion:"+i+" DesdeGarita:"+pDesdeGarita+" CuandoGarita:"+pCuandoGarita+"\n");
	}
    load_object(DIR_FOSO);
    DIR_FOSO->CambioPorton(i);
    return pPortonAbierto = i;
}

public varargs void ActualizaEstadoPorton(int por_guardia)
{
    int state, accion = -1;
    // actualizamos el estado
    // por si ya es hora de cambiarlo
/**/
    //if (!pPortonAbierto && (   state = SERVER_ANNUFAM->QueryState()) != ND_NIGHT
    if (!pPortonAbierto && (   state = NIGHTDAY->QueryState()) != ND_NIGHT
                            && state != ND_PREDAWN)
    // el port�n se abre
    {
        accion = P_ABRIR;
    }
    else if (   pPortonAbierto
             //&& member(HORAS_PORTON_CERRADO, SERVER_ANNUFAM->QueryState()) >= 0)
             && member(HORAS_PORTON_CERRADO, NIGHTDAY->QueryState()) >= 0)
     // se cierra que es denoche
    {
        accion = P_CERRAR;
    }
/**/
    // si no hay que hacer cambios, salimos.
    if (accion == -1) return;
    if (por_guardia)
    // si esta funci�n la llama el guardi�n del port�n, es �l
    // quien lo cierra
    {
        tell_room(TO,"El guardi�n mira extra�ado el port�n y sacude la "
                     "cabeza mientras murmura:\n"
                     "'Hmmmm. �Qu� demonios hace el port�n " +
                     (pPortonAbierto ? "abierto" : "cerrado") + " a estas "
                     "horas?'\n\n"
                     "Contrariado, entra en la garita.\n");
        SetPortonAbierto(accion);
        tell_room(TO,"El guardia sale de la garita mientras dice: "
                     "Si no fuera por m�...\n");
        return;
    }
	SetPortonAbierto(accion, 1);
    pPortonAbierto = accion;
}

public int QueryPortonAbierto() /*{ return pPortonAbierto; }*/
{
	if (QueryDayState() != pCuandoGarita)
		pDesdeGarita = -1;
	//if (find_object("tagoras")) dtell("tagoras", "Estoy en QueryPortonAbierto Garita:"+pDesdeGarita+"\n");
	// A estas horas deber�a estar cerrado
	if ((-1 != member(HORAS_PORTON_CERRADO, QueryDayState())) && (pDesdeGarita==1))
	{
		return pPortonAbierto = 1;
	}
	// A estas horas deber�a estar abierto
	if ((-1 == member(HORAS_PORTON_CERRADO, QueryDayState())) && (pDesdeGarita==0))
	{
		//if (find_object("tagoras")) dtell("tagoras", "Day:"+QueryDayState()+" CuandoGarita:"+pCuandoGarita+" Garita:"+pDesdeGarita+":"+QueryRoomClosedMsg()+"\n");
		//tell_object(TP, "Day:"+QueryDayState()+"Garita:"+pDesdeGarita+":"+QueryRoomClosedMsg());
		return pPortonAbierto = 0;
	}
	// En general
	if (-1 == member(HORAS_PORTON_CERRADO, QueryDayState()))
	{
		return pPortonAbierto = 1;
	}
	else
	{
		//if (find_object("tagoras")) dtell("tagoras", "Day:"+QueryDayState()+" CuandoGarita:"+pCuandoGarita+" Garita:"+pDesdeGarita+":"+QueryRoomClosedMsg()+"\n");
		//tell_object(TP, "Day:"+QueryDayState()+"Garita:"+pDesdeGarita+":"+QueryRoomClosedMsg());
		return pPortonAbierto = 0;
	}
}

public void create()
{
    "*"::create();
    // colocamos el port�n como debe de estar
    ActualizaEstadoPorton();

    SetIntShort("la avenida real de Annufam");
    SetIntLong((:"Caminas por el principio de la avenida de la ciudad. Si "
                 "comparas estas construcciones con las de la capital "
                 "Kha-annu, te das cuenta de que aqu� no se viene a "
                 "descansar. Es todo sobriedad. Un camino de tierra, pero a "
                 "la vez bien cuidado sigue de norte a sur. Hacia el sur, " +
                 (!QueryPortonAbierto() ?
                 "ves alzarse imponente el port�n de la ciudad" :
                 "ves el port�n de la ciudad, que al estar bajado, sirve de "
                 "puente entre esta avenida y la entrada") +
                 ". Al este, puedes ver una peque�a garita, que supones servir� "
                 "para controlar la apertura y cierre del puente levadizo, "
                 "y al oeste la entrada a una torre.\n"
                 "Un par de antorchas iluminan esta parte de la avenida "
                 "cuando es necesario.\n":));
    AddDetail(({"muralla","murallas","muro"}),
              "Es una muralla de piedra, de casi diez metros de altura. "
                "Preservan a la ciudad de cualquier intento de intrusi�n.\n");

    AddDetail(({"porton","port�n","puerta","puente","puente levadizo"}),
              (:"Es una gran puerta de hierro sujeta por cuatro gruesas "
                "cadenas que permiten subirla o bajarla con relativa "
                "facilidad. Supones que el control est� en la garita que "
                "puedes ver al este.\n"
                "Actualmente el port�n est� " +
                (QueryPortonAbierto() ? " abierto, sirviendo as� de puente para "
                                  "atravesar el foso que separa la entrada "
                                  "de la ciudad en s�.\n" :
                                  "cerrado, impidiendo as� la entrada a la ciudad.\n"):));

    AddDetail("torre",
              "Es una torre que llega hasta lo m�s alto de las murallas. "
              "Observas su entrada al oeste.\n");

    AddDetail("garita","Se trata de una edificaci�n construida al lado del "
                       "gran puente levadizo, y es donde el guardia de "
                       "turno ha de levantar o descender el mismo seg�n la hora o las circunstancias.\n");

    // notificar� a esta room cuando se cambie de etapa en el d�a
	SetCloseTime(HORAS_PORTON_CERRADO);
    SetLastDest(HAB_AVENIDA_ANNUFAM("avenida_01"));
    SetNotifyExits(({"sur", "norte"}));
    SetInformCloseMsg("El guardi�n grita:\nA ver todo el mundo, entrad o salid de la ciudad que vamos a izar el port�n\n");
    SetThrowOutMsg("Escuchas un estr�pito de cadenas. El guardi�n grita:\nTodo el mundo a la ciudad, la noche puede resultar muy peligrosa ah� fuera.\n");
    SetNotifyOpenMsg(({"Escuchas un estr�pito de cadenas. Miras el port�n, y observas como desciende r�pidamente.\nAl poco, el port�n termina de bajar y cesa el ruido.\n"}));
    SetNotifyCloseMsg(({"Escuchas un estr�pito de cadenas. Miras el port�n, y ves como comienza a elevarse lentamente.\nTras unos instantes, el port�n termina de cerrarse.\n"}));
    SetRoomClosedMsg("El port�n est� cerrado, no puedes pasar.\n");
    SetNoSchedulerObject(1);

	//SetIndoors(0);
    AddAntorchas();
    AddSuelo();
    AddItem(PNJ_CIUDAD_ANNUFAM("guardian_porton"),REFRESH_DESTRUCT,1);
    AddExit("sur",SF(salir_ciudad));
	//AddExit("sur",HAB_CIUDAD_ANNUFAM("entrada"));
    AddExit("norte",HAB_AVENIDA_ANNUFAM("avenida_02"));
    AddExit("este",SF(entrar_garita));
    AddExit("oeste",SF(entrar_torre));
}

int salir_ciudad()
{
    if (!TP) return 0;
	if ((-1 != member(HORAS_PORTON_CERRADO, QueryDayState())) && (pDesdeGarita==1))
	{
        TP->move(HAB_CIUDAD_ANNUFAM("entrada"),M_GO,"sur");
        return 1;
	}
	if ((-1 == member(HORAS_PORTON_CERRADO, QueryDayState())) && (pDesdeGarita==0))
	{
		write(QueryRoomClosedMsg());
		return 1;
	}
	if (-1 == member(HORAS_PORTON_CERRADO, QueryDayState()))
	{
        TP->move(HAB_CIUDAD_ANNUFAM("entrada"),M_GO,"sur");
		return 1;
	}
	else
	{
		write(QueryRoomClosedMsg());
		return 1;
	}
/*
    if (QueryPortonAbierto())	//pPortonAbierto && (pDesdeGarita!=0))
    {
        TP->move(HAB_CIUDAD_ANNUFAM("entrada"),M_GO,"sur");
        return 1;
    }
    //write("El port�n est� cerrado, no puedes pasar.\n");
	write(QueryRoomClosedMsg());
    return 1;
*/
}

int entrar_garita()
{
    if (QueryGuardian())
    // hay alg�n guardia aqu� vivo, as� que no te deja pasar.
    {
        write("El guardi�n te corta el paso y te dice: �A d�nde crees que "
              "vas? �No puedes entrar ah�!\n");
        say(CAP(TNAME) + " se dirige hacia la garita.\n"
              "Sin embargo, el guardi�n le corta el paso y le impide entrar.\n");
        return 1;
    }
    TP->move(HAB_CIUDAD_ANNUFAM("garita"),M_GO,"este");
    return 1;
}

public void NotifyDayStateChange(mixed data, int state)
{
    int accion = -1;
	// Sea como sea olvidamos lo que hab�a en la garita
	pDesdeGarita = -1;
    // si es denoche, el port�n debe cerrarse
    if (state == ND_NIGHT) accion = P_CERRAR;
    // si est� amaneciendo (ya es el alba), lo abrimos
    else if (state == ND_DAWN) accion = P_ABRIR;
    // si no hay acci�n, salimos
    if (accion == -1) return;
    // si la acci�n es la misma que el estado del port�n, salimos
    if (accion == pPortonAbierto) return;
    if (!QueryGuardian())
    // no hay guardia
    {
        tell_room(TO,"Llega un soldado y mira hacia todos lados con "
                     "expresi�n col�rica mientras murmura:\n"
                     "'Maldita sea, nunca est� cuando tiene que " +
                     (accion == P_CERRAR ? "subir" : "bajar") +
                     " el maldito port�n.'\n\n"
                     "A continuaci�n, entra en la garita.\n");
        SetPortonAbierto(accion);
        tell_room(TO,"El soldado sale de la garita y desaparece en la noche.\n");
        return;
    }
    // hay guardia
    tell_room(TO,"El guardi�n mira al cielo y entra en la garita.\n");
    SetPortonAbierto(accion);
    tell_room(TO,"El guardi�n sale de la garita.\n");
    ::NotifyDayStateChange(data, state);
    return;
}

public varargs int ThrowOutPeople(int silent, object from, int from_silent)
{
	SetPortonAbierto(P_CERRAR);
	return 0;
}

public varargs void OpenRoom(int silent)
{
	::OpenRoom(silent);
	if (pPortonAbierto) return;
	if (!QueryGuardian())
	// no hay guardia
    {
        tell_room(TO,"Llega un soldado y mira hacia todos lados con "
                       "expresi�n col�rica mientras murmura:\n"
                       "'Maldita sea, nunca est� cuando tiene que " 
                       "bajar" 
                       " el maldito port�n.'\n\n"
                       "A continuaci�n, entra en la garita.\n");
        SetPortonAbierto(1);
        tell_room(TO,"El soldado sale de la garita y desaparece en la "
                     "noche.\n");
        return;
    }
    // hay guardia
    tell_room(TO,"El guardi�n mira al cielo y entra en la garita.\n");
    SetPortonAbierto(1);
    tell_room(TO,"El guardi�n sale de la garita.\n");
    return;
}

public int allow_enter(int method, mixed extra)
{
	return ME_OK;
}

public void notify_enter(mixed from, int method, mixed extra)
{
    object prev = PO ||TP;
    ::notify_enter(from, method, extra);
    // si ha entrado un guardia, actualizamos el estado del port�n
    if (living(prev) && prev->id("guardian_porton"))
    {
        call_out("ActualizaEstadoPorton",1,POR_GUARDIA);
    }

    if (living(prev) && extra == "norte")
    // quien sea est� entrando en la ciudad
    {
        tell_object(prev,"Cruzas el puente levadizo y entras en la "
                         "ciudad.\n");
    }
}

public void notify_leave(mixed to, int method, mixed extra)
{
    ::notify_leave(to, method, extra);
    if (extra == "sur" && living(PO))
    {
        tell_object(PO,"Cruzas el puente levadizo y sales de la ciudad.\n");
    }
}


int entrar_torre()
{
    if (QueryGuardian())
    // hay alg�n guardia aqu� vivo, as� que no te deja pasar.
    {
        write("Te diriges hacia la torre, pero el guardi�n te corta el paso "
              "bruscamente mientras te grita: Eh, �d�nde demonios te crees "
              "que vas?\n");
        say(CAP(TNAME) + " se dirige hacia la torre.\n"
              "Sin embargo, el guardi�n le corta el paso y le impide entrar.\n");
        return 1;
    }
    TP->move(HAB_MURALLAS_ANNUFAM("escaleras"),M_GO,"oeste");
    return 1;
}
