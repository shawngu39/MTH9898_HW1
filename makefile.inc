APPL_INCLUDES = -I./include -I./lib/include -I ./ext_lib/include
LIB_INCLUDES = -I../../include -I../../../ext_lib/include
CFLAGS = -Wall -g2 -std=c++11
ARCFLAGS = -cvq
CC = g++
ARC = ar
SRC = src
LIBS = -L./lib/libs -L./ext_lib/libs
BIN = ./bin
MAKE = make