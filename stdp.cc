#include <vector>
#include "Helper.h"
#include "sock.h"

using namespace std;

extern string inb;
extern string outb;
extern vector<string>ready;
extern string STDB; 
extern int header_size; 
extern int tail_ready; 

void stdpParse(void) {
int pos = 0, i = 0, stdp = 1;
int size_header = 0, size_body = 0;
//        	cout << "Принято stdpParse -> inb: " << inb << "LEN:" << inb.length() << endl;
//		cout << "Size Header " <<  atoi(inb.substr(pos + 4, 3).c_str()) << endl; 
//		cout << "Size Body " <<  atoi(inb.substr(pos + 7, 8).c_str()) << endl;
        while(((pos = inb.find(STDB)) >= 0)  && (inb.length() >= 
		((size_header = atoi(inb.substr(pos + 4, 3).c_str())) + 
		(size_body = atoi(inb.substr(pos + 7, 8).c_str()))))){
		ready[tail_ready++] = inb.substr(pos, size_header + size_body);
		inb = inb.replace(pos, size_header + size_body, "");

        	//cout << "Принято stdpParse -> inb: " << inb << "LEN:" << inb.length() << endl;

	}
		inb = todkoi(inb);
}



void stdpReady(void) {
int i;
string request, rest, msg;
int hLen, dLen, type;

int rc, cb, HOW;
string aFrom, aTo, aoList;

//int ctrl, attr;
string kns, KNS = "000000000000", len, attr, ctrl;
struct tm *timestamp_tm;
time_t t;
char *TKNS=(char *)malloc(12*sizeof(char));

	for(i = 0; i < tail_ready; i++) {
		request = ready[i];
		hLen = atoi(request.substr(4, 3).c_str());
		dLen = atoi(request.substr(7, 8).c_str());
		type = atoi(request.substr(15, 2).c_str());
		rest = request.substr(17, request.length());
		msg = request.substr(hLen, dLen);
		if(type == 4) {		//-- Ответ на запрос соединения  --
			aFrom = rest.substr(0, 13);
			aTo = rest.substr(13, 13);
			HOW = atoi(rest.substr(26, 3).c_str());
			cb = atoi(rest.substr(29, 2).c_str());
			rc = atoi(rest.substr(31, 2).c_str());
			aoList = rest.substr(32, rest.length());
			//cout << "aFrom: " << aFrom << " aTo: " << aTo << " HOW: " << HOW << " cb " << cb << " rc " << rc << " aoList: " << aoList << endl; 
			cout << "Принята ИЕ ответ на уст соед\n" << request << endl;
			if(rc == 0) {	//-- Соединение установлено корректно  --
				//	Здесь нужна обработка списка
				//	автоответов если он получен
				cout << "Соединение установлено" << endl;
			} else {
				cout << "Ошибка установдения соединения !" << endl;
			}		//-- !Ответ на запрос соединения --
		} else if(type == 5) {	//-- Данные --
			ctrl = rest.substr(0, 2);
			attr = rest.substr(2, 2);
			aFrom = rest.substr(4, 13);
			aTo = rest.substr(17, 13);
			len = rest.substr(30, 8);
			kns = rest.substr(38, 12);
			
			t = time(NULL);
			timestamp_tm = localtime(&t);
			sprintf(TKNS, "%02d%02d%02d%02d%02d00", (timestamp_tm->tm_mon) + 1, timestamp_tm->tm_mday,
								timestamp_tm->tm_hour, timestamp_tm->tm_min,
								timestamp_tm->tm_sec);
			KNS = TKNS;
			outb = outb + "STDP0810000000006" + ctrl + attr + aTo + aFrom + len  + kns + "00" + KNS;	
			cout << "Принята ИЕ  сообщение\n" << request << endl;
			cout << "Отправлена ИЕ подверждение на сообщение: " << outb << endl;
		}			//!-- Данные --
		else if(type == 6) {	//-- Ответ на полученные данные --
			cout << "Принята ИЕ ответ подтверждение на сообщение\n" << request << endl;

		}			//!-- Ответ на полученные данные --
		else if(type == 7) {	//-- Завершение соединения --

		}			//!-- Завершение соединения --
		else if(type == 8) {	//-- Ответ на тест --
			aFrom = rest.substr(0, 13);
			aTo = rest.substr(13, 13);
			cb = atoi(rest.substr(26, 2).c_str());
			cout << "Принята ИЕ тест\n" << request << endl;
			outb = outb + "STDP0470000000009" + aFrom + aTo + "00" + "00";
			cout << "Отправлена ИЕ ответ на тест\n" << outb <<  endl;
		}			//!-- Ответ на тест --
		else if(type == 9) {	//-- Запрос тест --

		}			//!-- Запрос тест --
	}
	
		tail_ready = 0;
		free(TKNS);

}
