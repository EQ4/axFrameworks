#axFrameworks

A C++ cross-platform framework to build highly customizable platform-independent graphical user interface base on OpenGL.

## Features
- Easy to setup.
- Currently supports Mac OS X (10.10), Windows 7 and 8, Linux (X11) and Raspberry Pi.
- Extensive use of C++14 and Standard Template Library (STL) syntax.
- Use of C++14 lambda functions and threads for event management.
- Minimize interaction with operating systems.

## Builtin Widgets

axButton        | axSlider          | axKnob            | axToggle          | axMenu            |
|:------------: | :---------------: | :---------------: | :---------------: | :---------------: |
| **axNumberBox**  | **axGrid**     | **axPopupMenu**   | **axDropMenu**    | **axScrollBar**   |

## Git instructions.

### Clone
    git clone https://github.com/axlib/axFrameworks.git
    ./build.sh init

## Compile

    ./build.sh build
    sudo ./build.sh install
    export LD_LIBRARY_PATH=/usr/local/lib/:$LD_LIBRARY_PATH

### Dependencies
    - libpng16
    - libfreetype2
    - libsndfile
    - libportaudio
    - libsqlite3

## Create Project

### Mac OS 10.10 (Yosemite) - Xcode 6.1

1. First you need to install freetype-2.4.0 library or newer version and libpng15.
* Make sure they're located in **/usr/local/include/** and **/usr/local/lib/**

2. Create new Project Cocoa application with **Objective-C** language.

3. Delete test folder in project navigator and click on move to trash.

![Delete test folder](https://dl.dropboxusercontent.com/u/26931825/axLibWebData/ProjectFromScratch_Test.png)

4. Then go in project option under **Targets List** right click and delete test target.

![Delete test](https://dl.dropboxusercontent.com/u/26931825/axLibWebData/ProjectFromScratch_Tst2.png)

5. Delete these files in project navigator and move to trash.
    * **AppDelegate.h**
    * **AppDelegate.m**
    * **MainMenu.xib**

6. Add these folder to **Search Paths** tab under **Header Search Paths** in project configuration.
    * **/usr/local/include/**
    * **/usr/local/include/freetype2/**

7. Add this folder to **Search Paths** tab under **Library Search Paths** in project configuration.
    * **/usr/local/lib/**

8. Add these flags to **Linking** tab under **Other Linker Flags** still in project configuration.
    * **-laxLibCore**
    * **-lfreetype**
    * **-lpng15**

9. Change **Per-configuration Build Products Path** in **Build Locations** tab to :
    * **$(SRCROOT)/Debug/**
    * **$(SRCROOT)/Release/**
