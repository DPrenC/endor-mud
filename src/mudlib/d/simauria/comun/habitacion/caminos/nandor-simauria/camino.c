/****************************************************************************
Fichero: camino.c
Autor: Ratwor
Fecha: 19/11/2006
Descripción: Archivo base para el camino de Nandor-ishtria
****************************************************************************/
#include "./path.h"
inherit SIM_ROOM;

create()
{
    ::create();

    SetLocate("Camino Nandor-Ishtria");
    SetIntShort("el camino Nandor-Ishtria");
    switch(d10()){
        case 1:
            SetIntLong("Estás atravesando el camino que une la villa de Nandor con "
            "la capital Ishtria, en un sinuoso sendero que se extiende de norte a "
            "sur.\n  El camino es largo y pesado, más te hubiera valido coger la "
            "diligencia para ahorrarte la caminata.\n  Al este ves todo el tiempo un"
            " bosque de árboles jóvenes, mientras que al oeste se divisan las "
            "montañas.\n  En algunos sitios el bosque parece ceder terreno hacia el "
            "este, y es posible internarse en él por algunos huecos dejados por"
            " los árboles en algunas partes del camino.\n");
            break;
        case 2:
            SetIntLong("Estás en el camino que une Nandor con Ishtria, es una senda "
            "poco transitada a pie, pues hay una diligencia que pasa regularmente "
            "por aquí. Por ello puedes observar que está bastante mal señalizado.\n "
            " Aquí y allá ves huellas que podrían ser de ganado, y otras que sin duda "
            "pertenecen a la diligencia que cubre este camino.\n Ves al este los "
            "árboles de un bosque joven, mientras que al oeste se despliega una "
            "cadena montañosa.\n");
            break;
        case 3:
            SetIntLong("Estás atravesando el camino que une Ishtria con Nandor, con "
            "las montañas al oeste y el bosque al este.\n  Es posible que hubiera "
            "sido mejor que cogieras la diligencia que te hubiera ahorrado hacer este"
            " largo sendero a pie.\n  Ves que en algunos lugares los árboles del "
            "bosque parecen dejar algunos huecos hacia el este, por donde quizás "
            "fuera posible internarse en él.\n");
            break;
        case 4:
            SetIntLong("En estos momentos estás en el camino que va de Nandor, una "
            "de las villas de Marhalt,  a Ishtria, la Gran Capital de Simauria.\n  Al"
            " este sólo ves bosque y árboles jóvenes, en su mayoría hayas y robles,"
            " mientras que al oeste puedes ver una cadena de montañas.\n  Las huellas"
            " que ves en el sendero te recuerdan que por aquí pasa regularmente una "
            "diligencia que hubiera podido ahorrarte la caminata.\n");
            break;
        case 5:
            SetIntLong("Atraviesas la senda que une Nandor, al norte, con Ishtria, "
            "al sur. La zona está bastante mal señalizada, quizás porque nadie parece "
            "gustoso de transitarla a pie y todos prefieren abordar la diligencia "
            "que cubre este camino.\n  Al este se despliega un colorido bosque de "
            "árboles jóvenes, hacia donde la frondosidad de la vegetación te impide "
            "internarte desde algunos puntos del sendero.\n  Al oeste quedan las "
            "montañas.\n  Ves distintas huellas de ganado y de ruedas de carros.\n");
            break;
        case 6:
            SetIntLong("Éste es el camino que lleva desde la villa de Nandor a la gran"
            " capital Ishtria. Es un sendero largo y sinuoso, donde  sin duda te "
            "hubiera convenido atravesarlo a bordo de la diligencia que pasa "
            "regularmente por aquí.\n  El bosque de Marhalt queda hacia el este, con "
            "su colorido de árboles y arbustos jóvenes que a veces parecen dejar "
            "algunos huecos por donde pudieras internarte en él.\n  Al oeste ves "
            "montañas y más montañas.\n");
            break;
        case 7:
            SetIntLong("Estás en el camino que une Nandor con Ishtria. Es un largo "
            "sendero que transcurre entre el bosque de Marhalt al este y las montañas"
            " al oeste.\n  Esta región está bastante mal señalizada, y si miras hacia"
            " el suelo puedes observar huellas de ganado y de ruedas de carro..., "
            "pero pocas huellas de pies humanos, lo que te sugiere que hubiera sido "
            "mejor que usaras la diligencia que cubre este camino en lugar de "
            "atravesarlo a pie.\n  En esta zona los árboles del bosque parecen dejar "
            "algunos claros, y se puede sospechar que quizás fuese posible internarte "
            "en el bosque desde alguna parte del camino.\n");
            break;
        case 8:
            SetIntLong("Estás en el camino que lleva desde Nandor hasta Ishtria, la "
            "gran capital de Simauria. Es un largo y sinuoso sendero bastante mal "
            "señalizado, y por todas partes observas huellas de carros que han pasado"
            " por aquí. Te das cuenta de que debe de tratarse de la diligencia que "
            "atraviesa regularmente este camino y que mejor hubieras debido coger "
            "para ahorrarte las fatigas del viaje a pie.\n  Al este, el bosque de "
            "Marhalt se muestra en todo su esplendor, que contrasta con la monotonía de"
            " las montañas que transcurren hacia el oeste.\n");
            break;
        case 9:
            SetIntLong(" Te hallas en un largo sendero bastante mal señalizado, quizás"
            " porque regularmente hay una diligencia que lo cubre y que sin duda "
            "hubieras debido coger para ahorrarte la caminata. Este sinuoso camino "
            "conduce desde la villa de Nandor hasta la capital Ishtria.\n  Al oeste"
            ", la cadena montañosa parece no tener fin.\n  Si miras hacia el este ves"
            " el bosque de Marhalt, con su vegetación joven y frondosa que en "
            "ocasiones permite sin embargo observar algunos claros por donde "
            "posiblemente pudieras internarte en él.\n");
            break;
        case 10:
            SetIntLong(" Te encuentras en el camino que une Nandor al norte con "
            "Ishtria al sur. Es un largo sendero que casi nadie quiere recorrer a "
            "pie. Hay una diligencia que cubre regularmente esta zona, y más te "
            "hubiera valido cogerla para ahorrarte las fatigas y los riesgos de andar "
            "a solas por un camino tan poco frecuentado.\n Al este divisas los robles"
            " y las hayas del bosque de Marhalt, y al oeste transcurre una cadena "
            "montañosa.\n  El suelo está cubierto de huellas de carros y de ganado.\n");
            break;
    }

    if(d4()==1)
        AddItem(PNJ("camino/aveboske"),REFRESH_REMOVE, d2());
    SetIndoors(0);
    AddDetail(({"huella", "huellas"}), "Son huellas de ganado, caballos y ruedas,"
        "posiblemente de caravanas o diligencias.\n");
    AddDetail(({"montaña", "montañas"}), "Es una pequeña cordillera montañosa que "
        "acompaña al camino en su parte oeste, por sus características es posible que "
        "albergue extraños desfiladeros.\n");
    AddDetail(({"bosque","bosque de nandor","este", "bosque del este", "robles",
        "roble", "bosque de marhalt", "bosque de Marhalt", "hayas", "haya"}),
        "En toda la parte este, y a lo largo de todo el camino que une la capital Ishtria"
        " con la villa de nandor, acompaña un joven bosque poco frondoso de hayas y"
        " robles, aunque no por ello fácil de adentrarse. Quizá por alguna parte "
        "del camino podrías introducirte en él.\n");
    AddDetail(({"camino","suelo"}), "Es el camino que une Ishtria con Nandor de sur a "
        "norte, no es que sea muy largo, pero podrías haber cogido una diligencia. De "
        "hecho puedes ver algunas huellas de carros y diligencias en el suelo.\n");
}
