/****************************************************************************
Fichero: trampa.c
Autor: Ratwor
Fecha: 10/02/2007
Descripción: Una trampa en medio del bosque de Marhalt.
****************************************************************************/


#include "./path.h"
#include <skills.h>
#include <moving.h>
#include <combat.h>
#include <sounds.h>
public void snd_golpe();
inherit SIM_ROOM;

object arriba, obsequio;
int subir, encontrado;
int busqueda = d4();

public string f_descripcion(){
    arriba=find_object(MARH("nandor/bosque/bosque087"));
    if (!arriba || !present("cuerda", arriba))
    return "Te encuentras en un estrecho foso bajo el suelo del bosque de Marhalt,"
        " alguien lo ha debido de construir a propósito para utilizarlo como trampa, "
        "o al menos ese era su objetivo, pues así lo indican unos pinchos oxidados que "
        "sobre salen del suelo.\n La salida del foso se encuentra varios metros por "
        "encima de tu cabeza, siendo practicamente imposible salir sin la ayuda de "
        "una cuerda o algo similar.\n Clavado en los pinchos puedes ver un esqueleto "
        "humano con unos trapos hechos girones que algún día debió de ser ropa.\n";

    return "Te encuentras en un estrecho foso bajo el suelo del bosque de Marhalt,"
        " alguien lo ha debido de construir a proposito para utilizarlo como trampa, "
        "o al menos ese era su objetivo, pues así lo indican unos pinchos oxidados que "
        "sobre salen del suelo.\n La salida del foso se encuentra varios metros por "
        "encima de tu cabeza, donde sería fácil salir trepando ayudándote con la cuerda "
        "que cuelga de arriba.\n Clavado en los pinchos puedes ver un esqueleto "
        "humano con unos trapos hechos girones que algún día debió de ser ropa.\n";
}

public string f_mirar_cuerda(){
    arriba=find_object(MARH("nandor/bosque/bosque087"));
    if (arriba || present("cuerda", arriba))
    return "Es una simple cuerda que cuelga desde la abertura de arriba para que "
        "puedas subir trepando.\n";
}

public string f_encontrar(){
    write("Lo que alguna vez pudo ser ropa, hoy sólo es un montón de hilachos.\n");
    if (busqueda==1 && encontrado==0){
        encontrado=1;
        obsequio = clone_object("/d/simauria/comun/objeto/otro/gema");
        obsequio->AddId(({"piedra", "piedra preciosa"}));
        obsequio->move(environment(TP));
        return "Entre la ropa destrozada encuentras lo que parece una piedra preciosa.\n";
    }
    return "";
}

public int f_subida(){
    arriba=find_object("/d/simauria/comun/habitacion/marhalt/nandor/bosque/bosque087");
    if (!TP->QueryIsPlayer())  return 0;
    if (!arriba || !present("cuerda", arriba))
        return notify_fail("necesitarás que alguien te eche una cuerda desde arriba "
        "para que puedas subir...\n", NOTIFY_NOT_VALID);
    if (TP->UseSkill(HAB_TREPAR) <= -10){
        write("Intentas subir por la cuerda, pero apenas subes un par de metros vuelves"
        " a caer fuertemente sobre los pinchos.\n");
        say(CAP(TNAME)+ " sube un par de metros por la cuerda, pero vuelve a caer "
        "fuertemente sobre los pinchos.\n");
        tell_room(MARH("nandor/bosque/bosque087"), CAP(TNAME)+ " intenta salir del foso "
        "por la cuerda, pero no lo consigue.\n");
        TP->Defend(d10(),DT_PIERCE,DEFEND_NOMSG);
        snd_golpe();
        return 1;
    }else{
        TP->move(MARH("nandor/bosque/bosque087"), M_SPECIAL,
        ({"sube ágilmente por la cuerda saliendo del foso",
        "sale del foso ayudándose con la cuerda",
        "trepas por la cuerda ágilmente saliendo por fin de el maldito foso"}));
        return 1;
    }
    return 0;
}

