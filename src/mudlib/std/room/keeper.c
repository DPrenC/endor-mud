/*
Fichero: keeper.c
Autor: kastwey@simauria
Creación: 05/02/2005
Basado en el comm.c de las tiendas.
10/02/2005: Añadidas un par de funciones de manejo de dinero
***/



#include <config.h>
#include <properties.h>
#include <living.h>
#include <rooms.h>
#include "keeper.h"
#include <money.h>

#define KEEPER_ID "Soy_el_empleado"
#define LSF(x) symbol_function(x, TO)
#define ESF(x) symbol_function(x)
#define AO (TP->QueryGender() == 2?"a":"o")

int pNoKeeper = 1;


public object QueryKeeper()
// devuelve el objeto empleado
{
    object ob;

    ob = present(KEEPER_ID, TO);
    if (ob && living(ob)) return ob;
    return 0;
}

public int SetNoKeeper(int i)
{
    if (QueryKeeper() && i) return pNoKeeper;
    return pNoKeeper = i;
}

public int QueryNoKeeper() { return pNoKeeper; }

public void RemoveKeeper()
// elimina al empleado
{
    object ob;
    string fname;
    if (ob = QueryKeeper())
    {
        fname = blueprint(ob);
        ob->remove();
        if (ob) destruct(ob);
        pNoKeeper = 1;
        TO->RemoveItem(fname);
        if (member(inherit_list(TO), SCHEDULER_ROOM + ".c") >= 0)
        // se trata de una scheduler, así que quitamos la id del scheduler
        {
            TO->SetSchedulerID(0);
            TO->SetNoSchedulerObject(1);
        }

    }
}

public varargs void SetKeeper(mixed arg1, mixed arg2)
// agrega al empleado
// si no se le pasa el parámetro File, añadirá a un empleado
// estándar: humano, nivel 17.
// si se le pasan propiedades, asignará dichas propiedades al pnj que se clone.
{
    int gender = random(30) < 15;
    mapping properties;
    string file;
    file =    (stringp(arg1) && arg1)
           || (stringp(arg2) && arg2);
    properties =    (mappingp(arg1) && arg1)
                 || (mappingp(arg2) && arg2)
                 || ([]);

    pNoKeeper = 0;
    RemoveKeeper();
    if (!file)
    { // no se ha pasado file como parámetro, aasí que creamos un pnj estándar
        file = "/std/npc";
        properties = ([
            P_GENDER:  gender ? GENDER_MALE : GENDER_FEMALE,
            P_RACE:    "humano",
            P_LEVEL:   17,
            P_IVISION: 20,
            P_UVISION: 300,
            P_SHORT:   gender ? "el empleado" : "la empleada",
            P_NAME:    gender ? "el empleado" : "la empleada",
            P_CANT_LURE: 1,
            P_IDS:     gender ? ({"empleado","asistente"})
                              : ({"empleada","asistenta"}),
            P_LONG:    gender ? "Éste es el empleado.\n"
                              : "Ésta es la empleada.\n"
        ]) + properties;
    }
    TO->AddItem(file, REFRESH_HOME, properties + ([P_CANT_LURE: 1]), LSF("keeper_refresh"));
    if (member(inherit_list(TO), SCHEDULER_ROOM + ".c") >= 0)
    // es una scheduler_room, así que ajustamos la ID del encargado
    {
        TO->SetSchedulerID(KEEPER_ID);
    }
}

public varargs int keeper_in_room(int silent)
// comprueba si el empleado está en la habitación.
// Si no está y sylent vale 0, envía un mensaje al player.
// si P_NO_KEEPER_MSG vale 0, se enviará un mensaje por defecto.
{
    if (QueryNoKeeper() || QueryKeeper()) return 1;
    if (!silent)
    {
        return notify_fail(   TO->Query(P_NO_KEEPER_MSG)
                           || "No hay nadie aquí que pueda atenderte.\n",
                           NOTIFY_NOT_VALID);
    }
}

