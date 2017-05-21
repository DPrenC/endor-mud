/*
DESCRIPCION : panaderia de Boris en Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/tienda/panaderia.c
MODIFICACION: 19-04-98 [Angor@Simauria] Creacion
              11-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
#include <moving.h>
#include <wizlevels.h>
inherit SHOP;
#define PRON    (TP->QueryGender()==GENDER_FEMALE?"la":"le")
    
int cmd_matar(string str)
{
    if (!str) return 0;
    if (str!="Boris" && str!="boris" && str!="panadero" && str!="tendero") return 0;
    write("Boris grita: ¡Socorro, me atacan!\nAl tiempo que Boris se esconde bajo el mostrador, "
        "el corpulento Vaq sale rápidamente de la trastienda cargado con una inmensa hacha de "
        "combate para defender a su padre.\nVaq dice: ¡Miserable! ¡Atacar a un viejo indefenso! "
        "¡Te voy a enseñar modales! Te agarra con fuerza y te arrastra hasta la calle, "
        "arrojándote al suelo diciendo: ¡A ver si así aprendes a comportarte!\n");
    say(NOMBRE+" ataca a Boris, quien grita pidiendo auxilio y se esconde bajo el mostrador. "
        "Al momento aparece el corpulento Vaq desde la trastienda, armado con una inmensa hacha "
        "de combate, defendiendo a su padre.\nVaq le dice a "+NOMBRE+": ¡Miserable! ¡Atacar a "
        "un viejo indefenso! ¡te voy a enseñar modales!, tras lo cual "+PRON+" agarra con "
        "fuerza y "+PRON+" arrastra hasta la calle. Al cabo de un momento Vaq vuelve a entrar "
        "solo.\n",TP);
    tell_room(Z_CIUDAD("calle_02"),"Se oyen gritos que provienen de la panadería. De repente "
        "Vaq, el corpulento hijo del panadero sale de la panadería arrastrando a "+NOMBRE+" y "+
        PRON+" tira al suelo en medio de la calle. Tras esto, Vaq regresa a la panadería.\n");
    TP->move(Z_CIUDAD("calle_02"), M_SILENT);
    return 1;
}

create()
{
    ::create();
    SetIntShort("la panadería de Boris");
    SetIntLong("Te encuentras en la panadería de Boris. Es un pequeño local con un mostrador "
        "tras el cuál se halla el gran horno de leña donde se fabrica el pan. El viejo Boris "
        "se afana en controlar el horno y atender a los clientes, mientras su hijo Vaq, al que "
        "puedes ver de espaldas a través de la puerta, prepara la masa en la trastienda, "
        "al fondo del local.\n");
    AddDetail(({"mostrador"}),"Es una especie de armario bajo cubierto por una gruesa lámina de "
        "cristal bajo la cuál se exponen los productos que se fabrican en la panadería.\n");
    AddDetail(({"horno","lenya","leña","caldera","plancha","portilla"}),"Tras el mostrador, y "
        "en la pared del fondo del local se halla la puerta del horno consistente en una "
        "gruesa plancha de metal. Bajo ella una pequeña portilla permite acceder a la caldera "
        "donde se está quemando leña continuamente para mantener el horno caliente. Cada "
        "cierto tiempo, Boris arroja allí un poco de leña.\n");
    AddDetail(({"masa","trastienda","puerta","productos"}),"Una puerta comunica la panadería "
        "con la trastienda. Es allí donde se almacenan los diversos ingredientes y donde se "
        "fabrican los distintos productos que, tras pasar por el horno, se venderán en la "
        "panadería.\n");
    AddDetail(({"Vaq","vaq","hijo"}),"Vaq es el hijo de Boris, el propietario de esta "
        "panadería. Es un joven y corpulento orco con el que es mejor no enfrentarse. Ayuda a "
        "su padre trabajando en la trastienda de la panadería, aunque un día de éstos se "
        "enrolará en el ejército: sueña con ver mundo y correr grandes aventuras.\n");
    SetIntNoise("Se oye el lento crepitar de la leña al quemarse mientras calienta el horno.\n");
    SetIntSmell("Hmm.. del horno llega un agradable y tentador olor a pan recién hecho.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(1);
    SetIntBright(50);
    CanSell(0);
    CanAppraise(0);
    CanIdentify(0);
    RemoveDustbin();
    SetShopkeeper(PNJ_Z_CIUDAD("boris"));
    SetLastDest(Z_CIUDAD("calle_02"));
    SetNotifyExits("oeste");
    AddExit("oeste", Z_CIUDAD("calle_02"));
    AddDoor("oeste","la puerta de la panadería",
        "Es una gruesa puerta de madera labrada, fuerte y resistente.\n",
        ({"puerta","puerta de panaderia","puerta de panadería","puerta de la panaderia",
            "puerta de la panadería","puerta oeste"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({({"Intentas abrir la puerta, y al no poder, la miras y ves "
                "un cartel:\n'Cerrado toda la noche.'\n","Tratas de abrir la puerta en "
                "la oscuridad, pero no logras encontrar la manija.\n"}),({"@nombre@ trata de "
                "entrar en la panadería, pero se da cuenta de que cierra durante la noche.\n",
                "Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"}),
                P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddArticle(COMIDA("pan_barra"),REFRESH_REMOVE,6);
    AddArticle(COMIDA("pan_hogaza"),REFRESH_REMOVE,3);
    AddArticle(COMIDA("pan_molde"),REFRESH_REMOVE,6);
    AddArticle(COMIDA("panecillo"),REFRESH_REMOVE,10);
    AddArticle(COMIDA("rosquillas"),REFRESH_REMOVE,3);
    AddArticle(COMIDA("pastas"),REFRESH_REMOVE,3);
    AddArticle(COMIDA("bizcocho"),REFRESH_REMOVE,3);
    AddRoomCmd("matar","cmd_matar");
}

init()
{
    ::init();
    if (IS_LEARNER(TP) && TP->QueryInvis()) return;
    SkSay("Hola "+NOMBRE+", bienvenid"+AO+" a mi tienda.\n");
}
