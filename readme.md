# Simple Shutdown

>Simple shutdown is a scheduling software to turn off your computer at desired time. Functions it provides are: 
  - Shutdown
  - Restart
  - Sleep
  - Hibernate

  
# Preview
![alt tag](http://i.imgur.com/n0lcWec.png)


# How to build
### Requirements
1. [MinGW compiler 4.8.1 ](https://sourceforge.net/projects/mingwbuilds/files/host-windows/releases/4.8.1/32-bit/threads-posix/sjlj/)
2. [wxWidgets 3.0.2](https://www.wxwidgets.org/)
3. Code::Blocks IDE (or something else)

### Compile wxWidgets for C::B
Navigate to wxwidgets-3.0.2\build\msw

```
mingw32-make -f makefile.gcc USE_XRC=1 SHARED=1 MONOLITHIC=1 BUILD=release UNICODE=1 USE_OPENGL=1 VENDOR=cb CXXFLAGS="-fno-keep-inline-dllexport" clean
```

```
mingw32-make -f makefile.gcc USE_XRC=1 SHARED=1 MONOLITHIC=1 BUILD=release UNICODE=1 USE_OPENGL=1 VENDOR=cb CXXFLAGS="-fno-keep-inline-dllexport"
```

 [C::B Wiki page](http://wiki.codeblocks.org/index.php/Compiling_wxWidgets_3.0.0_to_develop_Code::Blocks_(MSW))
 
# Download
- [Setup](https://www.dropbox.com/s/6j0n5e79etwkpyg/setup-SimpleShutdown.exe?dl=1)
- [Portable](https://www.dropbox.com/s/5cibdhzv0152acx/SimpleShutdown_Portable.zip?dl=1)
 

 
 
# License

MIT

