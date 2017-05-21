// Comando designorar

#include <wizlevels.h>
#include <sounds.h>

public int main(string arg) {
    string name, name2, *rc;
    int    zeit;
    int    i;


    if (arg == "?") {
        return notify_fail(
            "Designorar <quien> ................... Dejas de ignorar a alguien.\n"
            "Ahora podr�s escuchar los gritos.\n"
            "Ahora podr�s recibir los mensajes de telepat�a o canal y ver los "
            "sociales de todos los jugadores.\n");
    }

    if (!sizeof(arg)) { // listo los ignorados
        mapping ignoredNames = TP->QueryIgnored();
        string *ix;

        if (TP->QueryIgnoreAll()) {
            write("Actualmente, est�s ignorando a todos los jugadores de Endor.\n");
            write("Escribe '"+query_verb()+" ?' para obtener m�s informacion\n");
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
            if (TP->QueryEarmuffs()) write("Actualmente, est�s ignorando los gritos y no te es posible escucharlos.\n");
            else write("Puedes escuchar a todos.\n");
        }
        else
        {
            write("Actualmente, est�s ignorando a:\n"+sprintf("%75#s\n", implode(rc, "\n")));
            if (TP->QueryEarmuffs()) write("Adem�s, est�s ignorando los gritos y no te "
            	"es posible escucharlos.\n");
        }
        write("Escribe '"+query_verb()+" ?' para obtener m�s informacion\n");
        return 1;
    }

    // Ignoro a alguien nuevo

    arg = lower_case(arg);

    if (arg == "a todos") {
        if (TP->QueryIgnoreAll()) {
            TP->SetIgnoreAll(0);
            write("Ya no ignoras a todos los jugadores de Endor.\n"
            "Ahora podr�s recibir sus mensajes de telepat�a o canal y ver sus sociales.\n");
            play_sound(TP, SND_CANALES("designorar"));
            return 1;
        }
        else return notify_fail("No est�s ignorando a todos.\n");
    }

    if (arg == "gritos") {
        if (TP->QueryIgnoreAll())
            return notify_fail("Primero tienes que dejar de ignorar a todos los jugadores.\n");
        if (!TP->QueryEarmuffs()) {
            write("Actualmente no est�s ignorando los gritos.\n");
            return 1;
        }
        write("Ahora podr�s escuchar los gritos de nuevo.\n");
        TP->SetEarmuffs(0);
        play_sound(TP, SND_CANALES("designorar"));
        return 1;
    }
    if (!TP->CheckIgnored(arg)) return notify_fail("No est�s ignorando a "+arg+".\n");
    TP->RemoveIgnored(arg);
    write("Ya no ignoras a "+capitalize(arg)+".\n");
    play_sound(TP, SND_CANALES("designorar"));
    return 1;
}