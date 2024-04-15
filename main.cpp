#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;
//
//vector<string> read_file(){
//    vector<string> data;
//    string line;
//
//    while (getline(cin, line)){
//        data.push_back(line);
//    }
//    return data;
//}
int main() {

//    vector<string> file_data = read_file();
//
//    cout << "Data read from file (or stdin):" << endl;
//    for (const auto& line : file_data){
//        cout << line << endl;
//    }

    char filename = (50);
    ifstream fileSelect;
    cin.getline(&filename, 50);
    fileSelect.open(&filename);

    system ("pause");
    return 0;
}
