#########################################################
# File: Standard Makefile Template for 162
# Description: Makefile for Lab5
#########################################################

# CXX Compiler
CXX = g++

# CXXFLAGS compile flags.
# -std=c++0x Language Version 
CXXFLAGS = -std=c++0x

# -Wall turns on all warnings
CXXFLAGS += -Wall

# -pedantic-errors strictly enforces the standard
CXXFLAGS += -pedantic-errors

# -g turns on debug information 
CXXFLAGS += -g

####################
###   Variables  ###
####################

# SRCS source files. 

SRC1 = main.cpp
SRC2 = ant.cpp
SRC3 = critter.cpp
SRC4 = doodleBug.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4}

# HEADERS is a standard name for the header files. 

HEADER1 =
HEADER2 = 
HEADER3 = 
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3}

# These will be your executable names. 
PROG1 = lab5
#PROG2 = 
#PROG3 = 
#PROGS = ${PROG1}# ${PROG2} ${PROG3}

# This is the name of your document(s). 
# Edit as needed.
#DOC = lab5Document.pdf

# Name of Compressed File
TAR = cs162_lab5_JamesSandoval.tar.bz2

#####################
### BUILD SECTION ###
#####################

# Typing 'make' in terminal calls the first build available.
# In this case, default.
default:
	${CXX} ${SRCS} -o lab5

# Typing 'make all' in terminal calls this build.
all:
	${CXX} ${CXXFLAGS} ${SRCS} ${HEADERS} -o ${PROG1}

# Typing 'make tar' in terminal calls this build.
# This creates a compressed file for submission.
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOC} makefile

# Typing 'make clean' calls this build.
# It's designed to clean up the folder.
# Be careful with this, edit as needed.
clean: 
	rm -f ${PROGS} *.o *~

