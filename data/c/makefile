all: cwe787.exe

cwe787.exe: cwe787.o
	 gcc -o cwe787.exe cwe787.o

cwe787.o: cwe787.c
	 gcc -c cwe787.c

clean:
	 rm cwe787.o cwe787.exe


	 codeql database analyze vul-eval-codeql-c --format=sarif-latest --output=.