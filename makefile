ifeq ($(OS),Windows_NT)
    exten := .exe
else
    exten := .out
endif

all :
	gcc -o Project_Prime$(exten) Project_Prime_1.c
