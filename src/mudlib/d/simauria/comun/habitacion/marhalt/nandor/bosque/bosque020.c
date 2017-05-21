/****************************************************************************
Fichero: bosque020.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt. Por aqu� se cruza el r�o.
****************************************************************************/
#include "./path.h"
#include <skills.h>
#include <moving.h>
#include <combat.h>
#include <sounds.h>
inherit MARH("nandor/bosque/orilla");
public void snd_chapuzon();

public string mirar_orilla_sur(){
    object sur = find_object(MARH("nandor/bosque/bosque030"));
    write(sur->QueryIntLong()+ sur->Content());
    return "";
}

public string f_mirar_rio(){
    object rio = find_object(MARH("nandor/bosque/bosque027"));
    write(rio->QueryIntLong()+ rio->Content());
    return "";
}

int f_cruce_rio(){
    if (TP->QueryTP() <= 1) return notify_fail("Deber�as descansar antes.\n",
        NOTIFY_NOT_VALID);
    write("Te dispones a coger impulso para atravesar el r�o saltando de roca en "
        "roca...\n\n");
    if (TP->QueryIsPlayer()){
        switch(TP->UseSkill(HAB_SALTAR)){
            case -90.. -60:
                TP->move(MARH("nandor/bosque/bosque027"), M_SPECIAL,
                ({"toma impulso para saltar el r�o de roca en roca...\n Pero torpemente "
                "se cae de cabeza al agua.\n �Chooof!",
                "toma impulso para saltar el r�o de roca en roca desde la orilla norte "
                "a la del sur...\n Pero tropieza y cae de cabeza al agua junto a "
                "t�.\n �Chooof!",
                "Pero torpemente tropiezas con una piedra medio enterrada en el borde del"
                " r�o y caes de cabeza al agua.\n �Chooof!"}));
                tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
                " toma impulso para saltar el r�o de roca en roca hacia esta orilla...\n"
                " Pero parece que tropieza y cae de cabeza al r�o.\n �Choooof!.\n");
                TP->Defend(d10(2),DT_NOAIR, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
                TP->AddTP(-1);
                snd_chapuzon();
                return 1;
                break;
            case -59.. -20:
                TP->move(MARH("nandor/bosque/bosque027"), M_SPECIAL,
                ({"toma impulso para saltar el r�o de roca en roca...\n\n Salta a una de "
                "las rocas del medio del r�o...\n\n Va a saltar a la "
                "segunda, pero uno de los pies se le resvala y cae al agua.\n �Chooof!",
                "toma impulso para saltar el r�o de roca en roca desde la orilla del norte "
                "a la del sur...\n\n Salta a una de las rocas del medio del r�o...\n\n Va "
                "a saltar a la segunda, pero uno de los pies se le resvala y cae al agua "
                "junto a t�.\n �Chooof!",
                "Saltas a una de las rocas del medio del r�o...\n\n Vas a saltar a "
                "la segunda, pero uno de los pies se te resvala y caes al agua "
                "irremediablemente.\n�Chooof!"}));
                tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
                " toma impulso para saltar el r�o de roca en roca hacia esta orilla...\n\n"
                " Salta a una de las rocas del medio del r�o...\n\n Va a saltar a "
                "la segunda, pero resvala y cae en plancha al agua.\n �Choooof!.\n");
                TP->Defend(d8(2),DT_NOAIR, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
                TP->AddTP(-2);
                snd_chapuzon();
                return 1;
                break;
            case -19.. 0:
                TP->move(MARH("nandor/bosque/bosque027"), M_SPECIAL,
                ({"se dispone a saltar el r�o de roca en roca...\n\n Salta a una de las "
                "rocas del medio del r�o...\n\n Salta a la segunda...\n\n Va a saltar a la"
                " tercera... pero se resvala y cae al agua.\n �Chooof!",
                "toma impulso para saltar el r�o de roca en roca desde la orilla norte "
                "a la del sur...\n\n Salta a una de las rocas del medio del r�o...\n\n "
                "Salta a la segunda...\n\n Va a saltar a la tercera, pero se resvala "
                "y cae al agua junto a ti.\n �Chooof!",
                "Saltas a una de las rocas del medio del r�o...\n\n Saltas a la segunda"
                "...\n\n Vas a saltar a la tercera, pero te resvalas y caes al agua. "
                "\n�Chooof!"}));
                tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
                " toma impulso para saltar el r�o de roca en roca desde la orilla del "
                "norte hacia aqu�...\n\n Salta a una de las rocas del medio del "
                "r�o...\n\n Salta a la segunda...\n\n Va a saltar a la tercera, pero "
                "resvala y cae torpemente al agua.\n �Choooof!.\n");
                TP->Defend(d6(2),DT_NOAIR, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
                TP->AddTP(-3);
                snd_chapuzon();
                return 1;
                break;
            case 1..15:
                TP->move(MARH("nandor/bosque/bosque027"), M_SPECIAL,
                ({"se dispone a saltar el r�o de roca en roca...\n\n Salta a una de las "
                "rocas del medio del r�o...\n\n Salta a la segunda...\n\n Salta a la "
                "tercera...\n\n Va a saltar a la orilla norte del r�o, ya casi lo ha "
                "conseguido, pero se resvala y cae al agua.\n �Chooof!",
                "se dispone a saltar el r�o de roca en roca desde la orilla norte hacia la "
                "del sur...\n\n Salta a una de las rocas del medio del r�o...\n\n Salta "
                "a la segunda...\n\n Salta a la tercera...\n\n Va a saltar a la orilla "
                "sur del r�o, ya casi lo ha conseguido, pero se resvala y cae al agua "
                "junto a ti.\n �Chooof!",
                "Saltas a una de las rocas del medio del r�o...\n\n Saltas a la "
                "segunda...\n\n Saltas a la tercera...\n\n Vas a saltar a la orilla "
                "sur del r�o, ya casi lo has conseguido, pero te resvalas y caes al "
                "agua.\n �Chooof!"}));
                tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
                " se dispone a saltar el r�o de roca en roca desde la orilla del norte "
                "hacia esta...\n\n Salta a una de las rocas del medio del r�o...\n\n "
                "Salta a la segunda...\n\n Salta a la tercera...\n\n Ya casi ha "
                "conseguido saltar junto a t�, pero torpemente resvala y cae al "
                "agua.\n �Choooof!.\n");
                TP->Defend(d4(2),DT_NOAIR, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
                TP->AddTP(-4);
                snd_chapuzon();
                return 1;
                break;
            case 16..100:
                TP->move(MARH("nandor/bosque/bosque030"), M_SPECIAL,
                ({" se dispone a saltar el r�o de roca en roca...\n\n Salta a una de las "
                "rocas del medio del r�o...\n\n Salta a la segunda...\n\n Salta a la "
                "tercera...\n\n Y magistralmente, consigue saltar a la orilla sur del r�o",
                "se dispone a saltar el r�o de roca en roca desde la orilla del norte hacia"
                " aqu�...\n\n Salta a una de las rocas del medio del r�o...\n\n Salta a la"
                " segunda...\n\n Salta a la tercera...\n\n Y magistralmente, consigue "
                "saltar junto a t� en esta orilla.\n",
                "Saltas a una de las rocas del medio del r�o...\n\n Saltas a la segunda..."
                "\n\n Saltas a la tercera...\n\n Y magistralmente, consigues saltar a la "
                "orilla sur del r�o"}));
                tell_room(MARH("nandor/bosque/bosque027"), CAP(TP->QueryName())+
                " se dispone a saltar el r�o de roca en roca desde la orilla norte a la "
                "sur...\n\n Salta a la primera roca del r�o...\n\n Salta a la segunda..."
                "\n\n Salta a la tercera...\n\n Y, sin ning�n esfuerzo, consigue alcanzar "
                "la orilla norte del r�o.\n");
                TP->AddTP(-5);
                return 1;
                break;
            default:
                write("�Y si te caes al agua?.\n");
                say("Pero parece que se lo piensa mejor.\n",TP);
                return 1;
                break;
        }
    }
    return 0;
}