public varargs string KeeperShort(int cap)
// devuelve la descripción corta del empleado.
// si se le pasa 1 como argumento, la descripción aparecerá capitalizada.
{
    object ob;
    string message;

    if (QueryNoKeeper()) message = "el empleado";
    else if (!QueryKeeper()) return 0;
    else message = QueryKeeper()->QueryShort() || "alguien";
    return cap?capitalize(message):message;
}

public varargs string KeeperName(int cap)
// devuelve el nombre del empleado.
// si se le pasa 1 como parámetro, lo devolverá capitalizado
{
    object ob;
    string message;

    if (QueryNoKeeper()) message = "el empleado";
    else if (!QueryKeeper()) return 0;
    else message = QueryKeeper()->QueryName()||"alguien";
    return cap?capitalize(message):message;
}

public varargs int KeeperSay(string str)
// El empleado verbaliza 'str' y devuelve 1.
// En caso de error, devolverá 0.
{
    if (keeper_in_room(K_SILENT))
    {
        tell_room(TO,W(KeeperName(K_CAP)+" dice: "+str));
        return 1;
    }
    return 0;
}

public varargs int KeeperTell(string str, object ob)
// el empleado verbaliza 'str' solo para el cliente y devuelve 1.
// en caso de error, devuelve 0.
// Si se pasa ob, enviará ese mensaje a ob. Si no, ob será TP.
{
    if (!ob) ob = TP;
    if (keeper_in_room(K_SILENT))
    {
        tell_object(ob,W(KeeperName(K_CAP)+" te dice: "+str));
        return 1;
    }
    return 0;
}

public int KeeperEmote(mixed str)
// el empleado envía un mensaje.
// Si el parámetro es una cadena, enviará el mensaje a la room.
// Si es un array de dos elementos, el primer elemento lo enviará al player
// y el segundo a la room, escluyendo a dicho player.
// si uno de los dos elementos es 0, ese mensaje se omitirá.
{
    if (keeper_in_room(K_SILENT))
    {
        if (stringp(str))
        {
            tell_room(TO,W(KeeperName(K_CAP) + " " + str));
        }
        else
        if (pointerp(str) && sizeof(str) == 2)
        {
            if (str[0]) tell_object(TP,W(KeeperName(K_CAP)+" "+ str[0]));
            if (str[1]) tell_room(TO,W(KeeperName(K_CAP)+" "+str[1]),({TP}));
        }
        return 1;
    }
    return 0;
}

public void keeper_refresh(object ob)
{
    ob->AddId(KEEPER_ID);
}


public varargs void Emote(mixed msg, mixed exclude)
// envía un mensaje a la room, excluyendo por defecto a TP
// además de excluir a la  lista pasada como segundo parámetro (opcional).
{
    say(  W(msg) || ""
        , (exclude ? (objectp(exclude) ? ({ exclude, TP }) : exclude )
                   : ({ TP }) )
          + filter(  all_inventory(TO)
                   ,(: !(living($1) && $1->CanSeeObject($2)) :)
                   , TP )
       );
}

