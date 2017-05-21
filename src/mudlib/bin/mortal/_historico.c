// Comando historico

public int main(string str) {
    int i,s;
    string *historico;

    if (str=="?") {
        return notify_fail(
"Uso: histórico             Muestra los comandos grabados en el histórico\n"
"     %                     Repite el último comando\n"
"     %<num>                Repite el comando número <num>\n");
    }
    historico = TP->QueryHistorico();
    if (s = sizeof(historico)) {
        for (i = s; i--; )
            write(sprintf("%2i - %s\n", i+1, historico[i]));
    }
    else {
       write("No has .\n");
    }
    return 1;
}
