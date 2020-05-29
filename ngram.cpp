#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <cmath>

using namespace std;

const string BOS="BOS";
const string EOS="EOS";

map<string, map<string, int>> ngram;
map<string, int> total_count;

vector<string> training_data = {
    BOS + " unit tests are failing",
    BOS + " unit tests are passing but gradescope is failing",
    BOS + " the gradescope submission does not terminate",
    BOS + " please cancel my gradescope submission",
    BOS + " all the unit tests are passing",
    BOS + " unit tests pass with warning",
    BOS + " all the unit tests are failing",
    BOS + " please resolve issues with unit tests",
    BOS + " the unit tests are not running",
    BOS + " unit tests are taking forever",
    BOS + " my gradescope submission is running forever",
    BOS + " the unit tests are running into issues",
    BOS + " failure in unit tests",
    BOS + " unexpected failure in gradescope submissions",
    BOS + " please terminate my gradescope submission",
    BOS + " however the tests are failing",
    BOS + " running into issues with the unit tests",
    BOS + " the unit tests are buggy",
    BOS + " my unit tests are terminating with errors",
    BOS + " bug in the gradescope tests",
    BOS + " the unit tests are terminating with errors",
    BOS + " gradescope submission is terminating with errors",
    BOS + " unit tests are not terminating",
    BOS + " the tests are passing but gradescope is failing"
};

ostream& operator<<(ostream& os, set<string> mset)
{
    os << "{\n";
    for(auto& s : mset)
        cout << "\t" << s << '\n';
    os << "}\n";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, map<string, T> mapa)
{
    os << " {\n";
    for(auto& p : mapa)
        cout << "\t" << p.first << ":" << p.second << '\n';
    os << "}\n";
    return os;
}

/* no se usa realmente en el algoritmo, fue para probar*/
set<string> build_set(vector<string>& vec)
{
    set<string> res;
    for(string& s : vec)
    {
        stringstream ss(s);
        string t;
        while(ss >> t)
            res.insert(t);
    }
    return res;
}

/* puede que se puedan unir bigrama y trigrama en un simple algorithmo*/
void fill_bigram(vector<string>& vec)
{
    for(string& s : vec)
    {
        stringstream ss(s);
        vector<string> words;
        string t;
        while(ss >> t)
        {
            words.emplace_back(t);
        }
        for(int i=0; i<words.size() - 1; ++i)
        {
            string w = words[i];
            string n = words[i+1];
            auto& mapa = ngram[w];
            ++mapa[n];
        }
            
    }
}

void fill_trigram(vector<string>& vec)
{
    for(string& s : vec)
    {
        stringstream ss(s);
        vector<string> words;
        string t;
        while(ss >> t)
        {
            words.emplace_back(t);
        }
        for(int i=0; i<words.size() - 2; ++i)
        {
            string w = words[i] + " " + words[i+1];
            string n = words[i+2];
            auto& mapa = ngram[w];
            ++mapa[n];
        }
            
    }
}

void laplacian_smooth(map<string, map<string, int>>& ngram, set<string>& vocabulary, int k)
{
    for(auto& p : ngram)
    {
        auto& mapa = p.second;
        for(string s : vocabulary)
        {
            mapa[s] += k;
        }
        
    }
}

/* suma el numero de palabras que suceden a otra, e.g. are passing, are failing, sumaria are a 2*/
void fill_total_cnt(map<string, map<string, int>>& mapa)
{
    for(auto& p : mapa)
    {
        int cnt = 0;
        for(auto& pp : p.second)
            cnt += pp.second;
        total_count[p.first] = cnt;
    }
}

/* calcula la probabilidad de que la frase n subsiga a la frase s */
double calc(string s, string n)
{
    int instances_of_s = ngram[s][n];
    int total = total_count[s];
    //cout << "ins: " << instances_of_s << " total: " << total << endl;
    const double prob = (double)instances_of_s/(double)total;
    cout << "P( " << n << " | " << s << " )=" << prob << '\n';
    return prob;
}

double calc_trigram(string s)
{
    double prob = 1.0;
    stringstream ss(s);
    vector<string> words;
    string t;
    while(ss >> t)
    {
        words.emplace_back(t);
    }
    for(int i=0; i<words.size() - 2; ++i)
    {
        string par = words[i] + " " + words[i+1];
        string n = words[i+2];
        double prb = calc(par, n);
        prob *= prb;
    }
    return prob;
}

double calc_bigram(string s)
{
    double prob = 1.0;
    stringstream ss(s);
    vector<string> words;
    string t;
    while(ss >> t)
    {
        words.emplace_back(t);
    }
    for(int i=0; i<words.size() - 1; ++i)
    {
        string cur = words[i];
        string n = words[i+1];
        double prb = calc(cur, n);
        prob *= prb;
    }
    return prob;
}

double perplejidad(string& frase, double p)
{
    const double sz = (double)frase.size();
    const double perp = pow(p, -1.0/sz);
    return perp;
}

int main()
{
    set<string> vocabulary = build_set(training_data);
    for(auto& s : training_data)
        s = s + " " + EOS;
    //fill_trigram(training_data);
    fill_bigram(training_data);
    laplacian_smooth(ngram, vocabulary, 1);
    fill_total_cnt(ngram);
    
    //cout << ngram;
    //cout << total_count;
    
    string query = BOS + " " + "my gradescope submission is failing" + " " + EOS;
    double prob = calc_bigram(query);
    cout << prob << endl;
    double perp = perplejidad(query, prob);
    cout << "perplejidad: " << perp << endl;
    //cout << "P(passing | are): " << calc("tests are", "passing");
    
    return 0;
}