pushd build/test > /dev/null
./BinaryConversionTest --gtest_output=json > test_detail.txt
# ./BinaryConversionTest
# ./BinaryConversionTest --gtest_filter=ConverterSuite.overrideConversion
popd > /dev/null
