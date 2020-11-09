/**
 * Nick Wright & Kevin Luu
 * 040911884 & 040905303
 * CST8244
 */

#include "../../des_controller/src/des.h"

int main(void) {

	Display client_message;
	Display response;
	int rcvid;
	int chid;

	//Call ChannelCreate() to create a channel for the controller process to attach
	chid = ChannelCreate(0);
	//On Failure: print error message and EXIT_FAILURE
	if (chid == -1) {
		fprintf(stderr, "ChannelCreate failure.\n");
		exit(EXIT_FAILURE);
	}
	//Print display's PID; controller needs to know this PID

	printf("display's PID is %d\tAnd the Channel ID (chid) is: %d\n", getpid(),
			chid);

	while( TRUE ) {

		//Call MsgReceive() to receive Display object from controller
		rcvid = MsgReceive(chid, &client_message, sizeof(client_message), NULL);
		if (rcvid == -1) {
			fprintf(stderr, "MsgReceive error.\n");
			exit(EXIT_FAILURE);
		}

		//Call MsgReply(), sending EOK back to the controller
		MsgReply(rcvid, EOK, &response, sizeof(response));

		//IF message == ID_SCAN THEN
		if (client_message.message == Output.ID_SCAN){
			//Print person has been scanned entering (or leaving)
			//the building and display the person's ID
		}
		//ELSE IF message = WEIGHED THEN
		else if (client_message.message == Output.WEIGHED){
			//Print person has been weighed and their weight
		}
		//ELSE // regular message
		else if (client_message.message != Output.EXIT){
			//Print message to Neutrino console (i.e. stdout)
		}
		else {
			//IF message == EXIT THEN
			//break out of while loop
			break;
		}

	}

	//PHASE III
	//Call ChannelDestroy() to destroy the channel that controller attaches to
	ChannelDestroy(chid);
	exit(EXIT_SUCESS);

}
