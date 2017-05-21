/*****************************************************************************************
 ARCHIVO:       rosa_rs.c
 AUTOR:         Ztico
 FECHA:         28-06-2005
 DESCRIPCIÓN:   Una rosa rosada, intoxicante (alcohol)
******************************************************************************************/

#include "./path.h"
#include <commands.h>
#include <properties.h>

#define AE (TP->QueryGender()== 1?"e":"a")

inherit "/obj/hierba";

private int cmd_comer(string str);
private int f_borrachuzo(int tiempo);
public int f_filtrar(string str);
public int f_reestablecer();

create()
{
    if(::create()) return 1;

    SetShort("una rosa rosada");
    SetLong("Es una rosa de un sorprendente tono coralino, sus pétalos brillan "
        "como el más delicado cristal élfico, y en su centro, los delicados estambres de "
        "color dorado se arraciman en torno al pistilo, similar a una diminuta copa.\n");
    AddId(({"rosa", "rosa rosada", "bellisima rosa", "bellísima rosa"}));
    SetSmell("Esta delicada rosa huele como el más caro y exquisito de los vinos, "
        "embriaga tus sentidos y te hace desear beber algo con avidez.\n");
    Set(P_GENDER, GENERO_FEMENINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
    SetClass("intoxicante");
    SetType("flor");
    SetWeight(60);
    Set(P_MAGIC, QueryHerb());
}

private int cmd_comer(string str)
{
    object pl;

    if(!str || member(QueryIds(),str) < 0) return 0;
    pl = TP;
    if(!pl || !living(pl)) return notify_fail("Nadie me come.\n", NOTIFY_NOT_OBJ);

    write("El exquisito perfume de la rosa te seduce, y decides probar si su sabor es "
        "comparable a su aroma. Arrancas con cuidado uno de sus hermosos pétalos y lo "
        "masticas con deleite, en breve tu boca se ve inundada por un delicioso sabor "
        "a vino de bayas. Estás a punto de comerte otro cuando de pronto...\n"
        "Te sientes increíblemente torpe, tu cabeza parece flotar en un mar de "
        "algodón, y de pronto los objetos a tu alrededor parecen multiplicarse y "
        "girar, lo cual te hace reir tontamente de forma inexplicable... "
        "¡Vaya borrachera!\n");
    say(CAP(NNAME(pl)) + " mastica con deleite un rosado pétalo, de pronto parece "
        "sufrir un extraño mareo, sus movimientos se vuelven torpes y sufre un ataque "
        "de risa tonta. A continuación tropieza y cae al suelo pesadamente.\n");
    f_borrachuzo(30);
    return 1;
}

private int f_borrachuzo(int tiempo)
{
    add_action("f_filtrar", "", AA_NOSPACE);
    call_out("f_reestablecer", tiempo);
    return 1;
}

public int f_filtrar(string str)
{
    write("¡Llevas una borrachera de campeonato! Será mejor que no te muevas durante "
        "un ratito, no vayas a sufrir un accidente o, peor aún, hacer el ridículo.\n");
    say(CAP(TNAME) + " se esfuerza en recuperar la verticalidad, pero se hace un lío "
        "con sus extremidades y vuelve a caer al suelo.\n");
    return 1;
}

public int f_reestablecer()
{
    remove_action("", TP);
    write("Lentamente recuperas la lucidez, parece que los efectos de esa extraña "
        "borrachera van desapareciendo, para ser sustituidos por la jaqueca más "
        "terrible que hayas sufrido en tu vida. Sientes un desagradable sabor de boca "
        "y tu estómago sufre unas náuseas considerables.\n");
    say(CAP(TNAME) + " parece recuperar el control de sus movimientos y se pone en pie "
        "con una desagradable y verdosa expresión en su rostro, parece sufrir, entre "
        "otras cosas, un terrible dolor de cabeza. Sería mejor no molestarl" + AE +
        " en lo que queda de día.\n");
    TP->SetAlcohol(TP->QueryAlcohol()+ 100);
    TO->remove();
    return 1;
}

public varargs void init()
{
    ::init();

    add_action("cmd_comer", "comer");
}
