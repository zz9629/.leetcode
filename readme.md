Hi, there are something you should know:

Before running this code, please make sure that you have installed the fftw library.

For MacOS, it can be installed by
```
brew install fftw
```
If brew does not work, download packages and install fftw via cmake locally.

```
// enter the unzipped folder
sudo make .
sudo make
sudo make install
```

Then, run following scripts in terminal.

```
g++ -std=c++11 assignment.cpp -I/usr/local/include -L/usr/local/lib -lfftw3 -lm -o test
./test
```
