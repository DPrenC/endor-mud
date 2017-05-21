/****************************************************************************
Fichero: torre3_4.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: La pequeña torre sudeste del castillo.
****************************************************************************/

#include "./path.h"
#include <door.h>
#include <sounds.h>
#include <moving.h>
#include <combat.h>
inherit CASTILLO("murallas/alto_torre");
public void derrumbe();
int daño_suelo;
object abajo = find_object(CASTILLO("murallas/torre3_3"));
public int cmd_saltar(){
    play_sound(TO, SND_SUCESOS("crujir_madera"));
    play_sound(abajo, SND_SUCESOS("crujir_madera"));
    switch(daño_suelo){
        case 0:
            if (QueryIntWeight() >= 300000){
                daño_suelo=2;
                write("Te das impulso dando un gran salto y cayendo sobre el carcomido "
                "suelo de madera.\n Algunas tablas se astillan entre crujir de vigas "
                "y soportes mientras el suelo desciende unos centímetros en el centro.\n");
                say(CAP(TNAME)+" da impulso dando un gran salto y cayendo sobre el "
                "carcomido suelo de madera.\n Algunas tablas se astillan entre crujir "
                "de vigas y soportes mientras el suelo desciende unos centímetros en "
                "el centro.\n");
                SetIntLong(QueryIntLong()+ "El suelo de la torre se inclina de forma "
                "palpable hacia el centro y varios tablones aparecen medio partidos "
                "con largas astillas sobresaliendo como si la plataforma se fuera "
                "a venir abajo de un momento a otro.\n");
                AddDetail("suelo", "El suelo está hecho de madera, que por su aspecto "
                "excesivamente agrietado y debilitado podría derrumbarse en cualquier "
                "momento.\n");
                tell_room(abajo, "Algo impacta con fuerza contra el techo.\n Una "
                "intensa lluvia de polvo de madera podrida y astillas cae sobre ti "
                "mientras algunas tablas se astillan y las vigas crujen ominosamente "
                "en sus soportes.\n");
                abajo->AddDetail("techo", "El techo de tablas de maderas inestables "
                "presenta innumerables grietas dando la impresión de derrumbamiento "
                "inminente.\n");
                return 1;
            }else{
                daño_suelo=1;
                write("Das un buen salto sobre la tablazón del suelo.\n Se produce "
                "una serie de leves crujidos y chasquidos que indican que la vieja "
                "madera se resiente.\n");
                say(CAP(TNAME)+" da un buen salto sobre la tablazón del suelo.\n Se "
                "produce una serie de leves crujidos y chasquidos que indican que "
                "la vieja madera se resiente.\n");
                tell_room(abajo, "Se escucha un leve golpe en el techo.\n El armazón "
                "cruje un poco dejando caer una fina lluvia de polvo y serrín.\n");
                AddDetail("suelo", "El suelo está hecho de madera, que por su aspecto "
                "ligeramente agrietado podría derrumbarse con excesivo esffuerzo.\n");
                abajo->AddDetail("techo", "El techo de tablas de maderas inestables "
                "presenta algunas grietas.\n"); 
                return 1;
            }
            break;
        case 1:
            if (QueryIntWeight() >= 130000){
                daño_suelo=2;
                call_out("derrumbe",1);
                write("Tomando impulso das un enorme salto cayendo con todo tu peso "
                "sobre el frágil suelo de la torre.\n");
                say(CAP(TNAME)+ " toma impulso dando un enorme salto cayendo con todo "
                "su peso sobre el frágil suelo de la torre.\n");
                tell_room(abajo, "El techo sufre un brutal impacto...\n");

            }else{                
                daño_suelo=2;
                write("Te das impulso dando un gran salto y cayendo sobre el carcomido "
                "suelo de madera.\n Algunas tablas se astillan entre crujir de vigas "
                "y soportes mientras el suelo desciende unos centímetros en el centro.\n");
                say(CAP(TNAME)+" da impulso dando un gran salto y cayendo sobre el "
                "carcomido suelo de madera.\n Algunas tablas se astillan entre crujir "
                "de vigas y soportes mientras el suelo desciende unos centímetros en "
                "el centro.\n");
                SetIntLong(QueryIntLong()+ "El suelo de la torre se inclina de forma "
                "palpable hacia el centro y varios tablones aparecen medio partidos "
                "con largas astillas sobresaliendo como si la plataforma se fuera "
                "a venir abajo de un momento a otro.\n");
                AddDetail("suelo", "El suelo está hecho de madera, que por su aspecto "
                "excesivamente agrietado y debilitado podría derrumbarse en cualquier "
                "momento.\n");
                tell_room(abajo, "Algo impacta con fuerza contra el techo.\n Una "
                "intensa lluvia de polvo de madera podrida y astillas cae sobre ti "
                "mientras algunas tablas se astillan y las vigas crujen ominosamente "
                "en sus soportes.\n");
                abajo->AddDetail("techo", "El techo de tablas de maderas inestables "
                "presenta innumerables grietas dando la impresión de derrumbamiento "
                "inminente.\n");
                return 1;
            }
            break;
        case 2:
            call_out("derrumbe",1);
          
            write("Tomando impulso das un enorme salto cayendo con todo tu peso "
            "sobre el frágil suelo de la torre.\n");
            say(CAP(TNAME)+ " toma impulso dando un enorme salto cayendo con todo "
            "su peso sobre el frágil suelo de la torre.\n");
            tell_room(abajo, "El techo sufre un brutal impacto...\n");
            break;
        default:
            write("Saltas y saltas...\n Te diviertes un montón.\n");
            break;
    }
    return 1;// tengo dudas sobre este  return.
}
  

