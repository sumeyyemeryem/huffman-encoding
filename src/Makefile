
Main: Main.o HufmanTree.o
    g++ Main.o HufmanTree.o -o Main

Main.o: Main.cpp
    g++ -c Main.cpp

HufmanTree.o: HufmanTree.h
    g++ -c HufmanTree.h

clean:
    rm *.o Main