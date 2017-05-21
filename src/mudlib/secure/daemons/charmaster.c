/**
 * /secure/obj/charmaster.c
 */

#include <wizlevels.h>
#include <colours.h>
#include <characters.h>
#include <files.h>
#include <input_to.h>

#define BAN_OBJECTS ({SECUREBINPATH "_nicks", "/bin/wiz/_kick"})
// objetos que pueden banear


private int pValidatorEnabled; // el validador de nicks activado o desactivado

public int SetValidatorEnabled(int i)
{
    pValidatorEnabled = i;
    save_object(CHARACTERSLOGPATH "data");
    return pValidatorEnabled;
}
public int QueryValidatorEnabled()
{
    restore_object(CHARACTERSLOGPATH "data");
    return pValidatorEnabled;
}




// ----------------------------------------------------------------------------

// Baneo y desbaneo de nombres

public varargs mixed QueryBanishedName(string name, int info)
// devuelve el estado de un nick con respecto a si está o no baneado.
// si se le pasa info, devolverá un array, en el que el primer elemento es el estado, y el
// segundo el array del registro de la tabla de la base de datos.
{
    mixed *res;
    if (!name || !strlen(name)) return NICK_UNBANISHED;
    name = LOWER(name);
    DBMASTER->Exec("select * from banished_names where name='" + db_conv_string(name) + "'");
    if (!sizeof(res = DBMASTER->Fetch())) return (info == CH_INFO ? ({NICK_UNBANISHED}) : NICK_UNBANISHED);
    res[N_BAN_ID] = to_int(res[N_BAN_ID]);
    res[N_BAN_NAME] = to_string(res[N_BAN_NAME]);
    res[N_BAN_DATE] = to_int(res[N_BAN_DATE]);
    res[N_BAN_REASON] = to_string(res[N_BAN_REASON]);
    res[N_BAN_UNTIL] = to_int(res[N_BAN_UNTIL]);

    if (res[N_BAN_UNTIL] && res[N_BAN_UNTIL] < time())
    // está baneado, pero ya es hora de desbanearlo
    {
        log_file(CHARACTERSLOGPATH "info", sprintf("%-78=s",
                 ctime() + ": Se desbanea automáticamente a " + res[N_BAN_NAME] + " al "
                 "expirar el plazo definido para este baneo (" +
                 STR->etime(0, ctime(res[N_BAN_UNTIL])) + ").\n"));
        DBMASTER->Exec("delete from banished_names where name='" + db_conv_string(name) + "'");
        return (info == CH_INFO ? ({NICK_UNBANISHED}) : NICK_UNBANISHED);
    }
    return (info == CH_INFO ? ({NICK_BANISHED, res}) : NICK_BANISHED);
}

