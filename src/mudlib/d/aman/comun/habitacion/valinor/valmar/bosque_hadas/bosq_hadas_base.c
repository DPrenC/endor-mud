/*****************************************************************************************
 ARCHIVO:       bosq_hadas_base.c
 AUTOR:         Ztico
 FECHA:         15-03-2005
 DESCRIPCI�N:   Habitaci�n est�ndar para el bosque de las hadas.
 COMENTARIOS:   details...
*****************************************************************************************/

#include "./path.h"

inherit HAB_VALMAR("hab_bosque.c");

//public string f_oler();
//public string f_escuchar();

create()
{
    if(::create()) return 1;

    SetLocate("Bosques de Valmar");
    SetIntShort("el bosque de las Hadas");
//    SetIntBright(50);
SetIndoors(0);
    switch(random(160))
    {
        case 0..20:
            SetIntLong("El bosque est� sumido en un intrigante silencio, los �rboles "
                "se yerguen majestuosamente creando un luminoso dosel verde; quiz�s "
                "sean los m�s altos que hayas visto jam�s. El lugar tiene un aire de "
                "encantamiento que induce a todo explorador a ser cauto. Celidonias, "
                "violetas y campanillas crecen a la sombra en densos macizos. En todas "
                "direcciones puedes ver troncos cubiertos de hongo arcaico, junto a "
                "matas de an�monas y napelos.\n");
            AddDetail(({"", ""}), ".\n");

            break;
        case 21..40:
            SetIntLong("En medio de la exuberante vegetaci�n, el silencio que te "
                "envuelve es tan denso que crees poder tocarlo. Abunda el tr�bol, unas "
                "ondulantes parcelas de tr�boles rosados y purp�reos, y amplias "
                "extensiones de tr�bol dulce, blanco y peque�o, con olor a miel.\n");
            break;
        case 41..60:
            SetIntLong("Est�s rodeado de frondosos l�quenes a cuyos pies crecen unas "
                "peculiares flores de p�talos color negro con pigmentos rojos y "
                "p�rpura. El aroma que exhalan es aturdidor.\n");
            break;
        case 61..80:
            SetIntLong("El bosque se abre aqu� en un claro cubierto de suave hierba. "
                "Esparcidos por doquier ves arbustos cargados de frambuesas y moras. "
                "Los frutos ofrecen una apariencia muy especial, un brillo satinado "
                "que cambia por momentos. Por todas partes revolotean vistosas mariposas "
                "y lib�lulas de hermosas alas transparentes.\n");
            break;
        case 81..100:
            SetIntLong("Te encuentras en un punto donde una estribaci�n rocosa forma "
                "una cadena de peque�as grutas. Un suave musgo parduzco recubre las "
                "piedras y tapiza el suelo, haciendo que este lugar resulte un tanto "
                "peligroso a la hora de avanzar por �l. Los �rboles aqu� son menos "
                "altos y puedes ver a sus pies infinidad de curiosas setas de todos "
                "los tama�os y colores.\n");
            break;
        case 101..120:
            SetIntLong("No est�s muy seguro de lo que ven tus ojos. Desde luego, se "
                "trata de �rboles aparentemente normales pero, algo en ellos va mutando "
                "de modo constante. Las ramas se estiran y retuercen como dedos. Las "
                "hojas se mecen columpi�ndose y parecen bocas haciendo muecas. La "
                "corteza se expande y contrae creando la ilusi�n de rostros que te "
                "observan.\n");
            break;
        case 121..140:
            SetIntLong("Los �rboles se hallan aqu� equidistantes unos de otros formando "
                "un c�rculo perfecto. Entre ellos, inmensas telas de ara�a se extienden "
                "como s�banas de gasa que ondean impulsadas por una brisa que no se "
                "percibe. Fulguran y centellean en miles de puntitos luminosos. "
                "Son muy delicadas por lo que te ser� posible atravesarlas sin "
                "problema.\n");
            break;
        case 141..160:
            SetIntLong(".\n");

            break;
    }

    //SetIntSmell(SF(f_oler));
    //SetIntNoise(SF(f_escuchar));
}

/*public string f_oler()
{
    if(member(RAZASENEMIGAS, TP->QueryRace()) >= 0)
        return "Este olor tan puro y fresco te repugna.\n";
    return "Canteros de heliotropo perfuman el aire.\n";
}

public string f_escuchar()
{
    if(member(RAZASENEMIGAS, TP->QueryRace()) >= 0)
        return "Tus oidos no captan nada especial.\n";
    return "Escuchas como la brisa se cuela entre las ramas de los robles.\n";
}
*/