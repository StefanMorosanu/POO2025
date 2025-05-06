#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <cctype>

using namespace std;

string toLower( string& s) {
    string result;
    for (char c : s)
        result += tolower(c);
    return result;
}


bool isSeparator(char c) {
    return c == ' ' || c == ',' || c == '?' || c == '!' || c == '.';
}


vector<string> splitWords( string& text) {
    vector<string> words;
    string word;
    for (size_t i = 0; i < text.size(); ++i) {
        if (!isSeparator(text[i])) {
            word += text[i];
        } else {
            if (!word.empty()) {
                words.push_back(toLower(word));
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        words.push_back(toLower(word));
    }
    return words;
}

int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cerr << "Cannot open file.\n";
        return 1;
    }

    string line, text;
    while (getline(fin, line)) {
        text += line + " ";
    }
    fin.close();

    vector<string> words = splitWords(text);

  
    map<string, int> freq;
    for ( auto& word : words) {
        ++freq[word];
    }

   struct Compare {
    bool operator()(pair<string, int>& a, pair<string, int>& b) {
        if (a.second != b.second)
            return a.second < b.second;  
        return a.first > b.first;        
    }
};

    priority_queue<
    pair<string, int>,
    vector<pair<string, int>>,
    Compare> pq;

    for ( auto& [word, count] : freq) {
        pq.emplace(word, count);
    }

    
    while (!pq.empty()) {
        auto [word, count] = pq.top();
        pq.pop();
        cout << word << " => " << count << "\n";
    }

    return 0;
}
