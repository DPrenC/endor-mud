/*
DESCRIPCION  : Biblioteca del edificio de suministros
FICHERO      : /d/limbo/comun/habitacion/limbo/templo/biblioteca.c
MODIFICACION : 30-09-98 [Angor@Simauria] Creacion.
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

#define LIBRO(x) "/d/limbo/docs/"+x

int leer_cmd(string str);
string leer_nota();
string catalogo();
catalogo_cmd();

create() {
  ::create();
  SetIntShort("la biblioteca");
  SetIntLong(
"Estas en la biblioteca de la que dispone el edificio de los siervos de los "
"dioses. Es una pequenya biblioteca con un conjunto de libros muy modesto si se "
"compara con otras que existen en este mundo, especialmente con la Gran "
"Biblioteca de la ciudad de Simauria, pero tiene informacion util especialmente "
"para los recien llegados a este mundo. Ves estanterias llenas de libros que "
"puedes leer y en la pared una nota con el catalogo de volumenes disponibles.\n");

AddDetail(({"estanterias","estanteria"}),
 "Las estanterias cubren las paredes de esta pequenya biblioteca. Estan hechas de "
 "olorosa madera de cedro y colocados en ellas se encuentran los libros.\n");

AddDetail(({"libros","libro"}),
 "Siendo esto una biblioteca es razonable que los haya, no? Los libros estan "
 "colocados en las estanterias. Deberias leer la nota con el catalogo para saber "
 "que libros puedes encontrar en esta biblioteca. Para leer un libro no tienes mas "
 "que usar el comando 'leer libro <numero_del_libro>'.\n");

AddDetail(({"nota","catalogo"}),leer_nota());

 SetIntNoise("El silencio preside la biblioteca.\n");
 SetIntSmell("Huele a papel anyejo.\n");
 SetLocate("isla Limbo");
 SetIndoors(1);
 SetIntBright(50);

 AddRoomCmd("leer",SF(leer_cmd));
 AddRoomCmd("catalogo",SF(catalogo_cmd));
 AddExit("norte",TEMPLO("escalera"));
 SetSafe(1);
}

string leer_nota(){
return "Catalogo de libros existente en esta biblioteca:\n"+catalogo()+
       "Para leer un libro, usa el comando 'leer libro <numero_del_libro>'.\n";
}

int catalogo_cmd(){
  write(leer_nota());
  return 1;
}

int leer_cmd(string str) {
 string libro,tmp,fich,fich2,titulo;
 int i, num;
 if ((str=="nota")||(str=="catalogo")) {write(leer_nota());return 1;}
 if ((!str) || (sscanf(str,"libro %s",libro)<1) || (str=="libro")){
    write("Usa el comando 'leer libro <numero_del_libro>' para leer los libros.\n");
    return 1;
 }

 tmp=read_file(LIBRO("catalogo.txt"), 0, 0);
 if (tmp==0) {write("(En este momento no hay libros en la biblioteca)\n");return 1;}

 i=0;
 num=0;
 tmp="";
 fich2="";
  do {
     tmp=read_file(LIBRO("catalogo.txt"), i, 1);
     if ((tmp[0]!=59)&&(tmp[0]!=0)&&(sscanf(tmp,"%s,%s",fich,titulo)==2)) {
             if ((string)num==libro) fich2=fich;
             num++;
             }
     i++;
     tmp=read_file(LIBRO("catalogo.txt"), i, 1);
     }while (tmp!=0);

  if (fich2=="") {
      write("Ese libro no existe en el catalogo.\n");
      return 1;
      }
  if (read_file(LIBRO(fich2), 0, 1)==0){
      write("El libro existe en el catalogo, pero esta en blanco.\n");
      return 1;
     }
  write(read_file(LIBRO(fich2)));
return 1;
}

string catalogo(){
  string cat,tmp,fich,titulo;
  int i,j,num,pos,fin;
  i=0;
  num=0;
  tmp="";
  //vacio?
  cat=read_file(LIBRO("catalogo.txt"), 0, 0);
  if (cat==0) return "(En este momento no hay libros en la biblioteca)\n";
  cat="";
  do {
     tmp=read_file(LIBRO("catalogo.txt"), i, 1);
     if ((tmp[0]!=59)&&(tmp[0]!=0)&&(sscanf(tmp,"%s,%s",fich,titulo)==2)) {
             cat=cat+"["+(string)num+"] ";

             //cat+=titulo+"\n";
             cat+=titulo;

             //pos=sscanf(tmp,",%s",libro);
             //fin=strlen(tmp);
             //for(j=pos;j<=fin;j++) cat=cat+tmp[j];
             //cat=cat+"["+(string)num+"] "+tmp;

             num++;
             }
     i++;
     tmp=read_file(LIBRO("catalogo.txt"), i, 1);
     }while (tmp!=0);
  if (cat=="") return "(El catalogo existe, pero esta vacio)\n";
  else return cat;
}