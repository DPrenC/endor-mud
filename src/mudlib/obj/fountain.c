/**
 * /obj/fountain
 */


#include <messages.h>
#include "drink.h"
#include <properties.h>
#include <sounds.h>t
#define AO (pGender == 2?"a":"o")

inherit THING;

/* Propiedades */

private int pCapacity, pFull, pMlPerDraught, pMlPerSecond, pNoRefill, pSeeState;
private int  pGender, pLastUse;
private mixed pDrinkMsg, pCantDrinkMsg, pNoWaterMsg, pRefillMsg, pCantRefillMsg;
private object pRefilledObject;
private string pReferrerName;
private string *pCommandsDrink = ({"agua","agua de la fuente","agua de fuente",
                                   "de fuente","de la fuente"});


/* funciones */


// volúmen de la cantimplora (en mililitros)
public int SetCapacity(int vol) { return pCapacity = vol; }
public int QueryCapacity() { return pCapacity; }

public int SetFull(int full)
// ajusta el volúmen de agua que hay en la fuente, en mililitros
{
    if (full < 0) return pFull = 0;
    return pFull = (full > pCapacity ? pCapacity : full);
}
public int QueryFull() { return pFull; }

public int SetFullPoints(int water)
// ajusta el llenado de la fuente en puntos de sed.
{
    pFull = water * ML_PER_POINT;
    return water;
}
public int QueryFullPoints() { return pFull / ML_PER_POINT; }

public int SetCapacityPoints(int i)
{
    pCapacity = i * ML_PER_POINT;
    return i;
}
public int QueryCapacityPoints() { return pCapacity / ML_PER_POINT; }


public int SetMlPerSecond(int ml)
// ajusta la cantidad de mililitros por segundo en los que se irá llenando la fuente
{
    return pMlPerSecond = ml;
}
public int QueryMlPerSecond() { return pMlPerSecond; }

public int SetDrinkPointsPerSecond(int i)
// ajusta los puntos de agua en los que se irá llenando la fuente por cada segundo
{
    pMlPerSecond = i * ML_PER_POINT;
    return i;
}
public int QueryDrinkPointsPerSecond() { return pMlPerSecond / ML_PER_POINT; }

public int SetMlPerDraught(int i)
// ajusta la cantidad de mililitros que se incrementará al contador de agua del
// jugador, por cada trago que dé en la fuente
{
    return pMlPerDraught = i;
}
public int QueryMlPerDraught() { return pMlPerDraught; }

public int SetDrinkPointsPerDraught(int i)
// ajusta la cantidad de puntos de sed que se incrementará al contador de agua del jugador,
// por cada trago que dé en la fuente
{
    pMlPerDraught = i * ML_PER_POINT;
    return i;
}
public int QueryDrinkPointsPerDraught() { return pMlPerDraught / ML_PER_POINT; }


public int QueryRefilling()
// devuelve 1 si alguien está rellenando un objeto cantimplora en la fuente, o 0 de lo contrario
{
    return pRefilledObject != 0;
}

public object SetRefilledObject(object ob) { return pRefilledObject = ob; }
public object QueryRefilledObject() { return pRefilledObject; }
public object QueryRefiller()
// devuelve el jugador que contiene el objeto que está siendo rellenado
{
    object env;
    if (!pRefilledObject) return 0;
    if (!(env = environment(pRefilledObject)) || !query_once_interactive(env)) return 0;
    return env;
}


public mixed SetNoRefill(mixed msg) { return pNoRefill = msg; }
public mixed QueryNoRefill() { return pNoRefill; }



public void UpdateFull()
// actualiza el llenado de la fuente
{
    int i;
    if (!pLastUse)
    {
        pLastUse = time();
        return;
    }
    if (pFull != pCapacity)
    // no está llena
    {
        // calculamos la cantidad de segundos que hace que no se ejecuta la función, y
        // multiplicamos por la cantidad de mililitros por segundo que se irá llenando la
        // fuente, para ver cuanto hay que sumarle al pFull
        i= time() - pLastUse;
        i *= pMlPerSecond;
        pFull += (pFull + i > pCapacity ? pCapacity - pFull : i);
    }
    pLastUse = time();
}



