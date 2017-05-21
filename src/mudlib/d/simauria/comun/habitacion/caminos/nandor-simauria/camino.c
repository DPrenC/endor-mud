/****************************************************************************
Fichero: camino.c
Autor: Ratwor
Fecha: 19/11/2006
Descripci�n: Archivo base para el camino de Nandor-ishtria
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
            SetIntLong("Est�s atravesando el camino que une la villa de Nandor con "
            "la capital Ishtria, en un sinuoso sendero que se extiende de norte a "
            "sur.\n  El camino es largo y pesado, m�s te hubiera valido coger la "
            "diligencia para ahorrarte la caminata.\n  Al este ves todo el tiempo un"
            " bosque de �rboles j�venes, mientras que al oeste se divisan las "
            "monta�as.\n  En algunos sitios el bosque parece ceder terreno hacia el "
            "este, y es posible internarse en �l por algunos huecos dejados por"
            " los �rboles en algunas partes del camino.\n");
            break;
        case 2:
            SetIntLong("Est�s en el camino que une Nandor con Ishtria, es una senda "
            "poco transitada a pie, pues hay una diligencia que pasa regularmente "
            "por aqu�. Por ello puedes observar que est� bastante mal se�alizado.\n "
            " Aqu� y all� ves huellas que podr�an ser de ganado, y otras que sin duda "
            "pertenecen a la diligencia que cubre este camino.\n Ves al este los "
            "�rboles de un bosque joven, mientras que al oeste se despliega una "
            "cadena monta�osa.\n");
            break;
        case 3:
            SetIntLong("Est�s atravesando el camino que une Ishtria con Nandor, con "
            "las monta�as al oeste y el bosque al este.\n  Es posible que hubiera "
            "sido mejor que cogieras la diligencia que te hubiera ahorrado hacer este"
            " largo sendero a pie.\n  Ves que en algunos lugares los �rboles del "
            "bosque parecen dejar algunos huecos hacia el este, por donde quiz�s "
            "fuera posible internarse en �l.\n");
            break;
        case 4:
            SetIntLong("En estos momentos est�s en el camino que va de Nandor, una "
            "de las villas de Marhalt,  a Ishtria, la Gran Capital de Simauria.\n  Al"
            " este s�lo ves bosque y �rboles j�venes, en su mayor�a hayas y robles,"
            " mientras que al oeste puedes ver una cadena de monta�as.\n  Las huellas"
            " que ves en el sendero te recuerdan que por aqu� pasa regularmente una "
            "diligencia que hubiera podido ahorrarte la caminata.\n");
            break;
        case 5:
            SetIntLong("Atraviesas la senda que une Nandor, al norte, con Ishtria, "
            "al sur. La zona est� bastante mal se�alizada, quiz�s porque nadie parece "
            "gustoso de transitarla a pie y todos prefieren abordar la diligencia "
            "que cubre este camino.\n  Al este se despliega un colorido bosque de "
            "�rboles j�venes, hacia donde la frondosidad de la vegetaci�n te impide "
            "internarte desde algunos puntos del sendero.\n  Al oeste quedan las "
            "monta�as.\n  Ves distintas huellas de ganado y de ruedas de carros.\n");
            break;
        case 6:
            SetIntLong("�ste es el camino que lleva desde la villa de Nandor a la gran"
            " capital Ishtria. Es un sendero largo y sinuoso, donde  sin duda te "
            "hubiera convenido atravesarlo a bordo de la diligencia que pasa "
            "regularmente por aqu�.\n  El bosque de Marhalt queda hacia el este, con "
            "su colorido de �rboles y arbustos j�venes que a veces parecen dejar "
            "algunos huecos por donde pudieras internarte en �l.\n  Al oeste ves "
            "monta�as y m�s monta�as.\n");
            break;
        case 7:
            SetIntLong("Est�s en el camino que une Nandor con Ishtria. Es un largo "
            "sendero que transcurre entre el bosque de Marhalt al este y las monta�as"
            " al oeste.\n  Esta regi�n est� bastante mal se�alizada, y si miras hacia"
            " el suelo puedes observar huellas de ganado y de ruedas de carro..., "
            "pero pocas huellas de pies humanos, lo que te sugiere que hubiera sido "
            "mejor que usaras la diligencia que cubre este camino en lugar de "
            "atravesarlo a pie.\n  En esta zona los �rboles del bosque parecen dejar "
            "algunos claros, y se puede sospechar que quiz�s fuese posible internarte "
            "en el bosque desde alguna parte del camino.\n");
            break;
        case 8:
            SetIntLong("Est�s en el camino que lleva desde Nandor hasta Ishtria, la "
            "gran capital de Simauria. Es un largo y sinuoso sendero bastante mal "
            "se�alizado, y por todas partes observas huellas de carros que han pasado"
            " por aqu�. Te das cuenta de que debe de tratarse de la diligencia que "
            "atraviesa regularmente este camino y que mejor hubieras debido coger "
            "para ahorrarte las fatigas del viaje a pie.\n  Al este, el bosque de "
            "Marhalt se muestra en todo su esplendor, que contrasta con la monoton�a de"
            " las monta�as que transcurren hacia el oeste.\n");
            break;
        case 9:
            SetIntLong(" Te hallas en un largo sendero bastante mal se�alizado, quiz�s"
            " porque regularmente hay una diligencia que lo cubre y que sin duda "
            "hubieras debido coger para ahorrarte la caminata. Este sinuoso camino "
            "conduce desde la villa de Nandor hasta la capital Ishtria.\n  Al oeste"
            ", la cadena monta�osa parece no tener fin.\n  Si miras hacia el este ves"
            " el bosque de Marhalt, con su vegetaci�n joven y frondosa que en "
            "ocasiones permite sin embargo observar algunos claros por donde "
            "posiblemente pudieras internarte en �l.\n");
            break;
        case 10:
            SetIntLong(" Te encuentras en el camino que une Nandor al norte con "
            "Ishtria al sur. Es un largo sendero que casi nadie quiere recorrer a "
            "pie. Hay una diligencia que cubre regularmente esta zona, y m�s te "
            "hubiera valido cogerla para ahorrarte las fatigas y los riesgos de andar "
            "a solas por un camino tan poco frecuentado.\n Al este divisas los robles"
            " y las hayas del bosque de Marhalt, y al oeste transcurre una cadena "
            "monta�osa.\n  El suelo est� cubierto de huellas de carros y de ganado.\n");
            break;
    }

    if(d4()==1)
        AddItem(PNJ("camino/aveboske"),REFRESH_REMOVE, d2());
    SetIndoors(0);
    AddDetail(({"huella", "huellas"}), "Son huellas de ganado, caballos y ruedas,"
        "posiblemente de caravanas o diligencias.\n");
    AddDetail(({"monta�a", "monta�as"}), "Es una peque�a cordillera monta�osa que "
        "acompa�a al camino en su parte oeste, por sus caracter�sticas es posible que "
        "albergue extra�os desfiladeros.\n");
    AddDetail(({"bosque","bosque de nandor","este", "bosque del este", "robles",
        "roble", "bosque de marhalt", "bosque de Marhalt", "hayas", "haya"}),
        "En toda la parte este, y a lo largo de todo el camino que une la capital Ishtria"
        " con la villa de nandor, acompa�a un joven bosque poco frondoso de hayas y"
        " robles, aunque no por ello f�cil de adentrarse. Quiz� por alguna parte "
        "del camino podr�as introducirte en �l.\n");
    AddDetail(({"camino","suelo"}), "Es el camino que une Ishtria con Nandor de sur a "
        "norte, no es que sea muy largo, pero podr�as haber cogido una diligencia. De "
        "hecho puedes ver algunas huellas de carros y diligencias en el suelo.\n");
}