create(){
    ::create();
    daño_suelo=0;
    SetIntShort("lo alto de la torre de la Dama");
    SetIntLong("Estás en lo alto de la torre de la Dama, un espacio cuadrado y almenado "
    "con suelo de madera. Éste es sin duda el punto mas alto de la fortaleza y si miras "
    "el entorno y los alrededores se puede observar gran parte del territorio y el "
    "castillo circundantes.\n Izado sobre un largo mástil, ondea el estandarte de "
    "los Dhes-Bláin.\n");
    AddDetail("suelo", "El suelo está hecho de madera, que por su aspecto podría "
    "derrumbarse en cualquier momento.\n");
    AddExit("abajo", "./torre3_3");
    AddDoor("abajo", "una trampilla",
    "Una vieja trampilla de tablas unidas con bandas de hierro.\n",
    ({"trampilla", "abajo"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_pequena"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_puerta_pequena")]));

    AddRoomCmd("saltar", "cmd_saltar");

}

public void derrumbe(){
    object *contenido;
                    
    abajo->SetIntLong("La escalera de caracol que asciende de la planta "
    "inferior termina en esta pequeña estancia, ocupada solo por un par "
    "de catres de madera.\n Dos ventanas arqueadas dan al norte y al sur,"
    " cerradas por barrotes de hierro y postigos de madera que permiten "
    "aislar la habitación del exterior.\n El suelo está cubierto de "
    "vieja argamasa, tablas y vigas, todo ello procedente, al parecer, "
    "de lo alto donde aún se inclinan los extremos de algunos de los "
    "soportes del techo que formaba el suelo de lo alto de la torre de "
    "la Dama.\n");
    tell_room(abajo, "Todo se viene abajo en un estallido de argamasa, vigas "
    "y tablas rotas que llueven sobre ti sin misericordia.\n");
    abajo->SetIndoors(0);
    abajo->RemoveExit("arriba");
    filter(all_inventory(abajo), (:if (living($1))
        {
        $1->Defend(20+d20(2),TD_APLASTAMIENTO, DEFEND_NOMSG | DEFEND_NOLIV | DEFEND_NO_DEF_SK);
    }
    return 0;:));

    if (sizeof(contenido = all_inventory(TO)) > 0) {
        foreach (object ob: contenido) {
            if (ob->move(abajo)
            != ME_OK) {
                ob->move(abajo, M_NOCHECK);
            }
            if (living(ob)) {
                tell_object(ob, "Tras un estremecedor crujido de maderas rotas, "
                "el suelo se viene abajo arrastrándote en su caída.\n Caes al "
                "vacío...\n El demoledor impacto contra el suelo de piedra te "
                "deja sin respiración mientras trozos de vigas, tablas y agramasa "
                "llueven sin misericordia sobre ti.\n");
                ob->Defend(10+d20(2), TD_APLASTAMIENTO, DEFEND_NOLIV | DEFEND_NOMSG | 
                DEFEND_NO_DEF_SK);
                ob->AddTP(-d6());
            } 
        }
    }
    play_sound(abajo, SND_SUCESOS("caida_fuerte"));
    play_sound(abajo, SND_SUCESOS("desprendimiento"));
    play_sound(abajo, SND_SUCESOS("romper_madera"));
    abajo->AddDetail("techo", "El ruinoso techo de maderas viejas se ha "
    "venido todo abajo y ahora multitud de tablas destrozadas se encuentran "
    "esparcidas por el suelo.\n");
    TP->SetExplored();              
    TO->remove();
    if (TO) destruct(TO);

    return;
}

