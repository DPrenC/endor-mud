// Comando tipo

public int main(string str) {
    seteuid(getuid());
    return REPORTMASTER->DoReport(str, "TYPO"
        , "Gracias por notificarnos el error tipogr�fico, los Valar de Endor le pondr�n remedio lo antes posible.\n"
        , "Informe sobre error tipogr�fico cancelado.\n");
}