
; 磁盘厂商
BS_OEMName	db "---CN---"	; 必须为8个字节
BPB_BytePerSec	dw 512		; 每个扇区的字节数
BPB_SecPerClus	db 1		; 每族扇区数
BPB_RsvdSecCnt	dw 1		; Boot占用多少扇区
BPB_NumFATs	db 2		; 共有多少FAT表
BPB_RootEntCnt	dw 224		; 根目录文件数最大值
BPB_TotSec16	dw 2880		; 逻辑扇区总数
BPB_Media		db 0xf0		; 介质描述符
BPB_FATSz16	dw 9		; 每FAT扇区数
BPB_SecPerTrk	dw 18		; 每磁道扇区数
BPB_NumHeads	dw 2		; 磁头数（面数）
BPB_HideSec	dd 0		; 隐藏扇区数
BPB_TotSec32	dd 0		; 如果BPB_TotSec16是0，则由这个值记录扇区数
BS_DrvNum		db 0		; 中断13的驱动器号
BS_Reservedl	db 0		; 未使用
BS_BootSig	db 0x29		; 拓展引导标记（0x29）
BS_VolID		dd 0		; 卷序列号
BS_VolLab		db "--CONCHOS--"	; 卷标，必须为11个字节
BS_FileSysType	db "FAT12   "	; 文件系统类型，必须为8个字节
