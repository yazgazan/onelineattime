OneLineAtTime
=============

OneLineAtTime is a command line tool written in c that wrap lines.

## example

When you download a file with axel, you get something like this :

```shell
$ axel "http://url.to.download/file"
Initializing download
File size: 727832574 bytes
Opening output file
Starting download

...
[  3%]  .......... .......... .......... .......... ..........  [18681.6KB/s]
[  3%]  .......... .......... .......... .......... ..........  [18685.2KB/s]
[  3%]  .......... .......... .......... .......... ..........  [18695.7KB/s]
[  3%]  .......... .......... .......... .......... ..........  [18704.9KB/s]
[  3%]  .......... .......... .......... .......... ..........  [18708.7KB/s]
[  4%]  .......... .......... .......... .......... ..........  [18715.9KB/s]
[  4%]  .......... .......... .......... .......... ..........  [18728.6KB/s]
[  4%]  .......... .......... .......... .......... ..........  [18735.1KB/s]
...

Downloaded 694.1 megabytes in 38 seconds. (18450.97 KB/s)
$ 
```

With oneLineAtTime, the progress bar scroll without polluting your term :
```shell
$ axel "http://url.to.download/file" | 1lineattime -H 5 --regex "^\[.+%\]"
Initializing download
File size: 727832574 bytes
Opening output file
Starting download

[100%]  .......... .......... .......... .......... ..........  [18735.1KB/s]

Downloaded 694.1 megabytes in 38 seconds. (18450.97 KB/s)
```

## Usage

```
Usage : 1lineattime [options]

options :
    -e, --regex <regex> :  only the matching lines will be wrapped.
    -H, --head  <n>   :  the first n lines won't be wrapped.
```

