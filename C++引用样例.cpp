#include <stdio.h>
#include <stdlib.h>

void change(char *&q){
    q=(char*)malloc(100);
    fgets(q,100,stdin);
}
int main() {
    char *p;
    change(p);
    puts(p);
    return 0;
}
/*
    法二：不用引用 
	#include <stdio.h>
    #include <stdlib.h>

    void print(char *q){
      puts(q);
    }
   int main() {
      char *p;
      p=(char*)malloc(100);
      fgets(p,100,stdin);
      print(p);
      return 0;
   }
*/

