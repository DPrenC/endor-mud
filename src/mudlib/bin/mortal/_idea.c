// Comando idea

public int main(string str) {
    seteuid(getuid());
    return REPORTMASTER->DoReport(str, "IDEA"
        , "Tu idea será estudiada.. gracias por colaborar.\n"
        , "Idea cancelada.\n");
}