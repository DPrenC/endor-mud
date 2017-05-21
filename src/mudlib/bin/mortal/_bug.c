// Comando error / bug

public int main(string str) {
    seteuid(getuid());
    return REPORTMASTER->DoReport(str, "BUG"
        , "Error notificado con éxito.\n"
        "El equipo de administradores te lo agradece y solucionará el error lo antes posible.\n"
        , "Notificación de error cancelada.\n");
}