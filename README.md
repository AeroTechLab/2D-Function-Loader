# Simple Function Loader

Load function curves data from a storage format into memory data structures

## Usage

On a terminal, get the [GitHub code repository](https://github.com/LabDin/Function-Curves-Loader) with:

    $ git clone https://github.com/LabDin/Function-Curves-Loader [<my_project_folder>]

This implementation depends on [Data I/O JSON](https://github.com/LabDin/Data-IO-JSON) and [Simple Function Curves](https://github.com/LabDin/Simple-Function-Curves) projects, which are added as [git submodules](https://git-scm.com/docs/git-submodule).

To add those repositories to your sources, navigate to the root project folder and clone them with:

    $ cd <my_project_folder>
    $ git submodule update --init

With dependencies set, you can now build the library to a separate build directory with [CMake](https://cmake.org/):

    $ mkdir build && cd build
    $ cmake .. 
    $ make

For building it manually e.g. with [GCC](https://gcc.gnu.org/) in a system without **CMake** available, the following shell command (from project directory) would be required:

    $ gcc curve_loader.c curves/curve.c data_io/data_io_json.c data_io/json/json.c -Icurves -Idata_io/interface -Idata_io/json -shared -fPIC -o libcurveloader.{so,dll}
    
 
## Documentation

Detailed description of the loader functions is available on a [Doxygen](http://www.stack.nl/~dimitri/doxygen/index.html)-generated [documentation page](https://github.com/LabDin/Function-Curves-Loader/curve_loader_8h.html)
