# SW Professional Level

## How to build

### Using make

```ps1
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
make # build all target
make -j8 # like above but faster
make Survival_Train # build single target
```

### Using Visual Studio (msbuild)

```ps1
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017"
cmake --build .
```

## Run

```ps1
cd build/Bacteria
./Bacteria
(Measure-Command {./Bacteria | Out-Default }).ToString() # To measure run time
```
