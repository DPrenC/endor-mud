/*
DESCRIPCION : fonda 'el Jabali Feroz'
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/tienda/fonda.c
MODIFICACION: 07-04-98 [Angor@Simauria] Creacion
              [woo] Anyadidas algunas bebidas...
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <nightday.h>
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
inherit PUB;
#define SUF             (TP->QueryGender()==GENDER_FEMALE?"a":"o")

int matar_cmd(string str)
{
    if (!present("grogor",TO)) return 0;
    if (!str) return 0;
    if (str!="Grogor" && str!="grogor" && str!="propietario" && str!="orco") return 0;
    else
    {
        write("Cuando te dispones a atacar a Grogor te lo piensas un momento. La mayor parte de "
            "sus clientes son amigos suyos y no dudarían en defenderle. Además en esta zona "
            "todo el mundo va fuertemente armado. Piensas que si le atacases posiblemente tú "
            "saldrías peor parad"+SUF+" que él...\n");
        return 1;
    }
}

create() 
{
    ::create();
    SetIntShort("la fonda El Jabalí Feroz");
    SetIntLong("Te encuentras en la fonda El Jabalí Feroz. El local es regentado por el orco "
        "Grogor, quien atiende a los clientes, y su mujer Kabia que se encarga de la cocina. "
        "Su especialidad es el jabalí asado, aunque el guiso de ternera que hace Kabia es "
        "famoso en todo el valle. La comida es sabrosa y los precios moderados.\nEl local en "
        "sí es un bajo amplio pero austero, lleno de mesas y con una gran chimenea al fondo. "
        "Una puerta de doble hoja comunica al norte con la cocina y una escalera con el piso de "
        "arriba.\n");
    AddDetail(({"cocina","puerta"}),"Al norte de esta habitación está la cocina en la que "
        "trabaja Kabia, la mujer de Grogor. Para que sea fácil entrar y salir de ella cargando "
        "con los platos de comida se ha instalado una puerta de doble hoja: para abrirla basta "
        "con empujarla y unos resortes hacen que se cierre sola.\n");
    AddDetail(({"mesas"}),"La fonda está llena de ellas. ¿Dónde si no iban a comer los "
        "clientes?\n");
    AddDetail(({"chimenea"}),"Al fondo de la habitación hay una gran chimenea en la que "
        "siempre hay un agradable fuego que mantiene la fonda a una confortable temperatura.\n");
    AddDetail(({"escalera"}),"La escalera permite subir al piso de arriba donde viven los "
        "dueños de la fonda.\n");
    SetIntNoise("Oyes a la gente comiendo.\n");
    SetIntSmell("¡Hmmmm! el olor que llega de la cocina te hace la boca agua.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(1);
    SetIntBright(50);
    SetKeeper(PNJ("z_ciudad/grogor"));
    SetCloseTime(({ND_NIGHT,ND_PREDAWN,ND_DAWN,ND_SUNRISE,ND_PRENOON}));
    SetAssociatedRooms("fonda_cocina");
    SetLastDest(Z_CIUDAD("calle_02"));
    SetNotifyExits("este");
    SetInformCloseMsg("Grogor dice: Bien, señores, el género está casi agotado, vayan "
        "terminando, por favor. Vamos a cerrar ya.\n");
    SetThrowOutMsg("Grogor sonríe y dice: Por favor, señores, cerramos ya,gracias por su "
        "visita. Espero que todo haya sido de su agrado, y espero volver a verles de nuevo en "
        "mi casa.\n");
    SetNotifyCloseMsg("Grogor saluda a todos sus clientes en la puerta, les dedica una amplia "
        "sonrisa, y vuelve a entrar, cerrando tras de sí.\n");
    SetNotifyOpenMsg("Se abre la puerta de la fonda y aparece Grogor, quien sonríe afablemente, "
        "y dice: Si tienen la bondad de entrar, serán bien atendidos. Muchas gracias.\n"
        "Acto seguido, entra en la fonda y comienza a servir a los clientes.\n");
    AddExit("este",Z_CIUDAD("calle_02"));
    AddExit("norte","fonda_cocina");
    AddDoor("este","la puerta de la fonda",
        "Es una gruesa puerta de madera bien pulida, pintada de un bonito tono azul y adornada "
            "con gruesos clavos de bronce.\n",
        ({"puerta","puerta de fonda","puerta de la fonda"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_CANT_OPEN_MSG:({"La fonda está cerrada, no es ésta hora "
            "para comer.\n","@nombre@ debe tener hambre, intentaba ir a la fonda pero se da "
            "cuenta de que está cerrada.\n","Parece que alguien intenta abrir alguna puerta.\n"}),
        P_DOOR_CLOSE_TIME : ({ND_NIGHT,ND_PREDAWN,ND_DAWN,ND_SUNRISE,ND_PRENOON})]));
    AddFood("jabalí asado","un plato de",8,9,0);
    AddFood("pollo con patatas","un plato de",8,8,0);
    AddFood("guiso de ternera","un plato de",7,7,0);
    AddDrink("vino","una jarra de",8,6,5,0);
    AddDrink("cerveza","una jarra de",5,6,5,0);
    AddItem(PNJ("z_ciudad/bardo"),REFRESH_DESTRUCT,1);
    SetSoundEnvironment(SND_AMBIENTES("chimenea"),80);
}
