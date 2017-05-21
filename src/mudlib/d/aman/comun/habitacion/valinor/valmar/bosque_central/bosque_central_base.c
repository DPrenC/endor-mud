/*****************************************************************************************
 ARCHIVO:       bosque_central_base.c
 AUTOR:         Ztico
 FECHA:         12-03-2005
 DESCRIPCIÓN:   Habitación estándar general para el bosque central de Faeria.
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
            SetIntLong("Te encuentras en los bosques mágicos de Valmar.\n"
                "Las copas de los árboles son tan tupidas que apenas puedes ver el "
                "cielo, sus troncos son nudosos, las ramas retorcidas y las hojas "
                "oscuras y largas. La hiedra crece sobre ellos y se arrastra por el "
                "suelo.\n");
            AddDetail(({"árboles", "arboles"}), "Los árboles son nuevos y muy "
                "frondosos.\n");
            AddDetail("copas", "Son muy espesas.\n");
            AddDetail("cielo", "No hay mucho que ver. Las copas de los árboles te lo "
                "impiden.\n");
            AddDetail("ramas", "Las ramas se curvan formando sinuosos perfiles.\n");
            AddDetail("troncos", "Son nudosos, torcidos y robustos.\n");
            AddDetail("hojas", "Las hojas apretadas y rizadas, tienen pinta de ser "
                "muy rugosas.\n");
            AddDetail(({"hiedra", "yedra"}), "Cubre los troncos de los árboles y se "
                "desparrama por el suelo.\n");
            AddDetail("suelo", "Ves hierbas, hojas secas y trozos de corteza.\n");
//            SetIntBright(query_luz()); //Lugar cerrado
            break;

        case 10..19:
            SetIntLong("Te encuentras en los bosques mágicos de Valmar.\n"
                "La zona en la que te encuentras está llena de senderos poblados de "
                "matorrales y montículos de hierba. Además, abundan los helechos "
                "amarillentos y ramas caídas. Hay espesas capas de agujas de pino, y "
                "aquí y allá árboles secos.\n");
            AddDetail("senderos", "Son estrechos y serpentean entre los árboles.\n");
            AddDetail("matorrales", "Adoptan formas achaparradas, abundan sobre todo los "
                "espliegos.\n");
            AddDetail("espliegos", "No tienen flores, pero aún así son muy "
                "aromáticos.\n");
            AddDetail(({"montículos", "monticulos", "montículos de hierba"}), "Son como "
                "tartas verdes con pinchos.\n");
            AddDetail(({"helechos", "helechos amarillentos"}), "Un mar de helechos de "
                "altas frondas se levantan por encima del metro de altura.\n");
            AddDetail(({"ramas", "ramas caídas", "ramas caidas"}), "Son pequeñas y "
                "grises, algunas podrían confundirse con astas de ciervo.\n");
            AddDetail(({"capas", "espesas capas", "capas de agujas", "agujas",
                "agujas de pino"}), "Hacen que el suelo tenga un tono ocre.\n");
            AddDetail(({"árboles", "arboles", "árboles secos"}), "Ves troncos derechos, "
                "finos y pulidos.\n");
            AddDetail("suelo", "El suelo esta aquí seco y abrigado.\n");
            SetIndoors(0);
            break;

        case 20..29:
            SetIntLong("Te hallas en los bosques mágicos de Valmar.\n"
                "Todo a tu alrededor es misterioso y cautivador. Te encuentras "
                "rodeado por una profusa vegetación. Las raices de los árboles y "
                "arbustos crecen fuera de la tierra haciendo que la superficie sea "
                "mucho más áspera.\n");
            AddDetail(({"vegetación", "vegetacion"}), "Por todas partes crece una "
                "exhuberante vegetación de matas y hierbas aromáticas.\n");
            AddDetail("raices", "Están retorcidas y entrelazadas.\n");
            AddDetail(({"árboles", "arboles"}), "Ves robles altos y muy viejos, además "
                "de un crecido seto de espinos.\n");
            AddDetail(({"seto", "seto de espinos"}), "Es denso y punzante.\n");
            AddDetail("arbustos", "Enmarañados arbustos y ramas entretejidas crecen bajo "
                "los árboles.\n");
            AddDetail(({"ramas"}), "Son ramas muertas y desmochadas de los árboles, que "
                "se van enredando entre los arbustos.\n");
            AddDetail(({"suelo", "superficie"}), "Está lleno de escorias y pequeños "
                "guijarros.\n");
            SetIndoors(0);
            break;

        case 30..39:
            SetIntLong("los bosques mágicos de Valmar se extienden a tu alrededor.\n"
                "Está tan poblado de árboles que la luz apenas llega a rozar el suelo. "
                "A pesar de los arbustos, hay ciertas zonas hacia las que puedes "
                "avanzar sin problemas.\n");
            AddDetail(({"árboles", "arboles"}), "Troncos de diferentes formas y tamaños: "
                "erguidos o inclinados, rechonchos o finos, pulidos o nudosos;  todos "
                "son verdes o grises, cubiertos de musgo y de viscosas y peludas "
                "protuberancias.\n");
            AddDetail("musgo", "Manojos de musgo húmedo tapizan las cortezas de los "
                "árboles.\n");
            AddDetail("protuberancias", "Son de pálidos colores terrosos, grises y "
                "verdes, parecen pellejos de animales.\n");
            AddDetail("suelo", "Es blando, húmedo y arruina o confunde las huellas de "
                "los animales que puedan transitar por aquí.\n");
            AddDetail("arbustos", "Son espesos y tienen matas de hierba a los "
                "costados.\n");
            AddDetail("cielo", "No hay mucho que ver. Las copas de los árboles te lo "
                "impiden.\n");
//            SetIntBright(query_luz()); //Lugar cerrado
            break;

        case 40..49:
            SetIntLong("Te hallas en un bosque mágico en la región de Valinor.\nA tu "
                "alrededor ves unos árboles altos de corteza gris que se encorvan "
                "adquiriendo formas sinuosas. Diminutas huellas y extrañas pisadas se "
                "pierden en todas direcciones.\n");
            AddDetail(({"arboles", "árboles"}), "Parecen castaños y tienen aún las "
                "hojas, secas y ocres, de temporadas pasadas, como manos huesudas que "
                "muestran los largos dedos.\n");
            AddDetail("corteza", "Su aspecto es similar al de caparazones vacíos ya que "
                "en muchas zonas se ha ahuecado.\n");
            AddDetail(({"formas", "formas sinuosas"}), "Algunas recuerdan a viejos "
                "y anchos brazos.\n");
            AddDetail(({"huella", "huellas", "pisada", "pisadas"}), "Son de formas muy "
                "diversas: unas parecen de ave, otras de pequeños elfos, y aquí y allá "
                "otras que no siguen ningún orden.\n");
            AddDetail("suelo", "En la tierra hay un sinfín de huellas marcadas.\n");
            SetIndoors(0);
            break;

        case 50..59:
            SetIntLong("Estás en los grandes bosques de Valmar.\nLas copas de los árboles "
                "forman un techo natural de ramajes y hojas, y a sus pies crecen hongos "
                "y hierbas de hojas pálidas y olor desagradable. El suelo está cubierto "
                "por una capa de musgo debido a que a penas le llega la luz del sol.\n");
            AddDetail(({"copas", "techo", "ramajes", "hojas"}), "Los ramajes y las hojas "
                "se mezclan y aprietan en las alturas impidiendo prácticamente que la "
                "luz los atraviese.\n");
            AddDetail(({"árboles", "arboles"}), "Troncos de diferentes formas y tamaños: "
                "erguidos o inclinados, rechonchos o finos, pulidos o nudosos;  todos "
                "son verdes o grises, cubiertos de musgo y de viscosas y peludas "
                "protuberancias.\n");
            AddDetail(({"pelusilla", "musgo", "capa de musgo"}), "Manojos de musgo "
                "húmedo tapizan las cortezas de los árboles y el suelo.\n");
            AddDetail("protuberancias", "Son de pálidos colores terrosos, grises y "
                "verdes, parecen pellejos de animales.\n");
            AddDetail("cielo", "No hay mucho que ver. Las copas de los árboles te lo "
                "impiden.\n");
            AddDetail("hongos", "Son de color pardo y tienen motas rojizas.\n");
            AddDetail("hierbas", "Por su color y su olor parece que están muertas.\n");
            AddDetail("suelo", "Tiene una pelusilla de color verde.\n");
//            SetIntBright(query_luz());  //Lugar cerrado
            break;

        case 60..69:
            SetIntLong("Los grandes bosques de Valmar se extienden en torno a ti.\n"
                "De los árboles se descuelgan flexibles lianas que, al enmarañarse "
                "unas con otras, forman tupidas cortinas que apenas permiten distinguir"
                "los troncos.\n");
            AddDetail(({"árboles", "arboles", "troncos"}), "Los troncos de los árboles "
                "tienden a ser de color claro, rectos y verticales, con una corteza lisa "
                "y llena de líquenes.\n");
            AddDetail(({"lianas", "flexibles lianas"}), "Crecen hacia arriba para "
                "absorber luz, enredándose en las ramas.\n");
            AddDetail("cortinas", "Parecen grandes telones verdes y oscuros.\n");
            AddDetail("suelo", "Los extraños cortinajes nacen en el suelo y crecen hasta "
                "toparse con las ramas.\n");
            SetIndoors(0);
            break;

        case 70..79:
            SetIntLong("Estás en los bosques de Valmar.\n"
                "A los pies de los árboles hay unas florecitas amarillas. Entre ellas, "
                "balanceándose sobre tallos delgados, hay otras flores, blancas o de un "
                "verde muy pálido; relumbran como una llovizna entre el rico colorido "
                "de la hierba.\n");
            AddDetail(({"árboles", "arboles"}), "Puedes ver robles, alisos, olmos de "
                "follaje amarillo y espeso y abetos delgados y pobres de ramas.\n");
            AddDetail("florecillas", "Tienen forma de estrella.\n");
            AddDetail("flores", "Las hay de todos los colores; de color blanco puro y "
                "hojas verdes, otras de pétalos violetas que contrastan con estambres "
                "azules.\n");
            AddDetail(({"tallos", "tallos delgados"}), "Son flexibles, de color verde "
                "amarillento.\n");
            AddDetail(({"vegatación", "vegetacion", "hierba"}), "Puebla la base de los "
                "árboles y crece verde y alocadamente.\n");
            AddDetail("suelo", "Está totalmente cubierto de vegetación.\n");
            SetIndoors(0);
            break;

        case 80..89:
            SetIntLong("Te hallas entre la abundante hierba verde y bajo una hilera de "
                "robles anchos de brazos y los olmos altos. Diminutas flores de color "
                "rojo, amarillo y blanco tapizan el suelo cubierto de densa y suave "
                "hierba. Por encima de tu cabeza, la cúpula formada por las ramas de los "
                "altos árboles deja entrever retazos de cielo.\n");
            AddDetail("flores", "Las hay de todos los colores; de color blanco puro y "
                "hojas verdes, otras de pétalos violetas que contrastan con estambres "
                "azules.\n");
            AddDetail("hierba", "Puebla la base de los árboles y crece verde y "
                "alocadamente por el suelo.\n");
            AddDetail(({"cúpula", "cupula"}), "Los árboles no son muy tupidos y puedes "
                "apreciar el cielo tras las ramas en movimiento.\n");
            AddDetail(({"ramas", "brazos"}), "Están moviéndose constantemente aún cuando"
                "el viento es inapreciable.\n");
            AddDetail(({"hilera", "robles", "olmos", "árboles", "arboles"}), "Ves un "
                "grupo de viejos árboles retorcidos.\n");
            AddDetail(({"olmos", "olmos altos"}), "Son delgados y escasos de ramas.\n");
            AddDetail("suelo", "Está totalmente cubierto por vegetación.\n");
            SetIndoors(0);
            break;

        case 90..99:
        	  SetIntLong("Las ramas de los árboles crecen golpeándose unas contra otras. "
        	      "Entre el follaje, revolotean pajarillos y las ardillas saltan de un "
        	      "árbol a otro demostrando una gran agilidad. En el suelo no crece nada "
        	      "vivo y reconocible.\n");
        	  AddDetail("ramas", "No son muy gruesas, y por eso algunas de ellas se rompen "
        	      "cuando chocan con otras.\n");
        	  AddDetail(({"árboles", "arboles", "árbol"}), "No son excesivamente gruesos, "
        	      "pero si muy altos.\n");
        	  AddDetail("follaje", "Es de distintos tonos de verde.\n");
        	  AddDetail("pajarillos", "Aletean graciosamente entre las ramas.\n");
        	  AddDetail("ardillas", "Son juguetonas, y van de un lado a otro con pequeños "
        	      "frutos en la boca.\n");
        	  AddDetail("suelo", "Está yermo.\n");
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
    return "Huele a bosque húmedo, y el ambiente es muy fresco.\n";
}

public string f_escuchar()
{
    if(member(RAZASENEMIGAS, TP->QueryRace()) >= 0)
        return "Tus oidos no captan nada especial.\n";
    return "Escuchas unas suaves tonadas procedentes de algún lugar del bosque.\n";
}
/*
//Esta función devuelve la luz que será decrementada
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