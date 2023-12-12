# Binary Conversion

## Requirements
- [Cmake](https://cmake.org/)
- sh
  - Unix
  - Windows: [Git](https://git-scm.com/downloads)
- [Gtest](https://github.com/google/googletest.git)

## Config
### Unix
```sh
./scripts/config.sh
```

### Windows
```sh
./scripts/config.sh win
```

## Build
```sh
./scripts/build.sh
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
./scripts/run.sh
```

## Test
```sh
./scripts/test.sh
```
