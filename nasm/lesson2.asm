section .data:
  msg db "hello world!", 0AH

global _start

section .text
_start:
  mov edx, 13
  mov ecx, msg
  mov ebx, 1
  mov eax, 4
  int 80h

_exit:
  mov ebx, 88
  mov eax, 1
  int 80h
