all:
	rootcint -f Dict.cpp -c DoubleFitter.h LinkDef.h
	g++ -o fit fit.cpp DoubleFitter.cxx Dict.cpp `root-config --cflags --glibs`
