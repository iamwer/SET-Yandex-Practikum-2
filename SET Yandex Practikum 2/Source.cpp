#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

set<string> MakeSet(vector<string> query_words) {
    set<string> s;
    for (string word : query_words) {
        s.insert(word);
    }
    return s;
}

vector<string> SplitIntoWords(string text) {
    vector<string> words;
    string word;
    for (const char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += c;
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}

int CalculateSimilarity(vector<string> first, vector<string> second) {
    set<string> first_set = MakeSet(first);
    set<string> second_set = MakeSet(second);
    set<string> intersection;
    for (string word : first_set) {
        if (second_set.count(word) > 0) {
            intersection.insert(word);
        }
    }
    return intersection.size();
}

int main() {
    string query, description;

    getline(cin, query);
    getline(cin, description);

    cout << CalculateSimilarity(SplitIntoWords(query), SplitIntoWords(description)) << endl;
}