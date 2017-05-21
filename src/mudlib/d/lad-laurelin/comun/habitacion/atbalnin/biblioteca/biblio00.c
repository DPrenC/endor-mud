#include "./path.h"


inherit "/room/bibl_room";


prestado()
{
  write("Este libro no est� disponible en estos momentos.\n"
  	"Rogamos disculpen las molestias.\n");
  return 1;
}

create () {
    ::create();
    SetIntShort("la biblioteca de Atbalnin");
    SetIntLong("Silencio, el silencio es lo que parecen rezumar todas las bibliotecas que\n"+
  	"puedes recordar. Esta debe ser la excepci�n. Es una biblioteca porque tiene la\n"+
  	"cantidad de personas adecuadas para que lo sea (que suele ser inversamente\n"+
  	"proporcional a la cantidad de gente que pulula por los bares del lugar),\n"+
  	"tiene la obligada capa de polvo que cubre todos los vol�menes (haciendo un\n"+
  	"tremendo esfuerzo mental que esperas que no te pase factura recuerdas que es\n"+
  	"una directiva del gremio de libreros la que obliga a limpiarla por la noche y\n"+
  	"volverla a depositarla por la ma�ana). Adem�s est� la sempiterna bibliotecaria\n"+
  	"de cara inescrutable, que conforma parte del mobiliario. Sin embargo no hay\n"+
  	"silencio, el edificio parece que desee ocupar otra parte de la ciudad, como por\n"+
  	"ejemplo sus propios cimientos. Es increible lo mucho que puede crujir la\n"+
  	"madera a�eja. Piensas que quiz�s la habitaci�n est� intentando leer sus\n"+
  	"propios vol�menes.\n");
    SetTema("Leyendas");
    AddDetail("bibliotecaria", "Es... una bibliotecaria est�ndar. Pensada para camuflarse con el entorno.\n");
    AddBook("Wyvelt","El diario de los Wyvelt",PATH_BOOK+"wyvelt");
    AddBook("Caballero","Relato del Caballero An�nimo", SF(prestado));
    AddBook("Dama","La Dama del Lago", SF(prestado));
    AddBook("Guerra","La Gran Guerra", PATH_BOOK+"davagis");
    AddBook("Antiguo","Libro antiguo",SF(prestado));
    AddExit("salir", ATB_CI("ciudad28"));
}
