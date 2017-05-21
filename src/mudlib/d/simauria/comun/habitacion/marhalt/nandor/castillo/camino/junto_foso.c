/****************************************************************************
Fichero: junto_foso.c
Autor: Ratwor
Fecha: 24/12/2007
Descripci�n: archivo base del camino del exterior del castillo, junto al foso.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();

    SetIntShort("el sendero de la colina, junto al castillo");
    switch(d4()){
        case 1:
            SetIntLong("Te encuentras en lo altto de la colina, junto a la esplendida "
            "fortaleza de la villa de Nandor. Tan s�lo te separa de la enorme muralla "
            "el maloliente foso que tienes a tus pies.\n Desde tu altura puedes "
            "divisar gran parte de la regi�n de Marhalt como: los bosques de Cored y "
            "Marhalt, la colina casi en su totalidad, la villa de Nandor y la esquina "
            "nordeste del castillo.\n");
            break;
        case 2:
            SetIntLong("Est�s junto a la muralla del enorme castillo que reina sobre "
            "la colina en la que te encuentras. El maloliente foso bordea en su "
            "totalidad toda la fortaleza, evitando as� la escala de sus muros a los "
            "posibles enemigos. Desde aqu� se puede divisar gran parte de la regi�n de "
            "Marhalt, pues es uno de los puntos m�s altos de la zona.\n");
            break;
        case 3:
            SetIntLong("Caminas bordeando la fortaleza, acompa��ndote en todo momento "
            "el horrible foso que tantas vidas se habr� cobrado.\n Las murallas se "
            "alzan sobre tu cabeza en multitud de metros, vistas desde tu posici�n "
            "parece realmente dif�cil su escala.\n Esta parte del camino est� algo "
            "m�s cuidada respecto al inc�modo sendero serpenteante del este de la "
            "colina, aunque por supuesto deja mucho que desear al lado del camino "
            "empedrado que se puede apreciar desde aqu� en su �rea noroeste.\n");
            break;
        case 4:
            SetIntLong("Te encuentras junto al castillo de la villa de Nandor, bajo "
            "sus enormes murallas bordeadas por un apestoso y peligroso foso.\n La "
            "entrada de la fortaleza la puedes encontrar algo m�s al oeste, donde "
            "se une este peque�o sendero con el camino empedrado que asciende la colina "
            "desde el camino del norte de Marhalt, en la parte noroeste de esta loma.\n");
            break;
    }
    AddDetail(({"esquina nordeste", "esquina nordeste del castillo"}),
    "En la esquina nordeste de la fortaleza se alza imperioso el torre�n de C�nor.\n");
    AddDetail(({"torre�n del nordeste", "torre�n de C�nor", "torre�n de c�nor", "c�nor",
        "torreon del nordeste", "torreon de C�nor", "torreon de c�nor", "c�nor",
        "torreon", "torre�n", "torre"}),
    "El torre�n de C�nor recibe �ste nombre en honor al famoso h�roe que inici� la "
    "l�nea Desh'Blain.\n"
    "Est� constru�do en forma cil�ndrica para evitar los puntos d�biles ofrecidos en las "
    "torres con esquinas que al ser derrumbadas ocasionan la ruina de toda la "
    "fortificaci�n, y con el objetivo de dotar a la estructura de mas resistencia al "
    "estar repartido por igual el peso sobre la obra exterior. Se apoya sobre "
    "robustos contrafuertes, una especie de cortos muros laterales de no mas de un "
    "metro de anchura que se van estrechando hacia arriba. Unas angostas aspilleras "
    "oradadas a lo largo de los muros proporcionan puntos de vigilancia y disparo a los "
    "defensores. La parte superior est� protegida por almenas algo sobresalientes, "
    "apoyadas sobre una serie de gradas invertidas, de forma que la parte superior del "
    "torre�n es mas amplia que el cuerpo propiamente dicho.\n");

    AddDetail(({"suelo", "sendero"}), "Te encuentras en una superficie m�s o menos "
    "plana de la colina, con total seguridad debido a la cercan�a de las murallas del "
    "castillo y su foso el cual lo tienes casi a tus pies.\n");
    AddDetail(({"loma", "colina"}),
    "La colina rompe el paisage suave y ondulado como un descarnado "
    "pu�o de piedra que emerge s�bitamente del suelo. Desde aqu� puedes ver sus "
    "vertientes este y norte.\n");
    AddDetail("vertiente este", "un abrupto terrapl�n de varias decenas de metros de altura "
    "por el que serpentea un estrecho camino que asciende trabajosamente entre rocas "
    "y �rboles esmirriados y torcidos que se aferran a la �rida pared pedregosa como "
    "extra�os seres amarillentos a una calavera reseca.\n");
    AddDetail(({"fortaleza", "castillo"}),
    "La fortaleza se cierne sobre el terreno circundante desde lo alto de la "
    "colina, una edificaci�n recia, sombr�a y angulosa, carente de todo atractivo "
    " art�stico pero sin duda bien situado y de construcci�n s�lida.\n");
    AddDetail(({"Nandor", "nandor", "villa", "pueblo", "aldea"}),
    "La villa de Nandor se extiende all� abajo al este, en el interior de una suave hondonada que "
    "acuna sus sencillas construcciones de piedra y madera.\n Hacia el sudeste, el "
    "verde dosel del bosque de Maralth se recorta contra el cielo, al otro lado de "
    "la depresi�n del terreno.\n");
    AddDetail(({"cored", "Cored", "bosque de cored", "bosque de Cored"}),
    "El bosque viejo de Cored parece emanar una negrura sobrenatural en el norte. "
    "Es denso y no es posible apreciar ning�n detalle a trav�s de su gama de colores "
    "oscuros. Todo lo que espresa su vegetaci�n es intranquilidad.\n");
    AddDetail(({"declibe", "vertiente norte"}), "La vertiente norte de la colina desciende en un "
    "suave declive cubierto de hierba hasta el camino del norte de Marhalt, el cual "
    "a su vez bordea tanto esta colina como el oscuro bosque de Cored.\n");
    AddDetail("puente", "Un robusto puente levadizo de madera de roble sostenido por "
    "cadenas de hierro que salva el profundo foso que rodea el castillo.\n");
    AddDetail("foso", "Te asomas para observar el foso. Es una profunda "
    "zanja cabada a los pies de los contrafuertes que sostienen las murallas en cuyo "
    "terroso fondo hay algunos charcos negruzcos de barro malholiente procedente de las "
    "aguas fecales y dem�s desperdicios del castillo. �sta zona ha sido descuidada, "
    "pues sus bordes aparecen desmoronados, las estacas de hierro que rematan el fondo "
    "est�n oxidadas e inclinadas, y en la parte baja crecen algunas plantas rastreras.\n");
    AddDetail(({"estacas", "estaca"}), "Son unas barras de hierro de metro y medio de "
    "longitud que se estrechan desde la base para terminar en punta. Habitualmente este "
    "tipo de defensa se coloca en el fondo de fosos y zanjas defensivas para ensartar a "
    "cualquier hombre o caballo que caiga desde arriba, lo que suele resultar en una "
    "muerte ag�nica y terrible. �stas estacas en particular est�n recubiertas por una "
    "gruesa capa de �xido ya antiguo, aparecido por causa de la humedad y al descuido.\n"
    "Algunas se inclinan precariamente, mientras que otras reposan medio enterradas "
    "en el barro.\n");
    AddDetail(({"murallas", "muralla", "muro", "pared", "paredes"}),
    "Las fuertes murallas que protegen el castillo "
    "cercan el patio de armas por tres de sus lados, alz�ndose en hileras de grandes "
    "bloques de piedra cada una de las cuales se apoya sobre otras dos, haciendo el "
    "muro mas resistente y evitando que se derrumbe por el peso.\n");
    SetIntSmell("Percibes el olor de agua estancada procedente del foso.\n");

    SetIndoors(0);
    SetLocate("el norte de Marhalt");
    if(d10()==1)
        AddItem(PNJCASTILLO("hombre_armas1"), REFRESH_DESTRUCT);
}

