/*****************************************************************************************
 ARCHIVO:       zinnia.c
 AUTOR:         Ztico
 FECHA:         28-06-2005
 DESCRIPCI�N:   Una zinnia, venenosa
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
    SetLong("Es una bell�sima zinnia de un alegre color anaranjado, sus innumerables "
        "p�talos le dan un aspecto suave y mullido, como un peque�o coj�n de seda. Tiene "
        "un aspecto realmente bello y tentador.\n");
    AddId(({"zinnia", "flor de zinnia", "naranja", "zinnia naranja"}));
    SetSmell("Huele de maravilla, su olor es refrescante y ligeramente �cido.\n");
    Set(P_GENDER, GENERO_FEMENINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
    SetWeight(60);
    SetType("flor"); //A�ade adem�s el id "flor"
    SetClass("venenoso");
    Set(P_MAGIC, QueryHerb());
}

private int cmd_comer(string str)
{
    object pl;

    if(!str || member(QueryIds(),str) < 0) return 0;
    pl = TP;
    if(!pl || !living(pl)) return notify_fail("Nadie me come.\n");

    write("El fresco aroma de la zinnia estimula tu paladar y tu curiosidad, as� que "
        "decides probar uno sus p�talos anaranjados. Su sabor es igual de refrescante "
        "que su aroma, aunque un poco m�s �cido, te recuerda a una mezcla de lima y "
        "pomelo.\n\n");
    say(CAP(NNAME(pl)) + " come uno de los anaranjados p�talos de la zinnia, y por su "
        "expresi�n, deduces que adem�s de bella es muy sabrosa...\n\n");
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
     write("Sientes un extra�o malestar que poco a poco se convierte en una "
        "insoportable marea de dolor y rigidez; tu est�mago y  tus venas arden, "
        "sientes que ha llegado tu �ltima hora. Caes al suelo, tu cuerpo cubierto de "
        "sudor sufre fuertes convulsiones y a ratos pierdes el conocimiento.\n");
     say("Inesperadamente, " + CAP(TNAME) + " parece encontrarse muy mal, su cuerpo se "
        "dobla sobre s� mismo y cae al suelo v�ctima de fuertes convulsiones.\n");
     return 1;
}

public int f_filtrar(string str)
{
    write("Tu pobre cuerpo s�lo es capaz de intentar expulsar el contenido de tu "
        "est�mago por la v�a m�s r�pida.\n");
    say(CAP(TNAME) + " parece estar muy grave, su cuerpo est� r�gido, los espasmos "
        "amenazan con partirl" + AE + " en dos y de su boca sale una gran cantidad de "
        "espuma verdosa de aspecto desagradable.\n");
    return 1;
}

public int f_reestablecer()
{
    object pl = TP;

    remove_action("", pl);
    if(pl->QueryHP() >= (pl->QueryMaxHP()/5))  //Si est� por encima de 1/5 de vida
    {
        pl->SetHP(pl->QueryHP()/5);            //Su vida es = a su vida/5
    }
    if(pl->QueryHP() < ((pl->QueryMaxHP()/5))) //Si est� por debajo de 1/5 de vida
    {
        pl->Die();                             //El player muere
        TO->remove();
        return 1;
    }

    write("Tu cuerpo a�n sufre ligeros espasmos y tu est�mago es un volc�n en "
        "miniatura, pero consigues ponerte en pie con dificultad y juras solemnemente "
        "que si sobrevives a �sta, no volver�s a comer zinnias el resto de tu vida.\n");
    say("Las convulsiones parecen remitir y " + CAP(NNAME(pl)) + "recupera la "
        "conciencia, con todo el aspecto de alguien que acaba de librarse por muy poco "
        "de las garras de la muerte. Lentamente se pone en pie con sus manos sujetando "
        "su abdomen y una expresi�n dolorida en su asustado y p�lido rostro.\n");
    TO->remove();
    return 1;
}

public varargs void init()
{
    ::init();

    add_action("cmd_comer", "comer");
}
