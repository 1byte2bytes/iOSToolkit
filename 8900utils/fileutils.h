#include <sys/stat.h>
#include <unistd.h>

inline int is_sane_file(char* filename) {
	// Check if file exists
	if( access(filename, F_OK) == -1 ) {
		fprintf(stderr, "check8900: error: file inaccessible or non-existant.\r\n");
		return -3;
	}

	// Check that we haven't gotten a folder passed to us
	struct stat sb;
	if (stat(filename, &sb) == 0 && S_ISDIR(sb.st_mode)) {
		fprintf(stderr, "check8900: error: folder was passed, not file.\r\n");
		return -4;
	}

	return 0;
}