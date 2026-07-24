class Solution {
public:
    bool rotateString(string s, string goal) {

        for(int i = 1; i <= s.length();i++){
            rotate(s.begin(),s.begin()+1,s.end());
            if(s == goal) return true;
        }
        return false;
        
    }
};



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