#########################################################
# File: Standard Makefile Template for 162
# Description: Makefile for lab#3
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

SRC1 = Die.cpp
SRC2 = LoadedDie.cpp
SRC3 = gameplay.cpp
SRC4 = main.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3} ${SRC4}

# HEADERS is a standard name for the header files. 

HEADER1 =
HEADER2 =
HEADER3 =
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3}

# These will be your executable names. 
PROG1 = die
PROG2 = 
PROG3 = 
PROGS = ${PROG1}# ${PROG2} ${PROG3}

# This is the name of your document(s). 
# Edit as needed.
#DOC = lab3document.pdf

# Name of Compressed File
TAR = lab3.tar.bz2

#####################
### BUILD SECTION ###
#####################

# Typing 'make' in terminal calls the first build available.
# In this case, default.
default:
	${CXX} ${SRCS}${HEADERS} -o lab3

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

