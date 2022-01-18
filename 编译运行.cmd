g++ -fexec-charset=GBK Randomer.cpp -c
g++ -fexec-charset=GBK Generator.cpp -c
g++ -fexec-charset=GBK ConsoleShow.cpp -c
g++ -fexec-charset=GBK Scorer.cpp -c
g++ -fexec-charset=GBK main.cpp -c
g++ main.o Randomer.o Generator.o ConsoleShow.o Scorer.o -o student
del main.o Randomer.o Generator.o ConsoleShow.o Scorer.o
echo 编译完成，按任意键运行
pause
start student.exe