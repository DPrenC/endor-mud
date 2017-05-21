
#include <properties.h>
#include <moving.h>
// he quitado el mud.h... NO UTILICES ESO NUNCA, es un peazo tocho de fichero, y
// es demasiado para sólo querer la def. de TP. Este último lo he
// definido en el path.h de tu dir. raíz

#include <guild.h>
#include "./path.h"

inherit ROOM;

create() {
::create();
SetLocate("Gremio de hechiceros");
SetIntShort("un pasillo"); // mejor "un pasillo" que "EL pasillo", al fin y al cabo sólo
			   // es un pasillo, no tiene nada de especial

// Aquí básicamente he cambiado ciertas comas por puntos, ya que la frase tras la
// coma no tiene mucho que ver con la anterior. Para cuando pongas una coma, asegúrate
// de que pones un espacio detrás (no pongas "hola pepe,hola juan", si no "hola pepe, hola juan")
// Otra regla es: intenta usar palabras en vez de números. Queda mejor.
// He cambiado la última frase antes de lo de las salidas, porque no me parecía correcto
// que a un mago se le distorsione la vista... Te he puesto algo que podría quedar bien.
// Si quieres cambiarlo, cambialo, pero no te metas mucho en la percepción del jugador.
// Por lo demás, la cosa va de cojones. Sitúas al personaje y le das una pequeña descripción
// de su entorno, que por no ser más que un pasillo corriente, no ha de ser muy grande.
SetIntLong(W("Estás en el pasillo que comunica el hall de entrada con el resto del "
"primer piso y con las escaleras que suben al segundo. La iluminación corre a cargo "
"de unas esferas flotantes que están junto al techo cada cinco pasos. Sientes la "
"presencia de la magia a tu alrededor.En la pared puedes ver un cartel.\n"));
// Esto último intenta evitarlo, a no ser que seas capaz de saber qué hay más allá de
// donde estás porque lo ves (o lo pone escrito). Además, ten en cuenta que despues de esto
// viene la descripción automática de las salidas y podría quedar un poco redundante.
// Yo te aconsejo que pongas placas informativas al lado de las puertas o escaleras.
// De esta forma, no se carga demasiado la descripción, y el personaje sólo sabe qué
// hay en la otra habitación si ha estado antes o si ha leído la placa (o cartel), y no
// por arte de magia ;)
SetIndoors(1);
SetIntBright(60);
SetIntNoise(W("Escuchas unos susurros que hacen que se te erize la piel, más vale "
"que sepas lo que estás haciendo.\n"));
SetIntSmell("No puedes oler nada tu olfato te falla y solo sientes un cosquilleo en la nariz.\n");
// No hace falta que pongas olor y ruido en cada hab. que hagas. Queda bien, pero la mayoría
// de la gente no va por ahí olisqueando todo. Aún así, si hay un sitio en el que ponerlo,
// este es el idóneo, solo que el olor lo cambiaría a algo como "Distingues el especiado olor
// de ciertos elementos dedicados a formular hechizos."... algo que haga alusión al lugar
// donde estamos. Sobre el sonido, ten en cuenta que quien está aquí ya es hechicero,
// no debería acojonarse con lo que oye. Yo más bien pondría algo así "El pasillo está envuelto
// en un silencio mortecino. Sólo algunos susurros apagados interrumpen este silencio."
AddDetail(({"cartel"}),W("Es un pequeño cartel dorado, podrias leerlo, asi podiras saber lo que pone.\n"));
AddReadMsg(({"cartel"}),W(
"El cartel pone:\n"
"La habitacion de entrenamiento se encuentra al norte, al este el hall del gremio de los hechiceros"
" y al nordeste estan las escaleras que suben al segundo piso.\n"
));
AddExit("norte","./entrena");
AddExit("este","hall");
AddExit("nordeste","./esca0");
}

allow_enter(int metodo,mixed extras)
{
  if( TP->QueryGuild()!=GC_HECHICEROS )
  {
    write(W("Conforme entras al pasillo, sientes una extraña sensación. Examinas tu entorno "
         "y te das cuenta de que es muy parecido al hall en el que estabas. Algo te dice que "
         "vuelves a estar en el mismo sitio.\n"));
    return ME_NO_ENTER;
  }
  return ::allow_enter(metodo,extras);
}
