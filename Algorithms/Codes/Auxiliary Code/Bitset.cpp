int main() {
    //bitset1.to_string()
    //bitset1.to_ulong()
    // M For bit size i.e. 32,16,8,4..
    // default constructor initializes with all bits 0
    bitset<M> bset1;
    // bset2 is initialized with bits of 20
    bitset<M> bset2(20);
    // bset3 is initialized with bits of specified binary string
    bitset<M> bset3(string("1100"));
    // count function returns number of set bits in bitset
    int numberof1 = set2.count();
    // size function returns total number of bits in bitset
    // so there difference will give us number of unset(0)
    // bits in bitset
    int numberof0 = set2.size() - numberof1;
    // test function return 1 if bit is set else returns 0
    for (int i = 0; i < set2.size(); i++)
        cout << set2.test(i) << " ";
    // any function returns true, if atleast 1 bit
    // is set
    if (!set8.any())
        cout << "set8 has no bit set.\n";
    if (!bset1.any())
        cout << "bset1 has no bit set.\n";
    // none function returns true, if none of the bit is set
    if (!bset1.none())
        cout << "bset1 has all bit set\n";
    // flip function flips all bits i.e.  1 <-> 0 and  0 <-> 1
    set2.flip(2);
    set2.flip();
    // Converting decimal number to binary by using bitset
    int num = 100;
    Decimal number: num
    Binary equivalent:  bitset<8>(num);
    //Usage 01: Set and Reset a bit in the bitset
    bitset3.set();
    bitset2.set(position);
    bitset2.reset();
    bitset3.reset(position);
    bitset<4> bset1(9);      // bset1 contains 1001
    bitset<4> bset2(3);      // bset2 contains 0011
    // comparison operator
    cout << (bset1 == bset2) << endl;  // false 0
    cout << (bset1 != bset2) << endl;  // true  1
    // bitwise operation and assignment
    cout << (bset1 ^= bset2) << endl;  // 1010
    cout << (bset1 &= bset2) << endl;  // 0010
    cout << (bset1 |= bset2) << endl;  // 0011
    // left and right shifting
    cout << (bset1 <<= 2) << endl;     // 1100
    cout << (bset1 >>= 1) << endl;     // 0110
    // not operator
    cout << (~bset2) << endl;          // 1100
    // bitwise operator
    cout << (bset1 & bset2) << endl;    // 0010
    cout << (bset1 | bset2) << endl;    // 0111
    cout << (bset1 ^ bset2) << endl;    // 0101
}