public int BanName(string name, string reason, int until)
// banea a un jugador hasta una fecha determinada, o indefinidamente, si until es 0.
{
    mixed res;
    object ob;

    if (!name || !strlen(name) || !reason || !strlen(reason))
    {
        return notify_fail("Debes introducir tanto el nombre a banear como la razón del baneo.\n",
                           NOTIFY_NOT_VALID);
    }

    name = LOWER(name);
    if (!LOGIN->valid_name(name))
    {
        return notify_fail("Nombre no válido.\n",
                           NOTIFY_NOT_VALID);
    }
    if (!MASTER->find_userinfo(name))
    {
        return notify_fail("Ese jugador no existe en Simauria.\n", NOTIFY_NOT_VALID);
    }

    if (!IS_ARCH(TP) && member(BAN_OBJECTS, object_name(PO || TP)) < 0)
    {
        log_file(CHARACTERSLOGPATH "illegal",
                 ctime() + ". " + TNREAL + " intentó banear a " + name + ".\n\n");
        return notify_fail("No tienes permiso para banear o desbanear personajes.\n");
    }
    
    
    if ((res = QueryBanishedName(name, CH_INFO))[CH_STATUS] == NICK_BANISHED)
    // ya está baneado. Actualizamos la fecha
    {
        if (until && until < time())
        // el plazo es menor que la fecha actual
        {
            return notify_fail("El plazo para desbanear a este personaje es inferior a la fecha "
                               "actual.\n", NOTIFY_NOT_VALID);
        }

        // actualizamos la fecha de este baneo
        if (until == to_int(res[CH_INFO][N_BAN_UNTIL]))
        // no hay cambios en until, así que no se hace nada
        {
            return notify_fail("El plazo de baneo introducido es igual que el establecido con "
                               "anterioridad. No se realizaron cambios.\n", NOTIFY_NOT_VALID);
        }

        if (TP)
        {
            tell_object(TP, "Actualizando el plazo del baneo para " + CAP(name) + ". "
                            "Nuevo plazo: " + (!until ? "indefinido" : STR->etime(1, ctime(until))) +
                            ".\n");
        }
        DBMASTER->Exec("update banished_names set wizard='" + db_conv_string(getuid(TP || PO)) + "', "
                       "reason='" + db_conv_string(reason) + "', "
                       "timestamp=" + time() + ", "
                       "until=" + until + " where name='" +
                       db_conv_string(name) + "'");
        log_file(CHARACTERSLOGPATH "info", sprintf("%-78=s",
                 ctime() + ": " + CAP(getuid(TP || PO)) + " modificó el plazo de desbaneo para el "
                 "jugador " + CAP(name) + ". Nuevo plazo: " +
                 (!until ? "indefinido" : STR->etime(0, ctime(until))) + ".\n"));
        return 1;
    }

    // no está baneado, así que lo baneamos
    if (until && until < time())
    {
        return notify_fail("El plazo para desbanear a este personaje es inferior a la fecha "
                           "actual.\n", NOTIFY_NOT_VALID);
    }
    DBMASTER->Exec("insert into banished_names values(default, '" + db_conv_string(name) + "', '" +
                   db_conv_string(getuid(TP || PO)) + "', " + time() + ", '" + db_conv_string(reason) +
                   "', " + until + ")");
    log_file(CHARACTERSLOGPATH "info", sprintf("%-78=s",
             ctime() + ": " + CAP(getuid(TP || PO)) + " baneó a " + CAP(name) +
             (!until ? " por tiempo indefinido" : " hasta el " + STR->etime(0, ctime(until))) +
             ". Razón: " + reason + ".\n"));
    if (ob = find_object(name))
    {
        tell_object(ob, TC_RED + "¡atención! ¡Tu personaje ha sido baneado " +
                        (!until ? "por tiempo indeterminado" : "hasta el " + STR->etime(1, ctime(until))) +
                        ". En caso de duda, contacta con un vala.\n" + TC_NORMAL);
    }
    if (TP)
    {
        tell_object(TP, "Has baneado a " + CAP(name) + " " +
                        (!until ? "por tienpo indefinido" :
                         "hasta el " + STR->etime(1, ctime(until))) + ".\n");
    }
    return 1;
}


public int UnbanName(string name)
// desbanea al nombre <name>
{
    if (!name || !strlen(name))
    {
        return notify_fail("Debes introducir el nombre del jugador a desbanear.\n",
                           NOTIFY_NOT_VALID);
    }

    name = LOWER(name);
    if (!LOGIN->valid_name(name))
    {
        return notify_fail("Nombre no válido.\n", NOTIFY_NOT_VALID);
    }
    if (QueryBanishedName(name) == NICK_UNBANISHED)
    {
        return notify_fail("Este jugador no estaba baneado.\n",
                           NOTIFY_NOT_VALID);
    }
    
    if (!IS_ARCH(TP) && member(BAN_OBJECTS, object_name(PO || TP)) < 0)
    {
        log_file(CHARACTERSLOGPATH "illegal",
                 ctime() + ". " + TNREAL + " intentó banear a " + name + ".\n\n");
        return notify_fail("No tienes permiso para banear o desbanear personajes.\n");
    }
    
    // lo desbaneamos
    DBMASTER->Exec("delete from banished_names where name='" + db_conv_string(name) + "'");
    log_file(CHARACTERSLOGPATH "info", sprintf("%-78=s",
             ctime() + ": " + CAP(getuid(TP || PO)) + " ha desbaneado a " + CAP(name) + ".\n"));
    if (TP)
    {
        tell_object(TP, "Has desbaneado a " + CAP(name) + ".\n");
    }
    return 1;
}

