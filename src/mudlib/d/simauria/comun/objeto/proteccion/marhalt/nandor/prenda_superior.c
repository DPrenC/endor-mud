/****************************************************************************
Fichero: prenda_superior.c
Autor: Rakwor.
Fecha: 11/08/2007
Descripción: Una camisa o una blusa según el sexo del pnj.
****************************************************************************/

#include "./path.h"
#include <combat.h>
#include <properties.h>
#include <materials.h>

inherit ARMOUR;
create(){
    ::create();
    string *colores=({"gris", "violeta", "marrón", "a rayas", "a cuadros", "verde", "azul",
        "granate", "con flores", "de tela", "remendada", "de piel", "desteñida",
        "blanca", "amarilla", "roja", "parda"});
    string color=colores[random(sizeof(colores))];

	SetStandard(AT_TUNICA,d2(), P_SIZE_LARGE, M_TELA);
	SetResetQuality(100);
	Set(P_NUMBER, NUMBER_SINGULAR);
	Set(P_GENDER, GENDER_FEMALE);
	SetWeight(600);
	SetValue(QueryValue()*3);

	if (!TP || TP->QueryGender()==GENDER_MALE){
        SetShort("una camisa "+color);
        SetLong("Una elegante camisa "+color+" de la región de Marhalt.\n");
        AddId(({"camisa", "elegante camisa","camisa elegante", "prenda", "ropa"}));
    }else{
        SetShort("una blusa "+color);
        SetLong("Una bonita blusa "+color+" de la región de Marhalt.\n");
        AddId(({"blusa", "bonita blusa", "blusa bonita", "prenda", "ropa"}));
    }
}
