/*

You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:

Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
Example 2:

Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

*/



// keypoints:
// 1. hash table is natural choise
// 2. if digit exists in secret, plus 1, like product
// 3. if digit exists in guess, minus 1, like consumer
// 4. hash[secret] <= 0 means current digit was consumed(aka exist in guess), 
//    since it was positive before
// 5. hash[guess] >= 0 means current digit was producted(aka exist in secret), 
//    since it was negative before

class Solution {
public:
    string getHint(string secret, string guess) {
        // hash
        int hash[256] = {0};
        int a = 0, b = 0;
        for (int i = 0, n = secret.size(); i < n; ++i) {
            char& s = secret[i];
            char& g = guess[i];
            
            // exist in secret, plus 1; exist in guess, minus 1
            if (s == g) {
                ++a;
            } else {
                
                ++hash[s];
                --hash[g];
                
                // since ++ and -- operation before, if hash[i] = 0
                // it means digit occur same time in secret and guess
                // so init hash as 0 is safe, won't mess up
                // use "<=" and ">=" in case repeated digits: 1122 2211
                if (hash[s] <= 0) // occur in guess
                    ++b;
                
                if (hash[g] >= 0) // occur in secret
                    ++b;
            }
        }
        
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
