; section 分段 align 内存对齐格式16位32位对齐
section code align=16 vstart=0x7c00

    mov si, HelloWorldDB
    xor di, di
    call PrintString
    inc si
    call PrintString

    jmp $

SetCharColor equ 0x07

;=========================================================
; 打印字符串
PrintString:
    mov ax, 0xB800
    mov es, ax
    mov ah, SetCharColor

    mov cx, 0x0000
llop:
    mov al, [ds:si]
    cmp al, 0x00
    je .PrintStringEnd
    mov [es:di], ax
    inc si
    add di, 2
    loop llop

.PrintStringEnd:
    ret

;=========================================================
HelloWorldDB    db 'Hello OS'
                db 0x00
ByeOSDB         db 'Bye OS'
                db 0x00

times 510 - ($-$$) db 0
dw 0xAA55
