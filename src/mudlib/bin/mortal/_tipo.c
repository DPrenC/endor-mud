// Comando tipo / typo

public int main(string str) {
    seteuid(getuid());
    return REPORTMASTER->DoReport(str, "TYPO"
        , "Gracias por tu colaboracion, en breve solucionaremos el error tipográfico.\n"
        , "Informe sobre error tipográfico cancelado.\n");
}