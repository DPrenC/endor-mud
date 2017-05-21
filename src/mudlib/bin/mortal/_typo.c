// Comando tipo

public int main(string str) {
    seteuid(getuid());
    return REPORTMASTER->DoReport(str, "TYPO"
        , "Gracias por notificarnos el error tipográfico, los Valar de Endor le pondrán remedio lo antes posible.\n"
        , "Informe sobre error tipográfico cancelado.\n");
}