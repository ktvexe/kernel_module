/*
*user program v1.0
*
*used to read file in /proc created by kernel module program
*
*@author LG Liu
*@link https://github.com/ktvexe/kernel_module
*/
#include <stdio.h>
#include <stdlib.h>


int main(){
	FILE* fp;
	char ch;
	
	//file name id "ker_proc"
	if((fp=fopen("/proc/ker_proc","r"))==NULL){
    	printf("open file error!!\n");
        exit(0);
    }

    while((ch=fgetc(fp))!=EOF){
    	printf("%c",ch);
    }

    fclose(fp);
    return 0;

}
