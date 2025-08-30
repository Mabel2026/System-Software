#define _GNU_SOURCE 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
void convert(char h[12]); 
char bitmask[12]; 
char bit[12] = { 0 }; 
int main() { 
char add[6], length[10], 
input[10], binary[12], relocbit, 
ch, pn[5], name[10]; 
int start, len, i, address, 
opcode, addr, actualadd, tlen; 
FILE *fp1, *fp2; 
printf("Enter the name of the program: "); 
scanf("%s", name); 
printf("\nEnter the new starting address: "); 
scanf("%x", &start); 
fp1 = fopen("Obj1.txt", "r"); 
if (fp1 == NULL) { 
fprintf(stderr, "Error opening Obj1.txt\n"); 
return EXIT_FAILURE; 
} 
fp2 = fopen("Reloc_out.txt","w"); 
if (fp2 == NULL) { 
fprintf(stderr, "Error 
opening Reloc_out.txt\n"); 
fclose(fp1); 
return EXIT_FAILURE; 
} 
fprintf(fp2, "\tIn 
Memory\n"); 
fprintf(fp2,"Location\tObject Code\n"); 
fscanf(fp1, "%s", input); 
 
while (strcmp(input, "E") !=0) { 
if (strcmp(input, "H") 
== 0) { 
fscanf(fp1, "%s %s %s", pn, add, length); 
fscanf(fp1, "%s",input); // Read next input 
} 
if (strcmp(input, "T") == 0) { 
fscanf(fp1, "%x %x %s", &address, &tlen, bitmask); 
address += start; // 
Adjust address by start 
convert(bitmask); 
len = strlen(bit); 
if (len >= 11) len = 10; // Limit length to 10 bits 
for (i = 0; i < len; i++) { 
fscanf(fp1, "%x %x", &opcode, &addr); 
relocbit = bit[i]; 
actualadd = (relocbit == '0') ? addr : addr+ start; 
fprintf(fp2,"%x\t\t%x%x\n", address, opcode,actualadd); 
address += 3; //Increment address for nextrecord 
} 
fscanf(fp1, "%s", 
input); // Read next input 
} 
} 
fclose(fp1); 
 
fclose(fp2); 
fp2 = fopen("Reloc_out.txt","r"); 
if (fp2 == NULL) { 
fprintf(stderr, "Error reopening Reloc_out.txt for reading\n"); 
return EXIT_FAILURE; 
} 
// Read and print the contents of the output file 
ch = fgetc(fp2); 
while (ch != EOF) { 
putchar(ch); 
ch = fgetc(fp2); 
} 
fclose(fp2); 
return EXIT_SUCCESS; 
} 
void convert(char h[12]) { 
int i, l; 
strcpy(bit, ""); // 
Initialize bit as emptyl = strlen(h); 
for (i = 0; i < l; i++) { 
switch (h[i]) { 
case '0': strcat(bit, "0"); 
break; 
case '1': strcat(bit, "1"); 
break; 
case '2': strcat(bit, "10"); 
break; 
case '3': strcat(bit, "11"); 
break; 
case '4': strcat(bit, "100"); 
break; 
case '5': strcat(bit, "101"); 
break; 
case '6': strcat(bit, "110"); 
break; 
case '7': strcat(bit, "111"); 
break; 
 
case '8': strcat(bit, "1000"); 
break; 
case '9': strcat(bit, "1001"); 
break; 
case 'A': strcat(bit, "1010"); 
break; 
case 'B': strcat(bit, "1011"); 
break; 
case 'C': strcat(bit, "1100"); 
break; 
case 'D': strcat(bit, "1101"); 
break; 
case 'E': strcat(bit, "1110"); 
break; 
case 'F': strcat(bit, "1111"); 
break; 
} 
} 
} 
