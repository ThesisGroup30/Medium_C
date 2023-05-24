#include <bitset>
#include <string>

class Bitset {
private:
    std::bitset<32> bits; // Assuming the maximum size is 32 bits

public:
    Bitset(int size) {
        // Resize the bitset to the given size
        bits.resize(size);
    }

    void fix(int idx) {
        // Set the bit at the given index to 1
        bits.set(idx);
    }

    void unfix(int idx) {
        // Set the bit at the given index to 0
        bits.reset(idx);
    }

    void flip() {
        // Flip the values of each bit in the bitset
        bits.flip();
    }

    bool all() {
        // Check if all bits in the bitset are set to 1
        return bits.all();
    }

    bool one() {
        // Check if at least one bit in the bitset is set to 1
        return bits.any();
    }

    int count() {
        // Count the number of bits set to 1 in the bitset
        return bits.count();
    }

    std::string toString() {
        // Convert the bitset to string representation
        return bits.to_string();
    }
};
