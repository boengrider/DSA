INCLUDE_DIR:=/include
SRC_DIR:=/src
RUN_DIR:=/run
C_DIR:=/C
ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
COMPILER=gcc

.PHONY: test

test:
	echo $(ROOT_DIR)$(INCLUDE_DIR)
	echo $(ROOT_DIR)$(SRC_DIR)
	echo $(ROOT_DIR)$(RUN_DIR)

anagram:
	$(COMPILER) -I$(ROOT_DIR)$(C_DIR)$(INCLUDE_DIR) $(ROOT_DIR)$(C_DIR)$(SRC_DIR)/anagram.c -o $(ROOT_DIR)$(C_DIR)$(RUN_DIR)/anagram
	$(ROOT_DIR)$(C_DIR)$(RUN_DIR)/anagram

clean:
	rm -f $(ROOT_DIR)$(C_DIR)$(SRC_DIR)/*.o

