all: stdpclient

stdpclient: Helper.cc initConn.cc serv.cc stdp.cc 
	g++ -g -o stdpclient Helper.cc initConn.cc serv.cc stdp.cc

clean: 
	rm -f stdpclient
