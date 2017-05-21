/*****************************************************************************************
 ARCHIVO:       rosa_r.c
 AUTOR:         Ztico
 FECHA:         28-06-2005
 DESCRIPCIÓN:   Una rosa roja del amor, curativa
******************************************************************************************/

#include "./path.h"
#include <properties.h>
#include <moving.h>

inherit "/obj/hierba";

private string pOwner;
public string SetOwner(string owner) { return pOwner = owner; }
public string QueryOwner() { return pOwner; }

public int cmd_oler(string str);
public int cmd_comer(string str);

create()
{
    if(::create()) return 1;

    SetShort("una espléndida rosa roja");
    SetLong("Es una espectacular rosa de un intenso color rojo sangre. Es tan grande "
        "que podría ocupar toda la palma de tu mano, sus pétalos son más suaves que la "
        "seda y tienen la textura y el brillo del más fino terciopelo. Hasta sus "
        "afiladísimas espinas te parecen bellas.\n");
    AddId(({"rosa", "rosa roja", "esplendida rosa", "espléndida rosa"}));
    Set(P_GENDER, GENERO_FEMENINO);
    Set(P_NUMBER, NUMERO_SINGULAR);
    SetClass("curativo");
    SetType("flor");
    SetWeight(60);
    Set(P_MAGIC, QueryHerb());
}

public int cmd_oler(string str)
{
    object own, pl;
    string plname;

    if(!str || member(QueryIds(),str) < 0) return 0;

    pl = TP;
    plname = CAP(NNAME(pl));

    if(!pl || !living(pl)) return notify_fail("Nadie me está oliendo.\n", NOTIFY_NOT_OBJ);
    if(!(own = find_object(pOwner)) || !pOwner || pl == own)
    {
        write("La fragancia más exquisita que jamás haya llegado a tu nariz te "
            "envuelve por completo, y sientes la necesidad de olerla para siempre.\n");
        say(plname + " huele una espléndida rosa roja que lleva consigo, y parece que "
            "su respiración se altera fugazmente.\n");
        return 1;
    }
    if(pl != own)
    {
        if(present(own, ENV(pl)))
        {
            write("Hueles la rosa y su increíble fragancia te envuelve. De pronto "
                "sientes que tu corazón se acelera, tu respiración se entrecorta y la "
                "sangre se vuelve fuego en tus venas, y entonces...\n"
                "Un impulso irresistible te acerca más y más a " + CAP(pOwner) + ", "
                "sientes una absoluta necesidad de juntar tu cuerpo con el suyo... le "
                "rodeas con tus brazos y vuelcas tu pasión en un maravilloso e "
                "interminable beso.\n");
            say(plname + " inspira el aroma de su rosa y de pronto se estremece y sus "
                "ojos brillan como estrellas.\n" + plname + " se acerca peligrosamente "
                "a " + CAP(pOwner) + "... le rodea con sus brazos y le besa "
                "apasionadamente.\n", ({own, pl}));
            tell_object(own, plname + " inspira el aroma de su rosa, de pronto notas "
                "que le invade un estremecimiento, te mira fijamente y ves que sus "
                "ojos brillan como estrellas.\n" + plname + " se te acerca "
                "peligrosamente... te rodea con sus brazos y te envuelve en un "
                "maravilloso e interminable beso.\n");
            return 1;
        }
        write("Inspiras profundamente la exquisita fragancia que desprende.\n"
            "Al instante comienzas a sentir con increible intensidad la necesidad de "
            "estar junto a " + CAP(pOwner) + " y besarle apasionadamente.\n");
        say(plname + " aspira profundamente la fragancia que desprende su rosa, y por "
            "un segundo, sus ojos adquieren el brillo de mil soles.\n");
        tell_object(own, "De pronto te invade la extraña sensación de que " + plname +
            " te ama.\n");
        return 1;
    }
}

public int cmd_comer(string str)
{
    object pl;

    if(!str || member(QueryIds(), str) < 0) return 0;
    pl = TP;
    write("El sabor es bastante agradable. Notas cómo tu cuerpo se recupera.\n");
    say(CAP(NNAME(pl)) + " se come una rosa roja.\n");

    pl->HealHP(50);
    TO->remove();
    return 1;
}

public varargs int move(mixed dest, int method, mixed extra)
{
    object ob = PO;
    object from = ENV(TO);
    int val = ::move(dest, method, extra);
    if(val == ME_OK && method == M_GET && ob && query_once_interactive(ob)
       && from && !sizeof(all_environment(from)) && !pOwner)
    // coge la flor del suelo
    {
        pOwner = NREAL(ob);  //no tiene dueño, así que se setea al player como
    }                                  //como tal
    return val;
}

public varargs void init()
{
    ::init();

    add_action("cmd_oler", "oler");
    add_action("cmd_comer", "comer");
}
