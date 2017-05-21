// Comando mensajes

public int main(string str) {
    int i, num, sz;
    string quien,que;
    string *mensajes;

    mensajes = TP->QueryMessages();

    if(!sizeof(mensajes)) {
        write("Nadie te ha dicho nada últimamente.\n");
        return 1;
    }
    sz = sizeof(mensajes);

    if (str) num = to_int(str);
    else num = 20;

    if (num>sz) num = sz;

    write(sprintf("Mostrando %d/%d mensajes:\n", num, sz));
    for (i=sz-num; i<sz; i++) {
        sscanf(mensajes[i], "%s##%s", quien, que);
        write("  " + quien + ": " + que);
    }
    return 1;
}