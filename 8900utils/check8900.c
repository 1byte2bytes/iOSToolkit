#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char* argv[]) {
	// Verify correct number of args is passed
	if(argc != 2) {
		printf("check8900: error: incorrect arguments passed.\r\n");
		return -1;
	}

	// Check if file exists
	if( access(argv[1], F_OK) == -1 ) {
		printf("check8900: error: file inaccessible or non-existant.\r\n");
		return -2;
	}

	// Check that we haven't gotten a folder passed to us
	struct stat statbuf;
	if (stat(argv[1], &statbuf) == 0) {
		printf("check8900: error: folder was passed, not file.\r\n");
		return -2;
	}
	free(&statbuf);

	// Declare base variables
	FILE* file = fopen(argv[1], "rb");
	char buf[7];

	// Read the first 7 bytes of the file
	fread(buf, 1, 7, file);

	if(buf[0] == '8' && buf[1] == '9' && buf[2] == '0' && buf[3] == '0' 
		&& buf[4] == '1' && buf[5] == '.' && buf[6] == '0') {
		return 0;
	} else {
		printf("check8900: error: No 8900 header found.\r\n");
		return 1;
	}

	free(&file);
	free(&buf);
}