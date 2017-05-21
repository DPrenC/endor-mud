/******************************************/
/* Comando para eliminar testers.         */
/* Izet@Simauria                          */
/******************************************/

int untester(string str) {
   if (!str) { write("A quien vas a eliminar como tester?\n"); return 1; }
    str = lower_case(str);
   if (!find_object(str)) { write(capitalize(str)+" no está conectado.\n"); return 1; }
   find_object(str)->SetAttribute("tester",0);
   if (find_object(str)->QueryGender() == 2) {
      find_object(str)->SetTitle("la nueva "+find_object(str)->QueryRace());
   } else {
      find_object(str)->SetTitle("el nuevo "+find_object(str)->QueryRace());
   }
   write(capitalize(str)+" ha dejado de ser tester de Endor.\n");
    tell_object(find_object(str),capitalize(getuid(TP))+" te ha eliminado de la lista de Testers de Endor.\n");
   return 1;
}
