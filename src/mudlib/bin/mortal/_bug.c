// Comando error / bug

public int main(string str) {
    seteuid(getuid());
    return REPORTMASTER->DoReport(str, "BUG"
        , "Error notificado con �xito.\n"
        "El equipo de administradores te lo agradece y solucionar� el error lo antes posible.\n"
        , "Notificaci�n de error cancelada.\n");
}