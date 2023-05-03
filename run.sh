# module mode
# echo c c g q | ccmake -DBuildModule=1 -DBuildTest=0
# test mode
# echo c c g q | ccmake -DBuildModule=0 -DBuildTest=1
if [[ "$1" == "-b" || "$1" == "--build" ]]; then
	set -e
	mkdir -p bin
	make
	shift
fi
./bin/binary-conversion "$@"
# ./bin/binary-conversion-test
