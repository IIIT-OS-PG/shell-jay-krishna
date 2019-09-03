#include "shellrunner.h"

void execute(char buffer[],unordered_map <string,string> &environment_var,unordered_map <string,string> &executable_var, char* commands[]){
	auto pid=fork();
	// int status;
	if(pid>0){
		wait(NULL);
	}
	else if(pid==0){
		// auto itr=
		string pathpass="PATH="+environment_var.find("PATH")->second;
    	char* e1[3]={(char*)pathpass.c_str(),(char*)"TERM=xterm-256color",NULL};
		auto e = execve(commands[0],commands,e1);
	
		if (e == -1)
			fprintf(stderr, "Error: %s\n", strerror(errno));

		exit(1);
	}
	else{
		printf("Fork Error\n");
	}
}