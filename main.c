/*
 *        Project:  hlt2lb
 *       Filename:  main.c
 *
 *    Description:  Converts herbstluftwm tag_status to lemonbar
 *
 *        Version:  0.1a
 *        Created:  2021-09-10 23:08
 *       Compiler:  gcc
 *
 *         Author:  Ian D. Brunton (idb), iandbrunton at gmail .com
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define TAGSTATUS "herbstclient tag_status"
#define EMPTY_TAG "%%{A:herbstclient use %c:} %c %%{A}"
#define OCCUPIED_TAG "%%{A:herbstclient use %c:} %%{+o}%c%%{-o} %%{A}"
#define FOCUSED_TAG "%%{A:herbstclient use %c:}%%{R} %c %%{R}%%{A}"
#define URGENT_TAG "%%{A:herbstclient use %c:}%%{F%s} %c %%{F-}%%{A}"

int main (int argc, char *argv[]) {
	char *urgent = "#cd5666";
	char input [16];
	FILE *pp;

	pp = popen (TAGSTATUS, "r");
	if (pp == NULL) {
		printf ("Error opening stream\n");
		exit (1);
	}

	while (fscanf (pp, "%s", input) == 1) {
		switch (input[0]) {
			case '.':
				printf (EMPTY_TAG, input[1], input[1]);
				break;
			case ':':
				printf (OCCUPIED_TAG, input[1], input[1]);
				break;
			case '#':
				printf (FOCUSED_TAG, input[1], input[1]);
				break;
			case '!':
				printf (URGENT_TAG, input[1], urgent, input[1]);
				break;
		}
	}

	pclose (pp);

	return EXIT_SUCCESS;
}
