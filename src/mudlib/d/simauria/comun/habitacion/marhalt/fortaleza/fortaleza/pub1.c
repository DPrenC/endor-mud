/*=============================================================*
 |            << Simauria:fortaleza. [m] Maler >>              |
 *=============================================================*
 |               Creacion............. 15-07-00                |
 |               Ultima Modificacion.. 15-07-00                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit PUB;

create()
{
    ::create();
    SetIntShort("la taberna de la banda");
    SetIntLong(
        "Est�s en la taberna de la fortaleza. Antiguo lugar de reposo de la tropa, ahora "
        "no es m�s que un local de mala muerte regentado por un bandido. Hay una barra "
        "mugrienta, sobre la que reposa una nota en la que puedes leer el men� del d�a. "
        "El hecho de que todo el mundo te est� mirando no parece una buena se�al en este "
        "lugar, te est�s empezando a replantear seriamente tu situaci�n.\n");
    SetIntBright(30);
    SetIntNoise("Todos hablan muy bajito como si quisieran que nadie les oyera.\n");
    SetIntSmell("Es el t�pico olor de taberna asquerosa.\n");
    AddDetail(({"taberna","pub","garito","habitacion","habitaci�n"}),
        "Es un sitio bastante simple, apenas cuatro paredes y unas cuantas mesas y"
        " sillas conforman toda la decoraci�n y los muebles del local.\n");
    AddDetail(({"paredes","pared"}),
        "Son simples paredes de piedra sin ning�n ornamento colgado.\n");
    AddDrink("cerveza negra","una",4,5,6,0,"Te bebes una cerveza bien fresquita.");
    AddDrink("orujo","un vaso de",2,10,3,0,
        "Notas como el fuego se abre paso hacia tu interior.\n");
    AddDrink("agua","un vaso de",3,0,10,0,
        "Te bebes un vaso de agua refrescante.\n");
    AddDrink("leche","un vaso de",8,0,5,0,
        "Te bebes el vaso de leche entre las miradas at�nitas de la gente.\n");
    AddDrink("whisky","un vaso de",1,7,2,0);

    AddExit("fuera",ROOMFF("patio06"));
    AddDoor("fuera", "la puerta de salida",
    "Es la puerta de salida que da al patio de la fortaleza.\n",
    ({"puerta", "puerta de salida", "puerta de fuera"}));
    SetKeeper(PNJFF("tabernero_cored"));
    AddItem(PNJFF("mercenar"),REFRESH_DESTRUCT);
    AddItem(PNJFF("soldado"),REFRESH_DESTRUCT,2);
    SetLocate("Cored");
}
