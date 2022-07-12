```sh
$> ls -l ~
-rwsr-x---+ 1 level1 users 747441 Mar  6  2016 level0

$> ./level0
Segmentation fault (core dumped)

$> ./level0 test
No !
```

As we can see in the source code, we just have to set the first argument to 0x1a7 (423 in decimal) to launch a new terminal

```sh
$> ./level0 423
$ whoami
level1
$ cd /home/user/level1
$ ls -la
total 17
dr-xr-x---+ 1 level1 level1   80 Mar  6  2016 .
dr-x--x--x  1 root   root    340 Sep 23  2015 ..
-rw-r--r--  1 level1 level1  220 Apr  3  2012 .bash_logout
-rw-r--r--  1 level1 level1 3530 Sep 23  2015 .bashrc
-rwsr-s---+ 1 level2 users  5138 Mar  6  2016 level1
-rw-r--r--+ 1 level1 level1   65 Sep 23  2015 .pass
-rw-r--r--  1 level1 level1  675 Apr  3  2012 .profile
$ cat .pass
1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a
$ exit

$> su level1
Password: 1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a
```
