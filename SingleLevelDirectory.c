#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX 100 
typedef struct 
{ 
char name[MAX]; 
char path[MAX]; 
}file; 
file singlel[MAX]; 
int scount; 
void screate() 
{ 
char n[MAX]; 
printf("Enter file name :\n"); 
scanf("%s",n); 
for(int i=0;i<scount;i++) 
{ 
if(strcmp(singlel[i].name,n)==0) 
{ 
printf("File already exists!\n"); 
}} 
strcpy(singlel[scount].name,n); 
strcpy(singlel[scount].path,"/"); 
strcat(singlel[scount].path,n); 
scount++; 
printf("File added successfully.\n"); 
} 
void sdisplay() 
{ 
printf("Single level directory files -\n"); 
for(int i=0;i<scount;i++) 
{ 
printf("File: %s",singlel[i].name); 
printf("\tPath: root%s\n",singlel[i].path); 
}} 
 
void ssearch() 
{ 
int f=0; 
char fname[MAX]; 
printf("Enter file name to search: \n"); 
scanf("%s",fname); 
for(int i=0;i<scount;i++) 
{ 
if(strcmp(singlel[i].name,fname)==0) 
{ 
printf("File found\n"); 
printf("Path: %s\n",singlel[i].path); 
f=1; 
}} 
if(f==0) 
{ 
printf("File not found!\n"); 
}} 
void sdel() 
{ 
int f=0,i,j; 
char fname[MAX]; 
printf("Enter file name to delete: \n"); 
scanf("%s",fname); 
for(i=0;i<scount;i++) 
{ 
if(strcmp(singlel[i].name,fname)==0) 
{ 
f=1; 
for(j=i;j<scount;j++) 
{ 
singlel[j]=singlel[j+1]; 
} 
scount--; 
printf("File deleted successfully.\n"); 
}} 
if(f==0) 
 { 
  printf("File not found!\n"); 
 }} 
void main() 
{ 
int x=0; 
while(x!=5) 
{ 
printf("\nEnter choice: 1.Create  2.Delete  3.Search  4.Display 
5.Exit\n"); 
scanf("%d",&x); 
if(x==1) 
 { 
  screate(); 
 } 
else if(x==2) 
 { 
  sdel(); 
 } 
else if(x==3) 
 { 
  ssearch(); 
 } 
else if(x==4) 
 { 
  sdisplay(); 
 } 
else if(x==5) 
 { 
  exit(0); 
 } 
else 
 { 
  printf("Invalid choice\n"); 
 }}}
