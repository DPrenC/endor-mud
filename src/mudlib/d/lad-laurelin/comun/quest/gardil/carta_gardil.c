/****************************************************************************
Fichero: carta_gardil.c
Autor: Kastwey
Fecha: 01/04/2006
Descripción: Una carta sellada, que debe entregar el jugador al shamán de flenton
para que le haga la poción para curar a la hechicera.
****************************************************************************/


#include <properties.h>
#include <colours.h>
#include <moving.h>

inherit THING;

private string pOwner;

public string QueryOwner() { return pOwner; }
public string SetOwner(string own) { return pOwner = own; }

create()
{
    ::create();
    SetShort("una carta lacrada");
    SetLong("Se trata de un pliego de papel fino, doblado sobre sí mismo y sujeto "
            "con un sello de lacre, para evitar que sea abierto por alguien "
            "que no sea el destinatario de la misma.\n");
    SetReadMsg("En el reverso de la carta, puedes leer con letras grandes y elegantes: "
               TC_BLUE + "PARA EL GRAN SHAMÁN, DE GARDIL, LA HECHICERA" + TC_NORMAL + "\n\n"
               "Desgraciadamente, la parte interesante de la carta queda oculta "
               "por el lacre que la mantiene doblada.\n");

    SetIds(({"carta", "papel", "papel doblado", "carta sellada", "carta lacrada",
             "carta de gardil", "carta de Gardil", "carta_quest_gardil"}));
    Set(P_NOSELL, 1);
    SetValue(0);
    SetNoDrop("Te da pena tirar la carta de la hechicera, así que decides conservarla.\n");
    SetWeight(40);
}



public varargs int move(mixed dest, int method, mixed extra)
{
    if (   (   method == M_GIVE && dest
            && (dest->QueryShamanFlenton() || NREAL(to_object(dest)) == QueryOwner()))
        || method != M_GIVE)
    {
        return ::move(dest, method, extra);
    }
    tell_object(PO, "Esta carta te la dió Gardil, mejor conservarla.\n");
    return ME_NO_GIVE;
}
