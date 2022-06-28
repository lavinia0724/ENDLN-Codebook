#include <stdio.h>
#include <string.h>

int main(){
char * c;
char str1[1005], str2[1005];
scanf("%s %s", str1, str2);
c = strstr(str1, str2);
if (c != NULL){
    printf("Yes\n");
}
else printf("No\n");
}
// Input : Hello eLl
// Output : No