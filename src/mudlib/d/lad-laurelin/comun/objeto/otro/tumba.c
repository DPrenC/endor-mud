/*
DESCRIPCION: Objeto tumba, de la que puede salir un muerto viviente
FICHERO:
CREACION: Alura (Julio del 2000)
MODIFICACION: Mayo del 2001
*/

#include <properties.h>
#include <moving.h>
inherit "std/room/items";
inherit "/obj/chest";

int TieneOcupante;  //valores: 0 y 1
object OCUPANTE;

void mensaje(){
   if (TO->Query("Abierta")==1)
	TO->SetLong("Es una tumba cavada en el suelo tapada por una gran losa de mármol.\n"+
	"La puerta está abierta de par en par.\n");
   else TO->SetLong("Es una tumba cavada en el suelo tapada por una gran losa de mármol.\n"+
	"Está cerrada.\n");
}


int AbrirTumba(string str)  //incluir en el init
{
	int aux;
        if (str=="tumba"){
        if (TO->Query("Abierta")==1) {
                dtell(TP->QueryName(),"Esta tumba ya está abierta.\n");
                return 1;
        }else{
		aux=random(2);
		if ( (aux==0) || (aux==1) ) OCUPANTE=clone_object("/d/lad-laurelin/comun/pnj/tiin/lago/ghoul");
                else OCUPANTE=clone_object("/d/lad-laurelin/comun/pnj/tiin/lago/momia");
		OCUPANTE->move(environment(),M_SILENT);
                tell_room(environment(),"Una tumba se abre y un ser putrefacto sale de ella.\n");
                TO->Set("Abierta",1);
                mensaje();
                return 1;
        }//else
  }else return 0; //if str
}


int CerrarTumba()  //incluir en el init
{
        if (TO->Query("Abierta")==1)
        dtell(TP->QueryName(),"Una vez abierta ya no consigues cerrarla.\n");
        else dtell(TP->QueryName(),"La tumba ya está cerrada.\n");
        mensaje();
        return 1;
}


create(){
        ::create();
          Set("Abierta",0);
        SetShort("una tumba");
        SetIntShort("una tumba abierta");
        mensaje();
        SetPreContent("Dentro descansa\n");
        Set(P_NOGET, 1);
        Set(P_NOSELL, 1);
        AddId(({"tumba","lápida","lapida"}));
}

init(){
        ::init();
        add_action("AbrirTumba","abrir");
        add_action("CerrarTumba","cerrar");
}
