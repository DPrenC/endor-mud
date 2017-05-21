// Comando P�gina

#define USAGE(cond,txt) if (cond) { return notify_fail(txt); }

public int main(string str) {
    int n = to_int(str);

    if (!TP) return 0;

    if (!str || str == "?" || to_string(n) != str)
        return notify_fail("p�gina [n]\n  Establece o visualiza el tama�o de p�gina.\n");
    TP->SetPageSize((n > 0) ? n : 20);
    write("El tama�o de p�gina es de "+TP->QueryPageSize()+" l�neas.\n");
    return 1;
}