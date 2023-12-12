cmake -B build \
-DCMAKE_BUILD_TYPE=Release \
-DWIN_TEST=`[[ $1 == "win" ]] && echo ON || echo OFF`
