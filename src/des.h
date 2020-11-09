/**
 * Nick Wright
 * 040911884
 * CST8244
 */

#ifndef DOOR_ENTRY_SYSTEM_H_
#define DOOR_ENTRY_SYSTEM_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define NUM_STATES n	// where n = number of states in your finite state machine (FSM)
typedef enum {
	//TODO :: to see the list of //TODOS, Window > Show View > Tasks
	//TODO :: assign an enum value, one for each state
    LEFT_SCAN = 0,
    RIGHT_SCAN = 1,
    WEIGHT_SCALE = 2,
    LEFT_OPEN = 3,
    RIGHT_OPEN = 4,
    LEFT_CLOSED = 5,
    RIGHT_CLOSED = 6,
    GUARD_LEFT_UNLOCK = 7,
    GUARD_RIGHT_UNLOCK = 8,
    GUARD_LEFT_LOCK = 9,
    GUARD_RIGHT_LOCK = 10
} State;

#define NUM_INPUTS 12	// where n equals the number of input commands that drive the FSM.
			// From the assignment specification, notice the prompt. Each command, ls, rs, etc.

typedef enum {
	//TODO :: assign an enum value, one for each input command
	LS = 0,
	RS = 1,
	GLU = 2,
	GRU = 3,
	LO = 4,
	RO = 5,
	WS = 6,
	LC = 7,
	RC = 8,
	GLL = 9,
	GRL = 10,
	EXIT = 11,
} Input;

const char *inMessage[NUM_INPUTS] = {
	//TODO :: each input command. For example, "ls"
	"ls",
	"rs",
	"glu",
	"gru",
	"lo",
	"ro",
	"ws",
	"lc",
	"rc",
	"gll",
	"grl",
	"exit"
};

#define NUM_OUTPUTS 11	// where n equals the number of output messages from the FSM.
typedef enum {
	//TODO :: assign an enum value, one for each output message from the FSM
	PS = 0,
	GLU = 1,
	GRU = 2,
	LO = 3,
	RO = 4,
	PW = 5,
	LC = 6,
	RC = 7,
	GLL = 8,
	GRL = 9,
	EXIT = 10
} Output;

const char *outMessage[NUM_OUTPUTS] = {
	//TODO :: each output message. For example, "Person opened left door"
    "Person scanned ID, ID: =",
    "Guard left door unlocked.",
    "Guard right door unlocked.",
    "Person opened left door",
    "Person opened right door.",
    "Person weighed, weight =",
    "Left door closed",
    "Right door closed",
    "Guard left door locked.",
    "Guard right door locked.",
    "Exiting"
};

// inputs client sends a Person struct to its server, the controller
typedef struct {
	//TODO :: fields for person's ID (int), weight (int), direction (inbound or outbound),
	//	and some way to remember what state the Person is in. Suppose the Person in "Left Scan" state.
	//	You need a way to represent that.
} Person;

// controller client sends a Display struct to its server, the display
typedef struct {
	//TODO :: fields for the output message and the Person. For the output message, I used an int, which
	//	is the index into the outMessages array. That way I don't pass strings in my messages.
	//	The Person field is needed, as some output message require information from the Person.
	//	Specifically, those messages that display the Person's ID and weight.
} Display;

#endif /* DOOR_ENTRY_SYSTEM_H_ */
