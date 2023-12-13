#include <iostream>  
#include <string>  
#include <cmath>
#include <bits/stdc++.h>
#include <algorithm>  
#include <stdexcept>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
using namespace std;

struct arrWrap
{
	string arr[16];
};

string string_to_hex(const string& input)
{
    static const char hex_digits[] = "0123456789ABCDEF";

    string output;
    output.reserve(input.length() * 2);
    for (unsigned char c : input)
    {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
    }
    return output;
}

int hex_value(unsigned char hex_digit)
{
    static const signed char hex_values[256] = {
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
         0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
        -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    };
    int value = hex_values[hex_digit];
    if (value == -1) throw invalid_argument("invalid hex digit");
    return value;
}

string hex_to_string(const string& input)
{
    const auto len = input.length();
    if (len & 1) throw invalid_argument("odd length");

    string output;
    output.reserve(len / 2);
    for (auto it = input.begin(); it != input.end(); )
    {
        int hi = hex_value(*it++);
        int lo = hex_value(*it++);
        output.push_back(hi << 4 | lo);
    }
    return output;
}

string convertDecimalToBinary(int decimal){  
	string binary;  
	while(decimal != 0) {  
		binary = (decimal % 2 == 0 ? "0" : "1") + binary;  
		decimal = decimal/2;  
	}
	while(binary.length() < 4){  
		binary = "0" + binary;  
	}  
	return binary;  
}  

int convertBinaryToDecimal(string binary)  {  
	int decimal = 0;  
	int counter = 0;  
	int size = binary.length();  
	for(int i = size-1; i >= 0; i--){  
		if(binary[i] == '1'){  
			decimal += pow(2, counter);  
		}  
		counter++;  
	}  
	return decimal;  
}  
string convertHexToBinary(string s)
{
	string bin = "";
	for (int i = 0; i < int(s.size()); i++)
	{
		switch (s[i])
		{
		case '0': bin += "0000"; break;
		case '1': bin += "0001"; break;
		case '2': bin += "0010"; break;
		case '3': bin += "0011"; break;
		case '4': bin += "0100"; break;
		case '5': bin += "0101"; break;
		case '6': bin += "0110"; break;
		case '7': bin += "0111"; break;
		case '8': bin += "1000"; break;
		case '9': bin += "1001"; break;
		case 'A':
		case 'a': bin += "1010"; break;
		case 'B':
		case 'b': bin += "1011"; break;
		case 'C':
		case 'c': bin += "1100"; break;
		case 'D':
		case 'd': bin += "1101"; break;
		case 'E':
		case 'e': bin += "1110"; break;
		case 'F':
		case 'f': bin += "1111"; break;

		}
	}
	return bin;
}

string convertBinToHex(string s)
{
	string hex = "";
	for (int i = 0; i < int(s.size()); i += 4)
	{
		string k = "";
		for (int j = i; j < i + 4; j++)
			k += s[j];
		if (k == "0000")
			hex += '0';
		else if (k == "0001")
			hex += '1';
		else if (k == "0010")
			hex += '2';
		else if (k == "0011")
			hex += '3';
		else if (k == "0100")
			hex += '4';
		else if (k == "0101")
			hex += '5';
		else if (k == "0110")
			hex += '6';
		else if (k == "0111")
			hex += '7';
		else if (k == "1000")
			hex += '8';
		else if (k == "1001")
			hex += '9';
		else if (k == "1010")
			hex += 'A';
		else if (k == "1011")
			hex += 'B';
		else if (k == "1100")
			hex += 'C';
		else if (k == "1101")
			hex += 'D';
		else if (k == "1110")
			hex += 'E';
		else if (k == "1111")
			hex += 'F';
	}
	return hex;
}

string Xor(string a, string b){  
	string result = "";  
	int size = b.size();  
	for(int i = 0; i < size; i++){  
		if(a[i] != b[i]){  
			result += "1";  
		}  
		else{  
			result += "0";  
		}  
	}  
	return result;  
}  

string shift_left_once(string key_chunk){  
	string shifted="";  
	for(int i = 1; i < 28; i++){  
		shifted += key_chunk[i];  
	}  
	shifted += key_chunk[0];  
	return shifted;  
}  

string shift_left_twice(string key_chunk){  
	string shifted="";  
	for(int i = 0; i < 2; i++){  
		for(int j = 1; j < 28; j++){  
			shifted += key_chunk[j];  
		}  
		shifted += key_chunk[0];  
		key_chunk= shifted;  
		shifted ="";  
	}  
	return key_chunk;  
}  

struct arrWrap generate_keys(string key){  
	struct arrWrap round_keys;
	int pc1[56] = {  
		57,49,41,33,25,17,9,  
		1,58,50,42,34,26,18,  
		10,2,59,51,43,35,27,  
		19,11,3,60,52,44,36,  
		63,55,47,39,31,23,15,  
		7,62,54,46,38,30,22,  
		14,6,61,53,45,37,29,  
		21,13,5,28,20,12,4  
	};  

