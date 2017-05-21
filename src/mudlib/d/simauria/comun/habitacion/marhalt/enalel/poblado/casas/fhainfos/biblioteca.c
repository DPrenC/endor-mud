/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Poblado Enanel
 *****************************************************************************/

#include "path.h"
#include <sounds.h>
#include <door.h>
#define eLIBRO(x) ENALHAB"textos/"+ x

inherit SIM_ROOM;

string catalogo();
public string LeerCatalogo();
int leer_cmd(string str);

create() {
    ::create();

    SetIntBright(50);
    SetLocate("Casa Fhainfos");
    SetIntShort("la biblioteca");
    SetIntLong("Estás en la biblioteca de la familia Fhainfos. Las estanterías "
    "ocupan todas las paredes de la sala. Al oeste está la salita de estar.\n");
    SetIntSmell("Un leve aroma a manzanas se percibe por todas partes.\n");
    AddDetail(({"estanteria","estanterias","estante","estantes"}),"Son altas "
  "estanterías repletas de libros.\nEn uno de los extremos hay un catálogo que "
    "puedes mirar.\n");
    AddDetail(({"libros","libro"}),"Son libros de los más diversos temas. Puedes "
    "leer el catálogo para ver cuales puedes leer.\n");
    AddDetail(({"catalogo","catálogo"}),SF(LeerCatalogo));
    AddExit("oeste",ENALHAB"poblado/casas/fhainfos/sala_estar");
    AddDoor("oeste", "la puerta de la sala de estar.\n",
    "Una puerta de madera para pasar a la otra estancia.\n",
    ({"puerta", "puerta del oeste"}));
    AddExit("arriba", ENALHAB"poblado/casas/fhainfos/trastero");
    AddDoor("arriba", "una trampilla",
    "Una trampilla para acceder a la estancia de arriba.\n",
    ({"trampilla", "arriba"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_pequena"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_puerta_pequena")]));
    AddRoomCmd("leer",SF(leer_cmd));
}

public string LeerCatalogo(){
  return "En el catálogo hay los siguientes libros:\n\n" + catalogo() + "\n escribe "
  "leer y el número de libro que quieras leer.\n";
}

string catalogo(){
  string cat,tmp,fich,titulo;
  int i,j,num,pos,fin;
  i=0;
  num=0;
  tmp="";
  //vacio?
  cat=read_file(eLIBRO("catalogo_fhainfos.txt"), 0, 0);
  if (cat==0) return "(En este momento no hay libros en la biblioteca)\n";
  cat="";
  do {
     tmp=read_file(eLIBRO("catalogo_fhainfos.txt"), i, 1);
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
     tmp=read_file(eLIBRO("catalogo_fhainfos.txt"), i, 1);
     }while (tmp!=0);
  if (cat=="") return "(El catalogo existe, pero esta vacio)\n";
  else return cat;
}


int leer_cmd(string str) {
 string libro,tmp,fich,fich2,titulo;
 int i, num;
 if ((str=="catálogo")||(str=="catalogo")) {write(LeerCatalogo());return 1;}
 if ((!str) || (sscanf(str,"libro %s",libro)<1) || (str=="libro")){
    write("Usa el comando 'leer libro <numero_del_libro>' para leer los libros.\n");
    return 1;
 }

 tmp=read_file(eLIBRO("catalogo_fhainfos.txt"), 0, 0);
 if (tmp==0) {write("(En este momento no hay libros en la biblioteca)\n");return 1;}

 i=0;
 num=0;
 tmp="";
 fich2="";
  do {
     tmp=read_file(eLIBRO("catalogo_fhainfos.txt"), i, 1);
     if ((tmp[0]!=59)&&(tmp[0]!=0)&&(sscanf(tmp,"%s,%s",fich,titulo)==2)) {
             if ((string)num==libro) fich2=fich;
             num++;
             }
     i++;
     tmp=read_file(eLIBRO("catalogo_fhainfos.txt"), i, 1);
     }while (tmp!=0);

  if (fich2=="") {
      write("Ese libro no existe en el catalogo.\n");
      return 1;
      }
  if (read_file(eLIBRO(fich2), 0, 1)==0){
      write("El libro existe en el catalogo, pero esta en blanco.\n");
      return 1;
     }
  write(read_file(eLIBRO(fich2)));
return 1;
}
