#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
class ArmstrongChecker {
public:
    static bool isArmstrong(int num) {
        int k = to_string(num).length(); 
        int sum = 0;
        int n = num;

        while (n > 0) {
            int ld = n % 10;           
            sum += pow(ld, k);         
            n /= 10;                
        }

        return sum == num; 
    }
};

//Complexity Analysis
//Time Complexity: O(d) where d is the number of digits in the input number.
//Space Complexity: O(1) since we are using only a constant amount of space to store the variables.