	int pc2[48] = {  
		14,17,11,24,1,5,  
		3,28,15,6,21,10,  
		23,19,12,4,26,8,  
		16,7,27,20,13,2,  
		41,52,31,37,47,55,  
		30,40,51,45,33,48,  
		44,49,39,56,34,53,  
		46,42,50,36,29,32  
	};  
	//Rearrange key using pc1
	string perm_key ="";  
		for(int i = 0; i < 56; i++){  
		perm_key+= key[pc1[i]-1];  
	}  
	//Divide into two
	string left= perm_key.substr(0, 28);  
	string right= perm_key.substr(28, 28);  
		
	for(int i=0; i<16; i++){  
		// For rounds 1, 2, 9, 16 the key_chunks are shifted by one
		if(i == 0 || i == 1 || i==8 || i==15 ){  
			left= shift_left_once(left);  
			right= shift_left_once(right);  
		}  
		else{  
			left= shift_left_twice(left);  
			right= shift_left_twice(right);  
		}  
		string combined_key = left + right;  
		string round_key = "";  
		//Rearrange key using pc2
		for(int i = 0; i < 48; i++){  
			round_key += combined_key[pc2[i]-1];  
		}  
		round_keys.arr[i] = round_key;    
	}
	return round_keys;  
  
}
  
string DES(string pt, struct arrWrap round_keys){  
	int initial_permutation[64] = {  
		58,50,42,34,26,18,10,2,  
		60,52,44,36,28,20,12,4,  
		62,54,46,38,30,22,14,6,  
		64,56,48,40,32,24,16,8,  
		57,49,41,33,25,17,9,1,  
		59,51,43,35,27,19,11,3,  
		61,53,45,37,29,21,13,5,  
		63,55,47,39,31,23,15,7  
	};  
	
	int expansion_table[48] = {  
		32,1,2,3,4,5,4,5,  
		6,7,8,9,8,9,10,11,  
		12,13,12,13,14,15,16,17,  
		16,17,18,19,20,21,20,21,  
		22,23,24,25,24,25,26,27,  
		28,29,28,29,30,31,32,1  
	};  
	
	int substition_boxes[8][4][16]=  {
		{  
		14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,  
		0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,  
		4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,  
		15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13  
		},  
		{  
		15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,  
		3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,  
		0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,  
		13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9  
		},  
		{  
		10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,  
		13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,  
		13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,  
		1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12  
		},  
		{  
		7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,  
		13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,  
		10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,  
		3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14  
		},  
		{  
		2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,  
		14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,  
		4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,  
		11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3  
		},  
		{  
		12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,  
		10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,  
		9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,  
		4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13  
		},  
		{  
		4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,  
		13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,  
		1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,  
		6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12  
		},  
		{  
		13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,  
		1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,  
		7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,  
		2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11  
		}
	};  
	
	int permutation_tab[32] = {  
		16,7,20,21,29,12,28,17,  
		1,15,23,26,5,18,31,10,  
		2,8,24,14,32,27,3,9,  
		19,13,30,6,22,11,4,25  
	};  
	int inverse_permutation[64]= {  
		40,8,48,16,56,24,64,32,  
		39,7,47,15,55,23,63,31,  
		38,6,46,14,54,22,62,30,  
		37,5,45,13,53,21,61,29,  
		36,4,44,12,52,20,60,28,  
		35,3,43,11,51,19,59,27,  
		34,2,42,10,50,18,58,26,  
		33,1,41,9,49,17,57,25  
	};  
	//initial permutation
	string perm = "";  
	for(int i = 0; i < 64; i++){  
		perm += pt[initial_permutation[i]-1];  
	}  
	//divide into two
	string left = perm.substr(0, 32);  
	string right = perm.substr(32, 32);  
	//16 times encryption round
	for(int i=0; i<16; i++) {  
		//expansion of right side
		string right_expanded = "";  
		for(int i = 0; i < 48; i++) {  
			right_expanded += right[expansion_table[i]-1];  
		};  
		//xor right side with keys
		string xored = Xor(round_keys.arr[i], right_expanded);  
		string res = "";  
		//subtitution of the result
		for(int i=0;i<8; i++){  
			string row1= xored.substr(i*6,1) + xored.substr(i*6 + 5,1);  
			int row = convertBinaryToDecimal(row1);  //00
			string col1 = xored.substr(i*6 + 1,1) + xored.substr(i*6 + 2,1) + xored.substr(i*6 + 3,1) + xored.substr(i*6 + 4,1);;  
			int col = convertBinaryToDecimal(col1);  //1 1 1 1
			int val = substition_boxes[i][row][col];  //0 0 15
			res += convertDecimalToBinary(val);  //011110
			//0 1 1 1
		}  
		//another permutation
		string perm2 ="";  
		for(int i = 0; i < 32; i++){  
			perm2 += res[permutation_tab[i]-1];  
		}  
		//xor with left side
		xored = Xor(perm2, left);  
		left = xored;  
		if(i < 15){  
			string temp = right;  
			right = xored;  
			left = temp;  
		}  
	}  
	string combined_text = left + right;  
	string ciphertext ="";  
	for(int i = 0; i < 64; i++){  
		ciphertext+= combined_text[inverse_permutation[i]-1];  
	}  
	return ciphertext;  
}    

