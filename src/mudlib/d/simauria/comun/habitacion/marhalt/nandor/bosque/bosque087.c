/****************************************************************************
Fichero: bosque087.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
Aqu� hay una trampa.
****************************************************************************/

#include "./path.h"
#include <moving.h>
#include <combat.h>
#include <skills.h>
#include <sounds.h>
inherit MARH("nandor/bosque/bosque_base");
int hay_cuerda;
#define P_AVISO_NO_CUERDA "aviso_no_cuerda"
public void snd_golpe();
public int f_bajada(){
    if (!TP->QueryIsPlayer()) return 0;
    if (!hay_cuerda){
        if (TP->Query(P_AVISO_NO_CUERDA)!=1){
            TP->Set(P_AVISO_NO_CUERDA,1);
            return notify_fail("Sin la ayuda de una cuerda no es muy aconsejable "
            "bajar a ese agujero.\n");
        }else{
            TP->move(MARH("nandor/bosque/trampa"), M_SPECIAL,
            ({"se tira de cabeza por el agujero",
            "cae de cabeza desde arriba estamp�ndose contra los pinchos",
            "te lanzas por el agujero sin cuerda...\n  el descenso se te hace largo, "
            "pero un fuerte golpe contra el suelo del foso lleno de pinchos frena la "
            "ca�da en seco"}));
            TP->Defend(50,TD_APLASTAMIENTO, DEFEND_NOMSG);
            snd_golpe();
            return 1;
        }
    }
    if (TP->UseSkill(HAB_TREPAR)<= 0){
        TP->move(MARH("nandor/bosque/trampa"), M_SPECIAL,
        ({"baja por la cuerda al interior del agujero...",
        "cae torpemente desde arriba estamp�ndose contra los pinchos del suelo",
        "empiezas a bajar por la cuerda hacia el interior del agujero, pero tu "
        "inexperiencia trepando te hace caer dentro del foso de mala manera estamp�ndote"
        " contra el suelo lleno de pinchos"}));
        TP->Defend(40,TD_APLASTAMIENTO, DEFEND_NOMSG);
        snd_golpe();
        return 1;
    }else{
        TP->move(MARH("nandor/bosque/trampa"), M_SPECIAL,
        ({"baja por el agujero del suelo ayud�ndose con la cuerda...",
        "llega desde arriba bajando por la cuerda",
        "bajas por la cuerda hasta el interior del foso..."}));
        return 1;
    }
    return 0;
}

public string f_tronco(){
    if (!hay_cuerda)
        return "Es un tronco cortado hace muchos a�os que apenas sobresale medio "
        "metro del suelo.\n";
        return "Es un tronco cortado hace muchos a�os que apenas sobresale medio "
        "metro del suelo. Ahora tiene una cuerda atada a �l que se mete directamente "
        "en el agujero.\n";
}

public string f_agujero(){
    if (!hay_cuerda)
        return "Es un agujero de m�s o menos un metro de di�metro, casi tapado por "
        "la vegetaci�n,  de forma que  no se ve el fondo  aunque se intuye que es  "
        "profundo.\n";
        return "Es un agujero de m�s o menos un metro de di�metro, casi tapado por la "
        "vegetaci�n,  de forma que  no se ve el fondo  aunque se intuye que es  "
        "profundo.\n  Una cuerda, que est� atada a un tronco cercano, entra en el "
        "agujero hacia las profundidades del foso.\n";
}

create(){
    ::create();
    SetIntShort("el bosque de Marhalt, junto a un gran toc�n");
    SetIntLong("Sigues en un ambiente total de vegetaci�n, rode�ndote los mismos "
        "robles y hayas que te acompa�an a lo largo y ancho del bosque de Marhalt. \n"
        " En esta parte concretamente rompe la monoton�a un agujero de poco m�s "
        "de un metro en el suelo, por el que a buen seguro te hubieras ca�do de no "
        "haberlo visto. Apenas un par de metros junto al agujero, puedes ver el "
        "tronco de un �rbol cortado hace mucho tiempo.\n");
    AddDetail(({"tronco", "arbol cortado", "arbol", "�rbol", "�rbol cortado", "toc�n",
         "tocon"}), SF(f_tronco));
    AddDetail(({"agujero", "trampa", "agujero del suelo", "agujero de suelo"}),
        SF(f_agujero));
    AddDetail("suelo", "Es igual que el resto del suelo del bosque, pero en esta "
        "parte puedes ver un agujero con pinta de ser una trampa.\n");
    AddDetail(({"dentro del agujero", "dentro de agujero", "abajo"}), "No se ve mucho,"
        " el agujero es bastante profundo.\n");
    AddExit("norte","./bosque078");
    AddExit("nordeste","./bosque079");
    AddExit("sur", "./bosque091");
    AddExit("este", "./bosque088");
    AddExit("abajo", SF(f_bajada));
    AddExit("bajar", SF(f_bajada));
    HideExit("bajar",1);
    HideExit("abajo",1);
    AddRoomCmd("atar", "cmd_atar");
    AddRoomCmd("desatar", "cmd_desatar");
    AddRoomCmd("gritar", "cmd_gritar");
    }

