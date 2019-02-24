#include "sock.h"
#include "Helper.h"

using namespace std;

extern string init_type;
extern string init_size_header;
extern string init_size_body;
extern string init_max_message;
extern string init_ctrl;
extern string STDB;
//extern string sp;
extern sock sp;


int initConn(string aos, string aoc){
//initConn(string aos, string aoc, sock si){
//STDP0480000000003(11 8004 7)15(11 8000 5)0001080

string std_init = STDB + init_size_header + init_size_body + init_type +  aoc + aos + init_max_message + init_ctrl;
if(sp.write(todkoi(std_init).c_str(), strlen(todkoi(std_init).c_str())) < 0) return 10;
//si.write(todkoi(std_init).c_str(), strlen(todkoi(std_init).c_str())); 
cout << "Отправлена ИЕ инит\n" << std_init << "\n";

return 0;

}
