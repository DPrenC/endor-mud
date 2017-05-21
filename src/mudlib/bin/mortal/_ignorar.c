// Comando ignorar

#include <wizlevels.h>
#include <sounds.h>

public int main(string arg) {
    string name, name2, *rc;
    int    zeit;
    int    i;
    mapping ignoredNames;

    if (arg == "?") { // Le pongo la ayuda
      return notify_fail(
          "Ignorar <quien> [minutos | siempre] .. Ignoras a alguien durante un tiempo.\n"
          "Ignorar gritos ....................... Ignoras todos los gritos.\n"
          "Ignorar a todos ...................... Ignoras a todos, incluidos los gritos.\n");
    }

    ignoredNames = TP->QueryIgnored() || ([]);

    if (!sizeof(arg)) { // listo los ignorados
        string *ix;

        if (TP->QueryIgnoreAll()) {
            write("Estás ignorando a todos.\n");
            write("Escribe '"+query_verb()+" ?' para obtener más informacion\n");
            return 1;
        }
        if (!sizeof(ignoredNames))
        {
            write("No estás ignorando a nadie.\n");
            return 1;
        }


        ix = m_indices(ignoredNames);
        rc = ({});
        for (i = sizeof(ix); i-- ; ) {
            zeit = ignoredNames[ix[i]];
            if (zeit > 0 && time()-zeit > 0)
                ignoredNames = m_delete(ignoredNames, ix[i]);
            else {
                name = capitalize(ix[i]);
                rc += ({name+": "
                      +(zeit >= 0 ? to_string((zeit+30-time())/60)+" min" : "siempre")
                     });
            }
        }

        if (!sizeof(rc)) {
            if (TP->QueryEarmuffs()) write("Estás ignorando los gritos.\n");
            else write("Escuchas a todos.\n");
        }
        else
        {
            write("Estás ignorando a:\n"+sprintf("%75#s\n", implode(rc, "\n")));
            if (TP->QueryEarmuffs()) write("También estás ignorando los gritos.\n");
        }
        write("Escribe '"+query_verb()+" ?' para obtener más informacion\n");
        return 1;
    }

// Quiero ignorar a alguien nuevo, alla vamos
    notify_fail(
        "Ignorar <quien> [minutos | siempre] .... Ignora a alguien durante un tiempo.\n"
        "Ignorar gritos ......................... Ignora todos los gritos.\n"
        "Ignorar a todos ........................ Ignora a todos, incluidos los gritos.\n");
    if (arg == "a todos") {
        if (!TP->QueryIgnoreAll()) {
            TP->SetIgnoreAll(1);
            write("Ignorando a todos por tiempo indefinido.\n");
            play_sound(TP, SND_CANALES("ignorar"));
            return 1;
        }
        else return notify_fail("Ya estás ignorando a todos.\n");
    }

    rc = explode(arg, " ");
    if (sizeof(rc) < 2) rc += ({ "60" });
    if (sizeof(rc) > 2) return 0;
    name = lower_case(rc[0]);
    zeit = -1;
    if (name =="gritos") {
        if (TP->QueryEarmuffs() || TP->QueryIgnoreAll()) {
            write("Ya estabas ignorando los gritos.\n");
            return 1;
        }
        write("A partir de ahora no oirás ningún grito.\n");
        TP->SetEarmuffs(1);
        play_sound(TP, SND_CANALES("ignorar"));
        return 1;
    }

    if (lower_case(rc[1]) != "siempre" && (zeit = to_int(rc[1])) < 1) {
        return 0;
    }
    if (!MASTER->find_userinfo(name))
    {
        return notify_fail(CAP(name) + " no existe en Simauria.\n");
    }

    
    name2 = capitalize(name);

    if (IS_LEARNER(name) || name == geteuid(TO))
        write ("No puedes ignorar a "+name2+".\n");
    else {
        int reignorar;
        if (reignorar = member(ignoredNames, name))
        {
            write("Ya estabas ignorando a " + name2 + ". Cambiando la duración del ignorar.\n");
        }
        if (zeit > 0) {
            write("Ignorando a "+capitalize(name)+" durante "+zeit+" minutos " + (reignorar ? " más" : "") + ".\n");
            TP->AddIgnored(name, time() + 60 * zeit);
            play_sound(TP, SND_CANALES("ignorar"));
        }
        else {
            write("Ignorando a "+name2+" por tiempo indefinido.\n");
            TP->AddIgnored(name, -1);
            play_sound(TP, SND_CANALES("ignorar"));
        }
    }
    return 1;

}