// ----------------------------------------------------------------------------

// Baneo y desbaneo de e-mails

public varargs mixed QueryBanishedEmail(string email, int info)
// devuelve el estado de un e-mail con respecto a si está o no baneado.
// si se le pasa info, devolverá un array, en el que el primer elemento es el estado, y el
// segundo el array del registro de la tabla de la base de datos.
{
    mixed *res;
    if (!email || !strlen(email)) return EMAIL_UNBANISHED;
    email = LOWER(email);
    DBMASTER->Exec("select * from banished_emails where email='" + db_conv_string(email) + "'");
    if (!sizeof(res = DBMASTER->Fetch())) return (info == CH_INFO ? ({EMAIL_UNBANISHED}) : EMAIL_UNBANISHED);
    res[E_BAN_ID] = to_int(res[E_BAN_ID]);
    res[E_BAN_EMAIL] = to_string(res[E_BAN_EMAIL]);
    res[E_BAN_DATE] = to_int(res[E_BAN_DATE]);
    res[E_BAN_REASON] = to_string(res[E_BAN_REASON]);
    res[E_BAN_UNTIL] = to_int(res[E_BAN_UNTIL]);

    if (res[E_BAN_UNTIL] && res[E_BAN_UNTIL] < time())
    // está baneado, pero ya es hora de desbanearlo
    {
        log_file(CHARACTERSLOGPATH "info", sprintf("%-78=s",
                 ctime() + ": Se desbanea automáticamente la dirección " + res[E_BAN_EMAIL] + " al "
                 "expirar el plazo definido para este baneo (" +
                 STR->etime(0, ctime(res[E_BAN_UNTIL])) + ").\n"));
        DBMASTER->Exec("delete from banished_emails where email='" + db_conv_string(email) + "'");
        return (info == CH_INFO ? ({EMAIL_UNBANISHED}) : EMAIL_UNBANISHED);
    }
    return (info == CH_INFO ? ({EMAIL_BANISHED, res}) : EMAIL_BANISHED);
}

