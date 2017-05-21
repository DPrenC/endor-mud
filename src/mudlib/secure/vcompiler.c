#pragma strict_types
/*
 * Ich habe den Hook mal in den master eingebaut, um virtuelle
 * Objekte zu testen. Die Idee ist, falls ein File namens
 * path/blubb/blah geladen werden soll, wird, falls dieses file
 * nicht existiert, eine Funktion compile_object() in einem
 * moeglicherweise existierenden Objekt path/blubb/vcompiler.c
 * aufgerufen. [Deepthought, 29-Jun-94]
 *
 * Anmerkung: damit koennte man sauber das OBJ(/Deepthought)
 * implementieren, indem tatsaechlich versucht wird ein Objekt
 * namens "/Deepthought" zu laden, und ueber compile_object
 * dann das eigentlich richtige Playerobjekt geclont wird.
 * Sinnvoller ist dann wohl sowas wie /player/Deepthought.
 *
 * Andere Anwendungen sind Map-Raeume wie ein Meer.
 */
object compile_object(string filename) {
  log_file("vcompile","File: "+filename+"\n");
  /* Hier irgendwo der Aufruf eines noch spezielleren Compilers */
  /* in einem Wizard- oder Domain-Dir */
  return 0;
}
