#include <properties.h>

int main(string str) {
string elque;
string aquien;
object obj;

 if (!str || sscanf(str,"%s a %s", elque, aquien) != 2) {
    return notify_fail("Uso: acariciar <el que> a <quien>\n");
 }

 if (!obj=find_object(lower_case(aquien))) {
    return notify_fail(sprintf("%s\n",
    capitalize(aquien) no está aquí));
 }

 write(sprintf("Te acercas a "+capitalize(aquien)+" y le acaricias %s.\n",elque));
 tell_object(obj,sprintf(TP->Query(P_NAME)+" te acaricia con suavidad %s.\n",elque));
 return 1;

}
