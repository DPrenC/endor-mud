/*
DESCRIPCION : cocina de la fonda 'el Jabali feroz'
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/tienda/fonda_cocina.c
MODIFICACION: 24-04-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit SCHEDULER_ROOM;

int matar_cmd(string str)
{
    if (!str) return 0;
    if (str!="Kabia" && str!="kabia" && str!="cocinera" && str!="orco") return 0;
    else
    {
        write("Miras a Kabia un momento y te das cuenta de que acabar con esta orca grande y "
            "fornida armada con un gran machete de cocina no debe ser nada fácil. Mejor no "
            "intentarlo y acabar siendo la próxima carne ensartada en el asador...\n");
        return 1;
    }
}

int abrir_cmd(string str)
{
    if (!str) return 0;
    if (str!="armario" && str!="despensa") return 0;
    else
    {
        write("Cuando te acercas al armario con intención de abrirlo, oyes que Kabia te grita "
            "desde la otra parte de la cocina: '¡Tú, mantén las manos quietas si quieres "
            "conservarlas!' al tiempo que agita furiosamente el gran machete de cocina que "
            "tiene en las manos. Decides no tentar a la suerte esta vez.\n");
        say(CAP(TNAME)+" se acerca al armario con intención de abrirlo y Kabia le grita: '¡Tu, "
            "mantén las manos quietas si quieres conservarlas!'. "+CAP(TNAME)+" se aparta del "
            "armario.\n");
        return 1;
    }
}

create()
{
    ::create();
    SetIntShort("la cocina de la fonda 'El Jabalí feroz'");
    SetIntLong("Ante ti se halla la cocina de la fonda 'El Jabalí Feroz'. Es una amplia "
        "estancia en la que Kabia, la esposa de Grogor, cocina la comida que se sirve en esta "
        "fonda. En el centro de la habitación hay una gran cocina con varios fuegos sobre los "
        "que reposan otras tantas humeantes ollas, y en un extremo, un gran asador de carne.\n"
        "Un gran armario sirve de despensa, y de una tabla sujeta al techo cuelgan todo tipo de "
        "cacharros de cocina.\n");
    AddDetail(({"cocina","fuego","fuegos","caldera","tapadera"}),"En el centro de la estancia "
        "se halla la gran cocina, una especie de mesa hecha de metal. En su parte inferior hay "
        "una caldera en la que continuamente se quema carbón, cuyo fuego se usa para cocinar. "
        "En su parte superior hay varios agujeros circulares con su tapadera correspondiente, "
        "de tal forma que para cocinar solo hay que destapar alguno y colocar una olla encima.\n");
    AddDetail(({"ollas","olla"}),"Sobre los fuegos de la cocina hay varias ollas humeantes en "
        "las que Kabia prepara las nuevas raciones de comida para los clientes de la fonda. El "
        "olor que desprenden es tentador.\n");
    AddDetail(({"asador","asador de carne","jabali","jabalí"}),"En un extremo de la cocina se "
        "halla un inmenso asador de carne. Se trata de una barra horizontal de metal con "
        "varios enganches donde ensartar los animales a asar. Bajo ella unas brasas se "
        "encargan de calentar la carne. En este momento hay un jabalí en el asador al que "
        "Kabia da media vuelta cada cierto tiempo para que se haga por todos lados.\n");
    AddDetail(({"armario","despensa"}),"Un gran armario recorre una pared de la cocina. Es la "
        "despensa en la que Kabia guarda todos aquellos alimentos que necesita para hacer cada "
        "una de las comidas que se sirven en la fonda.\n");
    AddDetail(({"tabla","cacharros"}),"Del techo de la cocina cuelga un gran rectángulo de "
        "madera. En él se halla clavada una larga hilera de clavos y enganches de los que "
        "cuelgan todo tipo de cacharros, cucharones, jarras, potes, cuchillos, y muchos otros "
        "utensilios que Kabia usa para hacer las comidas. Al estar colgados así, es mucho más "
        "cómodo para Kabia coger cualquiera de ellos cuando lo necesita que si estuviese en "
        "algún cajón del gran armario.\n");
    SetIntNoise("Las brasas del fuego crepitan ruidosamente.\n");
    SetIntSmell("El aire es calido y el olor de los calderos tentador...\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(1);
    SetIntBright(50);
    AddRoomCmd ("abrir", SF(abrir_cmd));
    AddRoomCmd ("matar", SF(matar_cmd));
    AddItem(PNJ_Z_CIUDAD("kabia"),REFRESH_DESTRUCT,1);
    SetMainRoom("fonda");
    SetLastDest(Z_CIUDAD("calle_02"));
    SetNotifyExits(({}));
    SetNoSchedulerObject(1);
    SetInformCloseMsg("Kabia comienza a apagar los fuegos diciendo: Bueno, esto se acabó por "
        "hoy. Parece que la fonda va a cerrar, deberías ir saliendo ya.\n");
    SetThrowOutMsg("Kabia te dice: Vamos, sal de aquí, me voy a dormir, y no quiero a nadie en "
        "mi cocina.\nPiensas que es mejor no crear problemas, y sales de la fonda.\n");
    AddExit("sur","fonda");
}
