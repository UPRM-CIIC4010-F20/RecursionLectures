#include <iostream>
#include <string>
#include <vector>

using namespace std;

int recFactorial(int n)
{
    if (n == 0) {
        return 1;
    } else {
        return recFactorial(n-1) * n;
    }
}

int iterFactorial(int n) {

    int result = 1;
    for (int i=1; i<=n; i++) {
        result *= i;
    }
    return result;

}

int recFibo(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return recFibo(n-1) + recFibo(n-2);
    }
}

int iterFibo(int n) {

    int f0 = 0;
    int f1 = 1;
    int fn = f0 + f1;
    for (int i=2; i<=n; i++) {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }
    return fn;

}

bool isPalindrome(string word) {
    if (word.length() <= 1) {
        return true;
    }
    return ((word[0] == word[word.length()-1]) && (isPalindrome(word.substr(1, word.length() - 2))));
}


vector<string>* permutations(string word) 
{

    vector<string>* result = new vector<string>;
    if (word.length() <= 1) {
        result->push_back(word);
        return result;
    }
    for(int i=0; i<word.length(); i++) {
        string nextLetter = word.substr(i,1);
        string leftPart = word.substr(0,i);
        string rightPart = word.substr(i+1,word.length()-i-1);
        string shorterWord = leftPart + rightPart;
    }

}


int main() {

    cout << "recFactorial(0)" << recFactorial(0) << endl;
    cout << "recFactorial(1)" << recFactorial(1) << endl;
    cout << "recFactorial(5)" << recFactorial(5) << endl;


    cout << "iterFactorial(0)" << iterFactorial(0) << endl;
    cout << "iterFactorial(1)" << iterFactorial(1) << endl;
    cout << "iterFactorial(5)" << iterFactorial(5) << endl;

    cout << "recFibo(0): "<< recFibo(0) << endl;
    cout << "recFibo(1): "<< recFibo(1) << endl;
    cout << "recFibo(2): "<< recFibo(2) << endl;
    cout << "recFibo(3): "<< recFibo(3) << endl;
    cout << "recFibo(10): "<< recFibo(10) << endl;

    cout << "iterFibo(0): "<< iterFibo(0) << endl;
    cout << "iterFibo(1): "<< iterFibo(1) << endl;
    cout << "iterFibo(2): "<< iterFibo(2) << endl;
    cout << "iterFibo(3): "<< iterFibo(3) << endl;
    cout << "iterFibo(10): "<< iterFibo(10) << endl;

    cout << "reconocer: " << (isPalindrome("reconocer") ? "true" : "false") << endl;
    cout << "tacocat: " << (isPalindrome("tacocat") ? "true" : "false") << endl;
    cout << "tacocats: " << (isPalindrome("tacocats") ? "true" : "false") << endl;

    vector<string>* perms = permutations("eat");

}