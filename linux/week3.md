# Linux 常用命令

## 用户管理
能使用sudo的用户：需加入**sudoers**中
每个用户有唯一的**UID**

### useradd

## 目录操作

### 文件的权限

> eg. drwxr-xr-x<br>

第一个：`-`普通文件 `d`目录 `l`链接文件 `b`设备文件<br>
后九个字符三个一组，分别为 **文件所有者，文件所有者所在用户组，其他用户**的权限<br>
权限类型：**w**写，**r**读，**x**可执行

### ls

列出文件 `ls [选项]`
> -a -s -S -l

`.`当前目录，`..`上级目录

### cd

进入目录 `cd [路径名]`<br>
`.`当前目录，`..`上级目录，`/`根目录，`~`当前用户目录

### pwd

显示当前路径

### mkdir

创建目录 `mkdir [选项] 目录名`<br>
`-m`设置创建目录的权限(eg.777),`-p`递归形式创建目录

### rmdir

删除一个空目录 `rmdir [选项] 目录名`<br>
> 只能删除空目录<br>

`rm`与`rmdir`区别?<br>
`rm`用于删除文件

## 文件操作

### touch

在当前目录下直接创建文件 `touch [文件名]`

### cat

显示文件的内容 `cat [选项] [文件名]`<br>
`-A`显示所有字符......

> **重定向符与管道符**<br>
>
> |符号|格式|含义|
> |---|---|---|
> |>|Command > File|标准输入重定向|
> |<|Command < File|标准输入重定向|
> |2>|Command 2> File|标准错误输出重定向|
> |&>|Command &> File|标准输出合并重定向|
> |>>|Command >> File|标准输出追加重定向|
> wait for add...

### cp

复制文件 `cp [选项] <源文件> <目标>` <br>
`-i` 安全**询问**的方式进行拷贝
> 目标是文件：以文件重命名的方式实现文件的拷贝

### rm

删除文件 `rm [选项] [文件名/目录名]`<br>
`-r -R,--recursive`递归删除目录及内容，`-v,--verbose`显示步骤，`-f,--force`强制删除，忽略不存在的文件，`-i`删除前确认
> `rm -r *.txt` `*`是通配符

### mv

移动，即剪切复制 `mv [文件名] [路径名]`
> `mv`也可以实现重命名的操作

### chmod

修改**文件的权限**和**文件的属性** `chmod [<文件使用者>+/-/=<权限类型>]`

> **文件权限相关参数**<br>
>
> **文件使用者**<br>
>
> |参数|含义|
> |--|--|
> |u|user|
> |g|group|
> |o|others|
> |a|all|
>
> **操作符号**<br>
>
> |参数|含义|
> |--|--|
> |+|增加权限|
> |-|删除权限|
> |=|赋予指定的权限，并取消其他权限|
>
> **权限类型**<br>
>
> |参数|含义|
> |--|--|
> |r|read|
> |w|write|
> |x|可执行|
