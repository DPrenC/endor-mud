// Comando Página

#define USAGE(cond,txt) if (cond) { return notify_fail(txt); }

public int main(string str) {
    int n = to_int(str);

    if (!TP) return 0;

    if (!str || str == "?" || to_string(n) != str)
        return notify_fail("página [n]\n  Establece o visualiza el tamaño de página.\n");
    TP->SetPageSize((n > 0) ? n : 20);
    write("El tamaño de página es de "+TP->QueryPageSize()+" líneas.\n");
    return 1;
}