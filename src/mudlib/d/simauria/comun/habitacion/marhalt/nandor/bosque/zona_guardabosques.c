/****************************************************************************
Fichero: zona_guardabosques.c
Autor: Ratwor
Fecha: 03/02/2007
Descripción: Parte del bosque donde está el roble para subir a la cabaña
demadera del guardabosques.
****************************************************************************/

#include "./path.h"
#include <skills.h>
#include <moving.h>
#include <combat.h>
#include <sounds.h>

inherit MARH("nandor/bosque/bosque_base");
public void snd_golpe();
public int f_subir(){
    if (TP->QueryIsPlayer()){
        if (TP->QueryTP()<1)
        return notify_fail("Has agotado tus fuerzas, descansa un rato.\n");
        if (TP->UseSkill(HAB_TREPAR) >= -10){
            TP->move(MARH("nandor/bosque/cabanya_guardabosques1"), M_SPECIAL,
            ({"sube a la cabaña trepando por la cuerda...",
              "llega trepando por la cuerda desde abajo...",
              "subes trepando por la cuerda hasta la cabaña..."}));
            TP->AddTP(-d3());
            return 1;
        } else {
            write ("te pones a trepar por la cuerda para subir a la cabaña... \n"
            "pero al no tener experiencia, se te resvalan las manos y caes a mitad "
            "de camino golpeándote fuertemente contra el suelo.\n");
            say (CAP(TNAME)+ " se pone a trepar por la cuerda para subir a la cabaña..."
            " \n Pero se cae golpeándose fuertemente contra el suelo.\n");
            TP->Defend(d12(),TD_APLASTAMIENTO, DEFEND_NOMSG);
            snd_golpe();
            TP->AddTP(-d3());
            return 1;
        }
    }
    return 0;
}

create()
{
    ::create();
    SetLocate("bosque de Marhalt");
    SetIntShort("lo profundo del bosque, junto a un gran roble");
    SetIntLong("Has llegado a una parte del bosque un tanto distinta, igualmente "
        "integrada en el ambiente del resto del bosque, pero como más transitada, y a "
        "su vez más tupida y más reforestada.\n De un gran roble ves que baja una "
        "gruesa cuerda desde las alturas, ciertamente esta zona no es como el resto "
        "del bosque.\n");
    AddDetail(({"construccion", "construcción", "casa", "cabaña"}), "Desde aquí abajo "
        "no se ve muy bien, mejor se verá desde arriba.\n");
    AddDetail("cuerda", "Cuelga desde lo alto del árbol, es bastante gruesa, podría "
        "aguantar perfectamente el peso de una persona.\n");
    AddDetail(({"arbol", "árbol", "roble"}), "es un fuerte y robusto roble, quizá "
        "algo más que el resto de los que te rodean.\n Le cuelga una gruesa cuerda "
        "desde arriba hasta el suelo.\n Miras hacia donde proviene y, sobre su copa,"
        " puedes ver una construcción de madera que parece una cabaña.\n");
    AddRoomCmd("gritar", "cmd_gritar");
    AddExit("este", "./bosque123");
    AddExit("nordeste", "./bosque118");
    AddExit("noroeste", "./bosque117");
    AddExit("suroeste", "./bosque127");
    AddExit("sur", "./bosque128");
    AddExit("sudeste", "./bosque129");
    AddExit("arriba", SF(f_subir));
    AddExit("trepar", SF(f_subir));
    HideExit("arriba",1);
    HideExit("trepar",1);
}

init(){
    ::init();
    call_out("presencia",1);
}

public void presencia(){
    tell_room(MARH("nandor/bosque/cabanya_guardabosques1"), "Puedes ver como "+CAP(TNAME)+
        " merodea por la base de este roble.\n");
}

public int cmd_gritar(string str){
    tell_room(MARH("nandor/bosque/cabanya_guardabosques2"), "Escuchas que alguien grita "
        "desde abajo.\n");
    if (!str){
        tell_room(MARH("nandor/bosque/cabanya_guardabosques1"), "Escuchas que "+CAP(TNAME)+
        " grita muy fuerte desde abajo.\n");
        return 0;
    }else{
        tell_room(MARH("nandor/bosque/cabanya_guardabosques1"), "Escuchas que "+CAP(TNAME)+
        " grita desde abajo: '"+str+"'.\n");
        return 0;
    }
    return 0;
}

public void snd_golpe(){
    object arriba = find_object(MARH("nandor/bosque/cabanya_guardabosques1"));
    tell_room(MARH("nandor/bosque/cabanya_guardabosques1"), CAP(TNAME)+
            " intenta subir hasta aquí trepando por la cuerda, pero se cae pegándose un "
            "fuerte golpe contra el suelo.\n");
    play_sound(TO, SND_SUCESOS("caida_fuerte"));
    play_sound(arriba, SND_SUCESOS("caida_fuerte"), 0, 30);
}

