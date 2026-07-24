class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        if ((s + s).find(goal) != string::npos) return true;
        return false;
    }
};


//Approch 1 : ROTATE STL
// std::rotate(first, middle, last)

// Before Rotation
// Part 1          Part 2
// | A | B | C | | D | E | F |
//   ^             ^       ^end
//    first        middle (becomes new first)

//        ↓ rotate() ↓

// After Rotation
// | D | E | F | | A | B | C |

// Rule 2: Part 2 moves to the front, Part 1 moves to the back.
// Rule 3: Left Rotate by k  -> rotate(begin, begin + k, end);
// Rule 4: Right Rotate by k -> rotate(begin, end - k, end);
// Time Complexity: O(n) | Space Complexity: O(1)


//Approch2 : Concatenate self string
//and you'll find the goal in the  Concatenated string 