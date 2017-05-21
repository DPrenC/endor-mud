/****************************************************************************
Fichero: patio12.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"
#include <sounds.h>
inherit CASTILLO("patio/patio_base");

int contiene_cubo;
public int cmd_llenar(string str){
    if(str!="cubo" || !str)
        return notify_fail("Qué dices que quieres llenar?\n");
    if(contiene_cubo>=20)
        return notify_fail("El cubo contiene mucha agua, no es necesario llenarlo más.\n");
    write("Giras la manivela haciendo descender el cubo hasta que lo oyes chapotear en "
    "el agua, acto seguido comienzas a girar la manivela en sentido contrario, con gran "
    "trabajo, alzando el cubo de agua hasta la boca del pozo.\n");
    say(CAP(TNAME)+" gira la manivela haciendo descender el cubo hasta que se oye "
    "chapotear en el agua del interior del pozo, tras lo cual gira en sentido contrario "
    "para sacar el cubo ya lleno hasta la superficie.\n");
    contiene_cubo=25+d10(2);
    TP->AddTP(d3());
    return 1;
}

public int cmd_vaciar(string str){
    if(!str || str!="cubo")
        return notify_fail("¿Qué dices que quieres vaciar?\n");
    if(!contiene_cubo)
        return notify_fail("El cubo no tiene agua para tener que vaciarlo.\n");
    write("Vuelcas el cubo en el interior del pozo, donde cae todo el agua que contenía.\n");
    say(CAP(TNAME)+" vuelca el cubo dentro del pozo para vaciarlo de agua.\n");
    contiene_cubo=0;
    TP->SetExplored();
    return 1;
}

public int cmd_beber(string str){
    if(!str) return notify_fail("¿Qué quieres beber?\n");
    if(str=="agua" || str=="agua del cubo" || str=="agua de cubo")
    {
        if(contiene_cubo>0)
        {
            if(TP->QueryDrink()<TP->QueryMaxDrink())
            {
                write("Metes la cabeza en el cubo y bebes un buen trago de agua fresca.\n");
                say(CAP(TNAME)+" mete la cabeza dentro del cubo del pozo para beber agua, tras lo "
                "cual la saca con la cara chorreando.\n");
                play_sound(TO, SND_SUCESOS("beber"));
                TP->AddDrink(d6());
                if(TP->QueryHP()<TP->QueryMaxHP()) TP->AddHP(d2());
                contiene_cubo--;
                return 1;
            }
            return notify_fail("Ahora mismo no tienes sed.\n", NOTIFY_NOT_VALID);
        }
        return notify_fail("El cubo no tiene agua para beber, tendrás que llenarlo.\n");
    }else{
        if(str=="agua de pozo" || str=="agua del pozo"){
            say(CAP(TNAME)+" mete la cabeza dentro del pozo con la intención de beber agua, "
            "pero tras meter medio cuerpo se da cuenta que no consigue llegar al agua "
            "y desiste de su empeño.\n");
            write("Metes la cabeza dentro del pozo, pero te das cuenta que "
            "el agua queda demasiado abajo, mejor bebe del cubo.\n");
            return 1;
        }
        return notify_fail("El contenido del pozo debe de ser agua, por si te interesa mejor.\n");
    }
}


public string f_cubo(){
    string agua;
    if(contiene_cubo>=30)
        agua="Contiene mucha agua en su interior.\n";
    if(contiene_cubo<30 && contiene_cubo>10)
        agua="Contiene agua en su interior.\n";
    if(contiene_cubo<=10 && contiene_cubo>0)
        agua="Contiene muy poca agua en su interior.\n";
    if(!contiene_cubo)
        agua="Está vacío, no contiene ni una gota de agua.\n";
    return "Un pesado cubo de madera del tamaño suficiente para que un "
    "hombre pueda caber agachado, fabricado con multitud de anchos listones unidos por "
    "dos bandas circulares de hierro que forman el  borde superior y la parte inferior, "
    "con las partes de unión rellenas de brea para evitar que el contenido se derrame "
    "por alguna grieta. Unida a la parte superior hay un asa en forma de arco con una "
    "argolla a la que se engancha la cuerda que tira del cubo.\n"+agua;
}

create(){
    ::create();
    SetIntShort("el patio de armas, junto a un pozo");
    SetIntLong(QueryIntLong()+"Aquí se encuentra la fuente de agua del castillo, un "
    "ancho pozo rodeado de un muro bajo. El cubo que recoge el agua cuelga de un "
    "travesaño horizontal que  se apoya sobre dos postes verticales con el extremo "
    "superior ahorquillado. En los extremos del travesaño se encajan dos manivelas para "
    "hacerlo girar recogiendo o soltando la cuerda de la que cuelga el cubo.\n"
    "Al norte una escalera de piedra asciende a la muralla.\n");
    AddDetail("muro", "Un muro que llega a la altura de la cintura hecho con piedras  "
    "irregulares, cubiertas de moho en su parte inferior. Su anchura es suficiente como "
    "para sentarse sobre él.\n");
    AddDetail("cubo", SF(f_cubo));
    AddDetail("pozo", "Te asomas al pozo, que se hunde en el corazón de la colina, y no "
    "aciertas a ver el fondo sumido en las sombras.\n");
    AddDetail(({"manivela", "manivelas"}), "Son de hierro y tienen forma de cruz. Van "
    "encajadas en los extremos del travesaño, entre unas lengüetas metálicas que frenan "
    "el giro del conjunto impidiendo que el propio peso del cubo lo hagan bajar con "
    "demasiada brusquedad estampándose contra el fondo del pozo.\n");
    AddDetail("travesaño", "Un simple tronco de grosor medio con la parte media "
    "rebajada para enrrollar la cuerda del cubo.\n");
    AddDetail("escalera", "Una empinada escalera de piedra con algunos escalones a "
    "medio derrumbar que une el patio de armas con la muralla norte.\n");
    AddExit("este", "./patio13");
    AddExit("oeste",  "./patio11");
    AddExit("norte", "./patio06");
    AddExit("nordeste", "./patio07");
    AddExit("noroeste", "./patio05");
    AddExit("sur", "./patio14");
    AddExit("sudeste", "./patio15");
    AddRoomCmd("llenar", "cmd_llenar");
    AddRoomCmd(({"vaciar", "volcar"}), "cmd_vaciar");
    AddRoomCmd("beber", "cmd_beber");
}


