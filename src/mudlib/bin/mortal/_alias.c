// Comando alias

#include <sounds.h>

int main(string str) {
    string al, cmd, msg_als;
    int i;

    if(str=="?")
        return notify_fail(
"Uso: alias                        Devuelve una lista de todos los alias\n"
"     alias <alias>		  Devuelve  la acción o cadena de acciones asociadas al <alias>\n"
"     alias <alias> <comando>      Establece el <alias> de <comando>\n"
"     !1, !2,.. !*                 Distintos comodines que puedes usar\n"
"Para más información escribe 'ayuda alias'.\n");

    if (!str) {
        mixed aliases = TP->QueryAliases();
        if (sizeof(aliases[0]))
        {
            mixed AlsNames = sort_array(aliases[0], SF(>));
            msg_als="Alias definidos:\n";
            for(i = 0; i < sizeof(AlsNames); i++) {
                msg_als+=STR->ladjust("  "+AlsNames[i]+" ",17,".")+" "+aliases[1][member(aliases[0], AlsNames[i])]+".\n";
            }
            STR->smore(msg_als);
        }
        else write("Actualmente no tienes ningún alias establecido .\n");
        return 1;
    }
    if (sscanf(str,"%s %s",al, cmd) == 2) {
        write("'"+al+"' queda guardado como alias que equivale a '"+cmd+"'.\n");
        TP->AddAlias(al, cmd);
        play_sound(TP, SND_SUCESOS("addalias"));

        return 1;
    }

    if (!TP->HasAlias(str)) {
        return notify_fail("El alias '"+str+"' no está almacenado como alias.\n");
    }
    write("El alias '"+str+"' equivale a la acción '"+TP->QueryAlias(str)+"'.\n");

    return 1;
}
