/****************************************************************************
Fichero: pantalones.c
Autor: Dharkus
            
Fecha: 30/05/2010
Descripción: Varios pantalones para los ciudadanos de Koek
****************************************************************************/


#include <properties.h>
#include <combat.h>
inherit ARMOUR;

create() {
    ::create();
    SetStandard(AT_TROUSERS,1,P_SIZE_LARGE,M_TELA);
    SetIds(({"pantalones","ropa", "pantalon", "pantalón"}));
    switch(d4()){
        case 1:
            SetShort("unos pantalones negros");
            SetLong("Son unos pantalones negros de tela gruesa sin bolsillos.\n");
            AddAdjective("negros");
            break;
        case 2:
            SetShort("unos pantalones blancos");
            SetLong("Son unos pantalones blancos de tela gruesa y resistente.\n");
            AddAdjective("blancos");
            break;
        case 3:
            SetShort("unos pantalones marrones");
            SetLong("Son unos pantalones marrones de resistente tela gruesa.\n");
            AddAdjective("marrones");
            break;
        case 4:
            SetShort("unos pantalones grises");
            SetLong("Se trata de unos pantalones grises de tela fina con cuadros "
            "pequeños.\n");
            AddAdjective("grises");
            break;
    }
    SetWeight(500);
    Set(P_NUMBER,NUMBER_PLURAL);
}
