class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string binar=bitset<32>(n).to_string();
        reverse(binar.begin(),binar.end());
        return stoul(binar,nullptr,2);
    }
};