public int BanEmail(string email, string reason, int until)
// banea una dirección de correo electrónico hasta una fecha determinada, o indefinidamente, si until es 0.
{
    mixed res;
    object ob;

    if (!email || !strlen(email) || !reason || !strlen(reason))
    {
        return notify_fail("Debes introducir tanto el e-mail a banear como la razón del baneo.\n",
                           NOTIFY_NOT_VALID);
    }

    email = LOWER(email);
    if (LOGIN->valid_email(email) <= 0)
    {
        return notify_fail("email no válido.\n",
                           NOTIFY_NOT_VALID);
    }
    if (!IS_ARCH(TP) && member(BAN_OBJECTS, object_name(PO || TP)) < 0)
    {
        log_file(CHARACTERSLOGPATH "illegal",
                 ctime() + ". " + TNREAL + " intentó banear la dirección " + email + ".\n\n");
        return notify_fail("No tienes permiso para banear o desbanear e-mails.\n");
    }
    
    
    if ((res = QueryBanishedEmail(email, CH_INFO))[CH_STATUS] == NICK_BANISHED)
    // ya está baneado. Actualizamos la fecha
    {
        if (until && until < time())
        // el plazo es menor que la fecha actual
        {
            return notify_fail("El plazo para desbanear este e-mail es inferior a la fecha "
                               "actual.\n", NOTIFY_NOT_VALID);
        }

        // actualizamos la fecha de este baneo
        if (until == to_int(res[CH_INFO][E_BAN_UNTIL]))
        // no hay cambios en until, así que no se hace nada
        {
            return notify_fail("El plazo de baneo introducido es igual que el establecido con "
                               "anterioridad. No se realizaron cambios.\n", NOTIFY_NOT_VALID);
        }

        if (TP)
        {
            tell_object(TP, "Actualizando el plazo del baneo para la dirección " + email + ". "
                            "Nuevo plazo: " + (!until ? "indefinido" : STR->etime(1, ctime(until))) +
                            ".\n");
        }
        DBMASTER->Exec("update banished_emails set wizard='" + db_conv_string(getuid(TP || PO)) + "', "
                       "reason='" + db_conv_string(reason) + "', "
                       "timestamp=" + time() + ", "
                       "until=" + until + " where email='" +
                       db_conv_string(email) + "'");
        log_file(CHARACTERSLOGPATH "info", sprintf("%-78=s",
                 ctime() + ": " + CAP(getuid(TP || PO)) + " modificó el plazo de desbaneo para la "
                 "dirección de correo " + email + ". Nuevo plazo: " +
                 (!until ? "indefinido" : STR->etime(0, ctime(until))) + ".\n"));
        return 1;
    }

    // no está baneado, así que lo baneamos
    if (until && until < time())
    {
        return notify_fail("El plazo para desbanear este e-mail es inferior a la fecha "
                           "actual.\n", NOTIFY_NOT_VALID);
    }
    DBMASTER->Exec("insert into banished_emails values(default, '" + db_conv_string(email) + "', '" +
                   db_conv_string(getuid(TP || PO)) + "', " + time() + ", '" + db_conv_string(reason) +
                   "', " + until + ")");
    log_file(CHARACTERSLOGPATH "info", sprintf("%-78=s",
             ctime() + ": " + CAP(getuid(TP || PO)) + " baneó el e-mail " + email +
             (!until ? " por tiempo indefinido" : " hasta el " + STR->etime(0, ctime(until))) +
             ". Razón: " + reason + ".\n"));
    if (TP)
    {
        tell_object(TP, "Has baneado el e-mail " + email + " " +
                        (!until ? "por tienpo indefinido" :
                         "hasta el " + STR->etime(1, ctime(until))) + ".\n");
    }
    return 1;
}


public int UnbanEmail(string email)
// desbanea el e-mail <email>
{
    if (!email || !strlen(email))
    {
        return notify_fail("Debes introducir el nombre del jugador a desbanear.\n",
                           NOTIFY_NOT_VALID);
    }

    email = LOWER(email);
    if (!LOGIN->valid_email(email))
    {
        return notify_fail("E-mail no válido.\n", NOTIFY_NOT_VALID);
    }
    if (QueryBanishedEmail(email) == EMAIL_UNBANISHED)
    {
        return notify_fail("Este e-mail no estaba baneado.\n",
                           NOTIFY_NOT_VALID);
    }
    
    if (!IS_ARCH(TP) && member(BAN_OBJECTS, object_name(PO || TP)) < 0)
    {
        log_file(CHARACTERSLOGPATH "illegal",
                 ctime() + ". " + TNREAL + " intentó banear el e-mail " + email + ".\n\n");
        return notify_fail("No tienes permiso para banear o desbanear e-mails.\n");
    }
    
    // lo desbaneamos
    DBMASTER->Exec("delete from banished_emails where email='" + db_conv_string(email) + "'");
    log_file(CHARACTERSLOGPATH "info", sprintf("%-78=s",
             ctime() + ": " + CAP(getuid(TP || PO)) + " ha desbaneado a " + email + ".\n"));
    if (TP)
    {
        tell_object(TP, "Has desbaneado el e-mail " + email + ".\n");
    }
    return 1;
}

// ----------------------------------------------------------------------------


// Aceptar y rechazar nombres

