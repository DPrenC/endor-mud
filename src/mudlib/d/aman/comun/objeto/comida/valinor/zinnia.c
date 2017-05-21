/*****************************************************************************************
 ARCHIVO:       zinnia.c
 AUTOR:         Ztico
 FECHA:         28-06-2005
 DESCRIPCIÓN:   Una zinnia, venenosa
******************************************************************************************/

#include "./path.h"
#include <commands.h>
#include <properties.h>

#define AE (TP->QueryGender()== 1?"e":"a")

inherit "/obj/hierba";

private int cmd_comer(string str);
private int f_envenenado(int tiempo);
public int f_filtrar(string str);
public int f_reestablecer();
public int f_espera();

create()
{
    if(::create()) return 1;

    SetShort("una llamativa zinnia");
    SetLong("Es una bellísima zinnia de un alegre color anaranjado, sus innumerables "
        "pétalos le dan un aspecto suave y mullido, como un pequeño cojín de seda. Tiene "
        "un aspecto realmente bello y tentador.\n");
    AddId(({"zinnia", "flor de zinnia", "naranja", "zinnia naranja"}));
    SetSmell("Huele de maravilla, su olor es refrescante y ligeramente ácido.\n");
    Set(P_GENDER, GENERO_FEMENINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
    SetWeight(60);
    SetType("flor"); //Añade además el id "flor"
    SetClass("venenoso");
    Set(P_MAGIC, QueryHerb());
}

private int cmd_comer(string str)
{
    object pl;

    if(!str || member(QueryIds(),str) < 0) return 0;
    pl = TP;
    if(!pl || !living(pl)) return notify_fail("Nadie me come.\n");

    write("El fresco aroma de la zinnia estimula tu paladar y tu curiosidad, así que "
        "decides probar uno sus pétalos anaranjados. Su sabor es igual de refrescante "
        "que su aroma, aunque un poco más ácido, te recuerda a una mezcla de lima y "
        "pomelo.\n\n");
    say(CAP(NNAME(pl)) + " come uno de los anaranjados pétalos de la zinnia, y por su "
        "expresión, deduces que además de bella es muy sabrosa...\n\n");
    call_out("f_espera", 3);
    f_envenenado(60);
    return 1;
}

private int f_envenenado(int tiempo)
{
    add_action("f_filtrar", "", AA_NOSPACE);
    call_out("f_reestablecer", tiempo);
    return 1;
}

public int f_espera()
{
     write("Sientes un extraño malestar que poco a poco se convierte en una "
        "insoportable marea de dolor y rigidez; tu estómago y  tus venas arden, "
        "sientes que ha llegado tu última hora. Caes al suelo, tu cuerpo cubierto de "
        "sudor sufre fuertes convulsiones y a ratos pierdes el conocimiento.\n");
     say("Inesperadamente, " + CAP(TNAME) + " parece encontrarse muy mal, su cuerpo se "
        "dobla sobre sí mismo y cae al suelo víctima de fuertes convulsiones.\n");
     return 1;
}

public int f_filtrar(string str)
{
    write("Tu pobre cuerpo sólo es capaz de intentar expulsar el contenido de tu "
        "estómago por la vía más rápida.\n");
    say(CAP(TNAME) + " parece estar muy grave, su cuerpo está rígido, los espasmos "
        "amenazan con partirl" + AE + " en dos y de su boca sale una gran cantidad de "
        "espuma verdosa de aspecto desagradable.\n");
    return 1;
}

public int f_reestablecer()
{
    object pl = TP;

    remove_action("", pl);
    if(pl->QueryHP() >= (pl->QueryMaxHP()/5))  //Si está por encima de 1/5 de vida
    {
        pl->SetHP(pl->QueryHP()/5);            //Su vida es = a su vida/5
    }
    if(pl->QueryHP() < ((pl->QueryMaxHP()/5))) //Si está por debajo de 1/5 de vida
    {
        pl->Die();                             //El player muere
        TO->remove();
        return 1;
    }

    write("Tu cuerpo aún sufre ligeros espasmos y tu estómago es un volcán en "
        "miniatura, pero consigues ponerte en pie con dificultad y juras solemnemente "
        "que si sobrevives a ésta, no volverás a comer zinnias el resto de tu vida.\n");
    say("Las convulsiones parecen remitir y " + CAP(NNAME(pl)) + "recupera la "
        "conciencia, con todo el aspecto de alguien que acaba de librarse por muy poco "
        "de las garras de la muerte. Lentamente se pone en pie con sus manos sujetando "
        "su abdomen y una expresión dolorida en su asustado y pálido rostro.\n");
    TO->remove();
    return 1;
}

public varargs void init()
{
    ::init();

    add_action("cmd_comer", "comer");
}
