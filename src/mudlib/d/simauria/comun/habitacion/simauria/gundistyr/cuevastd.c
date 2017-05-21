/* *********************************************************************** */
/* *                                                                     * */
/* *      ARCHIVO: cuevastd.c                                            * */
/* *      AUTOR: [a] Artic                                               * */
/* *                                                                     * */
/* *********************************************************************** */

#include "./path.h"
#include <damage.h>


inherit SIM_ROOM;

int arriba, abajo, caer, vida, peso, tamanyo;
string str;

public int cmd_gritar(string str)
{
    write("Te dispones a gritar, pero de pronto piensas que eso podría atraer a gran "
        "multitud de seres con lo que desechas la idea.\n");
    say(CAP(TNAME) + " parece que se dispone a hacer algo, pero se echa atrás "
        "inquietamente.\n");
    return 1;
}

create()
{
    ::create();

    arriba = d4();
    abajo = d4();

    SetIntShort("las cuevas de Gundistyr");

    switch (arriba)
    {
        case 1:
            str = "Estás en el interior de las cuevas que se encuentran bajo la torre de "
                  "Gundistyr. El ambiente es frío debido a la profundidad que te "
                  "encuentras y a la humedad que reina en este lugar.\n";
            break;
        case 2 :
        	   str = "Te encuentras en los profundos y estrechos pasillos que conforman las "
        	         "antiguas cuevas bajo la torre de Gundistyr. Todo a tu alrededor es "
        	         "una negrura espesa en la que tan sólo se distinguen las altas paredes "
        	         "que te rodean.\n";
            break;
        case 3 :
        	   str = "Te encuentras en los oscuros pasillos que conforman las cuevas bajo "
        	         "la torre de Gundistyr. Todo a tu alrededor es frío y humedad. Las "
        	         "estrechísimas paredes te hacen sentir como si los muros se movieran y "
        	         "pudieran llegar al punto de aplastarte.\n";
            break;
        case 4:
        	   str = "Estás en uno de los numerosísimos pasillos que forman la cueva bajo "
        	         "la torre de Gundistyr. La sensación claustrofóbica que te producen "
        	         "las altas y estrechas paredes no te abandona ni por un segundo.\n";
            break;
    }

    switch (abajo)
    {
        case 1 :
            SetIntLong(str + "Sobre tu cabeza distingues un alto techo del que cuelgan "
                "algunas estalactitas que por su tamaño deben tener millones de años.\n");
            AddDetail(({"estalactitas", "estalactita"}), "Hay unas enormes estalactytas "
                "encima de tu cabeza.\n");
            AddDetail("techo", "Eres incapaz de distinguir hasta dónde llega el techo, "
                "debido a su gran altura y a la oscuridad que no te abandona.\n");
            break;
        case 2 :
            SetIntLong(str + "El suelo es altamente resbaladizo debido a la humedad que "
                "crea sobre él y produce una leve capa de agua que puede hacerte caer en "
                "cualquier instante.\n");
            AddDetail("suelo", "El suelo que pisas está totalmente mojado por la humedad "
                "de estas cuevas.\n");
            break;
        case 3:
            SetIntLong(str + "Por encima tuyo tienes un alto techo del que observas que "
                "cuelgan varias estalactitas que llegan incluso a fundirse con el suelo "
                "formando una hermosa columna.\n");
            AddDetail(({"estalactita", "estalactitas"}),"Hay unas enormes estalactitas "
                "encima de tu cabeza.\n");
            AddDetail("techo", "Eres incapaz de distinguir hasta donde llega el techo, "
                "debido a su gran altura y a la oscuridad que no te abandona.\n");
            AddDetail(({"columna", "hermosa columna"}), "Una bella columna creada de "
                "forma natural va desde el suelo hasta el techo.\n");
            break;
        case 4:
            SetIntLong(str + "Piensas que lo mejor sería que andaras con cuidado porque "
                "el suelo está muy húmedo y mojado, con lo que  caerse sería muy "
                "sencillo.\n");
            AddDetail("suelo", "El suelo que pisas está totalmente mojado por la humedad "
                "de estas cuevas.\n");
            break;
    }
    AddDetail(({"pared", "paredes"}), "A tu lado tienes unas altas paredes de caliza.\n");
    SetIntSmell("Aspiras el aire y notas un olor nauseabundo que ocupa por completo el "
        "ambiente.\n");
    SetIntNoise("Escuchas un leve goteo en alguna parte. Cuando te acercas a las paredes "
        "te parece escuchar un sonido extraño, como un murmullo de agua en "
        "movimiento.\n");

    AddRoomCmd("gritar", "cmd_gritar");

    SetIndoors(1);
    SetIntBright(0);
}

public void init()
{
    ::init();

    if (TP->QueryDex() < 20)
        caer = random(6);
    else
        caer = random(16);
    if (caer == 0)
    {
        write("No tienes suficiente cuidado al andar y torpemente resbalas debido al "
            "mojado suelo.\n");
        tamanyo = TP->QuerySize();
        peso = (TP->QueryWeight())/50000;
        vida = 2 + tamanyo + peso;
        TP->Defend(vida, DT_BLUDGEON);
    }
}