public varargs mixed QueryValidName(string name, int info, int force_check)
// el estado de un nick
//  si info está a 1, devolverá un array. El primer elemento es el estado del nick,
// y el segundo el resultado de la consulta sql
// si pValidatorEnabled está en false, todos los nombres se considerarán válidos,
// escepto que force_check esté a 1.
// Cualquier vala también se considerará válido, escepto si force_check está a 1.
{
    mixed *res;
    int mode;
    if (!name || !strlen(name)) return NICK_UNKNOWN;
    if (!force_check && (!pValidatorEnabled || query_wiz_level(name))) return (info == CH_INFO ? ({NICK_VALID ,0}) : NICK_VALID);
    name = LOWER(name);

    DBMASTER->Exec("select * from valid_names where name='" + db_conv_string(name) + "'");
    if (sizeof(res = DBMASTER->Fetch()))
    {
        return (info == CH_INFO ? ({to_int(res[N_MODE]), res}) : to_int(res[N_MODE]));
    }
    return (info == CH_INFO ? ({NICK_UNKNOWN}) : NICK_UNKNOWN);
}


public int AcceptName(string name)
// acepta el nombre <name>
{
    object ob;
    int st;

    if (!name ||!strlen(name))
    {
        return notify_fail("No has introducido el nombre del jugador a aceptar.\n", NOTIFY_NOT_VALID);
    }

    name = LOWER(name);

    if (query_wiz_level(getuid(TP)) && getuid(TP) != name && query_wiz_level(name) >= query_wiz_level(getuid(TP ||PO)))
    {
        return notify_fail("No puedes aceptar nombres de valar de nivel igual o superior a ti.\n",
                           NOTIFY_NOT_VALID);
    }

    if ((st = QueryValidName(name, CH_STATUS, CH_FORCE_CHECK)) == NICK_VALID)
    {
        return notify_fail("Este jugador ya estaba validado.\n", NOTIFY_NOT_VALID);
    }
    if (st != NICK_UNKNOWN)
    {
        DBMASTER->Exec("update valid_names set wizard='" + db_conv_string(getuid(TP || PO)) +
                       "', reason=default, timestamp=" + time() + ", mode=" + NICK_VALID +
                       " where name='" + db_conv_string(name) + "'");
    }
    else
    {
        DBMASTER->Exec("insert into valid_names values(default, '" + db_conv_string(name) + "', '" +
                       db_conv_string(getuid(TP || PO)) + "', " + time() + ", " + NICK_VALID + ", default)");
    }
    if (ob = find_object(name))
    {
        tell_object(ob, TC_RED + "El nombre que has elegido está en consonancia con la ambientación "
        "de Endor y ha sido aceptado por los Valar.\n"
                        "¡Que Eru te guíe y te guarde a lo largo de las aventuras que te "
                        "esperan en la Tierra Media!\n" +
                        TC_NORMAL);
    }
    log_file(CHARACTERSLOGPATH "info",
             sprintf("%-78=s", ctime() + ": " + CAP(getuid(TP || PO)) + " aceptó el nick '" + name + "'.\n"));
    return 1;
}

