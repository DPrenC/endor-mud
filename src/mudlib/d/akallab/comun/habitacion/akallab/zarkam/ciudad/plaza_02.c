/*
DESCRIPCION : centro de la plaza de central de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/plaza_02.c
MODIFICACION: 27-04-98 [Angor@Simauria] Creacion
              12-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

public string ver_presos(string arg)
{
    object cal=load_object("/obj/calendario/calendario_estandar");
    if (cal->QueryDiaNombre()=="martes") return "Hoy hay dos presos encadenados de pies y "
        "manos a las gruesas vigas del pat�bulo. Un orco y un humano, esperan su sentencia de "
        "muerte o el poco probable perd�n por parte del governador.\nEl orco esta callado, tal "
        "vez asumido ya su destino, pero con un gesto lleno de rabia. El humano, desesperado, "
        "pasa el d�a gritando que es inocente. Cuando se vuelve muy molesto, el verdugo le da "
        "un par de guantazos para que se calle de una vez. Probablemente, estos dos no ser�n "
        "m�s que un trozo de carne colgante antes de que llegue la noche.\n";
    return "No ves "+arg+" por aqu�.\n";
}

public string ver_cadaver(string arg)
{
    object cal=load_object("/obj/calendario/calendario_estandar");
    if ((cal->QueryDiaNombre()=="miercoles")||(cal->QueryDiaNombre()=="jueves")) return "Hoy, "
        "colgando de dos de las horcas del pat�bulo, hay un par de presos, un orco y un humano, "
        "ajusticiados ayer por la tarde ante la multitud. Colgando del cuello del cad�ver del "
        "orco hay un letrero que dice: 'TRAIDOR', y colgando del cuello del humano hay otro "
        "con el texto: 'ESCLAVO HUIDO'. Las tensas sogas de las horcas chirr�an cuando los "
        "cad�veres giran por una racha de viento.\n";
    return "No ves "+arg+" por aqu�.\n";
}

public string ver_vieja(string arg)
{
    object cal=load_object("/obj/calendario/calendario_estandar");
    if (cal->QueryDiaNombre()=="sabado") return "Hoy, sobre el pat�bulo, se haya el verdugo "
        "azotando a una vieja orca que est� atada a uno de los pilares. Su espalda est� llena "
        "de las sangrantes marcas del l�tigo. No para de gritar e insultar al verdugo, "
        "llegando incluso a echarle una oscura maldici�n hace un rato. Sobre la vieja hay un "
        "letrero en el que se puede leer: 'LADRONA'.\n";
    return "No ves una "+arg+" por aqu�.\n";
}

public string mirar_patibulo()
{
    string msg;
    object cal=load_object("/obj/calendario/calendario_estandar");
    switch(cal->QueryDiaNombre())
    {
        case "lunes":
            msg="Sobre el pat�bulo se haya el verdugo. Este orco fornido con una gran cicatriz "
                "en la cara, va de un lado a otro de la plataforma repasando cuidadosamente el "
                "funcionamiento de cada una de las horcas. Ma�ana es d�a de ejecuciones y si "
                "algo falla, tal vez sea �l una de las pr�ximas v�ctimas.\n";
        break;
        case "martes":
            msg="Hay dos presos encadenados de pies y manos a las gruesas vigas del pat�bulo.\n";
        break;
        case "miercoles":
            msg="Colgando de dos de las horcas del pat�bulo hay un par de cad�veres.\n";
        break;
        case "jueves":
            msg="El verdugo est� acabando de descolgar los dos cad�veres de los presos que "
                "fueron ajusticiados hace un par de d�as. Los cuerpos, que ya empiezan a oler, "
                "ser�n llevados en una vieja carreta hasta una fosa com�n en el cementerio.\n";
        break;
        case "viernes":
            msg="El pat�bulo est� vac�o, lo cual no acaba de ser demasiado tranquilizador.\n"
                "El verdugo, ante la falta de trabajo, est� sentado tallando un pedazo de "
                "madera y mirando la gente que pasa por la plaza.\n";
        break;
        case "sabado":
       msg="Sobre el pat�bulo, una vieja orca est� siendo azotada por el verdugo.\n";
        break;
        case "domingo":
            msg="El verdugo est� arreglando una de las vigas del pat�bulo aprovechando que hoy "
                "no hay nadie en �l. Parece que la madera est� medio podrida y quiz� no pueda.\n";
        break;
        default:
            msg="";
        break;;
    }
    return msg;
}


protected void HazDescr()
{
    SetIntLong("Te hallas en medio de la plaza central de Zarkam. Al oeste de aqu� se halla la "
        "entrada al castillo donde vive el gobernador local, y junto a la cual se halla "
        "construido un pat�bulo de madera del que cuelgan varias horcas... " +
        mirar_patibulo());
}

create()
{
    ::create();
    SetIntShort("el pat�bulo frente al castillo");
    HazDescr();
    AddDetail(({"plaza","plaza central"}),"Es una gran explanada que se encuentra en el centro "
        "de la ciudad de Zarkam. A su alrededor se alzan altos edificios y al oeste el "
        "castillo de la ciudad. Es el lugar en que se re�ne la gente cuando se producen "
        "ejecuciones p�blicas o cuando el governador realiza alg�n importante anuncio.\n");
    AddDetail(({"patibulo","pat�bulo"}),"Es una plataforma elevada de madera con varias horcas. "
        "Es all� donde se ejecuta p�blicamente a los delincuentes o prisioneros de guerra como "
        "castigo p�blico y como advertencia al resto de la poblaci�n.\n"+mirar_patibulo());
    AddDetail(({"castillo"}),"La ciudad de Zarkam se ha construido en torno al gran castillo "
        "que observas al oeste de aqu�. En �l vive el governador orco que el emperador ha "
        "elegido para dirigir esta provincia.\nEl castillo es una inmensa mole de piedra m�s "
        "alta que cualquiera de los edificios que lo rodean. Sobre �l se alza una alta torre "
        "desde la que se vigila el valle constantemente.\n");
    AddDetail(({"torre"}),"Se alza sobre el castillo.\n");
    AddDetail(({"orca","horcas"}),"Varias horcas hechas con una gruesa soga cuelgan de la viga "
        "superior del pat�bulo. En ellas los orcos ajustician p�blicamente a quien el "
        "governador decide.\n");
    AddDetail(({"presos","preso","traidor","esclavo"}),SF(ver_presos));
    AddDetail(({"cadaver","cad�ver","cadaveres","cad�veres"}),SF(ver_cadaver));
    AddDetail(({"vieja","ladrona"}),SF(ver_vieja));
    SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
    SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(0);
    AddExit("sur",Z_CIUDAD("calle_03"));
    AddExit("este",Z_CIUDAD("plaza_03"));
    AddExit("oeste",Z_CASTILLO("patio/patio00"));
    AddExit("norte",Z_CIUDAD("plaza_00"));
    //AddItem(PNJ("guardia"), REFRESH_DESTRUCT,2);
    //AddItem(PNJ("verdugo"), REFRESH_DESTRUCT);
}