init(){
    ::init();
    if (d12()==1) call_out("caer",1);
}

public void caer(){
    if (TP->QueryIsPlayer() && present(TP, environment())){
        if ((TP->QueryInt()+TP->QueryDex()) < 35){
            TP->move(MARH("nandor/bosque/trampa"), M_SPECIAL,
            ({"camina demasiado cerca del agujero del suelo y se cae t�rpemente hacia "
                "las profundidades",
            "cae desde arriba junto a t� estamp�ndose contra los pinchos del suelo",
            "caminas demasiado cerca del borde del agujero del suelo y, en un paso mal "
            "dado, caes hacia las profundidades golpe�ndote repetidas veces hasta que "
            "frenas en seco clav�ndote unos oxidados pinchos"}));
            TP->Defend(50,TD_APLASTAMIENTO, DEFEND_NOMSG);
            snd_golpe();
        }else{
            write("Te hacercas demasiado al borde del abujero, pero consigues mantener "
            "el equilibrio y te salvas de caerte al interior.\n");
            say(CAP(TNAME)+ " casi se cae por el agujero, pero gracias a su equilibrio "
            "consigue mantenerse en la superficie.\n");
        }
    }
    return 0;
}

public int cmd_desatar(string str){
    if (!str) return notify_fail("�Qu� quieres desatar?", NOTIFY_NOT_VALID);
    if (str=="cuerda" || str=="la cuerda" || str=="CUERDA DE ARBOL" ||
        str=="cuerda de �rbol" || str=="cuerda de tronco" || str=="cuerda del arbol" ||
        str=="cuerda del �rbol" || str=="cuerda del tronco"){
        if (!hay_cuerda) return notify_fail("No hay ninguna cuerda para desatar.\n",
            NOTIFY_NOT_VALID);
        return notify_fail("La cuerda est� fuertemente atada, va a ser imposible "
            "desatarla.\n", NOTIFY_NOT_VALID);
    }
    return notify_fail("Eso no se puede desatar.\n", NOTIFY_NOT_VALID);
}

public int cmd_atar(string str){
if (!str) return notify_fail("�Qu� quieres atar y a d�nde?\n",
    NOTIFY_NOT_VALID);
    if (str=="cuerda a arbol" || str=="cuerda a �rbol" ||
        str=="cuerda a tronco" || str=="cuerda al arbol" || str=="cuerda al �rbol" ||
        str=="cuerda al tronco" || str=="cuerda a tocon" || str=="cuerda a toc�n"
        || str=="cuerda al tocon" || str=="cuerda al toc�n"){
        if (hay_cuerda==1) return notify_fail("Eso que quieres hacer ya est� hecho.\n",
            NOTIFY_NOT_VALID);
        object cuerda = present("cuerda", TP);
        if (cuerda){
            write("atas la cuerda fuertemente al tronco del �rbol que hay junto al "
            "agujero y echas el resto de la cuerda en el interior.\n");
            say(CAP(TNAME)+ "  ata una cuerda a un tronco que hay proximo al agujero del "
            "suelo y echa el resto de la cuerda en el interior.\n");
        tell_room(MARH("nandor/bosque/trampa"), "Alguien tira una cuerda desde arriba "
        "para que puedas salir trepando por ella.\n");
            hay_cuerda=1;
            cuerda->SetNoGet("Est� fuertemente atada al tronco, no podr�s moverla de"
            " ah�.\n");
        cuerda->SetShort("una cuerda atada a un tronco");
        cuerda->SetLong("Es una simple cuerda fuertemente atada al tronco.\n");
            cuerda->move(TO, M_SILENT);
            return 1;
        }
        return notify_fail("No tienes cuerda.\n", NOTIFY_NOT_VALID);
    }
    return notify_fail("�Qu� quieres atar y a d�nde?\n",
    NOTIFY_NOT_VALID);
}

public int cmd_gritar(string str){
    if (!str){
        tell_room(MARH("nandor/bosque/trampa"), "Escuchas que "+CAP(TNAME)+" grita desde "
        "arriba.\n");
    }else{
        tell_room(MARH("nandor/bosque/trampa"), "Escuchas que "+CAP(TNAME)+" grita desde"
        " arriba: '" +str+ "'.\n");
    }
    return 0;
}

public void snd_golpe(){
    object abajo = find_object(MARH("nandor/bosque/trampa"));
    play_sound(({TP, abajo}), SND_SUCESOS("caida_fuerte"));
    play_sound(TO, SND_SUCESOS("caida_fuerte"), 0, 20);
}

