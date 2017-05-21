// Comando historico

public int main(string str) {
    int i,s;
    string *historico;

    if (str=="?") {
        return notify_fail(
"Uso: hist�rico             Muestra los comandos grabados en el hist�rico\n"
"     %                     Repite el �ltimo comando\n"
"     %<num>                Repite el comando n�mero <num>\n");
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