public int RejectName(string name, string reason)
// rechaza el nombre <name>
{
    object ob;
    mixed st;

    if (!name || !strlen(name) ||!reason || !strlen(reason))
    {
        return notify_fail("Debes introducir tanto el nombre como la razón del rechazo "
                           "de este nombre.\n", NOTIFY_NOT_VALID);
    }

    name = LOWER(name);
    if (name == getuid(TP ||PO))
    {
        return notify_fail("¡No puedes rechazar tu propio nombre!\n",
                           NOTIFY_NOT_VALID);
    }

    if (query_wiz_level(name) >= query_wiz_level(getuid(TP ||PO)))
    {
        return notify_fail("No puedes rechazar nombres de valar de igual o nivel superior a ti.\n",
                           NOTIFY_NOT_VALID);
    }

    if ((st = QueryValidName(name, CH_INFO, CH_FORCE_CHECK))[CH_STATUS] == NICK_INVALID)
    {
        return notify_fail("Este nombre ya estaba rechazado.\n",
                           NOTIFY_NOT_VALID);
    }

    if (st[CH_STATUS] == NICK_VALID)
    // estaba aceptado
    {
        if (!sizeof(st[CH_INFO])) return 0;
        write("¡Atención! Ese nombre había sido aceptado por " + CAP(st[CH_INFO][N_WIZ]) +
              ", con fecha " + STR->etime(0, ctime(to_int(st[CH_INFO][N_DATE]))) + ".\n");
        if (!IS_ARCH(getuid(TP || PO)))
        // un wiz inferior a arch no puede rechazar nombres previamente aceptados
        {
            return notify_fail("No tienes permiso para rechazar nombres ya aceptados.\n",
                               NOTIFY_NOT_VALID);
        }
    }
    if (st != NICK_UNKNOWN)
    {
        DBMASTER->Exec("update valid_names set wizard='" + db_conv_string(getuid(TP || PO)) + "', "
                       "timestamp=" + time() + ", reason='" + db_conv_string(reason) + "', "
                       "mode=" + NICK_INVALID + " where name='" + db_conv_string(name) + "'");
    }
    else
    {
        DBMASTER->Exec("insert into rejected_names values(default, '" + db_conv_string(name) + "', '" +
                       db_conv_string(getuid(TP || PO)) + "', " + time() + ", '" + db_conv_string(reason) +
                       "')");
    }
    if (ob = find_object(name))
    // el jugador al que se rechaza está conectado
    {
        tell_object(ob, TC_RED + "El nombre que has elegido no está en consonancia con "
        "la ambientación de Endor y deberás escoger uno distinto.\n"
        "Escribe 'ayuda nombres' o contacta con un vala para más información.\n"
        "Esta ficha será borrada en cuanto salgas del juego.\n\n" + TC_NORMAL);
        ob->SetValidName(0);
    }
    log_file(CHARACTERSLOGPATH "info",
             sprintf("%-78=s", ctime() + ": " +
                    CAP(getuid(TP || PO)) + " rechazó el nick '" + name + "', alegando la siguiente razón: " +
                    "'" + reason + "'.\n"));
    return 1;
}

// ----------------------------------------------------------------------------

// Nombres pendientes

public int AddPendingName(string name)
{
    if (!name || !strlen(name)) return 0;
    if (QueryValidName(name, CH_STATUS, CH_FORCE_CHECK) != NICK_UNKNOWN) return 0;
    // solo los nicks que no estaban en la bd se pueden añadir como pendientes
    DBMASTER->Exec("insert into valid_names values(default, '" + db_conv_string(name) + "', '" +
                   db_conv_string(getuid(TP || PO)) + "', " + time() + ", " + NICK_PENDING +
                   ", default)");
    send_server_request("SendAdmin", 0, "Nuevo personaje pendiente de validar",
                        "¡Hola!\nHay un nuevo personaje para ser validado. El nombre es: " +
                        name + ".\nEntra a simauria para completar la validación.\n"
                        "Saludos,\nCharmaster.\n");
    return 1;
}


public int RemoveName(string name)
// borra un nombre de la base de datos de validados
{
    if (!name || !strlen(name)) return 0;
    DBMASTER->Exec("delete from valid_names where name='" + db_conv_string(name) + "'");
    return DBMASTER->AffectedRows();
}


public mixed *QueryPendingNames()
{
    mixed *res= ({}), *res_bd;
    int i;
    DBMASTER->Exec("select name from valid_names where mode=" + NICK_PENDING);
    while(sizeof(res_bd = DBMASTER->Fetch()) && ++i <= 3001)
    {
        res += res_bd;
    }
    return res;
}

public int CheckPendingNames(int prompt)
// si prompt está a 1, usa el INPUT_PROMPT para enviar la info
{
    mixed res;
    if (!sizeof(res = QueryPendingNames()))
    {
        return notify_fail("No hay nombres pendientes de validar.\n");
    }

    if (!prompt)
    {
        write("¡Atención! Hay " + sizeof(res) + " nombres pendientes de validar. "
              "¿Deseas hacerlo ahora? Pulsa s, o n.\n");
        input_to("_check_pending_names", 0, res);
    }
    else
    {
        input_to("_check_pending_names", INPUT_PROMPT,
                 "¡Atención! Hay " + sizeof(res) + " nombres pendientes de validar. "
              "¿Deseas hacerlo ahora? Pulsa s, o n.\n", res);
    }
    return 1;
}



