/****************************************************************************
Fichero: zona_guardabosques.c
Autor: Ratwor
Fecha: 03/02/2007
Descripci�n: Parte del bosque donde est� el roble para subir a la caba�a
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
            ({"sube a la caba�a trepando por la cuerda...",
              "llega trepando por la cuerda desde abajo...",
              "subes trepando por la cuerda hasta la caba�a..."}));
            TP->AddTP(-d3());
            return 1;
        } else {
            write ("te pones a trepar por la cuerda para subir a la caba�a... \n"
            "pero al no tener experiencia, se te resvalan las manos y caes a mitad "
            "de camino golpe�ndote fuertemente contra el suelo.\n");
            say (CAP(TNAME)+ " se pone a trepar por la cuerda para subir a la caba�a..."
            " \n Pero se cae golpe�ndose fuertemente contra el suelo.\n");
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
        "integrada en el ambiente del resto del bosque, pero como m�s transitada, y a "
        "su vez m�s tupida y m�s reforestada.\n De un gran roble ves que baja una "
        "gruesa cuerda desde las alturas, ciertamente esta zona no es como el resto "
        "del bosque.\n");
    AddDetail(({"construccion", "construcci�n", "casa", "caba�a"}), "Desde aqu� abajo "
        "no se ve muy bien, mejor se ver� desde arriba.\n");
    AddDetail("cuerda", "Cuelga desde lo alto del �rbol, es bastante gruesa, podr�a "
        "aguantar perfectamente el peso de una persona.\n");
    AddDetail(({"arbol", "�rbol", "roble"}), "es un fuerte y robusto roble, quiz� "
        "algo m�s que el resto de los que te rodean.\n Le cuelga una gruesa cuerda "
        "desde arriba hasta el suelo.\n Miras hacia donde proviene y, sobre su copa,"
        " puedes ver una construcci�n de madera que parece una caba�a.\n");
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
            " intenta subir hasta aqu� trepando por la cuerda, pero se cae peg�ndose un "
            "fuerte golpe contra el suelo.\n");
    play_sound(TO, SND_SUCESOS("caida_fuerte"));
    play_sound(arriba, SND_SUCESOS("caida_fuerte"), 0, 30);
}

