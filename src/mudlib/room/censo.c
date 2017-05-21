/**
 * /room/censo.c
 *
 * Habitación estandar del censo
 *
 * Si no se define ninguna ciudad el comando de censar no estará disponible.
 */

inherit ROOM;

#ifndef CENSO
#define CENSO "/obj/censo"
#endif

//----------------------------------------------------------------------------

private string city;

//----------------------------------------------------------------------------

public string SetCity(string str) {
    if (stringp(str) && str != "") {
        city = capitalize(str);
        SetIntShort("la oficina del censo de " + city);
        SetIntLong("La oficina del censo de " + city +".\n"
               "Usa 'censar' para censar a alguien o cambiar el censo.\n"
               "Usa 'consultar' para saber donde está censado alguien.\n");
        return city;
    }
    return 0;
}
public string QueryCity()         { return city; }

//----------------------------------------------------------------------------

public int censar() {
    return CENSO->Censar(TP->QueryRealName(), city);
}

public int consultar() {
    return CENSO->C_Censo(TP->QueryRealName());
}

//----------------------------------------------------------------------------

create() {
    ::create();
    SetIntShort("una oficina del censo");
    SetIntLong("Una oficina del censo.\n"
               "Usa 'consultar' para saber donde está censado alguien.\n");
    SetIntBright(50);
    SetIndoors(1);
}

init() {
    ::init();
    add_action("consultar","consultar");
    add_action("censar","censar");
}

//----------------------------------------------------------------------------