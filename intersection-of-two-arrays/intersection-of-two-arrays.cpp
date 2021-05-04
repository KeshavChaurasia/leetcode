class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> hash;
        set<int> results;
        vector<int> uniqueElements;
        for(int num: nums1){
            hash.insert(num);
        }
        
        for(int num: nums2){
            if(hash.find(num) != hash.end()){
                if(results.find(num) == results.end()){
                    uniqueElements.push_back(num);
                } 
                results.insert(num);
            }
        }
        return uniqueElements;
    }
};