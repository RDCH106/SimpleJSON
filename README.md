About
-----

SimpleJSON is a simple JSON library written in C++. It is designed to be simple
to use and be cross platform.

The library consists of 2 classes - JSON and JSONValue. The JSON class acts
similar to the Javascript JSON object and contains Parse() and Stringify()
methods for dealing with decoding and encoding JSON text. The JSONValue class
is the class that deals with representing the various JSON values in a C++ way.

Included with the source code is a demo application to give a basic example of
how the library works and run some tests on the library. Linux users should
just need the basic development tools installed while Windows will need VS2008
to build the project (or be able to handle VS2008 project files).

The library requires no 3rd party libraries and so can be dropped into any
existing project effortlessly. It has been tested on Linux and Windows
(using VS2008), if you come across any issues with using it on any system, feel
free to contact me by visiting my site at http://mjpa.co.uk

Notes
-----

If building for Android and using Visual Studio, make sure `Ignore All Default
Libraries` is set to `No`. The setting can be changed by going `Settings ->
Configuration Properties -> Linker -> Input`.

If you look at the examples, you will see usage of `JSONArray` and `JSONObject`
these are simply type definitions as outlined below:

* JSONArray: std::vector<JSONValue*>
* JSONObject: std::map<std::wstring, JSONValue*>

Compiling crossplatform with CMake
-------------------------------------

1. Set this path in source
2. Choose a toolchain if is needed and your IDE configuration (MSVS, Eclipse, Makefile...)
3. Choose the build path where the project will be built
4. Configure & generate


