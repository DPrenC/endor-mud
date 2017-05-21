/****************************************************************************
Fichero: sala_ero.c
Autor: Ratwor
Fecha: 24/04/2008
Descripci�n: una sala oculta para los vicios del noble.
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
    "ella est� tapizada por una mullida alfombra de colores oscuros, mientras que en las "
    "paredes, destacan tapices y un cuadro de sutil simbolog�a. En el primer tercio de "
    "la sala se puede apreciar varias mesas auxiliares, cargadas de licores de todo tipo "
    "y finas viandas. En la parte central se encuentran varios divanes de aspecto "
    "confortable, adornados de cojines de vistosos colores. El �ltimo tercio de la "
    "habitaci�n est� presidido por una enorme vidriera emplomada, que representa "
    "varias figuras. Junto a la vidriera se encuentra una gran mesa de trabajo con un "
    "gran sill�n de cuero curtido. La estancia se adorna con un par de esculturas y "
    "multitud de objetos de las m�s diversas procedencias. En el centro de la misma "
    "destaca sobremanera un gran pebetero con brasas.\n");
    SetIntBright(30);
    AddDetail(({"dib�n", "diban"}),
    "Se trata de una tumbona con respaldo en uno de sus laterales. El armaz�n est� "
    "realizado en fina madera imitando los trazos de una mujer tumbada, mientras que "
    "la superficie est� rellenada de plum�n y cubierta por tejidos de brocado y encajes.\n");
    AddDetail("alfombra",
    "Se trata de una gruesa alfombra de tupido trenzado, en la que destacan los "
    "motivos vin�colas y er�ticos, est� salpicada aqu� y all� por parras de uvas, "
    "ninfas, querubines desnudos, etc. En el centro se puede ver una reproducci�n de "
    "Boros, dios del vino.\n");
    AddDetail(({"estatua", "estatuas", "esculturas", "escultura"}),
    "La sala est� adornada con dos essuverantes esculturas: una escultura de un s�cubo y "
    "otra de un s�tiro.\n");
    AddDetail(({"escultura de un s�cubo", "s�cubo", "sucubo", "escultura de un sucubo"}),
    "En esta espectacular escultura, realizada de los mejores materiales, de allende "
    "los mares y con unos excelsos policromismos, que dotan de vida propia a las "
    "estatuas, se representan dos figuras:\n En la parte inferior una inocente "
    "doncella, de angelical rostro, trata de cubrir sus pechos desnudos, con los "
    "restos desgarrados de su vestido, mientras observa con p�nico creciente el "
    "inevitable desenlace. Sobre ella se alza majestuosa un S�cubo, de prietas y "
    "redondeadas nalgas, de firmes y torneados muslos, de pechos exultantes de plenitud. "
    "Su cuerpo desnudo tan solo se oculta en parte, por su larga cabellera azabache y "
    "por sus magn�ficas alas que vate amenazadoramente hacia su presa.\n");
    AddDetail(({"estatua de un s�tiro", "estatua de un satiro", "s�tiro", "satiro"}),
    "Esta es la escultura de un S�tiro, realizada en el m�s puro m�rmol blanco, representa "
    "un ser dual. La mitad superior de su cerco cuerpo es el de un hombre atl�tico "
    "de orejas puntiagudas, mientras su parte inferior es la de un macho cabr�o.\n "
    "Entre las piernas se puede apreciar la caracter�stica m�s simb�lica de los S�tiros, "
    "sus desmesurados genitales, los cuales est�n presididos por un falo con priapismo "
    "perpetuo y de dimensiones monumentales.\n");
    AddDetail(({"cuadro este", "cuadro del este", "este"}),
    "Es un cuadro finamente pintado en el que se representa a la diosa de la fertilidad "
    "y la veneraci�n que sus hijas le procesan.\n Sobre un maravilloso amanecer "
    "como fondo, se alza una hermosa mujer de dorados cabellos y de rostro extasiado, "
    "Su estilizada figura no se ve si no realzada por el terso y prominente vientre de "
    "gestaci�n y por sus revosantes pechos de matrona. A su diestra y siniestra  se "
    "alinean sus hijas en amorosa veneraci�n. Las dos hijas mayores, de opulentas "
    "curvas, una a cada lado, lamen amorosas las l�grimas derramadas por la diosa "
    "por los sufrimientos de la humanidad, mientras dejan descansar los senos sobre "
    "las cabecitas de sus hermanas menores. Estas mujercitas adolescentes oprimen el  "
    "costado de la diosa, con sus nacientes pechos, frutas tiernas de las delicadas "
    "curvas de la juventud. succionan hambrientas los pezones de la gran madre fuente "
    "de inagotable alimento, el cual las sacia y rebosa, deram�ndose por la comisura "
    "de sus labios. La ni�a p�ber se arrodilla mostrando su infantil y nacarado trasero "
    "entre las piernas de su madre, lamiendo con fruici�n el jugo de la fuente "
    "de la vida pasada y futura. Finalmente dos peque�os beb�s se abrazan a los tobillos "
    "de la gran madre como ofrenda de sumisi�n y adoraci�n.\n");
    AddDetail("pebetero",
    "Se trata de un gran brasero de pie. El talle representa en bronce, la figura "
    "de un hombre completamente desnudo, el cual sostiene sobre sus manos un gran cuenco "
    "repleto de ascuas. Arrodillada a sus pies se encuentra otra figura tambi�n de "
    "bronce, la cual representa a una bella mujer que, mediante movimientos oscilantes, "
    "se introduce el miembro viril de la primera figura en su boca. En el momento que "
    "el falo se esconde por completo en el interior de la segunda estatua, las "
    "brasas se avivan como si esta hubiera insuflado vida a la primera figura y de "
    "lo alto del cuenco se alzan potentes llamaradas que caldean toda la estancia.\n "
    "Este brasero o es obra de los grandes ingenieros gnomos o es brujer�a, por que "
    "algo as� no debe ser normal.\n");
    AddDetail("mesa",
    "Es una mesa de trabajo, realizada con un gran tablero de la m�s oscura madera. Las "
    "patas de la mesa las forman los cuerpos a cuatro patas de dos mujeres desnudas "
    "realizadas en la misma madera que el tablero principal, el cual reposa sobre "
    "sus espaldas, muestran la cara vuelta hacia la vidriera, mientras ofrecen el "
    "trasero invitadoramente a cualquiera que entre en la estancia.\n El maestro artesano "
    "que haya desarrollado esta mesa sin duda alguna es un artista.\n");
    AddDetail(({"sillon", "sill�n"}),
    "Se trata de un s�lido sill�n de madera y cuero curtido. Tallados en la madera "
    "se pueden apreciar s�mbolos demon�acos y er�ticos, el amplio respaldo est� coronado "
    "por la figura tallada de una peque�a S�cubo con las alas extendidas.\n");

    AddDetail(({"tapiz", "pared norte", "norte"}),
    "El tapiz representa a una doncella galopando a pelo sobre un "
    "corcel negro. El viento agita los largos cabellos cobrizos de la amazona cuyo "
    "hermoso rostro expresa la euforia producida por la velocidad mientras eleva un "
    "brazo bronceado por el sol, enarbolando una esbelta lanza de punta plateada. La piel "
    "ligeramente tostada por la vida a la intemperie delinea de forma exquisita su "
    "cuerpo flexible como el de una pantera, no exento de sensuales curvas. Las piernas "
    "desnudas aprietan los sudorosos flancos del corcel, acicate�ndolo con los "
    "talones. El animal de aspecto estilizado, patas finas, cabeza peque�a y larga cola "
    "ondeante no lleva ning�n tipo de arreo.\n");
    AddDetail(({"oeste", "cuadro oeste", "cuadro del oeste", "pared oeste"}),
    "�ste lienzo muestra una faceta hasta ahora "
    "desconocida de la vida cotidiana en la isla escondida, habitada por las kisalas.\n"
    "Fue pintado por un artista trotamundos que consigui� llegar por alg�n medio "
    "desconocido a�n hoy al refugio de las kisalas. En el cuadro aparece un id�lico prado "
    "cubierto de c�sped que desciende suavemente desde el linde de un bosque de "
    "abedules hasta las aguas transparentes de un lago. Cerca de la orilla, tres "
    "amazonas desnudas yacen en un placentero revoltijo. La primera est� acostada boca "
    "arriba con los ojos entrecerrados y una sonrisa beat�fica en su juvenil rostro, "
    "mientras una segunda doncella cubierta tan solo por sus largos cabellos oscuros "
    "recorre h�bidamente con la boca sus turgentes senos, que se muestran oferentes y "
    "gr�vidos como grandes y redondos frutos maduros. Los cabellos de ambas mujeres "
    "se mezclan de forma exquisita, contrast�ndo v�vidamente el azabache de una con el "
    "dorado de la otra. La morena enlaza a su compa�era por la nuca con el brazo "
    "izquierdo desliz�ndo en forma delicada las yemas de sus dedos sobre su terso "
    "vientre. Por su parte la rubia, cuyos gordezuelos pezones se ven endurecidos por "
    "la excitaci�n,  tiene el brazo derecho cubierto por el pelo de su compa�era, con la "
    "mano bajo el torso, mientras el brazo izquierdo reposa estirado sobre el verde "
    "c�sped, con la mano abierta junto a la hermosa empu�adura de una espada corta. La "
    "tercera amazona, de cuerpo atl�tico, piel clara cubierta de pecas y rebeldes rizos "
    "color de fuego, sumerge sus sedientos labios en el dulce v�rtice formado por las "
    "piernas de la doncella de cabellos dorados sobre cuyos muslos abiertos apoya "
    "las manos, cerrando los suyos sobre la pantorrilla de su compa�era. Sobre la "
    "parte superior derecha de la espalda tiene tatuada una llama azul. El tr�o de "
    "mujeres es observado por una cuarta. Se trata de una doncella de unos diecis�is "
    "a�os, de facciones suaves, y grandes ojos pardos. Los bucles casta�o-rojizos caen "
    "sobre sus blancos hombros cpobremente cubiertos por una liviana t�nica de seda "
    "que desciende  hasta la parte superior de los muslos moldeando sus suaves curvas y "
    "dejando uno de sus tiernos senos al descubierto. La aparentemente n�vil amazona "
    "apoya la espalda en un esbelto abedul mientras atisba entre sus p�rpados "
    "entrecerrados la escena del prado y desliza la mano derecha bajo la breve t�nica, "
    "rodeando con la otra el seno descubierto.\n"
    "El cuadro encerrado en rico marco de plata, ocupa casi por completo una pared de la "
    "estancia. Fue tra�do desde la ciudad de Crowi, all� en el lejano sur, despu�s de "
    "que su autor, tras el gran �xito obtenido con la obra, desapareciera sin dejar "
    "rastro. Nunca m�s regres�, o al menos no entero, puesto que d�as mas tarde, la "
    "parte de su anatom�a a la que presumiblemente deb�a la rese�able exactitud y "
    "detallismo de la pintura, apareci� en el puerto de Crowi, a�n sangrante y sujeta "
    "con un clavo retorcido al tabl�n que informa del itenerario del Benoshan, barco "
    "en el cual hab�a arribado a la tierra de Goldhai. Nadie os� retirar tan macabro "
    "despojo y all� permaneci�, putrefacto hasta que los picoteos de las gaviotas acabaron con �l.\n");
    SetIntSmell("Huele a hierbas arom�ticas y perfume.\n");
    SetIntNoise("Suena una leve melod�a, suave y casi inapreciable.\n");
    Set(P_TPORT,TPORT_NO);
    ForbidAllMagic("La magia que se puede hacer aqu� es algo m�s gratificante que lo "
    "que pretentes hacer.\n");
    AddExit("norte", "./bodega2");
    AddExit("sur", "./terraza");
    AddDoor("norte", "una vieja puerta",
    "Es una destartalada puerta de madera vieja y negra para salir de esta estancia.\n",
    ({"puerta", "vieja puerta", "puerta vieja", "puerta de madera", "puerta del norte"}),
    "anillo_noble", ([P_DOOR_STATE:DOOR_CLOSED,P_DOOR_LOCK_STATE:DOOR_LOCKED]));
    AddDetail(({"cerradura", "cerradura de la puerta", "cerradura de puerta"}),
    "La puerta tiene una extra�a cerradura cuadrada.\n");
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
