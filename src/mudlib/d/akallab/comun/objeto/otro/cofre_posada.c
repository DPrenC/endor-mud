/*
DESCRIPCION  : cofre de la posada
FICHERO      : /d/limbo/comun/objeto/otro/cofre_posada.c
MODIFICACION : 03-10-98 [Angor@Simauria] Creacion
               09-11-99 [Angor@Simauria] Modificaciones varias
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
#include <money.h>
#include AK_MACRO
inherit THING;

int    abierto; //armario cerrado[0], abierto[1]
int    ruido;   //probabilidad de haga ruido al abrir/cerrar
string tipo;    //cofre, armario, etc..
mapping cosas;  //lo que contiene

int HazContenido(){
  int ncapa, ncamisa;
  ncapa=random(3);
  ncamisa=random(4);
  cosas=(["capa":PROT("capa");ncapa,"camisa":PROT("camisa");ncamisa]);
  return 1;
}

string VerContenido(){
  string *idx, str, msg;
  int n_idx,i,n,vacio;
  vacio=1;
  msg="El "+tipo+" contiene:\n";
  n_idx=sizeof(cosas);
  idx = m_indices(cosas);
  for(i=0;i<n_idx;i++) {
      str = idx[i];
      n=cosas[str,1];
      if ((n>0)&&(str)){
         msg+=n+" "+str+(n>1?"s":"")+".\n";
         vacio=0;
         }
  }
  if (vacio==1) msg="El "+tipo+" esta vacio.\n";
  return msg;
}

int NuevaDesc(){
  string str;

  SetShort();
  SetLong();
  SetShort("un gran "+tipo+" "+(abierto==1?"abierto":"cerrado"));
  str="En un gran "+tipo+" de madera, tan pesado que no crees que se pueda mover.\nEsta ";
  str+=(abierto==1?"abierto. "+VerContenido():"cerrado.\n");
  SetLong(str);
  return 1;
}


public int    QueryEstado(){return abierto;}
public int    SetEstado(int i){abierto=i; NuevaDesc(); return 1;}
public int    QueryRuido(){return ruido;}
public int    SetRuido(int i){ruido=i; return 1;}
public string QueryTipo(){return tipo;}
public int    SetTipo(string s){tipo=s; AddId(tipo); NuevaDesc(); return 1;}

/*
reset() {
  ::reset();
  abierto=0;
}*/

int mirar_cmd(string que){
  if (member(TO->QueryIds(),que)!=-1)
     {
     NuevaDesc();
	 }
  return 0;
}

int coger_cmd(string s) {
  string *idx, str, msg, path;
  int n_idx,i,n,cogido;
  object ob;

  if (!s) return 0;

  cogido=0;
  n_idx=sizeof(cosas);
  idx = m_indices(cosas);
  for(i=0;i<n_idx;i++) {
      str = idx[i];
      n=cosas[str,1];
      path=cosas[str,0];
      if ((n>0)&&(s==str)&&(cogido==0)){
            ob=clone_object(path);
            if (ob) {
               cogido=1;
               if (ob->move(TP)){
                  cosas[str,1]=cosas[str,1]-1;
				  NuevaDesc();
    			  write("Coges un"+(TO->Query(P_GENDER)==GENDER_FEMALE?"a ":" ")+s+" del "+QueryTipo()+".\n");
				  }
               }
           }
    }
    if (cogido==0) return 0;
  return 1;
}


int abrir_cmd(string str) {
  object ob;
  if ((!str)||(str!=tipo)) return 0;
  if (abierto==0) {
     write("Tras forcejear un poco con el oxidado pestillo del "+tipo+", consigues abrirlo.\n");
     abierto=1;
     NuevaDesc();
     if (random(100)<=QueryRuido()-(TP->QueryDex())){
        abierto=1;
        NuevaDesc();
        write("El "+tipo+" hace un ruidoso chirrido al abrirse.\n");
        say(NOMBRE+" abre ruidosamente el "+tipo+".\n",TP);
        ob=present("huesped",environment(TO));
        if (ob) ob->despertar();
        }
     else{
        say(NOMBRE+" abre el "+tipo+".\n",TP);
        }
     return 1;
     }
  else {write("El "+tipo+" ya esta abierto.\n");return 1;}
}


int cerrar_cmd(string str) {
  object ob;
  if ((!str)||(str!=tipo)) return 0;
  if (abierto==1) {
    abierto=0;
    NuevaDesc();
    if (random(100)<=QueryRuido()-(TP->QueryDex())){
        write("Cierras el "+tipo+" con un golpe seco.\n");
        say(NOMBRE+" cierra el "+tipo+" con un golpe seco.\n",TP);
        ob=present("huesped",environment(TO));
        if (ob) ob->despertar();
        }
     else{
        write("Cierras el "+tipo+".\n");
        say(NOMBRE+" cierra el "+tipo+".\n",TP);
        }
    return 1;
    }
  else {write("El "+tipo+" ya esta cerrado.\n");return 1;}
}


create() {
  ::create();
  seteuid(getuid(TO));
  SetShort("un cofre");
  SetLong("Es un cofre.\n");
  SetIds(({"mueble"}));
  HazContenido();

  if (!tipo) {abierto=0; ruido=75; SetTipo("cofre"); NuevaDesc();}

  SetWeight(100000);
  SetValue(0);
  Set(P_NOGET,1);
}


init() {
  ::init();
    add_action("abrir_cmd","abrir");
    add_action("cerrar_cmd","cerrar");
	
    add_action("mirar_cmd","mirar");	
    add_action("coger_cmd","coger");
}

