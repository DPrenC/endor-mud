/*
DESCRIPCION : cocina de la fonda/posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/cocina.c
MODIFICACION: 16-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include "./posada.h"
#include RAIZ "sys/macros.h"
inherit ROOM;

/*
int matar_cmd(string str)
{
 if (!str) return 0;
 if (str!=COCINERO && str!=lower_case(COCINERO) && str!="cocinera" && str!="orco") return 0;
 else{
   write("Miras a Kabia un momento y te das cuenta de que acabar con esta orca grande y "
         "fornida armada con un gran machete de cocina no debe ser nada facil. Mejor no "
         "intentarlo y acabar siendo la proxima carne ensartada en el asador...\n");
   return 1;
   }
}*/


/*
int abrir_cmd(string str)
{
 if (!str) return 0;
 if (str!="armario" && str!="despensa") return 0;
 else{
   write("Cuando te acercas al armario con intencion de abrirlo, oyes que Kabia te grita "
         "desde la otra parte de la cocina: '¡Tu, manten las manos quietas si quieres "
         "conservarlas!' al tiempo que agita furiosamente el gran machete de cocina que "
         "tiene en las manos. Decides no tentar a la suerte esta vez.\n");
   say(capitalize(NOMBRE)
       +" se acerca al armario con intencion de abrirlo y Kabia le grita: '¡Tu, "
        "manten las manos quietas si quieres conservarlas!'. "
       +capitalize(NOMBRE)+" se aparta del armario.\n");
   return 1;
   }
}*/


create() {
  ::create();
  SetIntShort("la cocina de la "+TIPO);
  SetIntLong(
    "Ante ti se halla la cocina de la "+TIPO+" "+POS_NOM+". Es una amplia "
    "estancia en la que "+COCINERO+", la esposa de "+POSADERO+", cocina toda la comida "
    "que se sirve en esta "+TIPO+". En el centro de la habitacion esta una gran cocina "
    "con varios fuegos sobre los que reposan otros tantas humeantes ollas y en un "
    "extremo, un gran asador de carne. En una tabla sujeta del techo cuelgan todo "
    "tipo de cacharros de cocina. Al este de aqui se halla la despensa.\n");

  AddDetail(({"cocina","fuego","fuegos","caldera","tapadera"}),
    "En el centro de la estancia se halla la gran cocina, una especie de mesa hecha "
    "de metal. En su parte inferior hay una caldera en la que continuamente se quema "
    "carbon, cuyo fuego se usa para cocinar. En su parte superior hay varios agujeros "
    "circulares con su tapadera correspondiente, de tal forma que para cocinar solo "
    "hay que destapar alguno y colocar una olla encima.\n");

  AddDetail(({"ollas","olla"}),
    "Sobre los fuegos de la cocina hay varias ollas humeantes en las que "+COCINERO+" "
    "prepara las nuevas raciones de comida para los clientes de la "+TIPO+". El olor "
    "que desprenden es tentador.\n");

  AddDetail(({"asador","asador de carne","cordero"}),
    "En un extremo de la cocina se halla un gran inmenso asador de carne. Se trata "
    "de una barra horizontal de metal con varios enganches donde empalar los animales "
    "a asar. Bajo ella unas brasas se encargan de calentar la carne. En este momento "
    "hay un cordero en el asador al que "+COCINERO+" da media vuelta cada cierto tiempo "
    "para que se haga por todos lados.\n");

  AddDetail(({"despensa"}),
    "La habitacion que queda al este hace las veces de despensa de la "+TIPO+".\n");

  AddDetail(({"tabla","cacharros"}),
    "Del techo de la cocina cuelga un gran rectangulo de madera. En el se hallan "
    "clavados una larga hilera de clavos y enganches desde los que cuelgan todo tipo "
    "de cacharros, cucharones, jarras, potes, cuchillos, y mucho otros utensilios que "
    "Kabia usa para hacer las comidas. Al estar colgados asi, es mucho mas comodo "
    "para Kabia coger cualquiera de ellos cualdo lo necesita que si estuviese en "
    "algun cajon del gran armario.\n");

  SetIntNoise("Las brasas del fuego crepitan ruidosamente.\n");
  SetIntSmell("El aire es calido y el olor de los calderos tentador...\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  //AddRoomCmd ("abrir", SF(abrir_cmd));
  //AddRoomCmd ("matar", SF(matar_cmd));
  //AddItem(PNJ("z_ciudad/kabia"),REFRESH_DESTRUCT,1);

  AddExit("norte",Z_POSADA("comedor01"));
  AddExit("este",Z_POSADA("despensa"));
}