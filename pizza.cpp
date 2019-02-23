#include<iostream>
#include<fstream>

using namespace std;

int main(void){
	int r = 0, R = 0, c = 0, C = 0, L = 0, h = 1, H = 0, noOfSlice = 0, noOfT = 0, noOfM = 0, cbeg = 0, flag = 1;
	char line[50];

	ifstream ifpizza("c_medium.in");
	fstream fpizza;
	fpizza.open("temp.out", ios::in | ios::out | ios::binary);		
	ofstream ofpizza("c_medium.out");

	ifpizza >> R >> C >> L >> H;
	
	char grid[R][C];
	
	for(r = 0; r < R; r++){
		for(c = 0; c < C; c++){
			ifpizza >> grid[r][c];
		}
	}
	
	ifpizza.close();

	for(r = 0; r < R; r++){	
		noOfT = 0;
		noOfM = 0;					
		c = 0;
		h = 1;
		flag = 1;
		while(c < C){		
			while(h <= H){
				if(grid[r][c] == 'T'){
					noOfT += 1;
					if(flag){
						cbeg = c;
						flag--;
					}
				}
				if(grid[r][c] == 'M'){
					noOfM += 1;
					if(flag){
						cbeg = c;
						flag--;
					}
				}
				if(noOfT >= L && noOfM >= L)
					break;
				c++;
				h++;	
			}
			if(c < C && h <= H){
				++noOfSlice;
				noOfT = 0;
				noOfM = 0;
				h = 1;
				flag = 1;
				fpizza << r << " " << cbeg << " " << r << " " << c << "\n";
			}else if(c >= C){
				break;

			}else if(h > H){
				h = 1;
				flag = 1;
				noOfT = 0;
				noOfM = 0;
			}
			c++;
		}
	}

	fpizza.seekg(0);
	ofpizza << noOfSlice << "\n";
	while(fpizza){
		fpizza.getline(line, 50);
		ofpizza << line << "\n";
	}
	
	fpizza.close();
	ofpizza.close();

	return 0;
}
