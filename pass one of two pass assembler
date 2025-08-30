#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
void main() 
{ 
int start_addr; 
int locctr; 
int length; 
char label[20]; 
char opcode[20];    
char operand[20]; 
    
FILE *input_ptr, *optab_ptr, *symtab_ptr, *intermed_ptr, 
*length_ptr; 
 
input_ptr = fopen("input.txt", "r"); 
symtab_ptr = fopen("symtab.txt", "w"); 
intermed_ptr = fopen("intermediate.txt", "w"); 
length_ptr = fopen("programsize.txt", "w"); 
while (feof(input_ptr) == 0) 
{ 
 fscanf(input_ptr, "%s %s %s", label,opcode, operand); 
 if (strcmp(label, "-") != 0 && strcmp(opcode, "START") != 0 && 
strcmp(opcode, "END") != 0) 
fprintf(symtab_ptr, "%s %x\n", label, locctr);  
 if (strcmp(opcode, "START") == 0) 
 { 
length = 0; 
start_addr=(int)strtol(operand,NULL, 16); 
locctr = start_addr; 
} 
else if (strcmp(opcode, "END") == 0) 
{ 
length = 0; 
fprintf(length_ptr, "%x", locctr - start_addr); 
}        
else if (strcmp(opcode, "BYTE") == 0) 
{ 
if (operand[0] == 'X') 
length = (strlen(operand) - 3) / 2; 
if (operand[0] == 'C') 
length = strlen(operand) - 3; 
}        
else if (strcmp(opcode, "WORD") == 0) 
length = 3;        
else if (strcmp(opcode, "RESB") == 0) 
length = (int)strtol(operand, NULL, 16); 
else if (strcmp(opcode, "RESW") == 0) 
length = 3 * (int)strtol(operand, NULL, 16); 
else 
{ 
if (opcode[0] == '+') 
length = 4; 
else 
length = 3; 
char opc[20]; 
char value[10]; 
int flag = 0; 
optab_ptr = fopen("optab.txt", "r"); 
while (feof(optab_ptr) == 0) 
{ 
fscanf(optab_ptr, "%s %s", opc, value); 
char temp[20] = "+"; 
strcat(temp, opc); 
 
if (strcmp(opcode, opc) == 0 || strcmp(opcode, temp) == 0) 
{ 
flag = 1; 
break; 
} 
} 
fclose(optab_ptr); 
 
if (flag == 0) 
{ 
printf("Opcode not existing for the instruction.\n"); 
break;}}        
fprintf(intermed_ptr, "%x %d %s %s %s\n", locctr, length, label, 
opcode, operand); 
printf("%x %d %s %s %s\n", locctr, length, label, opcode, 
operand); 
locctr += length; 
} 
fprintf(length_ptr,"\nLength of program: %x", locctr - 
start_addr); 
fclose(input_ptr); 
fclose(symtab_ptr); 
fclose(intermed_ptr); 
fclose(length_ptr); 
} 
