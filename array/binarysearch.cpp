#include "iostream"
#include "vector"

using namespace std;


template <typename T>
class  binarysearch
{
private:
    /* data */
public:
     binarysearch(/* args */){}
    ~ binarysearch(){}

    /// @brief find target value in ordered array
    /// @param target 
    /// @param array 
    /// @return -1: no target in array  other: the index of target value 
    int SearchTarget(T target,vector<T> array)
    {
        int left = 0;
        int right = array.size() - 1;
        int middle = left + (right-left)/2;
        while(left<=right)
        {
            int middle = left+(right-left)/2;
            if(array[middle]>target)  //target in left
            {
                right = middle-1;
            }
            else if(array[middle]<target) //target in right
            {
                left = middle+1;
            }
            else{
                return middle; 
            }
        } 
        return -1;
    }

};






int main(int argc,char** argv[])
{
    //generate a ordered array
    vector<int> nums;
    nums.resize(100);
    for(int i = 0; i < 100; i++){
        nums[i] = i;
    }


    //define target is 50
    int target = 50;
    binarysearch<int> bs;
    int index = bs.SearchTarget(target,nums);
    cout<<"the target: "<<target<<" , the index: "<<index<<endl;

    return 0;
}