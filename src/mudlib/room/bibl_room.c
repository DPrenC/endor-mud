/*****************************************************************************

 ARCHIVO:	biblioteca.c

 AUTOR:		[n] Nemesis (nemesis@simauria.upv.es)

 FECHA:		Febrero 1999
 COMENTARIO:	Biblioteca Standard.


 MODIFICACIONES:  21-02-99 [n] Totalmente terminada.
                  25-02-99 [n] Quiza no... Interceptada la funcion QueryLong
                               para que no haga falta meter lo del cartel en
                               cada sala... Eso demuestra que se pueden
                               aprender cosas aún
   		  23-07-99 [t] Toqueteo un poco para que el cartel lo puedas
   		               leer y mirar.
   		  24-07-99 [t] Sigo toqueteando para poder añadir un 'suceso'
   		  	       a un libro... es decir, el libro puede ser un
   		  	       archivo o una closure.
   		  27-02-03 [n] Arreglado un poco el RemoveBook. Ahora asigna
   		  	       el mapping modificado. ¿Qué pasa? Un fallito
   		  	       lo tiene cualquiera...
   		  27-02-03 [z] Cambio la forma de almacenar los libros y pongo
   		  	       que algunos se puedan pillar para quests. La
   		  	       forma será AddBook(id,titulo,archivo,pillable).
   		  	       Por defecto pillable es 0 (si no se pone nada),
   		  	       1 si lo quieres que se pueda sacar. Se suprimen
   		  	       los índices. El Path se pasa de la biblioteca
   		  	       al 2º argumento de AddBook, archivo para más
   		  	       señas, así se pueden meter libros de diferentes
   		  	       directorios por si se quiere repetir alguno
   		  	       de otra biblioteca de otra parte. Por defecto
   		  	       el tema es "varios" para que no salga un 0 en
   		  	       el cartel.

 		 28-03-03 [z]  Añado una linea de comprobación para que si
 		 	       un player escribe solo "leer" no pete.
 *****************************************************************************/

#include <properties.h>
#include <files.h>
#include <moving.h>

#define BOOK_NOMBRE 	0
#define BOOK_ARCHIVO 	1
#define BOOK_PILLABLE 	2

inherit ROOM;

private nosave mapping books;
private string tema;

public mapping QueryBooks() 		{ return books; }
public string SetTema(string str) 	{ return tema=str; }
public string QueryTema() 		{ return tema; }
public int QueryNumberBooks()		{ return sizeof(books); }

Iniciar() {
	books=([]);
}

public varargs AddBook(string id, string nombre, mixed archivo, int pillable) {
	if (stringp(id)) books+=([lower_case(id):nombre;archivo;pillable]);
	else books+=([id:nombre;archivo;pillable]);
}

public RemoveBook(string id) {
	books-=([id]);
}

public string QueryIntLong() {
	return ::QueryIntLong()+"Ves un cartel en la pared.\n";
}

public string fcartel() {
	return "Esta es la sala dedicada a: "+QueryTema()+"\n"+
	"Para ver los libros disponibles pon: 'libros'\n"+
	"Se ruega mantener silencio.\n";
}

public int flibros() {
	int cantidad;
	string *indice,aux;

	if (!QueryNumberBooks()) {
		write("La sala está vacía. No hay ningún libro.\n");
		return 1;
 	}
	aux = "\n             LISTA DE LIBROS DISPONIBLES EN ESTA SALA:\n";
	aux += "====================================================================\n";
	aux += "|     Referencia     |            Título                           |\n";
	aux += "====================================================================\n";
	indice=m_indices(QueryBooks());
	cantidad=sizeof(indice);
	for(int i=0; i<cantidad;i++) {
		if (books[indice[i],BOOK_PILLABLE]) aux+=" * ";
		else aux += "   ";
		aux += sprintf("%-19s %s\n", capitalize(indice[i]), books[indice[i], BOOK_NOMBRE]);
	}
	aux += "\n  Para leer un libro, escribe: 'leer <referencia>'.\n";
	aux += "  Para coger un libro, escribe: 'coger <referencia>'.\n";
	aux += "  Son prestables los libros marcados con '*'.\n";
	write(aux);
	return 1;
}

public int fleer(string referencia) {
	mixed archivo;

	if (referencia=="cartel") return 0;
	if (referencia) referencia=lower_case(referencia);
	if (!referencia || !QueryNumberBooks() || !member(QueryBooks(),referencia)) return 0;
	else {
		archivo=QueryBooks()[referencia,BOOK_ARCHIVO];
		if (stringp(archivo)) {
			if (file_size(archivo)==FSIZE_NOFILE || file_size(archivo)==FSIZE_DIR) {
				write("¡LIBRO INEXISTENTE! (INFORMA A UN WIZARD SOBRE ESTO)\n");
				log_file("/BIBLIOTECAS/libros",sprintf("Archivo inexistente en: %O\nArchivo: %s\n",TO,to_string(archivo)));
				return 1;
			}
			STR->smore(read_file(archivo));
			return 1;
		}
		else if (closurep(archivo)) return funcall(archivo);
		return 1;
	}
}

public int fcoger(string referencia) {
	object cogido;
	mixed archivo;

	if (!referencia) return 0;
	else if (referencia=="libro" || referencia=="libros") {
		write("Coger <referencia del libro>.\nEscribe 'libros' para más detalles.\n");
		return 1;
	}
	else {
		referencia=lower_case(referencia);
		if (!member(QueryBooks(),referencia) || !QueryBooks()[referencia,BOOK_PILLABLE]) return 0;
	    else {
            archivo=QueryBooks()[referencia,BOOK_ARCHIVO];
            write("Coges el libro "+QueryBooks()[referencia,BOOK_NOMBRE]+"\n");
            if (stringp(archivo)) {
                if (file_size(archivo)==FSIZE_NOFILE || file_size(archivo)==FSIZE_DIR) {
                    write("¡LIBRO INEXISTENTE! (INFORMA A UN WIZARD SOBRE ESTO)\n");
                    log_file("/BIBLIOTECAS/libros",sprintf("Archivo inexistente en: %O\nArchivo: %s\n",TO,to_string(archivo)));
                    return 1;
                }
            }
            else if (closurep(archivo)) return funcall(archivo);
            cogido=clone_object("/std/thing");
            cogido->SetShort("Libro: "+QueryBooks()[referencia,BOOK_NOMBRE]);
            cogido->SetLong("Es un libro grande y pesado con cubierta de cuero.\n"
            "Tiene una larga correa que lo cierra y lo hace más portable.\n");
            cogido->Set(P_NOBUY,1);
            cogido->Set(P_NOSELL,1);
            cogido->SetWeight(5000);
            cogido->SetValue(0);
            cogido->AddId("libro");
            cogido->AddId(referencia);
            cogido->AddId("libro "+referencia);
            cogido->SetReadMsg(read_file(QueryBooks()[referencia,BOOK_ARCHIVO])+"\n");
            cogido->move(TP,M_SILENT);
            RemoveBook(referencia);
            return 1;
        }
    }
}

create() {
  ::create();

  REGISTER->Register(TO, "BIBLIOTECA");
  SetTema("Varios");
  SetIntShort("Una habitación en una biblioteca");
  SetIntLong("Estás en una sala llena de libros.\n");
  SetIndoors(1);
  SetIntBright(40);
  AddReadMsg("cartel", SF(fcartel));
  AddDetail("cartel", SF(fcartel));
  AddRoomCmd("leer","fleer");
  AddRoomCmd("libros","flibros");
  AddRoomCmd("coger","fcoger");
  Iniciar();
}
