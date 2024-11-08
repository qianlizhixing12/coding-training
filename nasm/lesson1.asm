section .data:
  msg db "hello world!"

global _start

section .text
_start:
  mov edx, 12
  mov ecx, msg
  mov ebx, 1
  mov eax, 4
  int 80h

_exit:
  mov ebx, 88
  mov eax, 1
  int 80h
