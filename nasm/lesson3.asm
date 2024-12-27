section .data:
  msg db "hello world!", '\n', '\0'

global _start

section .text
_start:
  mov eax, msg
  call _print
  call _exit


; 输入eax字符串地址
; 输出ebx字符串长度
_strlen:
  push eax
  push ebx
  mov ebx, eax
  _loop:
    cmp byte [ebx], 0
    jz _ret
    inc ebx
    jmp _loop
  _ret:
    sub ebx, eax
    ret


; 输入eax字符串地址
_print:
  call _strlen
  mov edx, ebx
  mov ecx, msg
  mov ebx, 1
  mov eax, 4
  int 80h
  ret

_exit:
  mov ebx, 88
  mov eax, 1
  int 80h
