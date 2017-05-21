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
        "manos a las gruesas vigas del patíbulo. Un orco y un humano, esperan su sentencia de "
        "muerte o el poco probable perdón por parte del governador.\nEl orco esta callado, tal "
        "vez asumido ya su destino, pero con un gesto lleno de rabia. El humano, desesperado, "
        "pasa el día gritando que es inocente. Cuando se vuelve muy molesto, el verdugo le da "
        "un par de guantazos para que se calle de una vez. Probablemente, estos dos no serán "
        "más que un trozo de carne colgante antes de que llegue la noche.\n";
    return "No ves "+arg+" por aquí.\n";
}

public string ver_cadaver(string arg)
{
    object cal=load_object("/obj/calendario/calendario_estandar");
    if ((cal->QueryDiaNombre()=="miercoles")||(cal->QueryDiaNombre()=="jueves")) return "Hoy, "
        "colgando de dos de las horcas del patíbulo, hay un par de presos, un orco y un humano, "
        "ajusticiados ayer por la tarde ante la multitud. Colgando del cuello del cadáver del "
        "orco hay un letrero que dice: 'TRAIDOR', y colgando del cuello del humano hay otro "
        "con el texto: 'ESCLAVO HUIDO'. Las tensas sogas de las horcas chirrían cuando los "
        "cadáveres giran por una racha de viento.\n";
    return "No ves "+arg+" por aquí.\n";
}

public string ver_vieja(string arg)
{
    object cal=load_object("/obj/calendario/calendario_estandar");
    if (cal->QueryDiaNombre()=="sabado") return "Hoy, sobre el patíbulo, se haya el verdugo "
        "azotando a una vieja orca que está atada a uno de los pilares. Su espalda está llena "
        "de las sangrantes marcas del látigo. No para de gritar e insultar al verdugo, "
        "llegando incluso a echarle una oscura maldición hace un rato. Sobre la vieja hay un "
        "letrero en el que se puede leer: 'LADRONA'.\n";
    return "No ves una "+arg+" por aquí.\n";
}

public string mirar_patibulo()
{
    string msg;
    object cal=load_object("/obj/calendario/calendario_estandar");
    switch(cal->QueryDiaNombre())
    {
        case "lunes":
            msg="Sobre el patíbulo se haya el verdugo. Este orco fornido con una gran cicatriz "
                "en la cara, va de un lado a otro de la plataforma repasando cuidadosamente el "
                "funcionamiento de cada una de las horcas. Mañana es día de ejecuciones y si "
                "algo falla, tal vez sea él una de las próximas víctimas.\n";
        break;
        case "martes":
            msg="Hay dos presos encadenados de pies y manos a las gruesas vigas del patíbulo.\n";
        break;
        case "miercoles":
            msg="Colgando de dos de las horcas del patíbulo hay un par de cadáveres.\n";
        break;
        case "jueves":
            msg="El verdugo está acabando de descolgar los dos cadáveres de los presos que "
                "fueron ajusticiados hace un par de días. Los cuerpos, que ya empiezan a oler, "
                "serán llevados en una vieja carreta hasta una fosa común en el cementerio.\n";
        break;
        case "viernes":
            msg="El patíbulo está vacío, lo cual no acaba de ser demasiado tranquilizador.\n"
                "El verdugo, ante la falta de trabajo, está sentado tallando un pedazo de "
                "madera y mirando la gente que pasa por la plaza.\n";
        break;
        case "sabado":
       msg="Sobre el patíbulo, una vieja orca está siendo azotada por el verdugo.\n";
        break;
        case "domingo":
            msg="El verdugo está arreglando una de las vigas del patíbulo aprovechando que hoy "
                "no hay nadie en él. Parece que la madera está medio podrida y quizá no pueda.\n";
        break;
        default:
            msg="";
        break;;
    }
    return msg;
}


protected void HazDescr()
{
    SetIntLong("Te hallas en medio de la plaza central de Zarkam. Al oeste de aquí se halla la "
        "entrada al castillo donde vive el gobernador local, y junto a la cual se halla "
        "construido un patíbulo de madera del que cuelgan varias horcas... " +
        mirar_patibulo());
}

create()
{
    ::create();
    SetIntShort("el patíbulo frente al castillo");
    HazDescr();
    AddDetail(({"plaza","plaza central"}),"Es una gran explanada que se encuentra en el centro "
        "de la ciudad de Zarkam. A su alrededor se alzan altos edificios y al oeste el "
        "castillo de la ciudad. Es el lugar en que se reúne la gente cuando se producen "
        "ejecuciones públicas o cuando el governador realiza algún importante anuncio.\n");
    AddDetail(({"patibulo","patíbulo"}),"Es una plataforma elevada de madera con varias horcas. "
        "Es allí donde se ejecuta públicamente a los delincuentes o prisioneros de guerra como "
        "castigo público y como advertencia al resto de la población.\n"+mirar_patibulo());
    AddDetail(({"castillo"}),"La ciudad de Zarkam se ha construido en torno al gran castillo "
        "que observas al oeste de aquí. En él vive el governador orco que el emperador ha "
        "elegido para dirigir esta provincia.\nEl castillo es una inmensa mole de piedra más "
        "alta que cualquiera de los edificios que lo rodean. Sobre él se alza una alta torre "
        "desde la que se vigila el valle constantemente.\n");
    AddDetail(({"torre"}),"Se alza sobre el castillo.\n");
    AddDetail(({"orca","horcas"}),"Varias horcas hechas con una gruesa soga cuelgan de la viga "
        "superior del patíbulo. En ellas los orcos ajustician públicamente a quien el "
        "governador decide.\n");
    AddDetail(({"presos","preso","traidor","esclavo"}),SF(ver_presos));
    AddDetail(({"cadaver","cadáver","cadaveres","cadáveres"}),SF(ver_cadaver));
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
