/****************************************************************************
Fichero: gulfar.c
Autor: Ratwor
Fecha: 26/08/2007
Descripci�n: El tabernero del drag�n azul.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <gremios.h>
#include <money.h>
#include <moving.h>
inherit KBASE;

create(){
    ::create();
    SetStandard("Gulfar", "enano", ([GC_LUCHADOR:35]),GENDER_MALE);
    SetShort("Gulfar el tabernero");
    SetLong("Este viejo y ce�udo enano, de aspecto hosco y genio f�cil es muy respetado "
    "en la sociedad de Kha-Annu, pues regenta con eficacia una de las mayores tabernas "
    "de la ciudad. \nSeg�n cuentan las historias, y el mismo gusta de proclamar a "
    "los 4 vientos, particip� hace poco m�s de siglo y medio en las sangrientas guerras "
    "contra los orcos por el control de las minas de azmodan.\n Seg�n se dice, luch� "
    "codo con codo con el legendario Ungrim Barba roja el mismo d�a que los enanos "
    "perdieron el control de las minas, vendiendo caras sus vidas y sus tesoros.\n"
    " Si est� de buen humor, cosa que ocurre en contadas ocasiones, gusta de contar "
    "grandiosas historias, reales o imaginarias, sobre sus tiempos de guerrero y sus "
    "aza�as en el campo de batalla. Pese a ello, nadie le ha o�do hablar jam�s de las "
    "estra�as circunstancias que en aquel aciago d�a provocaron la p�rdida de su "
    "pierna izquierda.\n Sea como fuere, dicho tr�gico suceso provoc� el fin de su "
    "carrera militar, y desde hace d�cadas deambula entre las mesas de la taberna"
    ", apoy�ndose estoicamente en una pesada muleta de hierro forjado que maneja "
    "con sorprendente ligereza: gru�endo entre dientes, maldiciendo a los orcos, "
    "despachando barriles de espumosa cerveza y fuentes rebosantes de jugosa carne "
    "y Haciendo gala de un vigor y una vitalidad dignas del mas j�ven guerrero. Pese a "
    "ello, aveces reunido entorno al barril de cerveza, sus manos aprietan con furia "
    "la pesada muleta y a sus brillantes ojos  aflora una expresi�n melanc�lica "
    "de insondable intensidad, que jam�s aflora a su p�treo rostro pero que deja "
    "traslucir la nostalgia de tiempos mejores.\n");
    SetWeight(80000);

    InitChats(2,
        ({"Gulfar cruza el local con rapidez, manteniendo en extraordinario equilibrio "
            "varias jarras en alto.\n",
        "Gulfar camina entre las mesas, acompa�ado del retumbar constante de su "
        "pesada muleta.\n",
        "Gulfar te observa ir�nico.\n", "Gulfar te clava una mirada feroz.\n",
        "Gulfar rellena una enorme jarra de piedra, con un borboteante chorro de espumosa "
        "cerveza negra, bajo el grifo del gran barril.\n",
        "Gulfar despacha con celeridad varias fuentes de piedra con enormes costillares "
        "humeantes.\n",
        "Gulfar cata con inter�s profesional la cerveza de una jarra.\n",
        "Gulfar se sirve una gran jarra de cerveza y la vac�a de un largo y sonoro trago.\n",
        "Gulfar masculla algo entre dientes.\n",
        "Gulfar truena: Quien quiere m�s cerveza? cre�a v�rmelas con enanos, no con "
        "elfos!!\n",
        "Gulfar masculla entre dientes: Malditos sean por siempre los orcos y sus inmundos "
        "antepasados.\n",
        "Gulfar comenta con tono casual: el que se fia de un kender es enano desvalijado!\n",
        "Gulfar farfulla: Solo los viles orcos mienten mas que los elfos!\n",
        "Gulfar clama atronador: Alg�n d�a borraremos de la faz de simauria a los viles "
        "orcos a fuerza de hachazos!\n"}));
    InitAChats(8,
    ({QueryName()+ " de equilibra con sorprendente agilidad apoy�ndose con la mano "
        "derecha sobre una mesa mientras con la izquierda blande su muleta con "
        "ferocidad.\n",
        QueryName()+ " trata de esquivar los ataques apoy�ndose en su muleta.\n",
        QueryName()+ " se aleja dando traspi�s mientras trata de recuperar el equilibrio.\n",
        QueryName()+ " vocifera:\n Lamedor de horines de troll! Te voy a aplastar el "
    "cr�neo!.\n"}));

    AddId(({"Gulfar", "gulfar", "tabernero", "cojo"}));
    AddQuestion(({"guerra", "guerras", "lucha", "luchas", "batalla", "batallas"}),
        QueryName()+ " te mira pensativo mientras una expresi�n amarga transluce en "
        "sus ojos, y luego comenta:\n Si... Yo estube all�, hace muchos a�os... \n "
        "Fueron duras para nuestro pueblo... \n Vi caer a muchos amigos y parientes, "
        "asesinados por esos inmundos pielesverdes, que el infierno se los lleve!.\n"
        " 5 largos a�os duraron aquellas guerras, y por mi honor que vendimos caro cada "
        "cent�metro, cada piedra y cada nivel! y m�s caro a�n vendimos nuestro oro!.\n"
        " Al final una veintena de nosotros conseguimos abrirnos paso a trav�s del "
        "balle tras sellar para siempre las c�maras sagradas en las que nuestros ca�dos "
        "yacer�n por siempre junto con las grandiosas monta�as de tesoros que no "
        "pudimos llevarnos con nosotros aquel d�a fat�dico.\n");

    AddQuestion(({"orcos", "pielesverdes", "pieles verdes", "enemigos"}),
        QueryName()+" hace un peligroso gesto amenazador con su muleta y luego gru�e:\n"
        " Eeesos pielesverdes infernales! Cientos, miles de ellos cayeron bajo la "
        "furia y las hachas de nuestro pueblo, viles criaturas, que el infierno se las "
        "lleve!.\n Eran cientos... que digo cientos, miles! nos derrotaron con trampas "
        "y traiciones propias solo de esa raza maldita una y mil veces!.\n"
        " Por el honor de mis antepasados que alg�n d�a adornar� esa pared la cabeza "
        "disecada de su caudillo, si es que a�n sigue con vida.\n");
    AddQuestion(({"cerveza", "cerveza negra"}),
        QueryName()+" exclama: Aaah! Si�ntate y humedece el gaznate!\n A fe m�a "
        "que no hay nada como un buen par de buenas jarras de cerveza negra de kha-Annu,"
        " cuando uno regresa de esas tierras del exterior, infestadas de viles orcos, "
        "elfos afeminados y kenders rateros.\n");

    AddQuestion("taberna", QueryName()+
        " dice: me encargo de esta taberna desde antes de que tu madre tubiera edad para "
        "parirte.\n  Por nuestro Se�or Beltaim y mis antepasados que no encontrar�s "
        "mejor cerveza que la m�a en todo Kha-Annu... y en todo el Mundo! que me "
        "afeiten la barba si no digo bien!.\n");

    AddQuestion(({"minas", "azmodan"}),
        "Te parece distinguir una expresi�n de profunda melancol�a en los duros ojos "
        "del enano mientras dice:\n Nuestro pueblo trabaj� como solo los enanos "
        "somos capaces de trabajar, penetr� en las monta�as hasta profundidades "
        "inalcanzables para cualquier otra raza.\n Los tesoros y la gloria eran "
        "infinitos en aquellos tiempos: piedras preciosas, oro... Nuestras caravanas "
        "cruzaban el mundo de punta a punta cargadas con los mejores tesoros que "
        "jam�s se han visto en Simauria.\n Pero tanta riqueza atrajo a los viles "
        "Pielesverdes como la carro�a a los buitres. ca�an sobre nosotros de noche"
        ", desgast�ndonos con sucias emboscadas y viles trampas hasta que el �ltimo "
        "de nuestros valerosos guerreros perdi� la vida, que nuestro pueblo los "
        "cubran de honor por toda la eternidad!.\n");

    AddQuestion(({"Ungrim", "ungrim"}), QueryName()+
        " se golpea la frente, fuertemente, con un pu�o macizo como una roca, y "
        "seguidamente dice:\n Ahhhh!, Ese viejo tunante bebedor de barriles y pisoteador"
        " de orcos!... Acaso lo has visto ultimamente? Hace a�os que no tengo noticias "
        "suyas!.\n Por su culpa estoy aqu�, cri�ndo moho en esta taberna como un "
        "humano envejecido y arrugado... Yo deb� morir aquel d�a sabes? Deb� caer "
        "junto a los m�os, morir honrradamente llev�ndome por delante a un buen "
        "pu�ado de esos pielesverdes lamedores de horines de troll, que los fuegos "
        "del avismo los consuman para siempre!.\n Lider� la defensa del �ltimo reducto "
        "de la resistencia enana con el coraje y la determinaci�n del que solo un "
        "enano es capaz, y nos encabez� como un urac�n en la carga final, el d�a en "
        "que marchamos sobre el balle en cerrada formaci�n y nos abrimos paso entre las "
        "infinitas hordas de orcos y goblins a fuerza de hachazos, sangre y odio!. "
        "Aquel d�a, el solo despedaz� a m�s Pielesverdes que todos los dem�s juntos!, "
        "y al final... al final... Maldici�n! Ese viejo botarate me sac� de all�!"
        " Que su barba crezca larga y espesa por muchos siglos!.\n Nos trajo de vuelta a"
        " Kha-Annu a unos 20 camaradas, mas muertos que vivos... pero el no aguant� "
        "mucho, por mis antepasados que me alegro de su fortuna... Volvi� a partir "
        "hacia las minas pocos a�os despu�s. Hizo un juramento... Desde entonces no se "
        "lo a vuelto aver por aqu�.\n");

    AddQuestion("juramento", QueryName()+
        " dice: Por mi barba! Los enanos jam�s faltamos a nuestra palabra! jam�s"
        "! Aunque nos cueste la vida o todos nuestros tesoros, un juramento es un "
        "juramento!.\n");

    AddQuestion("muleta", QueryName()+
        " te la muestra amenazador, levant�ndola sin esfuerzo aparente y te gru�e:.\n"
        " Que pasa! Quieres saborearla? te aseguro que es nutritiva! un par de bocados "
        "y dejar�s de tener hambre el resto de tu vida! ja ja ja! Te aseguro que "
        "no ser�as el primero! ja ja ja!.\n");

    AddQuestion("pierna",
        "Los nudillos de Gulfar se vuelven blancos mientras aprieta con fuerza la "
        "muleta. La g�lida mirada de ferocidad que te clava casi te hace creer "
        "que se va a lanzar contra ti de un momento a otro, as� que decides, "
        "prudentemente, no volver a mencionar el tema.\n");

    AddQuestion(({"barril", "barriles", "barril de cerveza", "barriles de cerveza",
        "barril de cerveza negra", "barriles de cerveza negra"}), QueryName()+
        " te dice: tengo la mejor cerveza negra de todo el reino de Kha-annu, y, por mi "
        "barba  que seguro que del extranjero. Por tan solo 20 platinos te puedes "
        "llevar un magn�fico barril de mi excepcional cerveza.\n",1);

    AddItem(WEAPON,REFRESH_REMOVE,
            ([P_WEAPON_TYPE:WT_VARA, P_WC:2, P_SIZE:P_SIZE_MEDIUM,
            P_MATERIAL:M_HIERRO,P_SHORT:"una muleta de hierro",
            P_LONG:"Una increiblemente pesada muleta de hierro forjado de algo menos "
                "de metro y medio de altura, con una tosca orquilla superior tambi�n de "
                "hierro y sin acolchar, para apoyarla bajo el brazo del portador.\n"
                "En toda su longitud no presenta ning�n tipo de adorno, solo varios anillos de remaches"
                " puntiagudos colocados a intervalos regulares.\n Su extremo inferior "
                "termina en una cabeza ancha y maciza cuya forma y tama�o recuerda "
                "vagamente a la de un martillo de forja.\n",
            P_IDS:({"muleta", "muleta de hierro"}), P_GENDER:GENDER_FEMALE,
            P_NUMBER_HANDS:1, P_WEIGHT:2400, P_VALUE: 730]), SF(wieldme));

}


public void init(){
    ::init();
    add_action("cmd_comprar", "comprar");
}

public int cmd_comprar(string str){
    object barril= clone_object(OTRO("barril_cerveza"));
    string *pagar;
    if(TP->QueryRace()=="orco")
        return notify_fail(QueryName()+ " te grita: ��Jam�s le vender� mi cerveza "
        "a los sucios pielesverdes!!.\n");
    if (!str)
        return notify_fail(QueryName()+ " dice: bien, bien, as� me gusta, que quieras "
        "gastarte el dinero, ahora s�lo hace falta que tengas claro que es lo que "
        "quieres comprar.\n");
    if (str=="barril" || str=="barril de cerveza" || str=="baril de cerveza negra"){
        if (MONEY_LIB->QuerySomeonesValue(TP) < 12000)
        return notify_fail(QueryName()+" te dice: la cerveza no es gratis, mequetrefe, "
        "si quieres un barril de la mejor cerveza de todo Kha-annu tendr�s que "
        "llevar encima 20 platinos.\n");
        if(TP->MayAddIntWeight(30000)){
            tell_room(environment(), QueryName()+ " grita: Marchando un barril de buena "
                "cerveza negra para "+ (TP->QueryGender()==GENDER_FEMALE ? "la " : "el ")+
                TP->QueryRace()+" "+CAP(TNAME)+".\n");
            barril->move(TP);
            pagar = MONEY_LIB->PayValueString2(TP, 20000, 0,
                "a cambio del barril de cerveza negra");
            write (pagar[0]);
            say (pagar[1], TP);
            return 1;
        }
        return notify_fail(QueryName()+ " te dice: ja ja ja! pretendes cargar eso "
            "encima? no creo que seas capaz ni de levantar una de estas jarras!.\n");
    }
    return notify_fail(QueryName()+ " te dice: esto es una taberna enana, aqu� se "
        "vende cerveza. Si quieres puedes mirar el men� y pedir lo que te plazca o lo "
        "que seas capaz de meterte en el cuerpo. Y tambi�n te puedo vender un barril de "
        "la mejor cerveza negra de Kha-annu.\n");
}
