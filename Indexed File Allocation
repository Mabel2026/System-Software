#include<stdio.h> 
struct Alloc_Table{ 
int index; 
char Name[100]; 
int size; 
int alloc[100]; 
}; 
void main(){ 
int ch; 
int count=0,size_used=0,totalsize=0,in; 
struct Alloc_Table A[100]; //max 100 files 
printf("\tIndexed File Allocation\n"); 
printf("Enter the Total No. of Blocks : "); 
scanf("%d", &totalsize); 
int mem[totalsize]; //memory size 
for(int i=0;i<totalsize;i++){ 
mem[i]=-1; //-1 indicates empty block 
} 
while(1){ 
printf("Enter the Name of the File : "); 
scanf("%s",A[count].Name); 
printf("Enter the number of blocks for File : "); 
scanf("%d",&A[count].size); 
size_used+=A[count].size; 
if(size_used>totalsize){ 
printf("Not Enough Space! File Cannot Be Allocated\n"); 
} 
else{ 
in=rand()%totalsize; 
while(mem[in]==1){ 
in=rand()%totalsize; 
} 
A[count].index=in; 
mem[in]=1; 
for(int i=0;i<A[count].size;i++){ 
while(mem[in]==1){ 
in=rand()%totalsize; 
} 
mem[in]=1; 
A[count].alloc[i]=in; 
} 
count++; 
} 
printf("Do you want to add more files?\n1. Yes\n2. No\n : "); 
scanf("%d",&ch); 
if(ch==1){ 
continue; 
} 
else{ 
break; 
} 
} 
if(count==0){ 
printf("Nothing to Show!\n"); 
}else{ 
printf("\n\t Allocation table\n"); 
printf("Index\tName\tSize\tBlocks Allocated\n"); 
for( int i=0;i<count;i++){ 
printf("%d\t%s\t%d\t",A[i].index,A[i].Name,A[i].size); 
for(int j=0;j<A[i].size;j++){ 
printf("%d ",A[i].alloc[j]); 
} 
printf("\n"); 
} 
}} 
