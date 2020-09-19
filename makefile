ifeq ($(OS),Windows_NT)
    exten := .exe
    lm :=
else
    exten := .out
    lm := -lm
endif

all :
	gcc -Ofast -o Project_Prime$(exten) Project_Prime_1.c $(lm)
	
