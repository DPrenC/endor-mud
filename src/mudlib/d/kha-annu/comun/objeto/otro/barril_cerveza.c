/****************************************************************************
Fichero: barril_cerveza.c
Autor: Buh
Fecha: 02/09/2007
Descripción: Un barril de cerveza negra para llevarselo a Ungrim.
****************************************************************************/
#include <properties.h>
#include <sounds.h>
#define BARRIL_ROTO "barril_roto_suelo"

inherit THING;

create(){
    ::create();
    AddId(({"barril", "barril de cerveza", "barril de cerveza negra"}));
    SetShort("un barril de cerveza negra");
    SetLong("Es un gran barril de madera vieja,lleno de cerveza negra de Kha-annu.\n");
    SetWeight(30000);
    Set(P_SIZE,P_SIZE_MEDIUM);
    SetValue(10000);
}

public void init(){
    ::init();
    add_action("cmd_beber", "beber");
    add_action("cmd_beber", "abrir");
    add_action("cmd_romper", "romper");
    add_action("cmd_romper", "lanzar");
    add_action("cmd_romper", "tirar");
}
public int cmd_beber(string str){
    if(!str) return 0;
    if(str=="barril" || str=="barril de cerveza"  || str=="barril de cerveza negra"
        || str=="cerveza" ||str=="cerveza negra")
        return notify_fail("Seguro que hay algún amante de la cervveza que te lo "
        "agradecerá más que tu cuerpo.\n", NOTIFY_NOT_VALID);
}

public int cmd_romper(string str){
    if (!str) return notify_fail("¿Qué quieres romper?.\n");
    if (str=="barril" || str=="barril de cerveza" || str=="barril de cerveza negra"){
        write("Alzas en lo alto el barril, por encima de tu cabeza, y lo estampas "
        "contra el suelo con todas tus fuerzas.\n");
        say(CAP(TNAME)+" Alza un barril por encima de su cabeza y lo estampa contra "
        "el suelo.\n",TP);
        tell_room(environment(TP), "El barril se ha despedazado por completo "
        "convirtiéndose en un montón de astillas y esparciendo la espumosa cerveza "
        "negra por todo el suelo.\n");
        play_sound(environment(TP), SND_SUCESOS("romper_madera"),0,80);
        if (environment(TP)->Query(BARRIL_ROTO) !=1){
            environment(TP)->AddDetail("astillas", "Las astillas del barril.\n");
            environment(TP)->SetIntLong(environment(TP)->QueryIntLong()+
            " Está todo el suelo lleno de espumosa cerveza negra.\n");
            environment(TP)->SetIntSmell("Hay un fuerte olor a cerveza.\n");
            environment(TP)->AddDetail(({"cerveza","cerveza negra",
                "espumosa cerveza","espumosa cerveza negra"}),
                "Hay cerveza esparcida por todo el suelo.\n");
            environment(TP)->Set(BARRIL_ROTO,1);
        }
        return remove();
    }
}
