/*****************************************************************************************
 ARCHIVO:       rosa_a.c
 AUTOR:         Ztico
 FECHA:         28-06-2005
 DESCRIPCI�N:   Una rosa amarilla
******************************************************************************************/

#include "./path.h"
#include <properties.h>

inherit "/obj/hierba";

public int cmd_comer(string str);

create()
{
    if(::create()) return 1;

    SetShort("una rosa amarilla");
    SetLong("Es una peque�a rosa, de un amarillo deslumbrante como el mismo sol. El "
        "borde de sus p�talos es de un tono ligeramente m�s intenso que su centro, su "
        "tallo es fino pero no obstante parece s�lido, y sus espinas dan la impresi�n de "
        "ser muy afiladas.\n");
    AddId(({"rosa", "rosa amarilla", "magnifica rosa", "magn�fica rosa"}));
    SetSmell("Huele maravillosamente bien, su delicioso aroma parece estimular tu "
        "apetito.\n");
    Set(P_GENDER, GENERO_FEMENINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
    SetWeight(60);
    SetType("flor");
    SetClass("saciante");
    Set(P_MAGIC, QueryHerb());
}

public int cmd_comer(string str)
{
    object pl;

    if(!str || member(QueryIds(), str) < 0) return 0;
    pl = TP;
    if(!pl || !living(pl)) return notify_fail("Nadie me come.\n");

    write("Es totalmente imposible resistirse al delicioso aroma que esta rosa "
        "desprende, no puedes evitar comer sus dorados p�talos. Su sabor es a la vez "
        "maravilloso e indescriptible, y hace que tu boca se inunde de saliva, te "
        "recuerda a todos aquellos manjares que alguna vez hayas tenido la oportunidad "
        "de comer, a las frutas tempranas, al pan reci�n horneado, a los pasteles "
        "caseros, al cordero asado y aromatizado con hierbas, crujiente y "
        "delicioso....\n");
    say(CAP(NNAME(pl)) + " aspira con gran deleite el aroma de esta bella rosa "
        "amarilla, su expresi�n se torna ansiosa e inmediatamente arranca unos cuantos "
        "p�talos y se los come. Una oleada de placer recorre su rostro mientras "
        "mastica con fruici�n, al parecer tienen un sabor realmente delicioso.\n");

    pl->SetFood(TP->QueryFood() + 60);
    TO->remove();
    return 1;
}

public varargs void init()
{
    ::init();

    add_action("cmd_comer", "comer");
}
