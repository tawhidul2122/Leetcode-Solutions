// https://leetcode.com/problems/design-add-and-search-words-data-structure

class WordDictionary {
public:
  // Adds a word into the data structure.
  void addWord(string word) {
    words.insert(word);
    ws[word.length()].insert(word);
  }
 
  // Returns if the word is in the data structure. A word could
  // contain the dot character '.' to represent any one letter.
  bool search(string word) {
    if (word.find(".") == string::npos)
      return words.count(word);
    
    for (const string& w : ws[word.length()])
      if (match(word, w)) return true;    
 
    return false;
  }
    
  bool match(const string& p, const string& w) {
    for (int i = 0; i < p.length(); ++i) {
      if (p[i] == '.') continue;
      if (p[i] != w[i]) return false;
    }
    return true;
  }
private:
    unordered_set<string> words;
    unordered_map<int, unordered_set<string>> ws;
};