create(){
    ::create();
    SetIntShort("la orilla norte del r�o Kandal");
    SetIntLong(" Esta parte de la orilla norte del r�o parece estar m�s cerca de la  "
    "m�rgen contraria, lo que  te permitir�a cruzarlo con poca dificultad, y m�s "
    "teniendo en cuenta las 3 rocas existentes  en el medio de  la corriente  que"
    " m�s de uno habr� aprovechado para cruzar el r�o.\n Hacia el oeste se puede notar "
    "que el r�o tiene  una curva ensanchada con tendencia noroeste.\n");
    AddDetail(({"curva", "curva ensanchada"}), "El r�o se ensancha y gira ligeramente"
        " en direcci�n noroeste.\n");
    AddDetail("orilla", "�Qu� orilla quieres mirar?.\n");
    AddDetail(({"rocas", "piedras", "roca", "piedra"}), "En medio del r�o ves tres rocas"
        ", las cuales te permitir�an cruzar sin mucha dificultad a la orilla del sur.\n");
    AddDetail(({"orilla norte", "orilla del norte", "la orilla del norte", "la orilla norte"}),
        QueryIntLong());
    AddDetail(({"rio", "r�o", "aguas", "agua", "kandal", "Kandal"}), SF(f_mirar_rio));
    AddDetail(({"orilla sur", "sur", "orilla del sur", "la orilla del sur",
        "la orilla sur"}), SF(mirar_orilla_sur));

    AddRoomCmd(({"ba�arse", "nadar"}), "cmd_nadar");
    AddRoomCmd("gritar", "cmd_gritar");
    AddExit("nordeste","./bosque015");
    AddExit("este","./bosque021");
    AddExit("sur",SF(f_cruce_rio),1);
    AddExit("saltar",SF(f_cruce_rio),1);
    HideExit("saltar",1);
}

