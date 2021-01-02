
%include "asm/aso_io.inc"
 section .text
global main
main:
push ebx
mov ebp,esp

mov [ebp-4],dword 0
mov edx,[ebp-4]
mov [ebp-4],edx
mov edx,[ebp-4]
mov [ebp-8],edx
mov eax, [ebp-8]
call print_int_i
pop ebx
ret