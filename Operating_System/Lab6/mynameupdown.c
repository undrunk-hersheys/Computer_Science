#include <stdio.h>
#include <string.h>
int main(){
	char * name = "Gyuho Tae";
	int nameLength = strlen(name);
	int count;
	for (count=0; count<nameLength; count++){
		printf("%c\n", name[count]);
	}
	for (count=(nameLength-1); count>=0; count--){
		printf("%c\n", name[count]);
	}
	return 0;
}