init(){
    ::init();
    call_out("presencia",1);
}

public void presencia(){
    if (present(TP, environment())){
        tell_room(MARH("nandor/bosque/bosque027"), "Ves a "+CAP(TNAME)+ " que"
        " merodea por la orilla norte.\n");
        tell_room(MARH("nandor/bosque/bosque030"), "Ves a "+CAP(TNAME)+ " que"
        " merodea por la orilla norte.\n");
    }
    return 0;
}

int cmd_nadar(){
    if (TP->UseSkill(HAB_NADAR) < 0){
        TP->move(MARH("nandor/bosque/bosque027"), M_SPECIAL,
        ({"salta a las fr�as aguas del r�o torpemente...\n �Chooof!.\n Ha ca�do en "
        "plancha y se ha tenido que hacer da�o por lo aparatoso del salto",
        "se lanza torpemente al r�o desde la orilla norte cerca de t�, haci�ndose da�o "
        "por caer en plancha al agua",
        "te lanzas al r�o de cabeza...\n �Choooof!.\n Caes en plancha y te haces un "
        "da�o horrible por todo el cuerpo"}));
        TP->Defend(d6(4),DT_NOAIR, DEFEND_F_NOLIV | DEFEND_F_NOMSG | DEFEND_NO_DEF_SK);
        tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
        " se lanza torpemente al agua desde la orilla del norte, y por lo aparatoso de "
        "la ca�da se ha tenido que hacer da�o.\n");
        TP->AddTP(-2);
        snd_chapuzon();
        return 1;
    }else{
        TP->move(MARH("nandor/bosque/bosque027"), M_SPECIAL,
        ({"se lanza magistralmente de cabeza al r�o.\n �Choooof!",
        "se lanza de cabeza al agua desde la orilla del norte junto a t� con gran maestr�a",
        "te lanzas al r�o de cabeza con gran profesionalidad.\n �Choooof!"}));
        tell_room(MARH("nandor/bosque/bosque030"), CAP(TP->QueryName())+
        " se lanza de cabeza al agua desde la orilla del norte, haci�ndolo con gran"
        " arte.\n");
        TP->AddTP(-1);
        snd_chapuzon();
        return 1;
    }
    return 0;
}

public int cmd_gritar(string str){
    if (!str){
        tell_room(MARH("nandor/bosque/bosque030"), CAP(TNAME)+" grita desde la orilla "
        "del norte.\n");
        tell_room(MARH("nandor/bosque/bosque027"), CAP(TNAME)+" grita desde la orilla "
        "del norte.\n");
        return 0;
    }else{
        tell_room(MARH("nandor/bosque/bosque030"), CAP(TNAME)+" grita desde la orilla "
        "del norte: '"+str+"'.\n");
        tell_room(MARH("nandor/bosque/bosque027"), CAP(TNAME)+" grita desde la orilla "
        "del norte: '"+str+"'.\n");
        return 0;
    }
    return 0;
}

public void snd_chapuzon(){
    object rio = find_object(MARH("nandor/bosque/bosque027"));
    object norte = find_object(MARH("nandor/bosque/bosque020"));
    object sur = find_object(MARH("nandor/bosque/bosque030"));
    play_sound(({norte, sur, rio}), SND_SUCESOS("chapuzon"), 0, 80);
}
