# Linux 常用软件

## LibreOffice

Ubuntu 默认安装的办公套件

## Firefox

Ubuntu **默认的浏览器**

## Gedit

文本编辑器，支持终端和图形化界面

## vi 文本编辑器(重点)

### vi 介绍

vi 是一个文本编辑器

> 其他的文本编辑器(了解)：vim(vi improved)，Emacs

### vi 的启动和退出

启动：`vi [文件名]`

> NOTE：eg.`vi +5 test.txt`可在打开时将光标移到第5行

退出：

| 命令           | 含义              |
| ------------ | --------------- |
| :q           | 源文件未修改时退出       |
| :q!          | 放弃修改并退出         |
| :wq!         | 强制保存文件并退出       |
| :e!          | 放弃修改并恢复原样(编辑窗口) |
| :w           | 保存当前文件          |
| :w [文件名/路径名] | 另存为             |

### vi 的模式及模式的切换(⭐)

**命令模式**，**插入模式**，**末行模式/转译模式**

> NOTE：末行模式的进入：(命令模式下)输入`:`

### vi 的编辑(了解)

### 
