/****************************************************************************
Fichero: avenida_01.c
Autor: Kastwey
		Tagoras [t]
Creación: 24/07/2005
Descripción: Inicio de la avenida real de Annufam
[t] 19/02/2009: Comentadas las secciones que hacen referencia al servidor del clima. Por ello el portón no funciona automáticamente.
[t] 25/02/2009: Cambiado SERVER_ANNUFAM por NIGHTDAY para saber el estado del dia.
[t] 15/03/2009: El portón funciona.
[t] 20/03/2009: Añadido sonido de abrir y cerrar al portón.
[t] 02/05/2010: Había un momento del día que la rueda no permitía bajar el portón, ahora parece que funciona.
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

int pPortonAbierto; // el portón
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
// abre o cierra el portón.
// si se le pasa 1 en SILENT, lo hará en silencio
{
    object hab_player;
    // si hay algún call_out al actualizar estado del portón
    // lo quitamos
    if (find_call_out("ActualizaEstadoPorton"))
    {
        remove_call_out("ActualizaEstadoPorton");
    }
	// Quitamos cualquier acción manual del jugador
	pDesdeGarita=-1;


	//if (find_object("tagoras")) dtell("tagoras", "DayState:"+QueryDayState()+" Cerrado:"+member(HORAS_PORTON_CERRADO, QueryDayState())+" Accion:"+i+" DesdeGarita:"+pDesdeGarita+" CuandoGarita:"+pCuandoGarita+" PortonAbierto:"+pPortonAbierto+"\n");
    if (i == pPortonAbierto) return i;
    if (pPortonAbierto && !i && !silent)
    // está abierto y se va a cerrar
    {
        string msg = "Escuchas un estrépito de cadenas. Miras el portón, y "
                     "ves como comienza a elevarse lentamente.\n"
                     "Tras unos instantes, el portón termina de "
                     "cerrarse.\n";
        tell_room(TO,msg);
        tell_room(ENTRADA,msg);
		play_sound(TO,SND_SUCESOS("cerrar_porton"));
		//play_sound(ENTRADA,SND_SUCESOS("cerrar_porton"));
    }
    if (!pPortonAbierto && i && !silent)
    // Se va a abrir
    {
        string msg = "Escuchas un estrépito de cadenas. Miras el portón, "
                     "y observas como desciende rápidamente.\n"
                     "Al poco, el portón termina de bajar y cesa el "
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
                         "Con gran destreza, hace girar rápidamente la "
                         "gran rueda, hasta que el portón queda "
                         "totalmente " + (i ? "bajado" : "alzado") + ". "
                         "A continuación, sale de la garita sin tan "
                         "siquiera haberte visto.\n");
    }
    // si el que lo ha movido es un player y está en la garita, y además,
    // hay aquí un guardia...
    if (query_once_interactive(TP)
        && object_name(hab_player) == GARITA
        && QueryGuardian())
    {
        tell_room(TO,"El guardián mira boquiabierto el portón.\n"
                     "Rápidamente se dirige hacia la garita.\n");
        // Nos traemos al player y a todos los que estén en la garita
        // por los pelos
        object *inv;
        inv = filter(all_inventory(hab_player),(:query_once_interactive($1) && $1 != TP:));
        tell_object(TP,"El guardián del portón llega desde la entrada "
                       "de la ciudad.\n"
                       "Te mira, y luego mira la barra que aún "
                       "sujetas.\n"
                       "El enano te agarra de los pelos con increible "
                       "fuerza mientras te grita:\n"
                       "'¿Pero qué demonios te crees que haces aquí?\n"
                       "¿Piensas que el portón es cosa de risa?!!\n"
                       "¡La próxima vez utilizaré mi hacha contigo, "
                       "maldit" + AO + " gamberr" + AO + "!!!'\n"
                       "De un tirón, te arrastra hasta la entrada de "
                       "la ciudad.\n");
        tell_room(hab_player,"Llega el guardia del portón, y clava en " +
                             CAP(TNAME) + " una mirada capaz de atravesar "
                             "una roca mientras le amonesta a gritos por "
                             "haber movido el portón.\n"
                             "Sin darle tiempo a reaccionar," + LALO + " "
                             "coge por los pelos y " + LALO + " arrastra "
                             "hacia la salida.\n"),({TP});
        tell_room(TO,CAP(TNAME) + " llega arrastrad " + AO + " por el guardia.\n");
        pPortonAbierto = i;
        TP->move(TO,M_SILENT);

        tell_room(hab_player,"El guardia vuelve a asomarse y grita:\n"
                             "'¡Eh " + (sizeof(inv)>1?"vosotros":"tú") +
                             "!!! ¡Largo de aquí ahora mismo!\n");
        filter(inv,(:tell_object($1,"Sin atreverte a rechistar, sales de la garita.\n");
                     $1->move(TO,M_GO,"oeste");:));
        tell_room(TO,"El guardián mira el portón y suelta una maldición:\n"
                     "¡Por todos los demonios! ahora tengo que dejar el "
                     "maldito portón como estaba!\n"
                     "Tras decir esto, entra en la garita, " +
                     (i?"sube" : "baja") + " el portón y "
                     "vuelve a salir.\n");
        return pPortonAbierto = !i;
    }
	// El player lo mueve desde la garita
	if (query_once_interactive(TP) && (object_name(hab_player) == GARITA))
	{
		// A estas horas debería estar cerrado pero el jugador lo abre
		if ((-1 != member(HORAS_PORTON_CERRADO, QueryDayState())) && i)
		{
			pDesdeGarita = i;
			pCuandoGarita = QueryDayState();
		}
		// A estas horas debería estar abierto pero el jugador lo cierra
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
    // el portón se abre
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
    // si esta función la llama el guardián del portón, es él
    // quien lo cierra
    {
        tell_room(TO,"El guardián mira extrañado el portón y sacude la "
                     "cabeza mientras murmura:\n"
                     "'Hmmmm. ¿Qué demonios hace el portón " +
                     (pPortonAbierto ? "abierto" : "cerrado") + " a estas "
                     "horas?'\n\n"
                     "Contrariado, entra en la garita.\n");
        SetPortonAbierto(accion);
        tell_room(TO,"El guardia sale de la garita mientras dice: "
                     "Si no fuera por mí...\n");
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
	// A estas horas debería estar cerrado
	if ((-1 != member(HORAS_PORTON_CERRADO, QueryDayState())) && (pDesdeGarita==1))
	{
		return pPortonAbierto = 1;
	}
	// A estas horas debería estar abierto
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
    // colocamos el portón como debe de estar
    ActualizaEstadoPorton();

    SetIntShort("la avenida real de Annufam");
    SetIntLong((:"Caminas por el principio de la avenida de la ciudad. Si "
                 "comparas estas construcciones con las de la capital "
                 "Kha-annu, te das cuenta de que aquí no se viene a "
                 "descansar. Es todo sobriedad. Un camino de tierra, pero a "
                 "la vez bien cuidado sigue de norte a sur. Hacia el sur, " +
                 (!QueryPortonAbierto() ?
                 "ves alzarse imponente el portón de la ciudad" :
                 "ves el portón de la ciudad, que al estar bajado, sirve de "
                 "puente entre esta avenida y la entrada") +
                 ". Al este, puedes ver una pequeña garita, que supones servirá "
                 "para controlar la apertura y cierre del puente levadizo, "
                 "y al oeste la entrada a una torre.\n"
                 "Un par de antorchas iluminan esta parte de la avenida "
                 "cuando es necesario.\n":));
    AddDetail(({"muralla","murallas","muro"}),
              "Es una muralla de piedra, de casi diez metros de altura. "
                "Preservan a la ciudad de cualquier intento de intrusión.\n");

    AddDetail(({"porton","portón","puerta","puente","puente levadizo"}),
              (:"Es una gran puerta de hierro sujeta por cuatro gruesas "
                "cadenas que permiten subirla o bajarla con relativa "
                "facilidad. Supones que el control está en la garita que "
                "puedes ver al este.\n"
                "Actualmente el portón está " +
                (QueryPortonAbierto() ? " abierto, sirviendo así de puente para "
                                  "atravesar el foso que separa la entrada "
                                  "de la ciudad en sí.\n" :
                                  "cerrado, impidiendo así la entrada a la ciudad.\n"):));

    AddDetail("torre",
              "Es una torre que llega hasta lo más alto de las murallas. "
              "Observas su entrada al oeste.\n");

    AddDetail("garita","Se trata de una edificación construida al lado del "
                       "gran puente levadizo, y es donde el guardia de "
                       "turno ha de levantar o descender el mismo según la hora o las circunstancias.\n");

    // notificará a esta room cuando se cambie de etapa en el día
	SetCloseTime(HORAS_PORTON_CERRADO);
    SetLastDest(HAB_AVENIDA_ANNUFAM("avenida_01"));
    SetNotifyExits(({"sur", "norte"}));
    SetInformCloseMsg("El guardián grita:\nA ver todo el mundo, entrad o salid de la ciudad que vamos a izar el portón\n");
    SetThrowOutMsg("Escuchas un estrépito de cadenas. El guardián grita:\nTodo el mundo a la ciudad, la noche puede resultar muy peligrosa ahí fuera.\n");
    SetNotifyOpenMsg(({"Escuchas un estrépito de cadenas. Miras el portón, y observas como desciende rápidamente.\nAl poco, el portón termina de bajar y cesa el ruido.\n"}));
    SetNotifyCloseMsg(({"Escuchas un estrépito de cadenas. Miras el portón, y ves como comienza a elevarse lentamente.\nTras unos instantes, el portón termina de cerrarse.\n"}));
    SetRoomClosedMsg("El portón está cerrado, no puedes pasar.\n");
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
    //write("El portón está cerrado, no puedes pasar.\n");
	write(QueryRoomClosedMsg());
    return 1;
*/
}

