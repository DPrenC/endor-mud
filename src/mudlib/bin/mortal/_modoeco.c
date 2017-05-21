// Comando modoeco

public int main(string arg) {

    if (!sizeof(arg)) {
        if (TP->QueryEchoMode()) {
            write("El modo eco está activado\n");
        }
        else {
            write("El modo eco está desactivado\n");
        }
        return 1;
    }

    arg = lower_case(arg);

    if (arg == "activar" || arg== "si") {
        TP->SetEchoMode(1);
        write("Has activado el modo eco.\n");
        return 1;
    }

    if (arg == "desactivar" || arg == "no") {
        TP->SetEchoMode(0);
        write("Has desactivado el modo eco.\n");
        return 1;
    }

    return notify_fail("Uso: modoeco [si|activar|no|desactivar]\n");
}
