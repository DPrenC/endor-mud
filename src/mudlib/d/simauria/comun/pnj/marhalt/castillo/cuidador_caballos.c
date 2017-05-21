/****************************************************************************
Fichero: cuidador_caballos.c
Autor: Ratwor
Fecha: 24/09/2006 15:30
Descripción: Un cuidador de caballos para las cuadras del castillo de Nandor.
Comentarios:
Se alterna entre el parapernero y el mozo de cuadra.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
inherit NPC;
inherit GUARD;
public string f_init();
create()
{
    "*"::create();

    switch(d2())
    {
        case 1:
            SetStandard("el palafrenero", "humano", ([GC_TORPE:16+d3()]), GENDER_MALE);
            AddId(({"palafrenero", "hombre"}));
            SetShort("el palafrenero");
            SetLong("Este es el palafrenero del castillo de Nandor, parece un tipo "
            "castigado por la edad, pero realmente no es tan mayor como aparenta.\n No "
            "suele tener mucho trabajo debido que a la mujer y las hijas del noble "
            "no les gusta mucho montar, por lo que en sus largos ratos sin faena hace de"
            " mozo de cuadra.\n");
            break;
        case 2:
            SetStandard("el mozo", "humano", ([GC_TORPE:16+d3()]), GENDER_MALE);
            AddId(({"mozo", "hombre"}));
            SetShort("el mozo de cuadra");
            SetLong("Este es el mozo de cuadras del castillo, es algo joven, pero aún "
            "así hace muy bien su trabajo.\n Al igual que el palafrenero, tampoco tiene "
            "mucho trabajo, pues se lo reparten entre los dos, y además tampoco hay "
            "mucha afición por los caballos en este castillo ni tienen necesidad de "
            "usarlos en demasía.\n");
            break;
    }
    SetCitizenship("nandor");
    SetGuardDefendMsg(QueryShort()+" grita: ¡Salvaje!\n");
    AddQuestion(({"caballos", "caballo", "yegua", "yeguas", "potro", "potros", "mula"}),
        QueryShort()+" dice: todos los cuadrúpedos que tenemos en el castillo son buenas"
        " piezas, se portan bien, nos portamos bien con ellos y no les hacemos trabajar"
        " en exceso.\n");
    SetSmell("Por su ocupación lo único que se puede esperar es que huela a caballos y derivados.\n");
    InitChats(5, ({SF(f_init)}));
    AddQuestion(({"noble", "rocher", "señor"}),
    QueryShort()+" se acerca a tí confidencialmente y te dice: \n"
        " Lo normal es que te diga que es un buen señor, pero no sería verdad, de todas"
        " formas prefiero no comentar nada sobre el, tengo un trabajo cómodo y no me"
        " agovia mucho a mí personalmente.\n", 1);
        if(d2()==1)
            AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["plata":random(5),"cobre":d10()])]));
}

public string f_init()
{
    //si no hay caballos.
    string *init_normal =
        ({QueryShort()+" remueve la paja.\n",
        QueryShort()+" se limpia el sudor de la frente.\n",
        QueryShort()+" se mira las uñas.\n",
        QueryShort()+" limpia el suelo de excrementos de los animales.\n"});
//personaliza el init.
    object *a_mirar = all_inventory(environment()) - ({TO});
    object elegido = a_mirar[random(sizeof(a_mirar))];
//mensajes cuando hay caballos.
    string *con_caballos =
        ({QueryShort()+" cepilla a "+elegido->QueryShort()+".\n",
        QueryShort()+" le mira el hozico a "+elegido->QueryShort()+".\n",
        QueryShort()+" le da de comer unas beyotas a "+elegido->QueryShort()+".\n",
        QueryShort()+" le da unas palmadas, en el lomo, a "+elegido->QueryShort()+".\n"})
        +init_normal;
//miro a ver si hay caballos.
    int vivos, i;
    object *inv = all_inventory(environment(TP));
    for (i=0;i<sizeof(inv);i++)
    {
        if (living(inv[i]) && inv[i]->id("cuadrupedo"))
        vivos++;
    }
    if (TO->Fighting()==0)
    {
        if (vivos>0)
        {
            if (elegido->id("cuadrupedo"))
            {
                tell_room(environment(), con_caballos[random(sizeof(con_caballos))]);
            }else{
                tell_room(environment(), QueryShort()+" mira a " + elegido->QueryShort() +
                ".\n", ({elegido}));
                tell_object(elegido, QueryShort()+" te mira curioso.\n");
            }
        }else{
            tell_room(environment(), init_normal[random(sizeof(init_normal))]);
        }
    }
    return "";
}
