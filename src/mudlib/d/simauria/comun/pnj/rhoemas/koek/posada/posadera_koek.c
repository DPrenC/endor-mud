/****************************************************************************
Fichero: posadera_koek.c
Autor: Ratwor
Fecha: 18/08/2006
Descripción: una tarbernera, mujer del posadero de la posada de koek, para que atienda en
el comedor.
****************************************************************************/

#include "./path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO
public string f_servir();
create()
{
    ::create();

    SetStandard("Bartha", "humano", 9, GENDER_FEMALE);
    AddId(({"posadera", "tabernera", "humana", "mujer", "esposa", "bartha", "Bartha"}));
    SetShort("Bartha la posadera");
    SetLong("Bartha es la esposa de tirkas y, entre los dos, regentan la posada que tan "
    "buen servicio ofrece al pueblo y los peregrinos, y que con tanta abundancia visitan "
    "Koek.\n  Ronda la cuarentena, pero su pelo rizado y rubio la rejuvenece unos años."
    " Aunque también suele tener un comportamiento algo juvenil para su edad y, casi siempre,"
    " la puedes contemplar sirviendo las mesas canturreando canciones en voz baja.\n");
    SetSmell("Huele a las comidas que le sirve a los peregrinos.\n");
    SetNoise("VA canturreando en voz baja.\n");
    AddSubDetail("pelo", "Tiene el pelo ruvio clarito y rizado.\n");
    InitAChats(10, ({"Bartha Grita: ¡Tirkas, socorro, Socorro!.\n",
        "Bartha grita: ¡ayuda ayudadme!.\n",
             "Bartha dice: yo no te he hecho nada, ¿por qué me haces esto?.\n"}));
    InitChats(3, ({SF(f_servir)}));
    AddQuestion("posada", "Bartha te dice: mi marido y yo llevamos este negocio hace "
            "muchos años y cada vez nos va mejor debido al crecimiento del pueblo.\n", 1);
    AddQuestion(({"comida", "bebida", "comidas","bebidas", "menu", "menú"}),
        "La posadera te dice: mejor lee el menú y te  quedará más claro.\n", 1);
    AddQuestion(({"koek", "pueblo"}), "Bartha te dice: a mi me gusta mucho Koek, y cada "
        "vez se hace más grande, que es lo que a mi me interesa por el negocio.\n", 1);
    AddQuestion(({"marido", "tirkas", "posadero"}), "Bartha te dice: mi marido sí, le "
        "quiero mucho, aunque la verdad es que siempre me tiene aquí metida trabajando.\n", 1);
}

public string f_servir()
{
    //los arrays para cuando  hay peregrinos y para cuando no los hay.
    string *con_peregrinos =
    ({"La posadera le lleva una jarra de cerveza a un peregrino.\n",
        "La posadera grita: ¿para quién era el pollo asado?.\n",
        "A la posadera se le cae una copa de vino al suelo.\n",
        "La posadera le sirve un plato de pollo asado a un peregrino.\n",
        "La posadera mira, con cara rara, como come un peregrino.\n",
        "La posadera recoge los platos de una mesa vacía.\n",
        "Bartha se pone bien el delantal mientras mira la calle por la ventana.\n"});
    string *sin_peregrinos =
        ({"La posadera le pasa el trapo a una mesa.\n",
        "Bartha se arregla el pelo.\n",
        "La posadera prepara una mesa.\n",
        "Bartha te mira.\n",        "La posadera recoge los platos de una mesa.\n"});

//comenzamos el bukle for para comprovar si hay peregrinos vivos en el comedor.
    int vivos, i;
    object *inv = all_inventory(environment(TP));
    for (i=0;i<sizeof(inv);i++)
    {
        if (living(inv[i]) && inv[i]->id("peregrino"))
        vivos++;
    }
    if (vivos>1)
    {
        return con_peregrinos[random(sizeof(con_peregrinos))];
    } else {
        return sin_peregrinos[random(sizeof(sin_peregrinos))];
    }
}


