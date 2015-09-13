#axFrameworks

A C++ cross-platform framework to build highly customizable platform-independent graphical user interface base on OpenGL.

## Features
- Easy to setup.
- Currently supports Mac OS X (10.10), Windows 7 and 8, Linux (X11) and Raspberry Pi.
- Extensive use of C++14 and Standard Template Library (STL) syntax. 
- Use of C++14 lambda functions and threads for event management.
- Minimize interaction with operating systems.

## Build in Widgets

axButton        | axSlider          | axKnob            | axToggle          | axMenu            |
|:------------: | :---------------: | :---------------: | :---------------: | :---------------: |
| **axNumberBox**  | **axGrid**     | **axPopupMenu**   | **axDropMenu**    | **axScrollBar**   |

## Git instructions.

### Clone
    git clone https://github.com/axlib/axFrameworks.git
    git submodule init
    git submodule update
    git submodule foreach git pull origin master
    git submodule foreach git checkout master

## Compile

    ./build.sh build
    sudo ./build.sh install
    export LD_LIBRARY_PATH=/usr/local/lib/:$LD_LIBRARY_PATH