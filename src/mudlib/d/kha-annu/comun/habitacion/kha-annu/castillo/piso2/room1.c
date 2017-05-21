/* Castillo Kha-annu.
 *   [I] Izet@Simauria.
 *   Creacion: 16 Oct, 1997
 *   Ultima modificacion: 1 May, 1998.
 */

#include "path.h"
#include <properties.h>
#include <door.h>


inherit KHA_ROOM;

int abierto;
int tester;
int sillon;
int cama;

create() {
   ::create();
  tester = 0;
  abierto = 0;
  sillon = 0;
  cama = 0;

  SetIntShort("una habitación de invitados");
  SetIntLong(
 "Te encuentras dentro de una habitacion de invitados. La habitacion es muy "
"espaciosa y parece muy comoda. El mobilirario de la habitacion se compone "
"una gran cama rodeada de cortinas, un sillon decorado y un armario adosado "
"a la pared norte.\n");
  SetIntBright(70);

    AddExit("oeste",PISO2+"piso2_2");
    AddDoor("oeste","la puerta del pasillo",
        "La puerta está hecha de madera, y barnizada con muchísimo esmero.\n",
        ({"puerta","puerta de pasillo","puerta del pasillo"}), GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_STATE:DOOR_CLOSED]));

  AddDetail(({"lampara","lamparas","lampara de diamantes",
              "lamparas de diamantes",}),
"Las lamparas del techo estan hechas con diamantes engarzados entre si. De "
"ellas fluyen luces de todos los colores en toda la estancia.\n");
  AddDetail("suelo","Ves tu propio reflejo en el suelo junto con el juego de "
"            luces que crean las lamparas del techo.\n");
  AddDetail(({"paredes","pared"}),
"Son paredes de pura roca tallada, cubiertas de finas lineas de oro.\n");
  AddDetail("cama","La cama es encantadora, y parece muy comoda...\n");
  AddDetail("sillon","Es un pequenyo y comodo sillon.\n");
}
/*
init()  {
   ::init();
   add_action("sentar","sentar");
   add_action("dormir","dormir");
   add_action("sentar","sentarse");
   add_action("dormir","dormirse");
   add_action("abrir","abrir");
   add_action("cerrar","cerrar");
   add_action("mirar","mirar");
   add_action("mirar","m");
   add_action("mirar","mi");
   add_action("mirar","mir");
   add_action("mirar","mira");
   add_action("mirar","exa");
}

sentar(string str)  {
   sillon = 0;

   if ((str == "sillon") || (str == "en sillon") || (str == "en el sillon")
       && (sillon == 0))  {
      write("Te sientas en el sillon y te relajas durante unos segundos.\n");
      say(TP->QueryName()+" se sienta en el sillon.\n");
      sillon = 1;
      TP->SetHP(TP->QueryHP()+2);
      return 1;
   }
   if (sillon == 1) {
      write("Tu cuerpo no reacciona... Estas muy relajado.\n");
      sillon = 2;
      call_out("levantar",1);
      add_action("nada","o");
      add_action("nada","oeste");
      add_action("nada","matar");
      return 1;
   }
   if (sillon == 2)  {
      write("No puedes sentarte, el sillon esta ocupado.\n");
      return 1;
   }
}

dormir(string str)  {
   if (cama == 0)  {
      if (str == "cama" || str == "en cama" || str == "en la cama") {
      write("Te metes en la cama y duermes placenteramente.\n");
      say(TP->QueryName()+" se mete a dormir en la cama.\n");
      cama = 1;
      TP->SetHP((TP->QueryHP()+10));
      call_out("levantar_s",1);
      return 1;
      }
      else {
         write("dormir DONDE?\n");
	 return 1;
      }

   }
   if (cama == 1) {
      write("No puedes hacer nada, el suenyo te ha vencido.\n");
      cama = 2;
      call_out("levantar_c",1);
      add_action("nada","a");
      add_action("nada","b");
      add_action("nada","c");
      add_action("nada","d");
      add_action("nada","e");
      add_action("nada","f");
      add_action("nada","g");
      add_action("nada","h");
      add_action("nada","i");
      add_action("nada","j");
      add_action("nada","k");
      add_action("nada","l");
      add_action("nada","m");
      add_action("nada","n");
      add_action("nada","o");
      add_action("nada","p");
      add_action("nada","q");
      add_action("nada","r");
      add_action("nada","s");
      add_action("nada","t");
      add_action("nada","u");
      add_action("nada","v");
      add_action("nada","w");
      add_action("nada","x");
      add_action("nada","y");
      add_action("nada","z");
      add_action("nada","=");
      add_action("nada","'");
      return 1;
   }
   if (cama == 2)  {
      if (str == "cama" || str == "en cama" || str == "en la cama") {
         write("No puedes dormir en la cama, esta ocupada.\n");
         return 1;
      }
      else  {
         write ("Dormir DONDE?\n");
	 return 1;
      }
   }
}

levantar_s ()  {
   write("Te levantas y te sientes mucho mejor.\n");
   sillon = 0;
   return 1;
}

levantar_c()  {
   write("Te despiertas y sales de la cama. Te sientes en plena forma.\n");
   cama = 0;
   return 1;
}

nada()  {
     return 1;
}

abrir(string str)  {
   if (str !="armario" && str !="el armario")  {
     write("Abrir QUE?\n");
     return 1;
  }
   else  {
      if (abierto == 1)  {
	 write("El armario ya esta abierto.\n");
	 return 1;
      }
      if (abierto == 0)  {
	 write("Abres el armario.\n");
         say(TP->QueryName()+" abre el armario.\n");
         abierto = 1;
         return 1;
      }

   }
}

cerrar(string str)  {
   if (str !="armario" && str !="el armario")  {
     write("Cerrar QUE?\n");
     return 1;
  }
   else  {
      if (abierto == 0)  {
	 write("El armario ya esta cerrado.\n");
	 return 1;
      }
      if (abierto == 1)  {
	 write("Cierras el armario.\n");
         say(TP->QueryName()+" cierra el armario.\n");
	 abierto = 0;
         return 1;
      }

   }
}

mirar(string armario)  {
   if (armario !="armario" && armario !="el armario")  {
     return 0;
  }
   else  {
      if (abierto == 0) {
 	  write("Es un armario de caoba decorada. Esta cerrado.\n");
	  say(TP->QueryName()+" mira un armario.\n");
          return 1;
      }
      if ((abierto == 1) && (tester == 0)) {
	  write(
"Es un armario de caoba decorada. Al mirar en su interior encuentras una "
"armadura.\n");
	  say(TP->QueryName()+" mira un armario.\n");
	  TP->clone_object(ARMADURA+"placas");
	  tester = 1;
          return 1;
      }
      if ((abierto == 1) && (tester == 1)) {
	  write("Es un armario de caoba decorada. Esta vacio.\n");
          return 1;
      }
   }
}
*/