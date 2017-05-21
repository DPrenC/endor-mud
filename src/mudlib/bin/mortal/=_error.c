// Comando error / bug

public int main(string str) {
    seteuid(getuid());
    return REPORTMASTER->DoReport(str, "BUG"
        , "Gracias por tu colaboración, en breve solucionaremos el error.\n"
        , "Informe sobre el error cancelado.\n");
}