/****************************************************************************
Fichero: cubilete.c
Autor: Ratwor
Fecha: 28/07/2006
Descripción: un cubilete de dados para tirar los dados. Lo llevará Jerton en la posada de gorat.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <sounds.h>

inherit THING;

public int cmd_tirar (string str)
{
    int tirada;
    if (str=="los dados" || str=="dados")
    {
        tirada = d6(3);
        play_sound(environment(TP), SND_SUCESOS("lanzar_dados"));
        if (environment() == TP)
        {
            write("Ajitas el cubilete y con arte tiras los dados sacando " + tirada + ".\n");
            say(CAP(TP->QueryRealName()) + " ajita el cubilete, con cara de concentración, "
            "y tira los dados sacando " + tirada + ".\n", TP);
            return 1;
        }
        write("Coges el cubilete, lo ajitas, y lanzas los dados sacando " + tirada +
        ".\n Vuelves a meter los dados en el cubilete y lo dejas donde estaba.\n");
        say(CAP(TP->QueryRealName()) + " coge el cubilete, lo ajita y saca " + tirada +
        ".\n  Luego recoge los dados y deja el cubilete donde estaba.\n", TP);
        return 1;
    }
    return notify_fail("¿Qué quieres tirar?.\n", NOTIFY_NOT_VALID);
}

public int cmd_agitar(string str){
    if (!str) return notify_fail("¿Qué quieres agitar?\n");
    if (str=="cubilete" || str=="dados"){
        play_sound(environment(TP), SND_SUCESOS("agitar_dados"));
        if (environment()==TP){
            write("Agitas el cubilete con gracia haciendo sonar los dados.\n");
            say(CAP(TNAME)+ " agita el cubilete haciendo sonar los dados.\n");
            return 1;
        }else{
            write("Coges el cubilete, lo agitas haciendo sonar los dados, y lo "
            "vuelves a dejar donde estaba.\n");
            say(CAP(TNAME)+ " coge el cubilete, lo agita haciendo sonar los dados, "
            "y lo vuelve a dejar donde estaba.\n", TP);
            return 1;
        }
    }
    return notify_fail("Crees que agitando eso conseguirás algo?\n");
}

create()
{
    ::create();
    SetShort("un cubilete con dados");
    SetLong("Es un cubilete de piel dura que contiene 3 dados en su interior.\n");
    AddId("cubilete");
    SetWeight(300);
    SetValue(800);
    SetSize(P_SIZE_SMALL);
    SetNoise("Ajitas el cubilete y se oye el choque de los dados en su interior.\n");
    SetSmell("Huele a piel.\n");
    AddSubDetail("dados", "Hay 3 dados de 6 caras, del 1 al 6, claro.\n");
}

public void init()
{
    ::init();

    add_action("cmd_tirar", "tirar");
    add_action("cmd_tirar", "lanzar");
    add_action("cmd_agitar", "agitar");
}


