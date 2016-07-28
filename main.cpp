//Number of automorphisms for stream of Sudoku subgrids/patterns
//last changed July 28, 2016
//Author: Mladen Dobrichev

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include "patminlex.h"

#include <memory.h>
int main() {
        char buf[2000];
        while(fgets(buf, sizeof(buf), stdin)) { //read a line of size up to 2000 symbols
        	buf[81] = '\t';
        	patminlex z(buf, &buf[82]); //read the sub-grid from the first 81 characters in the line and store its minlexed morph after the tab
        	//dump the result and all distinct backward transformations
        	char b[200];
        	for(int i = 0; i < 164; i++) b[i] = buf[i] ? 1 : 0;
            printf("%163.163s\t%d\n", buf, (int)z.theMaps.size());
            for(patminlex::mappers::iterator m = z.theMaps.begin(); m != z.theMaps.end(); m++) {
            	for(int i = 0; i < 81; i++)
            		printf("%2.2d ", (int)m->cell[i]);
           		printf(" ");
            	for(int i = 0; i < 10; i++)
            		printf("%d", (int)m->label[i]);
           		printf("\n");
           		for(int i = 0; i < 81; i++) { //debug backward mapping, should display the original
           			b[i] = m->cell[i] == 99 ? '.' : buf[82 + i] <= '9' && buf[82 + i] > 0 ? '0' + m->label[buf[82 + m->cell[i]] - '0'] : '*';
           		}
           		printf("%81.81s\n", b);
            }
        }
}

