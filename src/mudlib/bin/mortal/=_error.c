// Comando error / bug

public int main(string str) {
    seteuid(getuid());
    return REPORTMASTER->DoReport(str, "BUG"
        , "Gracias por tu colaboraci�n, en breve solucionaremos el error.\n"
        , "Informe sobre el error cancelado.\n");
}