public varargs void _check_pending_names(string str, mixed *res, int primera)
{
    if (!TP || !query_wiz_level(TP)) return;
    if (!str ||str == "" ||member(({"s", "si", "sí", "n", "no"}), str) < 0)
    {
        input_to("_check_pending_names", INPUT_PROMPT,
                 "Debes pulsar s o n.\n¿Deseas validar los nombres pendientes ahora? "
                 "Escribe s, o n.\n", res);
        return;
    }
    if (str == "n" ||str == "no")
    {
        write("De acuerdo, ¡pero no olvides hacerlo pronto!\n");
        return;
    }
    input_to("_check_pending_names2", INPUT_PROMPT,
             "Nombre: " + CAP(res[0]) + ". Pulsa s para aceptarlo, n para rechazarlo, p para "
             "prorrogar la decisión, o c para cancelar el proceso de validación.\n", res);
}

private void _next_name(mixed *res)
{
    if (!sizeof(res)) return;
    res -= res[0..0];
    if (!sizeof(res))
    // fin de las validaciones
    {
        write("¡Fin de la confirmación de nombres! ¡Saliendo!\n");
        return;
    }
    input_to("_check_pending_names2", INPUT_PROMPT,
             "Siguiente nombre: " + CAP(res[0]) + ". Pulsa s para validar, n para "
             "rechazar, p para prorrogar la decisión, o c para cancelar el proceso "
             "de validación.\n", res);
}


public void _check_pending_names2(string str, mixed *res)
{
    if (!str || ((str = LOWER(str)) == "") || member(({"s", "si", "sí", "n", "no", "c", "p"}), str) < 0)
    {
        input_to("_check_pending_names2", INPUT_PROMPT,
                 "Debes pulsar s, n, p o c.\nNombre: " + CAP(res[0]) + ". Pulsa "
                 "s para aceptarlo, n para rechazarlo, p para prorrogarlo, o c para cancelar "
                 "el proceso de validación.\n", res);
        return;
    }
    if (str == "s" || str == "si" || str == "sí")
    {
        write("Validando " + CAP(res[0]) + ".\n");
        if (!AcceptName(res[0]))
        {
            write("Error al validar.\n");
        }
        else
        {
            write("OK.\n");
        }
        return _next_name(res);
    }
    else if (str == "p")
    // prorrogamos la decisión
    {
        write("Se prorroga la decisión sobre este nombre.\n");
        return _next_name(res);
    }
    else if (str == "c")
    {
        write("Cancelando el proceso de validación.\n");
        return;
    }
    else if(str == "no" ||str == "n")
    {
        input_to("_check_pending_names3", INPUT_PROMPT,
                 "Dame una razón para ello, o pulsa c para cancelar el proceso de validación.\n",
                 res);
        return;
    }
}


public void _check_pending_names3(string str, mixed *res)
{
    if (!str || str == "")
    {
        input_to("check_pending_names3", INPUT_PROMPT,
                 "No me has dado ninguna razón. Dame una razón para rechazar este nombre, o "
                 "pulsa c para cancelar el proceso de validación.\n", res);
    }
    if (str == "c")
    {
        write("Cancelando el proceso de validación. Saliendo.\n");
    }
    else
    {
        write("Rechazando el nombre '" + CAP(res[0]) + "'.\n");
        if (!RejectName(res[0], str))
        {
            write("Error al rechazar el nombre '" + CAP(res[0]) + "'.\n");
        }
        else
        {
            write("Nombre rechazado.\n");
        }
        _next_name(res);
        return;
    }
}

// ----------------------------------------------------------------------------


create()
{
    restore_object(CHARACTERSLOGPATH "data");
}
