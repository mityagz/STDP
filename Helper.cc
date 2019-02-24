#include "sock.h"
#include "Helper.h"
#include <string>


void itoa(int n,char *s) {
int i, sign;

if ((sign = n) < 0) 
   n = -n;    
i = 0;
do { 
   *(s + i++) = n % 10 + '0';
}   while ((n /=10) > 0);
if (sign < 0)
   *(s + i++) = '-';
*(s + i) = '\0';
reverse(s);
}




void reverse(char *s) {  
 int c, i, j;
 	for(i = 0, j = strlen(s) - 1; i < j; i++, j--)  {
    		c = *(s + i);
    		*(s + i) = *(s + j);
    		*(s + j) = c;
 	}
}

 int hex2int(string s) {
        	int i=0;
                for (int j=0;j<s.length();j++) {
                	switch (s.at(j)) {
                        case '0': { i=i*16; break; }
                        case '1': { i=i*16+1; break; }
                        case '2': { i=i*16+2; break; }
                        case '3': { i=i*16+3; break; }
                        case '4': { i=i*16+4; break; }
                        case '5': { i=i*16+5; break; }
                        case '6': { i=i*16+6; break; }
                        case '7': { i=i*16+7; break; }
                        case '8': { i=i*16+8; break; }
                        case '9': { i=i*16+9; break; }
                        case 'A': { i=i*16+10; break; }
                        case 'B': { i=i*16+11; break; }
                        case 'C': { i=i*16+12; break; }
                        case 'D': { i=i*16+13; break; }
                        case 'E': { i=i*16+14; break; }
                        case 'F': { i=i*16+15; break; }
                        case 'a': { i=i*16+10; break; }
                        case 'b': { i=i*16+11; break; }
                        case 'c': { i=i*16+12; break; }
                        case 'd': { i=i*16+13; break; }
                        case 'e': { i=i*16+14; break; }
                        case 'f': { i=i*16+15; break; }
                        }
                }
                return i;
        }

long hex2long(string s) {
        	long i=0;
                for (int j=0;j<s.length();j++) {
                	switch (s.at(j)) {
                        case '0': { i=i*16; break; }
                        case '1': { i=i*16+1; break; }
                        case '2': { i=i*16+2; break; }
                        case '3': { i=i*16+3; break; }
                        case '4': { i=i*16+4; break; }
                        case '5': { i=i*16+5; break; }
                        case '6': { i=i*16+6; break; }
                        case '7': { i=i*16+7; break; }
                        case '8': { i=i*16+8; break; }
                        case '9': { i=i*16+9; break; }
                        case 'A': { i=i*16+10; break; }
                        case 'B': { i=i*16+11; break; }
                        case 'C': { i=i*16+12; break; }
                        case 'D': { i=i*16+13; break; }
                        case 'E': { i=i*16+14; break; }
                        case 'F': { i=i*16+15; break; }
                        case 'a': { i=i*16+10; break; }
                        case 'b': { i=i*16+11; break; }
                        case 'c': { i=i*16+12; break; }
                        case 'd': { i=i*16+13; break; }
                        case 'e': { i=i*16+14; break; }
                        case 'f': { i=i*16+15; break; }
                        }
                }
                return i;
        }

int mod(int i, int j) {
	    return i % j;
	}
/*	
 int div(int i, int j) {
	    int k=mod(i,j);
	    i=i-k;
	    return (int)(i/j);
	}	

	
string int2hex(int i) {
	    if (i<0) { i=i+256; }
	    string iret="";
	    while (i>0) {
		switch (mod(i,16)) {
		case 0: { iret="0"+iret; break; }
		case 1: { iret="1"+iret; break; }
		case 2: { iret="2"+iret; break; }
		case 3: { iret="3"+iret; break; }
		case 4: { iret="4"+iret; break; }
		case 5: { iret="5"+iret; break; }
		case 6: { iret="6"+iret; break; }
		case 7: { iret="7"+iret; break; }
		case 8: { iret="8"+iret; break; }
		case 9: { iret="9"+iret; break; }
		case 10: { iret="A"+iret; break; }
		case 11: { iret="B"+iret; break; }
		case 12: { iret="C"+iret; break; }
		case 13: { iret="D"+iret; break; }
		case 14: { iret="E"+iret; break; }
		case 15: { iret="F"+iret; break; }
		}
		i=div(i,16);
	    }
	    return iret;
	}
	
*/

