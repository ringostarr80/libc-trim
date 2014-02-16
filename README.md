libc-trim
=========

a little c-library that trims c-chars from leading and trailing whitespaces

build
-----
simply type
```
make
```
the library file is placed in dist/Debug/GNU-Linux-x86/libc-trim.so

testing
-------
if you want to run the CUnit tests, you need to install cunit-library  
on Ubuntu:
```
sudo apt-get install libcunit1-dev
```
and then you can run the test with:
```
make test
```
