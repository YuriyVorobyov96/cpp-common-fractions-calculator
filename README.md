How to build it w/out MS VS or smthg else?

Instal C++ compiler (GCC for example). Then run in terminal:
- g++ -c main.cpp
- g++ -c tests.cpp
- g++ -c rational.cpp
- g++ main.o tests.o rational.o -o my_program_cool_name

That's all!