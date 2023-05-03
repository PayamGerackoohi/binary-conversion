# Binary Conversion

## Requirements
- [Cmake](https://cmake.org/)
- sh
  - Unix
  - Windows: [Git](https://git-scm.com/downloads)

## Build
```sh
echo Config Cmake
ccmake .

echo Build and Run
./run.sh -b
```

### Build Types
- `Release`: high optimization level, no debug info, code or asserts.
- `Debug`: No optimization, asserts enabled, [custom debug (output) code enabled],
   debug info included in executable (so you can step through the code with a
   debugger and have address to source-file:line-number translation).
- `RelWithDebInfo`: optimized, *with* debug info, but no debug (output) code or asserts.
- `MinSizeRel`: same as Release but optimizing for size rather than speed.

## Run
```sh
echo Run with 'v' command
./run v
```

## Output
bin/binary-conversion

## Test
```sh
echo c c g q | ccmake -DBuildModule=0 -DBuildTest=1
./run.sh -b
```
