/***
fichero: registerbook.c
autor: kastwey@simauria
Descripción: Un libro de registros para contabilizar la gente que hay dada de alta, las fechas y demás.
Fecha inicio: 23/08/2004. Creación de este archivo.
***/

#include <securebox.h>

inherit THING;

private string leer_libro(); // para leer el libro de registros

mapping pRegistros;

create()
{
    ::create();
    pRegistros = ([]);
    SetShort("un libro de registros");
    SetLong("Este es el libro de registros de las taquillas.\n"
            "En él aparecen todas las personas que tienen caja en la hermandad de consignas.\n");
    SetWeight(1000);
    SetNoGet(1);
    SetNoTake(1);
    SetNoDrop(1);
    SetNoGive(1);

    SetReadMsg(SF(leer_libro));
    AddId("libro");
    AddId("registro");
}

public int guardar()
{
    return save_object(SBOXLOGPATH "BOXES");
}

public int recuperar()
{
    return restore_object(SBOXLOGPATH  "BOXES");
}


public mapping AddCaja(string player,string lugar,string fecha)
{
    recuperar();
    pRegistros += ([player:lugar;fecha]);
    guardar();
    return pRegistros;
}


public mapping QueryRegistros() { return pRegistros; }

public mapping RemoveCaja(string nombre)
{
    recuperar();
    m_delete(pRegistros, nombre);
    guardar();
    return pRegistros;
}

private leer_libro()
{
    string texto;
    if (!query_wiz_level(TNREAL))
    {
        return "Intentas abrir el libro, pero por alguna extraña razón no lo consigues.\n";
    }
    texto = "Lista de clientes dados de alta en la hermandad de consignas:\n\n";
    recuperar();
    texto += "Nombre         |  Lugar del alta |  Fecha de alta.\n\n";
    filter(pRegistros, (:$3 += sprintf("%-15s|  %-15s|  %-15s.\n", $1, $2[0], $2[1]):), &texto);
    return texto;
}
