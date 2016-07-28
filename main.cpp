//Canonicalization, Number of automorphisms, and reverse transformation for stream of Sudoku subgrids/patterns
//last changed July 28, 2016
//Author: Mladen Dobrichev

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include "patminlex.h"

#include <memory.h>
//int main1() {
//		//this is the old example. To make it working, make patminlex struct (instead of class, to make all members public) and change i/o back to ASCII
//        char buf[2000];
//        while(fgets(buf, sizeof(buf), stdin)) { //read a line of size up to 2000 symbols
//        	buf[81] = '\t';
//        	patminlex z(buf, &buf[82]); //read the sub-grid from the first 81 characters in the line and store its minlexed morph after the tab
//        	//dump the result and all distinct backward transformations
//        	char b[200];
//            printf("%163.163s\t%d\n", buf, (int)z.theMaps.size());
//            for(patminlex::mappers::iterator m = z.theMaps.begin(); m != z.theMaps.end(); m++) {
//            	for(int i = 0; i < 81; i++)
//            		printf("%2.2d ", (int)m->cell[i]);
//           		printf(" ");
//            	for(int i = 0; i < 10; i++)
//            		printf("%d", (int)m->label[i]);
//           		printf("\n");
//           		for(int i = 0; i < 81; i++) { //debug backward mapping, should display the original
//           			b[i] = m->cell[i] == 99 ? '.' : buf[82 + i] <= '9' && buf[82 + i] > 0 ? '0' + m->label[buf[82 + m->cell[i]] - '0'] : '*';
//           		}
//           		printf("%81.81s\n", b);
//            }
//        }
//}

int main() {
        char buf[2000];
        while(fgets(buf, sizeof(buf), stdin)) { //read a line of size up to 2000 symbols
         	char in[81];
         	char out[81];
         	char outs[81];
         	char back[81 * 200];
         	for(int i = 0; i < 81; i++) in[i] = buf[i] <= '9' && buf[i] > '0' ? buf[i] - '0' : 0;
        	patminlex z(in, out); //read the sub-grid from the first 81 characters in the line and store its minlexed morph after the tab
        	//dump the result and all distinct backward transformations
         	for(int i = 0; i < 81; i++) outs[i] = out[i] ? out[i] + '0' : '.';
            int automorphisms = z.size();
            printf("%81.81s\n%81.81s\t%d\n", buf, outs, automorphisms);
            if(automorphisms > 200) automorphisms = 200; //truncate to 200
            z.map(out, back); //map back the minlexed output to the original in the all possible ways. All lines should match the original.
            for(int n = 0; n < automorphisms; n++) {
            	for(int i = 0; i < 81; i++) outs[i] = back[81 * n + i] ? back[81 * n + i] + '0' : '.';
            	printf("%81.81s\n", outs);
            }
            printf("\n");
        }
}

