/**
 * Nick Wright
 * 040911884
 * CST8244
 */

#include "des.h"

int main(void) {

	client_sent_t msg_send;
	server_response_t msg_receive;
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

		//Print person has been scanned entering (or leaving) the building and display the person's ID

		//ELSE IF message = WEIGHED THEN

		//Print person has been weighed and their weight

		//ELSE // regular message

		//Print message to Neutrino console (i.e. stdout)

		//IF message == EXIT THEN

		//break out of while loop

	}


	//Call ChannelDestroy() to destroy the channel that controller attaches to
	ChannelDestroy();
	exit(EXIT_SUCESS);

}
