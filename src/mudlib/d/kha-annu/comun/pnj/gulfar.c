/****************************************************************************
Fichero: gulfar.c
Autor: Ratwor
Fecha: 26/08/2007
Descripción: El tabernero del dragón azul.
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
    SetLong("Este viejo y ceñudo enano, de aspecto hosco y genio fácil es muy respetado "
    "en la sociedad de Kha-Annu, pues regenta con eficacia una de las mayores tabernas "
    "de la ciudad. \nSegún cuentan las historias, y el mismo gusta de proclamar a "
    "los 4 vientos, participó hace poco más de siglo y medio en las sangrientas guerras "
    "contra los orcos por el control de las minas de azmodan.\n Según se dice, luchó "
    "codo con codo con el legendario Ungrim Barba roja el mismo día que los enanos "
    "perdieron el control de las minas, vendiendo caras sus vidas y sus tesoros.\n"
    " Si está de buen humor, cosa que ocurre en contadas ocasiones, gusta de contar "
    "grandiosas historias, reales o imaginarias, sobre sus tiempos de guerrero y sus "
    "azañas en el campo de batalla. Pese a ello, nadie le ha oído hablar jamás de las "
    "estrañas circunstancias que en aquel aciago día provocaron la pérdida de su "
    "pierna izquierda.\n Sea como fuere, dicho trágico suceso provocó el fin de su "
    "carrera militar, y desde hace décadas deambula entre las mesas de la taberna"
    ", apoyándose estoicamente en una pesada muleta de hierro forjado que maneja "
    "con sorprendente ligereza: gruñendo entre dientes, maldiciendo a los orcos, "
    "despachando barriles de espumosa cerveza y fuentes rebosantes de jugosa carne "
    "y Haciendo gala de un vigor y una vitalidad dignas del mas jóven guerrero. Pese a "
    "ello, aveces reunido entorno al barril de cerveza, sus manos aprietan con furia "
    "la pesada muleta y a sus brillantes ojos  aflora una expresión melancólica "
    "de insondable intensidad, que jamás aflora a su pétreo rostro pero que deja "
    "traslucir la nostalgia de tiempos mejores.\n");
    SetWeight(80000);

    InitChats(2,
        ({"Gulfar cruza el local con rapidez, manteniendo en extraordinario equilibrio "
            "varias jarras en alto.\n",
        "Gulfar camina entre las mesas, acompañado del retumbar constante de su "
        "pesada muleta.\n",
        "Gulfar te observa irónico.\n", "Gulfar te clava una mirada feroz.\n",
        "Gulfar rellena una enorme jarra de piedra, con un borboteante chorro de espumosa "
        "cerveza negra, bajo el grifo del gran barril.\n",
        "Gulfar despacha con celeridad varias fuentes de piedra con enormes costillares "
        "humeantes.\n",
        "Gulfar cata con interés profesional la cerveza de una jarra.\n",
        "Gulfar se sirve una gran jarra de cerveza y la vacía de un largo y sonoro trago.\n",
        "Gulfar masculla algo entre dientes.\n",
        "Gulfar truena: Quien quiere más cerveza? creía vérmelas con enanos, no con "
        "elfos!!\n",
        "Gulfar masculla entre dientes: Malditos sean por siempre los orcos y sus inmundos "
        "antepasados.\n",
        "Gulfar comenta con tono casual: el que se fia de un kender es enano desvalijado!\n",
        "Gulfar farfulla: Solo los viles orcos mienten mas que los elfos!\n",
        "Gulfar clama atronador: Algún día borraremos de la faz de simauria a los viles "
        "orcos a fuerza de hachazos!\n"}));
    InitAChats(8,
    ({QueryName()+ " de equilibra con sorprendente agilidad apoyándose con la mano "
        "derecha sobre una mesa mientras con la izquierda blande su muleta con "
        "ferocidad.\n",
        QueryName()+ " trata de esquivar los ataques apoyándose en su muleta.\n",
        QueryName()+ " se aleja dando traspiés mientras trata de recuperar el equilibrio.\n",
        QueryName()+ " vocifera:\n Lamedor de horines de troll! Te voy a aplastar el "
    "cráneo!.\n"}));

    AddId(({"Gulfar", "gulfar", "tabernero", "cojo"}));
    AddQuestion(({"guerra", "guerras", "lucha", "luchas", "batalla", "batallas"}),
        QueryName()+ " te mira pensativo mientras una expresión amarga transluce en "
        "sus ojos, y luego comenta:\n Si... Yo estube allí, hace muchos años... \n "
        "Fueron duras para nuestro pueblo... \n Vi caer a muchos amigos y parientes, "
        "asesinados por esos inmundos pielesverdes, que el infierno se los lleve!.\n"
        " 5 largos años duraron aquellas guerras, y por mi honor que vendimos caro cada "
        "centímetro, cada piedra y cada nivel! y más caro aún vendimos nuestro oro!.\n"
        " Al final una veintena de nosotros conseguimos abrirnos paso a través del "
        "balle tras sellar para siempre las cámaras sagradas en las que nuestros caídos "
        "yacerán por siempre junto con las grandiosas montañas de tesoros que no "
        "pudimos llevarnos con nosotros aquel día fatídico.\n");

    AddQuestion(({"orcos", "pielesverdes", "pieles verdes", "enemigos"}),
        QueryName()+" hace un peligroso gesto amenazador con su muleta y luego gruñe:\n"
        " Eeesos pielesverdes infernales! Cientos, miles de ellos cayeron bajo la "
        "furia y las hachas de nuestro pueblo, viles criaturas, que el infierno se las "
        "lleve!.\n Eran cientos... que digo cientos, miles! nos derrotaron con trampas "
        "y traiciones propias solo de esa raza maldita una y mil veces!.\n"
        " Por el honor de mis antepasados que algún día adornará esa pared la cabeza "
        "disecada de su caudillo, si es que aún sigue con vida.\n");
    AddQuestion(({"cerveza", "cerveza negra"}),
        QueryName()+" exclama: Aaah! Siéntate y humedece el gaznate!\n A fe mía "
        "que no hay nada como un buen par de buenas jarras de cerveza negra de kha-Annu,"
        " cuando uno regresa de esas tierras del exterior, infestadas de viles orcos, "
        "elfos afeminados y kenders rateros.\n");

    AddQuestion("taberna", QueryName()+
        " dice: me encargo de esta taberna desde antes de que tu madre tubiera edad para "
        "parirte.\n  Por nuestro Señor Beltaim y mis antepasados que no encontrarás "
        "mejor cerveza que la mía en todo Kha-Annu... y en todo el Mundo! que me "
        "afeiten la barba si no digo bien!.\n");

    AddQuestion(({"minas", "azmodan"}),
        "Te parece distinguir una expresión de profunda melancolía en los duros ojos "
        "del enano mientras dice:\n Nuestro pueblo trabajó como solo los enanos "
        "somos capaces de trabajar, penetró en las montañas hasta profundidades "
        "inalcanzables para cualquier otra raza.\n Los tesoros y la gloria eran "
        "infinitos en aquellos tiempos: piedras preciosas, oro... Nuestras caravanas "
        "cruzaban el mundo de punta a punta cargadas con los mejores tesoros que "
        "jamás se han visto en Simauria.\n Pero tanta riqueza atrajo a los viles "
        "Pielesverdes como la carroña a los buitres. caían sobre nosotros de noche"
        ", desgastándonos con sucias emboscadas y viles trampas hasta que el último "
        "de nuestros valerosos guerreros perdió la vida, que nuestro pueblo los "
        "cubran de honor por toda la eternidad!.\n");

    AddQuestion(({"Ungrim", "ungrim"}), QueryName()+
        " se golpea la frente, fuertemente, con un puño macizo como una roca, y "
        "seguidamente dice:\n Ahhhh!, Ese viejo tunante bebedor de barriles y pisoteador"
        " de orcos!... Acaso lo has visto ultimamente? Hace años que no tengo noticias "
        "suyas!.\n Por su culpa estoy aquí, criándo moho en esta taberna como un "
        "humano envejecido y arrugado... Yo debí morir aquel día sabes? Debí caer "
        "junto a los míos, morir honrradamente llevándome por delante a un buen "
        "puñado de esos pielesverdes lamedores de horines de troll, que los fuegos "
        "del avismo los consuman para siempre!.\n Lideró la defensa del último reducto "
        "de la resistencia enana con el coraje y la determinación del que solo un "
        "enano es capaz, y nos encabezó como un uracán en la carga final, el día en "
        "que marchamos sobre el balle en cerrada formación y nos abrimos paso entre las "
        "infinitas hordas de orcos y goblins a fuerza de hachazos, sangre y odio!. "
        "Aquel día, el solo despedazó a más Pielesverdes que todos los demás juntos!, "
        "y al final... al final... Maldición! Ese viejo botarate me sacó de allí!"
        " Que su barba crezca larga y espesa por muchos siglos!.\n Nos trajo de vuelta a"
        " Kha-Annu a unos 20 camaradas, mas muertos que vivos... pero el no aguantó "
        "mucho, por mis antepasados que me alegro de su fortuna... Volvió a partir "
        "hacia las minas pocos años después. Hizo un juramento... Desde entonces no se "
        "lo a vuelto aver por aquí.\n");

    AddQuestion("juramento", QueryName()+
        " dice: Por mi barba! Los enanos jamás faltamos a nuestra palabra! jamás"
        "! Aunque nos cueste la vida o todos nuestros tesoros, un juramento es un "
        "juramento!.\n");

    AddQuestion("muleta", QueryName()+
        " te la muestra amenazador, levantándola sin esfuerzo aparente y te gruñe:.\n"
        " Que pasa! Quieres saborearla? te aseguro que es nutritiva! un par de bocados "
        "y dejarás de tener hambre el resto de tu vida! ja ja ja! Te aseguro que "
        "no serías el primero! ja ja ja!.\n");

    AddQuestion("pierna",
        "Los nudillos de Gulfar se vuelven blancos mientras aprieta con fuerza la "
        "muleta. La gélida mirada de ferocidad que te clava casi te hace creer "
        "que se va a lanzar contra ti de un momento a otro, así que decides, "
        "prudentemente, no volver a mencionar el tema.\n");

    AddQuestion(({"barril", "barriles", "barril de cerveza", "barriles de cerveza",
        "barril de cerveza negra", "barriles de cerveza negra"}), QueryName()+
        " te dice: tengo la mejor cerveza negra de todo el reino de Kha-annu, y, por mi "
        "barba  que seguro que del extranjero. Por tan solo 20 platinos te puedes "
        "llevar un magnífico barril de mi excepcional cerveza.\n",1);

    AddItem(WEAPON,REFRESH_REMOVE,
            ([P_WEAPON_TYPE:WT_VARA, P_WC:2, P_SIZE:P_SIZE_MEDIUM,
            P_MATERIAL:M_HIERRO,P_SHORT:"una muleta de hierro",
            P_LONG:"Una increiblemente pesada muleta de hierro forjado de algo menos "
                "de metro y medio de altura, con una tosca orquilla superior también de "
                "hierro y sin acolchar, para apoyarla bajo el brazo del portador.\n"
                "En toda su longitud no presenta ningún tipo de adorno, solo varios anillos de remaches"
                " puntiagudos colocados a intervalos regulares.\n Su extremo inferior "
                "termina en una cabeza ancha y maciza cuya forma y tamaño recuerda "
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
        return notify_fail(QueryName()+ " te grita: ¡¡Jamás le venderé mi cerveza "
        "a los sucios pielesverdes!!.\n");
    if (!str)
        return notify_fail(QueryName()+ " dice: bien, bien, así me gusta, que quieras "
        "gastarte el dinero, ahora sólo hace falta que tengas claro que es lo que "
        "quieres comprar.\n");
    if (str=="barril" || str=="barril de cerveza" || str=="baril de cerveza negra"){
        if (MONEY_LIB->QuerySomeonesValue(TP) < 12000)
        return notify_fail(QueryName()+" te dice: la cerveza no es gratis, mequetrefe, "
        "si quieres un barril de la mejor cerveza de todo Kha-annu tendrás que "
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
    return notify_fail(QueryName()+ " te dice: esto es una taberna enana, aquí se "
        "vende cerveza. Si quieres puedes mirar el menú y pedir lo que te plazca o lo "
        "que seas capaz de meterte en el cuerpo. Y también te puedo vender un barril de "
        "la mejor cerveza negra de Kha-annu.\n");
}
