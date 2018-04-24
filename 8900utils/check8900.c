#include <stdio.h>
#include <stdlib.h>

#include "fileutils.h"

int main(int argc, char* argv[]) {
	// Verify correct number of args is passed
	if(argc != 2) {
		fprintf(stderr, "check8900: error: incorrect arguments passed.\r\n");
		return -2;
	}

	// Check that the input file is sane
	int r = is_sane_file(argv[1]);
	if(r != 0){
		return r;
	}

	// Declare base variables
	FILE* file = fopen(argv[1], "rb");
	char buf[7];

	// Read the first 7 bytes of the file
	fread(buf, 1, 7, file);

	if(buf[0] == '8' && buf[1] == '9' && buf[2] == '0' && buf[3] == '0' 
		&& buf[4] == '1' && buf[5] == '.' && buf[6] == '0') {
		return 0;
	} else {
		fprintf(stderr, "check8900: error: No 8900 header found.\r\n");
		return -1;
	}
}