create()
{
    ::create();
    SetLocate("el bosque de Marhalt");
    SetIntShort("un foso");
    SetIntLong(SF(f_descripcion));
    SetIntNoise("Por arriba te llega el sonido del bosque.\n");
    SetIntSmell("Desde luego que bien no huele.\n");
    SetIndoors(0);
    AddDetail("cuerda",SF(f_mirar_cuerda));
    AddDetail(({"arriba", "techo","cielo"}), "Varios metros por encima de tu cabeza "
        "puedes ver el cielo que se ve desde el bosque, ciertamente preferirías verlo "
        "desde allí en vez que desde aquí abajo.\n");
    AddDetail(({"pinchos", "pincho", "pinchos oxidados", "pincho oxidado", "suelo"}),
        "Del suelo sobresalen una veintena de pinchos oxidados, donde algún día años "
        "atrás, se clavó el cadaver del pobre infeliz que te acompaña en tan lúgubre"
        " estancia.\n");
    AddDetail(({"esqueleto", "cadaver", "cadáver"}), "Parece de humano, no sabrías "
        "acertar cuanto tiempo lleva aquí.\n");
    AddDetail(({"ropa", "trapos", "ropas", "tela", "girones"}), SF(f_encontrar));
    AddDetail(({"pared", "paredes"}), "Las paredes están bastante juntas entre ellas, "
        "las adornan algunas raices, rocas y tierra.\n");
    AddDetail("tiempo", "Desde aquí abajo no se aprecia muy bien, si estuviera "
        "lloviendo quizá te cayera algo de agua.\n");
    ForbidAllMagic("Te concentras...\n Te concentras...\n La proximidad de las paredes"
        " del foso hace revotar la energía mental que precisas para utilizar tu magia "
        "y no consigues ningún resultado.\n");
    AddExit("arriba", SF(f_subida));
    AddExit("subir", SF(f_subida));
    HideExit("subir", 1);
    HideExit("arriba", 1);
    AddRoomCmd("gritar", "cmd_gritar");
    AddRoomCmd("silbar", "cmd_silbar");
    AddItem(OTRO("marhalt/nandor/cable"),REFRESH_REMOVE,1);

}

public int cmd_gritar(string str){

    tell_room(MARH("nandor/bosque/bosque088"), "Escuchas unos gritos apagados que "
    "proviennen desde el oeste.\n");
    tell_room(MARH("nandor/bosque/bosque091"), "Escuchas unos gritos apagados que "
    "proviennen desde el norte.\n");
    tell_room(MARH("nandor/bosque/bosque078"), "Escuchas unos gritos apagados que "
    "proviennen desde el sur.\n");
    tell_room(MARH("nandor/bosque/bosque079"), "Escuchas unos gritos apagados que "
    "proviennen desde el suroeste.\n");

    if (!str){
        tell_room(MARH("nandor/bosque/bosque087"), "Escuchas a alguien gritar bajo "
        "tierra.\n");
        return 0;
    }else{
        tell_room(MARH("nandor/bosque/bosque087"), "Escuchas a alguien gritar bajo "
        "tierra: '" +str+ "'.\n");
        return 0;
    }
    return 0;
}

public int cmd_silbar(){
    write("Silbas fuerte, pero el sonido no debe llegar muy lejos, da la impresión que"
        " la proximidad de las paredes del foso amortigua el silbido.\n");
    say(CAP(TNAME)+" silba, pero la proximidad de las paredes y el poco espacio "
        "atenúan casi por completo el sonido.\n");
    return 1;
}

public void snd_golpe(){
    arriba=find_object(MARH("nandor/bosque/bosque087"));
    play_sound(arriba, SND_SUCESOS("caida_fuerte"), 0, 20);
    play_sound(TO, SND_SUCESOS("caida_fuerte"));
}
