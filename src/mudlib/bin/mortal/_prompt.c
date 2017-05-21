// Comando prompt

#include <config.h>
#include <properties.h>
#include <colours.h>
#include <wizlevels.h>
#include <prompt.h>

private int _prompt_err_msg() {
    mixed *curr;
    int idx;
    string modo;

    write("Uso: prompt <modo>\n");
    write("Cambia el prompt del mud. Los siguientes modos están disponibles:\n");
    write(TC_BOLD + "  ninguno" + TC_NORMAL + ": no muestra ningún prompt.\n");
    write(TC_BOLD + " estándar" + TC_NORMAL + ": muestra el prompt estándar '>'.\n");
    write(TC_BOLD + "  detalle" + TC_NORMAL + ": muestra puntos de vida y magia en el prompt.\n");
    if (IS_WIZARD(TP)) {
        write(TC_BOLD + "     path" + TC_NORMAL + ": muestra el path en el prompt.\n");
    }
    curr = unmkmapping(REP);
    idx = member(curr[1], TP->QueryPrompt());
    if (idx == -1) {
        modo = "desconocido";
    }
    else {
        modo = curr[0][idx];
    }
    modo = TC_BOLD + modo + TC_NORMAL;

    write("Tu modo actual es: " + modo + ".\n");

    return 1;
}

public int main(string str) {
    int tmp;

    if (!str) {
        return _prompt_err_msg();
    }
    str = lower_case(str);
    if (!member(REP, str)) {
        return _prompt_err_msg();
    }
    tmp = REP[str];
    if (!IS_WIZARD(TP) && tmp == PR_WIZ_PROMPT) {
        return _prompt_err_msg();
    }
    TP->SetPrompt(tmp);

    if (TP->QueryTTY() == "ansi" || TP->QueryTTY() == "vt100") {
        str = TC_BOLD + str + TC_NORMAL;
    }

    write("Cambiando modo a '" + str + "'.\n");
    return 1;
}