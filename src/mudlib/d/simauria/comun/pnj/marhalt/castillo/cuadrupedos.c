/****************************************************************************
Fichero: cuadrupedos.c
Autor: Ratwor
Fecha: 01/10/2006
Descripción: animales para las cuadras.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
#include <sounds.h>
inherit NPC;
int ayuda;
public void snd_relincho();
create()
{
    ::create();
    string *ccaballos=({" marrón", " negro", " blanco", " gris", " pardo", " moteado"});
    string *cyeguas=({" blanca", " negra", " marrón", " gris", " parda", " moteada"});
    string *cmulas=({" parda", " gris"});
    string color_m= ccaballos[random(sizeof(ccaballos))];
    string color_f= cyeguas[random(sizeof(cyeguas))];
    string color_mula=cmulas[random(sizeof(cmulas))];
    switch(d3())
    {
        case 1:
            AddId(({color_m, "caballo "+color_m, "caballo"}));
            SetStandard("un caballo"+color_m, "cuadrupedo", ([GC_TORPE:14+d2()]), GENDER_MALE);
            SetShort("un caballo"+color_m);
            SetLong("Es un bonito caballo"+color_m+" grande y robusto.\n");
            break;
        case 2:
            AddId(({color_f, "yegua "+color_f, "yegua"}));
            SetStandard("una yegua"+color_f, "cuadrupedo", ([GC_TORPE:12+d2()]), GENDER_FEMALE);
            SetShort("una yegua"+color_f);
            SetLong("Una hermosa yegua"+color_f+", parece algo presumida, pero a la "
            "vez se le nota que es un buen ejemplar y está bien cuidada.\n");
            break;
        case 3:
            AddId(({color_mula, "mula "+color_mula, "mula"}));
            SetStandard("una mula"+color_mula, "cuadrupedo", ([GC_TORPE:10+d2()]), GENDER_FEMALE);
            SetShort("una mula"+color_mula);
            SetLong("Una interesante mula adulta, de color"+color_mula+", es bonita y parece"
            " revosar de alegría.\n");
            break;
    }
    AddId(({"cuadrupedo", "animal"}));
    SetWeight(500000);
    SetSmell("Huele a lo típico que se huele siendo un animal como este.\n");
    SetCitizenship("nandor");
    Set(P_HANDS, ({
    ({"la pata trasera derecha", 0, 6}),
    ({"la pata trasera izquierda", 0, 6}),
    ({"un mordisco", 1, 7})}));
    SetSize(P_SIZE_LARGE);
    InitChats(3, ({SF(snd_relincho), SF(snd_relincho),
    QueryShort()+" come un poco de pienso.\n",
    QueryShort()+" no parece prestarte especial atención.\n",
    QueryShort()+" mueve la cola animadamente.\n",
    QueryShort()+" espanta una mosca con la cola.\n",
    QueryShort()+" mueve la cabeza.\n"}));

}

public void init()
{
    ::init();
    add_action("montar", "montar");
}

public int montar(string str){
    if(!str) return notify_fail("¿Qué quieres montar?\n");
    object montura = present(str);
    if (montura && living(montura) ){
        write("Te subes a " +montura->QueryShort()+ " y montas con maestría, te sientes superior ahí "
        "ariba...\n  El animal parece que no se siente tan agusto, pierdes el control y de"
        " un movimiento brusco te tira al suelo.\n Por poco te matas con la caída...\n");
        say(CAP(TNAME)+ " se monta en " +montura->QueryShort() + " y la cara se le ilumina como si "
        "estuviera disfrutando del momento, pero no termina de dominar la situación y de"
        " un movimiento brusco cae irremediablemente al suelo dándose un brutal golpe.\n", TP);
        TP->Defend(d20(),TD_APLASTAMIENTO,DEFEND_NOMSG);
        play_sound(environment(), SND_SUCESOS("caida_fuerte"));
        return 1;
    }
    return notify_fail("No podrás montar lo que no está.\n");
}

public void snd_relincho(){
    tell_room(environment(), "Hiiii...hiiiiii....brrrr...\n");
    play_sound(environment(), SND_PNJS("relincho"));
}
