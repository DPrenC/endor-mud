/*
Fichero: c1_patio.c
Fecha: 12/10/2014
Autor: aulë
Descripción: patio de la casa entre los edificios.
*/
#include "./path.h"
inherit BREE_ROOM;
#include <sounds.h>
int contiene_cubo;
public int cmd_llenar(string str){
    if(str!="cubo" || !str)
        return notify_fail("Llenar el qué?\n");
    if(contiene_cubo>=20)
        return notify_fail("El cubo ya está lleno.\n");
    write("Haces girar el tosco torno mientras el cubo desciende hasta el fondo del pozo.\n"
    "Después, con gran trabajo haces girar el torno en sentido inverso y el cubo aparece,"
    " balanceándose, repleto de agua.\n");
    say(CAP(TNAME)+" opera el torno dejando que el cubo descienda por el pozo.\n"
    "Acto seguido y con visibles muestras de esfuerzo gira el torno en sentido contrario "
    "y el cubo asciende lentamente, lleno de agua.\n");
    contiene_cubo=25+d10(2);
    TP->AddTP(d3());
    return 1;
}

public int cmd_vaciar(string str){
    if(!str || str!="cubo")
        return notify_fail("¿Vaciar el qué?\n");
    if(!contiene_cubo)
        return notify_fail("El cubo ya está vacío.\n");
    write("Sujetas el cubo por un borde y lo levantas del lado contrario vaciando toda "
    "el agua, que se derrama cual sonora cascada dentro del pozo.\n");
    say(CAP(TNAME)+" agarra el cubo y lo vuelca, dejando caer el agua dentro del pozo.\n");
    contiene_cubo=0;
    TP->SetExplored();
    return 1;
}

public int cmd_beber(string str){
    if(!str) return notify_fail("¿Qué quieres beber?\n");
    if(str=="agua" || str=="agua del cubo" || str=="agua de cubo")
    {
        if(contiene_cubo>0)
        {
            if(TP->QueryDrink()<TP->QueryMaxDrink())
            {
                write("Te agachas e inclinas sobre el cubo, sorbiendo agua ruidosamente "
                "directamente de su interior.\n");
                say(CAP(TNAME)+" se agacha junto al pozo y se inclina sobre el cubo, sorbiendo agua ruidosamente de su interior.\n");
                play_sound(TO, SND_SUCESOS("beber"));
                TP->AddDrink(d6());
                if(TP->QueryHP()<TP->QueryMaxHP()) TP->AddHP(d2());
                contiene_cubo--;
                return 1;
            }
            return notify_fail("Ahora mismo no tienes sed.\n", NOTIFY_NOT_VALID);
        }
        return notify_fail("El cubo está vacío.\n");
    }else{
        if(str=="agua de pozo" || str=="agua del pozo"){
            say(CAP(TNAME)+" mete la cabeza dentro del pozo con la intención de beber agua, "
            "pero tras meter medio cuerpo se da cuenta que no consigue llegar al agua "
            "y desiste de su empeño.\n");
            write("Metes la cabeza dentro del pozo, pero te das cuenta que "
            "el agua queda demasiado abajo.\n");
            return 1;
        }
        return notify_fail("El pozo contiene agua.\n");
    }
}


public string f_cubo(){
    string agua;
    if(contiene_cubo>=30)
        agua="Contiene mucha agua en su interior.\n";
    if(contiene_cubo<30 && contiene_cubo>10)
        agua="Contiene agua en su interior.\n";
    if(contiene_cubo<=10 && contiene_cubo>0)
        agua="Contiene muy poca agua en su interior.\n";
    if(!contiene_cubo)
        agua="Está vacío.\n";
    return "Es un cubo de gruesos listones y fondo de cobre con asa para engancharlo.\n"+agua;
}



create()
{
    ::create();
    	SetIntShort("un patio");
    	SetIntLong(
    	"Estás en un patio cuadrado entre la casa al norte, el establo al este y un "
    	"pequeño cobertizo al sur. Al oeste se accede a un huerto. Un poco localizado en "
    	"medio del patio suministra agua a la casa y un enorme trozo compacto de raíz "
    	"hace las veces de tajo para partir leña, de la que hay una buena pila justo al "
    	"lado. El suelo es de tierra batida cubierta a medias de césped y gravilla "
    	"procedente de la construcción de la casa entre la que algunas aves suelen "
    	"rebuscar y picotear.\n");
    	AddDetail(({"raiz", "raíz", "tajo"}),
    	"Es un enorme raigón seco que ha sido limpiado y tallado toscamente a hachazos "
    	"para presentar una superficie más o menos plana y algo inclinada para cortar "
    	"leña o descabezar un pollo si es necesario.\n");
    	AddDetail("casa",
    	"Al norte se levanta una pequeña vivienda de dos plantas, paredes de piedra "
    	"tosca y tejado de tejas a dos aguas.\n");
    	AddDetail("establo",
    	"Un edificio de piedra basta y techado con tejas planas.\n");
    	AddDetail("cobertizo",
    	"Un pequeño cobertizo cuadrado techado de paja que se levanta al sur de aquí.\n");
    	AddDetail("huerto",
    	"Al oeste ves un huerto primorosamente plantado al que podrías ir desde aquí.\n");
    	AddDetail("pozo",
    	"Un pozo redondo en medio del patio con un bropcal de grandes piedras y un torno con un cubo para recoger agua.\n");
    	AddDetail("torno",
    	"Sobre un soporte de madera hay una sección cilíndrica con otras dos secciones más "
    	"anchas cerrando los extremos y cuatro manijas que forman una cruz.\n"
    	"Haciéndolas girar se suelta o recoge cuerda para bajar o subir el cubo del pozo.\n");
AddExit("este", "./c1_establo3");
AddExit("oeste", "./c1_huerto2");    	
    	AddExit("norte", "./c1_piso1");
    	AddExit("sur", "./c1_cobertizo");
    	
    	AddDoor("norte", "La puerta de la casa",
    	"Es una simple puerta de madera sin manilla ni picaporte. Algunas marcas "
    	"desiguales cubren su superficie.\n",
    	({"puerta", "n", "norte", "puerta n", "puerta norte", "casa", "puerta de la casa", "puerta"}));
    	AddDoor("este", "un portón de madera",
    	"Es un ancho portón de madera oscurecida por la intemperie y el tiempo, claveteada "
    	"con grandes clavos de bronce y con una viga inferior que sustenta el conjunto y "
    	"sobre la que hay que pasar para entrar. Tiene doble batiente para permitir el "
    	"paso del ganado o de un carro cargado.\n",
    	({"porton", "portón", "e", "este", "portón de madera", "porton de madera"}));
    	AddDoor("sur", "la puerta del cobertizo",
    	"Es una puerta algo baja, de tablones de madera verticales con otros dos más "
    	"largos cruzados en X para dar solidez al conjunto.\n"
    	"Tiene una cerradura para asegurarla.\n",
    	({"puerta", "sur", "s", "puerta s", "puerta sur", "puerta del cobertizo"}));
    	    AddRoomCmd("llenar", "cmd_llenar");
    AddRoomCmd(({"vaciar", "volcar"}), "cmd_vaciar");
    AddRoomCmd("beber", "cmd_beber");
}


