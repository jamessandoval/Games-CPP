#########################################################
# File: Standard Makefile Template for 162
# Description: Makefile for lab #9
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
SRC2 = buffer.cpp
SRC3 = palindrome.cpp
SRCS = ${SRC1} ${SRC2} ${SRC3}

# HEADERS is a standard name for the header files. 

HEADER1 = 
HEADER2 = 
HEADER3 = 
HEADERS = ${HEADER1} ${HEADER2} ${HEADER3}

# These will be your executable names. 
PROG1 = 
PROG2 = 
PROG3 = 
PROGS = ${PROG1}# ${PROG2} ${PROG3}

# This is the name of your document(s). 
# Edit as needed.
#DOC = lab9document.pdf

# Name of Compressed File
TAR = program2.tar.bz2

#####################
### BUILD SECTION ###
#####################

# Typing 'make' in terminal calls the first build available.
# In this case, default.
default:
	${CXX} ${SRCS} -o lab9

# Typing 'make all' in terminal calls this build.
all:
	${CXX} ${CXXFLAGS} ${SRCS} -o ${PROG1}

# Typing 'make tar' in terminal calls this build.
# This creates a compressed file for submission.
tar:
	tar cvjf ${TAR} ${SRCS} ${HEADERS} ${DOC} makefile

# Typing 'make clean' calls this build.
# It's designed to clean up the folder.
# Be careful with this, edit as needed.
clean: 
	rm -f ${PROGS} *.o *~