public int CantRefill()
// si la fuente está vacía, no se puede rellenar nada en ella
{
    UpdateFull();
    return pCapacity && !pFull;
}



public int SetSeeState(int see) { return pSeeState = see; }
public int QuerySeeState() { return pSeeState; }


public int SetGender(int gen) { return pGender = gen; }
public int QueryGender() { return pGender; }


public string SetReferrerName(string name) { return pReferrerName = name; }
public string QueryReferrerName() { return pReferrerName; }

private mixed _convert_fountain_msg(mixed var, mixed msg)
// pasado un mensaje, lo convierte al tipo de mensajes que guardan las variables de
// mensajes de la fuente: ({msg_al_player, msg_a_la_room}).
{
    return var = (stringp(msg) || closurep(msg)?({msg,0}):
                  (pointerp(msg) && sizeof(msg) == 2?msg:var));
}


public void SendFountainMsg(mixed msg, string msg1, string msg2)
// envía el mensaje <msg> al player y a la habitación, y si alguno de los dos no existe,
// coge los mensajes de <msg1> y <msg2> respectivamente
{
    if (!TP) return;
    tell_object(TP, (msg ? funcall(msg[0]) : msg1));
    tell_room(environment(), ({MSG_SEE,
              (msg ? (stringp(msg[1]) ? CAP(TNAME) + " " + msg[1] : funcall(msg[1])) :
               CAP(TNAME) + " " + msg2)}), ({TP}));
}

public mixed SetDrinkMsg(mixed msg) { return _convert_fountain_msg(&pDrinkMsg, &msg); }
public mixed QueryDrinkMsg() { return pDrinkMsg; }

public mixed SetCantDrinkMsg(mixed msg) { return _convert_fountain_msg(&pCantDrinkMsg, &msg); }
public mixed QueryCantDrinkMsg() { return pCantDrinkMsg; }

public mixed SetNoWaterMsg(mixed msg) { return _convert_fountain_msg(&pNoWaterMsg, &msg); }
public mixed QueryNoWaterMsg() { return pNoWaterMsg; }


public mixed SetRefillMsg(mixed msg) { return _convert_fountain_msg(&pRefillMsg, &msg); }
public mixed QueryRefillMsg() { return pRefillMsg; }

public mixed SetCantRefillMsg(mixed msg) { return _convert_fountain_msg(&pCantRefillMsg, &msg); }
public mixed QueryCantRefillMsg() { return pCantRefillMsg; }



public int SetLastUse(int time) { return pLastUse = time; }
public int QueryLastUse() { return pLastUse; }
public string *SetCommandsDrink(string *cmds) { return pCommandsDrink = cmds; }
public string *QueryCommandsDrink() { return pCommandsDrink; }

public string *AddCommandDrink(mixed cmds)
{
    if (stringp(cmds))
    {
        if (member(pCommandsDrink || ({}),cmds) >= 0) return pCommandsDrink;
        return pCommandsDrink += ({cmds});
    }
    else if (pointerp(cmds))
    {
        return pCommandsDrink += filter(cmds,(:member($2,$1) < 0:),
                                        pCommandsDrink);
    }
    return pCommandsDrink;
}

public int QueryIsFountain() { return 1; }


public int RemoveDrink(int ml)
{
    int i;
    i = pFull -= (ml < pFull?ml:pFull);
    UpdateFull();
    return i;
}

public int DrinkDraught() { return RemoveDrink(pMlPerDraught); }


public string QueryFullState()
{
    string estado;
    int porcentaje;
    UpdateFull();
    porcentaje     = 100 * pFull / pCapacity;
    switch(porcentaje)
    {
        case 0:       estado = "está totalmente vací" + AO;              break;
        case 1..10:   estado = "sólo quedan algunas gotas de agua";      break;
        case 11..30:  estado = "está casi vací" + AO;                    break;
        case 31..50:  estado = "está casi hasta la mitad";              break;
        case 51..70:  estado = "está bastante llen" + AO;                break;
        case 71..90:  estado = "está casi llen" + AO;                    break;
        case 91..100: estado = "está totalmente llen" + AO;              break;
    }
    return estado;
}


