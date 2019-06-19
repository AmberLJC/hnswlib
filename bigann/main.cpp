#include <iostream>
#include <fstream>
#include <queue>
#include <chrono>


using namespace std;

int main(int argc, char *argv[]){
 char const *path_q = argv[1];
size_t qsize = 10000;
ifstream inputQ(path_q, ios::binary);
size_t vecdim = 128;
    unsigned char *massb = new unsigned char[vecdim];
    unsigned char *massQ = new unsigned char[qsize * vecdim];

    for (size_t i = 0; i < qsize; i++) {
        int in = 0;
        inputQ.read((char *) &in, 4);
        if (in != 128) {
            cout << "in = " << in << endl;
            cout << "file error" << endl;
            exit(1);
        }
        inputQ.read((char *) massb, in);
        for (size_t j = 0; j < vecdim; j++) {
            massQ[i * vecdim + j] = massb[j];
       		cout<<  massb[j] <<" , ";
       	}
	cout<<endl;
    }
    inputQ.close();













}
