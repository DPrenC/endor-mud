/*
Fichero: pajar.c
Autor: aulë
Fecha: 18/03/2013
Descripción:  pajar del establo del Poney Pisador.
*/
#include "./path.h"
#include <moving.h>
#include <xp.h>
inherit HABITACION+"bree/poney_pisador/bestablo";
int sacudida, cantidad=0;
object ratones;
create()
{
    ::create();
    sacudida=3;
    	SetIntShort("un amplio pajar");
    	SetIntLong("Esta zona de los establos se destina al almacenaje de paja y heno "
    	"para alimentar y proporcionar descanso a las monturas de los huéspedes de la "
    	"posada.\n"
    	"Grandes montones de paja  se alzan contra los muros hasta rozar las oscuras vigas "
    	"del techo y balas de heno se amontonan ordenadamente en grandes pilas.\n"
    	"El ambiente está lleno del polvillo procedente de la paja seca que amortigua y "
    	"opaca los sonidos.\n"
    	"Poco se puede ver de las paredes pues están cubiertas por el forraje, aunque en "
    	"un espacio libre cuelgan varias herramientas.\n");
    	AddDetail("herramientas",
    	"Horcas para transportar la paja hasta los pesebres y rastrillos para amontonarla.\n");
AddDetail(( {"paja", "montones de paja"}),
    "Son montones de paja limpia que cubren casi la totalidad de las paredes del pajar.\n"
    "En ocasiones es necesario sacudir la paja para auyentar a los pequeños "
    "animalillos que suelen anidar en su interior.\n");
AddRoomCmd(({"sacudir", "agitar", "golpear"}), "cmd_sacudir");
     AddExit("norte", "./establo2");
          AddExit("sur", HABITACION+"bree/callejon2");
              HideExit("sur",1);
              AddDoor("sur", "una baja puerta",
              "Es una puerta de madera gruesa, pesada, baja y ancha cerrada por un par de "
              "trancas y medio enterrada en la paja. Por el aspecto que ofrece parece "
              "que no es utilizada muy a menudo.\n",
              ({"puerta", "puerta s", "puerta del sur", "s", "sur"}));
 
   

    }

public int cmd_sacudir(string str){
    TP->SetTP(TP->QueryTP()-d3());
        if (str!="paja" && str!="montones de paja" && str!="la paja" && str!="los montones de paja") return 0;
    if(TP->QueryTP()<=1)
    return notify_fail("Te encuentras cansad"+TP->QueryGenderEndString()+", descansa un rato.\n", NOTIFY_NOT_VALID);
    if (sacudida>0){
            cantidad=1+d2(sacudida);

                    write("Sacudes fuertemente los montones de paja y de su interior aparecen "+
        itoa(cantidad)+" ratoncillos algo asustadizos.\n");
        TP->exp(cantidad*10);
                    TP->SetExplored();
        say(capitalize(TNAME)+" sacude los montones de paja y ves como "+itoa(cantidad)+
        " ratoncillos salen espantados.\n");
        for (int i = 0;i<cantidad;i++) {
      ratones=clone_object(ANIMALES("ratones"));
      ratones->move(TO,M_SILENT);
            }
sacudida--;
        return 1;
    }else{
        write("Sacudes fuertemente los montones de paja, consigues desahogarte un poco.\n");
        say(capitalize(TNAME)+" sacude los montones de paja con ansiedad, parece relajarle.\n");
        return 1;
    }
}