bool isPrime(int n) {
	if (n % 2 == 0) return n == 2;
	if (n % 3 == 0) return n == 3;
	int step = 4, m = (int)pow(n, 0.5) + 1;
	for (int i = 5; i < m; step = 6 - step, i += step) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void send(string message){
	//send public key
	FILE *msg = fopen("message.txt", "w+");
    fprintf(msg, "%s\n", message.c_str());
    fclose(msg);
    system("nc 10.16.1.3 3333 -q 0 < message.txt");
}

string receive(){
	while(1){
		system("nc -l -p 3333 > message.txt");
		break;
	}

	FILE *fptr;
    if ((fptr = fopen("message.txt", "r")) == NULL) {
        printf("Error! File cannot be opened.");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
	char pu[100];
    // reads text until newline is encountered
    fscanf(fptr, "%[^\n]", pu);
	fclose(fptr);
	string message=pu;
	return message;
}

void split(string str, string* a, string* b){
	size_t pos = str.find(";");
	if (pos == string::npos) {
		cout<<"Error!no semicolon found."<<endl;
        // Program exits if the file pointer returns NULL.
        exit(1);
	}
	else {
    	*a = str.substr(0, pos);
    	*b = str.substr(pos + 1);
	}
}

// calculate a^b mod m using modular exponentiation
int modpow(int a, int b, int m) {
   int result = 1;
   while (b > 0) {
       if (b & 1) {
           result = (result * a) % m;
       }
       a = (a * a) % m;
       b >>= 1;
   }
   return result;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}

int nthPrime(int n)
{
	int candidate, count;
	for (candidate = 2, count = 0; count < n; ++candidate) {
		if (isPrime(candidate)) {
			++count;
		}
	}
	return candidate - 1;
}

int main(){  
	long p = 53;
    long q = 59;
    double n = p * q;
    int phi = (p - 1) * (q - 1);
	double e =nthPrime(rand()%phi);
    double d = modInverse(e, phi);

    //exchange public key
	string msg;
	msg = to_string(e);
	msg += ";";
	msg += to_string(n);
	send(msg);
 
	string msg_rcv = receive();
	string e1_str,n1_str;
	split(msg_rcv,&e1_str,&n1_str);
    double e1 = stoi(e1_str);
    double n1 = stoi(n1_str);

	cout<<"public key:"<<msg<<endl;
    cout<<"private key:"<< d<<endl;
    cout<<"public key msg_received:"<<msg_rcv<<endl;
    
    //send id and n1
    sleep(1);
	double id = 12;
	double N1 = 201;
	msg = to_string(modpow(id,e1,n1));
	msg += ";";
	msg += to_string(modpow(N1,e1,n1));
	send(msg);
    cout<<"id and N1 before encrypt: "<< id<<" "<<N1<<endl;
    cout<<"id and N1 send:" <<msg<<endl;
	
    //receive N1 and N2
	msg_rcv = receive();
	string m2_N1,m2_N2;
	split(msg_rcv,&m2_N1,&m2_N2);
	double m2_N1_int=modpow(stoi(m2_N1),d,n);
    double m2_N2_int=modpow(stoi(m2_N2),d,n);
	if(m2_N1_int==N1){
		cout<<"n1 matched"<<endl;
	} else{
		cout<<"n1 doesn't match"<<endl;
		//exit(1);
	}
    cout<<"N1 and N2 received:" <<msg_rcv<<endl;
    cout<<"N1 decrypt: "<<m2_N1_int<<endl;
    cout<<"N2 decrypt: "<<m2_N2_int<<endl;

    //send N2
    sleep(1);
	double m3_N2_int=modpow(m2_N2_int,e1,n1);
	msg = to_string(m3_N2_int);
	send(msg);
    cout<<"N2 send: "<<msg<<endl;

    //send session key
	int i=0;
    string sess_key = "51;34;56;78;91;23;45;67;";
	while(i<8){
		sleep(1);
		string key_s;
		size_t pos = sess_key.find(";");
		if (pos == string::npos) {
			cout<<"Error!no semicolon found."<<endl;
			// Program exits if the file pointer returns NULL.
			exit(1);
		}
		else {
			key_s = sess_key.substr(0, pos);
			sess_key = sess_key.substr(pos + 1);
		}
		msg = to_string(modpow(stoi(key_s),e1,n1));
		send(msg);
		i++;
	}
	sess_key = "5134567891234567";
	struct arrWrap keys;
    sess_key = convertHexToBinary(sess_key);
	keys=generate_keys(sess_key); 
	string pt;
    cout<<"Enter plaintext 8 character: ";  
    cin>>pt;
    pt = string_to_hex(pt);
	pt = convertHexToBinary(pt);  
    
	string ct = DES(pt, keys);  
	ct = hex_to_string(convertBinToHex(ct));
    cout<<"Ciphertext: "<<ct<<endl; 
	send(ct);
}