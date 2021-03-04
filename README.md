# OS笔记

#### 关于

就目前开发环境是Windows10，可能以后会换这个环境，不过问题不大。软件开发环境使用的 IDE 是 VScode ，关于对磁盘的操作用的是 dd 工具，系统运行在 Bochs 2.6.11 上，接下来也是会用Bochs进行调试。

还有就是编译器，我这里 汇编是使用的 nasm ， c语言是 GCC 或者 Visual Studio 。

## 准备工作环境的搭建

#### 虚拟硬盘的创建

**windows**启动 `cmd` ，使用 `diskpart` 命令，在弹出的对话框稍微等待，出现`DISKPART>` 就可以了

创建磁盘（**vhd**）：

```assembly
create vdisk file=C:\路径\磁盘名.vhd maximum=10 type=fixed
maximum 磁盘大小
```

创建磁盘（**img**）： 使用 `dd` 创建一个 **1.44Mb** 的img文件

```assembly
dd if=/dev/zero of=new_img.img bs=512 count=2880
    ; count 磁盘扇区数，bs 扇区大小
```

#### 编译

使用 `nasm.exe` 进行编译：`nasm 文件名.asm -o 目标文件名` 

**头文件** `nams -I 头文件目录` 

#### 刷入

使用 `dd.exe` 写入磁盘：`dd if=可执行文件路径 of=磁盘路径 bs=写入的大小(byte) count=1` 
