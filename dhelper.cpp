#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
#include<dhelperroot.h>
void testsol(){
	cout<<"Compiling..."<<endl;
	int val=system("g++ test.cpp -o sol -I . -std=c++11");
	if(val){
		cout<<"Compile error!"<<endl;
		system("del sol.exe");
		return;
	}
	cout<<"Compiled successfully!"<<endl;
	val=system("sol");
	if(val){
		cout<<"At least one testcase failed."<<endl;
		system("del sol.exe");
		return;
	}
}
void combine(string pth1,string pth2,string pth3){
	string line;
	ofstream of("full.cpp");
	ifstream fin1(pth1.data());
	while(getline(fin1,line)) of<<line<<endl;
	ifstream fin2(pth2.data());
	while(getline(fin2,line)) of<<line<<endl;
	ifstream fin3(pth3.data());
	while(getline(fin3,line)) of<<line<<endl;
	fin1.close();fin2.close();fin3.close();
	of.close();
	cout<<"Files combined to full.cpp."<<endl;
}
int main(int argc,char** argv){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	string args[120];
	for(int i=0;i<argc;i++) args[i]=argv[i];
	if(argc>=2&&args[1]=="parse"){
		cout<<"Type Ctrl+Shift+U in problem page to parse."<<endl;
		system("parse2cf");
		cout<<"Multiple tests per input?(Y/N)"<<endl;
		string command;
		int x=getch();
		if(x=='y'||x=='Y')
			command="copy "+dhelper_root+"\\test_multi.cpp test.cpp";
		else
			command="copy "+dhelper_root+"\\test_single.cpp test.cpp";
		system(command.data());
		if(x=='y'||x=='Y'){
			ofstream fout("MULTI_TESTS");
			fout<<" "<<endl;
			fout.close();
		}
		command="copy "+dhelper_root+"\\body.cpp sol.cpp";
		system(command.data());
		cout<<"Generated code!Check sol.cpp."<<endl;
		return 0;
	}
	if(argc>=2&&args[1]=="test"){
		testsol();
		return 0;
	}
	if(argc>=2&&args[1]=="combine"){
		ifstream fin("MULTI_TESTS");
		if(fin)
			combine(dhelper_root+"\\header.cpp","sol.cpp",dhelper_root+"\\main_multi.cpp");
		else
			combine(dhelper_root+"\\header.cpp","sol.cpp",dhelper_root+"\\main_single.cpp");
		return 0;
	}
	return 0;
}

