NAME=inherited_thread_class

g++ -pthread -o $NAME.ex $NAME.cpp && ./$NAME.ex

rm $NAME.ex