class Solution {
public:

    int bfs(string endWord, queue<string> &q, unordered_set<string>& wordSet){

        int steps=1;

        while(!q.empty()){
            int level=q.size();
            
            for(int i=0;i<level;i++){
                string currentWord=q.front();
                q.pop();
                
                if(currentWord == endWord ){
                    return steps;
                }

                for(int j=0; j<currentWord.length(); j++){
                    char originalChar = currentWord[j];
                    
                    for(char c='a'; c<='z'; c++){
                        currentWord[j] = c;
                        
                        // If the generated word exists in our set
                        if(wordSet.find(currentWord) != wordSet.end()){
                            q.push(currentWord);
                            wordSet.erase(currentWord); // Erase it so we never visit it again!
                        } 
                    }
                    currentWord[j] = originalChar; // Put original character back
                }
            }
            // Move steps++ here so it increments after a full level is processed
            steps++; 
        }
        return 0;

    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // Put all words in an unordered_set for instant lookups
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // if the endWord is not in the set at the first place
        if(wordSet.find(endWord) == wordSet.end()) return 0;

        queue<string> q;
        
        // Instead of manually finding beginWord's neighbors, just push beginWord
        // and let the BFS handle the rest!
        q.push(beginWord);
        wordSet.erase(beginWord); // Mark as visited

        // Call your modified BFS
        int no_of_steps=bfs(endWord, q, wordSet);

        return no_of_steps;
        
    }
};