string upBytes(string b) {
	    for (int i=0;i<b.length();i++) {
		switch (b[i]) {
		case (char)(0xC1): { b[i]=(char)(0xE1); break; }
		case (char)(0xC2): { b[i]=(char)(0xE2); break; }
		case (char)(0xD7): { b[i]=(char)(0xF7); break; }
		case (char)(0xC7): { b[i]=(char)(0xE7); break; }
		case (char)(0xC5): { b[i]=(char)(0xE5); break; }
		case (char)(0xA3): { b[i]=(char)(0xB3); break; }
		case (char)(0xD6): { b[i]=(char)(0xF6); break; }
		case (char)(0xDA): { b[i]=(char)(0xFA); break; }
		case (char)(0xC9): { b[i]=(char)(0xE9); break; }
		case (char)(0xCB): { b[i]=(char)(0xEB); break; }
		case (char)(0xCC): { b[i]=(char)(0xEC); break; }
		case (char)(0xCD): { b[i]=(char)(0xED); break; }
		case (char)(0xCE): { b[i]=(char)(0xEE); break; }
		case (char)(0xCF): { b[i]=(char)(0xEF); break; }
		case (char)(0xD0): { b[i]=(char)(0xF0); break; }
		case (char)(0xD2): { b[i]=(char)(0xF2); break; }
		case (char)(0xD3): { b[i]=(char)(0xF3); break; }
		case (char)(0xD4): { b[i]=(char)(0xF4); break; }
		case (char)(0xD5): { b[i]=(char)(0xF5); break; }
		case (char)(0xC6): { b[i]=(char)(0xE6); break; }
		case (char)(0xC8): { b[i]=(char)(0xE8); break; }
		case (char)(0xC3): { b[i]=(char)(0xE3); break; }
		case (char)(0xDE): { b[i]=(char)(0xFE); break; }
		case (char)(0xDB): { b[i]=(char)(0xFB); break; }
		case (char)(0xDD): { b[i]=(char)(0xFD); break; }
		case (char)(0xDF): { b[i]=(char)(0xFF); break; }
		case (char)(0xD9): { b[i]=(char)(0xF9); break; }
		case (char)(0xD8): { b[i]=(char)(0xF8); break; }
		case (char)(0xDC): { b[i]=(char)(0xFC); break; }
		case (char)(0xC0): { b[i]=(char)(0xE0); break; }
		case (char)(0xD1): { b[i]=(char)(0xF1); break; }
		case (char)(0xCA): { b[i]=(char)(0xEA); break; }
		case (char)(0xC4): { b[i]=(char)(0xE4); break; }
		}
	    }
	    return b;
	}


