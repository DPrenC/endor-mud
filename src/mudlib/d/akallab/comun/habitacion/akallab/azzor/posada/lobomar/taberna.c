/*
DESCRIPCION : posada del Lobo de mar
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/posada/lobomar/taberna.c
MODIFICACION:
06-12-05 [Riberales] Creacion
16-09-07 [Angor] Movido a posada/lobomar/ . Cambiadas las descripciones. Añadidas bebidas.
*/

#include "path.h"
#include <properties.h>
#include <nightday.h>
#include <materials.h>
#include <sounds.h>
#include <door.h>
inherit PUB;

create()
{
    ::create();
    SetLocate("ciudad de Azzor");
    SetIntShort("la taberna de la posada Lobo de Mar");
    SetIntLong("La planta baja de la posada es una amplia sala baja con gruesos pilares de "
        "madera que sostienen el resto del edificio. Al este un ventanal con vidrios "
        "translúcidos da al muelle. Una larga barra se halla junto a la pared norte, y tras "
        "ella, estantes con todo tipo de barriles. La simple decoración del local está hecha "
        "con viejos útiles de pesca colgados descuidadamente del techo, en especial redes y "
        "boyas.\n");
    AddDetail( ({"barra","pizarra","plancha"}),"Es una larga y baja barra de madera colocada "
        "frente a la pared norte de la sala. Deberías acercarte allí para pedir al tabernero "
        "algo. Colgada de la pared ves una plancha de pizarra en la que está escrito el menú "
        "que puedes leer.\n");
    SetIndoors(1);
    SetIntBright(45);
    SetIntSmell("Huele a alcohol y a carne asada.\n");
    SetIntNoise("Escuchas el follón típico de una taberna.\n");
    SetKeeper(PNJ_AZZOR("taber_lobo"));
    // Cerramos de madrugada y abrimos al mediodía, para servir las comidas...
    SetCloseTime(({ND_PREDAWN,ND_DAWN,ND_SUNRISE,ND_PRENOON}));
    SetAssociatedRooms("comedor");
    SetLastDest("entrada");
    SetNotifyExits("sur");
    SetInformCloseMsg("Molly golpea el mostrador con un cucharón gritando:\n¡Vamos, id "
        "terminando que nos vamos!\n");
    SetThrowOutMsg("Molly arroja el delantal bajo el mostrador, sale y grita:\n¡Venga, se "
        "acabó! ¡Todo el mundo fuera, que me voy a dormir!\n");
    SetNotifyCloseMsg("Molly sale de la taberna empujando al último cliente, cierra la puerta, "
        "y sin mirar a ningún lado, cruza el vestíbulo y sale a la calle.\n");
    SetNotifyOpenMsg("Molly llega del este, te mira lanzando un bufido, y sin decir palabra, "
        "abre la puerta de la taberna y entra en ella.\n");
    //Ahora el menú.
    AddFood("cordero asado","un plato de",10,8,0);
    AddFood("patas de cerdo","unas",15,11,0,"Te comes unas patitas de cerdo. "
        "¡Buenísimas!\n");
    AddDrink("stout","una gran jarra de",11,10,10,0,"Te tomas una jarra de cerveza stout, "
        "negra, densa, algo amarga y con mucha espuma... ¡Aah! muy buena...\n");
    AddDrink("lager","una gran jarra de",10,10,10,0,"Te tomas una jarra de cerveza lager, "
        "ambar, densa, amarga y con mucha espuma... ¡Aah! muy buena...\n");
    AddDrink("agua","un vaso de",5,0,9,0,"El agua esta algo salada...te preguntas si no la "
        "habrán cogido directamente del puerto...\n");
    AddDrink("vino rancio","un vaso de",9,8,6,0,"Los mejores días de este vino ya pasaron...\n");
    AddDrink("mataenanos","un chupito de",14,15,8,0,"Te tomas un chupito de mataenanos, una "
        "especialidad local a base de alcohol y plantas. ¡La garganta te arde!\n");
    AddExit("sur",AZ_POSADA("lobomar/entrada"));
    AddExit("oeste",AZ_POSADA("lobomar/comedor"));
    AddDoor("sur","la puerta de la taberna",
        "La puerta no es muy gruesa. Está hecha de madera pulida. En su parte superior tiene "
            "un panel de cristal. Supones que al ser interior, no precisa ser muy resistente.\n",
        ({"puerta","puerta sur","puerta de taberna","puerta de la taberna"}),GENDER_FEMALE,
        ([P_DOOR_TRANSPARENCY:1,P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME:({ND_PREDAWN,ND_DAWN,ND_SUNRISE,ND_PRENOON}),
        P_DOOR_CANT_OPEN_MSG:({({"Molly se fué a dormir de madrugada, "
            "y no volverá hasta el mediodía, a servir..., comida.\n","Tratas de abrir la "
            "puerta en la oscuridad, pero no consigues encontrar la manija.\n"}),({"@nombre@ "
            "pensaba meterse un lingotazo, pero la taberna está cerrada...\n","Oyes a alguien "
            "removerse, jurando en la oscuridad.\n"}),
            "Parece que alguien trata de abrir la puerta.\n"})]));
}

