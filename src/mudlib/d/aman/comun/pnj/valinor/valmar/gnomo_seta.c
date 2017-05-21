/*****************************************************************************************
 ARCHIVO:       gnomo_seta.c
 AUTOR:         Ztico
 FECHA:         24-05-2005
 COMENTARIOS:   Es un gnomo cascarrabias, que guarda con recelo su gran seta.
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

public int f_es_amigo(object pl);
public string f_raza();

create()
{
    if(::create()) return 1;

    SetStandard("un gnomo", "gnomo", ([GC_GUARDABOSQUES: 40 + d10()]), GENERO_MASCULINO);
    SetShort("un gnomo cascarrabias");
    SetLong("Es un gnomo con cara de pocos amigos.\n");
    AddId(({"gnomo","gnomo cascarrabias", "dueño_seta"}));
    SetAttackOwnRace(1000);
    SetAttackChance(1000);
    SetFriendFunction(SF(f_es_amigo));
    SetAggressive(2);
    SetWhimpy(-1);
    InitAChats(10,({SF(f_raza)}));
}

public int f_es_amigo(object pl)
{
    if (present("seta_id", pl)) return 0;
    return 1;
    //si la función devuelve 1, eres amigo, si devuelve 0, eres enemigo
}

public string f_raza()
{
    object enemigo;
    string mensaje, raza_agresor;

    if (!QueryEnemies()) 
    {
        return "Un gnomo cascarrabias dice: ¡Has intentado robar mi "
                                "seta, Paga por ello ladronzuelo!\n";
    }
    enemigo = QueryEnemies()[random(sizeof(QueryEnemies()))];
    raza_agresor = enemigo->QueryRace();
    switch(raza_agresor)
    {
        case "gnomo":
        	          mensaje = (d10() >=5 ?
        	              "Un gnomo cascarrabias dice: Eres un gusano, ¿Cómo te atreves "
        	              "a robar a los de tu raza?\n" :
        	          	  "Un gnomo cascarrabias dice: ¡Estás deshonrando a los de tu "
        	          	  "propia raza! Muere por traición.\n");
                    break;
        case "duende":
        case "kender":
        case "elfo":
                    mensaje = "¡¡Eh!! Esa es mi seta, lucharé hasta que lo pagues con "
                              "tu vida.\n";
                    break;
        case "humano":
                    mensaje = "Un gnomo cascarrabias dice: ¡Siempre he dicho que los "
                              "humanos sois unos cretinos! ¡¡Y robarme de esta manera "
                              "no tiene perdón!!\n";
                    break;
        case "troll":
        case "gigante":
                    mensaje = "Un gnomo cascarrabias dice: Metete con los de tu tamaño "
                              "cañalla..... ¡A pesar de todo vas a morir!\n";
                    break;
        case "orco":
                    mensaje = "Un gnomo cascarrabias dice: ¡¡Puaj!! ¿¿Como te has "
                              "atrevido asqueroso orco??\n";
                    break;
        default:
                    mensaje = "Un gnomo cascarrabias dice: ¡Ehh! Pero que estás "
                              "haciendo, ¿Quieres morir?\n";
                    break;
    }
    return mensaje;
}
