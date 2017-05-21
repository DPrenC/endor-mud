/*****************************************************************************************
 ARCHIVO:       bosque_central_base.c
 AUTOR:         Ztico
 FECHA:         12-03-2005
 DESCRIPCI�N:   Habitaci�n est�ndar general para el bosque central de Faeria.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <nightday.h>

inherit HAB_VALMAR("hab_bosque.c");

public string f_oler();
public string f_escuchar();
//public int query_luz();

create()
{
    if(::create()) return 1;

    SetLocate("Valmar");
    SetIntShort("los bosques de Valmar");

    switch(random(100))
    {
        case 0..9:
            SetIntLong("Te encuentras en los bosques m�gicos de Valmar.\n"
                "Las copas de los �rboles son tan tupidas que apenas puedes ver el "
                "cielo, sus troncos son nudosos, las ramas retorcidas y las hojas "
                "oscuras y largas. La hiedra crece sobre ellos y se arrastra por el "
                "suelo.\n");
            AddDetail(({"�rboles", "arboles"}), "Los �rboles son nuevos y muy "
                "frondosos.\n");
            AddDetail("copas", "Son muy espesas.\n");
            AddDetail("cielo", "No hay mucho que ver. Las copas de los �rboles te lo "
                "impiden.\n");
            AddDetail("ramas", "Las ramas se curvan formando sinuosos perfiles.\n");
            AddDetail("troncos", "Son nudosos, torcidos y robustos.\n");
            AddDetail("hojas", "Las hojas apretadas y rizadas, tienen pinta de ser "
                "muy rugosas.\n");
            AddDetail(({"hiedra", "yedra"}), "Cubre los troncos de los �rboles y se "
                "desparrama por el suelo.\n");
            AddDetail("suelo", "Ves hierbas, hojas secas y trozos de corteza.\n");
//            SetIntBright(query_luz()); //Lugar cerrado
            break;

        case 10..19:
            SetIntLong("Te encuentras en los bosques m�gicos de Valmar.\n"
                "La zona en la que te encuentras est� llena de senderos poblados de "
                "matorrales y mont�culos de hierba. Adem�s, abundan los helechos "
                "amarillentos y ramas ca�das. Hay espesas capas de agujas de pino, y "
                "aqu� y all� �rboles secos.\n");
            AddDetail("senderos", "Son estrechos y serpentean entre los �rboles.\n");
            AddDetail("matorrales", "Adoptan formas achaparradas, abundan sobre todo los "
                "espliegos.\n");
            AddDetail("espliegos", "No tienen flores, pero a�n as� son muy "
                "arom�ticos.\n");
            AddDetail(({"mont�culos", "monticulos", "mont�culos de hierba"}), "Son como "
                "tartas verdes con pinchos.\n");
            AddDetail(({"helechos", "helechos amarillentos"}), "Un mar de helechos de "
                "altas frondas se levantan por encima del metro de altura.\n");
            AddDetail(({"ramas", "ramas ca�das", "ramas caidas"}), "Son peque�as y "
                "grises, algunas podr�an confundirse con astas de ciervo.\n");
            AddDetail(({"capas", "espesas capas", "capas de agujas", "agujas",
                "agujas de pino"}), "Hacen que el suelo tenga un tono ocre.\n");
            AddDetail(({"�rboles", "arboles", "�rboles secos"}), "Ves troncos derechos, "
                "finos y pulidos.\n");
            AddDetail("suelo", "El suelo esta aqu� seco y abrigado.\n");
            SetIndoors(0);
            break;

        case 20..29:
            SetIntLong("Te hallas en los bosques m�gicos de Valmar.\n"
                "Todo a tu alrededor es misterioso y cautivador. Te encuentras "
                "rodeado por una profusa vegetaci�n. Las raices de los �rboles y "
                "arbustos crecen fuera de la tierra haciendo que la superficie sea "
                "mucho m�s �spera.\n");
            AddDetail(({"vegetaci�n", "vegetacion"}), "Por todas partes crece una "
                "exhuberante vegetaci�n de matas y hierbas arom�ticas.\n");
            AddDetail("raices", "Est�n retorcidas y entrelazadas.\n");
            AddDetail(({"�rboles", "arboles"}), "Ves robles altos y muy viejos, adem�s "
                "de un crecido seto de espinos.\n");
            AddDetail(({"seto", "seto de espinos"}), "Es denso y punzante.\n");
            AddDetail("arbustos", "Enmara�ados arbustos y ramas entretejidas crecen bajo "
                "los �rboles.\n");
            AddDetail(({"ramas"}), "Son ramas muertas y desmochadas de los �rboles, que "
                "se van enredando entre los arbustos.\n");
            AddDetail(({"suelo", "superficie"}), "Est� lleno de escorias y peque�os "
                "guijarros.\n");
            SetIndoors(0);
            break;

        case 30..39:
            SetIntLong("los bosques m�gicos de Valmar se extienden a tu alrededor.\n"
                "Est� tan poblado de �rboles que la luz apenas llega a rozar el suelo. "
                "A pesar de los arbustos, hay ciertas zonas hacia las que puedes "
                "avanzar sin problemas.\n");
            AddDetail(({"�rboles", "arboles"}), "Troncos de diferentes formas y tama�os: "
                "erguidos o inclinados, rechonchos o finos, pulidos o nudosos;  todos "
                "son verdes o grises, cubiertos de musgo y de viscosas y peludas "
                "protuberancias.\n");
            AddDetail("musgo", "Manojos de musgo h�medo tapizan las cortezas de los "
                "�rboles.\n");
            AddDetail("protuberancias", "Son de p�lidos colores terrosos, grises y "
                "verdes, parecen pellejos de animales.\n");
            AddDetail("suelo", "Es blando, h�medo y arruina o confunde las huellas de "
                "los animales que puedan transitar por aqu�.\n");
            AddDetail("arbustos", "Son espesos y tienen matas de hierba a los "
                "costados.\n");
            AddDetail("cielo", "No hay mucho que ver. Las copas de los �rboles te lo "
                "impiden.\n");
//            SetIntBright(query_luz()); //Lugar cerrado
            break;

        case 40..49:
            SetIntLong("Te hallas en un bosque m�gico en la regi�n de Valinor.\nA tu "
                "alrededor ves unos �rboles altos de corteza gris que se encorvan "
                "adquiriendo formas sinuosas. Diminutas huellas y extra�as pisadas se "
                "pierden en todas direcciones.\n");
            AddDetail(({"arboles", "�rboles"}), "Parecen casta�os y tienen a�n las "
                "hojas, secas y ocres, de temporadas pasadas, como manos huesudas que "
                "muestran los largos dedos.\n");
            AddDetail("corteza", "Su aspecto es similar al de caparazones vac�os ya que "
                "en muchas zonas se ha ahuecado.\n");
            AddDetail(({"formas", "formas sinuosas"}), "Algunas recuerdan a viejos "
                "y anchos brazos.\n");
            AddDetail(({"huella", "huellas", "pisada", "pisadas"}), "Son de formas muy "
                "diversas: unas parecen de ave, otras de peque�os elfos, y aqu� y all� "
                "otras que no siguen ning�n orden.\n");
            AddDetail("suelo", "En la tierra hay un sinf�n de huellas marcadas.\n");
            SetIndoors(0);
            break;

        case 50..59:
            SetIntLong("Est�s en los grandes bosques de Valmar.\nLas copas de los �rboles "
                "forman un techo natural de ramajes y hojas, y a sus pies crecen hongos "
                "y hierbas de hojas p�lidas y olor desagradable. El suelo est� cubierto "
                "por una capa de musgo debido a que a penas le llega la luz del sol.\n");
            AddDetail(({"copas", "techo", "ramajes", "hojas"}), "Los ramajes y las hojas "
                "se mezclan y aprietan en las alturas impidiendo pr�cticamente que la "
                "luz los atraviese.\n");
            AddDetail(({"�rboles", "arboles"}), "Troncos de diferentes formas y tama�os: "
                "erguidos o inclinados, rechonchos o finos, pulidos o nudosos;  todos "
                "son verdes o grises, cubiertos de musgo y de viscosas y peludas "
                "protuberancias.\n");
            AddDetail(({"pelusilla", "musgo", "capa de musgo"}), "Manojos de musgo "
                "h�medo tapizan las cortezas de los �rboles y el suelo.\n");
            AddDetail("protuberancias", "Son de p�lidos colores terrosos, grises y "
                "verdes, parecen pellejos de animales.\n");
            AddDetail("cielo", "No hay mucho que ver. Las copas de los �rboles te lo "
                "impiden.\n");
            AddDetail("hongos", "Son de color pardo y tienen motas rojizas.\n");
            AddDetail("hierbas", "Por su color y su olor parece que est�n muertas.\n");
            AddDetail("suelo", "Tiene una pelusilla de color verde.\n");
//            SetIntBright(query_luz());  //Lugar cerrado
            break;

        case 60..69:
            SetIntLong("Los grandes bosques de Valmar se extienden en torno a ti.\n"
                "De los �rboles se descuelgan flexibles lianas que, al enmara�arse "
                "unas con otras, forman tupidas cortinas que apenas permiten distinguir"
                "los troncos.\n");
            AddDetail(({"�rboles", "arboles", "troncos"}), "Los troncos de los �rboles "
                "tienden a ser de color claro, rectos y verticales, con una corteza lisa "
                "y llena de l�quenes.\n");
            AddDetail(({"lianas", "flexibles lianas"}), "Crecen hacia arriba para "
                "absorber luz, enred�ndose en las ramas.\n");
            AddDetail("cortinas", "Parecen grandes telones verdes y oscuros.\n");
            AddDetail("suelo", "Los extra�os cortinajes nacen en el suelo y crecen hasta "
                "toparse con las ramas.\n");
            SetIndoors(0);
            break;

        case 70..79:
            SetIntLong("Est�s en los bosques de Valmar.\n"
                "A los pies de los �rboles hay unas florecitas amarillas. Entre ellas, "
                "balance�ndose sobre tallos delgados, hay otras flores, blancas o de un "
                "verde muy p�lido; relumbran como una llovizna entre el rico colorido "
                "de la hierba.\n");
            AddDetail(({"�rboles", "arboles"}), "Puedes ver robles, alisos, olmos de "
                "follaje amarillo y espeso y abetos delgados y pobres de ramas.\n");
            AddDetail("florecillas", "Tienen forma de estrella.\n");
            AddDetail("flores", "Las hay de todos los colores; de color blanco puro y "
                "hojas verdes, otras de p�talos violetas que contrastan con estambres "
                "azules.\n");
            AddDetail(({"tallos", "tallos delgados"}), "Son flexibles, de color verde "
                "amarillento.\n");
            AddDetail(({"vegataci�n", "vegetacion", "hierba"}), "Puebla la base de los "
                "�rboles y crece verde y alocadamente.\n");
            AddDetail("suelo", "Est� totalmente cubierto de vegetaci�n.\n");
            SetIndoors(0);
            break;

        case 80..89:
            SetIntLong("Te hallas entre la abundante hierba verde y bajo una hilera de "
                "robles anchos de brazos y los olmos altos. Diminutas flores de color "
                "rojo, amarillo y blanco tapizan el suelo cubierto de densa y suave "
                "hierba. Por encima de tu cabeza, la c�pula formada por las ramas de los "
                "altos �rboles deja entrever retazos de cielo.\n");
            AddDetail("flores", "Las hay de todos los colores; de color blanco puro y "
                "hojas verdes, otras de p�talos violetas que contrastan con estambres "
                "azules.\n");
            AddDetail("hierba", "Puebla la base de los �rboles y crece verde y "
                "alocadamente por el suelo.\n");
            AddDetail(({"c�pula", "cupula"}), "Los �rboles no son muy tupidos y puedes "
                "apreciar el cielo tras las ramas en movimiento.\n");
            AddDetail(({"ramas", "brazos"}), "Est�n movi�ndose constantemente a�n cuando"
                "el viento es inapreciable.\n");
            AddDetail(({"hilera", "robles", "olmos", "�rboles", "arboles"}), "Ves un "
                "grupo de viejos �rboles retorcidos.\n");
            AddDetail(({"olmos", "olmos altos"}), "Son delgados y escasos de ramas.\n");
            AddDetail("suelo", "Est� totalmente cubierto por vegetaci�n.\n");
            SetIndoors(0);
            break;

        case 90..99:
        	  SetIntLong("Las ramas de los �rboles crecen golpe�ndose unas contra otras. "
        	      "Entre el follaje, revolotean pajarillos y las ardillas saltan de un "
        	      "�rbol a otro demostrando una gran agilidad. En el suelo no crece nada "
        	      "vivo y reconocible.\n");
        	  AddDetail("ramas", "No son muy gruesas, y por eso algunas de ellas se rompen "
        	      "cuando chocan con otras.\n");
        	  AddDetail(({"�rboles", "arboles", "�rbol"}), "No son excesivamente gruesos, "
        	      "pero si muy altos.\n");
        	  AddDetail("follaje", "Es de distintos tonos de verde.\n");
        	  AddDetail("pajarillos", "Aletean graciosamente entre las ramas.\n");
        	  AddDetail("ardillas", "Son juguetonas, y van de un lado a otro con peque�os "
        	      "frutos en la boca.\n");
        	  AddDetail("suelo", "Est� yermo.\n");
        	  SetIndoors(0);
        	  break;
    }
SetIndoors(0);
    SetIntSmell(SF(f_oler));
    SetIntNoise(SF(f_escuchar));
}

public string f_oler()
{
    if(member(RAZASENEMIGAS, TP->QueryRace()) >= 0)
        return "Este olor tan puro y fresco te repugna.\n";
    return "Huele a bosque h�medo, y el ambiente es muy fresco.\n";
}

public string f_escuchar()
{
    if(member(RAZASENEMIGAS, TP->QueryRace()) >= 0)
        return "Tus oidos no captan nada especial.\n";
    return "Escuchas unas suaves tonadas procedentes de alg�n lugar del bosque.\n";
}
/*
//Esta funci�n devuelve la luz que ser� decrementada
public int query_luz()
{
    switch(NIGHTDAY->QueryState())
    {
    	  case ND_DAY:      //100
        	  return -50; break;

        case ND_PRENOON:  //70
        case ND_POSTNOON: //70
        	  return -50; break;

        case ND_SUNRISE:  //40
        case ND_PREFALL:  //40
        	  return -30; break;

        case ND_FALL:     //20
        case ND_DAWN:     //20
        	  return -15; break;

        case ND_PRENIGHT: //10
        case ND_PREDAWN:  //10
        	  return -10; break;
        case ND_NIGHT:    //0
        	  return  0; break;

        default:
            return 50; break;
    }
}
*/