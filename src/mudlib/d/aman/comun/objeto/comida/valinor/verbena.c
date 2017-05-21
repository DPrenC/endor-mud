/*****************************************************************************************
 ARCHIVO:       verbena.c
 AUTOR:         Ztico
 FECHA:         28-06-2005
 DESCRIPCIÓN:   Una verbena roja
******************************************************************************************/

#include "./path.h"
#include <properties.h>

inherit "/obj/hierba";

public int cmd_comer(string str);

create()
{
    if(::create()) return 1;

    SetShort("una hermosa verbena");
    SetLong(W("Es un arbusto medianamente grande, cubierto en su totalidad por pequeños "
        "racimos de flores diminutas en forma de estrella de cinco puntas, de variados "
        "colores, a cual más bello. Un espectáculo muy agradable a la vista.\n"));
    AddId(({"verbena", "hermosa verbena", "hermosa"}));
    SetSmell("Su olor es dulce e intenso, una delicia para tus sentidos.\n");
    Set(P_GENDER, GENERO_FEMENINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
    SetWeight(60);
    SetType("flor"); //Añade además el id "flor"
    SetClass("curativo");
    Set(P_MAGIC, QueryHerb());
}

public int cmd_comer(string str)
{
    object pl;

    if(!str || member(QueryIds(), str) < 0) return 0;
    pl = TP;
    if(!pl || !living(pl)) notify_fail("Nadie me come.\n", NOTIFY_NOT_OBJ);

    write("Arrancas una pequeña flor de verbena y la llevas a tu nariz; su aroma es "
        "tan dulce, suave y reconfortante que optas por comértela. Al instante te "
        "invade una sensación de vigor, salud y bienestar que corre por tus venas de "
        "forma sumamente agradable.\n");
    say(CAP(NNAME(pl)) + " arranca una pequeña flor de verbena y la lleva a su nariz. "
        "Inspira su aroma con cara de satisfacción y a continuación se la come. De "
        "inmediato notas que su aspecto parece mucho más fuerte y saludable.\n");

    pl->HealHP(60);
    TO->remove();
    return 1;
}

public void init()
{
    ::init();

    add_action("cmd_comer", "comer");
}
