/*
DESCRIPCION  : Habitacion base de la senda del bosque de la fortaleza
FICHERO      : senda.c
MODIFICACION : 5-07-00 [Maler] Creacion
*/

#include "path.h"
inherit SIM_ROOM;

public void AnyadirPnjs(){
    switch(random(100))
    {
        case 0..4:AddItem(PNJFB("aguila"),REFRESH_DESTRUCT,1);break;
        case 5..9:AddItem(PNJFB("bandido"),REFRESH_DESTRUCT,1);break;
        case 10..14:AddItem(PNJFB("canario"),REFRESH_DESTRUCT,1);break;
        case 15..29:AddItem(PNJFB("ave_rnd"),REFRESH_DESTRUCT,1);break;
        case 30..34:AddItem(PNJFB("conejo"),REFRESH_DESTRUCT,1);break;
        case 35..39:AddItem(PNJFB("golondrina"),REFRESH_DESTRUCT,1);break;
        default:break;
    }
}

create()
{
    ::create();
    SetIntShort("una senda a través del bosque");
    switch(d6()){
        case 1:
            SetIntLong("Estás en una senda que recorre de norte a sur el bosque de Cored,"
                " una tupida extensión verde llena de árboles y fauna salvaje. No es "
                "aconsejable merodear por aquí a solas, nunca se sabe qué clase de alimaña "
                "podría estar oculta entre tanta vegetación.\n");
            break;
        case 2:
            SetIntLong(" Estás en la senda que cruza a través del bosque de Cored. El "
                "suelo está cubierto de tierra en la que crece la hierba, y de borrosas huellas"
                " de pies. No parece conveniente andar por aquí sin compañía, el bosque es "
                "demasiado frondoso, ideal para que fieras o bandoleros se oculten entre "
                "los árboles.\n");
                break;
        case 3:
            SetIntLong("Estás en la senda a través del bosque de Cored. Es un camino "
                "natural abierto en el bosque, cuyo suelo está cubierto de hierba fina y "
                "apisonada por las pisadas de quienes se aventuran por estos solitarios parajes.\n");
            break;
        case 4:
                SetIntLong("Estás en la senda que cruza de norte a sur el bosque de Cored, "
                "al norte de la villa de Nandor. Desde aquí puedes observar que se trata de "
                "un bosque frondoso en el que se ocultan animales peligrosos.\n");
            break;
        case 5:
            SetIntLong(" Estás en una senda que va de norte a sur recorriendo el bosque de "
                "Cored. Este es un paraje solitario y lleno de árboles que quitan luz al "
                "paisaje. En el suelo ves, confundiéndose con la hierba del sendero, borrosas "
                "huellas de pies que han pasado por aquí.\n");
            break;
        case 6:
            SetIntLong(" Te hallas en una senda que recorre el bosque de Cored. Es un "
                "bosque frondoso en el que cualquier alimaña hallaría lugar apropiado para "
                "ocultarse.\n");
            break;
    }
    AddDetail("huellas", "Son huellas de pies que no podrías identificar, y como están "
        "tan borrosas, tampoco puedes descubrir en qué dirección van o de dónde "
        "vienen.\n");
    SetIntNoise("Oyes el canto de los pájaros.\n");
    SetIntSmell("Huele a bosque.\n");
    AddDetail(({"fortaleza"}),
        "Al norte del camino ves como se alza una imponente fortaleza. Aunque parece "
        "abandonada, la fortaleza se conserva en un increíble buen estado.\n");
    AddDetail(({"bosque"}),
        "Alrededor de la senda se extiende un bosque muy tupido, no te puedes hacer "
        "una idea del tamaño que tiene, ni del tipo de animales que pueden habitar "
        "en él.\n");
    SetLocate("senda de la fortaleza");
    SetIndoors(0);
}
