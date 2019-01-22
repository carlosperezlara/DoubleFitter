all:
	rootcint -f Dict.cpp -c LinkDef.h
	g++ -o DoubleFitter.cxx Dict.cpp `root-config --cflags --glibs`
