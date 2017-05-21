/* SIMAURIA
 * Archivo: /lib/web/rorla.c
 * Utilidad: Se encarga de generar la orla.
 *
 * [m] Mirill@Simauria
 *
 * 28/06/00 [m] Comienza la creación del archivo.
 *
 */
#include "/secure/config.h"
#include <wizlevels.h>

public string Orla()
{

string str;
mixed orlastr2,orlastr,orlmap,aux,save,players;
int i, j;

    str = "";
    orlastr = get_dir("/players/???*");
    orlmap = ([ ]);
    save = get_dir("/save/*");
    orlastr2 = get_dir("/fotos/*.jpg");
      for (i = 0; i < sizeof(orlastr2); i++) {

          aux = orlastr2[i];
          aux = aux[0..strlen(aux)-5];
          orlastr2[i] = aux;

    }

// Crea la primera parte de la tabla, mirando los Gods.
     for (i = 0; i < sizeof(orlastr); i++) {
      if (IS_GOD(orlastr[i]) == 1) {
       if( member(orlastr2, orlastr[i]) == -1 )
          str += (orlastr[i]+":foto.jpg;");
        else
          str += (orlastr[i]+":"+orlastr[i]+".jpg;");
//      orlastr -= ({orlastr[i]});
    }
  }
  str += "\n%SEP%\n";
// Crea la tabla correspondiente a los Arch

    for (i = 0; i < sizeof(orlastr); i++) {
      if (IS_GOD(orlastr[i]) == 1) { }
         else {
      if (IS_ARCH(orlastr[i]) == 1) {

       if( member(orlastr2, orlastr[i]) == -1 )

          str += (orlastr[i]+":foto.jpg;");
        else
          str += (orlastr[i]+":"+orlastr[i]+".jpg;");
//       orlastr -= ({orlastr[i]});
      }
   }
 }
  str += "\n%SEP%\n";
// Crea la tabla de los Wizs normales
    for (i = 0; i < sizeof(orlastr); i++)
    {
      if( !IS_ARCH( orlastr[i] ) )
       {
          if (IS_LORD(orlastr[i]))
             str += ("L:");
          else if (IS_VICE(orlastr[i]))
               str += ("V:");
            else
               str +=("W:");
            if( member(orlastr2, orlastr[i]) == -1 )
               str += (orlastr[i]+":foto.jpg;");
            else
               str += (orlastr[i]+":"+orlastr[i]+".jpg;");
       }
     }
   return str;
}

