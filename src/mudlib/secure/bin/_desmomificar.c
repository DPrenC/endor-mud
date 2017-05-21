// Comando desmomificar

#include <wizlevels.h>

//public int desmomificar(string str) {
public int main(string str) {

    if (!IS_ARCH(TI)) return 0;

    if (!str) return notify_fail("Uso: desmomificar <nombre>\n");

    if (file_size(SECUREMUMMYPATH + str + ".o") < 0) {
        return notify_fail("Ese jugador no está momificado.\n");
    }

    rm(SECUREMUMMYPATH + str + ".o");
    write("Has desmomificado a " + str + ".\n");
    log_file("MOMIAS","<- "+TI->QueryRealName()+" desmomifica a "+str+".\n");
    return 1;
}