public varargs string CantAttend(mixed mix)
// devuelve 0 si el empleado te puede atender.
// Si no, devuelve un menxaje de error.
// Si se le pasa un objeto como parámetro, devolverá el resultado dependiendo
// de dicho objeto.
// Si se le pasa un 1, devolverá el mensaje en caso de error, como notify_fail.
{
    string message;
#ifdef FIGHTING_YOU_ROOM_MSG
    string message_room;
#endif
    int fail;

    if (!mix) mix = TP;
    if (intp(mix))
    {
        fail = mix;
        mix = TP;
    }
    if (QueryNoKeeper()) return 0;
    if (!QueryKeeper())
    { // no está
        message =    TO->Query(P_NO_KEEPER_MSG)
                  || "No hay nadie aquí para atenderte.\n";
    }
    else if (!QueryKeeper()->CanSeeObject(mix))
    {
        message =    TO->Query(P_CANT_SEE_MSG)
                  || KeeperName(K_CAP) + " no puede verte.\n";
    }
    else if (QueryKeeper()->Fighting())
    { // Está luchando
        if (member(QueryKeeper()->QueryEnemies() || ({}),mix) >= 0)
        { // mix es uno de los enemigos del empleado
            message =    TO->Query(P_FIGHTING_YOU_MSG)
                      || W("En el fragor de la batalla, consideras absurdo "
                           "entablar una conversación con "+KeeperName(K_CAP)+
                           ".\n");
#ifdef FIGHTING_YOU_ROOM_MSG
            message_room = TO->Query(P_FIGHTING_YOU_ROOM_MSG)?
              capitalize(mix->QueryName()) + " " + TO->Query(P_FIGHTING_YOU_ROOM_MSG):
              W("Cuando " + capitalize(mix->QueryName()) + " se dispone a "
                "hablar con " + KeeperName(K_CAP) + " se da cuenta de lo "
                "absurdo de la situación, y cierra la boca.\n");
#endif
        }
        else
        { // mix no es uno de los enemigos.
            message =    TO->Query(P_FIGHTING_MSG)
                      || W("Cuando vas a hablar con " + KeeperName(K_CAP) + ", "
                           "te das cuenta de que está algo ocupad"+AO+".\n");
#ifdef FIGHTING_YOU_ROOM_MSG
            message_room = TO->Query(P_FIGHTING_ROOM_MSG)?
              capitalize(mix->QueryName()) + " " + TO->Query(P_FIGHTING_ROOM_MSG):
              W("Cuando " + capitalize(mix->QueryName()) + " va a " +
              "hablar con " + KeeperName(K_CAP) + ", se da cuenta de que está un " +
              "poco ocupad" + AO + ".\n");
#endif
        }
    }
    if (!message) return 0;
#ifdef FIGHTING_YOU_ROOM_MSG
    if (fail == K_NOTIFY)
    {
        notify_fail((message_room?funcall((:tell_object(TP,$1);
              Emote($2);:),message,message_room):message));
    }
#else
    if (fail == K_NOTIFY) notify_fail(message);
#endif
    return message;
}

public varargs int CheckMoney(mixed mix, int coste)
// si se pasa como primer parámetro un int, se considera
// que el objeto es this_player y se evalúa el coste pasado como 1er parametro
// si se da ambos parámetros, el primero es el objeto, y el segundo, el coste.
{
    return    MONEY_LIB->QuerySomeonesValue(objectp(mix)?mix:TP)
           >= (intp(mix)?mix:coste);
}

public varargs int Pay(mixed arg1, mixed arg2, mixed arg3)
// función para pagar dinero
// se pasan como parámetros el objeto del que se va a descontar el dinero,
// la cantidad a pagar, y un mensaje extra que quieras que aparezca.
// de la forma: Pagas 3 monedas de oro 'mensaje extra'...
// el orden no importa, aunque es recomendable utilizar: objeto, cantidad,
// mensaje_extra.

{
    object who;
    int value;
    string extramsg, *result;

    who =    (objectp(arg1) && arg1)
          || (objectp(arg2) && arg2)
          || (objectp(arg3) && arg3)
          || TP;
    value =    (intp(arg1) && arg1)
            || (intp(arg2) && arg2)
            || (intp(arg3) && arg3);
    extramsg =    (stringp(arg1) && arg1)
               || (stringp(arg2) && arg2)
               || (stringp(arg3) && arg3);

    if (!who || !value) return 0;

    result = MONEY_LIB->PayValueString2(  who, value, 0, extramsg
                                        , who->QueryConsoleWidth());

    if (pointerp(result))
    {
        tell_object(who, result[0]);
        Emote(result[1], who);
        return 1;
    }
    return 0;
}


