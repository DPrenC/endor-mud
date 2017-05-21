// Comando espiar

#include "/secure/wizlevels.h"

// [Nyh] Todo lo relacionado con el espiar es una chapuza. Revisarlo.
// Ya he revisado parte del contenido del simul_efun, pero aun queda esto.
public int main(string str) {
    object snoopee;
    object *u;
    int i;

    if (!TI || !IS_WIZARD(TI)) return 0;

    if (str == "?") {
        return notify_fail("espiar\n  Mostrar a quién estás espiando.\n"
                    "espiar <nombre>\n  Espiar al jugador <nombre>\n"
                    "espiar lista\n  Mostrar todos los jugadores que estás espiando.\n"
                    "parar de espiar\n  Deja de espiar a quien estuvieras espiando.\n");
    }

    /* Comprueba a quien estas espiando */
    snoopee = 0;
    for (i = sizeof(u = users()); i--; ) {
        if (query_snoop(u[i]) == TI) {
            snoopee = u[i];
            break;
        }
    }

    if (!str) {
        if (!snoopee) write("Tu penetrante mirada no está puesta sobre ningún mortal.\n");
        else write("Tu penetrante mirada está puesta sobre  "+capitalize(snoopee->QueryRealName())+".\n");
        return 1;
    }

    str = lower_case (str);
    if (str == "lista") {
        object *user, snooper;
        mixed *data;

        for (i = 0, user = users(), data = ({}); i < sizeof(user); i++)
            if (snooper = query_snoop (user[i])) data += ({({ user[i], snooper })});
        if (!sizeof (data)) write("Tu penetrante mirada no está puesta sobreningún mortal en estos momentos.\n");
        else {
            write(sizeof(data)+" de "+sizeof(user)+" mortales están siendo vigilados.\n");
            for (i = sizeof(data); i -- ; )
                write("  "+capitalize(data[i][0]->QueryRealName())
                       +"\t por "+capitalize(data[i][1]->QueryRealName())+"\n"
                      );
        }
        return 1;
    }

    if (snoopee && !snoop(TI)) {
        return notify_fail("No puedes apartar tu penetrante mirada de "+capitalize(snoopee->QueryRealName())+".\n");
    }

    if (!(snoopee = find_object(lower_case(str)))) {
        return notify_fail("Ese jugador no se encuentra en Arda.\n");
    }

    if (!snoop(TI, snoopee)) {
        snoopee = 0;
        return notify_fail(capitalize(snoopee->QueryRealName())+" elude tu penetrante mirada.\n");
    }

    write("Fijas tu penetrante mirada sobre  "+capitalize(snoopee->QueryRealName())+". Ahora, todas sus acciones y pensamientos quedan al descubierto para ti.\n");
    return 1;
}