string fromdkoi(string src) {
for (int i=0;i<src.length();i++) 
{		switch (src[i]) {

		
		case (char)0x25: { src[i]=(char)0x0A; break; }
		case (char)0x0D: { src[i]=(char)0x00; break; }
		case (char)0xF1: { src[i]=(char)'1'; break; }
		case (char)0xF2: { src[i]=(char)'2'; break; }
		case (char)0xF3: { src[i]=(char)'3'; break; }
		case (char)0xF4: { src[i]=(char)'4'; break; }
		case (char)0xF5: { src[i]=(char)'5'; break; }
		case (char)0xF6: { src[i]=(char)'6'; break; }
		case (char)0xF7: { src[i]=(char)'7'; break; }
		case (char)0xF8: { src[i]=(char)'8'; break; }
		case (char)0xF9: { src[i]=(char)'9'; break; }
		case (char)0xF0: { src[i]=(char)'0'; break; }
		case (char)0x98: { src[i]=(char)'q'; break; }
		case (char)0xA6: { src[i]=(char)'w'; break; }
		case (char)0x85: { src[i]=(char)'e'; break; }
		case (char)0x99: { src[i]=(char)'r'; break; }
		case (char)0xA3: { src[i]=(char)'t'; break; }
		case (char)0xA8: { src[i]=(char)'y'; break; }
		case (char)0xA4: { src[i]=(char)'u'; break; }
		case (char)0x89: { src[i]=(char)'i'; break; }
		case (char)0x96: { src[i]=(char)'o'; break; }
		case (char)0x97: { src[i]=(char)'p'; break; }
		case (char)0x81: { src[i]=(char)'a'; break; }
		case (char)0xA2: { src[i]=(char)'s'; break; }
		case (char)0x84: { src[i]=(char)'d'; break; }
		case (char)0x86: { src[i]=(char)'f'; break; }
		case (char)0x87: { src[i]=(char)'g'; break; }
		case (char)0x88: { src[i]=(char)'h'; break; }
		case (char)0x91: { src[i]=(char)'j'; break; }
		case (char)0x92: { src[i]=(char)'k'; break; }
		case (char)0x93: { src[i]=(char)'l'; break; }
		case (char)0xA9: { src[i]=(char)'z'; break; }
		case (char)0xA7: { src[i]=(char)'x'; break; }
		case (char)0x83: { src[i]=(char)'c'; break; }
		case (char)0xA5: { src[i]=(char)'v'; break; }
		case (char)0x82: { src[i]=(char)'b'; break; }
		case (char)0x95: { src[i]=(char)'n'; break; }
		case (char)0x94: { src[i]=(char)'m'; break; }
		case (char)0xD8: { src[i]=(char)'Q'; break; }
		case (char)0xE6: { src[i]=(char)'W'; break; }
		case (char)0xC5: { src[i]=(char)'E'; break; }
		case (char)0xD9: { src[i]=(char)'R'; break; }
		case (char)0xE3: { src[i]=(char)'T'; break; }
		case (char)0xE8: { src[i]=(char)'Y'; break; }
		case (char)0xE4: { src[i]=(char)'U'; break; }
		case (char)0xC9: { src[i]=(char)'I'; break; }
		case (char)0xD6: { src[i]=(char)'O'; break; }
		case (char)0xD7: { src[i]=(char)'P'; break; }
		case (char)0xC1: { src[i]=(char)'A'; break; }
		case (char)0xE2: { src[i]=(char)'S'; break; }
		case (char)0xC4: { src[i]=(char)'D'; break; }
		case (char)0xC6: { src[i]=(char)'F'; break; }
		case (char)0xC7: { src[i]=(char)'G'; break; }
		case (char)0xC8: { src[i]=(char)'H'; break; }
		case (char)0xD1: { src[i]=(char)'J'; break; }
		case (char)0xD2: { src[i]=(char)'K'; break; }
		case (char)0xD3: { src[i]=(char)'L'; break; }
		case (char)0xE9: { src[i]=(char)'Z'; break; }
		case (char)0xE7: { src[i]=(char)'X'; break; }
		case (char)0xC3: { src[i]=(char)'C'; break; }
		case (char)0xE5: { src[i]=(char)'V'; break; }
		case (char)0xC2: { src[i]=(char)'B'; break; }
		case (char)0xD5: { src[i]=(char)'N'; break; }
		case (char)0xD4: { src[i]=(char)'M'; break; }
		case (char)0x4F: { src[i]=(char)'!'; break; }
		case (char)0x7C: { src[i]=(char)'@'; break; }
		case (char)0x7B: { src[i]=(char)'#'; break; }
		case (char)0x5B: { src[i]=(char)'$'; break; }
		case (char)0x6C: { src[i]=(char)'%'; break; }
		case (char)0x5F: { src[i]=(char)'^'; break; }
		case (char)0x50: { src[i]=(char)'&'; break; }
		case (char)0x5C: { src[i]=(char)'*'; break; }
		case (char)0x4D: { src[i]=(char)'('; break; }
		case (char)0x5D: { src[i]=(char)')'; break; }
		case (char)0x60: { src[i]=(char)'-'; break; }
		case (char)0x6D: { src[i]=(char)'_'; break; }
		case (char)0x7E: { src[i]=(char)'='; break; }
		case (char)0x4E: { src[i]=(char)'+'; break; }
		case (char)0xE0: { src[i]=(char)'\\'; break; }
		case (char)0x6A: { src[i]=(char)'|'; break; }
		case (char)0x79: { src[i]=(char)'`'; break; }
		case (char)0xA1: { src[i]=(char)'~'; break; }
		case (char)0x4A: { src[i]=(char)'['; break; }
		case (char)0xC0: { src[i]=(char)'{'; break; }
		case (char)0x5A: { src[i]=(char)']'; break; }
		case (char)0xD0: { src[i]=(char)'}'; break; }
		case (char)0x5E: { src[i]=(char)';'; break; }
		case (char)0x7F: { src[i]=(char)'"'; break; }
		case (char)0x7D: { src[i]=(char)'\''; break; }
		case (char)0x4C: { src[i]=(char)'<'; break; }
		case (char)0x6B: { src[i]=(char)','; break; }
		case (char)0x6E: { src[i]=(char)'>'; break; }
		case (char)0x4B: { src[i]=(char)'.'; break; }
		case (char)0x61: { src[i]=(char)'/'; break; }
		case (char)0x6F: { src[i]=(char)'?'; break; }
		case (char)0x90: { src[i]=(char)0xCA; break; }
		case (char)0x80: { src[i]=(char)0xC3; break; }
		case (char)0xAD: { src[i]=(char)0xD5; break; }
		case (char)0x9A: { src[i]=(char)0xCB; break; }
		case (char)0x8B: { src[i]=(char)0xC5; break; }
		case (char)0x9D: { src[i]=(char)0xCE; break; }
		case (char)0x8D: { src[i]=(char)0xC7; break; }
		case (char)0xB3: { src[i]=(char)0xDB; break; }
		case (char)0xB5: { src[i]=(char)0xDD; break; }
		case (char)0xB2: { src[i]=(char)0xDA; break; }
		case (char)0x8E: { src[i]=(char)0xC8; break; }
		case (char)0xB7: { src[i]=(char)0xDF; break; }
		case (char)0x8C: { src[i]=(char)0xC6; break; }
		case (char)0xB1: { src[i]=(char)0xD9; break; }
		case (char)0xAF: { src[i]=(char)0xD7; break; }
		case (char)0x77: { src[i]=(char)0xC1; break; }
		case (char)0x9F: { src[i]=(char)0xD0; break; }
		case (char)0xAA: { src[i]=(char)0xD2; break; }
		case (char)0x9E: { src[i]=(char)0xCF; break; }
		case (char)0x9B: { src[i]=(char)0xCC; break; }
		case (char)0x8A: { src[i]=(char)0xC4; break; }
		case (char)0xAE: { src[i]=(char)0xD6; break; }
		case (char)0xB4: { src[i]=(char)0xDC; break; }
		case (char)0xA0: { src[i]=(char)0xD1; break; }
		case (char)0xB6: { src[i]=(char)0xDE; break; }
		case (char)0xAB: { src[i]=(char)0xD3; break; }
		case (char)0x9C: { src[i]=(char)0xCD; break; }
		case (char)0x8F: { src[i]=(char)0xC9; break; }
		case (char)0xAC: { src[i]=(char)0xD4; break; }
		case (char)0xB0: { src[i]=(char)0xD8; break; }
		case (char)0x78: { src[i]=(char)0xC2; break; }
		case (char)0x76: { src[i]=(char)0xC0; break; }
		case (char)0xCC: { src[i]=(char)0xEA; break; }
		case (char)0xBB: { src[i]=(char)0xE3; break; }
		case (char)0xEB: { src[i]=(char)0xF5; break; }
		case (char)0xCD: { src[i]=(char)0xEB; break; }
		case (char)0xBD: { src[i]=(char)0xE5; break; }
		case (char)0xDA: { src[i]=(char)0xEE; break; }
		case (char)0xBF: { src[i]=(char)0xE7; break; }
		case (char)0xFB: { src[i]=(char)0xFB; break; }
		case (char)0xFD: { src[i]=(char)0xFD; break; }
		case (char)0xFA: { src[i]=(char)0xFA; break; }
		case (char)0xCA: { src[i]=(char)0xE8; break; }
		case (char)0x57: { src[i]=(char)0xFF; break; }
		case (char)0xBE: { src[i]=(char)0xE6; break; }
		case (char)0xEF: { src[i]=(char)0xF9; break; }
		case (char)0xED: { src[i]=(char)0xF7; break; }
		case (char)0xB9: { src[i]=(char)0xE1; break; }
		case (char)0xDC: { src[i]=(char)0xF0; break; }
		case (char)0xDE: { src[i]=(char)0xF2; break; }
		case (char)0xDB: { src[i]=(char)0xEF; break; }
		case (char)0xCE: { src[i]=(char)0xEC; break; }
		case (char)0xBC: { src[i]=(char)0xE4; break; }
		case (char)0xEC: { src[i]=(char)0xF6; break; }
		case (char)0xFC: { src[i]=(char)0xFC; break; }
		case (char)0xDD: { src[i]=(char)0xF1; break; }
		case (char)0xFE: { src[i]=(char)0xFE; break; }
		case (char)0xDF: { src[i]=(char)0xF3; break; }
		case (char)0xCF: { src[i]=(char)0xED; break; }
		case (char)0xCB: { src[i]=(char)0xE9; break; }
		case (char)0xEA: { src[i]=(char)0xF4; break; }
		case (char)0xEE: { src[i]=(char)0xF8; break; }
		case (char)0xBA: { src[i]=(char)0xE2; break; }
		case (char)0xB8: { src[i]=(char)0xE0; break; }
		case (char)0x7A: { src[i]=(char)':'; break; }
		case (char)'@':    { src[i]=(char)(0x20); break; }
		}
	    }
	    return src;
	}

	string todkoi(string src) {
	    src=upBytes(src);
	    for (int i=0;i<src.length();i++) {

		//translit
		switch (src[i]) {
		case (char)0xe1: { src[i]=(char)'A'; break; }
		case (char)0xf7: { src[i]=(char)'B'; break; }
		case (char)0xf3: { src[i]=(char)'C'; break; }
		case (char)0xe5: { src[i]=(char)'E'; break; }
		case (char)0xee: { src[i]=(char)'H'; break; }
		case (char)0xeb: { src[i]=(char)'K'; break; }
		case (char)0xed: { src[i]=(char)'M'; break; }
		case (char)0xef: { src[i]=(char)'O'; break; }
		case (char)0xf2: { src[i]=(char)'P'; break; }
		case (char)0xf4: { src[i]=(char)'T'; break; }
		case (char)0xe8: { src[i]=(char)'X'; break; }
		}

		switch (src[i]) {

		case (char)0x0A: { src[i]=(char)0x25; break; }
		case (char)' ': { src[i]=(char)'@'; break; }
		case (char)'1': { src[i]=(char)0xF1; break; }
		case (char)'2': { src[i]=(char)0xF2; break; }
		case (char)'3': { src[i]=(char)0xF3; break; }
		case (char)'4': { src[i]=(char)0xF4; break; }
		case (char)'5': { src[i]=(char)0xF5; break; }
		case (char)'6': { src[i]=(char)0xF6; break; }
		case (char)'7': { src[i]=(char)0xF7; break; }
		case (char)'8': { src[i]=(char)0xF8; break; }
		case (char)'9': { src[i]=(char)0xF9; break; }
		case (char)'0': { src[i]=(char)0xF0; break; }
		case (char)'q': { src[i]=(char)0x98; break; }
		case (char)'w': { src[i]=(char)0xA6; break; }
		case (char)'e': { src[i]=(char)0x85; break; }
		case (char)'r': { src[i]=(char)0x99; break; }
		case (char)'t': { src[i]=(char)0xA3; break; }
		case (char)'y': { src[i]=(char)0xA8; break; }
		case (char)'u': { src[i]=(char)0xA4; break; }
		case (char)'i': { src[i]=(char)0x89; break; }
		case (char)'o': { src[i]=(char)0x96; break; }
		case (char)'p': { src[i]=(char)0x97; break; }
		case (char)'a': { src[i]=(char)0x81; break; }
		case (char)'s': { src[i]=(char)0xA2; break; }
		case (char)'d': { src[i]=(char)0x84; break; }
		case (char)'f': { src[i]=(char)0x86; break; }
		case (char)'g': { src[i]=(char)0x87; break; }
		case (char)'h': { src[i]=(char)0x88; break; }
		case (char)'j': { src[i]=(char)0x91; break; }
		case (char)'k': { src[i]=(char)0x92; break; }
		case (char)'l': { src[i]=(char)0x93; break; }
		case (char)'z': { src[i]=(char)0xA9; break; }
		case (char)'x': { src[i]=(char)0xA7; break; }
		case (char)'c': { src[i]=(char)0x83; break; }
		case (char)'v': { src[i]=(char)0xA5; break; }
		case (char)'b': { src[i]=(char)0x82; break; }
		case (char)'n': { src[i]=(char)0x95; break; }
		case (char)'m': { src[i]=(char)0x94; break; }
		case (char)'Q': { src[i]=(char)0xD8; break; }
		case (char)'W': { src[i]=(char)0xE6; break; }
		case (char)'E': { src[i]=(char)0xC5; break; }
		case (char)'R': { src[i]=(char)0xD9; break; }
		case (char)'T': { src[i]=(char)0xE3; break; }
		case (char)'Y': { src[i]=(char)0xE8; break; }
		case (char)'U': { src[i]=(char)0xE4; break; }
		case (char)'I': { src[i]=(char)0xC9; break; }
		case (char)'O': { src[i]=(char)0xD6; break; }
		case (char)'P': { src[i]=(char)0xD7; break; }
		case (char)'A': { src[i]=(char)0xC1; break; }
		case (char)'S': { src[i]=(char)0xE2; break; }
		case (char)'D': { src[i]=(char)0xC4; break; }
		case (char)'F': { src[i]=(char)0xC6; break; }
		case (char)'G': { src[i]=(char)0xC7; break; }
		case (char)'H': { src[i]=(char)0xC8; break; }
		case (char)'J': { src[i]=(char)0xD1; break; }
		case (char)'K': { src[i]=(char)0xD2; break; }
		case (char)'L': { src[i]=(char)0xD3; break; }
		case (char)'Z': { src[i]=(char)0xE9; break; }
		case (char)'X': { src[i]=(char)0xE7; break; }
		case (char)'C': { src[i]=(char)0xC3; break; }
		case (char)'V': { src[i]=(char)0xE5; break; }
		case (char)'B': { src[i]=(char)0xC2; break; }
		case (char)'N': { src[i]=(char)0xD5; break; }
		case (char)'M': { src[i]=(char)0xD4; break; }
		case (char)'!': { src[i]=(char)0x4F; break; }
		case (char)'@': { src[i]=(char)0x7C; break; }
		case (char)'#': { src[i]=(char)0x7B; break; }
		case (char)'$': { src[i]=(char)0x5B; break; }
		case (char)'%': { src[i]=(char)0x6C; break; }
		case (char)'^': { src[i]=(char)0x5F; break; }
		case (char)'&': { src[i]=(char)0x50; break; }
		case (char)'*': { src[i]=(char)0x5C; break; }
		case (char)'(': { src[i]=(char)0x4D; break; }
		case (char)')': { src[i]=(char)0x5D; break; }
		case (char)'-': { src[i]=(char)0x60; break; }
		case (char)'_': { src[i]=(char)0x6D; break; }
		case (char)'=': { src[i]=(char)0x7E; break; }
		case (char)'+': { src[i]=(char)0x4E; break; }
		case (char)'\\': { src[i]=(char)0xE0; break; }
		case (char)'|': { src[i]=(char)0x6A; break; }
		case (char)'`': { src[i]=(char)0x79; break; }
		case (char)'~': { src[i]=(char)0xA1; break; }
		case (char)'[': { src[i]=(char)0x4A; break; }
		case (char)'{': { src[i]=(char)0xC0; break; }
		case (char)']': { src[i]=(char)0x5A; break; }
		case (char)'}': { src[i]=(char)0xD0; break; }
		case (char)':': { src[i]=(char)0x7A; break; }
		case (char)';': { src[i]=(char)0x5E; break; }
		case (char)'"': { src[i]=(char)0x7F; break; }
		case (char)'\'': { src[i]=(char)0x7D; break; }
		case (char)'<': { src[i]=(char)0x4C; break; }
		case (char)',': { src[i]=(char)0x6B; break; }
		case (char)'>': { src[i]=(char)0x6E; break; }
		case (char)'.': { src[i]=(char)0x4B; break; }
		case (char)'/': { src[i]=(char)0x61; break; }
		case (char)'?': { src[i]=(char)0x6F; break; }
		case (char)0xCA: { src[i]=(char)0x90; break; }
		case (char)0xC3: { src[i]=(char)0x80; break; }
		case (char)0xD5: { src[i]=(char)0xAD; break; }
		case (char)0xCB: { src[i]=(char)0x9A; break; }
		case (char)0xC5: { src[i]=(char)0x8B; break; }
		case (char)0xCE: { src[i]=(char)0x9D; break; }
		case (char)0xC7: { src[i]=(char)0x8D; break; }
		case (char)0xDB: { src[i]=(char)0xB3; break; }
		case (char)0xDD: { src[i]=(char)0xB5; break; }
		case (char)0xDA: { src[i]=(char)0xB2; break; }
		case (char)0xC8: { src[i]=(char)0x8E; break; }
		case (char)0xDF: { src[i]=(char)0xB7; break; }
		case (char)0xC6: { src[i]=(char)0x8C; break; }
		case (char)0xD9: { src[i]=(char)0xB1; break; }
		case (char)0xD7: { src[i]=(char)0xAF; break; }
		case (char)0xC1: { src[i]=(char)0x77; break; }
		case (char)0xD0: { src[i]=(char)0x9F; break; }
		case (char)0xD2: { src[i]=(char)0xAA; break; }
		case (char)0xCF: { src[i]=(char)0x9E; break; }
		case (char)0xCC: { src[i]=(char)0x9B; break; }
		case (char)0xC4: { src[i]=(char)0x8A; break; }
		case (char)0xD6: { src[i]=(char)0xAE; break; }
		case (char)0xDC: { src[i]=(char)0xB4; break; }
		case (char)0xD1: { src[i]=(char)0xA0; break; }
		case (char)0xDE: { src[i]=(char)0xB6; break; }
		case (char)0xD3: { src[i]=(char)0xAB; break; }
		case (char)0xCD: { src[i]=(char)0x9C; break; }
		case (char)0xC9: { src[i]=(char)0x8F; break; }
		case (char)0xD4: { src[i]=(char)0xAC; break; }
		case (char)0xD8: { src[i]=(char)0xB0; break; }
		case (char)0xC2: { src[i]=(char)0x78; break; }
		case (char)0xC0: { src[i]=(char)0x76; break; } /* * */
		case (char)0xEA: { src[i]=(char)0xCC; break; }
		case (char)0xE3: { src[i]=(char)0xBB; break; }
		case (char)0xF5: { src[i]=(char)0xEB; break; }
		case (char)0xEB: { src[i]=(char)0xCD; break; }
		case (char)0xE5: { src[i]=(char)0xBD; break; }
		case (char)0xEE: { src[i]=(char)0xDA; break; }
		case (char)0xE7: { src[i]=(char)0xBF; break; }
		case (char)0xFB: { src[i]=(char)0xFB; break; }
		case (char)0xFD: { src[i]=(char)0xFD; break; }
		case (char)0xFA: { src[i]=(char)0xFA; break; }
		case (char)0xE8: { src[i]=(char)0xCA; break; }
		case (char)0xFF: { src[i]=(char)0x57; break; }
		case (char)0xE6: { src[i]=(char)0xBE; break; }
		case (char)0xF9: { src[i]=(char)0xEF; break; }
		case (char)0xF7: { src[i]=(char)0xED; break; }
		case (char)0xE1: { src[i]=(char)0xB9; break; }
		case (char)0xF0: { src[i]=(char)0xDC; break; }
		case (char)0xF2: { src[i]=(char)0xDE; break; }
		case (char)0xEF: { src[i]=(char)0xDB; break; }
		case (char)0xEC: { src[i]=(char)0xCE; break; }
		case (char)0xE4: { src[i]=(char)0xBC; break; }
		case (char)0xF6: { src[i]=(char)0xEC; break; }
		case (char)0xFC: { src[i]=(char)0xFC; break; }
		case (char)0xF1: { src[i]=(char)0xDD; break; }
		case (char)0xFE: { src[i]=(char)0xFE; break; }
		case (char)0xF3: { src[i]=(char)0xDF; break; }
		case (char)0xED: { src[i]=(char)0xCF; break; }
		case (char)0xE9: { src[i]=(char)0xCB; break; }
		case (char)0xF4: { src[i]=(char)0xEA; break; }
		case (char)0xF8: { src[i]=(char)0xEE; break; }
		case (char)0xE2: { src[i]=(char)0xBA; break; }
		case (char)0xE0: { src[i]=(char)0xB8; break; }
		}
	    }
	    return src;
	}
	
