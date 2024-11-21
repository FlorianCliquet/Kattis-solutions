#include <bits/stdc++.h>
using namespace std;

const int MAXWORDS = 20000;
string words[MAXWORDS];
int counts[MAXWORDS];
int nwords = 0;

const int HASH_SIZE = 100007;
vector< map<string, int> > word_codes(HASH_SIZE);

unsigned hash_string(const char * s) {
    unsigned hash = 0;
    for(; *s; ++s) {
        hash += *s;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash%HASH_SIZE;
}

inline int get_code(const string& w) {
    int c = hash_string(w.c_str());
    map<string, int>::iterator r = word_codes[c].find(w);
    if (r == word_codes[c].end()) {
        int code = nwords++;
        words[code] = w;
        word_codes[c][w] = code;
        return code;
    } else 
        return r->second;
}

bool comparator(const pair<int, const string*>& lhs, const pair<int, const string*>& rhs) {
    if (lhs.first == rhs.first)
       return *lhs.second < *rhs.second;
    return lhs.first > rhs.first;
}

int main(int argc, char *argv[]) {
    vector<int> days[7];
    int LAST = 7-1;

    while (true) {
        char action_char[100];
        if (scanf("%s", action_char) != 1) break;

        string action = action_char;
        if (action == "<text>") {
            for (vector<int>::iterator it = days[0].begin();
                 it != days[0].end();
                 ++it) {
                --counts[*it];
            }

            for (int i = 0; i < LAST; ++i)
                days[i].swap(days[i+1]);
            days[LAST].clear();

            while (true) {
                char word_char[100];
                if (scanf("%s", word_char) != 1)
                    return -1;
                if (word_char[0] == '<')
                    break;
                string word = word_char;
                if (word.size() < 4)
                    continue;
                int code = get_code(word);
                days[LAST].push_back(code);
                counts[code]++;
            }
        
        } else {
            int how_many;
            if (scanf("%d%*s", &how_many) != 1)
                return -1;
            printf("<top %d>\n", how_many);
 
            int max_cnt = 0;
            vector<int> cnt(100000, 0);
            for (int i = 0; i < nwords; ++i) {
                cnt[counts[i]]++;
                max_cnt = max(max_cnt, counts[i]);
            }

            int thres = max_cnt+1;
            while (thres > 0 && how_many > 0) {
                --thres;
                how_many -= cnt[thres];
            }
            thres = max(1, thres);

            vector<pair<int, const string*> > result;
            for (int i = 0; i < nwords; ++i)
                if (counts[i] >= thres)
                    result.push_back(pair<int, const string*>(counts[i], &words[i]));

            sort(result.begin(), result.end(), comparator);
            for (vector<pair<int,const string*> >::iterator it = result.begin();
                 it != result.end();
                 ++it)
                    printf("%s %d\n", it->second->c_str(), it->first);
            printf("</top>\n");
        }
    } 
    return EXIT_SUCCESS;
}