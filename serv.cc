#include <string>
#include <sys/types.h>
#include <sys/unistd.h>
#include <locale.h>
#include <vector>
#include "sock.h"
#include "Helper.h"

sock sp;

string aoSTDS = "(11 8000 5)00";
string aoSTDC = "(11 8004 7)15";
string STDB   = "STDP";


string QUERY = "STDP06700000013058000(11 8004 7)15(11 8000 5)0000000013022816474300(:444 2 407:)";
int flag = 0;


string init_type = "03";
string init_size_header = "048";
string init_size_body = "00000000";
string init_max_message = "001";
string init_ctrl = "80";

int header_size = 15;


//map<int, string, compare>INB;
//map<int, string>READY;
//map<int, string>OUTB;

string inb = "";
string inbt = "";
string outb = "";
//char * ready[65535];
int 	 tail_ready = 0;

vector<string>ready(1000);

void stdpParse(void);
void stdpReady(void);

main(int argc, char *argv[]) {
	setlocale(LC_ALL,"ru_RU.KOI8-R");
	char *host = argv[1];
	int port = -1, rc, ret; 
	char *local_port = (char *)malloc(5 * sizeof(char));
	char *sock_std = (char *)malloc(20 * sizeof(char));
	char *local_host; 

	fd_set select_set_read;
	fd_set select_set_write;
   	struct timeval timeRec;	
	int f_dom;
	int rval;
	string init_state = "STDP050";
	string test_state = "STDP045";
	string answer;
	string state;
	sscanf(argv[2], "%d", &port), rc;
	char buf_head[65535],  socknm[80];


	sock sp(port != -1 ? AF_INET : AF_UNIX, SOCK_STREAM);

	if(!sp.good()) return 1;
	if(sp.connect(host, port) < 0) return 8;
	fcntl(sp.fd(), F_SETFL, O_NONBLOCK);

	local_host = sp.get_local_addr();
	itoa(sp.get_local_port(), local_port);
	cout <<  "local socket: " << local_host << ":" << local_port << endl;
	
	//connection established
		string std_init = STDB + init_size_header + init_size_body + init_type +  aoSTDC + aoSTDS + init_max_message + init_ctrl;
		if(sp.write(todkoi(std_init).c_str(), strlen(todkoi(std_init).c_str())) < 0) return 10;
		cout << "sends init\n" << std_init << endl;
	
	f_dom = sp.fd();
	timeRec.tv_sec = 5;
      	timeRec.tv_usec = 0;
      	FD_ZERO(&select_set_read);
      	FD_SET(f_dom, &select_set_read);
	//receives message and allocates INB && READY
	while(sp.good()){
		rc = select(10, &select_set_read, NULL, NULL, &timeRec);
			if(rc > 0) { 
				do {
				bzero(buf_head, sizeof(buf_head));
              				if ((rval = sp.read(buf_head, sizeof(buf_head))) > 0) {
						inb = inb + buf_head;
              				}
              				else if (rval < 0) {
                				break;
              				}
            			} while (rval != 0); 
			  // EBCDIC -> koi
			  if(inb != "") {
				inb = fromdkoi(inb); 
				stdpParse();
			  }
			}
			if(tail_ready) {
				stdpReady();
				//cout << "Ready INB:" << inb << endl;
			if(flag == 0) {
				cout << "Trap111" << "flag" << flag << endl;
				outb = QUERY;	
				flag = 1;
			}
			}

			// koi -> EBCDIC 
				//cout << "Main: " << outb.c_str() << " Len: " << strlen(outb.c_str()) << endl;
				outb = todkoi(outb);


			// sends data
			if(outb != "") {
				//cout << "Main: " << outb.c_str() << " Len: " << strlen(outb.c_str()) << endl;
				if(sp.write(outb.c_str(), strlen(outb.c_str())) < 0) return 10;
				outb = "";
			}

	if(rval == 0){
		close(sp.fd()); sp.shutdown(); cout << "connection abort" << endl; exit(0);
	}
      		FD_SET(f_dom,&select_set_read);
	}
	sp.shutdown();
	exit(0);

}

/*
void stdpParse() {
int pos = 0, i = 0, stdp = 1;
int size_header = 0, size_body = 0;
	cout << inb << endl;	
	cout << "Trap" << endl;
	pos = inb.find(STDB);
	cout << "Position: " << pos << endl;
	cout << "Header: " << inb.substr(pos,header_size) << endl;
	for(i = pos + STDB.length(); i <= header_size - 1; i++){
		if(!isdigit(inb[i])){
			cout << inb[i] << "Non digit\n";
			break;
			stdp = 0;
		}
	}
	if(stdp){
		size_header = atoi(inb.substr(pos + 4, 3).c_str());
		size_body = atoi(inb.substr(pos + 8, 8).c_str());
	}
	ready = inb.substr(pos, size_header + size_body); 
	ready = inb;
	inb = "";
}
*/
