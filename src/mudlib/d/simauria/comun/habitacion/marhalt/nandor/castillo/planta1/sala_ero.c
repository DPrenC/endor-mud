/****************************************************************************
Fichero: sala_ero.c
Autor: Ratwor
Fecha: 24/04/2008
Descripción: una sala oculta para los vicios del noble.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <magia.h>
inherit SIM_ROOM;
create(){
    ::create();
    SetIntShort("una amplia estancia");
    SetIntLong("Te encuentras en una amplia estancia tenuemente iluminada. Toda "
    "ella está tapizada por una mullida alfombra de colores oscuros, mientras que en las "
    "paredes, destacan tapices y un cuadro de sutil simbología. En el primer tercio de "
    "la sala se puede apreciar varias mesas auxiliares, cargadas de licores de todo tipo "
    "y finas viandas. En la parte central se encuentran varios divanes de aspecto "
    "confortable, adornados de cojines de vistosos colores. El último tercio de la "
    "habitación está presidido por una enorme vidriera emplomada, que representa "
    "varias figuras. Junto a la vidriera se encuentra una gran mesa de trabajo con un "
    "gran sillón de cuero curtido. La estancia se adorna con un par de esculturas y "
    "multitud de objetos de las más diversas procedencias. En el centro de la misma "
    "destaca sobremanera un gran pebetero con brasas.\n");
    SetIntBright(30);
    AddDetail(({"dibán", "diban"}),
    "Se trata de una tumbona con respaldo en uno de sus laterales. El armazón está "
    "realizado en fina madera imitando los trazos de una mujer tumbada, mientras que "
    "la superficie está rellenada de plumón y cubierta por tejidos de brocado y encajes.\n");
    AddDetail("alfombra",
    "Se trata de una gruesa alfombra de tupido trenzado, en la que destacan los "
    "motivos vinícolas y eróticos, está salpicada aquí y allá por parras de uvas, "
    "ninfas, querubines desnudos, etc. En el centro se puede ver una reproducción de "
    "Boros, dios del vino.\n");
    AddDetail(({"estatua", "estatuas", "esculturas", "escultura"}),
    "La sala está adornada con dos essuverantes esculturas: una escultura de un súcubo y "
    "otra de un sátiro.\n");
    AddDetail(({"escultura de un súcubo", "súcubo", "sucubo", "escultura de un sucubo"}),
    "En esta espectacular escultura, realizada de los mejores materiales, de allende "
    "los mares y con unos excelsos policromismos, que dotan de vida propia a las "
    "estatuas, se representan dos figuras:\n En la parte inferior una inocente "
    "doncella, de angelical rostro, trata de cubrir sus pechos desnudos, con los "
    "restos desgarrados de su vestido, mientras observa con pánico creciente el "
    "inevitable desenlace. Sobre ella se alza majestuosa un Súcubo, de prietas y "
    "redondeadas nalgas, de firmes y torneados muslos, de pechos exultantes de plenitud. "
    "Su cuerpo desnudo tan solo se oculta en parte, por su larga cabellera azabache y "
    "por sus magníficas alas que vate amenazadoramente hacia su presa.\n");
    AddDetail(({"estatua de un sátiro", "estatua de un satiro", "sátiro", "satiro"}),
    "Esta es la escultura de un Sátiro, realizada en el más puro mármol blanco, representa "
    "un ser dual. La mitad superior de su cerco cuerpo es el de un hombre atlético "
    "de orejas puntiagudas, mientras su parte inferior es la de un macho cabrío.\n "
    "Entre las piernas se puede apreciar la característica más simbólica de los Sátiros, "
    "sus desmesurados genitales, los cuales están presididos por un falo con priapismo "
    "perpetuo y de dimensiones monumentales.\n");
    AddDetail(({"cuadro este", "cuadro del este", "este"}),
    "Es un cuadro finamente pintado en el que se representa a la diosa de la fertilidad "
    "y la veneración que sus hijas le procesan.\n Sobre un maravilloso amanecer "
    "como fondo, se alza una hermosa mujer de dorados cabellos y de rostro extasiado, "
    "Su estilizada figura no se ve si no realzada por el terso y prominente vientre de "
    "gestación y por sus revosantes pechos de matrona. A su diestra y siniestra  se "
    "alinean sus hijas en amorosa veneración. Las dos hijas mayores, de opulentas "
    "curvas, una a cada lado, lamen amorosas las lágrimas derramadas por la diosa "
    "por los sufrimientos de la humanidad, mientras dejan descansar los senos sobre "
    "las cabecitas de sus hermanas menores. Estas mujercitas adolescentes oprimen el  "
    "costado de la diosa, con sus nacientes pechos, frutas tiernas de las delicadas "
    "curvas de la juventud. succionan hambrientas los pezones de la gran madre fuente "
    "de inagotable alimento, el cual las sacia y rebosa, deramándose por la comisura "
    "de sus labios. La niña púber se arrodilla mostrando su infantil y nacarado trasero "
    "entre las piernas de su madre, lamiendo con fruición el jugo de la fuente "
    "de la vida pasada y futura. Finalmente dos pequeños bebés se abrazan a los tobillos "
    "de la gran madre como ofrenda de sumisión y adoración.\n");
    AddDetail("pebetero",
    "Se trata de un gran brasero de pie. El talle representa en bronce, la figura "
    "de un hombre completamente desnudo, el cual sostiene sobre sus manos un gran cuenco "
    "repleto de ascuas. Arrodillada a sus pies se encuentra otra figura también de "
    "bronce, la cual representa a una bella mujer que, mediante movimientos oscilantes, "
    "se introduce el miembro viril de la primera figura en su boca. En el momento que "
    "el falo se esconde por completo en el interior de la segunda estatua, las "
    "brasas se avivan como si esta hubiera insuflado vida a la primera figura y de "
    "lo alto del cuenco se alzan potentes llamaradas que caldean toda la estancia.\n "
    "Este brasero o es obra de los grandes ingenieros gnomos o es brujería, por que "
    "algo así no debe ser normal.\n");
    AddDetail("mesa",
    "Es una mesa de trabajo, realizada con un gran tablero de la más oscura madera. Las "
    "patas de la mesa las forman los cuerpos a cuatro patas de dos mujeres desnudas "
    "realizadas en la misma madera que el tablero principal, el cual reposa sobre "
    "sus espaldas, muestran la cara vuelta hacia la vidriera, mientras ofrecen el "
    "trasero invitadoramente a cualquiera que entre en la estancia.\n El maestro artesano "
    "que haya desarrollado esta mesa sin duda alguna es un artista.\n");
    AddDetail(({"sillon", "sillón"}),
    "Se trata de un sólido sillón de madera y cuero curtido. Tallados en la madera "
    "se pueden apreciar símbolos demoníacos y eróticos, el amplio respaldo está coronado "
    "por la figura tallada de una pequeña Súcubo con las alas extendidas.\n");

    AddDetail(({"tapiz", "pared norte", "norte"}),
    "El tapiz representa a una doncella galopando a pelo sobre un "
    "corcel negro. El viento agita los largos cabellos cobrizos de la amazona cuyo "
    "hermoso rostro expresa la euforia producida por la velocidad mientras eleva un "
    "brazo bronceado por el sol, enarbolando una esbelta lanza de punta plateada. La piel "
    "ligeramente tostada por la vida a la intemperie delinea de forma exquisita su "
    "cuerpo flexible como el de una pantera, no exento de sensuales curvas. Las piernas "
    "desnudas aprietan los sudorosos flancos del corcel, acicateándolo con los "
    "talones. El animal de aspecto estilizado, patas finas, cabeza pequeña y larga cola "
    "ondeante no lleva ningún tipo de arreo.\n");
    AddDetail(({"oeste", "cuadro oeste", "cuadro del oeste", "pared oeste"}),
    "Éste lienzo muestra una faceta hasta ahora "
    "desconocida de la vida cotidiana en la isla escondida, habitada por las kisalas.\n"
    "Fue pintado por un artista trotamundos que consiguió llegar por algún medio "
    "desconocido aún hoy al refugio de las kisalas. En el cuadro aparece un idílico prado "
    "cubierto de césped que desciende suavemente desde el linde de un bosque de "
    "abedules hasta las aguas transparentes de un lago. Cerca de la orilla, tres "
    "amazonas desnudas yacen en un placentero revoltijo. La primera está acostada boca "
    "arriba con los ojos entrecerrados y una sonrisa beatífica en su juvenil rostro, "
    "mientras una segunda doncella cubierta tan solo por sus largos cabellos oscuros "
    "recorre hábidamente con la boca sus turgentes senos, que se muestran oferentes y "
    "grávidos como grandes y redondos frutos maduros. Los cabellos de ambas mujeres "
    "se mezclan de forma exquisita, contrastándo vívidamente el azabache de una con el "
    "dorado de la otra. La morena enlaza a su compañera por la nuca con el brazo "
    "izquierdo deslizándo en forma delicada las yemas de sus dedos sobre su terso "
    "vientre. Por su parte la rubia, cuyos gordezuelos pezones se ven endurecidos por "
    "la excitación,  tiene el brazo derecho cubierto por el pelo de su compañera, con la "
    "mano bajo el torso, mientras el brazo izquierdo reposa estirado sobre el verde "
    "césped, con la mano abierta junto a la hermosa empuñadura de una espada corta. La "
    "tercera amazona, de cuerpo atlético, piel clara cubierta de pecas y rebeldes rizos "
    "color de fuego, sumerge sus sedientos labios en el dulce vértice formado por las "
    "piernas de la doncella de cabellos dorados sobre cuyos muslos abiertos apoya "
    "las manos, cerrando los suyos sobre la pantorrilla de su compañera. Sobre la "
    "parte superior derecha de la espalda tiene tatuada una llama azul. El trío de "
    "mujeres es observado por una cuarta. Se trata de una doncella de unos dieciséis "
    "años, de facciones suaves, y grandes ojos pardos. Los bucles castaño-rojizos caen "
    "sobre sus blancos hombros cpobremente cubiertos por una liviana túnica de seda "
    "que desciende  hasta la parte superior de los muslos moldeando sus suaves curvas y "
    "dejando uno de sus tiernos senos al descubierto. La aparentemente núvil amazona "
    "apoya la espalda en un esbelto abedul mientras atisba entre sus párpados "
    "entrecerrados la escena del prado y desliza la mano derecha bajo la breve túnica, "
    "rodeando con la otra el seno descubierto.\n"
    "El cuadro encerrado en rico marco de plata, ocupa casi por completo una pared de la "
    "estancia. Fue traído desde la ciudad de Crowi, allá en el lejano sur, después de "
    "que su autor, tras el gran éxito obtenido con la obra, desapareciera sin dejar "
    "rastro. Nunca más regresó, o al menos no entero, puesto que días mas tarde, la "
    "parte de su anatomía a la que presumiblemente debía la reseñable exactitud y "
    "detallismo de la pintura, apareció en el puerto de Crowi, aún sangrante y sujeta "
    "con un clavo retorcido al tablón que informa del itenerario del Benoshan, barco "
    "en el cual había arribado a la tierra de Goldhai. Nadie osó retirar tan macabro "
    "despojo y allí permaneció, putrefacto hasta que los picoteos de las gaviotas acabaron con él.\n");
    SetIntSmell("Huele a hierbas aromáticas y perfume.\n");
    SetIntNoise("Suena una leve melodía, suave y casi inapreciable.\n");
    Set(P_TPORT,TPORT_NO);
    ForbidAllMagic("La magia que se puede hacer aquí es algo más gratificante que lo "
    "que pretentes hacer.\n");
    AddExit("norte", "./bodega2");
    AddExit("sur", "./terraza");
    AddDoor("norte", "una vieja puerta",
    "Es una destartalada puerta de madera vieja y negra para salir de esta estancia.\n",
    ({"puerta", "vieja puerta", "puerta vieja", "puerta de madera", "puerta del norte"}),
    "anillo_noble", ([P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
    AddDetail(({"cerradura", "cerradura de la puerta", "cerradura de puerta"}),
    "La puerta tiene una extraña cerradura cuadrada.\n");
    AddDoor("sur", "una vidriera",
    "Son dos grandes batientes rellenados de vidrio emplomado. Los vidrios en diferentes "
    "tonalidades de gris, amarillo y rojo, representan desde la parte superior izquierda "
    "hasta la parte inferior derecha, todas las posiciones posibles en las que dos "
    "personas del sexo que sean pueden copular: dos personas una encima de otra pero "
    "invertidas, Una mujer entre dos hombres, dos hombres...\n Son infinidad de posturas, "
    "representadas con gran detalle para tratarse de vidrio transparente de colores.\n",
    ({"vidriera", "puerta del sur", "vidriera emplomada"}),
    ([P_DOOR_TRANSPARENCY:1, P_MATERIAL: M_CRISTAL,
        P_DOOR_KNOCK_SOUND: SND_SUCESOS("llamar_puerta_cristal")]));
}
