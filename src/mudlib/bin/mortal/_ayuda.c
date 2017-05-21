/**
 * ENDOR-MUD'/bin/mortal/_ayuda.c'
 */

#include "/secure/wizlevels.h"

int ayuda(string what) {
            seteuid(getuid());
    string fname;

    if (!IS_MAIA(TP)) {
        if (!what || member(what,' ')!=-1) fname = "/doc/jugadores/ayuda";
        else fname = "/doc/jugadores/comandos/" + what;

        if ((what && member(what, '/') >= 0) || !fname || file_size(fname) <= 0) {
           fname = "/doc/jugadores/textos/" + what;
           if ((what && member(what, '/') >= 0) || !fname || file_size(fname) <= 0) {
             return notify_fail ("Ahora mismo no tenemos ayuda disponible acerca de "+what+", consulta con un Ainu.\n");
           }
        }
        STR->smore(read_file(fname));
        return 1;
    }
    else {
        if (!what || member(what,' ')!=-1) fname = "/doc/wizards/ayuda";
        else fname = "/doc/wizards/comandos/" + what;

        if ((what && member(what, '/') >= 0) || !fname || file_size(fname) <= 0) {
            fname = "/doc/wizards/textos/" + what;
            if ((what && member(what, '/') >= 0) || !fname || file_size(fname) <= 0) {
                fname = "/doc/jugadores/comandos/" + what;
                if ((what && member(what, '/') >= 0) || !fname || file_size(fname) <= 0) {
                    fname = "/doc/jugadores/textos/" + what;
                    if ((what && member(what, '/') >= 0) || !fname || file_size(fname) <= 0) {
                        return notify_fail ("Para obtener ayuda sobre "+what+" consulta con un Ainu, posiblemente haya que implementarlo.\n");
                    }
                }
            }
        }
        STR->smore(read_file(fname));
        return 1;
    }
    return 0;
}
