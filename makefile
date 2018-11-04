default: mkvmufs


mkvmufs.o: mkvmufs.c

        gcc -c mkvmufs.c -o mkvmufs.o


mkvmufs: mkvmufs.o

        gcc mkvmufs.o -o mkvmufs


clean:

        -rm -f mkvmufs.o

        -rm -f mkvmufs
