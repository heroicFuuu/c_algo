#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;
class Solution {
    string dict = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    unordered_map<string, string> MapL2S;
    unordered_map<string, string> MapS2L;

  public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code = "";
        do {
            for (int i = 0; i < 6; i++) {
                code += dict[(rand() % 62)];
            }
        } while (MapL2S.find(code) != MapL2S.end());

        MapL2S[longUrl] = code;
        MapS2L[code] = longUrl;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return MapS2L[shortUrl];
    }
};
