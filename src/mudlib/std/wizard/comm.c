/**
 * SIMAURIA /std/wizard/comm.c
 */

#include <prompt.h>
#include <colours.h>
#include <wizlevels.h>
#include <properties.h>

#include UDP_HEADER

inherit "/std/player/comm";

//-----------------------------------------------------------------------------

public string WizPrompt() {
      return TC_BOLD TC_BLUE + TO->QueryCurrentDir() + TC_NORMAL + "> ";
}

public int SetPrompt(int to) {
    switch(to) {
        case PR_WIZ_PROMPT:
            set_prompt(SF(WizPrompt), TO);
            break;
        default:
    }
    return ::SetPrompt(to, TO);
}

//-----------------------------------------------------------------------------

public int _rtell(string str) {
    object room;
    string a,b;
    if (!IS_LEARNER(TP)) return 0;
    if (!str) str = "yo nada";
    if (sscanf(str, "%s %s", a, b)!=2) { write("¿rtel dónde qué?\n"); return 1; }
    if (!(room=find_object(a))) { write("¡No existe esa habitación!\n"); return 1; }
    tell_room(room, Query(P_NAME)+" dice desde algún lugar: "+b+"\n");
    write("OK.\n");
    return 1;
}

public int _etell(string str) {
    string a,b;
    object who;
    if (!IS_LEARNER(TP)) return 0;
    if (!str) str="yo nada";
    if (sscanf(str,"%s %s",a,b)!=2) { write("¿etel quien que?\n"); return 1; }
    if (!(who=find_object(lower_case(a)))) { write("No hay nadie con ese nombre.\n"); return 1; }
    write("Ok.\n");
    tell_room(environment(who), "Escuchas una voz lejana que dice: "+b+"\n");
    return 1;
}

public int _echo(string str) {
    object *whos;
    int i;

    if (!sizeof(str)) {
        say("Se oye un leve y miserable eco.\n");
        echo_txt("Intentas decir algo pero nada sale de tu boca...\n");
        return(1);
    }
    if (str[0..1]=="a ") {
        if (str[2..6]=="todos") {
            if (str[8..] == "") {
              return notify_fail("No gritas nada...\n");
            }
            whos=users();
            for (i=0; i<sizeof(whos); i++) {
                if (whos[i] == TO)
                  write("Gritas a los cuatro vientos: "+str[8..]+"\n");
                else      // [K] Anyado la comprobacion de niveles.
                   if(query_wiz_level(whos[i]) > query_wiz_level(TO))
                      _tell_ear(whos[i],
                            "Eco de "+TO->QueryName()+": "+str[8..]+"\n","echoall");
                   else
                     _tell_ear(whos[i], str[8..]+"\n", "echoall");
            }
            return(1);
        }
          //return(_xshout(str[8..]));
        else return (int)(_echoto(str[2..]));
    }
    say(str+"\n");
    echo_txt("Eco: "+str+"\n");
    return 1;
}
/* arg 0:echoall 1:pecho 2:wecho */
public int _xshout(string str) {
    object *whos, who;
    int i, mylev, hislev, how;
    string ostr;

    if (!sizeof(str)) {
      return notify_fail(capitalize(query_verb())+" que?\n");
    }
    how = member ( ({ "eco_todos", "jeco", "weco" }), query_verb());
    if (how < 0) return 0;
    // if (QuerySP() < 1) { write("No tienes suficientes energias.\n"); return 1; }
    // if (!IS_LEARNER(TP)) SetSP(QuerySP()-30);
    ostr = str;
    if (Query(P_FROG)) str = "Crooaakkk Croooaakk";
    whos = users();
    mylev = TO->QueryLevel();
    for (i = 0; i < sizeof(whos); i++) {
        if ((who = whos[i]) == TO) {
            string tmp;
            tmp = "";
            switch(how) {
                case 0: tmp += "Eco a todos: "; break;
                case 1: tmp += "Eco a jugadores: "; break;
                case 2: tmp += "Eco a wizs: "; break;
            }
            echo_txt((tmp+ostr+"\n"));
            continue;
        }
        if ((hislev = (int)who->QueryEarmuffs()) && mylev <= hislev) continue;
        switch (how) {
            case 0: _tell_ear(who, str+"\n", "echoall"); break;
            case 1: if (!IS_WIZARD(who)) _tell_ear(who, str+"\n", "pecho"); break;
            case 2: if (IS_WIZARD(who)) _tell_ear(who, str+"\n", "wecho"); break;
        }
    }
    return 1;
}

public int _rwho(string str) {
    string u;
    string msg;

    if (!sizeof(str) || str == "?") {
        return notify_fail("Uso: rquien <nombre_mud>|estado\n");
    }
    if (str == "estado") return (int)_rpeers();
    if (stringp(u = geteuid(TO))) {
        if (msg = INETD->send_udp(str,
            ([ REQUEST: "who", SENDER: TP->QueryRealName() ]), 1))
        {
            write(msg);
        }
        else write("Petición enviada.\n");
    }
    return 1;
}

static add_comm_commands() {
    ::add_comm_commands();
    add_action("_rtell", "rtel");
    add_action("_etell", "etel");
    add_action("_echo", "eco");
    add_action("_xshout", "jeco");
    add_action("_xshout", "weco");
    add_action("_rwho", "rquien");
}

//-----------------------------------------------------------------------------
