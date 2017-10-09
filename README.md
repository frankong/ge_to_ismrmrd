# Getting started with the Orchestra to ISMRMRD converter library

Orchestra conversion tools

## To build and install the tools to convert GE raw files into ISMRMRD files:

1.  Define the `SDKTOP` environment variable to be the Orchestra directory, e.g.

    ```bash
    export SDKTOP=~/orchestra-sdk-1.6-1
    ```

1. Define the `ISMRMRD_HOME` to be the ISMRMRD source code directory AND `GE_TOOLS_HOME` to be the ge_to_ismrmrd source code directory. These specify installation location(s), e.g.

    ```bash
    export ISMRMRD_HOME=<prefix>/ismrmrd
    export GE_TOOLS_HOME=<prefix>/ge_to_ismrmrd
    ```

1.  Obtain the ISMRMRD source code:

    ```bash
    git clone https://github.com/ismrmrd/ismrmrd
    ```

1.  Pre-define the location of HDF5 in order to use Orchestra's static HDF5 library:

    ```bash
    export HDF5_ROOT=$SDKTOP/recon/3p/Linux/hdf5-1.8.12_dev_linux64
    ```

1. Configure, compile, and install ISMRMRD:

    ```bash
    cd ismrmrd/
    mkdir build
    cd build/
    cmake ..
    make install
    cd ../
    ```

1. Obtain the GE converter source code:

    ```bash
    git clone https://github.com/ismrmrd/ge_to_ismrmrd.git
    ```

1. Configure, compile and install the converter:

    ```bash
    cd ge_to_ismrmrd/
    mkdir build
    cd build/
    cmake -D OX_INSTALL_DIRECTORY=$SDKTOP ..
    make install
    cd ../
    ```
1. Make sure `$ISMRMRD_HOME/bin` and `$GE_TOOLS_HOME/bin` are added to your environment's `PATH` variable, and that `$ISMRMRD_HOME/lib` and `$GE_TOOLS_HOME/lib` are added to your environment's `LD_LIBRARY_PATH` variable, to be able to use the libraries and binaries supplied with these tools.

1. A typical command line to convert the supplied P-file using this library is:

   ```bash
   pfile2ismrmrd -v -l libp2i-generic.so -p GenericConverter -x $GE_TOOLS_HOME/share/ge-tools/config/default.xsl P12800_sample.7
   ```

1. If customized conversion libraries are desired, the corresponding command will be:

   ```bash
   pfile2ismrmrd -v -l libp2i-NIH.so -p NIH2dfastConverter -x $GE_TOOLS_HOME/src/ge-tools/config/default.xsl P12800_sample.7
   ```

   The source code that enables this example is included with these tools.  This example is a straightforward copy of the GenericConverter, but it shows how these classes can be inherited from and implemented.

