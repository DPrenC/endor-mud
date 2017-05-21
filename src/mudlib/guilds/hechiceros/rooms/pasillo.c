
#include <properties.h>
#include <moving.h>
// he quitado el mud.h... NO UTILICES ESO NUNCA, es un peazo tocho de fichero, y
// es demasiado para s�lo querer la def. de TP. Este �ltimo lo he
// definido en el path.h de tu dir. ra�z

#include <guild.h>
#include "./path.h"

inherit ROOM;

create() {
::create();
SetLocate("Gremio de hechiceros");
SetIntShort("un pasillo"); // mejor "un pasillo" que "EL pasillo", al fin y al cabo s�lo
			   // es un pasillo, no tiene nada de especial

// Aqu� b�sicamente he cambiado ciertas comas por puntos, ya que la frase tras la
// coma no tiene mucho que ver con la anterior. Para cuando pongas una coma, aseg�rate
// de que pones un espacio detr�s (no pongas "hola pepe,hola juan", si no "hola pepe, hola juan")
// Otra regla es: intenta usar palabras en vez de n�meros. Queda mejor.
// He cambiado la �ltima frase antes de lo de las salidas, porque no me parec�a correcto
// que a un mago se le distorsione la vista... Te he puesto algo que podr�a quedar bien.
// Si quieres cambiarlo, cambialo, pero no te metas mucho en la percepci�n del jugador.
// Por lo dem�s, la cosa va de cojones. Sit�as al personaje y le das una peque�a descripci�n
// de su entorno, que por no ser m�s que un pasillo corriente, no ha de ser muy grande.
SetIntLong(W("Est�s en el pasillo que comunica el hall de entrada con el resto del "
"primer piso y con las escaleras que suben al segundo. La iluminaci�n corre a cargo "
"de unas esferas flotantes que est�n junto al techo cada cinco pasos. Sientes la "
"presencia de la magia a tu alrededor.En la pared puedes ver un cartel.\n"));
// Esto �ltimo intenta evitarlo, a no ser que seas capaz de saber qu� hay m�s all� de
// donde est�s porque lo ves (o lo pone escrito). Adem�s, ten en cuenta que despues de esto
// viene la descripci�n autom�tica de las salidas y podr�a quedar un poco redundante.
// Yo te aconsejo que pongas placas informativas al lado de las puertas o escaleras.
// De esta forma, no se carga demasiado la descripci�n, y el personaje s�lo sabe qu�
// hay en la otra habitaci�n si ha estado antes o si ha le�do la placa (o cartel), y no
// por arte de magia ;)
SetIndoors(1);
SetIntBright(60);
SetIntNoise(W("Escuchas unos susurros que hacen que se te erize la piel, m�s vale "
"que sepas lo que est�s haciendo.\n"));
SetIntSmell("No puedes oler nada tu olfato te falla y solo sientes un cosquilleo en la nariz.\n");
// No hace falta que pongas olor y ruido en cada hab. que hagas. Queda bien, pero la mayor�a
// de la gente no va por ah� olisqueando todo. A�n as�, si hay un sitio en el que ponerlo,
// este es el id�neo, solo que el olor lo cambiar�a a algo como "Distingues el especiado olor
// de ciertos elementos dedicados a formular hechizos."... algo que haga alusi�n al lugar
// donde estamos. Sobre el sonido, ten en cuenta que quien est� aqu� ya es hechicero,
// no deber�a acojonarse con lo que oye. Yo m�s bien pondr�a algo as� "El pasillo est� envuelto
// en un silencio mortecino. S�lo algunos susurros apagados interrumpen este silencio."
AddDetail(({"cartel"}),W("Es un peque�o cartel dorado, podrias leerlo, asi podiras saber lo que pone.\n"));
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
    write(W("Conforme entras al pasillo, sientes una extra�a sensaci�n. Examinas tu entorno "
         "y te das cuenta de que es muy parecido al hall en el que estabas. Algo te dice que "
         "vuelves a estar en el mismo sitio.\n"));
    return ME_NO_ENTER;
  }
  return ::allow_enter(metodo,extras);
}
