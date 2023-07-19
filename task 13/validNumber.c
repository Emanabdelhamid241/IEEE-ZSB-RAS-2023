#include <stdbool.h>

bool isNumber(char * s){
    bool digitseen=false,expSeen=false,markSeen=false,dotSeen=false;

       if(*s !='\0'){
        // if has plus or minus
        if(*s=='-'||*s== '+'){
           if (markSeen || digitseen || *(s+1) == '\0' || dotSeen)
               return false;
           markSeen=true;
        }
        // if has e
          else if(s=="e"|| s=="E")  {
               if (expSeen || *(s+1) == '\0' || !digitseen) return false;
            expSeen = true;
          }


        // dot
        else if (*s == '.'){
 if (dotSeen || expSeen || (!digitseen && *(s+1)) == '\0')
      return false;
            dotSeen=true;
        }
         else digitseen = true;

        s++;
    }
    return true;
    }
