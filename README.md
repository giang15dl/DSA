# SW Professional Level

## How to build and run

### Using make

```bash
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
make # build all target
make -j8 # like above but faster
make Survival_Train # build single target
```

### Using Visual Studio (msbuild)

```bash
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017"
cmake --build .
```