int entrar_garita()
{
    if (QueryGuardian())
    // hay algún guardia aquí vivo, así que no te deja pasar.
    {
        write("El guardián te corta el paso y te dice: ¿A dónde crees que "
              "vas? ¡No puedes entrar ahí!\n");
        say(CAP(TNAME) + " se dirige hacia la garita.\n"
              "Sin embargo, el guardián le corta el paso y le impide entrar.\n");
        return 1;
    }
    TP->move(HAB_CIUDAD_ANNUFAM("garita"),M_GO,"este");
    return 1;
}

public void NotifyDayStateChange(mixed data, int state)
{
    int accion = -1;
	// Sea como sea olvidamos lo que había en la garita
	pDesdeGarita = -1;
    // si es denoche, el portón debe cerrarse
    if (state == ND_NIGHT) accion = P_CERRAR;
    // si está amaneciendo (ya es el alba), lo abrimos
    else if (state == ND_DAWN) accion = P_ABRIR;
    // si no hay acción, salimos
    if (accion == -1) return;
    // si la acción es la misma que el estado del portón, salimos
    if (accion == pPortonAbierto) return;
    if (!QueryGuardian())
    // no hay guardia
    {
        tell_room(TO,"Llega un soldado y mira hacia todos lados con "
                     "expresión colérica mientras murmura:\n"
                     "'Maldita sea, nunca está cuando tiene que " +
                     (accion == P_CERRAR ? "subir" : "bajar") +
                     " el maldito portón.'\n\n"
                     "A continuación, entra en la garita.\n");
        SetPortonAbierto(accion);
        tell_room(TO,"El soldado sale de la garita y desaparece en la noche.\n");
        return;
    }
    // hay guardia
    tell_room(TO,"El guardián mira al cielo y entra en la garita.\n");
    SetPortonAbierto(accion);
    tell_room(TO,"El guardián sale de la garita.\n");
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
                       "expresión colérica mientras murmura:\n"
                       "'Maldita sea, nunca está cuando tiene que " 
                       "bajar" 
                       " el maldito portón.'\n\n"
                       "A continuación, entra en la garita.\n");
        SetPortonAbierto(1);
        tell_room(TO,"El soldado sale de la garita y desaparece en la "
                     "noche.\n");
        return;
    }
    // hay guardia
    tell_room(TO,"El guardián mira al cielo y entra en la garita.\n");
    SetPortonAbierto(1);
    tell_room(TO,"El guardián sale de la garita.\n");
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
    // si ha entrado un guardia, actualizamos el estado del portón
    if (living(prev) && prev->id("guardian_porton"))
    {
        call_out("ActualizaEstadoPorton",1,POR_GUARDIA);
    }

    if (living(prev) && extra == "norte")
    // quien sea está entrando en la ciudad
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
    // hay algún guardia aquí vivo, así que no te deja pasar.
    {
        write("Te diriges hacia la torre, pero el guardián te corta el paso "
              "bruscamente mientras te grita: Eh, ¿dónde demonios te crees "
              "que vas?\n");
        say(CAP(TNAME) + " se dirige hacia la torre.\n"
              "Sin embargo, el guardián le corta el paso y le impide entrar.\n");
        return 1;
    }
    TP->move(HAB_MURALLAS_ANNUFAM("escaleras"),M_GO,"oeste");
    return 1;
}
