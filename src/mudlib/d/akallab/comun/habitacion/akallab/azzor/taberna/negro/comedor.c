/*
DESCRIPCION : Meson del Negro
FICHERO     : posada/meson_negro/comedor.c
MODIFICACION:
16-09-07 [Angor] Creacion
*/

#include "path.h"
#include AK_MACRO
#include <properties.h>
#include <nightday.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
inherit PUB;

create()
{
    ::create();
    SetLocate("ciudad de Azzor");
    SetIntShort("el mesón del Negro");
    SetIntLong("El mesón es simplemente una larga estancia de techo bajo con la cocina al "
        "fondo.\nLargas mesas y bancos ocupan la mayor parte del mismo. Junto a la puerta se "
        "halla una hamaca donde el Negro pasa las horas en las que no trabaja cuando hace buen "
        "tiempo y la brisa que llega del puerto atempera el calor. Allí se dedica a sus otras "
        "dos pasiones, el tabaco negro del sur y el dormir después de una buena noche de "
        "música y borrachera. En la pared del mesón cuelgan un par de tallas de madera con el "
        "estilo del sur.\n");
    AddDetail( ({"mesas","bancos"}),"Esto está lleno de mesas y bancos. Siéntate donde haya "
        "sitio libre.\n");
    AddDetail( ({"hamaca"}),"Está hecha de cáñamo trenzado y colgada junto a la puerta del "
        "mesón. Si el Negro no esta tras los fogones, seguro que esta descansando en ella.\n");
    AddDetail( ({"tallas", "tortugas"}),"Las tallas colgadas de la pared del mesón representan "
        "unas grandes tortugas cornudas de mar y están talladas en madera de palmera. Es un "
        "motivo típico de la decoración de las gentes del sur.\n");
    SetIndoors(1);
    SetIntBright(45);
    SetIntSmell("Huele a pescado asado.\n");
    SetIntNoise("Escuchas el follón típico de una taberna.\n");
    //Ahora el menú.
    AddFood("salmón asado","un plato de",12,12,0,
            "Unas generosas lonchas de salmón asadas a la piedra con sal gruesa, "
            "revuelto de setas de guarnición y un buen trozo de pan. ¡Esto tienes "
            "que repetirlo más a menudo!\n");
    AddFood("trucha al horno","una",8,8,0,
            "La trucha está aliñada con multitud de finas hierbas y asada enrollada en una "
            "hoja de platanero para mantener los jugos. El aspecto es inusual, pero el "
            "sabor es delicioso...\n");
    AddFood("pulpo con pimentón","una ración de",10,10,0,
            "Aunque pueda parecer fácil de cocinar, ya que no es más que pulpo cocido, aceite, "
            "ajo y pimentón, hacer que quede tan tierno como éste es complicado. Rebañas el "
            "plato con pan y te chupas los dedos...\n");
    AddFood("sopa de pescado","una ración de",3,3,0,
            "Con los restos de pescado, verduras y arroz el Negro ha cocinado una sopa que "
            "aunque no llena tanto como otros platos es muy sabrosa y económica.\n");
    AddFood("sopa de cangrejo","un plato de",4,4,0,
        "Los cangrejos los han aplastado tal cual para hacer esta sopa, así que has de apartar "
        "los trozos de concha si no quieres llevarte una sorpresa. De todas formas, la mezcla "
        "de sabores de cangrejo, tomate y ajo es deliciosa.\n");
    AddFood("cebiche","una ración de",6,6,0,
        "Pescado crudo con zumo de limón y guarnición de algas y maíz joven. Tardas en cogerle "
        "el punto, pero cuando lo haces, sabes que has de repetir..., si aún queda.\n");
    AddDrink("lager","una gran jarra de",10,10,10,0,
        "Te tomas una jarra de cerveza lager, ámbar, densa, amarga "
        "y con mucha espuma... ¡Aah! muy buena...\n");
    AddDrink("agua","un vaso de",5,0,9,0,
        "El agua esta algo salada...te preguntas si no la habran cogido "
        "directamente del puerto...\n");
    AddDrink("vino","un vaso de",11,9,6,0,
        "No es el mejor que has probado, pero los hay mucho peores...");
    AddDrink("mataviejas","un vaso pequeño de",14,15,8,0,
        "Alcohol destilado de arroz con un escorpión dentro de la botella... ¡Sabroso y buen "
        "desinfectante!\n");
    SetKeeper(PNJ_AZZOR("negro_comedor"));
    SetCloseTime(({ND_NIGHT,ND_PREDAWN,ND_DAWN,ND_SUNRISE,ND_PRENOON}));
    SetAssociatedRooms(({"cocina","despensa"}));
    SetLastDest(AZ_PUERTO("portico06"));
    SetThrowOutMsg("El negro llega del oeste y dice:\nVenga, Koen, cierra ya.\nY acto seguido "
        "desaparece por el este.\nKoen sale de detrás del mostrador y dice: Está bien señores, "
        "es hora de cerrar, vayan saliendo en orden por favor.\n");
    SetNotifyExits("este");
    SetInformCloseMsg("El negro se asoma desde la cocina y grita:\n¡Koen! ¡Ve recogiendo, que "
        "nos vamos!\n");
    SetNotifyOpenMsg("Koen aparece frotándose los ojos y abre la puerta del mesón. Casi como "
        "si le hubiesen llamado, aparece el Negro, quien te saluda con un descomunal bostezo, "
        "y ambos entran en el local.\n");
    SetNotifyCloseMsg("Koen sale del mesón alisándose el pelaje con las garras, cierra la "
        "puerta y se aleja calle abajo.\n");
    AddExit("este",AZ_PUERTO("portico06"));
    AddExit("oeste","cocina");
    AddDoor("este","la puerta del mesón",
        "Es una gruesa puerta de madera, barnizada y decorada, elegante , pero resistente.\n",
        ({"puerta","puerta meson","puerta de meson","puerta del meson","puerta mesón",
            "puerta de mesón","puerta del mesón"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME:({ND_NIGHT,ND_PREDAWN,ND_DAWN,ND_SUNRISE,ND_PRENOON}),
            P_DOOR_CANT_OPEN_MSG:({({"Tendrás que esperar algo si tienes hambre, el negro se "
                "va de noche, y no volverá hasta el mediodía.\n","Buscas una puerta en la "
                "oscuridad, pero no consigues encontrarla, cuidado al moverte, no te caigas al "
                "mar...\n"}),({"@nombre@ pensaba darse un festín, pero el mesón está cerrado...\n",
                "Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"})]));
}
