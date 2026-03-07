#include "letters.cpp"
#include "pynkt1.cpp"
std::string doNormWord(std::string& w){
    for (int i = 0; i < w.size(); i++) {
    if (w[i] == '¸') w[i] = 'å';
    if (w[i] == '¨') w[i] = 'Å';
    }
    return w;
}
std::string toLowerWord(std::string& w){
    char temp;
    for (int i = 0; i<w.size(); i++){
        if (w[i] >= 'À' && w[i] <= 'ß'){
            w[i] = w[i]+32;
        }
        if (w[i] == '¨') w[i] = '¸';
    }
    return w;
}
bool isCorrectWordForPynkt2(const std::string& word) {
    for (int i = 1; i < word.size(); i++) {
        if (word[i] < word[i - 1]) {
            return false;
        }
    }
    return true;
}

bool condition(const std::string& left, const std::string& right) { 
    return left.length() > right.length(); 
}

void removeDuplicates(std::vector<std::string>& vec) {
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}
void printV(std::vector<std::string>& result){
        for (int i = 0; i<result.size(); i++) std::cout << result[i] << std::endl;
}
int main(){
    std::setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // printLetters();
    // fon();

    std::ifstream in("../input.txt");
    int N;
    in >> N;
    
    std::ifstream in2("../text.txt");

    char sym;
    std::string temp;

    std::vector<std::string> allWords;

    while (in2.get(sym)){
        if (  (sym >= char(192) && sym <= char(223) || sym == char(168)) || ((sym >= char(224) && sym <= char(255)) || sym == char(184))  ){
            temp.push_back(sym);
        }
        if((sym == ' ') || (sym == '.') || (sym == ',')){
            if(!temp.empty()){
                allWords.push_back(temp);
                temp = "";
            }
        }
    }
    if (!temp.empty()) allWords.push_back(temp);
    std::sort(allWords.begin(), allWords.end(), condition);

    std::vector<std::string> result;
    std::vector<std::string> resultNorm;

    for (int i = 0; i < allWords.size(); i++) {
        std::string normalized = allWords[i];
        toLowerWord(normalized);
        doNormWord(normalized);

        if (!isCorrectWordForPynkt2(normalized)) {
            continue;
        }

        bool exists = false;
        for (int j = 0; j < resultNorm.size(); j++) {
            if (resultNorm[j] == normalized) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            result.push_back(allWords[i]);
            resultNorm.push_back(normalized);
        }

        if (result.size() == N) {
            break;
        }
    }

    std::ofstream out("../result.txt");
    for (int i = 0; i < result.size(); i++) {
        out << result[i] << std::endl;
    }

    return 0;
}