/*********************************************
*    Nombre: carro�ero.c                     *
*    Localizacion: Cueva de los Trolls       *
*    Realizada por : Cajun, el ejecutor      *
*    Creado : 17-11-99                       *
*    Modificado: 25-11-99                    *
**********************************************/

#include <properties.h>
inherit NPC;

create() {
    ::create();
    SetStandard("un carro�ero","carro�ero", 40, GENDER_MALE);
    SetShort("un monstruo carro�ero");
    SetLong("Un monstruo peludo y negro con unas gigantescas mandibulas y ojos oscuros. "
    "Su aspecto es horriblemente asqueroso y amenazante, y m�s teniendo en cuenta "
    "sus enormes pinzas con las que podr�a desmembrarte cualquier miembro.\n");
    SetHands( ({ ({"pinza derecha",0,0}),({"pinza izquierda",0,0}), }) );
    AddId(({"carro�ero","carronyero", "monstruo", "mounstruo"}));
  SetAlign(-400);
    SetSize(P_SIZE_MEDIUM);
    SetAggressive(1);
}
