g++ mupa.cpp -o test.o -c
g++ test.o -o test.exe -lglu32 -lopengl32 -lfreeglut
test.exe