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
    SetIntShort("el mes�n del Negro");
    SetIntLong("El mes�n es simplemente una larga estancia de techo bajo con la cocina al "
        "fondo.\nLargas mesas y bancos ocupan la mayor parte del mismo. Junto a la puerta se "
        "halla una hamaca donde el Negro pasa las horas en las que no trabaja cuando hace buen "
        "tiempo y la brisa que llega del puerto atempera el calor. All� se dedica a sus otras "
        "dos pasiones, el tabaco negro del sur y el dormir despu�s de una buena noche de "
        "m�sica y borrachera. En la pared del mes�n cuelgan un par de tallas de madera con el "
        "estilo del sur.\n");
    AddDetail( ({"mesas","bancos"}),"Esto est� lleno de mesas y bancos. Si�ntate donde haya "
        "sitio libre.\n");
    AddDetail( ({"hamaca"}),"Est� hecha de c��amo trenzado y colgada junto a la puerta del "
        "mes�n. Si el Negro no esta tras los fogones, seguro que esta descansando en ella.\n");
    AddDetail( ({"tallas", "tortugas"}),"Las tallas colgadas de la pared del mes�n representan "
        "unas grandes tortugas cornudas de mar y est�n talladas en madera de palmera. Es un "
        "motivo t�pico de la decoraci�n de las gentes del sur.\n");
    SetIndoors(1);
    SetIntBright(45);
    SetIntSmell("Huele a pescado asado.\n");
    SetIntNoise("Escuchas el foll�n t�pico de una taberna.\n");
    //Ahora el men�.
    AddFood("salm�n asado","un plato de",12,12,0,
            "Unas generosas lonchas de salm�n asadas a la piedra con sal gruesa, "
            "revuelto de setas de guarnici�n y un buen trozo de pan. �Esto tienes "
            "que repetirlo m�s a menudo!\n");
    AddFood("trucha al horno","una",8,8,0,
            "La trucha est� ali�ada con multitud de finas hierbas y asada enrollada en una "
            "hoja de platanero para mantener los jugos. El aspecto es inusual, pero el "
            "sabor es delicioso...\n");
    AddFood("pulpo con piment�n","una raci�n de",10,10,0,
            "Aunque pueda parecer f�cil de cocinar, ya que no es m�s que pulpo cocido, aceite, "
            "ajo y piment�n, hacer que quede tan tierno como �ste es complicado. Reba�as el "
            "plato con pan y te chupas los dedos...\n");
    AddFood("sopa de pescado","una raci�n de",3,3,0,
            "Con los restos de pescado, verduras y arroz el Negro ha cocinado una sopa que "
            "aunque no llena tanto como otros platos es muy sabrosa y econ�mica.\n");
    AddFood("sopa de cangrejo","un plato de",4,4,0,
        "Los cangrejos los han aplastado tal cual para hacer esta sopa, as� que has de apartar "
        "los trozos de concha si no quieres llevarte una sorpresa. De todas formas, la mezcla "
        "de sabores de cangrejo, tomate y ajo es deliciosa.\n");
    AddFood("cebiche","una raci�n de",6,6,0,
        "Pescado crudo con zumo de lim�n y guarnici�n de algas y ma�z joven. Tardas en cogerle "
        "el punto, pero cuando lo haces, sabes que has de repetir..., si a�n queda.\n");
    AddDrink("lager","una gran jarra de",10,10,10,0,
        "Te tomas una jarra de cerveza lager, �mbar, densa, amarga "
        "y con mucha espuma... �Aah! muy buena...\n");
    AddDrink("agua","un vaso de",5,0,9,0,
        "El agua esta algo salada...te preguntas si no la habran cogido "
        "directamente del puerto...\n");
    AddDrink("vino","un vaso de",11,9,6,0,
        "No es el mejor que has probado, pero los hay mucho peores...");
    AddDrink("mataviejas","un vaso peque�o de",14,15,8,0,
        "Alcohol destilado de arroz con un escorpi�n dentro de la botella... �Sabroso y buen "
        "desinfectante!\n");
    SetKeeper(PNJ_AZZOR("negro_comedor"));
    SetCloseTime(({ND_NIGHT,ND_PREDAWN,ND_DAWN,ND_SUNRISE,ND_PRENOON}));
    SetAssociatedRooms(({"cocina","despensa"}));
    SetLastDest(AZ_PUERTO("portico06"));
    SetThrowOutMsg("El negro llega del oeste y dice:\nVenga, Koen, cierra ya.\nY acto seguido "
        "desaparece por el este.\nKoen sale de detr�s del mostrador y dice: Est� bien se�ores, "
        "es hora de cerrar, vayan saliendo en orden por favor.\n");
    SetNotifyExits("este");
    SetInformCloseMsg("El negro se asoma desde la cocina y grita:\n�Koen! �Ve recogiendo, que "
        "nos vamos!\n");
    SetNotifyOpenMsg("Koen aparece frot�ndose los ojos y abre la puerta del mes�n. Casi como "
        "si le hubiesen llamado, aparece el Negro, quien te saluda con un descomunal bostezo, "
        "y ambos entran en el local.\n");
    SetNotifyCloseMsg("Koen sale del mes�n alis�ndose el pelaje con las garras, cierra la "
        "puerta y se aleja calle abajo.\n");
    AddExit("este",AZ_PUERTO("portico06"));
    AddExit("oeste","cocina");
    AddDoor("este","la puerta del mes�n",
        "Es una gruesa puerta de madera, barnizada y decorada, elegante , pero resistente.\n",
        ({"puerta","puerta meson","puerta de meson","puerta del meson","puerta mes�n",
            "puerta de mes�n","puerta del mes�n"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME:({ND_NIGHT,ND_PREDAWN,ND_DAWN,ND_SUNRISE,ND_PRENOON}),
            P_DOOR_CANT_OPEN_MSG:({({"Tendr�s que esperar algo si tienes hambre, el negro se "
                "va de noche, y no volver� hasta el mediod�a.\n","Buscas una puerta en la "
                "oscuridad, pero no consigues encontrarla, cuidado al moverte, no te caigas al "
                "mar...\n"}),({"@nombre@ pensaba darse un fest�n, pero el mes�n est� cerrado...\n",
                "Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"})]));
}
