#include<bits/stdc++.h>
using namespace std;
#include<sol.cpp>
TaskSolver sol;
int ac_count,to_count;
void testcase(int num){
	string mun=" ";
	mun[0]=(num+'0');
	string in_id="in"+mun+".txt";
	string out_id="out"+mun+".txt";
	string ans_id="ans"+mun+".txt";
	ifstream fakein(in_id.data());
	ofstream fakeout(out_id.data());
	if(!fakein){
		fakeout.close();
		return;
	}
	sol.solve(fakein,fakeout);
	fakeout<<flush;
	fakeout.close();
	string command="fc "+out_id+" "+ans_id+" /w";
	int val=system(command.data());
	to_count++;
	if(!val) ac_count++;
	fakeout.close();
	return;
}
void cleanup(int num){
	string mun=" ";
	mun[0]=(num+'0');
	string out_id="out"+mun+".txt";
	string command="del "+out_id;
	system(command.data());
}
int main(){
	for(int i=0;i<=9;i++)
		testcase(i);
	for(int i=0;i<=9;i++)
		cleanup(i);
	if(to_count==ac_count){
		cout<<"Congratulations!"<<endl;
		cout<<"All tests passed!"<<endl;
		return 0;
	}
	else{
		cout<<"Passed "<<ac_count<<"/"<<to_count<<" tests."<<endl;
		return 1;
	}
}
