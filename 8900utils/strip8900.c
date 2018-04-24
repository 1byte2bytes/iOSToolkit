#include <stdio.h>
#include <stdlib.h>

#include "fileutils.h"

int main(int argc, char* argv[]) {
	// Verify correct number of args is passed
	if(argc != 3) {
		fprintf(stderr, "check8900: error: incorrect arguments passed.\r\n");
		return -2;
	}

	// Check that the input file is sane
	int r = is_sane_file(argv[1]);
	if(r != 0){
		return r;
	}

	// Check that the other input file doesn't exist
	r = file_exists(argv[2]);
	if(r == 0) {
		fprintf(stderr, "check8900: error: output file already exists.\r\n");
		return -3;
	}

	// Declare base variables
	FILE* in_file = fopen(argv[1], "rb");
	FILE* out_file = fopen(argv[2], "wb");
	char buf[2048];

	// Skip the first 2048 bytes, the size of the 8900 header
	fread(buf, 1, 2048, in_file);

	// Continually read and write the file
	while(1 == 1) {
		int count = fread(&buf, 1, sizeof(buf), in_file);
		if (count < 1) {
			break;
		}

		if (fwrite(&buf, sizeof(char), count, out_file) < 1) {
			fprintf(stderr, "emojiencoder: failed to write (1)");
			return -1;
		}
	}
}