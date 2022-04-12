#include<iostream>
#include<math.h>
using namespace std;
#define max 10


int main(){
	string plaintxt;
	int len,i,j,k;
	cout << "Enter plaintxt : ";
	cin >> plaintxt;
	len = plaintxt.length();
	//cout << len;

	cout << "Enter dimension of key: ";
	int m;
	cin >> m;
	float key[max][max];
	cout << "Enter elements of key: \n";
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			cin >> key[i][j];
		}
	}
	//ENCRYPTION
	float textkeyrix[len][1];
	for(i=0;i<len;i++){
		if(isupper(plaintxt[i])){
			textkeyrix[i][0] = int(plaintxt[i] - 65);
		}
		else{
			textkeyrix[i][0] = int(plaintxt[i] - 97);
		}

	}
	

	//keyrix multiplication key[m][m] x textkeyrix[len][1]
	float c[len][1],e[len][1];

	for(i=0;i<m;i++){
		for(j=0;j<1;j++){
			c[i][j] = 0;

			for (k=0;k<3;k++){
				c[i][j] += key[i][k] * textkeyrix[k][j];
			}
			e[i][j] = c[i][j];
		}
	}
	
	for(i=0;i<m;i++){
		for(j=0;j<1;j++){
			c[i][j] = int(c[i][j]) % 26;
		}
	}
	
	char ch;
	cout << "\nCipher Text/ Encrypted Text:  ";
	for(i=0;i<m;i++){
		for(j=0;j<1;j++){
			//cout << (c[i][j]+97) << "\n";
			if(isupper(plaintxt[i])){
				ch = c[i][j]+65;
			}

			else{
				ch = c[i][j]+97;
			}
			
			cout << ch ;
		}
	}
	cout << endl;

	//DECRYPTION
	//keyrix Inverse

	float inv[m][m];
	float det=0;
	for(i = 0; i < 3; i++)
        det +=  (key[0][i] * (key[1][(i+1)%3] * key[2][(i+2)%3] - key[1][(i+2)%3] * key[2][(i+1)%3]));
    

	
	for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            inv[i][j] = ((key[(j+1)%3][(i+1)%3] * key[(j+2)%3][(i+2)%3]) - (key[(j+1)%3][(i+2)%3] * key[(j+2)%3][(i+1)%3]))/ det;
        }
    }


    float d[len][1];

    char ch2;
	for(i=0;i<m;i++){
		for(j=0;j<1;j++){
			d[i][j] = 0;

			for (k=0;k<3;k++){
				d[i][j] += inv[i][k] * e[k][j];
			}
		}
	}


	cout << "Decrypted Text: ";
	for(i=0;i<m;i++){
		for(j=0;j<1;j++){
		ch2 = (int(d[i][j]))+97;
		cout << ch2;
		
		}
	}
	cout << endl;

return 0;

}