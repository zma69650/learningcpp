#include "iostream"
#include "vector"

// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// 你可以假设数组中无重复元素。
// 示例 1:
// 输入: [1,3,5,6], 5
// 输出: 2

// 示例 2:
// 输入: [1,3,5,6], 2
// 输出: 1

using namespace std;

template <typename T>
class SearchInsetforPosition
{
private:
    /* data */
public:
    SearchInsetforPosition(/* args */){}
    ~SearchInsetforPosition(){}

    /// @brief  
    /// @param target 
    /// @param array 
    /// @return  position that will insert or target value location 
    int GetInsertPosition(T target,vector<T> array)
    {
        int left = 0;
        int right = array.size() - 1;
        int middle  = left + (right-left) / 2;
        if(target > array[right])  //target value is bigger than max value in array 
        {
            return right + 1;
        }

        if(target < array[left]){  //target value is smaller than min value in array
            return left;
        }
        while (left<=right)
        {
            /* code */
            int middle = left + (right - left) / 2;
            if(target > array[middle]){    //target value in right
                left = middle + 1;
            }
            else if(target < array[middle]){  //target value in left
                right = middle - 1;
            }     
            else{
                return middle;
            }

        }
        return left;
    }

};



int main(int argc,char** argv[])
{


    //construct a ordered array
    vector<int> array;
    array.resize(10);
    for(int i = 0;i<10;i++){
        array[i] = 2*i;
    }


    //define target 
    int target = 5;


    //begin search
    SearchInsetforPosition<int> sip;
    
    int position = sip.GetInsertPosition(target,array);
    for(int i = 0;i<10;i++){
        std::cout<<array[i];
    }
    std::cout<<"target value: "<<target<<" ,insert position: "<<position<<std::endl;
    return 0;


}


