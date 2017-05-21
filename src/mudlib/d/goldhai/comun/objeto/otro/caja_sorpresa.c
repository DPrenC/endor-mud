/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 28-05-97                |
 |               Ultima Modificacion.. 07-06-97                |
 |                                                             |
 *=============================================================*
 |  Esta caja es especial ya que cada vez que uno la abre le   |
 |  aguarda una agradable o desagradable sorpresa. Igual te    |
 |  te aparece un enano que te da una llave, como te aparece   |
 |  el mismo enano que te roba el dinero, como aparece un orco |
 |  con una fuerza abismal que te ataca, o bien se oscurece el |
 |  lugar donde estas, como empieza a llover granizo, etc...   |
 |  Que nadie te lo cuente, descubrelo tu mismo.. :)           |
 |                                                             |
 *=============================================================*/

#include "./path.h"
#include <properties.h>


inherit THING;

#define LOG_FILE LOGS "CAJA_SORPRESA"
#define RND_ATAQUE 2

string *npcs_ataque=
             ({
               PNJ("parque/ardilla"),
               PNJ("parque/oso")
             });

/* Variables */
string actual_song;

/* Funciones */
int abrir_caja(string str);
clonar_monstruo();

/* Funcion principal */
create() {
    ::create();
    seteuid(getuid(TO));
    AddId("caja sorpresa");
    AddId("caja");
    SetShort("una caja sorpresa");
    SetLong(
"Se trata de una caja de marfil muy antigua con una inscripcion que dice:\n\
Si eres un osado, intrepido, valiente y sin miedo a la muerte, abrela.\n");
    SetWeight(300);
    Set(P_VALUE,470);
    Set(P_MAGIC,1);
    Set(P_NODROP,0);
    Set(P_NOSELL,1);
    Set(P_NOBUY,1);
    Set(P_GENDER,GENERO_FEMENINO);
    Set(P_NUMBER,NUMERO_SINGULAR);
}

void init() {
  ::init();
  /* add_actions */
  add_action("abrir_caja","abrir");
}

/* Otras funciones */
int abrir_caja(string str)
{
 if(!str) return notify_fail("Que es lo que quieres abrir?\n"),0;
 if ((str!="caja") && (str!="caja sorpresa")) return notify_fail("Que es lo que quieres abrir?\n"),0;
 if(!present(TO,environment(TP))) return notify_fail("Quizas debieras dejar la caja en tierra antes de abrirla.\n"),0;
 switch(random(2))
 {
  case 0:
    write("Ufff, has tenido suerte.. de momento jeje.\n");
    destruct(TO);
    break;
  case 1:
    write_file(LOG_FILE,ctime(time())+" "+TNAME+" abrio la caja y le aparecio un monstruo.\n");
    write("La caja empieza a brillar, se abre y aparece una extranya criatura\n");
    call_out("clonar_monstruo",5);
    break;
  default:
    write("ufff, has tenido suerte.. de momento jeje.\n");
    destruct(TO);
    break;
 }
 return 1;
}

clonar_monstruo()
{
 int rnd;
 object m;
 rnd=random(RND_ATAQUE);
 m = clone_object(npcs_ataque[rnd]);
 m->move(environment(TO));
 m->SetAggressive(1);
 m->Kill(TP);
 TO->Set(P_NOGET,"La caja esta rodeada de un aura blanca y te es imposible cogerla.\n");
 call_out("d_monstruo",10,m);
}

d_monstruo(m)
{
 if(clonep(m)) destruct(m);
 tell_room(environment(TO),"La caja deja de brillar y desaparece.\n");
 destruct(TO);
}
