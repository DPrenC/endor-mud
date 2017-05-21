#ifndef _LIB_STRING_H
#define _LIB_STRING_H 1

  /* stime()-formats */

#define SD_WDAY 1
#define SD_DATE 2
#define SD_TIME 4
#define SD_SDATE 8
#define SD_FULL 7

  /* Standard-SMore using this_player()'s Pagesize: */

#define SMore(text) smore(text,(int)this_player()->QueryPageSize())

  /* smore() array fields */
#define SMORE_TEXT     0 /* string * : the text to more */
#define SMORE_LINE     1 /* int      : the current line */
#define SMORE_SIZE     2 /* int      : the number of lines */
#define SMORE_CHUNK    3 /* int      : the chunk's size */
#define SMORE_END      4 /* int      : the last line */
#define SMORE_PRINTALL 5 /* int      : flag if all should be printed */
#define SMORE_OBJECT   6 /* object   : the object holding SMORE_FUN */
#define SMORE_FUN      7 /* string   : name of the 'smore done' function */
#define SMORE_REGEXP   8 /* string   : last regexp pattern */
#define SMORE_DATASIZE 9

#endif
