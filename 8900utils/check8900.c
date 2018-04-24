#include <stdio.h>

int main(int argc, char* argv[]) {
	// Declare base variables
	FILE* file = fopen(argv[1], "rb");
	char buf[7];
	//89001.0

	// Read the first 7 bytes of the file
	fread(buf, 1, 7, file);

	if(buf[0] == '8' && buf[1] == '9' && buf[2] == '0' && buf[3] == '0' 
		&& buf[4] == '1' && buf[5] == '.' && buf[6] == '0') {
		return 0;
	} else {
		printf("check8900: error: No 8900 header found.\r\n");
		return 1;
	}
}