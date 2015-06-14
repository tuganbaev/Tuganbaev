#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::pair < std::vector<int>, std::vector<int> > > func_input (std::vector<std::pair < std::vector<int>, std::vector<int> > >data);

int main () {
    std::vector<std::pair < std::vector<int>, std::vector<int> > > data;
    data = func_input(data);
    const int N = data[0].first.size();
    const int M = data[0].second.size();
    const int coun = data.size();
    double NewronsWeights[M][N];
    for (auto i = 0; i < M; ++i){
        for (auto j = 0; j < N; ++j)
            NewronsWeights[i][j] = 0;
    }
    double delt = 0.5;
    bool error = 0;
    std::vector<int> result(M, 0);
    std::vector<int> dif(M, 0);
    for(int i = 0; i < coun; ++i){
        std::cout <<"i:" << i;
        for(int p = 0; p < M; ++p){
            std::cout <<" p:"<< p << " ";
            for(int j = 0; j < N; ++j){
                result[p] += NewronsWeights[p][j]*data[i].first[j];
                std::cout << result[p] << " ";
            }
            std::cout << "\n";
            result[p] = (result[p] > 0 ? 1:0);
            dif[p] = data[i].second[p] - result[p];
        }
        for(int t = 0; t < M; ++t){
            if(dif[t] != 0){
                std::cout << "MISTAKE \n";
                error = 1;
                for(int j = 0; j < N; ++j){
                    NewronsWeights[t][j] += delt*dif[t]*data[i].first[j];
                    std::cout << "correction:"<< NewronsWeights[t][j] << "\n";
                }
            }
        }
        if (i == coun - 1 and error == 0){
            std::cout << "Done\n";
            for(int c = 0; c < M; ++c){
                for(int d = 0; d < N; ++ d){
                    std::cout << NewronsWeights[c][d]<<"  ";
                }
                std::cout<<"\n";
            }
        }
        else if (i == coun - 1){
            i = -1;
            error = 0;
        }
    }
}

std::vector<std::pair < std::vector<int>, std::vector<int> > > func_input (std::vector<std::pair < std::vector<int>, std::vector<int> > >data){
	std::ifstream input;
	int N = 0, M=0, coun=0;
/*	input.open("C:\\NW\\NW\\input.txt");
	input >> coun;
	input >> N;
	input >> M;
*/
    std::cin >> coun >> N >> M;
	int a;
	for(int i = 0; i < coun; ++i){
		std::vector<int> v1;
		std::vector<int> v2;
		for(int j = 0; j < N; ++j){
 //           input >> a;
            std::cin >> a;
			v1.push_back(a);
		}
		v1.push_back(1);
		for(int j = 0; j < M; ++j){
//		    input >> a;
            std::cin >> a;
			v2.push_back(a);
		}
		std::pair < std::vector<int>, std::vector<int> > local (v1, v2);
		data.push_back(local);
    }
    return data;
}

