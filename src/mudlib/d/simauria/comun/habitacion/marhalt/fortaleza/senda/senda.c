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
    SetIntShort("una senda a trav�s del bosque");
    switch(d6()){
        case 1:
            SetIntLong("Est�s en una senda que recorre de norte a sur el bosque de Cored,"
                " una tupida extensi�n verde llena de �rboles y fauna salvaje. No es "
                "aconsejable merodear por aqu� a solas, nunca se sabe qu� clase de alima�a "
                "podr�a estar oculta entre tanta vegetaci�n.\n");
            break;
        case 2:
            SetIntLong(" Est�s en la senda que cruza a trav�s del bosque de Cored. El "
                "suelo est� cubierto de tierra en la que crece la hierba, y de borrosas huellas"
                " de pies. No parece conveniente andar por aqu� sin compa��a, el bosque es "
                "demasiado frondoso, ideal para que fieras o bandoleros se oculten entre "
                "los �rboles.\n");
                break;
        case 3:
            SetIntLong("Est�s en la senda a trav�s del bosque de Cored. Es un camino "
                "natural abierto en el bosque, cuyo suelo est� cubierto de hierba fina y "
                "apisonada por las pisadas de quienes se aventuran por estos solitarios parajes.\n");
            break;
        case 4:
                SetIntLong("Est�s en la senda que cruza de norte a sur el bosque de Cored, "
                "al norte de la villa de Nandor. Desde aqu� puedes observar que se trata de "
                "un bosque frondoso en el que se ocultan animales peligrosos.\n");
            break;
        case 5:
            SetIntLong(" Est�s en una senda que va de norte a sur recorriendo el bosque de "
                "Cored. Este es un paraje solitario y lleno de �rboles que quitan luz al "
                "paisaje. En el suelo ves, confundi�ndose con la hierba del sendero, borrosas "
                "huellas de pies que han pasado por aqu�.\n");
            break;
        case 6:
            SetIntLong(" Te hallas en una senda que recorre el bosque de Cored. Es un "
                "bosque frondoso en el que cualquier alima�a hallar�a lugar apropiado para "
                "ocultarse.\n");
            break;
    }
    AddDetail("huellas", "Son huellas de pies que no podr�as identificar, y como est�n "
        "tan borrosas, tampoco puedes descubrir en qu� direcci�n van o de d�nde "
        "vienen.\n");
    SetIntNoise("Oyes el canto de los p�jaros.\n");
    SetIntSmell("Huele a bosque.\n");
    AddDetail(({"fortaleza"}),
        "Al norte del camino ves como se alza una imponente fortaleza. Aunque parece "
        "abandonada, la fortaleza se conserva en un incre�ble buen estado.\n");
    AddDetail(({"bosque"}),
        "Alrededor de la senda se extiende un bosque muy tupido, no te puedes hacer "
        "una idea del tama�o que tiene, ni del tipo de animales que pueden habitar "
        "en �l.\n");
    SetLocate("senda de la fortaleza");
    SetIndoors(0);
}
