/******************************************/
/* Comando para hacer testers registrados */
/* Izet@Simauria                          */
/******************************************/

int tester(string str) {
   if (!str) { write("A quien vas a hacer tester?\n"); return 1; }
    str = lower_case(str);
   if (!find_object(str)) { write(capitalize(str)+" no está conectado.\n"); return 1; }
   find_object(str)->Set("tester",TP);
   find_object(str)->SetPresay("(tester) ");
   write(capitalize(str)+" se ha convertido en tu tester.\n");
   tell_object(find_object(str),capitalize(getuid(TP))+" te ha nombrado tester de endor.\n");
   return 1;
}
