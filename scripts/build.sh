cmake --build build --config Release -j8
d=test/data
rm -rf build/$d
cp -r $d build/$d