public string QueryLong()
// devuelve la descripción larga de la fuente
{
    if (!pSeeState) UpdateFull();
    return ::QueryLong() + (pSeeState && pCapacity?
                                capitalize(QueryFullState() + ".\n"):"");
}




/* acciones */


public int cmd_beber(string str)
// función para beber agua
{
    int drink, MaxDrink;
    string estado = (pSeeState?QueryFullState() : 0);
    if (!estado) UpdateFull();
    if (!str || member(pCommandsDrink,str) < 0)
    {
        return notify_fail("Beber qué?\n",NOTIFY_NOT_VALID);
    }
    if (pRefilledObject)
    { // alguien está llenando una cantimplora en la fuente
        if (TP == QueryRefiller())
        { // eres tu el que quieres beber, y el de la cantimplora
            return notify_fail("Antes de beber, espera a terminar de "
                               "rellenar " +
                               (pRefilledObject->QueryShort() || "la cantimplora") + ".\n");
        }
        return notify_fail(CAP(NNAME(QueryRefiller())) + " está " +
                             "rellenando " +
                             (pRefilledObject->QueryShort() || "una cantimplora") + " en este momento. "
                             "Mejor espera a que termine.\n");
    }
    if (pCapacity && (!pFull || pFull < pMlPerDraught))
    // no hay suficiente agua en la fuente.
    // o bien porque no queda nada, o porque no queda la suficiente para
    // satisfacer los puntos de sed que se deben añadir al player por cada trago.
    {
        return notify_fail((:SendFountainMsg(&pNoWaterMsg, CAP(pReferrerName) + " no "
                             "tiene suficiente agua para que puedas beber.\n",
                             "se dispone a beber, pero se da cuenta de que no hay suficiente "
                             "agua en " + pReferrerName + ".\n"):),
                           NOTIFY_NOT_VALID);
    }
    if ((drink = TP->QueryDrink()) == (MaxDrink = TP->QueryMaxDrink()))
    { // no puede beber más
        return notify_fail((:SendFountainMsg(&pCantDrinkMsg, "No puedes beber más.\n",
                                                "se acerca a " + pReferrerName +
                                                " pero se da cuenta de que no puede beber "
                                                "más.\n"):), NOTIFY_NOT_VALID);
    }
    TP->AddDrink(QueryDrinkPointsPerDraught());
    if (pCapacity) // la fuente tiene un volúmen de llenado
    {
        DrinkDraught(); // tomamos un trago de la fuente
        if (pMlPerSecond) pLastUse = time();
    }
    SendFountainMsg(&pDrinkMsg, "Bebes agua d" + (pReferrerName[..2] == "el " ? "" : "e ") +
                       pReferrerName + "." +
                       (estado && estado != (estado = QueryFullState()) ?
                        " Ahora " + estado + "." : "") + "\n",
                       "bebe agua d" + (pReferrerName[..2] == "el " ? "" : "e ") +
                       pReferrerName + ".\n");
    play_sound(environment(TP), SND_SUCESOS("beber"));
    return 1;
}




create()
{
    ::create();
    SetShort("una fuente");
    SetLong("Es una fuente.\n");
    AddId(({"fuente","fuente_de_agua"}));
    SetNoTake("¿De verdad pretendes coger una fuente?\n");
    SetWeight(100000);
    SetDrinkPointsPerDraught(5);
    SetGender(GENDER_FEMALE);
    SetReferrerName("la fuente");
}

init()
{
    ::init();
    add_action("cmd_beber","beber");
}

reset()
{
    if (!pFull && !pMlPerSecond)
    // si tiene capacidad pero no se ha definido un llenado automático (véase un barril, o similar,
    // se rellena en el reset
    {
        pFull = pCapacity;
    }
}
